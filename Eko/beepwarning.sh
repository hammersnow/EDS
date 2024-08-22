#!/bin/bash

files=("/root/Eko/ed01/ed01.txt" "/root/Eko/ed02/ed02.txt" "/root/Eko/ed03/ed03.txt" "/root/Eko/ed04/ed04.txt" "/root/Eko/ed05/ed05.txt" "/root/Eko/ed06/ed06.txt" "/root/Eko/ed09/ed09.txt" "/root/Eko/ed10/ed10.txt" "/root/Eko/ed11/ed11.txt" "/root/Eko/ed12/ed12.txt" "/root/Eko/ed13/ed13.txt" "/root/Eko/ed14/ed14.txt" "/root/Eko/ed15/ed15.txt" "/root/Eko/ed16/ed16.txt" "/root/Eko/ed17/ed17.txt" "/root/Eko/ed18/ed18.txt" "/root/Eko/ed19/ed19.txt" "/root/Eko/ed20/ed20.txt" "/root/Eko/ed23/ed23.txt" "/root/Eko/ed24/ed24.txt" "/root/Eko/ed25/ed25.txt" "/root/Eko/ed26/ed26.txt" "/root/Eko/ed27/ed27.txt" "/root/Eko/ed28/ed28.txt")

beep_interval=60

last_beep=0

beep_if_needed() {
current_time=$(date +%s)
if (( current_time - last_beep >= beep_interval )); then
	beep -f 1000 -l 200
	last_beep=$current_time
fi
}

watch_file() {
local file=$1
while true; do
if grep -q "!!!!!!!!!" "$file"; then
beep_if_needed
fi
sleep 0.50
done
}

for file in "${files[@]}"; do
watch_file "$file" &
done
wait
