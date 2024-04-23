#pragma once

#define MARIO_THEME \
    Q__NOTE(_E5), \
    H__NOTE(_E5), \
    H__NOTE(_E5), \
    Q__NOTE(_C5), \
    H__NOTE(_E5), \
    W__NOTE(_G5), \
    Q__NOTE(_G4),

#define MARIO_GAMEOVER \
    HD_NOTE(_C5 ), \
    HD_NOTE(_G4 ), \
    H__NOTE(_E4 ), \
    H__NOTE(_A4 ), \
    H__NOTE(_B4 ), \
    H__NOTE(_A4 ), \
    H__NOTE(_AF4), \
    H__NOTE(_BF4), \
    H__NOTE(_AF4), \
    WD_NOTE(_G4 ),

#define MARIO_MUSHROOM \
    S__NOTE(_C5 ), \
    S__NOTE(_G4 ), \
    S__NOTE(_C5 ), \
    S__NOTE(_E5 ), \
    S__NOTE(_G5 ), \
    S__NOTE(_C6 ), \
    S__NOTE(_G5 ), \
    S__NOTE(_GS4), \
    S__NOTE(_C5 ), \
    S__NOTE(_DS5), \
    S__NOTE(_GS5), \
    S__NOTE(_DS5), \
    S__NOTE(_GS5), \
    S__NOTE(_C6 ), \
    S__NOTE(_DS6), \
    S__NOTE(_GS6), \
    S__NOTE(_DS6), \
    S__NOTE(_AS4), \
    S__NOTE(_D5 ), \
    S__NOTE(_F5 ), \
    S__NOTE(_AS5), \
    S__NOTE(_D6 ), \
    S__NOTE(_F6 ), \
    S__NOTE(_AS6), \
    S__NOTE(_F6 )

#define E1M1_DOOM  \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_D4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_C4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_BF3), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_B3 ), \
    Q__NOTE(_C4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_D4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_C4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    H__NOTE(_BF3),

#define ALL_STAR \
    E__NOTE(_AS4), Q__NOTE(_FS4), S__NOTE(_FS4), S__NOTE(_DS4), E__NOTE(_FS4), Q__NOTE(_FS4), S__NOTE(_FS4), S__NOTE(_DS4), \
    E__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_FS4), QD_NOTE(_AS4), \
    E__NOTE(_AS4), Q__NOTE(_FS4), S__NOTE(_FS4), S__NOTE(_DS4), E__NOTE(_FS4), Q__NOTE(_FS4), S__NOTE(_FS4), S__NOTE(_DS4), \
    E__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_AS4), E__NOTE(_REST),\
    Q__NOTE(_AS4), Q__NOTE(_CS5), E__NOTE(_B4), E__NOTE(_CS5), E__NOTE(_DS5), Q__NOTE(_FS5), \
    E__NOTE(_GS5), Q__NOTE(_GS5), E__NOTE(_FS4), E__NOTE(_FS4), E__NOTE(_GS4), E__NOTE(_FS4), \
    E__NOTE(_AS4), Q__NOTE(_GS4), Q__NOTE(_GS4), Q__NOTE(_FS4), Q__NOTE(_GS4), \
    E__NOTE(_AS4), HD_NOTE(_DS4), \
    H__NOTE(_AS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), H__NOTE(_FS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), \
    H__NOTE(_FS4), W__NOTE(_FS4), W__NOTE(_FS4), QD_NOTE(_AS4), \
    H__NOTE(_AS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), H__NOTE(_FS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), \
    H__NOTE(_FS4), W__NOTE(_FS4), W__NOTE(_FS4), W__NOTE(_AS4), H__NOTE(_REST),\
    W__NOTE(_AS4), W__NOTE(_CS5), H__NOTE(_B4),  H__NOTE(_CS5), H__NOTE(_DS5), W__NOTE(_FS5), \
    H__NOTE(_GS5), W__NOTE(_GS5), H__NOTE(_FS4), H__NOTE(_FS4), H__NOTE(_GS4), H__NOTE(_FS4), \
    H__NOTE(_AS4), W__NOTE(_GS4), W__NOTE(_GS4), W__NOTE(_FS4), W__NOTE(_GS4), \
    H__NOTE(_AS4), WD_NOTE(_DS4)

#define IMPERIAL_MARCH \
  HD_NOTE(_A4), HD_NOTE(_A4), HD_NOTE(_A4), QD_NOTE(_F4), QD_NOTE(_C5), \
  HD_NOTE(_A4), QD_NOTE(_F4),  QD_NOTE(_C5), WD_NOTE(_A4), \
  HD_NOTE(_E5), HD_NOTE(_E5), HD_NOTE(_E5), QD_NOTE(_F5), QD_NOTE(_C5), \
  HD_NOTE(_A4), QD_NOTE(_F4),  QD_NOTE(_C5), WD_NOTE(_A4)


  #define BASKET_CASE \
    QD_NOTE(_G3), E__NOTE(_F3), E__NOTE(_E3), Q__NOTE(_F3), M__NOTE(_G3, 8+32), Q__NOTE(_REST), \
    Q__NOTE(_B4), Q__NOTE(_C4), Q__NOTE(_B4), E__NOTE(_A4), Q__NOTE(_G3), M__NOTE(_G3, 8+32), Q__NOTE(_REST), \
    Q__NOTE(_B4), Q__NOTE(_C4), Q__NOTE(_B4), E__NOTE(_A4), Q__NOTE(_G3), Q__NOTE(_G3), Q__NOTE(_G3), Q__NOTE(_G3), E__NOTE(_A4), E__NOTE(_C4), QD_NOTE(_B4), HD_NOTE(_B4)

