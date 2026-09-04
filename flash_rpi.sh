#!/bin/bash
set -euo pipefail

target=keebio/iris/rev8:vital7788

function flash() {
    echo "Waiting for raspberry pi bootloader"
    while ! lsblk -f | grep -q "RPI-RP2"; do
        sleep 1
    done

    device=$(lsblk -o NAME --filter 'LABEL =~ "RPI-RP2"' | tail -n 1)
    echo "Mounting RPI"
    mountpoint=$(udisksctl mount -b /dev/"$device" --no-user-interaction | sed 's/Mounted [^ ]* at //')
    echo "Copying firmware"
    cp "$firmware" "$mountpoint"
}

if [ $# -gt 0 ]; then
    firmware=$1
    if [ ! -f "$firmware" ]; then
        echo "No such file: $firmware" >&2
        exit 1
    fi
else
    qmk_home=$(qmk env QMK_HOME)
    firmware=$(qmk userspace-path)/keebio_iris_rev8_vital7788.uf2
    ( cd "$qmk_home" && SKIP_FLASHING_SUPPORT=1 ./util/docker_build.sh "$target" )
    echo ""
fi

flash
sleep 1
flash

echo "Done!"
