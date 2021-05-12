#! /bin/bash

make re

#gcc ft_tester.c && ./a.out $1 > test.txt 

#ARG=$( cat test.txt)

ARG=$( jot -r $1 -99 9999 )

./push_swap $ARG #| ./checker $ARG

rm -rf a.out 