#pragma once

#include <string>
#include <cstdint>

// carefully selected to match platform's scancodes
// https://developer.mozilla.org/en-US/docs/Web/API/UI_Events/Keyboard_event_code_values
enum class Key : uint16_t {
  none               = 0,

#if defined(__linux__) || defined(_WIN32)
  Escape             = 0x0001,
  Digit1             = 0x0002,
  Digit2             = 0x0003,
  Digit3             = 0x0004,
  Digit4             = 0x0005,
  Digit5             = 0x0006,
  Digit6             = 0x0007,
  Digit7             = 0x0008,
  Digit8             = 0x0009,
  Digit9             = 0x000A,
  Digit0             = 0x000B,
  Minus              = 0x000C,
  Equal              = 0x000D,
  Backspace          = 0x000E,
  Tab                = 0x000F,
  KeyQ               = 0x0010, Q = KeyQ,
  KeyW               = 0x0011, W = KeyW,
  KeyE               = 0x0012, E = KeyE,
  KeyR               = 0x0013, R = KeyR,
  KeyT               = 0x0014, T = KeyT,
  KeyY               = 0x0015, Y = KeyY,
  KeyU               = 0x0016, U = KeyU,
  KeyI               = 0x0017, I = KeyI,
  KeyO               = 0x0018, O = KeyO,
  KeyP               = 0x0019, P = KeyP,
  BracketLeft        = 0x001A,
  BracketRight       = 0x001B,
  Enter              = 0x001C,
  ControlLeft        = 0x001D,
  KeyA               = 0x001E, A = KeyA,
  KeyS               = 0x001F, S = KeyS,
  KeyD               = 0x0020, D = KeyD,
  KeyF               = 0x0021, F = KeyF,
  KeyG               = 0x0022, G = KeyG,
  KeyH               = 0x0023, H = KeyH,
  KeyJ               = 0x0024, J = KeyJ,
  KeyK               = 0x0025, K = KeyK,
  KeyL               = 0x0026, L = KeyL,
  Semicolon          = 0x0027,
  Quote              = 0x0028,
  Backquote          = 0x0029,
  ShiftLeft          = 0x002A,
  Backslash          = 0x002B,
  KeyZ               = 0x002C, Z = KeyZ,
  KeyX               = 0x002D, X = KeyX,
  KeyC               = 0x002E, C = KeyC,
  KeyV               = 0x002F, V = KeyV,
  KeyB               = 0x0030, B = KeyB,
  KeyN               = 0x0031, N = KeyN,
  KeyM               = 0x0032, M = KeyM,
  Comma              = 0x0033,
  Period             = 0x0034,
  Slash              = 0x0035,
  ShiftRight         = 0x0036,
  NumpadMultiply     = 0x0037,
  AltLeft            = 0x0038,
  Space              = 0x0039,
  CapsLock           = 0x003A,
  F1                 = 0x003B,
  F2                 = 0x003C,
  F3                 = 0x003D,
  F4                 = 0x003E,
  F5                 = 0x003F,
  F6                 = 0x0040,
  F7                 = 0x0041,
  F8                 = 0x0042,
  F9                 = 0x0043,
  F10                = 0x0044,
  ScrollLock         = 0x0046,
  Numpad7            = 0x0047,
  Numpad8            = 0x0048,
  Numpad9            = 0x0049,
  NumpadSubtract     = 0x004A,
  Numpad4            = 0x004B,
  Numpad5            = 0x004C,
  Numpad6            = 0x004D,
  NumpadAdd          = 0x004E,
  Numpad1            = 0x004F,
  Numpad2            = 0x0050,
  Numpad3            = 0x0051,
  Numpad0            = 0x0052,
  NumpadDecimal      = 0x0053,
  IntlBackslash      = 0x0056,
  F11                = 0x0057,
  F12                = 0x0058,
#endif // defined(__linux__) || defined(_WIN32)

#if defined(__linux__)
  NumLock            = 0x0045,
  IntlRo             = 0x0059,
  Convert            = 0x005C,
  KanaMode           = 0x005D,
  NonConvert         = 0x005E,
  NumpadEnter        = 0x0060,
  ControlRight       = 0x0061,
  NumpadDivide       = 0x0062,
  PrintScreen        = 0x0063,
  AltRight           = 0x0064,
  Cancel             = 0x0065,
  Home               = 0x0066,
  ArrowUp            = 0x0067,
  PageUp             = 0x0068,
  ArrowLeft          = 0x0069,
  ArrowRight         = 0x006A,
  End                = 0x006B,
  ArrowDown          = 0x006C,
  PageDown           = 0x006D,
  Insert             = 0x006E,
  Delete             = 0x006F,
  AudioVolumeMute    = 0x0071,
  AudioVolumeDown    = 0x0072,
  AudioVolumeUp      = 0x0073,
  Power              = 0x0074,
  NumpadEqual        = 0x0075,
  Settings           = 0x0076,
  Pause              = 0x0077,
  NumpadComma        = 0x0079,
  Lang1              = 0x007A,
  Lang2              = 0x007B,
  IntlYen            = 0x007C,
  MetaLeft           = 0x007D,
  MetaRight          = 0x007E,
  ContextMenu        = 0x007F,
  BrowserStop        = 0x0080,
  Again              = 0x0081,
  Props              = 0x0082,
  Undo               = 0x0083,
  Select             = 0x0084,
  Copy               = 0x0085,
  Open               = 0x0086,
  Paste              = 0x0087,
  Find               = 0x0088,
  Cut                = 0x0089,
  Help               = 0x008A,
  LaunchApp2         = 0x008C,
  Sleep              = 0x008E,
  WakeUp             = 0x008F,
  LaunchApp1         = 0x0090,
  LaunchMail         = 0x009B,
  BrowserFavorites   = 0x009C,
  BrowserBack        = 0x009E,
  BrowserForward     = 0x009F,
  Eject              = 0x00A1,
  MediaTrackNext     = 0x00A3,
  MediaPlayPause     = 0x00A4,
  MediaTrackPrevious = 0x00A5,
  MediaStop          = 0x00A6,
  MediaRewind        = 0x00A8,
  LaunchMediaPlayer  = 0x00AB,
  BrowserHome        = 0x00AC,
  BrowserRefresh     = 0x00AD,
  F13                = 0x00B7,
  F14                = 0x00B8,
  F15                = 0x00B9,
  F16                = 0x00BA,
  F17                = 0x00BB,
  F18                = 0x00BC,
  F19                = 0x00BD,
  F20                = 0x00BE,
  F21                = 0x00BF,
  F22                = 0x00C0,
  F23                = 0x00C1,
  F24                = 0x00C2,
  MediaPlay          = 0x00C8,
  MediaPause         = 0x00C9,
  Prog3              = 0x00CA,
  MediaFastForward   = 0x00D0,
  BrowserSearch      = 0x00D9,
  BrightnessDown     = 0x00E0,
  BrightnessUp       = 0x00E1,
  DisplayToggleIntExt= 0x00E3,
  WLAN               = 0x00EE,
  Fn                 = 0x01D0,
#endif // defined(__linux__)

#if defined(_WIN32)
  Pause              = 0x0045,
//PrintScreen        = 0x0054, // Alt + PrintScreen
  NumpadEqual        = 0x0059,
  F13                = 0x0064,
  F14                = 0x0065,
  F15                = 0x0066,
  F16                = 0x0067,
  F17                = 0x0068,
  F18                = 0x0069,
  F19                = 0x006A,
  F20                = 0x006B,
  F21                = 0x006C,
  F22                = 0x006D,
  F23                = 0x006E,
  KanaMode           = 0x0070,
  Lang2              = 0x0071,
  Lang1              = 0x0072,
  IntlRo             = 0x0073,
  F24                = 0x0076,
  Convert            = 0x0079,
  NonConvert         = 0x007B,
  IntlYen            = 0x007D,
  NumpadComma        = 0x007E,
  DisplayToggleIntExt= 0xE002,
  WLAN               = 0xE006,
  BrightnessUp       = 0xE008,
  BrightnessDown     = 0xE009,
  MediaTrackPrevious = 0xE010,
  MediaTrackNext     = 0xE019,
  NumpadEnter        = 0xE01C,
  ControlRight       = 0xE01D,
  AudioVolumeMute    = 0xE020,
  LaunchApp2         = 0xE021,
  MediaPlayPause     = 0xE022,
  MediaStop          = 0xE024,
  AudioVolumeDown    = 0xE02E,
  AudioVolumeUp      = 0xE030,
  BrowserHome        = 0xE032,
  Prog3              = 0xE033,
  NumpadDivide       = 0xE035,
  PrintScreen        = 0xE037,
  AltRight           = 0xE038,
  NumLock            = 0xE045,
  Cancel             = 0xE046, // Ctrl + Pause
  Home               = 0xE047,
  ArrowUp            = 0xE048,
  PageUp             = 0xE049,
  ArrowLeft          = 0xE04B,
  ArrowRight         = 0xE04D,
  Settings           = 0xE04E,
  End                = 0xE04F,
  ArrowDown          = 0xE050,
  PageDown           = 0xE051,
  Insert             = 0xE052,
  Delete             = 0xE053,
  MetaLeft           = 0xE05B,
  MetaRight          = 0xE05C,
  ContextMenu        = 0xE05D,
  Power              = 0xE05E,
  BrowserSearch      = 0xE065,
  BrowserFavorites   = 0xE066,
  BrowserRefresh     = 0xE067,
  BrowserStop        = 0xE068,
  BrowserForward     = 0xE069,
  BrowserBack        = 0xE06A,
  LaunchApp1         = 0xE06B,
  LaunchMail         = 0xE06C,
  LaunchMediaPlayer  = 0xE06D,

