# PandaKB Lily58 — ash

Vial firmware for the PandaKB Lily58 (RP2040), built on [vial-qmk](https://github.com/vial-kb/vial-qmk).

## Source

The board definition and keymap come from PandaKB's [QMK-firmware-for-keyboards](https://github.com/PandaKBLab/QMK-firmware-for-keyboards/tree/main/lily58) repo:

- `lily58/lily58/` → `keyboards/lily58/pandakb/`
- `lily58/lily58/keymaps/vial/` → `keyboards/lily58/pandakb/keymaps/ash/`

## Editing the keymap

All keymap changes are made in [Vial](https://get.vial.today/). `keymap.c` only holds the defaults that get loaded on first boot or after an EEPROM reset.

## Building

The Nix flake provides the toolchain, `qmk`, and `picotool`. With [direnv](https://direnv.net/), run `direnv allow` once in the repo root and the dev shell loads automatically (otherwise run `nix develop` first).

```sh
make lily58/pandakb:ash
```

This produces `lily58_pandakb_ash.uf2` in the repo root. CI builds every push to `vial` and publishes it as a GitHub Release named `<date>-<commit>`.

## Flashing

Flash the same `.uf2` to both halves (handedness is read from a pin). Plug in one half and double-tap its reset switch to enter the bootloader, then use any of the following:

- **Drag and drop:** the half mounts as a USB drive named `RPI-RP2`. Copy `lily58_pandakb_ash.uf2` onto it; the half reboots when the copy finishes.
- **picotool:** `picotool load -x lily58_pandakb_ash.uf2`
- **QMK:** `make lily58/pandakb:ash:flash` builds, waits for the `RPI-RP2` drive, and copies the firmware onto it.

QMK Toolbox doesn't support the RP2040 bootloader, so use one of the above instead.
