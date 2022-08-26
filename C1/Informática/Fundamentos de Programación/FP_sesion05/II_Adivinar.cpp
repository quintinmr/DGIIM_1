/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Este es un programa para jugar a adivinar un n�mero. Consiste en que el
   usuario introduce un n�mero y el programa indica si dicho n�mero est� por 
   encima o por debajo del n�mero aleatorio que genere el programa.
   
   Entradas: 
    Un n�mero cualquiera que introduce el usuario (numero).
    
   Salidas:
    Un mensaje que nos dice si el n�mero que hemos introducido est� por enicma
    o por debajo del n�mero aleatorio, o si hemos acertado.
    
   
   El programa lo he llevado a cabo de la siguiente forma: 
   En primer lugar, he introducido una serie de instrucciones para la 
   generaci�n del n�mero aleatorio a adivinar, y que he copiado del gui�n
   de pr�cticas, dicho sea de paso. Una vez generado dicho n�mero, he 
   establecido una estructura repetitiva de tipo pre-test, dentro de la cual
   he establecido una serie de estructuras condicionales dobles acerca de las
   caracter�sticas del n�mero introducido. La condici�n que he establecido
   para entrar en el ciclo while la he definido mediante una variable tipo bool.
   Dicha condici�n es que el n�mero introducido no coincida con el n�mero 
   originado aleatoriamente ni con el terminador (el terminador es un n�mero
   (al que le he asignado el valor -1), tal que sea cual sea el momento en 
   el que el usuario lo introduzca, se finaliza el juego). Por otro lado, si
   se cumple la condici�n impuesta se procede a analizar las caracter�sticas
   del n�mero introducido, mediante una estructura condicional doble, 
   determinando as� si dicho n�mero est� por encima o por debajo del n�mero
   secreto.
   Si no se cumple la condici�n del while ser�, como ya he dicho, que el usuario
   ha acertado el n�mero o que ha introducido el terminador. De esta forma, no
   se ejecuta el while y se actualiza el contador de intentos que me dir� 
   cu�ntos intentos he realizado para acertar el n�mero y se muestra en pantalla
   un mensaje en funci�n de lo que haya ocurrido: si ha acertado, muestra un
   mensaje felicitando, y si ha introducido el terminador, muestra un mensaje
   de fin del juego.
                         
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaraci�n de datos
	
	int numero = 0;
	
	const int TERMINADOR = -1;
	const int MIN = 1;
	const int MAX = 100;
	int intentos = 1;
		
	const int NUM_VALORES = MAX - MIN + 1; // N�mero de valores posibles
	                 
	int num_secreto = 0;  // N�mero aleatorio a generar: "inc�gnita"
	
/******************************************************************************/

	// Entrada de datos
	
		time_t t;
		srand (time(&t));   // Se inicia el generador de n�meros aleatorios 
		                    // con el reloj del sistema.
	                  
	   // Generaci�n del n�mero aleatorio (MIN <= num_secreto <= MAX)
	   
	    num_secreto = (rand() % NUM_VALORES) + MIN;   
	    
	    
		cout << "ADIVINA UN NUMERO";
		cout << endl;
		cout << "Introduzca un numero entre 1 y 100, o introduzca -1 "
				"para terminar la partida: ";
		cin  >> numero;
		
		// Declaro una variable tipo bool para determinar la condici�n del
		// ciclo que voy a establecer, que ser� del tipo pre-test
		
		bool num_ok = ((numero >= 1) && (numero <= 100));
		
		while(num_ok){
		
		bool juega = ((numero != TERMINADOR) && (numero != num_secreto)); 		
		
		while (juega){
			
	    		if (numero < num_secreto){
	    		
	    			cout << "Se ha quedado por debajo del numero."
				         << " Intente de nuevo";
	    	        cout << endl;
	    	             
	    		}
	    	
	    		else
	    		{
					cout << "Se ha quedado por encima del numero. "
					     << "Intente de nuevo.";
					cout << endl;
												 	    	    
				}
					
		    
		    intentos ++;   // Se actualiza el contador de intentos
		    
		    cout << endl;
			cout << "Introduzca un numero entre 1 y 100, o introduzca -1 "
				    "para terminar la partida: ";
			cin  >> numero;
			
			// Actualizo la bandera
			
			juega = ((numero != TERMINADOR) && (numero != num_secreto));
			
		}
		
		if (numero == TERMINADOR){  // No se quiere seguir jugando
			
			    cout << endl;
				cout << "FIN DEL JUEGO. HASTA PRONTO";
				cout << endl;
		}
			
		else  // Que el usuario acierte el n�mero (numero == num_secreto)
		{  
			
				cout << endl;
				cout << "GENIAL, �HA ADIVINADO EL NUMERO!";
				cout << " ERA EL " << num_secreto;
				cout << ". LO HA HECHO EN " << intentos << " intentos";
				cout << endl;
				
		}
		
		cout << "Si desea seguir jugando pulse s . Si no es asi, pulse"
			         << " -1: ";
			         
		if ("s"){
			
			cout << "Introduzca un numero entre 1 y 100, o introduzca -1 "
				 << "para terminar la partida: ";
			cin  >> numero;
			
	    }
	
		else
		{
			if ("-1"){
				
				cout << "FIN DEL JUEGO";
				cout << endl;
			}
					
			else{
				cout << "FIN DEL JUEGO";
				cout << endl;
					
			}
			
		}
	

		
	}
				
				
			
					 

/******************************************************************************/
	return 0;	
		
}

	  	
	

	


