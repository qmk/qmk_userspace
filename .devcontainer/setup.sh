#!/usr/bin/env bash

set -eEuo pipefail

wget https://bootstrap.pypa.io/get-pip.py
python3 get-pip.py
python3 -m pip install qmk
rm get-pip.py

git config --global --add safe.directory /workspaces/qmk_userspace
git submodule update --init --recursive

[ -d /workspaces/qmk_firmware ] || git clone https://github.com/qmk/qmk_firmware.git /workspaces/qmk_firmware
git config --global --add safe.directory /workspaces/qmk_firmware

qmk config user.qmk_home=/workspaces/qmk_firmware
qmk config user.overlay_dir=/workspaces/qmk_userspace

qmk git-submodule

cat << __EOF__ > /workspaces/qmk_userspace/devcontainer.code-workspace
{
    "folders": [
        {
            "name": "qmk_userspace",
            "path": "/workspaces/qmk_userspace"
        },
        {
            "name": "qmk_firmware",
            "path": "/workspaces/qmk_firmware"
        },
    ],
}
__EOF__
