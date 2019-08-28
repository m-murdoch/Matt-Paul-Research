#!/bin/bash
# This is a comment!
echo Calling OSP.verify-rand many times
for n in {20..50..10}
do
    for m in {4..24..4}
    do
	echo
	echo "                    " n = $n and m = $m
	for j in {1..4}
	do
	    ../OSP.verify-rand $n $m
	done
    done
done
echo OK, I am done	# This is a comment, too!
