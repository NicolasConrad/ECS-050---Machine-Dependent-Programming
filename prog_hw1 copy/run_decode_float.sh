#!/bin/bash

case_num=$1
executable=decode_float

DIR=autograder_float_formats

case "$case_num" in
	1)	input="101010\n10101010\n1111000"; file=$DIR/test_format1.txt ;;
	2)	input="1111111"; file=$DIR/test_format1.txt ;;
	4)	input="0111110"; file=$DIR/test_format3.txt ;;
	6)  input="11111111011111111111111111111110"; file=$DIR/format_single_precision.txt ;;
	9)	input="00000000010000000"; file=$DIR/test_format5.txt ;;
esac

echo -e "$input" | ./$executable "$file"
