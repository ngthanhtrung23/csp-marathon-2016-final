#!/bin/bash

for t in $(seq -f "%02g" 1 42);
do
    echo "test = $t"
    ./validator < "test/$t/unblock.inp"
done
