#!/bin/bash

echo "Ethernet Port Status"
echo "===================="

for interface in $(ifconfig -s | awk '{print $1}')

do 

   if [ $interface != "lo" ]



   then 


      echo "Interface: $interface"


       ethtool $interface | grep "Speed\|Link detected\|Duplex"



    echo ""


      fi

done




