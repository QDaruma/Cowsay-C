#!/bin/bash
clear

afficher_cow(){ # fonction qui gere l'affichage
	cowsay $1
	sleep 1
	clear
}

fn=0
fn1=1
fn2=0

echo $fn2 | afficher_cow # affiche f0
afficher_cow $fn1 # affiche f1

i=2
while [ $i -lt $1 ]
do	
	fn=$((fn1 + fn2)) # calcule la nouvelle la valeur de fn
	fn2=$fn1 # fn-2 devient fn-1
	fn1=$fn # fn-1 devient fn
	((i++))	
	afficher_cow $fn
done 	
cowsay -T \UU $fn

