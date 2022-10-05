# Configuration for the test

R=$RANDOM

FUNC="getline_test"
OUTPUTFILE="$FUNC"
ERRORFILE="test_errors_$FUNC"

./monty $R
