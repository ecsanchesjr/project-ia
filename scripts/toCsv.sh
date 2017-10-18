#! /bin/bash

for entry in "../logs/*"
do
    for entry2 in "${entry}/*"
    do
        files=$(find ${entry2} -mindepth 1 -maxdepth 1 -type f -print0 | xargs -0 -I {} echo "{}")
        
        for i in ${files[@]}
        do
            sed 's/ \+/,/g' $i > $i.csv
        done
    done
done
