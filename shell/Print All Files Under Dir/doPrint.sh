#!/bin/bash
# $1 : the first paramater passed in
# set -x
doJob() {
    for dd in `ls $1`; do
        if [[ -d $dd ]]; then
            cd $dd
            doJob ./;
            cd - &> /dev/null
        else
            echo $dd
        fi
    done
}

if [[ "$#" != 0 ]]; then
    exit 0
fi
doJob './'
