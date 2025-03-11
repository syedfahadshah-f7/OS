#!/bin/bash

factorial() {
   for((i=1;i<=$1;i++))
   do
   ans=$((ans*i))
   done
}

read -p "Enter a number: " num
if [ "$num" -lt 0 ]; then
    echo "Factorial is not defined for negative numbers."
    exit 1
fi

ans=1
factorial "$num"
echo "ANS: $ans"

