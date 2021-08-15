## Binding vnc to localhost:1
echo "Starting qemu with \"dist/i386/kernel.iso\" as cdrom and binding the display to gtk"
DIR=$(dirname $0)
sudo qemu-system-x86_64 -cdrom "${DIR}/../dist/i686/kernel.iso" -display gtk