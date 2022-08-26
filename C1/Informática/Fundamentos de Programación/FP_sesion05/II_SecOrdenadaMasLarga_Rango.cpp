/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que calcula cuándo se produjo la mayor secuencia de días
   consecutivos con temperaturas crecientes. Para ello, el programa lee una
   secuencia de número reales que representan temperaturas, hasta llegar a -1
   y se calcula una subsecuencia ordenada de números (de menor a mayor longitud)
   de tal forma que el programa nos dice la posición en la que comienza dicha
   subsecuencia y su longitud.
   
   Entradas: 
    Una secuencia de temperaturas hasta llegar a -1 (temperatura1, temperatura2,
    temperatura3, temperatura
    
   Salidas:
    La mayor secuencia de días consecutivos con temperaturas crecientes.
    La posición donde comienza la subsecuencia (posicion) y longitud de dicha
	subsecuencia (subsecuencia).
	
   En este programa he procedido de la siguiente forma:
   En primer lugar, he establecido un intervalo de temperaturas constante 
   (he declarado un mínimo y un máximo como constantes). A continuación, he
   establecido un ciclo while al que se entrará sí y solo sí la temperatura
   introducida en primer lugar cumple la condición de que esté dentro del 
   rango establecido (dicho rango se le especifica al usuario al principio del
   programa). Una vez dentro del bucle le he asignado a la variable 
   temperatura_anterior el valor de la primera temperatura introducida, pues
   a continuación se pide otra temperatura, que por consiguiente será posterior
   a la inicial, con lo cual la inicial será la anterior de esa temperatura 
   nueva. Si dicha temeratura cumple la condición impuesta por el siguiente
   ciclo while (que sea mayor que la anterior y menor o igual que el máximo del
   rango), entonces se actualizan los contadores de longitud y posición de tal
   forma que se irá repitiendo el ciclo y se ira acumulando longitud y posición
   hasta que el usuario introduzca un valor de temperatura que no cumpla la 
   condición del while. De esta forma, se cierra el bucle y se actualiza el 
   contador de posición y se pasa a una estructura condicional simple que 
   establece que si la longitud de la secuencia de temperaturas consecutivas 
   crecientes es menor que la longitud de la cadena inicial, se le asigna a la
   variable de la longitud de las temperaturas crecientes, el valor de la
   variable de la longitud inicial (una variable contadora) y a la variable
   de la posición donde comienza la secuencia de temperaturas crecientes
   se le asocia el valor acumulado de la variable contadora posición y 
   se le resta la longitud de la cadena inicial. De esta forma obtengo, 
   por un lado, la longitud de la secuencia de temperaturas crecientes 
   consecutivas y la posición en la que comienza dicha secuencia.
                     
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaración de datos
	
	
	const double MIN_RANGO = -40;
	const double MAX_RANGO = 60;
	
	// Datos para el apartado de cálculos del programa y datos de salida
	
	int longitud_sec = 1;
    int longitud_maxima  = 0;  
    int posicion_inicial;
    int posicion = 1;
    
    double temperatura_actual;
    double temperatura_anterior;
    
    const int MAX_DATOS = 100;
    
    double temperaturas[MAX_DATOS]
    
    // Datos de salida: longitud_maxima y posicion_maxima
    
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca la temperatura del primer dia (debe estar entre -40" 
	     << " y 60, ambos inclusive): ";
    cin  >> temperatura_actual;
	
	                     
    while((temperatura_actual >= MIN_RANGO) && 
	      (temperatura_actual <= MAX_RANGO)){
    	
    	temperatura_anterior = temperatura_actual;
    	
    	cout << "Introduzca la siguiente temperatura: ";
    	cin  >> temperatura_actual;
    	
    	/* A continuación se ejecutará este ciclo while sí y solo sí la
    	   las temperaturas van en orden creciente y sean menores o iguales
    	   que el máximo del intervalo
    	*/  
    	while ((temperatura_anterior <= temperatura_actual) && 
		       (temperatura_actual <= MAX_RANGO)){ 
	
	    longitud_sec = longitud_sec + 1;
	    posicion     = posicion + 1;
		temperatura_anterior = temperatura_actual;
		
		cout << "Introduzca la siguiente temperatura: ";
		cin  >> temperatura_actual;
		
		}
		
		posicion = posicion + 1;
		
		if (longitud_maxima < longitud_sec){
			
			longitud_maxima  = longitud_sec;
			posicion_inicial = posicion - longitud_maxima;
			
		}
		
		longitud_sec = 1;
		
	}
	
	// Salida de datos
	
	
	cout << endl;
	cout << "La mayor secuencia de días consecutivos con temperaturas "
	     << "crecientes, comienza en la posicion: " << posicion_inicial;
	cout << endl;
	cout << "Y la longitud de dicha secuencia es: " << longitud_maxima;
	cout << endl;


	
/******************************************************************************/
	return 0;
} 
