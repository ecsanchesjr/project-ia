#!/bin/bash

# PATHS
logDir="../logs/"
libDir="../libs/"
LIB_PATH=""
LOG_PATH=""
RUN_DIR=""

# VARS

TSPs=( "berlin52" "lin105" "ch150" "a280" )
POPs=( 10 30 50 100 )
INI_POP=( 0 1 )
CROSS=( 0 1 )
ELITISM=( 10 20 30 40 )
MUT=( 2 5 10 ) 