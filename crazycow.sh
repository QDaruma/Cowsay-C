#!/bin/bash
clear
nb_mystere=$(( (RANDOM%100) + 1)) # genere un nombre entre 1 et 100
nb_essais=0
essai=-1

while [ $essai -ne $nb_mystere ] # tant que le nombre mystere n'est pas trouvé
do
	while [ $essai -lt 1 -o $essai -gt 100 ] # l'utilisateur entre un nombre
	do
		cowsay "Devinez le nombre mystere compris entre 1 et 100"
		read essai 
	done
	
	((nb_essais++))
	# gere les differents cas possibles (trop grand, trop petit, victoire)
	if [ $essai -eq $nb_mystere ]; then
		cowsay "Bravo! Tu as trouvé le nombre $nb_mystere en $nb_essais essais."
		exit 0
	else
		if [ $essai -lt $nb_mystere ]; then
			cowsay "Plus grand"
		else
			cowsay "Plus petit"  
		fi
	fi 
	essai=-1
	echo -------------------------------------------------------------------
done
