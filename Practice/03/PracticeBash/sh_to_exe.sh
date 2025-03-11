#for file in *.exe
#do
  #mv "$file" "${file%.exe}.sh"
#done

if [ "$(date +%A)" = "Monday" ]; then
  echo "OH NO!! Today is GR2"
else
  echo "Today is not Monday."
fi

