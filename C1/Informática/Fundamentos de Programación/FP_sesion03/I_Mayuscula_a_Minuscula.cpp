/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee un car�cter (ser� una letra may�scula), lo pasa a min�scula 
   y lo imprime en pantlla.

   Entradas: Una letra en may�scula.
   
   Salidas: Una letra en min�scula.
                      
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	
	// DECLARACI�N DE DATOS
	
	// Datos de entrada
	
    char mayuscula;
    const int DIFERENCIA = 32;    // El 32 se refiere a que en la pagina de 
                                  // c�digos ISO/IEC 8859-1, las letras 
                                  // may�sculas difieren en 32 posiciones de las
                                  //min�sculas (dato sacado de la tabla de la 
								  // p�gina 82 del gui�n de pr�cticas).
    // Dato de salida
    
	char minuscula;
    
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca una letra en mayuscula: ";
	cin >> mayuscula;
	
	// Conversi�n a min�scula
	
	minuscula = mayuscula + DIFERENCIA;
	
	// Salida de datos
	
	cout << "La letra en minuscula es: "<< minuscula <<endl;
    cout <<endl;
	
/******************************************************************************/    
    return 0;
}
