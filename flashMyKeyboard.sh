#! /bin/bash

KEYBOARD=splitkb/kyria/rev1
KEYMAP=struckmb_wip
SIDE=left

while getopts 'k:m:s:' opt; do
    case "$opt" in
    k)
        KEYBOARD=${OPTARG}
        ;;
    m)
        KEYMAP=${OPTARG}
        ;;
    s)
        SIDE=${OPTARG}
        ;;
    esac
done

echo "keyboard: ${KEYBOARD}, keymap: ${KEYMAP}, side: ${SIDE}"

if [ "$KEYBOARD" = "cantor" ]; then
    qmk flash -kb $KEYBOARD -km ${KEYMAP} -bl "dfu-util-split-${SIDE}"
else
    qmk flash -kb $KEYBOARD -km ${KEYMAP}
fi
