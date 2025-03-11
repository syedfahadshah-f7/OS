read -p "Enter 10 numbers: " -a arr
size=${#arr[@]}

# Bubble Sort
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

neg=0
pos=0
zero=0

# Counting negatives, positives, and zeros
for ((i=0; i<size; i++))
do
    if [ ${arr[i]} -lt 0 ]  
    then
        ((neg++))
    elif [ ${arr[i]} -eq 0 ]  
    then
        ((zero++))
    else
        ((pos++))
    fi
done

# Printing sorted array
echo "Sorted Array: "
for ((i=0; i<size; i++))
do
    echo -n "${arr[i]} "  
done
echo  

# Display count of negative, positive, and zero values
echo "Negative count: $neg"
echo "Zero count: $zero"
echo "Positive count: $pos"

