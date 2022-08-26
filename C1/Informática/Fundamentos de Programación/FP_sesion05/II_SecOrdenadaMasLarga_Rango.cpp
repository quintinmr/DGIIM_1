/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que calcula cu�ndo se produjo la mayor secuencia de d�as
   consecutivos con temperaturas crecientes. Para ello, el programa lee una
   secuencia de n�mero reales que representan temperaturas, hasta llegar a -1
   y se calcula una subsecuencia ordenada de n�meros (de menor a mayor longitud)
   de tal forma que el programa nos dice la posici�n en la que comienza dicha
   subsecuencia y su longitud.
   
   Entradas: 
    Una secuencia de temperaturas hasta llegar a -1 (temperatura1, temperatura2,
    temperatura3, temperatura
    
   Salidas:
    La mayor secuencia de d�as consecutivos con temperaturas crecientes.
    La posici�n donde comienza la subsecuencia (posicion) y longitud de dicha
	subsecuencia (subsecuencia).
	
   En este programa he procedido de la siguiente forma:
   En primer lugar, he establecido un intervalo de temperaturas constante 
   (he declarado un m�nimo y un m�ximo como constantes). A continuaci�n, he
   establecido un ciclo while al que se entrar� s� y solo s� la temperatura
   introducida en primer lugar cumple la condici�n de que est� dentro del 
   rango establecido (dicho rango se le especifica al usuario al principio del
   programa). Una vez dentro del bucle le he asignado a la variable 
   temperatura_anterior el valor de la primera temperatura introducida, pues
   a continuaci�n se pide otra temperatura, que por consiguiente ser� posterior
   a la inicial, con lo cual la inicial ser� la anterior de esa temperatura 
   nueva. Si dicha temeratura cumple la condici�n impuesta por el siguiente
   ciclo while (que sea mayor que la anterior y menor o igual que el m�ximo del
   rango), entonces se actualizan los contadores de longitud y posici�n de tal
   forma que se ir� repitiendo el ciclo y se ira acumulando longitud y posici�n
   hasta que el usuario introduzca un valor de temperatura que no cumpla la 
   condici�n del while. De esta forma, se cierra el bucle y se actualiza el 
   contador de posici�n y se pasa a una estructura condicional simple que 
   establece que si la longitud de la secuencia de temperaturas consecutivas 
   crecientes es menor que la longitud de la cadena inicial, se le asigna a la
   variable de la longitud de las temperaturas crecientes, el valor de la
   variable de la longitud inicial (una variable contadora) y a la variable
   de la posici�n donde comienza la secuencia de temperaturas crecientes
   se le asocia el valor acumulado de la variable contadora posici�n y 
   se le resta la longitud de la cadena inicial. De esta forma obtengo, 
   por un lado, la longitud de la secuencia de temperaturas crecientes 
   consecutivas y la posici�n en la que comienza dicha secuencia.
                     
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaraci�n de datos
	
	
	const double MIN_RANGO = -40;
	const double MAX_RANGO = 60;
	
	// Datos para el apartado de c�lculos del programa y datos de salida
	
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
    	
    	/* A continuaci�n se ejecutar� este ciclo while s� y solo s� la
    	   las temperaturas van en orden creciente y sean menores o iguales
    	   que el m�ximo del intervalo
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
	cout << "La mayor secuencia de d�as consecutivos con temperaturas "
	     << "crecientes, comienza en la posicion: " << posicion_inicial;
	cout << endl;
	cout << "Y la longitud de dicha secuencia es: " << longitud_maxima;
	cout << endl;


	
/******************************************************************************/
	return 0;
} 
