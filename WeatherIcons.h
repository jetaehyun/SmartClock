

const uint16_t storm[256] PROGMEM={
0x0000, 0x0000, 0xFFFF, 0xF7BE, 0xFFBE, 0xFFDF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0010 (16) pixels
0x0000, 0xFFFF, 0xEF5C, 0xE71B, 0xEF3B, 0xF79D, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0020 (32) pixels
0x0000, 0xFFDE, 0xDED9, 0xE6FA, 0xE71B, 0xE71B, 0xEF3B, 0xEF3B, 0xEF3C, 0xF79F, 0xFFF9, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000,   // 0x0030 (48) pixels
0x0000, 0xF7BD, 0xDEB9, 0xE6FA, 0xE6FA, 0xE71B, 0xE71B, 0xE71C, 0xE73F, 0xF620, 0xEF19, 0xFFBF, 0xEF3B, 0xE6FA, 0xF77C, 0xFFFF,   // 0x0040 (64) pixels
0x0000, 0xEF5C, 0xDEB9, 0xDEDA, 0xE6FA, 0xE6FA, 0xE71C, 0xE71D, 0xF600, 0xEDE8, 0xDF1D, 0xDEDA, 0xDEDA, 0xDEB9, 0xD6B9, 0xF77D,   // 0x0050 (80) pixels
0xF79D, 0xD699, 0xD699, 0xDEB9, 0xDEBA, 0xDEDC, 0xE6F9, 0xF660, 0xF600, 0xDEFC, 0xDEDA, 0xDEDA, 0xDEB9, 0xDEB9, 0xD698, 0xEF5C,   // 0x0060 (96) pixels
0xEF5C, 0xD678, 0xD678, 0xD699, 0xD6BB, 0xDEB5, 0xF660, 0xF6C0, 0xEEE8, 0xD6BF, 0xDEBA, 0xDEB9, 0xDEB9, 0xD698, 0xD678, 0xEF5C,   // 0x0070 (112) pixels
0xFFBE, 0xDEFA, 0xD698, 0xDEFB, 0xDEB8, 0xF5E0, 0xF6A0, 0xFF40, 0xFFA0, 0xEEEE, 0xD6BD, 0xD699, 0xD678, 0xD678, 0xEF3C, 0xFFFF,   // 0x0080 (128) pixels
0x0000, 0xFFFF, 0xFFFF, 0xFFDE, 0xFFFF, 0xE6B5, 0xF6A2, 0xFF60, 0xFFA0, 0xFF20, 0xFEC0, 0xEF39, 0xF77D, 0xFFFF, 0x0000, 0x0000,   // 0x0090 (144) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xEF9F, 0xF706, 0xF720, 0xF6E0, 0xFEA0, 0xEE26, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00A0 (160) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFEA0, 0xF660, 0xFF21, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00B0 (176) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFEA0, 0xF5A1, 0xFEC1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00C0 (192) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFF41, 0xFDC1, 0xFE81, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00D0 (208) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0xFF81, 0xFE41, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00E0 (224) pixels
0x0000, 0x0000, 0x0000, 0xFF21, 0xFF01, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00F0 (240) pixels
0x0000, 0x0000, 0x0000, 0xFE61, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0100 (256) pixels
};

