/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa en el que se presenta un menu principal para que el usuario elija
   entre calcular una suma, un producto o bien escoja la opci�n de salir, la
   cual hace que el programa termine su ejecuci�n. Si escoge la opci�n de 
   adici�n, se presenta un men� con tres opciones (sumar, restar, o salir).
   Si escoge sumar, se piden dos n�meros reales y se efectua su suma, 
   mostrando el resultado en pantalla y se vuelve al mismo men�. 
   Si se escoge restar, se piden dos n�meros y se restan mostrando el 
   resultado en pantalla y se vuelve al mismo men�, y si se escoge la opci�n 
   de salir, se vuelve al men� principal.
   Por otro lado, si se escoge la opci�n de producto, se muestra un men�
   secundario de tres opciones (multiplicar, dividir o salir). Si se escoge la
   opci�n de multiplicar, se piden dos n�meros reales y se multiplican, 
   mostr�ndose el resultado en pantalla y se vuelve al mismo men� secundario.
   Si se elige la opci�n de dividir, se piden dos reales y se dividen mostrando
   el resultado en pantalla y se vuevle inmediatamente al mismo men� anterior.
   Si por el contrario se escoge la opci�n de salir, se vuelve al men� 
   principal.
   
   Entradas: 
    Independientemente de opci�n escogida en los men�s, los datos de entrada van
    a ser dos n�meros reales (numero1, numero2).
   
   Salidas:
    El resultado de sumar, restar, multiplicar o dividir los n�meros 
    introducidos (suma, resta, multiplicacion ,division).
    
   Este programa lo he llevado a cabo mediante un anidamiento de estructuras
   repetitivas de tipo post test (do-while) y estructuras condicionales 
   m�ltiples (switch).
   En primer lugar, he establecido un ciclo do-while que entrar� en bucle s�
   y solo s� la opci�n escogida por el usuario en el men� principal no es la
   opci�n de salir (tanto las opciones como las operaciones las he declarado
   como datos de tipo car�cter, y en los switchs las he puesto entre comillas
   dobles, asignando as� un valor entero a los caracteres (equivalencia entre
   datos de tipo car�cter y entero). Si la opci�n escogida es adici�n o 
   producto se entra al bucle y se empieza a evaluar la primera estructura 
   switch, relativa a la opcionalidad, de tal forma que se contemplan tres
   casos:
   1) Que la opci�n sea la A: he establecido un ciclo do-while que entr� en
   bucle s� y solamente s� la opci�n escogida por el usuario en el men� 
   principal es la A y que en las operaciones no se haya escogido la opci�n de 
   salir del men�, de esta forma, si la condici�n se cumple, se eval�a el
   cuerpo del bucle y se pasa a otra escturctura condicional m�ltiple, en la 
   que se contemplan las operaciones posibles en esa opci�n, y en cada una de 
   ellas, se lleva cabo una lectura de datos (dos n�meros reales cualesquiera), 
   unos c�lculos y una salida de datos.
   2) Que opci�n sea la P: he establecido otro ciclo do-while al que se entrar�
   cuando se cumpla la condic�n de que la opci�n elegida sea la P y en las
   operaciones no se haya escogido la opci�n de salir del men�. Si la condici�n
   se cumple, entonces se procede a evaluar el cuerpo del bucle y se ejecuta
   una estructura condicional m�ltiple relativa a las operaciones que pueden 
   realizarse habiendo escogido esa opci�n del men�. En cada unos de los casos
   que se contemplan en dicha opci�n se lleva a cabo una lectura de datos (dos
   n�meros reales cualesquiera), unos c�lculos y una salida de datos.
   3) Si la opci�n marcada en el men� principal es la de salir, se muestra un
   mensaje de que el programa ha finalizado y se termina la ejecuci�n del 
   programa.
   
   En cualquiera de los casos 1) o 2), una vez que se realizan las operaciones
   pertinentes se vuelve a los men�s secundarios correspondientes. Adem�s
   en ambos casos si se escoge la opci�n de salir en los men�s secundarios de 
   operaciones, se vuelve inmediatamente al men� principal.    
                         
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <string>
#include <cctype>
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaraci�n de datos
	
	// Datos de entrada
	
	double numero1, numero2;
	
	// Datos del menu

	char operaciones, opcion;
	
	// Datos de salida
	
	double suma, resta, multiplicacion, division;
	
