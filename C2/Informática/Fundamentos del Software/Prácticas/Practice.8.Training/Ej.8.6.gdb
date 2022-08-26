#!/bin/bash
# Guión correspondiente al ejercicio 8.6
# Autor: Quintín Mesa Romero 1ºA.2 DGIIM

break 15
run
info locals
p/x$pc
x/i$pc
next
break 29
info locals
p/x$pc
x/i$pc
next
break 42
info locals
p/x$pc
x/i$pc
next
break 47
info locals
p/x$pc
x/i$pc
next
delete breakpoints 2 3 4