// const uint16_t sunny[256] PROGMEM={
// 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFE20, 0x0000, 0x0000, 0xFE20, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0010 (16) pixels
// 0x0000, 0x0000, 0x0000, 0xFE81, 0x0000, 0x0000, 0xFDE0, 0xCCA0, 0xD4E0, 0xFDC0, 0x0000, 0xF540, 0xFE00, 0x0000, 0x0000, 0x0000,   // 0x0020 (32) pixels
// 0x0000, 0x0000, 0x0000, 0xD440, 0xFE00, 0x0000, 0xFD60, 0xFE20, 0xFE00, 0xFD60, 0x0000, 0xFDE0, 0xCC20, 0x0000, 0x0000, 0x0000,   // 0x0030 (48) pixels
// 0x0000, 0xFEA1, 0xE520, 0x0000, 0xFD80, 0xFE20, 0xF5E0, 0xF5C0, 0xF5C0, 0xFDE0, 0xFE20, 0xFD80, 0x0000, 0xED20, 0xFE81, 0x0000,   // 0x0040 (64) pixels
// 0x0000, 0xE480, 0xFDC0, 0xFE40, 0xFE00, 0xF5A0, 0xF661, 0xF681, 0xF6A1, 0xF621, 0xF5A0, 0xFE00, 0xFE40, 0xFDA0, 0x0000, 0x0000,   // 0x0050 (80) pixels
// 0x0000, 0x0000, 0x0000, 0xFDA0, 0xF5A1, 0xF6C1, 0xF660, 0xF681, 0xF681, 0xF680, 0xF661, 0xF5C0, 0xFDA0, 0x0000, 0x0000, 0x0000,   // 0x0060 (96) pixels
// 0xFE20, 0xFE80, 0xFE20, 0xF5E0, 0xF641, 0xF661, 0xF6E0, 0xFF20, 0xFF00, 0xF6C0, 0xF660, 0xF601, 0xFDE0, 0xFE20, 0xFE80, 0xFE20,   // 0x0070 (112) pixels
// 0x0000, 0xBBE0, 0xFDA0, 0xF5A0, 0xF621, 0xF6A0, 0xFF20, 0xFF80, 0xFF80, 0xF700, 0xF681, 0xEE01, 0xF5C0, 0xFD80, 0xBBC0, 0x0000,   // 0x0080 (128) pixels
// 0x0000, 0xDD20, 0xFE40, 0xF5A0, 0xEE01, 0xF6A0, 0xFF20, 0xFF80, 0xFF80, 0xF700, 0xF681, 0xEDC1, 0xF5C0, 0xFE40, 0xDD00, 0x0000,   // 0x0090 (144) pixels
// 0xFE40, 0xFE00, 0xFD60, 0xF5C0, 0xEDC1, 0xF681, 0xF6E0, 0xFF20, 0xFF00, 0xF6C0, 0xF641, 0xEDC1, 0xFDC0, 0xFD40, 0xFE20, 0xFE20,   // 0x00A0 (160) pixels
// 0x0000, 0x0000, 0x0000, 0xFDE0, 0xF5E0, 0xEE01, 0xF660, 0xF6A1, 0xF6A1, 0xF640, 0xEDC1, 0xF600, 0xFDE0, 0x0000, 0x0000, 0x0000,   // 0x00B0 (176) pixels
// 0x0000, 0xF540, 0xFE00, 0xFD80, 0xFDE0, 0xF601, 0xEDC1, 0xEDE1, 0xEDE1, 0xEDC1, 0xF640, 0xFDC0, 0xFD80, 0xFE20, 0xF540, 0x0000,   // 0x00C0 (192) pixels
// 0x0000, 0xFE00, 0xCBE0, 0x0000, 0xFDE0, 0xFDC0, 0xFE20, 0xF640, 0xF640, 0xFE20, 0xFDA0, 0xFE00, 0x0000, 0xCC00, 0xFE00, 0x0000,   // 0x00D0 (208) pixels
// 0x0000, 0x0000, 0x0000, 0xE4E0, 0xFD80, 0x0000, 0xFD80, 0xFDA0, 0xFDA0, 0xFD80, 0x0000, 0xFDA0, 0xDCC0, 0x0000, 0x0000, 0x0000,   // 0x00E0 (224) pixels
// 0x0000, 0x0000, 0x0000, 0xFE61, 0x0000, 0x0000, 0xFDE0, 0xC400, 0xCC40, 0xFDE0, 0x0000, 0xE480, 0xFE00, 0x0000, 0x0000, 0x0000,   // 0x00F0 (240) pixels
// 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFDC0, 0x0000, 0x0000, 0xFDC0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0100 (256) pixels
// };

const uint16_t cloudy[256] PROGMEM={
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0010 (16) pixels
0xDEDA, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0020 (32) pixels
0xDEFB, 0xE71B, 0xE6FA, 0xE71B, 0xE73B, 0xEF5C, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0030 (48) pixels
0xF77D, 0xDEB9, 0xDEB9, 0xDEDA, 0xDEDA, 0xDEDA, 0xDED9, 0xDEDA, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0040 (64) pixels
0xFFFF, 0xFFBE, 0xEF5C, 0xDEB9, 0xDEB9, 0xEF3B, 0xEF3B, 0xEF5C, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0050 (80) pixels
0x0000, 0x0000, 0xD6BA, 0xFFFF, 0xFFFF, 0xDEBA, 0xC638, 0xD699, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0060 (96) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0070 (112) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xD6BA,   // 0x0080 (128) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF77D, 0xF77C, 0xEF3B, 0xE71B, 0xE6DA, 0xE71B, 0xFFDE,   // 0x0090 (144) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xE6FB, 0xDEDA, 0xEF3B, 0xE6FA, 0xE71A, 0xE71B, 0xE6FB, 0xE6FA, 0xDEDA, 0xDEDA, 0xF79D,   // 0x00A0 (160) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xDEB9, 0xD699, 0xDEB9, 0xDEDA, 0xDEDA, 0xDEDA, 0xDEDA, 0xDED9, 0xDE99, 0xD699, 0xEF5C,   // 0x00B0 (176) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xEF3C, 0xD699, 0xD699, 0xDEB9, 0xDEB9, 0xD699, 0xD699, 0xDEB9, 0xE71B, 0xE6FA, 0xFFBE,   // 0x00C0 (192) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEF7D, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79D, 0xF79D, 0xFFFF, 0xE71B, 0xE6FB, 0x0000,   // 0x00D0 (208) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00E0 (224) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00F0 (240) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0100 (256) pixels
};

