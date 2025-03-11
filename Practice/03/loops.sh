#!/bin/bash

read -p "Enter Values of Array: " -a arr
size=${#arr[@]}

echo -e "Without Sort Array:"
for ((i = 0; i < size; i++))
do
    echo -n "${arr[i]} "
done
echo ""

# Bubble Sort (Sorting based on string length)
for ((i = 0; i < size - 1; i++))
do
    for ((j = 0; j < size - i - 1; j++))
    do
        if [ ${arr[j]} -gt ${arr[j+1]} ]
        then
            temp=${arr[j]}
            arr[j]=${arr[j+1]}
            arr[j+1]=$temp
        fi
    done
done

echo -e "After Sort Array:"
for ((i = 0; i < size; i++))
do
    echo -n "${arr[i]} "
done
echo ""

