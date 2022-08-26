/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que intercambia el dinero que contienen dos cajas, una a la derecha
   y otra a la izquierda. 
   
   Entradas:  cantidad de dinero que contiene la caja izquierda (caja_izda) y 
   la caja derecha (caja_dcha).
   
   Salidas :cantidad de dinero de cada caja, pero intercambiado.
   
   El código que aparece en el enunciado del ejercicio,en el guión de prácticas:
   caja_izda = caja_dcha;
   caja_dcha = caja_izda;
   no es válido porque, si a la caja de la izquierda le asignamos el valor de la 
   caja derecha, ambas cajas tendrán el mismo valor. Por lo que al escribir en
   la segunda linea del código, caja_dcha = caja_izda, le estaríamos asignando a
   la caja derecha su propio valor, ya que, como se puede observar, en la línea
   1 de este código se le asigna el dinero de la caja derecha a la caja
   izquierda. Luego, en definitiva, ambas cajas acabarían teniendo la misma 
   cantidad de dinero (el valor de la caja derecha).
   
   La solución que yo propongo a este problema es, en primer lugar, la  
   declaración de dos datos adicionales, auxialiares: caja_dcha_aux, y
   caja_izda_aux, de tal forma que, a estos nuevos datos, les asigno los 
   valores de caja_dcha y caja_izda respectivamente. Por otro lado, a caja_dcha 
   le asigno el valor de caja_izda_aux, y a caja_izda, el valor de 
   caja_dcha_aux. De esta forma,se produce un intercambio;la caja de la derecha
   pasa a contener el dinero de la de la izquierda, y la caja de la izquierda 
   pasa a contener el dinero de la caja de la derecha.
                                       
*/               
/******************************************************************************/

#include <iostream>      //Inclusión de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	
	// DECLARACIÓN DE DATOS
	
	double caja_izda;     
	double caja_dcha;
	double caja_izda_aux;
	double caja_dcha_aux;

/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca la cantidad de dinero contenido en la caja izquierda: ";
	cin >> caja_izda;
	
	cout << "Introduzca la cantidad de dinero contenido en la caja derecha: ";
	cin >> caja_dcha;
	
	// Intercambio
	
	caja_izda_aux = caja_izda;
    caja_dcha_aux = caja_dcha;
	caja_dcha = caja_izda_aux;
	caja_izda = caja_dcha_aux;

	
	//Salida de datos
	
	cout <<endl;
	cout << "El valor de la caja de la izquierda es: "<< caja_izda <<endl;
	cout << "El valor de la caja de la derecha es: "<< caja_dcha <<endl;
	cout <<endl;
	
/******************************************************************************/
	return 0;
}


