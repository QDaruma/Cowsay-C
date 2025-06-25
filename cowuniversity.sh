#!/bin/bash
clear
afficher_cow(){
   cowsay $1
   sleep 1
   clear
}

is_premier() { #fonction qui affiche les nombres premiers jusqu'à l'argument donne en parametre de la fonction
  for ((i=2; i<=$1; i++)) # pour chaque nombre on compte le nombre de diviseurs
  do
    compteur_div=0
    for ((j=1; j<=$i; j++))
    do
      if [ $(($i%$j)) -eq 0 ]
      then
        ((compteur_div++))
      fi
    done
    if [ $compteur_div -eq 2 ] # si le nombre a 2 diviseurs (1 et et lui meme)
    then
      afficher_cow $i
    fi
  done
}

is_premier $1
