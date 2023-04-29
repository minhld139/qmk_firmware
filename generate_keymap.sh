#!/bin/bash

# sh ./generate_keymap.sh siegfried %input_file%

keymap=$1
input_json=$2

docker run --rm -it -w /qmk_firmware \
-v "$(pwd)":/qmk_firmware qmkfm/qmk_cli \
qmk json2c -o keyboards/gmmk/pro/rev1/ansi/keymaps/$keymap/new_keymap.c $input_json
