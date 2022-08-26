/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa en el que se presenta un menu principal para que el usuario elija
   entre calcular una suma, un producto o bien escoja la opción de salir, la
   cual hace que el programa termine su ejecución. Si escoge la opción de 
   adición, se presenta un menú con tres opciones (sumar, restar, o salir).
   Si escoge sumar, se piden dos números reales y se efectua su suma, 
   mostrando el resultado en pantalla y se vuelve al mismo menú. 
   Si se escoge restar, se piden dos números y se restan mostrando el 
   resultado en pantalla y se vuelve al mismo menú, y si se escoge la opción 
   de salir, se vuelve al menú principal.
   Por otro lado, si se escoge la opción de producto, se muestra un menú
   secundario de tres opciones (multiplicar, dividir o salir). Si se escoge la
   opción de multiplicar, se piden dos números reales y se multiplican, 
   mostrándose el resultado en pantalla y se vuelve al mismo menú secundario.
   Si se elige la opción de dividir, se piden dos reales y se dividen mostrando
   el resultado en pantalla y se vuevle inmediatamente al mismo menú anterior.
   Si por el contrario se escoge la opción de salir, se vuelve al menú 
   principal.
   
   Entradas: 
    Independientemente de opción escogida en los menús, los datos de entrada van
    a ser dos números reales (numero1, numero2).
   
   Salidas:
    El resultado de sumar, restar, multiplicar o dividir los números 
    introducidos (suma, resta, multiplicacion ,division).
    
   Este programa lo he llevado a cabo mediante un anidamiento de estructuras
   repetitivas de tipo post test (do-while) y estructuras condicionales 
   múltiples (switch).
   En primer lugar, he establecido un ciclo do-while que entrará en bucle sí
   y solo sí la opción escogida por el usuario en el menú principal no es la
   opción de salir (tanto las opciones como las operaciones las he declarado
   como datos de tipo carácter, y en los switchs las he puesto entre comillas
   dobles, asignando así un valor entero a los caracteres (equivalencia entre
   datos de tipo carácter y entero). Si la opción escogida es adición o 
   producto se entra al bucle y se empieza a evaluar la primera estructura 
   switch, relativa a la opcionalidad, de tal forma que se contemplan tres
   casos:
   1) Que la opción sea la A: he establecido un ciclo do-while que entrá en
   bucle sí y solamente sí la opción escogida por el usuario en el menú 
   principal es la A y que en las operaciones no se haya escogido la opción de 
   salir del menú, de esta forma, si la condición se cumple, se evalúa el
   cuerpo del bucle y se pasa a otra escturctura condicional múltiple, en la 
   que se contemplan las operaciones posibles en esa opción, y en cada una de 
   ellas, se lleva cabo una lectura de datos (dos números reales cualesquiera), 
   unos cálculos y una salida de datos.
   2) Que opción sea la P: he establecido otro ciclo do-while al que se entrará
   cuando se cumpla la condicón de que la opción elegida sea la P y en las
   operaciones no se haya escogido la opción de salir del menú. Si la condición
   se cumple, entonces se procede a evaluar el cuerpo del bucle y se ejecuta
   una estructura condicional múltiple relativa a las operaciones que pueden 
   realizarse habiendo escogido esa opción del menú. En cada unos de los casos
   que se contemplan en dicha opción se lleva a cabo una lectura de datos (dos
   números reales cualesquiera), unos cálculos y una salida de datos.
   3) Si la opción marcada en el menú principal es la de salir, se muestra un
   mensaje de que el programa ha finalizado y se termina la ejecución del 
   programa.
   
   En cualquiera de los casos 1) o 2), una vez que se realizan las operaciones
   pertinentes se vuelve a los menús secundarios correspondientes. Además
   en ambos casos si se escoge la opción de salir en los menús secundarios de 
   operaciones, se vuelve inmediatamente al menú principal.    
                         
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <string>
#include <cctype>
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaración de datos
	
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
						
						// Cálculos
					
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
					
					    // Cálculos
					    
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
						
					    // Cálculos
					
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
						
						// Cálculos
					
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
			
			
				
	
