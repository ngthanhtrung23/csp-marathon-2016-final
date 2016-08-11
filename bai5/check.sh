#!/bin/bash

for t in $(seq -f "%02g" 1 42);
do
    echo "test = $t"
    echo "test/$t" > "config.txt"
    echo "./" >> "config.txt"
    ./rr_bfs < "test/$t/unblock.inp" > unblock.out
    ./checker < config.txt
done
rm unblock.out
