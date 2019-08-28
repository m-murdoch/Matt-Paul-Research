#!/bin/bash
echo Testing *START*
for n in {1000..5000..500}
do
    echo $n
	for j in {1..7}
	do
	    ../OSP.timing-rand $n
	done
done
echo Testing *FINISHED*