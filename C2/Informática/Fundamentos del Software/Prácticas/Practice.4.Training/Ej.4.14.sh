#!/bin/bash

#Titulo: Ejercicio 4.14 Práctica 4
#Fecha: 11/04/2021
#Autor: Quintín Mesa Romero
#Uso: Indicado en el enunciado

if (($(((365 - $(date +%j)/7)%5 == 0)))); then printf "Es múltiplo de 5"; else echo no; fi