  // TODO:
  Again              = 0xD001,
  Props              = 0xD002,
  Undo               = 0xD003,
  Select             = 0xD004,
  Copy               = 0xD005,
  Open               = 0xD006,
  Paste              = 0xD007,
  Find               = 0xD008,
  Cut                = 0xD009,
  Help               = 0xD010,
  Sleep              = 0xD011,
  WakeUp             = 0xD012,
  Eject              = 0xD013,
  Fn                 = 0xD014,
#endif // defined(_WIN32)

#if defined(__APPLE__)
  KeyA               = 0x04, A = KeyA,
  KeyB               = 0x05, B = KeyB,
  KeyC               = 0x06, C = KeyC,
  KeyD               = 0x07, D = KeyD,
  KeyE               = 0x08, E = KeyE,
  KeyF               = 0x09, F = KeyF,
  KeyG               = 0x0A, G = KeyG,
  KeyH               = 0x0B, H = KeyH,
  KeyI               = 0x0C, I = KeyI,
  KeyJ               = 0x0D, J = KeyJ,
  KeyK               = 0x0E, K = KeyK,
  KeyL               = 0x0F, L = KeyL,
  KeyM               = 0x10, M = KeyM,
  KeyN               = 0x11, N = KeyN,
  KeyO               = 0x12, O = KeyO,
  KeyP               = 0x13, P = KeyP,
  KeyQ               = 0x14, Q = KeyQ,
  KeyR               = 0x15, R = KeyR,
  KeyS               = 0x16, S = KeyS,
  KeyT               = 0x17, T = KeyT,
  KeyU               = 0x18, U = KeyU,
  KeyV               = 0x19, V = KeyV,
  KeyW               = 0x1A, W = KeyW,
  KeyX               = 0x1B, X = KeyX,
  KeyY               = 0x1C, Y = KeyY,
  KeyZ               = 0x1D, Z = KeyZ,
  Digit1             = 0x1E,
  Digit2             = 0x1F,
  Digit3             = 0x20,
  Digit4             = 0x21,
  Digit5             = 0x22,
  Digit6             = 0x23,
  Digit7             = 0x24,
  Digit8             = 0x25,
  Digit9             = 0x26,
  Digit0             = 0x27,
  Enter              = 0x28,
  Escape             = 0x29,
  Backspace          = 0x2A,
  Tab                = 0x2B,
  Space              = 0x2C,
  Minus              = 0x2D,
  Equal              = 0x2E,
  BracketLeft        = 0x2F,
  BracketRight       = 0x30,
  Backslash          = 0x31,
  IntlRo             = 0x32,
  Semicolon          = 0x33,
  Quote              = 0x34,
  Backquote          = 0x35,
  Comma              = 0x36,
  Period             = 0x37,
  Slash              = 0x38,
  CapsLock           = 0x39,
  F1                 = 0x3A,
  F2                 = 0x3B,
  F3                 = 0x3C,
  F4                 = 0x3D,
  F5                 = 0x3E,
  F6                 = 0x3F,
  F7                 = 0x40,
  F8                 = 0x41,
  F9                 = 0x42,
  F10                = 0x43,
  F11                = 0x44,
  F12                = 0x45,
  PrintScreen        = 0x46,
  ScrollLock         = 0x47,
  Pause              = 0x48,
  Insert             = 0x49,
  Home               = 0x4A,
  PageUp             = 0x4B,
  Delete             = 0x4C,
  End                = 0x4D,
  PageDown           = 0x4E,
  ArrowRight         = 0x4F,
  ArrowLeft          = 0x50,
  ArrowDown          = 0x51,
  ArrowUp            = 0x52,
  NumLock            = 0x53,
  NumpadDivide       = 0x54,
  NumpadMultiply     = 0x55,
  NumpadSubtract     = 0x56,
  NumpadAdd          = 0x57,
  NumpadEnter        = 0x58,
  Numpad1            = 0x59,
  Numpad2            = 0x5A,
  Numpad3            = 0x5B,
  Numpad4            = 0x5C,
  Numpad5            = 0x5D,
  Numpad6            = 0x5E,
  Numpad7            = 0x5F,
  Numpad8            = 0x60,
  Numpad9            = 0x61,
  Numpad0            = 0x62,
  NumpadDecimal      = 0x63,
  IntlBackslash      = 0x64,
  LaunchApp1         = 0x65,
  Power              = 0x66,
  NumpadEqual        = 0x67,
  F13                = 0x68,
  F14                = 0x69,
  F15                = 0x6A,
  F16                = 0x6B,
  F17                = 0x6C,
  F18                = 0x6D,
  F19                = 0x6E,
  F20                = 0x6F,
  F21                = 0x70,
  F22                = 0x71,
  F23                = 0x72,
  F24                = 0x73,
  AudioVolumeMute    = 0x7F,
  AudioVolumeUp      = 0x80,
  AudioVolumeDown    = 0x81,
  NumpadComma        = 0x85,
  Lang1              = 0x90,
  Lang2              = 0x91,
  ControlLeft        = 0xE0,
  ShiftLeft          = 0xE1,
  AltLeft            = 0xE2,
  MetaLeft           = 0xE3,
  ControlRight       = 0xE4,
  ShiftRight         = 0xE5,
  AltRight           = 0xE6,
  MetaRight          = 0xE7,

