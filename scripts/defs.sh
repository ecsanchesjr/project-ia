#!/bin/bash
TSPs=( "berlin52.tsp" "lin105.tsp" "ch150.tsp" "a280.tsp" )

CROSS=( 0 1 )

INI_POP=( 0 1 )

MUT=( 2 5 10 ) 

ELITISM=( 10 20 30 40 )

POPs=( 10 30 50 100 )

for tsp in ${CROSS[@]}
do
    for eli in ${ELITISM[@]}
    do
        echo $tsp $eli
    done
done
