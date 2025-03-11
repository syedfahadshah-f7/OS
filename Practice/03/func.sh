CalAverage(){
	sum=0
	for((i=0;i<size;i++))
	do 
	sum=$((sum+ arr[i]))
	done
	avg=0
	avg=$((sum/size))
	
}
read -p "Enter Values for Average: " -a arr
size=${#arr[@]}

CalAverage 

echo "Average: $avg "