  MediaPlayPause     = 0xB0,
  MediaTrackNext     = 0xB5,
  MediaTrackPrevious = 0xB6,
  MediaStop          = 0xB7,

  // TODO:
  BrightnessDown     = 0xD000,
  BrightnessUp       = 0xD001,
  BrowserBack        = 0xD002,
  BrowserFavorites   = 0xD003,
  BrowserForward     = 0xD004,
  BrowserRefresh     = 0xD005,
  BrowserSearch      = 0xD006,
  BrowserStop        = 0xD007,
  Cancel             = 0xD008,
  ContextMenu        = 0xD009,
  Convert            = 0xD010,
  DisplayToggleIntExt= 0xD011,
  IntlYen            = 0xD012,
  KanaMode           = 0xD013,
  NonConvert         = 0xD014,
  Prog3              = 0xD015,
  Settings           = 0xD016,
  WLAN               = 0xD017,
  LaunchApp2         = 0xD018,
  LaunchMail         = 0xD019,
  LaunchMediaPlayer  = 0xD020,
  BrowserHome        = 0xD021,
  Again              = 0xD022,
  Props              = 0xD023,
  Undo               = 0xD024,
  Select             = 0xD025,
  Copy               = 0xD026,
  Open               = 0xD027,
  Paste              = 0xD028,
  Find               = 0xD029,
  Cut                = 0xD030,
  Help               = 0xD031,
  Sleep              = 0xD032,
  WakeUp             = 0xD033,
  Eject              = 0xD034,
  Fn                 = 0xD035,
#endif // defined(__APPLE__)

