#!/usr/bin/env sh

# Configuration for the test

arr=(README.md structs.h)

FUNC="getline_test"
OUTPUTFILE="$FUNC"
ERRORFILE="test_errors_$FUNC"

for file in $arr[@] ; do
	./monty $file
done