const uint16_t foggy[256] PROGMEM={
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0010 (16) pixels
0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0020 (32) pixels
0x0000, 0xFFFF, 0xE6FA, 0xE6FA, 0xE71A, 0xEF3C, 0xFFDE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xC617, 0x0000, 0x0000,   // 0x0030 (48) pixels
0x0000, 0xFFBE, 0xDED9, 0xE6FA, 0xE6FA, 0xE71B, 0xE71B, 0xE71B, 0xE71B, 0xE71B, 0xF7BD, 0xFFFF, 0xFFFF, 0xFFDE, 0xFFFF, 0xEF5C,   // 0x0040 (64) pixels
0x0000, 0xEF7C, 0xDEB9, 0xDEDA, 0xE6FA, 0xE6FA, 0xE71B, 0xE71A, 0xE6FB, 0xE6FA, 0xE6FA, 0xE71A, 0xDEDA, 0xDEB9, 0xDEDA, 0xFFBE,   // 0x0050 (80) pixels
0xFFBE, 0xDEB9, 0xD699, 0xDEB9, 0xDEDA, 0xDEDA, 0xE6FA, 0xDEDA, 0xE6FA, 0xE6FA, 0xDEDA, 0xDEDA, 0xDED9, 0xDEB9, 0xD698, 0xEF5C,   // 0x0060 (96) pixels
0xF77D, 0xD678, 0xD678, 0xD698, 0xD699, 0xDEB9, 0xDED9, 0xDEDA, 0xDEBA, 0xDEB9, 0xDEB9, 0xDEB9, 0xD699, 0xD678, 0xD699, 0xEF7D,   // 0x0070 (112) pixels
0xEF5D, 0xF7BD, 0xE71B, 0xF79D, 0xE6FA, 0xD678, 0xD698, 0xD699, 0xD698, 0xDEB9, 0xDEDA, 0xD699, 0xD678, 0xDEB9, 0xFFFF, 0xF79E,   // 0x0080 (128) pixels
0x0000, 0x0000, 0xB5B6, 0x0000, 0xFFFF, 0xFFBE, 0xEF3B, 0xE6FA, 0xEF5C, 0xFFFF, 0xFFDE, 0xFFFF, 0xFFDE, 0xFFFF, 0x0000, 0x0000,   // 0x0090 (144) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6B4C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00A0 (160) pixels
0x0000, 0x0000, 0xD69A, 0xCE59, 0xCE79, 0xA534, 0x0000, 0xC639, 0xC638, 0xD69A, 0x0000, 0xD69A, 0xC638, 0xD69A, 0x0000, 0x0000,   // 0x00B0 (176) pixels
0x0000, 0xC618, 0xBDF7, 0x0000, 0xB5B6, 0xC618, 0xC618, 0xC618, 0x0000, 0xBDF7, 0xC618, 0xBDD7, 0x0000, 0xB5B6, 0xD69A, 0x0000,   // 0x00C0 (192) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6B4C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00D0 (208) pixels
0x0000, 0x0000, 0xD69A, 0xCE59, 0xCE79, 0xA534, 0x0000, 0xC639, 0xC638, 0xD69A, 0x0000, 0xD69A, 0xC638, 0xD69A, 0x0000, 0x0000,   // 0x00E0 (224) pixels
0x0000, 0xC618, 0xBDF7, 0x0000, 0xB5B6, 0xC618, 0xC618, 0xC618, 0x0000, 0xBDF7, 0xC618, 0xBDD7, 0x0000, 0xB5B6, 0xD69A, 0x0000,   // 0x00F0 (240) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0100 (256) pixels
};