  ButtonLeft         = 0x0110,
  ButtonRight        = 0x0111,
  ButtonMiddle       = 0x0112,
  ButtonBack         = 0x0113,
  ButtonForward      = 0x0114,

  any                = 0xF000,
  timeout            = 0xF001,
  ContextActive      = 0xF002,

  last_physical      = 0xEFFF,
  first_virtual      = 0xF100,
  last_virtual       = 0xF1FF,
  first_action       = 0xF200,
  last_action        = 0xF2FF,
  first_logical      = 0xF300,
  last_logical       = 0xF3FF,

  first_mouse_button = ButtonLeft,
  last_mouse_button  = ButtonForward,

  Shift              = first_logical,
  Control            = first_logical + 1,
  Meta               = first_logical + 2,
};

constexpr uint16_t operator*(Key key) { return static_cast<uint16_t>(key); }

constexpr bool is_virtual_key(Key key) {
  return (key >= Key::first_virtual && key <= Key::last_virtual);
}

constexpr bool is_mouse_button(Key key) {
  return (key >= Key::first_mouse_button && key <= Key::last_mouse_button);
}

constexpr bool is_physical_key(Key key) {
  return (key > Key::none && key <= Key::last_physical && !is_mouse_button(key));
}

constexpr bool is_action_key(Key key) {
  return (key >= Key::first_action && key <= Key::last_action);
}
