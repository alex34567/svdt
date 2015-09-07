// secure_values.h: offsets for and ways to identify games with ASR

#define PRECONF_GAMES 7
// ACNL, SSB, Poke Shuffle, Poke X/Y/OR/AS
// not including Poke Rumble World, which has to be handled differently
#define ACNL_OFFSET     0x0
#define SSB_OFFSET      0x10
#define POKETORU_OFFSET 0x2c
#define POKEXY_OFFSET   0x65400
#define POKEORAS_OFFSET 0x75e00

#define SECURE_VALUE_SIZE 8

typedef enum secureGame
{
    SECURE_ACNL,
    SECURE_SSB,
    SECURE_POKETORU,
    SECURE_POKEX,
    SECURE_POKEY,
    SECURE_POKEOR,
    SECURE_POKEAS,
    SECURE_POKERW,
    SECURE_EMERGENCY,
    SECURE_CONFIG,
    SECURE_UNKNOWN
} secureGame;

extern int secureValueSet;
extern u8 secureValue[SECURE_VALUE_SIZE];

Result checkCustomSecureGame();
Result checkSecureConfig();
secureGame secureGameFromProductCode(const char* productCode);
secureGame secureGameFromFilesystem();
Result getSecureValue(secureGame whichSecureGame);
Result getSecureValue2(const char* productCode);
Result getPokeRumbleProps(u64* compressed_size, u64* decompressed_size, int* is_compressed, u32* crc32_check);
Result getPokeRumbleSecureValue();
Result writeSecureValue(secureGame whichSecureGame);
Result writeSecureValue2(const char* productCode);
Result writePokeRumbleSecureValue();
