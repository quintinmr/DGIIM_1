/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que intercambia el dinero que contienen dos cajas, una a la derecha
   y otra a la izquierda. 
   
   Entradas:  cantidad de dinero que contiene la caja izquierda (caja_izda) y 
   la caja derecha (caja_dcha).
   
   Salidas :cantidad de dinero de cada caja, pero intercambiado.
   
   El c�digo que aparece en el enunciado del ejercicio,en el gui�n de pr�cticas:
   caja_izda = caja_dcha;
   caja_dcha = caja_izda;
   no es v�lido porque, si a la caja de la izquierda le asignamos el valor de la 
   caja derecha, ambas cajas tendr�n el mismo valor. Por lo que al escribir en
   la segunda linea del c�digo, caja_dcha = caja_izda, le estar�amos asignando a
   la caja derecha su propio valor, ya que, como se puede observar, en la l�nea
   1 de este c�digo se le asigna el dinero de la caja derecha a la caja
   izquierda. Luego, en definitiva, ambas cajas acabar�an teniendo la misma 
   cantidad de dinero (el valor de la caja derecha).
   
   La soluci�n que yo propongo a este problema es, en primer lugar, la  
   declaraci�n de dos datos adicionales, auxialiares: caja_dcha_aux, y
   caja_izda_aux, de tal forma que, a estos nuevos datos, les asigno los 
   valores de caja_dcha y caja_izda respectivamente. Por otro lado, a caja_dcha 
   le asigno el valor de caja_izda_aux, y a caja_izda, el valor de 
   caja_dcha_aux. De esta forma,se produce un intercambio;la caja de la derecha
   pasa a contener el dinero de la de la izquierda, y la caja de la izquierda 
   pasa a contener el dinero de la caja de la derecha.
                                       
*/               
/******************************************************************************/

#include <iostream>      //Inclusi�n de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	
	// DECLARACI�N DE DATOS
	
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


