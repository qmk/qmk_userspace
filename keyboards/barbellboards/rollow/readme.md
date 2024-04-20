# Rollow

![Rollow](https://assets.bigcartel.com/product_images/327532800/BothBoards_Logo.png?auto=format&fit=max&h=300)

*Author's Note: Converting my ZMK Rollow to QMK, I decided to port/modernize Barbell Boards Rollow keyboard definition. Setting up a new definition here as his github account shows no activity since mid 2022. Ultimately, this is a fun exercise for me to better understand how to setup a new keyboard especially under the current standards. I take no credit for Barry's awesome hardware design.*

Rollow is low-profile 3x6+2 keys column-staggered split keyboard with horizontal thumb encoders. Based off Corne and also available in a 3x5+2 variant

The current build guide is [available here](https://github.com/barbellboards/Rollow/blob/main/Instructions/BuildGuide.md)

* Keyboard Maintainer: [Barbell Boards](https://github.com/barbellboards) and [t4corun](https://github.com/t4corun/qmk_userspace)
* Hardware Supported: Rollow Rev 1
* Hardware Availability: No longer available after initial Summer 2022 production run

Make example for this keyboard (after setting up your build environment):

```bash
make barbellboards/rollow:default
# or
qmk compile -kb barbellboards/rollow -km default
```

Flashing example for this keyboard:

```bash
make barbellboards/rollow:default:flash
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available