#! /bin/bash

make

#	genera numeri random in base all'argomento
MIN=$(( -999 * $1))
MAX=$(( 999 * $1))
ARG=$( jot -r $1 $MIN $MAX )

#	scrive la lista di numeri sullo stdout
echo $ARG
echo 

#	scrive le operazioni sullo stdout
./push_swap $ARG  #| ./checker $ARG
echo

#	scrive il numero di mosse utilizzato per il sort
echo "mosse: " 
./push_swap $ARG | wc -l
echo

#	scrive il risultato del checker_Mac
echo "risultato checker_Mac: " 
./push_swap $ARG | ./checker_Mac $ARG

#	scrive il risultato del mio checker
if [ "$2" == "bonus" ];
then
	make bonus
	echo "risultato checker_bonus: " 
	./push_swap $ARG | ./checker $ARG
fi
#rm -rf a.out

#make clean