piler(){
ans=1
for((i=0;i<3;i++))
do 
ans=$((ans*arr[i]))
done
echo "Ans: $ans"
} 


read -p "Enter Nums: " -a arr
piler 
