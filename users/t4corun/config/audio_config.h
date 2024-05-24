#pragma once

/* Audio
*
* https://docs.qmk.fm/#/feature_audio
* https://docs.qmk.fm/#/squeezing_avr?id=audio-settings
*
*/

//Clear variables we plan to use that might be set elsewhere
#undef NO_MUSIC_MODE
#undef AUDIO_CLICKY
#undef STARTUP_SONG
#undef GOODBYE_SONG
#undef DEFAULT_LAYER_SONGS
#undef KLOR_SOUND

//Set common configuration for all keyboards
#define KLOR_SOUND W__NOTE(_DS0), W__NOTE(_DS1), H__NOTE(_DS2), H__NOTE(_DS3), Q__NOTE(_DS4), Q__NOTE(_DS5), E__NOTE(_DS6), E__NOTE(_DS7), S__NOTE(_DS8), Q__NOTE(_GS0)
#define BYE_SOUND H__NOTE(_DS4), H__NOTE(_DS3), W__NOTE(_DS1)

#define NO_MUSIC_MODE
#define AUDIO_CLICKY
#define STARTUP_SONG SONG(KLOR_SOUND)
#define GOODBYE_SONG SONG(BYE_SOUND)
#define DEFAULT_LAYER_SONGS \
  { SONG(QWERTY_SOUND)      \
    ,SONG(COLEMAK_SOUND)    \
    ,SONG(GUITAR_SOUND)     \
  }
