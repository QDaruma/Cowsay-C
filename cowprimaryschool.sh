#!/bin/bash
clear
i=1
while [ $i -lt $1 ] # tant que i est inferieur au 1er argument
do	
	cowsay $i 
	sleep 1
	((i++)) # on incrémente
	clear
done 	
cowsay -T \UU $i # on affiche i avec la vache qui tire la langue
