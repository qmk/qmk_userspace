```text
█         █    █            ▄▄▄▀▀▀▀▀▀▄▄▄        █▀▀▀▀▀▀▀▀▀▀█
█        █     █          ▄▀            ▀▄      █          █
█       █      █        ▄▀                ▀▄    █          █
█      █       █        █                  █    █          █
█     █        █       █                    █   █          █
█    █         █       █                    █   █▄▄▄▄▄▄▄▄▄▄█
█   █ █        █       █                    █   █      █
█  █   █       █        █                  █    █       █
█ █     █      █        ▀▄                ▄▀    █        █
██       █     █          ▀▄            ▄▀      █         █
█         █    █▄▄▄▄▄▄▄▄    ▀▀▀▄▄▄▄▄▄▀▀▀        █          █
```

# KLOR split keyboard

KLOR is 42 keys column-staggered split keyboard made by @geigeigeist. It supports a per key RGB matrix, encoders, OLED displays, haptic feedback, audio, a Pixart Paw3204 trackball and four different layouts, through brake off parts.
It's schematics are based on the Sofle, while the layout is based on the Yacc46.

You can use this command to compile the firmware
`qmk compile -kb klor -km default`

and this command if you want to compile the firmware for a RP2040 based MCU
`qmk compile -kb klor/2040 -km default`

## t4corun modernization

this is my attempt at modernizing @geigeigeist's repo. It has not been updated in a few years and firmware cannot be built as-is as QMK has introduced breaking changes. @geigeigeist's repo can be found [here](https://github.com/GEIGEIGEIST/qmk-config-klor). Should work for all KLOR variations, but I tested against Saegwerk as that is the one I have

Features

- Can choose layout based on keymap rules.mk configuration. Before keyboard configuration would need to be changed
- Converted as much as possible to data driven configuration: `info.json`

What I did not test

- RGBLight
- Other variations (e.g.Polydactyl)
- Swap Hands