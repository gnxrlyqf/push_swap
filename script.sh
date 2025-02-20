#!/bin/bash
for i in {1..5000};
do
	echo -n "$i, "
	var=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
	./push_swap $var | wc -l | tr -d '\n'
	echo " - $var"
done