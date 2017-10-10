#!/bin/bash
. defs.sh

#start_time=`date +%s`
#./bin/exe berlin52.tsp batata.log 50 1 1 20 5
#end_time=`date +%s`
#echo `expr $end_time - $start_time` >> file.txt

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
                            RUN_DIR="${LOG_PATH}/test-${pops}-${ini}-${cross}-${elitism}-${mut}"
                            mkdir -p ${RUN_DIR}

                            ./../bin/exe "${libDir}${tsp}.tsp" "${RUN_DIR}/run_$i.stats" ${pops} ${ini} ${cross} ${elitism} ${mut} "${RUN_DIR}/run_$i.sol"
                        done
                    done
                done
            done
        done
    done
done