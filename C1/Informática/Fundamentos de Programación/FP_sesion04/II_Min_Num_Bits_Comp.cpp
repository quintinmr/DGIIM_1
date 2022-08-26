/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee un n�mero entero positivo, y calcula el m�nimo n�mero de
   bits necesarios para su representaci�n, comprobando previamente que el
   caracter que introduce el usuario es un n�mero positivo.

   Entradas: Un n�mero entero positivo (entero_positivo).
   
   Salidas: N�mero m�nimo de bits (min_num_bits) para representar al n�mero 
   entero positivo.
   
   En este programa, el usuario tiene que introducir un n�mero entero positivo
   pero puede que el usuario introduzca un numero negativo, o introduzca el
   cero. De esta forma, he establecido una condici�n doble, de tal forma
   que se verifica s� y solo s� el n�mero que se introduce es un entero 
   positivo. Si no es as� (else), el programa indica que ha habido un error 
   y pide al usuario que introduzca un entero positivo.
   Para calcular el m�nimo n�mero de bits, he procedido de la siguiente forma:
   en primer lugar, tomando como ejemplo algunos n�meros enteros, los he pasado
   a mano, a binario, y he visto la de forma experimental el m�nimo n�mero de 
   bits necesarios para su representaci�n. A continuaci�n, he observado que 
   existe una relaci�n entre el n�mero m�nimo de bits necesarios para 
   representar un n�mero entero, y las potencias de dos: de 0 a 1 (2^0)
   se necesita 1 bit, de 2 (2^1) a 3, se necesitan 2, de 4 (2^2) a 7, se 
   necesitan 3, y as� sucesivamente. De esta forma, para obtener el m�nimo
   n�mero de bits, hago uso del logaritmo en base dos del n�mer entero 
   (relaciono las potencias en base dos con el logaritmo en base dos). Dicho
   logaritmo me va a dar una cifra decimal, cuya parte entera es una unidad
   menor que el n�mero m�nimo de bits para representar al n�mero, de esta forma
   solo tendr�a que sumarle la unidad a la parte entera del logaritmo en base
   dos del n�mero.
   
                      
*/               
/******************************************************************************/

#include <iostream>    // Inclusi�n de los recursos de E/S (entrada/salida)
#include <cmath>       // Inclusi�n de los recursos matematicos
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	
    // DECLARACI�N DE DATOS
     
    // Datos de entrada
    
	int entero_positivo;
	
	// Datos de salida
	
	int min_num_bits;
	
	
	int log_base_dos;   // Declaro este dato para simplificar los c�lculos.
	                                               
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca un numero entero positivo: ";
	cin >> entero_positivo;
	
	// Condiciones, c�lculos y salida de datos
	

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