#define COIN_SOUND \
    E__NOTE(_A5  ),      \
    HD_NOTE(_E6  ),

#define ZELDA_TREASURE \
    Q__NOTE(_A4 ), \
    Q__NOTE(_AS4), \
    Q__NOTE(_B4 ), \
    HD_NOTE(_C5 ),

#define ZELDA_PUZZLE \
    Q__NOTE(_G5),     \
    Q__NOTE(_FS5),    \
    Q__NOTE(_DS5),     \
    Q__NOTE(_A4),    \
    Q__NOTE(_GS4),     \
    Q__NOTE(_E5),     \
    Q__NOTE(_GS5),     \
    HD_NOTE(_C6),

#define RICK_ROLL      \
    Q__NOTE(_F4),      \
    Q__NOTE(_G4),      \
    Q__NOTE(_BF4),     \
    Q__NOTE(_G4),      \
    HD_NOTE(_D5),      \
    HD_NOTE(_D5),      \
    W__NOTE(_C5),      \
    S__NOTE(_REST),    \
    Q__NOTE(_F4),      \
    Q__NOTE(_G4),      \
    Q__NOTE(_BF4),     \
    Q__NOTE(_G4),      \
    HD_NOTE(_C5),      \
    HD_NOTE(_C5),      \
    W__NOTE(_BF4),     \
    S__NOTE(_REST),    \
    Q__NOTE(_F4),      \
    Q__NOTE(_G4),      \
    Q__NOTE(_BF4),     \
    Q__NOTE(_G4),      \
    W__NOTE(_BF4),     \
    H__NOTE(_C5),      \
    H__NOTE(_A4),      \
    H__NOTE(_A4),      \
    H__NOTE(_G4),      \
    H__NOTE(_F4),      \
    H__NOTE(_F4),      \
    W__NOTE(_C5),      \
    W__NOTE(_BF4),

    /* Melody from the main themes of Star Trek TNG and the original series */
#define TO_BOLDLY_GO \
  W__NOTE(_BF3 ), \
  Q__NOTE(_EF4 ), \
  WD_NOTE(_AF4 ), \
  W__NOTE(_REST), \
  H__NOTE(_G4  ), \
  Q__NOTE(_EF4 ), \
  H__NOTE(_C4  ), \
  W__NOTE(_REST), \
  QD_NOTE(_F4  ), \
  M__NOTE(_BF4, 128),

#define KATAWARE_DOKI \
  W__NOTE(_G5), HD_NOTE(_G5), Q__NOTE(_G5), H__NOTE(_G5), H__NOTE(_E5), H__NOTE(_D5), Q__NOTE(_D5), Q__NOTE(_C5), \
  B__NOTE(_E5), H__NOTE(_C5), W__NOTE(_G5), HD_NOTE(_G5), Q__NOTE(_C5), H__NOTE(_C6), Q__NOTE(_B5), \
  Q__NOTE(_A5), H__NOTE(_G5), Q__NOTE(_G5), Q__NOTE(_A5), W__NOTE(_G5), QD_NOTE(_E5), \
  QD_NOTE(_F5), Q__NOTE(_E5), WD_NOTE(_D5), H__NOTE(_C5), W__NOTE(_G5), HD_NOTE(_G5), Q__NOTE(_G5), \
  H__NOTE(_G5), H__NOTE(_E5), H__NOTE(_D5), Q__NOTE(_D5), Q__NOTE(_C5), B__NOTE(_E5), H__NOTE(_G4), \
  Q__NOTE(_C5), Q__NOTE(_D5), Q__NOTE(_E5), H__NOTE(_D5), Q__NOTE(_C5), Q__NOTE(_C5), \
  Q__NOTE(_A4), H__NOTE(_C5), Q__NOTE(_C5), W__NOTE(_C5), Q__NOTE(_F4), Q__NOTE(_C5), \
  Q__NOTE(_D5), Q__NOTE(_E5), H__NOTE(_D5), H__NOTE(_C5), Q__NOTE(_C5), H__NOTE(_G5), \
  Q__NOTE(_C5), HD_NOTE(_D5), H__NOTE(_G4), Q__NOTE(_C5), Q__NOTE(_D5), Q__NOTE(_E5), \
  H__NOTE(_D5), Q__NOTE(_C5), Q__NOTE(_C5), Q__NOTE(_A4), H__NOTE(_C5), Q__NOTE(_C5), \
  W__NOTE(_C5), Q__NOTE(_F4), Q__NOTE(_C5), Q__NOTE(_D5), Q__NOTE(_E5), H__NOTE(_D5), \
  H__NOTE(_C5), Q__NOTE(_C5), H__NOTE(_G5), Q__NOTE(_C5), HD_NOTE(_D5), \
  HD_NOTE(_G4), Q__NOTE(_C5), Q__NOTE(_D5), BD_NOTE(_C5),
