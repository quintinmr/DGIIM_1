/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee tres números enteros y dice si están o no ordenados.
   
   Entradas:
    Tres números enteros (entero1, entero2, y entero3)   
   
   Salidas: 
    Están ordenados o no.
    
   En este programa, para determinar si los números que el usuario introduce
   están ordenados o no, he establecido una estructura condicional doble
   en la que he determinado una restricción de los datos. Dicha restricción
   se basa en que los datos que debe introducir el usuario han de ser de 
   carácter numérico. De esta forma he establecido que dichos datos deben
   ocupar una posición en la página de códigoc ASCII, entre '0' y '9'. En 
   cualquier otro caso distinto, el programa da ERROR y pide al usuario que
   introduzca un número y además entero. Si la condición se cumple, entonces
   se pasa a analizar los datos introducido; dicho análisis se basa en si
   dichos datos numéricos verifican la condicion de orden que he establecido,
   de tal forma que si la cumplen, el programa dirá que están ordenados y,
   en caso contrario, que no están ordenados.
                      
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaración de datos
	
	// Datos de entrada
	
	int num1;
	int num2;
	int num3;
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca el primer numero: ";
	cin >> num1;
	
	cout << "Introduzca el segundo numero: ";
	cin >> num2;
	
	cout << "Introduzca el tercer numero: ";
	cin >> num3;
	

	// Condiciones y salida de datos
	
	if (((num1 || num2 || num3 ) >= '0') && ((num1 || num2 || num3 ) <= '9')) {
		
		if (((num1<num2) && (num2<num3)) || ((num1>num2) && (num2>num3))) {
	
				
			cout << "Los numeros estan ordenados";
	
    	}
    
		else
		{
		
		cout << "Los numeros no estan ordenados";
		
   		}
    }
    
    else 
    {
    	cout << "ERROR: Debe introducir un numero entero" <<endl;
    	
    }
    
	cout << "\nFin del programa";

/******************************************************************************/	
	return 0;	  
}

	
