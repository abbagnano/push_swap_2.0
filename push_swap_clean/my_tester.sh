#! /bin/bash

make re

gcc ft_tester.c && ./a.out $1 > test.txt 

ARG=$( cat test.txt)

./push_swap $ARG #| ./checker $ARG

rm -rf a.out 