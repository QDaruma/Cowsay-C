#!/bin/bash
clear
i=1
while [ $i -lt 10 ] # tant que i est inferieur a 10
do	
	cowsay $i 
	sleep 1
	((i++)) # on incrémente i
	clear
done 
cowsay -T \UU $i # on affiche i avec la vache qui tire la langue
