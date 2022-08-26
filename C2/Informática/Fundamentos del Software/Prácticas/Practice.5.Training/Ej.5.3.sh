#!/bin/bash


echo "Pulse una tecla"
read TECLA;
fila=-1
case $TECLA in
[01-9]) fila=1;;
[qwertyuiopQWERTYUIOP]) fila=2;;
[asdfghjklñASDFGHJKLÑ]) fila=3;;
[zxcvbnmZXCVBNM]) fila=4;;
*) printf "La tecla '$TECLA' no ha sido considerada\n";;

esac

if [ $fila != "-1" ]; then printf "La tecla '$TECLA' está en la fila '$fila'";
fi
