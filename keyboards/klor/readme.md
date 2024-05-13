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

t4croun: this is my attempt at modernizing @geigeigeist's keymap. The repo has not been updated in a few years and QMK has introduced breaking changes. His repo can be found [here](https://github.com/GEIGEIGEIST/qmk-config-klor). Note: Focusing on defining my saegewerk configuration as that is what I have

You can use this command to compile the firmware
`qmk compile -kb klor -km default`

and this command if you want to compile the firmware for a RP2040 based MCU
`qmk compile -kb klor/2040 -km default`