/******************************************************************************/

	// Entrada de datos

    do{
     
    		cout << endl;
			cout << "---------------------------------";
			cout << "           MENU PRINCIPAL	      ";
			cout << "---------------------------------";
			cout << endl;
			cout << "    A-> Calcular adicion";
			cout << endl;
			cout << "    P-> Calcular producto";
			cout << endl;
			cout << "    X-> Salir";
			cout << endl;
			cout << "---------------------------------";
			cout << endl;
			
			do{
					
				cout << "Elija una de estas opciones: ";
				cin  >> opcion;
				opcion = toupper(opcion);
				cout << endl;
				
			}while ((opcion != 'A') && (opcion != 'P') &&
				    (opcion != 'X'));
			

		
		switch(opcion){
		
			case ('A'):
		
			do{
			
				cout << endl;
				cout << "---------------------------------";
				cout << "           MENU SECUNDARIO	      ";
				cout << "---------------------------------";
				cout << endl;
				cout << "    S-> Calcular suma";
				cout << endl;
				cout << "    R-> Calcular resta";
				cout << endl;
				cout << "    X-> Salir";
				cout << endl;
				cout << "---------------------------------";
				cout << endl;
				
				do{
					
				cout << "Elija una de estas operaciones: ";
				cin  >> operaciones;
				operaciones = toupper(operaciones);
				cout << endl;
				
				}while ((operaciones != 'S') && (operaciones != 'R') &&
				       (operaciones != 'X'));
					   			
				switch(operaciones){
				
					case('S'):
						
						// Entrada de datos
					
						cout << "Introduzca el primer numero: ";
						cin  >> numero1;
						cout << "Introduzca el segundo numero: ";
						cin  >> numero2;
						
						// C�lculos
					
						suma = numero1 + numero2 ;
						
					    // Salida de datos
					    
						cout << endl;
						cout << "La suma de estos dos numeros es: " << suma;
						cout << endl;
					
					break;
				
					case ('R'):
				
				        // Entrada de datos
				        
						cout << "Introduzca el primer numero: ";
						cin  >> numero1;
						cout << "Introduzca el segundo numero: ";
						cin  >> numero2;
					
					    // C�lculos
					    
						resta = numero1 - numero2 ;
						
						// Salida de datos
					
						cout << endl;
						cout << "La resta de estos dos numeros es: " << resta;
						cout << endl;	
					
					break;
				
					case ('X'):
				
					break;
					
				}
		
	    	}while (operaciones != 'X');
	    	
			while (operaciones != 'X'){	
		
			case ('P'):
		
				do{	
					cout << endl;
					cout << "---------------------------------";
					cout << "           MENU SECUNDARIO	      ";
					cout << "---------------------------------";
					cout << endl;
					cout << "    M-> Calcular multiplicacion";
					cout << endl;
					cout << "    D-> Calcular division";
					cout << endl;
					cout << "    X-> Salir";
					cout << endl;
					cout << "---------------------------------";
					cout << endl;
					
					do{
					
					cout << "Elija una de estas operaciones: ";
					cin  >> operaciones;
					operaciones = toupper(operaciones);
					cout << endl;
				
					}while ((operaciones != 'M') && (operaciones != 'D') &&
				       		(operaciones != 'X'));
			
				switch(operaciones){
				
					case ('M'):
						
						// Entrada de datos
					
						cout << "Introduzca el primer numero: ";
						cin  >> numero1;
						cout << "Introduzca el segundo numero: ";
						cin  >> numero2;
						
					    // C�lculos
					
						multiplicacion = numero1 * numero2 ;
						
						// Salida de datos
					
						cout << endl;
						cout << "La multiplicacion de estos dos numeros es: " 
					     	 << multiplicacion;
						cout << endl;
					
					break;
				
					case ('D'):
						
						// Entrada de datos
				
						cout << "Introduzca el primer numero: ";
						cin  >> numero1;
						do{
							cout << "Introduzca el segundo numero: ";
							cin  >> numero2;
							
						}while (numero2 == 0);
						
						// C�lculos
					
						division = numero1 / numero2 ;
						
						// Salida de datos
					
						cout << endl;
						cout << "La division de estos dos numeros es: " 
						     << division;
						cout << endl;	
					
					break;
				
					case ('X'):
					break;
				
				}
			
				}while (operaciones != 'X') ;
			
			case ('X'):
			break;
		
    	}
    }
	
	}while ((opcion != 'X'));
	
	
		
	cout << "FIN DEL PROGRAMA";
	cout << endl;
	

/******************************************************************************/
	return 0;
}
			
			
				
	
