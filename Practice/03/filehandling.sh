#!/bin/bash

read -p "Enter read and write file names: " rfile wfile

if [ ! -e "$rfile" ]; then
    echo "Error: Read file does not exist."
    exit 1
fi

echo "Reading from the file..."
filecontent=$(<"$rfile")
echo "$filecontent"

echo "Writing to the file..."
echo "This is a new line" >> "$wfile"
echo "Write operation completed."


#while read line; do
#    echo "$line" >> "$rfile"
# done < "$wfile"
