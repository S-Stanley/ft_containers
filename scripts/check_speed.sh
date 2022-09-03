#!/bin/bash

# start=$(date +%s)


# end=$(date +%s)
# echo "Elapsed Time: $(($end-$start)) seconds"

TIMEFORMAT='FT containers took %R seconds.'
time {
    for ((i=0; i < 25; i++))
    do
        if [ $i -ne 22 ] && [ $i -ne 18 ]
        then
            ./ft_containers map $i ft > /dev/null
        fi
    done
    for ((i=0; i < 3; i++))
    do
        ./ft_containers others $i ft > /dev/null
    done
    for ((i=0; i < 7; i++))
    do
        ./ft_containers vector $i ft > /dev/null
    done
    for ((i=0; i < 7; i++))
    do
        ./ft_containers stack $i ft > /dev/null
    done
}

TIMEFORMAT='STD containers took %R took seconds.'
time {
    for ((i=0; i < 21; i++))
    do
        if [ $i -ne 22 ] && [ $i -ne 18 ]
        then
            ./ft_containers map $i std > /dev/null
        fi
    done
    for ((i=0; i < 3; i++))
    do
        ./ft_containers others $i std > /dev/null
    done
    for ((i=0; i < 7; i++))
    do
        ./ft_containers vector $i std > /dev/null
    done
    for ((i=0; i < 7; i++))
    do
        ./ft_containers stack $i std > /dev/null
    done
}