#!/bin/bash
. scripts/defs.sh

start_time=`date +%s`
#./bin/exe berlin52.tsp batata.log 50 1 1 20 5
end_time=`date +%s`
echo `expr $end_time - $start_time` >> file.txt