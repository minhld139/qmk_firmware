#!/bin/bash

# sh ./build_firmware.sh siegfried

keymap="${1:-siegfried}"

util/docker_build.sh gmmk/pro/rev1/ansi:$keymap

cp -f gmmk_pro_rev1_ansi_$keymap.bin /mnt/user/share/
