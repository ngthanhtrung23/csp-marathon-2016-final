#!/bin/bash

for t in $(seq -f "%02g" 1 24);
do
    echo "test = $t"
    ./validator < "Test/test$t/internet.inp"
done
