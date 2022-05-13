#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

mkdir .tmp/
rm -rf .tmp/result

for ((i=0; i < 1; i++))
do
    ./ft_containers $i > .tmp/res.vector
    ./ft_containers $i std > .tmp/res.vector.std

    diff .tmp/res.vector .tmp/res.vector.std > /dev/null
    if [ $? -eq 0 ]
    then
        echo -e "${GREEN} CAPACITY OK" >> .tmp/result
    else
        echo -e "${RED} CAPACITY KO" >> .tmp/result
    fi
done

cat .tmp/result
cat .tmp/result | grep KO >> /dev/null
if [ $? -eq 0 ]
then
    exit 1
fi