#!/bin/bash

# start=$(date +%s)


# end=$(date +%s)
# echo "Elapsed Time: $(($end-$start)) seconds"

containers=(map vector stack others)

for container in "${containers[@]}";
do
    echo "calculating speed for container $container"
    TIMEFORMAT='FT containers took %R seconds.'
    time {
        if [ "$container" != map ]
        then
            for ((i=0; i < 25; i++))
            do
                if [ $i -ne 22 ] && [ $i -ne 18 ]
                then
                    ./ft_containers "$container" "$i" ft > /dev/null
                fi
            done
        fi

        if [ "$container" != vector ]
        then
            for ((i=0; i < 3; i++))
            do
                ./ft_containers "$container" "$i" ft > /dev/null
            done
        fi

        if [ "$container" != stack ]
        then
            for ((i=0; i < 7; i++))
            do
                ./ft_containers "$container" "$i" ft > /dev/null
            done
        fi

        if [ "$container" != others ]
        then
            for ((i=0; i < 7; i++))
            do
                ./ft_containers "$container" "$i" ft > /dev/null
            done
        fi
    }

    TIMEFORMAT='STD containers took %R took seconds.'
    time {
        if [ "$container" != map ]
        then
            for ((i=0; i < 25; i++))
            do
                if [ $i -ne 22 ] && [ $i -ne 18 ]
                then
                    ./ft_containers "$container" "$i" std > /dev/null
                fi
            done
        fi

        if [ "$container" != vector ]
        then
            for ((i=0; i < 3; i++))
            do
                ./ft_containers "$container" "$i" std > /dev/null
            done
        fi

        if [ "$container" != stack ]
        then
            for ((i=0; i < 7; i++))
            do
                ./ft_containers "$container" "$i" std > /dev/null
            done
        fi

        if [ "$container" != others ]
        then
            for ((i=0; i < 7; i++))
            do
                ./ft_containers "$container" "$i" std > /dev/null
            done
        fi
    }

    printf "\n"
done