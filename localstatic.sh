#!/bin/bash

2>&1
echo 1 execution: &> result.txt
./localstatic >> result.txt
echo &>> result.txt
for i in {2..10}
do
	echo $i execution: &>> result.txt
	./localstatic >> result.txt
	echo &>> result.txt
done
