#!/bin/bash

# start=$(date +%s)


# end=$(date +%s)
# echo "Elapsed Time: $(($end-$start)) seconds"

TIMEFORMAT='FT containers took %R seconds.'
time {
    for ((i=0; i < 21; i++))
    do
        ./ft_containers map $i ft > /dev/null
    done
    for ((i=0; i < 5; i++))
    do
        ./ft_containers others $i ft > /dev/null
    done
    for ((i=0; i < 6; i++))
    do
        ./ft_containers others $i ft > /dev/null
    done
    for ((i=0; i < 6; i++))
    do
        ./ft_containers others $i ft > /dev/null
    done
}

TIMEFORMAT='STD containers took %R took seconds.'
time {
    for ((i=0; i < 21; i++))
    do
        ./ft_containers map $i std > /dev/null
    done
    for ((i=0; i < 5; i++))
    do
        ./ft_containers others $i std > /dev/null
    done
    for ((i=0; i < 6; i++))
    do
        ./ft_containers others $i std > /dev/null
    done
    for ((i=0; i < 6; i++))
    do
        ./ft_containers others $i std > /dev/null
    done
}