```
read -p "Enter filename: " filename

if [[ ! -f $filename ]]; then
    echo "File does not exist!"
else
    count=$(wc -l < "$filename")
    echo "Number of lines: $count"
fi

```

## Output
![image](https://github.com/user-attachments/assets/de5735c3-2fd4-41c8-92bd-1bf9216c5ade)
