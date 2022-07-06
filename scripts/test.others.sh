#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

mkdir .tmp/
rm -rf .tmp/result

for ((i=0; i < 2; i++))
do
    ./ft_containers others $i ft > .tmp/res.others
    ./ft_containers others $i std > .tmp/res.others.std

    diff .tmp/res.others .tmp/res.others.std > /dev/null
    if [ $? -eq 0 ]
    then
        echo -e "${GREEN} TEST $i OK" >> .tmp/result
    else
        echo -e "${RED} TEST $i KO" >> .tmp/result
        diff .tmp/res.others .tmp/res.others.std
        echo "TEST FT"
        ./ft_containers others $i ft
        echo "TEST STD"
        ./ft_containers others $i std
    fi
done

cat .tmp/result
cat .tmp/result | grep KO >> /dev/null
if [ $? -eq 0 ]
then
    exit 1
fi