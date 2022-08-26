/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee tres n�meros enteros y dice si est�n o no ordenados.
   
   Entradas:
    Tres n�meros enteros (entero1, entero2, y entero3)   
   
   Salidas: 
    Est�n ordenados o no.
    
   En este programa, para determinar si los n�meros que el usuario introduce
   est�n ordenados o no, he establecido una estructura condicional doble
   en la que he determinado una restricci�n de los datos. Dicha restricci�n
   se basa en que los datos que debe introducir el usuario han de ser de 
   car�cter num�rico. De esta forma he establecido que dichos datos deben
   ocupar una posici�n en la p�gina de c�digoc ASCII, entre '0' y '9'. En 
   cualquier otro caso distinto, el programa da ERROR y pide al usuario que
   introduzca un n�mero y adem�s entero. Si la condici�n se cumple, entonces
   se pasa a analizar los datos introducido; dicho an�lisis se basa en si
   dichos datos num�ricos verifican la condicion de orden que he establecido,
   de tal forma que si la cumplen, el programa dir� que est�n ordenados y,
   en caso contrario, que no est�n ordenados.
                      
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaraci�n de datos
	
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

	
