#!/bin/bash
. defs.sh

for tsp in ${TSPs[@]}
do
    LOG_PATH="${logDir}${tsp}"
    mkdir -p ${LOG_PATH}
    LIB_PATH="${libDir}${tsp}.tsp"

    for i in {1..10}  # Running 10 times each parameters
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
                            echo -e "$i Run of $tsp with params: \nPopulation Size: $pops \nPopInit Method: $INI_POP \nCrossover Method: $cross \nElitism Percentage: $elitism \nMutation Percentage: $mut"

                            RUN_DIR="${LOG_PATH}/test-${pops}-${ini}-${cross}-${elitism}-${mut}"
                            mkdir -p ${RUN_DIR}

                            start_time=`date +%s`

                            distance=$(./../bin/exe "${libDir}${tsp}.tsp" "${RUN_DIR}/run_$i.stats" ${pops} ${ini} ${cross} ${elitism} ${mut} "${RUN_DIR}/run_$i.sol")
                            
                            end_time=`date +%s`

                            ((time=$end_time-$start_time-1))
                            echo "Run $i,$distance,$time" >> "${RUN_DIR}/run.log"

                            echo -e "\n======================================================\n"
                        done
                    done
                done
            done
        done
    done
done