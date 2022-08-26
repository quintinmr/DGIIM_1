/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee un n�mero entero positivo, y calcula el m�nimo n�mero de
   bits necesarios para su representaci�n.

   Entradas: Un n�mero entero positivo (entero_positivo).
   
   Salidas: N�mero m�nimo de bits (min_num_bits) para representar al n�mero 
   entero positivo.
                      
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
	
    
    bool argumento_factible;   // Declaro una variable tipo bool (el porqu� de
                               // esta decisi�n lo explico en los c�lculos).
    
                                                   
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca un numero entero positivo: ";
	cin >> entero_positivo;
	
	// C�lculos
	
	argumento_factible = entero_positivo > 0;
	
	log_base_dos = log2(entero_positivo);
	
	min_num_bits = argumento_factible * (log_base_dos) + 1 ;
	
	/* Como en el ejercicio nos dicen que se incluye el 0 adem�s de los enteros
    positivos, he decidido declarar una variable tipo bool para que, en caso de
    que el usuario introduzca el valor 0, el n�mero m�nimo de bits se muestre
    como 1, que es el n�mero m�nimo de bits necesarios para representar
	al cero. Lo que ocurre es lo siguiente: si el usuario introduce el n�mero 0,
    el lgaritmo en base dos de 0 no existe, por lo tanto, al haber declarado la 
    variable tipo bool "argumento_factible", en la que se establece la condici�n
	de que el argumento del logartimo ha de ser positivo, es decir que el n�mero
	entero que introduzca el usuario sea mayor estrico que cero, me devuelve un
	cero, que multiplicado por "log_base_dos", me da cero, luego, al sumarle 1
	(mirar apartado de c�clulos), el n�mero m�nimo de bits necesarios para
	reresentar al cero ser� uno. Para cualquier otro caso la condici�n ser� 
	verdadera y me devolver� un 1, que, como elemento neutro del producto, deja
	invariante el logaritmo, de tal forma que el n�mero m�nimo de bits
	necesarios para representar cualquier n�mero positivo, ser� su logaritmo en
	base dos, m�s la unidad.                                                  */
	
	// Salida de datos
	
	cout << "El numero minimo de bits necesarios para representar el numero " <<
			entero_positivo << " es: " << min_num_bits <<endl;
		   
/******************************************************************************/	   
    return 0;
}
    
	
