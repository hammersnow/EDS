#!/bin/bash
#ekremiscan

clear
ips=(10.1.10.37 10.1.10.40 10.1.10.35 10.1.10.36 10.1.10.38 10.1.10.39 10.1.10.25 10.1.10.17 10.1.10.23 10.1.10.22 10.1.10.33 10.1.10.32 10.1.10.20 10.1.10.28 10.1.10.21 10.1.10.26 10.1.10.27 10.1.10.24 10.1.10.44 10.1.10.46 10.1.10.43 10.1.10.45 10.1.10.41 10.1.10.42 )


for ip in "${ips[@]}"; do
        ssh -T $ip << \code 



edsid=$(cat /opt/eds/etc/scanner_persist.cfg | grep SCANNER | awk '{print $2}')
echo -e "$edsid"

disk=$(df -h | grep /image | awk '{print $5}' | cut -d '%' -f1)

echo "Disk alani kullanim orani % $disk"
if [[ $disk -gt '80' ]]; then echo -n "DISK ALANI %80'DEN FAZLA DOLU SILME ISLEMI ONERILIR"
echo "" 
fi
echo ""
code
done





