#!/bin/bash

function flash() {
    echo "Waiting for raspberry pi bootloader"
    while ! lsblk -f | grep -q "RPI-RP2"; do
        sleep 1
    done

    device=$(lsblk -o NAME --filter 'LABEL =~ "RPI-RP2"' | tail -n 1)
    echo "Mounting RPI"
    mountpoint=$(udisksctl mount -b /dev/"$device" --no-user-interaction | sed 's/Mounted [^ ]* at //')
    echo "Copying firmware"
    cp ./keebio_iris_rev8_Vital7788.uf2 "$mountpoint"
}

SKIP_FLASHING_SUPPORT=1 ./util/docker_build.sh keebio/iris/rev8:Vital7788
echo ""
flash
sleep 1
flash

echo "Done!"
