#!/bin/bash
# This is a comment!
echo Calling OSP.verify-rand many times
for n in {60..90..10}
do
    for m in {12..32..4}
    do
	echo "              " n=$n, m=$m
	for j in {1..2}
	do
	    ../OSP.verify-rand $n $m
	done
    done
done
echo OK, I am done	# This is a comment, too!
