
#include "Stage.h"
#include <cassert>
#include <algorithm>
#include <iterator>

namespace {
  KeySequence::iterator find_key(KeySequence& sequence, Key key) {
    return std::find_if(begin(sequence), end(sequence),
      [&](const auto& ev) { return ev.key == key; });
  }

  template<typename It, typename T>
  bool contains(It begin, It end, const T& v) {
    return std::find(begin, end, v) != end;
  }

  template<typename C, typename T>
  bool contains(const C& container, const T& v) {
    return contains(cbegin(container), cend(container), v);
  }

  bool is_virtual_key(Key key) {
    return (key >= Key::VIRTUAL1 && key <= Key::VIRTUAL8);
  }

  std::vector<MappingOverrideSet> sort(
      std::vector<MappingOverrideSet>&& override_sets) {
    // sort overrides sets by index
    for (auto& override_set : override_sets)
      std::sort(begin(override_set), end(override_set));
    return std::move(override_sets);
  }
} // namespace

bool operator<(const MappingOverride& a, int mapping_index) {
  return (a.mapping_index < mapping_index);
}

bool operator<(const MappingOverride& a, const MappingOverride& b) {
  return (a.mapping_index < b.mapping_index);
}

Stage::Stage(std::vector<Mapping> mappings,
             std::vector<MappingOverrideSet> override_sets)
  : m_mappings(std::move(mappings)),
    m_override_sets(sort(std::move(override_sets))) {
}

const std::vector<Mapping>& Stage::mappings() const {
  return m_mappings;
}

const std::vector<MappingOverrideSet>& Stage::override_sets() const {
  return m_override_sets;
}

void Stage::activate_override_set(int index) {
  m_active_override_set = (index < 0 || index >=
    static_cast<int>(m_override_sets.size()) ?
    nullptr : &m_override_sets[static_cast<size_t>(index)]);
}

void Stage::reuse_buffer(KeySequence&& buffer) {
  m_output_buffer = std::move(buffer);
  m_output_buffer.clear();
}

KeySequence Stage::apply_input(const KeyEvent event) {
  assert(event.state == KeyState::Down ||
         event.state == KeyState::Up);

  if (event.state == KeyState::Down) {
    // merge key repeats
    auto it = find_key(m_sequence, event.key);
    if (it != end(m_sequence))
      if (it->state == KeyState::DownMatched)
        m_sequence.erase(it);
  }
  m_sequence.push_back(event);

  if (event.state == KeyState::Up) {
    // release output when triggering input was released
    release_triggered(event.key);

    // remove from sequence
    // except when it was already used for a might match
    if (!m_sequence_might_match) {
      const auto it = find_key(m_sequence, event.key);
      assert(it != end(m_sequence));
      if (it->state == KeyState::DownMatched)
        m_sequence.erase(it);
    }
  }

  // find first mapping which matches sequence
  auto result = MatchResult::no_match;
  auto output = static_cast<const KeySequence*>(nullptr);
  if (!m_sequence.empty())
    for (const auto& mapping : m_mappings) {
      result = std::max(result, m_match(mapping.input, m_sequence));
      if (result == MatchResult::match) {
        output = &get_output(mapping);
        break;
      }
    }

  if (result == MatchResult::might_match) {
    // hold back sequence when something might match
    m_sequence_might_match = true;
  }
  else {
    // reapply temporarily released keys, when not suppressed again
    if (event.state == KeyState::Down)
      reapply_temporarily_released(output ? *output : m_sequence);

    // when no match was found, forward sequence to output
    if (!output)
      apply_sequence();
    else
      apply_output(*output);

    // sequence finished
    finish_sequence();
    m_sequence_might_match = false;
  }
  return std::move(m_output_buffer);
}

void Stage::release_triggered(Key key) {
  const auto it = std::stable_partition(begin(m_output_down), end(m_output_down),
    [&](const auto& k) { return k.trigger != key; });
  std::for_each(it, end(m_output_down),
    [&](const auto& k) {
      if (!k.temporarily_released)
        m_output_buffer.push_back({ k.key, KeyState::Up });
    });
  m_output_down.erase(it, end(m_output_down));
}

void Stage::reapply_temporarily_released(const KeySequence& expression) {
  for (const auto& output : m_output_down)
    if (output.temporarily_released &&
        !contains(expression, KeyEvent{ output.key, KeyState::Not }))
      update_output({ output.key, KeyState::Down }, output.trigger);
}

const KeySequence& Stage::get_output(const Mapping& mapping) const {
  // look for override
  if (m_active_override_set) {
    const auto& override_set = *m_active_override_set;
    const auto index = static_cast<int>(std::distance(m_mappings.data(), &mapping));
    auto it = std::lower_bound(begin(override_set), end(override_set), index);
    if (it != end(override_set) && it->mapping_index == index)
      return it->output;
  }
  return mapping.output;
}

void Stage::toggle_virtual_key(Key key) {
  auto it = find_key(m_sequence, key);
  if (it != cend(m_sequence))
    m_sequence.erase(it);
  else
    m_sequence.emplace_back(key, KeyState::Down);
}

void Stage::apply_output(const KeySequence& expression) {
  for (const auto& event : expression)
    if (is_virtual_key(event.key))
      toggle_virtual_key(event.key);
    else
      update_output(event, m_sequence.back().key);
}

void Stage::apply_sequence() {
  for (const auto& event : m_sequence)
    if (event.state == KeyState::Down)
      update_output(event, event.key);
    else if (event.state == KeyState::Up)
      release_triggered(event.key);
}

void Stage::update_output(const KeyEvent& event, Key trigger) {
  const auto it = std::find_if(begin(m_output_down), end(m_output_down),
    [&](const OutputDown& down_key) { return down_key.key == event.key; });

  if (event.state == KeyState::Up) {
    if (it != end(m_output_down)) {
      m_output_down.erase(it);
      m_output_buffer.push_back(event);
    }
  }
  else if (event.state == KeyState::Not) {
    // make sure it is released in output
    if (it != end(m_output_down) && !it->temporarily_released) {
      m_output_buffer.emplace_back(event.key, KeyState::Up);
      it->temporarily_released = true;
    }
  }
  else {
    assert(event.state == KeyState::Down);
    if (it == end(m_output_down))
      m_output_down.push_back({ event.key, trigger, false });
    else
      it->temporarily_released = false;
    m_output_buffer.emplace_back(event.key, KeyState::Down);
  }
}

void Stage::finish_sequence() {
  for (auto it = begin(m_sequence); it != end(m_sequence); ) {
    if (it->state == KeyState::Down || it->state == KeyState::DownMatched) {
      // convert to DownMatched when no Up follows, otherwise also erase
      if (!contains(it, end(m_sequence), KeyEvent{ it->key, KeyState::Up })) {
        it->state = KeyState::DownMatched;
        ++it;
        continue;
      }
    }
    it = m_sequence.erase(it);
  }
}