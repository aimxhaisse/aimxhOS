#!/bin/sh

echo "================================================================================"
echo "| Now waiting grub for booting, once ready, type the following:                |"
echo "================================================================================"

KSIZE=`cat src/kernel.bin | wc -c`
KLEN=`echo "$KSIZE.0/512.0" | bc`

echo ""
echo "grub> kernel 200+$KLEN" 
echo "grub> boot"
echo ""

