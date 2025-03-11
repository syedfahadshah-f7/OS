#!/bin/bash
a=10
b=10
for ((i=0; i<b; i++))
do
    echo -e "$((a + a * i))"
done

