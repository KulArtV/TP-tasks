#!/bin/bash
IFS=$'\n'
newcatalog="$1"
archivecatalog="$2"
mkdir -p "$newcatalog"
while [ -n "$3" ]
do
	find ~ -name "*.$3" | while read file
	do
		i=1
		filename=$(basename "$file" ".$3")
		nameWithExtension=$filename.$3
		while [ -e "$newcatalog/$nameWithExtension" ] 
		do
			nameWithExtension=$filename$i.$3
			i=$(($i+1))
		done 
		cp -f "$file" "$newcatalog/$nameWithExtension"
	done
	shift
done
tar -cf "$archivecatalog".tar ./"$newcatalog"/
echo "done" 
exit 0 