const uint16_t light_rain[256] PROGMEM={
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0010 (16) pixels
0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0020 (32) pixels
0x0000, 0xFFFF, 0xE6FA, 0xE6FA, 0xE71A, 0xEF3C, 0xFFDE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xC617, 0x0000, 0x0000,   // 0x0030 (48) pixels
0x0000, 0xFFBE, 0xDED9, 0xE6FA, 0xE6FA, 0xE71B, 0xE71B, 0xE71B, 0xE71B, 0xE71B, 0xF7BD, 0xFFFF, 0xFFFF, 0xFFDE, 0xFFFF, 0xEF5C,   // 0x0040 (64) pixels
0x0000, 0xEF7C, 0xDEB9, 0xDEDA, 0xE6FA, 0xE6FA, 0xE71B, 0xE71A, 0xE6FB, 0xE6FA, 0xE6FA, 0xE71A, 0xDEDA, 0xDEB9, 0xDEDA, 0xFFBE,   // 0x0050 (80) pixels
0xFFBE, 0xDEB9, 0xD699, 0xDEB9, 0xDEDA, 0xDEDA, 0xE6FA, 0xDEDA, 0xE6FA, 0xE6FA, 0xDEDA, 0xDEDA, 0xDED9, 0xDEB9, 0xD698, 0xEF5C,   // 0x0060 (96) pixels
0xF77D, 0xD678, 0xD678, 0xD698, 0xD699, 0xDEB9, 0xDED9, 0xDEDA, 0xDEBA, 0xDEB9, 0xDEB9, 0xDEB9, 0xD699, 0xD678, 0xD699, 0xEF7D,   // 0x0070 (112) pixels
0xEF5D, 0xF7BD, 0xE71B, 0xF79D, 0xE6FA, 0xD678, 0xD698, 0xD699, 0xD698, 0xDEB9, 0xDEDA, 0xD699, 0xD678, 0xDEB9, 0xFFFF, 0xF79E,   // 0x0080 (128) pixels
0x0000, 0x0000, 0xBDD7, 0x0000, 0xFFFF, 0xFFDE, 0xEF3B, 0xE6FA, 0xFFBE, 0xFFFF, 0xFFDE, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,   // 0x0090 (144) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x9C91, 0xCFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00A0 (160) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xA7FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00B0 (176) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x76BE, 0x363D, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00C0 (192) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x879F, 0x2D9A, 0x1DFC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00D0 (208) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3E5D, 0x1D79, 0x25FC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00E0 (224) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x26DF, 0x261D, 0x36BF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00F0 (240) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0100 (256) pixels
};

// const uint16_t light_showers[256] PROGMEM={
// 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0010 (16) pixels
// 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0020 (32) pixels
// 0x0000, 0xFFFF, 0xE6FA, 0xE6FA, 0xE71A, 0xEF3C, 0xFFDE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xC617, 0x0000, 0x0000,   // 0x0030 (48) pixels
// 0x0000, 0xFFBE, 0xDED9, 0xE6FA, 0xE6FA, 0xE71B, 0xE71B, 0xE71B, 0xE71B, 0xE71B, 0xF7BD, 0xFFFF, 0xFFFF, 0xFFDE, 0xFFFF, 0xEF5C,   // 0x0040 (64) pixels
// 0x0000, 0xEF7C, 0xDEB9, 0xDEDA, 0xE6FA, 0xE6FA, 0xE71B, 0xE71A, 0xE6FB, 0xE6FA, 0xE6FA, 0xE71A, 0xDEDA, 0xDEB9, 0xDEDA, 0xFFBE,   // 0x0050 (80) pixels
// 0xFFBE, 0xDEB9, 0xD699, 0xDEB9, 0xDEDA, 0xDEDA, 0xE6FA, 0xDEDA, 0xE6FA, 0xE6FA, 0xDEDA, 0xDEDA, 0xDED9, 0xDEB9, 0xD698, 0xEF5C,   // 0x0060 (96) pixels
// 0xF77D, 0xD678, 0xD678, 0xD698, 0xD699, 0xDEB9, 0xDED9, 0xDEDA, 0xDEBA, 0xDEB9, 0xDEB9, 0xDEB9, 0xD699, 0xD678, 0xD699, 0xEF7D,   // 0x0070 (112) pixels
// 0xEF5D, 0xF7BD, 0xE71B, 0xF79D, 0xE6FA, 0xD678, 0xD698, 0xD699, 0xD698, 0xDEB9, 0xDEDA, 0xD699, 0xD678, 0xDEB9, 0xFFFF, 0xF79E,   // 0x0080 (128) pixels
// 0x0000, 0x0000, 0xBDD7, 0x0000, 0xFFFF, 0xFFDE, 0xE6FA, 0xEF3B, 0xFFDE, 0xFFFF, 0xF7BD, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,   // 0x0090 (144) pixels
// 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xC6DC, 0xADB6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00A0 (160) pixels
// 0x0000, 0x0000, 0x0000, 0x7E5E, 0x7E7F, 0x0000, 0x871F, 0x0000, 0x0000, 0x8F1F, 0x5C96, 0x0000, 0x9FBF, 0x0000, 0x0000, 0x0000,   // 0x00B0 (176) pixels
// 0x0000, 0x0000, 0x0000, 0x8F1F, 0x0000, 0x6D9B, 0x8EFF, 0x0000, 0x0000, 0x8EFF, 0x0000, 0x867F, 0x7E5F, 0x0000, 0x0000, 0x0000,   // 0x00C0 (192) pixels
// 0x0000, 0x0000, 0x8EBF, 0x75FC, 0x0000, 0x8EFF, 0x0000, 0x0000, 0x8F1F, 0x5C75, 0x0000, 0x8F1F, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00D0 (208) pixels
// 0x0000, 0x0000, 0x8EFF, 0x0000, 0x869F, 0x867F, 0x0000, 0x75BB, 0x8EFF, 0x0000, 0x8F3F, 0x6D5A, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00E0 (224) pixels
// 0x0000, 0x86FF, 0x6519, 0x0000, 0x869F, 0x0000, 0x0000, 0x8F3F, 0x0000, 0x0000, 0x867F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00F0 (240) pixels
// 0x0000, 0x6DDD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x75BC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0100 (256) pixels
// };

