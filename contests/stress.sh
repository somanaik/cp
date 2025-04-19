#!/bin/sh
> stress-input.txt
> stree-ouput.txt

iter=50
for (( i=1; i<$iter; ++i))
do
    ./test-cases.sh
    echo "iter: " $i "..............................." >>  stress-input.txt
    cat input.txt >> stress-input.txt
    echo "iter: " $i "..............................." >>  stress-output.txt
    cat output.txt >> stress-output.txt
done
