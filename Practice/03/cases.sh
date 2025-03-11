read -p "Enter two Numbers and a operator" num1 num2 ope
case $ope in "plus")
	echo  "Ans: " $((num1+num2));;
"minus")
	echo "Ans: " $((num1-num2));;
"mul")
	echo "Ans: " $((num1*num2));;
"mod")
	echo "Ans: " $((num1%num2));;
*)
	echo "Invalid Operator";;
esac
