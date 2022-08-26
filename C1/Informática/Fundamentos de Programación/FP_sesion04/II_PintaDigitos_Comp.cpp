/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee un valor entero en un dato de tipo string, convirti�ndolo
   y asign�ndolo a un dato int (de tres d�gitos), de tal forma que se impriman
   en pantalla los d�gitos, separados por dos espacios en blanco.
   
   Entradas: 
    Un dato de tipo string (numero).
    
   Salidas: 
    Un dato string compuesto por tres parejas de valores constitu�das por 
    un espacio en blanco y un d�gito.
    
                      
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <string>
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaraci�n de datos
	
	// Datos de entrada
	
	string cad_3_digitos;
	
	int numero_tres_cifras;
	int numero_dos_cifras;
	
	int centenas;
	int decenas;
	int unidades;
	
	// Datos de salida
	
	string cad_final;
	const string ESPACIO = "   "; // Declaraci�n de una constante
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca un numero de tres cifras: ";
	cin  >> cad_3_digitos;
	cout <<endl;
	
	// Condiciones, c�lculos y salida de datos
	
		numero_tres_cifras = stoi(cad_3_digitos);
	
	if ((numero_tres_cifras >= 100 ) && (numero_tres_cifras <= 999)) {
		
		
		centenas           = (numero_tres_cifras / 100);
		numero_dos_cifras  = (numero_tres_cifras % 100);
		
		decenas            = (numero_dos_cifras / 10);
		unidades           = (numero_dos_cifras % 10);
		
		cad_final       = (ESPACIO + to_string(centenas) + 
		                      ESPACIO + to_string(decenas)  + 
							  ESPACIO + to_string(unidades));
					   
		cout << cad_final << endl;
		
	}
	
	else 
	{ 
		cout << "ERROR: Debe introducir un numero de tres cifras.";
		cout <<endl;
	
	}

	
/******************************************************************************/
	return 0;
	
}
	