const uint16_t rain[256] PROGMEM={
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0010 (16) pixels
0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0020 (32) pixels
0x0000, 0xFFFF, 0xE6FA, 0xE6FA, 0xE71A, 0xEF3C, 0xFFDE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xC617, 0x0000, 0x0000,   // 0x0030 (48) pixels
0x0000, 0xFFBE, 0xDED9, 0xE6FA, 0xE6FA, 0xE71B, 0xE71B, 0xE71B, 0xE71B, 0xE71B, 0xF7BD, 0xFFFF, 0xFFFF, 0xFFDE, 0xFFFF, 0xEF5C,   // 0x0040 (64) pixels
0x0000, 0xEF7C, 0xDEB9, 0xDEDA, 0xE6FA, 0xE6FA, 0xE71B, 0xE71A, 0xE6FB, 0xE6FA, 0xE6FA, 0xE71A, 0xDEDA, 0xDEB9, 0xDEDA, 0xFFBE,   // 0x0050 (80) pixels
0xFFBE, 0xDEB9, 0xD699, 0xDEB9, 0xDEDA, 0xDEDA, 0xE6FA, 0xDEDA, 0xE6FA, 0xE6FA, 0xDEDA, 0xDEDA, 0xDED9, 0xDEB9, 0xD698, 0xEF5C,   // 0x0060 (96) pixels
0xF77D, 0xD678, 0xD678, 0xD698, 0xD699, 0xDEB9, 0xDED9, 0xDEDA, 0xDEBA, 0xDEB9, 0xDEB9, 0xDEB9, 0xD699, 0xD678, 0xD699, 0xEF7D,   // 0x0070 (112) pixels
0xEF5D, 0xF7BD, 0xE6FB, 0xEF5C, 0xE6FA, 0xD678, 0xD698, 0xD699, 0xD698, 0xDEB9, 0xDEDA, 0xD699, 0xD698, 0xDEB9, 0xFFFF, 0xF79E,   // 0x0080 (128) pixels
0x0000, 0x0000, 0xC659, 0x0000, 0xFFFF, 0xFFDE, 0xEF5C, 0xEF1B, 0xF79D, 0xFFFF, 0xFFDE, 0xFFFF, 0xEF5C, 0xFFFF, 0x0000, 0x0000,   // 0x0090 (144) pixels
0x0000, 0x0000, 0x0000, 0x871F, 0x0000, 0x0000, 0xA4D3, 0xBEDC, 0x0000, 0x0000, 0x0000, 0x0000, 0x9FFF, 0x0000, 0x0000, 0x0000,   // 0x00A0 (160) pixels
0x0000, 0x0000, 0x9FBF, 0x5EBE, 0x0000, 0x0000, 0x0000, 0x8F1F, 0x5D99, 0x0000, 0x0000, 0x0000, 0x975F, 0x469E, 0x0000, 0x0000,   // 0x00B0 (176) pixels
0x0000, 0x0000, 0x7EDE, 0x1D7A, 0x25FC, 0x0000, 0x0000, 0x975F, 0x3E9E, 0x0000, 0x0000, 0x8F7F, 0x4DFB, 0x1DFC, 0x0000, 0x0000,   // 0x00C0 (192) pixels
0x0000, 0x4D58, 0x2DDB, 0x1D7A, 0x267E, 0x0000, 0x7EDE, 0x4E1B, 0x1D9A, 0x1CD6, 0x0000, 0x56FF, 0x1D79, 0x25BB, 0x1C54, 0x0000,   // 0x00D0 (208) pixels
0x0000, 0x0000, 0x263D, 0x25FC, 0x365E, 0x0000, 0x4F1F, 0x1D79, 0x259A, 0x2518, 0x0000, 0x2EBF, 0x25FC, 0x2E5E, 0x0000, 0x0000,   // 0x00E0 (224) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1D38, 0x265E, 0x2E7E, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00F0 (240) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0100 (256) pixels
};

