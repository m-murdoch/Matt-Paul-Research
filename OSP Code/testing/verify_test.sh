#!/bin/bash
# This is a comment!
echo Calling OSP.verify-rand many times
for n in {80..100..10}
do
    echo $n
    for m in {24..32..4}
    do
	echo $m
	for j in {1..2}
	do
	    ../OSP.verify-rand $n $m
	done
    done
done
echo OK, I am done	# This is a comment, too!
