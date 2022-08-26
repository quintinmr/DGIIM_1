/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee un valor entero en un dato de tipo string, convirtiéndolo
   y asignándolo a un dato int (de tres dígitos), de tal forma que se impriman
   en pantalla los dígitos, separados por dos espacios en blanco.
   
   Entradas: 
    Un dato de tipo string (numero).
    
   Salidas: 
    Un dato string compuesto por tres parejas de valores constituídas por 
    un espacio en blanco y un dígito.
    
                      
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <string>
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaración de datos
	
	// Datos de entrada
	
	string cad_3_digitos;
	
	int numero_tres_cifras;
	int numero_dos_cifras;
	
	int centenas;
	int decenas;
	int unidades;
	
	// Datos de salida
	
	string cad_final;
	const string ESPACIO = "   "; // Declaración de una constante
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca un numero de tres cifras: ";
	cin  >> cad_3_digitos;
	cout <<endl;
	
	// Condiciones, cálculos y salida de datos
	
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
	
