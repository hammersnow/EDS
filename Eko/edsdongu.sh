#!/bin/bash
#ekremiscan


while true
do
date '+%d/%m/%Y   %R' > /root/Eko/clock.txt
bash /root/Eko/ed01.sh > /root/Eko/ed01/ed01-.txt
cat /root/Eko/ed01/ed01-.txt > /root/Eko/ed01/ed01.txt
bash /root/Eko/ed02.sh > /root/Eko/ed02/ed02-.txt
cat /root/Eko/ed02/ed02-.txt > /root/Eko/ed02/ed02.txt
bash /root/Eko/ed03.sh > /root/Eko/ed03/ed03-.txt
cat /root/Eko/ed03/ed03-.txt > /root/Eko/ed03/ed03.txt
bash /root/Eko/ed04.sh > /root/Eko/ed04/ed04-.txt
cat /root/Eko/ed04/ed04-.txt > /root/Eko/ed04/ed04.txt
bash /root/Eko/ed05.sh > /root/Eko/ed05/ed05-.txt
cat /root/Eko/ed05/ed05-.txt > /root/Eko/ed05/ed05.txt
bash /root/Eko/ed06.sh > /root/Eko/ed06/ed06-.txt
cat /root/Eko/ed06/ed06-.txt > /root/Eko/ed06/ed06.txt
done

