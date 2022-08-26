/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee un número entero positivo, y calcula el mínimo número de
   bits necesarios para su representación.

   Entradas: Un número entero positivo (entero_positivo).
   
   Salidas: Número mínimo de bits (min_num_bits) para representar al número 
   entero positivo.
                      
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
	
    
    bool argumento_factible;   // Declaro una variable tipo bool (el porqué de
                               // esta decisión lo explico en los cálculos).
    
                                                   
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca un numero entero positivo: ";
	cin >> entero_positivo;
	
	// Cálculos
	
	argumento_factible = entero_positivo > 0;
	
	log_base_dos = log2(entero_positivo);
	
	min_num_bits = argumento_factible * (log_base_dos) + 1 ;
	
	/* Como en el ejercicio nos dicen que se incluye el 0 además de los enteros
    positivos, he decidido declarar una variable tipo bool para que, en caso de
    que el usuario introduzca el valor 0, el número mínimo de bits se muestre
    como 1, que es el número mínimo de bits necesarios para representar
	al cero. Lo que ocurre es lo siguiente: si el usuario introduce el número 0,
    el lgaritmo en base dos de 0 no existe, por lo tanto, al haber declarado la 
    variable tipo bool "argumento_factible", en la que se establece la condición
	de que el argumento del logartimo ha de ser positivo, es decir que el número
	entero que introduzca el usuario sea mayor estrico que cero, me devuelve un
	cero, que multiplicado por "log_base_dos", me da cero, luego, al sumarle 1
	(mirar apartado de cáclulos), el número mínimo de bits necesarios para
	reresentar al cero será uno. Para cualquier otro caso la condición será 
	verdadera y me devolverá un 1, que, como elemento neutro del producto, deja
	invariante el logaritmo, de tal forma que el número mínimo de bits
	necesarios para representar cualquier número positivo, será su logaritmo en
	base dos, más la unidad.                                                  */
	
	// Salida de datos
	
	cout << "El numero minimo de bits necesarios para representar el numero " <<
			entero_positivo << " es: " << min_num_bits <<endl;
		   
/******************************************************************************/	   
    return 0;
}
    
	