const uint16_t showers[256] PROGMEM={
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0010 (16) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0020 (32) pixels
0x0000, 0xEF5D, 0xEF7D, 0xDEFB, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0030 (48) pixels
0xCE79, 0xDEDB, 0xCE59, 0xDEFB, 0xFFDF, 0xFFFF, 0xFFFF, 0x0000, 0xAD55, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0040 (64) pixels
0xCE79, 0xB596, 0xB596, 0xBDF7, 0xC618, 0xC618, 0xC639, 0xFFFF, 0xFFDE, 0xF79E, 0xF7BE, 0xCE79, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0050 (80) pixels
0xDEDB, 0xA514, 0xA534, 0xB596, 0xBDD7, 0xB596, 0xDEFB, 0xE73B, 0xE71B, 0xEF5C, 0xF79D, 0xFFDE, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79D,   // 0x0060 (96) pixels
0xEF5D, 0xBDD7, 0xBDD7, 0xAD55, 0xA534, 0xA514, 0xDEBA, 0xDEDA, 0xDEDA, 0xE6FA, 0xE6FA, 0xE6FA, 0xE71B, 0xE71B, 0xE6FA, 0xF7BE,   // 0x0070 (112) pixels
0x0000, 0xBDF7, 0xDE79, 0xF77D, 0xDEBA, 0xEF1B, 0xEF5C, 0xDEB9, 0xDEB9, 0xDEB9, 0xDED9, 0xDED9, 0xDEB9, 0xD699, 0xD6B9, 0xEF7D,   // 0x0080 (128) pixels
0x0000, 0x0000, 0x0271, 0x0000, 0x0000, 0x33D5, 0xFFFF, 0xDEFB, 0xEF3C, 0xE6FA, 0xDEDA, 0xEF3B, 0xF79D, 0xEF1B, 0xFFDE, 0xFFFF,   // 0x0090 (144) pixels
0x0000, 0x0000, 0x1395, 0x0000, 0x1371, 0x024D, 0x0000, 0x028F, 0x0000, 0xFF7C, 0xE73C, 0xC67A, 0x0000, 0xBF3F, 0x0000, 0x0000,   // 0x00A0 (160) pixels
0x0000, 0x2434, 0x0000, 0x0000, 0x2454, 0x0000, 0x1350, 0x2BF3, 0x5E1F, 0x0000, 0x55DF, 0x126E, 0x0000, 0x5E3F, 0x0000, 0x0000,   // 0x00B0 (176) pixels
0x128C, 0x2434, 0x0000, 0x122A, 0x0000, 0x0000, 0x1370, 0x865F, 0x0000, 0x4BD2, 0x8EFF, 0x0000, 0x8EDF, 0x5CB7, 0x0000, 0x0000,   // 0x00C0 (192) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6DBB, 0x8EFF, 0x0000, 0xA7FF, 0x0000, 0x5454, 0x8F3F, 0x0000, 0x0000, 0x0000,   // 0x00D0 (208) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x86BF, 0x0000, 0x0000, 0x0000, 0x0000, 0x7E3E, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00E0 (224) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00F0 (240) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0100 (256) pixels
};

const uint16_t snow[256] PROGMEM={
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0010 (16) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0020 (32) pixels
0x0000, 0xEF5D, 0xEF7D, 0xDEFB, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0030 (48) pixels
0xCE79, 0xDEDB, 0xCE59, 0xDEFB, 0xFFDF, 0xFFFF, 0xFFFF, 0x0000, 0xAD55, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0040 (64) pixels
0xCE79, 0xB596, 0xB596, 0xBDF7, 0xC618, 0xC618, 0xC639, 0xFFFF, 0xFFDE, 0xF79E, 0xF7BE, 0xCE79, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0050 (80) pixels
0xDEDB, 0xA514, 0xA534, 0xB596, 0xBDD7, 0xB596, 0xDEFB, 0xE73B, 0xE71B, 0xEF5C, 0xF79D, 0xFFDE, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79D,   // 0x0060 (96) pixels
0xEF5D, 0xBDD7, 0xBDD7, 0xAD55, 0xA534, 0xA514, 0xDEBA, 0xDEDA, 0xDEDA, 0xE6FA, 0xE6FA, 0xE6FA, 0xE71B, 0xE71B, 0xE6FA, 0xF7BE,   // 0x0070 (112) pixels
0x0000, 0xBDB6, 0xD658, 0xEEFB, 0xDEBA, 0xE71C, 0xEF5C, 0xD699, 0xD6B9, 0xDEB9, 0xDED9, 0xDED9, 0xDEB9, 0xD699, 0xD6B9, 0xEF7D,   // 0x0080 (128) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFDE, 0xE6FA, 0xDEDA, 0xEF1B, 0xF73B, 0xEF3B, 0xFFFE, 0xFFFF,   // 0x0090 (144) pixels
0x0000, 0x567D, 0x6EBE, 0x6E9D, 0x5DDA, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFBE, 0xEF1B, 0xAEFD, 0x0000, 0x9DF8, 0x0000, 0x0000,   // 0x00A0 (160) pixels
0x0000, 0x46DF, 0x9EFE, 0xA71E, 0x677F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x4E5D, 0x6E7C, 0x6EDF, 0x0000, 0x0000,   // 0x00B0 (176) pixels
0x0000, 0x0000, 0x56FF, 0x673F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5F1F, 0x769D, 0xBF5F, 0x66FF, 0x0000, 0x0000,   // 0x00C0 (192) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x4D58, 0x66DE, 0x7EFF, 0x76FF, 0x0000, 0x0000, 0x571F, 0x66FF, 0x66BE, 0x0000, 0x0000,   // 0x00D0 (208) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x575F, 0x86BD, 0xB73E, 0x671F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00E0 (224) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x571F, 0x671F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00F0 (240) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0100 (256) pixels
};

