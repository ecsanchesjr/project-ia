#!/bin/bash
. defs.sh

TSPs=( "berlin52" "lin105" )

declare -a files


for tsp in ${TSPs[@]}
do
    for pops in ${POPs[@]}
    do
        for ini in ${INI_POP[@]}
        do
            for cross in ${CROSS[@]}
            do
                for elitism in ${ELITISM[@]}
                do
                    for mut in ${MUT[@]}
                    do
                        files+=("$elitism-$mut" )
                    done
                done
                Rscript graphicsGeneration.r "../logs/$tsp/test-${pops}-${ini}-${cross}-${files[0]}/run_1.stats.csv" "../logs/$tsp/test-${pops}-${ini}-${cross}-${files[1]}/run_1.stats.csv" "../logs/$tsp/test-${pops}-${ini}-${cross}-${files[2]}/run_1.stats.csv" "../logs/$tsp/test-${pops}-${ini}-${cross}-${files[3]}/run_1.stats.csv" "../logs/$tsp/test-${pops}-${ini}-${cross}-${files[4]}/run_1.stats.csv" "../logs/$tsp/test-${pops}-${ini}-${cross}-${files[5]}/run_1.stats.csv" "../logs/$tsp/test-${pops}-${ini}-${cross}-${files[6]}/run_1.stats.csv" "../logs/$tsp/test-${pops}-${ini}-${cross}-${files[7]}/run_1.stats.csv" "../logs/$tsp/test-${pops}-${ini}-${cross}-${files[8]}/run_1.stats.csv" "../logs/$tsp/test-${pops}-${ini}-${cross}-${files[9]}/run_1.stats.csv" "../logs/$tsp/test-${pops}-${ini}-${cross}-${files[10]}/run_1.stats.csv" "../logs/$tsp/test-${pops}-${ini}-${cross}-${files[11]}/run_1.stats.csv" "${files[0]}" "${files[1]}" "${files[2]}" "${files[3]}" "${files[4]}" "${files[5]}" "${files[6]}" "${files[7]}" "${files[8]}" "${files[9]}" "${files[10]}" "${files[11]}" "graph-${tsp}-${pops}-${ini}-${cross}" "DataSet: ${tsp}    PopSize: ${pops}    InitMethod: ${ini}    CrossMethod: ${cross}" "${tsp}"
            done
        done
    done
done