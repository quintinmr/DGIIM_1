/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Este es un programa para jugar a adivinar un número. Consiste en que el
   usuario introduce un número y el programa indica si dicho número está por 
   encima o por debajo del número aleatorio que genere el programa. Si ha 
   acertado, envía un mensaje de enhorabuena ,y si ha decidido termianar, 
   simplemente, se finaliza el juego. En ambos casos se pregunta si desea
   jugar de nuevo, de tal forma que si la respuesta es afirmativa, se inica
   de nuevo el juego.
   
   Entradas: 
    Un número cualquiera que introduce el usuario (numero).
    
   Salidas:
    Un mensaje que nos dice si el número que hemos introducido está por enicma
    o por debajo del número aleatorio, o si hemos acertado.
    
   
   El programa lo he llevado a cabo de la siguiente forma: 
   En primer lugar, he establecido una estructura repetitiva de tipo while que 
   se ejecutará al menos una vez debido a que a la condicón que le he puesto le
   he asignado el valor de verdad, mediante una variable tipo bool declarada 
   previamente. Una vez dentro del while, he introducido una serie de 
   instrucciones para la generación del número aleatorio a adivinar, y que he 
   copiado del guiónde prácticas, dicho sea de paso. Una vez generado dicho 
   número, he establecido una estructura repetitiva de tipo post-test para 
   filtrar el dato numérico que introduzca el jugador. Una vez filtrado el 
   número, he establecido una esturctura cíclica de tipo while dentro de la cual
   he establecido una serie de estructuras condicionales dobles acerca de las
   características del número introducido. La condición que he establecido
   para entrar en el ciclo while la he definido mediante una variable tipo bool.
   Dicha condición es que el número introducido no coincida con el número 
   originado aleatoriamente ni con el terminador (el terminador es un número
   (al que le he asignado el valor -1), tal que sea cual sea el momento en 
   el que el usuario lo introduzca, se finaliza el juego). Por otro lado, si
   se cumple la condición impuesta se procede a analizar las características
   del número introducido, mediante una estructura condicional doble, 
   determinando así si dicho número está por encima o por debajo del número
   secreto.
   Si no se cumple la condición del while será, como ya he dicho, que el usuario
   ha acertado el número o que ha introducido el terminador. De esta forma, no
   se ejecuta el while y se actualiza el contador de intentos que me dirá 
   cuántos intentos he realizado para acertar el número y se muestra en pantalla
   un mensaje en función de lo que haya ocurrido: si ha acertado, muestra un
   mensaje felicitando, y si ha introducido el terminador, muestra un mensaje
   de fin del juego. En el caso de que el jugador ,quiera volver a jugar, he
   establecido una estructura condicional doble relativa la respuesta del
   jugador; si quiere jugar, entonces deberá introducir la letra 's' de tal
   forma que se imprime un salto de línea y se vuelve a empezar el ciclo, 
   generándose otro número aleatorio con el que jugar. Si la respuesta es no, 
   el usuario deberá introducir 'n', y se imprime un mensaje de despedida.
                         
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaración de datos
	
	int numero = 0;
	
	const int TERMINADOR = -1;
	const int MIN = 1;
	const int MAX = 100;
	int intentos = 1;
	bool continua_jugando = true;
	char seguir_jugando;
		
	const int NUM_VALORES = MAX - MIN + 1; // Número de valores posibles
	                 
	int num_secreto = 0;  // Número aleatorio a generar: "incógnita"
	
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
		srand (time(&t));   // Se inicia el generador de números aleatorios 
		                    // con el reloj del sistema
		                	          
	   // Generación del número aleatorio (MIN <= num_secreto <= MAX)
	   
	    num_secreto = (rand() % NUM_VALORES) + MIN;   
	    
	    // A continuación filtro el número que introduce el usuario
	    
	    	do{
	    
				cout << endl;
				cout << "Introduzca un numero entre 1 y 100, o introduzca -1 "
					 <<	"para terminar la partida: ";
				cin  >> numero;
				
			}while(((numero < MIN) || (numero > MAX)) && (numero !=TERMINADOR));
			
			
		
		// Declaro una variable tipo bool para determinar la condición del
		// ciclo que voy a establecer, que será del tipo pre-test
		
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
			
			else    // Que el usuario acierte el número (numero == num_secreto)
			{  
			
					cout << endl;
					cout << "GENIAL, ¡HA ADIVINADO EL NUMERO!";
					cout << " ERA EL " << num_secreto;
					cout << ". LO HA HECHO EN " << intentos << " intentos";
					cout << endl;
					 
		    }
		    
		    // Si el usuario quiere seguir jugando
		    
		    cout << endl;
		    cout << "¿Desea jugar de nuevo? Si la respuesta es si, pulse 's' "
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
