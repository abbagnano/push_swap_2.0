#! /bin/bash

make re

#gcc ft_tester.c && ./a.out $1 > test.txt 

#ARG=$( cat test.txt)

ARG=$( jot -r $1 -999 9999 )

echo $ARG

./push_swap $ARG #| ./checker $ARG

rm -rf a.out 