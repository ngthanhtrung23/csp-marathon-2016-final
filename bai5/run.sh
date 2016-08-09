#!/bin/bash

for t in $(seq -f "%02g" 1 42);
do
    ./rr_bfs < "test/$t/unblock.inp" > "test/$t/unblock.out"
done

