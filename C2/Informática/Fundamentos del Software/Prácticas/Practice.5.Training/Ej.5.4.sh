#!/bin/bash

if [ $# == 1 ]; then

m=(ene feb mar apr may jun jul ago sep oct nov dic)
M=(Ene Feb Mar Apr May Jun Jul Ago Sep Oct Nov Dic)
n=(1 2 3 4 5 6 7 8 9 10 11 12)

case $1 in

1 | ${m[0]} | ${M[0]}) echo "Mes: Enero";;
2 | ${m[1]} | ${M[2]}) echo "Mes: Febrero";;
3 | ${m[2]} | ${M[2]}) echo "Mes: Marzo";;
4 | ${m[3]} | ${M[3]}) echo "Mes: Abril";;
5 | ${m[4]} | ${M[4]}) echo "Mes: Mayo";;
6 | ${m[5]} | ${M[6]}) echo "Mes: Junio";;
7 | ${m[6]} | ${M[6]}) echo "Mes: Julio";;
8 | ${m[7]} | ${M[7]}) echo "Mes: Agosto";;
9 | ${m[8]} | ${M[8]}) echo "Mes: Septiembre";;
10 | ${m[9]} | ${M[9]}) echo "Mes: Octubre";;
11 | ${m[10]} | ${M[10]}) echo "Mes: Noviembre";;
12 | ${m[11]} | ${M[11]}) echo "Mes: Diciembre";;

esac

else echo "Error en el número de argumentos" && exit 1
fi
