#pragma once

enum unicode_names {
    EA1,
    EA1M,
    EA2,
    EA2M,
    AA1,
    AA1M,
    EA3,
    EA3M,
    CA1,
    CA1M,
    OA1,
    OA1M,
    AA2,
    AA2M,
    IA1,
    IA1M,
    UA1,
    UA1M,
    UA2,
    UA2M,
    IA2,
    IA2M,
    UA3,
    UA3M,
    EA4,
    EA4M,
    OA2,
    OA2M,
    EURO
};

const uint32_t PROGMEM unicode_map[] = {
    [EA1]  = 0x00E9, // é
    [EA1M] = 0x00C9, // É
    [EA2]  = 0x00E8, // è
    [EA2M] = 0x00C8, // È
    [AA1]  = 0x00E0, // à
    [AA1M] = 0x00C0, // À
    [EA3]  = 0x00EA, // ê
    [EA3M] = 0x00CA, // Ê
    [CA1]  = 0x00E7, // ç
    [CA1M] = 0x00C7, // Ç
    [OA1]  = 0x00F4, // ô
    [OA1M] = 0x00D4, // Ô
    [AA2]  = 0x00E2, // â
    [AA2M] = 0x00C2, // Â
    [IA1]  = 0x00EE, // î
    [IA1M] = 0x00CE, // Î
    [UA1]  = 0x00FB, // û
    [UA1M] = 0x00DB, // Û
    [UA2]  = 0x00F9, // ù
    [UA2M] = 0x00D9, // Ù
    [IA2]  = 0x00EF, // ï
    [IA2M] = 0x00CF, // Ï
    [UA3]  = 0x00FC, // ü
    [UA3M] = 0x00DC, // Ü
    [EA4]  = 0x00EB, // ë
    [EA4M] = 0x00CB, // Ë
    [OA2]  = 0x0153, // œ
    [OA2M] = 0x0152, // Œ
    [EURO] = 0x20AC, // €
};

#define FR_EA1 XP(EA1, EA1M)
#define FR_EA2 XP(EA2, EA2M)
#define FR_AA1 XP(AA1, AA1M)
#define FR_EA3 XP(EA3, EA3M)
#define FR_CA1 XP(CA1, CA1M)
#define FR_OA1 XP(OA1, OA1M)
#define FR_AA2 XP(AA2, AA2M)
#define FR_IA1 XP(IA1, IA1M)
#define FR_UA1 XP(UA1, UA1M)
#define FR_UA2 XP(UA2, UA2M)
#define FR_IA2 XP(IA2, IA2M)
#define FR_UA3 XP(UA3, UA3M)
#define FR_EA4 XP(EA4, EA4M)
#define FR_OA2 XP(OA2, OA2M)

#define FR_EM1 X(EA1M)
#define FR_EM2 X(EA2M)
#define FR_AM1 X(AA1M)
#define FR_EM3 X(EA3M)
#define FR_CM1 X(CA1M)
#define FR_OM1 X(OA1M)
#define FR_AM2 X(AA2M)
#define FR_IM1 X(IA1M)
#define FR_UM1 X(UA1M)
#define FR_UM2 X(UA2M)
#define FR_IM2 X(IA2M)
#define FR_UM3 X(UA3M)
#define FR_EM4 X(EA4M)
#define FR_OM2 X(OA2M)

#define EURO X(EURO)
