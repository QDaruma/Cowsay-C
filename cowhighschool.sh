#!/bin/bash
clear
i=1
while [ $(($i * $i)) -lt $(($1 * $1)) ] # tant que i*i < $1*$1
do	
	cowsay $(($i * $i)) # affiche la valeur du carré de i
	sleep 1
	((i++)) # on incremente i
	clear
done 	
cowsay -T \UU $(($i * $i))
