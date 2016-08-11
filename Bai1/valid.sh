#!/bin/bash

for t in $(seq -f "%02g" 1 15);
do
    echo "test = $t"
    ./validator < "Tasks/XNUM/Test$t/xnum.inp"
done

