#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

mkdir .tmp/
rm -rf .tmp/result

for ((i=0; i < 7; i++))
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

if [[ $(uname) == 'Linux' ]]
then
    for ((i=0; i < 7; i++))
    do
        valgrind --leak-check=full --error-exitcode=1 ./ft_containers stack $i ft > /dev/null
        if [ $? -eq 0 ]
        then
            echo -e "${GREEN} NO LEAK ON TEST $i OK" >> .tmp/result
        else
            echo -e "${RED} LEAKS ON TEST $i KO" >> .tmp/result
        fi
    done
fi

cat .tmp/result
cat .tmp/result | grep KO >> /dev/null
if [ $? -eq 0 ]
then
    exit 1
fi