const uint16_t sunny_period[256] PROGMEM={
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFE20, 0x0000, 0xFE40, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0010 (16) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xDC40, 0xFEA0, 0x0000, 0xFD80, 0x0000, 0xFD60, 0x0000, 0xFEA0, 0x0000, 0x0000, 0x0000,   // 0x0020 (32) pixels
0x0000, 0x0000, 0x0000, 0x61C0, 0xBBE0, 0x0000, 0xFD80, 0xFE40, 0xF580, 0xFE00, 0xF5A0, 0xFE40, 0xFD60, 0x0000, 0xC400, 0x0000,   // 0x0030 (48) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0xFE40, 0xFE20, 0xFDE0, 0xF5C0, 0xF681, 0xF681, 0xF641, 0xF5A0, 0xF600, 0xFE20, 0xFE40, 0x0000,   // 0x0040 (64) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFDA0, 0xF5E1, 0xF6A1, 0xF681, 0xF6A1, 0xF681, 0xF661, 0xF5C0, 0xFDC0, 0x0000, 0x0000,   // 0x0050 (80) pixels
0x0000, 0x0000, 0x0000, 0xFDE0, 0xFD60, 0xF5C0, 0xF641, 0xF6A1, 0xFF20, 0xFF40, 0xF6E0, 0xF661, 0xF5E1, 0xFDE0, 0xFDA0, 0xFE20,   // 0x0060 (96) pixels
0x0000, 0x0000, 0xFFFF, 0xF7FF, 0xF75A, 0xF5E3, 0xEDE0, 0xF6C0, 0xFF60, 0xFFA0, 0xFF40, 0xF681, 0xF601, 0xFDE0, 0x0000, 0x0000,   // 0x0070 (112) pixels
0x0000, 0xFFFF, 0xF77C, 0xEF3C, 0xEF7D, 0xF7FF, 0xF712, 0xF752, 0xFF95, 0xFF65, 0xF6E0, 0xF660, 0xF600, 0xFD60, 0xF560, 0xFDE0,   // 0x0080 (128) pixels
0x0000, 0xFFDE, 0xDEB9, 0xE6FA, 0xE71A, 0xE71B, 0xEF5D, 0xEF5E, 0xEF5E, 0xF7BF, 0xF732, 0xED80, 0xF6CA, 0xF736, 0xFF7A, 0x0000,   // 0x0090 (144) pixels
0x0000, 0xFFBD, 0xDED9, 0xDEDA, 0xE6FA, 0xE71B, 0xE71B, 0xE71B, 0xE71B, 0xE71A, 0xEF7E, 0xFFBF, 0xEF7F, 0xE73D, 0xF79E, 0xF7DF,   // 0x00A0 (160) pixels
0x0000, 0xEF5C, 0xDEB9, 0xDEDA, 0xE6FA, 0xE6FA, 0xE6FA, 0xE71B, 0xE71B, 0xE71B, 0xE6FA, 0xDEFA, 0xDEDA, 0xDEB9, 0xDEB9, 0xF79D,   // 0x00B0 (176) pixels
0xF7BE, 0xD6B9, 0xD699, 0xDEB9, 0xDED9, 0xDEDA, 0xE6FA, 0xE6FA, 0xE6FA, 0xDEDA, 0xDEDA, 0xDEDA, 0xDED9, 0xDEB9, 0xD698, 0xEF5C,   // 0x00C0 (192) pixels
0xEF5C, 0xD678, 0xD678, 0xD699, 0xDEB9, 0xDEB9, 0xDEDA, 0xDED9, 0xDEDA, 0xDEDA, 0xDED9, 0xDEB9, 0xD699, 0xD698, 0xD678, 0xEF5C,   // 0x00D0 (208) pixels
0xFFDF, 0xDEBA, 0xD678, 0xDEB9, 0xDE99, 0xD699, 0xD699, 0xDEB9, 0xDE99, 0xD699, 0xD699, 0xD698, 0xD678, 0xD678, 0xE71B, 0xFFFF,   // 0x00E0 (224) pixels
0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xDEB9, 0xD678, 0xD698, 0xDEB9, 0xEF7C, 0xFFFF, 0xEF5C, 0xE73B, 0xFFFE, 0xFFFF, 0x0000,   // 0x00F0 (240) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xEF3C, 0xEF5C, 0xF7BE, 0x0000, 0x0000, 0x9CF3, 0xA513, 0x0000, 0x0000, 0x0000,   // 0x0100 (256) pixels
};

