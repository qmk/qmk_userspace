# T4CORUN Userspace

My userspace for building QMK firmware via GitHub Actions. This does not require a local build environment where files are placed within keyboard subfolders.

## Layout

The custom layout optimizes for programming (SQL, Powershell, C) and minimizes holds for comfort. It started from [Manna Harbor Miryoku](https://github.com/manna-harbour/miryoku) and took heavy influence from [Jonas Hietala T-34](https://www.jonashietala.se/series/t-34/). The keymap designed for split 3x5, two thumbs keys, dual encoders, and combined with a Ploopy Nano trackball mouse. Design themes:

- Releasing all keys always brings you back to base layer
- Keeping certain keys consistent on all layers for better muscle memory
- Numbers and function keys are positioned similarly
- Symbols important for powershell / writing are positioned under stronger fingers
- Game keymap that doesn't require massive game key bind changes. Tested on Resident Evil 4 Remake

Notes:

- Outside thumb keys are encoder clicks. Some keyboards may have extra thumb keys
- Pressing Pointer DPI and Drag Scroll Toggle will enter bootlaoder on Ploopy Nano

![image](my_keymap.png)

## Features

### Build Non-Tree Keyboards

- Extended the [qmk/.github](https://github.com/qmk/.github) userspace build actions to build non-tree qmk keyboards (e.g. Barbellboards Rollow). This works by copying keyboard definitions from the userspace to the qmk_firmware keyboards folder in the container. The list of keyboards to copy are defined in `qmk_nontree.json`

### Layout Wrapper Macros

A single keymap layout can be shared with multiple keyboards by using C preprocessor macros. These macros are referenced in the keyboard JSON files, and the build process will expand them into a transient keymap.c file during compile time.

In this userspace, the base split 3x5_3 layout can be adapted for other split keyboards by expanding it with macros. For example, there is a wrapper that will add extra columns to the base layout for a Corne's 42-key 3x6_3 layout.

### Tri-Layer

Hold both thumb momentary layer keys `NAV` and `SYM` to access the `_SYMBOL` layer

### One Shot Mods

One Shot Mods is here to minimize holding and simplify layers as mods are not required on every layer. Here we have bi-lateral(ish) GACS mods.

### Caps Word

Caps Word enables temporary all-caps typing without holding shift. Useful to typing programming variables. Tap `shift`  twice to enable Caps Word. It cancels when any key is pressed except

- `numbers 0-9`
- `backspace`
- `delete`
- `underscore`

### Tap-Holds

Certain keys have different behaviors when held vs tapped allowing commonly typed characters or auto-shifting certain keycodes

| Keycode   | When tapped | When held               | Comments                          |
| --------- | ----------- | ----------------------- | --------------------------------- |
| `TR_LBRC` | `[`         | `[]` with cursor inside |                                   |
| `TH_LCBR` | `{`         | `{}` with cursor inside |                                   |
| `TR_LABK` | `<`         | `<>` with cursor inside |                                   |
| `TR_LPRN` | `(`         | `()` with cursor inside |                                   |
| `TR_PERC` | `%`         | `^`                     |                                   |
| `TR_COMM` | `,`         | `(`                     | enables parenthesis on base layer |
| `TR_DOT`  | `.`         | `)`                     |                                   |

`Update this table later`

## Optional Features

These features can be disabled due to MCU size constraints or because certain keyboards do not support it

### Pointing Device

Enables trackball functionality on certain boards (e.g., Ploopy Nano and Bastardkb Charybdis Nano). The board definitions enables unique functionality:

- Charybdis Nano: "Sniper" precision tracking, drag Scroll, DPI changes
- Ploopy Nano: Ties with Host Status LED macros to enable drag scroll, dpi changes, and bootloader

Note: `MOUSEKEY_ENABLE` do not need to be enabled in tandem with this to get the mouse buttons.

### RGB Matrix

Taste the rainbow for boards with RGB LEDs and large MCU memory footprints. Enables RGB lighting effects and layer/host status indicators. Review the keyboard files to identify the key position for each LED and update the preprocessor definitions in `config\rgbmatrix_config.h`

**Known Issue** Commented out logic for layer/host status indicator LEDs as it caused random flickering on split side boards

### OLED

Enables keyboard status visualization. Shows currently selected layer, active modifiers, and host status (e.g, Num / Caps / Scroll Lock)

### Combos

Enables simultaneous pressing of key combinations to get another. Handy when there are not enough keys on the keyboard. Primarily used to implement mouse buttons and make important keys (enter, backspace, etc) available on base layer

## Target Keyboards

All boards use my keymaps unless noted

- Ploopy Nano: `lkbm` keymap
- Bastardkb Charybdis Nano 3x5
- Crkbd 3x6
- Planck Rev6
- Ferris Swoop
- Barbell Rollow (non-tree)
- DZRGB60v2 (coming)
- Geist KLOR (coming)

## Links

- [qmk documentation](https://docs.qmk.fm/#/)
- [qmk/awesome-userspaces Github](https://github.com/qmk/awesome-userspaces?tab=readme-ov-file). Links to fantastic userspaces to draw inspiration from, such as Drashna's
