#!/bin/bash
# Titulo: Entrega práctica 3
# Fecha:  22/03/2021
# Autor:  Quintín Mesa Romero
# Versión: 1.0
# Descripción: muestra los archivos de un directorio que pertenezcan a un determinado usuario.

printf "Los archivos del directorio $1 que pertenecen al usuario $2 son: \n"
find $1 -user $2