const uint16_t thunderstorms[256] PROGMEM={
0x0000, 0x0000, 0xF79E, 0xE73C, 0xEF5D, 0xF79E, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0010 (16) pixels
0x0000, 0xFFFF, 0xC638, 0xBDF7, 0xC618, 0xD69A, 0xF7BE, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0020 (32) pixels
0x0000, 0xDEFB, 0xAD75, 0xB5B6, 0xBDD7, 0xBDF7, 0xC618, 0xC638, 0xC618, 0xCE7C, 0xFFD8, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000,   // 0x0030 (48) pixels
0x0000, 0xD6BA, 0xAD55, 0xB5B6, 0xBDD7, 0xBDD7, 0xBDF7, 0xBDF8, 0xB5FB, 0xF620, 0xC616, 0xDF1C, 0xC618, 0xB5B6, 0xCE79, 0xF7BE,   // 0x0040 (64) pixels
0x0000, 0xCE59, 0xA534, 0xB596, 0xB5B6, 0xB5B6, 0xB5B8, 0xB5D9, 0xF620, 0xDDA7, 0xADB9, 0xB596, 0xAD75, 0xAD55, 0xA534, 0xDEFB,   // 0x0050 (80) pixels
0xE71C, 0xA534, 0xA534, 0xAD55, 0xAD75, 0xAD77, 0xB5B6, 0xFE80, 0xFE40, 0xAD98, 0xB596, 0xB596, 0xAD75, 0xAD55, 0xA514, 0xD69A,   // 0x0060 (96) pixels
0xD6BA, 0x9CF3, 0x9CF3, 0xA514, 0xA536, 0xB592, 0xFEA0, 0xFEC0, 0xE687, 0x9D1A, 0xAD75, 0xAD55, 0xAD55, 0xA514, 0x9CF3, 0xD69A,   // 0x0070 (112) pixels
0xEF5D, 0xBDD7, 0xA514, 0xB5B7, 0xAD74, 0xFE40, 0xF6C0, 0xFF40, 0xFFA0, 0xCE4B, 0x9D18, 0x9CF4, 0x9CF3, 0xA514, 0xCE38, 0xF7BE,   // 0x0080 (128) pixels
0x0000, 0xFFFF, 0xEF1C, 0xEF5D, 0xEF9F, 0xBDB2, 0xEE61, 0xFF60, 0xFFA0, 0xFF40, 0xFF00, 0xCE57, 0xCE7A, 0xE6FB, 0x0000, 0x0000,   // 0x0090 (144) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xCEBF, 0xF6E6, 0xFF20, 0xF6E0, 0xFEA0, 0xEE06, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x00A0 (160) pixels
0x0000, 0x0000, 0xA7FF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFEA0, 0xFE60, 0xFF21, 0x0000, 0x0000, 0x0000, 0xA7FF, 0x0000, 0x0000,   // 0x00B0 (176) pixels
0x0000, 0x8F7F, 0x5E5C, 0x0000, 0x0000, 0x0000, 0xFEA0, 0xFD80, 0xE668, 0x0000, 0x0000, 0x0000, 0x6E5B, 0x769D, 0x2E5E, 0x0000,   // 0x00C0 (192) pixels
0x0000, 0x7F1F, 0x1D79, 0x15DD, 0x0000, 0xFF00, 0xFD80, 0xA697, 0x2E7F, 0x0000, 0x0000, 0x0000, 0x8F7F, 0x257A, 0x1DFC, 0x0000,   // 0x00D0 (208) pixels
0x0000, 0x2E1C, 0x1D7A, 0x055E, 0xF6A2, 0xFE00, 0xB630, 0x4E3F, 0x1D9A, 0x1D79, 0x0000, 0x0000, 0x365D, 0x1D79, 0x25FC, 0x0000,   // 0x00E0 (224) pixels
0x0000, 0x26DF, 0x15FF, 0x95EE, 0xFF00, 0x0000, 0x2D9D, 0x1D9A, 0x1D7A, 0x2E1D, 0x0000, 0x0000, 0x267E, 0x265E, 0x36BF, 0x0000,   // 0x00F0 (240) pixels
0x0000, 0x0000, 0x0000, 0xFE40, 0x0000, 0x0000, 0x1433, 0x25BB, 0x25BB, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0100 (256) pixels
};
