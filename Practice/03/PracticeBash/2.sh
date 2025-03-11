read -p "Enter Number: " num
for((i=num/2;i>1;i--))
do
if [ $((num%i)) == 0 ]
then
	echo "Number $num is not Prime"
	exit 0
fi
done

echo "Number $num is Prime"
