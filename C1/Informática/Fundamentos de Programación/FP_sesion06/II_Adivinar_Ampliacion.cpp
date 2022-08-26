/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Este es un programa para jugar a adivinar un n�mero. Consiste en que el
   usuario introduce un n�mero y el programa indica si dicho n�mero est� por 
   encima o por debajo del n�mero aleatorio que genere el programa. Si ha 
   acertado, env�a un mensaje de enhorabuena ,y si ha decidido termianar, 
   simplemente, se finaliza el juego. En ambos casos se pregunta si desea
   jugar de nuevo, de tal forma que si la respuesta es afirmativa, se inica
   de nuevo el juego.
   
   Entradas: 
    Un n�mero cualquiera que introduce el usuario (numero).
    
   Salidas:
    Un mensaje que nos dice si el n�mero que hemos introducido est� por enicma
    o por debajo del n�mero aleatorio, o si hemos acertado.
    
   
   El programa lo he llevado a cabo de la siguiente forma: 
   En primer lugar, he establecido una estructura repetitiva de tipo while que 
   se ejecutar� al menos una vez debido a que a la condic�n que le he puesto le
   he asignado el valor de verdad, mediante una variable tipo bool declarada 
   previamente. Una vez dentro del while, he introducido una serie de 
   instrucciones para la generaci�n del n�mero aleatorio a adivinar, y que he 
   copiado del gui�nde pr�cticas, dicho sea de paso. Una vez generado dicho 
   n�mero, he establecido una estructura repetitiva de tipo post-test para 
   filtrar el dato num�rico que introduzca el jugador. Una vez filtrado el 
   n�mero, he establecido una esturctura c�clica de tipo while dentro de la cual
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
   de fin del juego. En el caso de que el jugador ,quiera volver a jugar, he
   establecido una estructura condicional doble relativa la respuesta del
   jugador; si quiere jugar, entonces deber� introducir la letra 's' de tal
   forma que se imprime un salto de l�nea y se vuelve a empezar el ciclo, 
   gener�ndose otro n�mero aleatorio con el que jugar. Si la respuesta es no, 
   el usuario deber� introducir 'n', y se imprime un mensaje de despedida.
                         
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
	bool continua_jugando = true;
	char seguir_jugando;
		
	const int NUM_VALORES = MAX - MIN + 1; // N�mero de valores posibles
	                 
	int num_secreto = 0;  // N�mero aleatorio a generar: "inc�gnita"
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "----------------------- ";
	cout << endl;
	cout << "  ADIVINA UN NUMERO";
	cout << endl;    
	cout << "----------------------- ";
	cout << endl;
	
	while (continua_jugando){
	
		time_t t;
		srand (time(&t));   // Se inicia el generador de n�meros aleatorios 
		                    // con el reloj del sistema
		                	          
	   // Generaci�n del n�mero aleatorio (MIN <= num_secreto <= MAX)
	   
	    num_secreto = (rand() % NUM_VALORES) + MIN;   
	    
	    // A continuaci�n filtro el n�mero que introduce el usuario
	    
	    	do{
	    
				cout << endl;
				cout << "Introduzca un numero entre 1 y 100, o introduzca -1 "
					 <<	"para terminar la partida: ";
				cin  >> numero;
				
			}while(((numero < MIN) || (numero > MAX)) && (numero !=TERMINADOR));
			
			
		
		// Declaro una variable tipo bool para determinar la condici�n del
		// ciclo que voy a establecer, que ser� del tipo pre-test
		
			bool juega = ((numero != TERMINADOR)&&(numero != num_secreto)); 		
		
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
		    
		    do{
		    	
		    	cout << endl;
				cout << "Introduzca un numero entre 1 y 100, o introduzca -1 "
				   	 <<	 "para terminar la partida: ";
				cin  >> numero;
				
			}while (((numero < MIN) || (numero > MAX))&&(numero !=TERMINADOR));
			
			// Actualizo la bandera
			
			juega = ((numero != TERMINADOR) && (numero != num_secreto));
			
		}
		
			if (numero == TERMINADOR){  // No se quiere seguir jugando
			
			    cout << endl;
				cout << "FIN DEL JUEGO. HASTA PRONTO";
				cout << endl;
				
			}
			
			else    // Que el usuario acierte el n�mero (numero == num_secreto)
			{  
			
					cout << endl;
					cout << "GENIAL, �HA ADIVINADO EL NUMERO!";
					cout << " ERA EL " << num_secreto;
					cout << ". LO HA HECHO EN " << intentos << " intentos";
					cout << endl;
					 
		    }
		    
		    // Si el usuario quiere seguir jugando
		    
		    cout << endl;
		    cout << "�Desea jugar de nuevo? Si la respuesta es si, pulse 's' "
		         << ". Si la respuesta es no, pulse 'n': ";
			cin  >> seguir_jugando;
			
			if (seguir_jugando != 's'){
				
				continua_jugando = false;
				cout << "HASTA PRONTO";
				
			}
			
			else
			{
				cout << endl;
				
			}
	
	}

/******************************************************************************/
	return 0;	
		
}
