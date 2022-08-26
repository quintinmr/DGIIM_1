/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee un número entero positivo, y calcula el mínimo número de
   bits necesarios para su representación, comprobando previamente que el
   caracter que introduce el usuario es un número positivo.

   Entradas: Un número entero positivo (entero_positivo).
   
   Salidas: Número mínimo de bits (min_num_bits) para representar al número 
   entero positivo.
   
   En este programa, el usuario tiene que introducir un número entero positivo
   pero puede que el usuario introduzca un numero negativo, o introduzca el
   cero. De esta forma, he establecido una condición doble, de tal forma
   que se verifica sí y solo sí el número que se introduce es un entero 
   positivo. Si no es así (else), el programa indica que ha habido un error 
   y pide al usuario que introduzca un entero positivo.
   Para calcular el mínimo número de bits, he procedido de la siguiente forma:
   en primer lugar, tomando como ejemplo algunos números enteros, los he pasado
   a mano, a binario, y he visto la de forma experimental el mínimo número de 
   bits necesarios para su representación. A continuación, he observado que 
   existe una relación entre el número mínimo de bits necesarios para 
   representar un número entero, y las potencias de dos: de 0 a 1 (2^0)
   se necesita 1 bit, de 2 (2^1) a 3, se necesitan 2, de 4 (2^2) a 7, se 
   necesitan 3, y así sucesivamente. De esta forma, para obtener el mínimo
   número de bits, hago uso del logaritmo en base dos del númer entero 
   (relaciono las potencias en base dos con el logaritmo en base dos). Dicho
   logaritmo me va a dar una cifra decimal, cuya parte entera es una unidad
   menor que el número mínimo de bits para representar al número, de esta forma
   solo tendría que sumarle la unidad a la parte entera del logaritmo en base
   dos del número.
   
                      
*/               
/******************************************************************************/

#include <iostream>    // Inclusión de los recursos de E/S (entrada/salida)
#include <cmath>       // Inclusión de los recursos matematicos
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	
    // DECLARACIÓN DE DATOS
     
    // Datos de entrada
    
	int entero_positivo;
	
	// Datos de salida
	
	int min_num_bits;
	
	
	int log_base_dos;   // Declaro este dato para simplificar los cálculos.
	                                               
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca un numero entero positivo: ";
	cin >> entero_positivo;
	
	// Condiciones, cálculos y salida de datos
	

	if (entero_positivo > 0) {
		
			log_base_dos = log2(entero_positivo);
	
			min_num_bits =  (log_base_dos) + 1 ;
	
	    	cout << "El numero minimo de bits necesarios para representar "
			"el numero 5" << entero_positivo << " es: " << min_num_bits <<endl;
		
	}

	else
	{
		cout << "ERROR: El caracter que debe introducir es un entero positivo. "
			 <<endl;
			 
    }
			 		   
/******************************************************************************/	   
    return 0;
}
