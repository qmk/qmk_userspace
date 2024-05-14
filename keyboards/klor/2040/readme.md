# KLOR keyboard with RP2040 MCU

This is the RP2040 revision of the firmware.
You can use several RP2040 based MCUs with Pro Micro formfactor.
By default the config is setup for the pinout of the Sparkfun Pro Micro RP2040, which is used by most of the RP2040 based MCUs. Since the KB2040/Blok/Elite-Pi have a slightly different pinout you need to change this line
`CONVERT_TO = promicro_rp2040`
to one of tis lines
`CONVERT_TO = kb2040`
`CONVERT_TO = blok`
`CONVERT_TO = elite_pi`
 in the `/2040/rules.mk` file.


## Bootloader

Enter the bootloader in 3 ways:

- **Keycode in layout**: Press the key mapped to `QK_BOOTLOADER` if it is configured.
- **Physical reset button**: Quick double-tap on the reset button soldered on the PCB.
- **Controller boot button**: Hold the `BOOT` button on the controller and plug in the USB.
- **Bootmagic reset**: Hold down the top left key on the left half and plug in the controller.
