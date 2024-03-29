#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

mkdir .tmp/
rm -rf .tmp/result

for ((i=0; i < 25; i++))
do
    if [ $i -ne 22 ] && [ $i -ne 18 ]
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


if [[ $(uname) == 'Linux' ]]
then
    if [ $i -ne 22 ] && [ $i -ne 18 ]
    then
        for ((i=0; i < 25; i++))
        do
            valgrind --leak-check=full --error-exitcode=1 ./ft_containers map $i ft > /dev/null
            if [ $? -eq 0 ]
            then
                echo -e "${GREEN} NO LEAK ON TEST $i OK" >> .tmp/result
            else
                echo -e "${RED} LEAKS ON TEST $i KO" >> .tmp/result
            fi
        done
    fi
fi

cat .tmp/result
cat .tmp/result | grep KO >> /dev/null
if [ $? -eq 0 ]
then
    exit 1
fi
