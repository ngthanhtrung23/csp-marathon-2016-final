#!/bin/bash

for t in $(seq 1 11);
do
    echo "test = $t"
    ./validator < "test/TEST$t/birds.inp"
done
