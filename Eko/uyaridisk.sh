#!/bin/bash

/usr/local/bin/./disk.sh > /home/eds_cm/eko/diskalaniuyari.txt
cikti=$(cat /home/eds_cm/eko/diskalaniuyari.txt | grep -B 2 "%80")

if grep -q -B 2 "%80" /home/eds_cm/eko/diskalaniuyari.txt; then
beep -f 3000 -l 200
sleep 0.5
beep -f 3000 -l 200
notify-send -t 900000 -u normal "$cikti"
fi
