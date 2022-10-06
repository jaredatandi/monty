#!/usr/bin/env sh

# Configuration for the test

declare -a arr=( "README.md" "structs.h" "errors.h" ) 

FUNC="getline_test"
OUTPUTFILE="$FUNC"
ERRORFILE="test_errors_$FUNC"

for file in ${arr[@]} ; do
	echo "$FUNC"
	./monty $file
	echo "tested monty with $file"

	if [[ $? -gt 0 ]]; then

		echo "there was an error"	
	fi
done

