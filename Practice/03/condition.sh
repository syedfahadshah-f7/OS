read -p "Enter two Numbers and a operator" num1 num2 ope
if [ $ope = "plus" ]
then 
	echo  "Ans: " $((num1+num2))
elif [ $ope = "minus" ]
then
	echo "Ans: " $((num1-num2))
elif [ $ope = "multiply" ]
then
	echo "Ans: " $((num1*num2))
elif [ $ope = "mod" ]
then
	echo "Ans: " $((num1%num2))
else 
	echo "Invalid Operator"
fi
