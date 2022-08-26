/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee un carácter (será una letra mayúscula), lo pasa a minúscula 
   y lo imprime en pantlla.

   Entradas: Una letra en mayúscula.
   
   Salidas: Una letra en minúscula.
                      
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	
	// DECLARACIÓN DE DATOS
	
	// Datos de entrada
	
    char mayuscula;
    const int DIFERENCIA = 32;    // El 32 se refiere a que en la pagina de 
                                  // códigos ISO/IEC 8859-1, las letras 
                                  // mayúsculas difieren en 32 posiciones de las
                                  //minúsculas (dato sacado de la tabla de la 
								  // página 82 del guión de prácticas).
    // Dato de salida
    
	char minuscula;
    
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca una letra en mayuscula: ";
	cin >> mayuscula;
	
	// Conversión a minúscula
	
	minuscula = mayuscula + DIFERENCIA;
	
	// Salida de datos
	
	cout << "La letra en minuscula es: "<< minuscula <<endl;
    cout <<endl;
	
/******************************************************************************/    
    return 0;
}
