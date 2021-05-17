#! /bin/bash

make re

#gcc ft_tester.c && ./a.out $1 > test.txt 

#ARG=$( cat test.txt)

ARG=$( jot -r $1 -9999 999999 )

echo $ARG

./push_swap $ARG #| ./checker $ARG

rm -rf a.out 