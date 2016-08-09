#!/bin/bash

for t in $(seq -f "%02g" 1 42);
do
    echo "test = $t"
    mv "test/$t/$t.inp" "test/$t/unblock.inp"
done
