#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

mkdir .tmp/
rm -rf .tmp/result

for ((i=0; i < 6; i++))
do
    ./ft_containers stack $i ft > .tmp/res.stack
    ./ft_containers stack $i std > .tmp/res.stack.std

    diff .tmp/res.stack .tmp/res.stack.std > /dev/null
    if [ $? -eq 0 ]
    then
        echo -e "${GREEN} TEST $i OK" >> .tmp/result
    else
        echo -e "${RED} TEST $i KO" >> .tmp/result
        diff .tmp/res.stack .tmp/res.stack.std
        echo "TEST FT"
        ./ft_containers stack $i ft
        echo "TEST STD"
        ./ft_containers stack $i std
    fi
done

cat .tmp/result
cat .tmp/result | grep KO >> /dev/null
if [ $? -eq 0 ]
then
    exit 1
fi