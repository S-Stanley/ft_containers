#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

mkdir .tmp/
rm -rf .tmp/result

for ((i=0; i < 21; i++))
do
    if [ $i -ne 7 ] && [ $i -ne 13 ] && [ $i -ne 16 ] && [ $i -ne 19 ] && [ $i -ne 20 ]
    then
        ./ft_containers map $i ft > .tmp/res.map
        ./ft_containers map $i std > .tmp/res.map.std

        diff .tmp/res.map .tmp/res.map.std > /dev/null
        if [ $? -eq 0 ]
        then
            echo -e "${GREEN} TEST $i OK" >> .tmp/result
        else
            echo -e "${RED} TEST $i KO" >> .tmp/result
            diff .tmp/res.map .tmp/res.map.std
            echo "TEST FT"
            ./ft_containers map $i ft
            echo "TEST STD"
            ./ft_containers map $i std
        fi
    fi
done

for ((i=0; i < 21; i++))
do
    if [ $i -ne 2 ] && [ $i -ne 5 ] && [ $i -ne 6 ] && [ $i -ne 7 ] && [ $i -ne 10 ] && [ $i -ne 11 ] && [ $i -ne 15 ] && [ $i -ne 16 ]
    then
        valgrind --leak-check=full --error-exitcode=1 ./ft_containers map $i ft > /dev/null
        if [ $? -eq 0 ]
        then
            echo -e "${GREEN} NO LEAK ON TEST $i OK" >> .tmp/result
        else
            echo -e "${RED} LEAKS ON TEST $i KO" >> .tmp/result
        fi
    fi
done

cat .tmp/result
cat .tmp/result | grep KO >> /dev/null
if [ $? -eq 0 ]
then
    exit 1
fi