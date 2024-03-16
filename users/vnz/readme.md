# Overview

Unicode keys are defined in the vnz.h file and need to be included in the keymap.c files.

```C
#include "vnz.h"
```

* Atlas

```bash
qmk compile -kb cannonkeys/atlas -km vnz
qmk flash -kb cannonkeys/atlas -km vnz
```

* Preonic

```bash
qmk compile -kb preonic/rev3 -km vnz
qmk flash -kb preonic/rev3 -km vnz

qmk compile -kb preonic/rev3_drop -km vnz
qmk flash -kb preonic/rev3_drop -km vnz
```

* GK6

```bash
qmk compile -kb gizmo_engineering/gk6 -km vnz
qmk compile -kb gizmo_engineering/gk6 -km vnz
```

* XD75

```bash
qmk compile -kb xiudi/xd75 -km vnz
qmk flash -kb xiudi/xd75 -km vnz
```

* CU7

```bash
qmk compile -kb capsunlocked/cu7 -km vnz
qmk flash -kb capsunlocked/cu7 -km vnz
```

* Treasure Type9

```bash
qmk compile -kb treasure/type9s2 -km vnz
qmk flash -kb treasure/type9s2 -km vnz
```

* Boardwalk

* KBD8x

* Damapad

```bash
qmk compile -kb bolsa/damapad -km vnz
qmk flash -kb bolsa/damapad -km vnz
```

* lulu

```bash
qmk compile -kb boardsource/lulu/rp2040 -km vnz
qmk flash -kb boardsource/lulu/rp2040 -km vnz
```

* Add a new keymap

```bash
cd ~/code/qmk/qmk_firmware
qmk new-keymap -kb <keyboard> -km <keymap>
```
