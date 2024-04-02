# T4CORUN Userspace

My userspace for building QMK firmware via GitHub Actions. This does not require a local build environment where files are placed within keyboard subfolders.

The custom layout optimizes for programming (SQL, Powershell, C) and minimizes holds for comfort. It started from [Manna Harbor Miryoku](https://github.com/manna-harbour/miryoku) and took heavy influence from [Jonas Hietala T-34](https://www.jonashietala.se/series/t-34/)

## Features

### Layout Wrapper Macros

A single keymap layout can be shared with multiple keyboards by using C preprocessor macros. These macros are referenced in the keyboard JSON files, and the build process will expand them into a transient keymap.c file during compile time.

In this userspace, the base split 3x5_2 layout can be adapted for other split keyboards by expanding it with macros. For example, there is a wrapper that will add extra columns to the base layout for a Corne's 42-key 3x6_3 layout.

### Tri-Layer

Hold both thumb momentary layer keys `NAV` and `SYM` to access the `_NUMBER` layer

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

### Mouse Keys

Enables mouse emulation for all boards. Required when using the Ploopy Nano as that has no mouse buttons.

Hold `a` to enter `_MOUSE` layer. Use right side directional pad (e.g. IJKL) to move the cursor and left side thumb keys for basic mouse clicking.

### RGB Matrix

Taste the rainbow for boards with RGB LEDs and large MCU memory footprints. Enables RGB lighting effects and layer/host status indicators. Review the keyboard files to identify the key position for each LED and update the preprocessor definitions in `config\rgbmatrix_config.h`

**Known Issue** Commented out logic for layer/host status indicator LEDs as it caused random flickering on split side boards

### OLED

Enables keyboard status visualization. Shows currently selected layer, active modifiers, and host status (e.g, Num / Caps / Scroll Lock)

### Combos

Enables simultaneous pressing of key combinations to get another. Handy when there are not enough keys on the keyboard

**Note** Framework is present but disabled during redesign

## Layout

This is the keymap designed for split 3x5 layout, two thumb keys on each side, and dual encoders. Emphasis on:

- Releasing all keys always brings you back to base layer
- Keeping certain keys consistent on all layers for better muscle memory
- Numbers and function keys are positioned similarly
- Symbols important for powershell / writing are positioned under stronger fingers
- Game keymap that doesn't require massive game key bind changes. Tested on Resident Evil 4 Remake

Additional keys may be mapped if present. Check each keyboard's `keymap.c` for more information

```text
╭──────┬──────┬──────┬──────┬──────╮         ╭──────┬──────┬──────┬──────┬──────╮
│ q    │ w    │ e    │ r    │ t    │         │ y    │ u    │ i    │ o    │ p    │
├──────┼──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┼──────┤
│ a mou│ s    │ d    │ f    │ g    │ qwerty  │ h    │ j    │ k    │ l    │ ' "  │
├──────┼──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┼──────┤
│ z    │ x    │ c    │ v    │ b    │         │ n    │ m    │ , (  │ . )  │ - _  │
╰──────┴──────┴──────┼──────┼──────┤         ├──────┼──────┼──────┴──────┴──────╯
                     │ sym  │ mou  │         │ spc  │ nav  │
                     ╰──────┴──────╯         ╰──────┴──────╯

╭──────┬──────┬──────┬──────┬──────╮         ╭──────┬──────┬──────┬──────┬──────╮
│ q    │ w    │ f    │ p    │ b    │         │ j    │ l    │ u    │ y    │ o    │
├──────┼──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┼──────┤
│ a mou│ r    │ s    │ t    │ g    │ colemak │ m    │ n    │ e    │ i    │ ' "  │
├──────┼──────┼──────┼──────┼──────┤   dh    ├──────┼──────┼──────┼──────┼──────┤
│ z    │ x    │ c    │ d    │ v    │         │ k    │ h    │ , (  │ . )  │ - _  │
╰──────┴──────┴──────┼──────┼──────┤         ├──────┼──────┼──────┴──────┴──────╯
                     │ sym  │ mou  │         │ spc  │ nav  │
                     ╰──────┴──────╯         ╰──────┴──────╯
Notes:
- swapped o and repeat on this keymap to keep repeat key in the same position across layers

╭──────┬──────┬──────┬──────┬──────╮         ╭──────┬──────┬──────┬──────┬──────╮
│ tab  │ q    │ w    │ e    │ r    │         │      │      │      │      │      │
├──────┼──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┼──────┤
│ gnum │ a    │ s    │ d    │ f    │  game   │      │      │      │      │      │
├──────┼──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┼──────┤
│ z    │ x    │ c    │ v    │ b    │         │      │      │      │      │      │
╰──────┴──────┴──────┼──────┼──────┤         ├──────┼──────┼──────┴──────┴──────╯
                     │ shft │ spc  │         │ spc  │ nav  │
                     ╰──────┴──────╯         ╰──────┴──────╯

╭──────┬──────┬──────┬──────┬──────╮         ╭──────┬──────┬──────┬──────┬──────╮
│ esc  │ home │ up   │ end  │ pgup │         │ ins  │      │ app  │      │ cfg  │
├──────┼──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┼──────┤
│      │ left │ down │ rght │ pgdn │   nav   │ bksp │ shft │ ctrl │ alt  │ gui  │
├──────┼──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┼──────┤
│ undo │ cut  │ copy │ pste │ redo │         │ del  │ tab  │ vol- │ vol+ │ mute │
╰──────┴──────┴──────┼──────┼──────┤         ├──────┼──────┼──────┴──────┴──────╯
                     │ sym  │ ent  │         │      │ nav  │
                     ╰──────┴──────╯         ╰──────┴──────╯

╭──────┬──────┬──────┬──────┬──────╮         ╭──────┬──────┬──────┬──────┬──────╮
│ esc  │ snip │ file │ func │ ` ~  │         │ ent  │ 7    │ 8    │ 9    │ tab  │
├──────┼──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┼──────┤
│ gui  │ alt  │ ctrl │ shft │ ; :  │ numbers │ bksp │ 4    │ 5    │ 6    │ .    │
├──────┼──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┼──────┤
│ undo │ cut  │ copy │ pste │ redo │         │ del  │ 1    │ 2    │ 3    │ - _  │
╰──────┴──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┴──────╯
              │      │ sym  │      │         │ spc  │ 0 nav│      │
              ╰──────┴──────┴──────╯         ╰──────┴──────┴──────╯

╭──────┬──────┬──────┬──────┬──────╮         ╭──────┬──────┬──────┬──────┬──────╮
│ esc  │      │ @    │ $    │ ` ~  │         │ = +  │ #    │ *    │      │ " "" │
├──────┼──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┼──────┤
│ &    │ { {} │ }    │ |    │ ; :  │ symbols │ bksp │ ?    │ [ [] │ ]    │ ' '' │
├──────┼──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┼──────┤
│ % ^  │ < <> │ >    │ \    │ !    │         │ del  │ /    │ , () │ . )  │ - _  │
╰──────┴──────┴──────┼──────┼──────┤         ├──────┼──────┼──────┴──────┴──────╯
                     │ sym  │      │         │      │ nav  │
                     ╰──────┴──────╯         ╰──────┴──────╯

Notes:
- tri layer: Activate th the symbol layer by holding down symbol and navigation

╭──────┬──────┬──────┬──────┬──────╮         ╭──────┬──────┬──────┬──────┬──────╮
│ mply2│ mrec2│      │ func │      │         │ pscr │ F7   │ F8   │ F9   │ F10  │
├──────┼──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┼──────┤
│      │      │      │      │ scrl │  func   │ caps │ F4   │ F5   │ F6   │ F11  │
├──────┼──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┼──────┤
│      │      │      │      │      │         │ paus │ F1   │ F2   │ F3   │ F12  │
╰──────┴──────┴──────┼──────┼──────┤         ├──────┼──────┼──────┴──────┴──────╯
                     │ sym  │      │         │ mply1│ mrec1│
                     ╰──────┴──────╯         ╰──────┴──────╯

╭──────┬──────┬──────┬──────┬──────╮         ╭──────┬──────┬──────┬──────┬──────╮
│      │ btn5 │ btn4 │ btn3 │      │         │ whup │      │ mouu │      │      │
├──────┼──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┼──────┤
│ mou  │ alt  │ ctrl │ shft │      │  mouse  │ whdn │ moul │ moud │ mour │      │
├──────┼──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┼──────┤
│      │      │      │ drgs │ snip │         │ sdpi │ pdpi │      │      │      │
╰──────┴──────┴──────┼──────┼──────┤         ├──────┼──────┼──────┴──────┴──────╯
                     │ btn1 │ btn2 │         │      │      │
                     ╰──────┴──────╯         ╰──────┴──────╯

Notes:
- drgs on non Charybdis Nano boards will trigger drag scrolling on Ploopy Nano
- pdpi on non Charybdis Nano boards will cycle Ploopy Nano DPI settings
- both together will enter bootlaoder on Ploopy Nano

╭──────┬──────┬──────┬──────┬──────╮         ╭──────┬──────┬──────┬──────┬──────╮
│      │ esc  │ `    │ g    │ t    │         │      │      │      │      │      │
├──────┼──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┼──────┤
│ gnum │ 1    │ 2    │ 3    │ 4    │  game   │      │      │      │      │      │
├──────┼──────┼──────┼──────┼──────┤    num  ├──────┼──────┼──────┼──────┼──────┤
│      │ 5    │ 6    │ 7    │ 8    │         │      │      │      │      │      │
╰──────┴──────┴──────┼──────┼──────┤         ├──────┼──────┼──────┴──────┴──────╯
                     │ alt  │ ctr  │         │      │ nav  │
                     ╰──────┴──────╯         ╰──────┴──────╯

╭──────┬──────┬──────┬──────┬──────╮         ╭──────┬──────┬──────┬──────┬──────╮
│      │      │      │      │      │         │ eeclr│ rboot│ boot │      │ cfg  │
├──────┼──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┼──────┤
│rgbtog│rgbMod│      │      │      │ config  │      │ shft │ ctrl │ alt  │ gui  │
├──────┼──────┼──────┼──────┼──────┤         ├──────┼──────┼──────┼──────┼──────┤
│ hue+ │ sat+ │ vib+ │ spd+ │ game │         │      │      │      │      │      │
╰──────┴──────┴──────┼──────┼──────┤         ├──────┼──────┼──────┴──────┴──────╯
                     │clmkdh│qwerty│         │      │ nav  │
                     ╰──────┴──────╯         ╰──────┴──────╯
```

## Target Keyboards

- Bastardkb Charybdis Nano 3x5
- Crkbd 3x6
- Planck Rev6
- DZRGB60v2 (combing)
- Ferris Swoop (coming)
- Geist KLOR (coming)

## Links

- [qmk documentation](https://docs.qmk.fm/#/)
- [qmk/awesome-userspaces Github](https://github.com/qmk/awesome-userspaces?tab=readme-ov-file). Links to fantastic userspaces to draw inspiration from, such as Drashna's

