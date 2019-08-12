#!/bin/bash

echo $'Timing Script -=START=-\n'
echo $'\n---------------- '$(date)' ----------------' >> map_timings.log

## Prints all sub directories of ./working and stores their name in $map
for map in $(ls ./working)
do
    echo $map': ' | tee -a map_timings.log
    ## Cleans old files, copies over new OSP.c, and makes
    (cd ./OSP && make new-map) > /dev/null
    cp ./working/$map/OSP.c ./OSP/OSP.c
    (cd ./OSP && make timing-rand) > /dev/null
    ## Runs timing script
    (cd ./OSP/testing && timing.sh) | tee map_timings.log
    ## Moves csv file to the maps sub-dirctory
	  mv ./OSP/testing/timing.csv ./working/$map
done


echo $'\nTiming Script -=FINISH=-'
