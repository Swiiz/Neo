## Binding vnc to localhost:1
echo "Starting qemu with \"dist/x86_64/kernel.iso\" as cdrom and binding the display to gtk"
sudo qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso -D ./logs/qemu-latest.txt -display gtk