#!/bin/bash

for t in $(seq 1 15);
do
    echo "test = $t"
    ./validator < "test/Test$t/test.inp"
done
