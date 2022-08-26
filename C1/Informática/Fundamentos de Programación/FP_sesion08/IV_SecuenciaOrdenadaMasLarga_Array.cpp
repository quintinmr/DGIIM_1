/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que calcula cu�ndo se produjo la mayor secuencia de d�as
   consecutivos con temperaturas crecientes. Para ello, el programa lee una
   secuencia de n�mero reales que representan temperaturas, hasta llegar a -1 o
   hasta el momento en el que se introduzca una temperatura fuera de rango
   y se calcula una subsecuencia ordenada de temperaturas (de menor a mayor 
   longitud) de tal forma que el programa nos dice la posici�n en la que 
   comienza dicha subsecuencia y su longitud.
   
   Entradas: 
    Una secuencia de temperaturas determinada.
    
   Salidas:
    La mayor secuencia de d�as consecutivos con temperaturas crecientes.
    La posici�n donde comienza la subsecuencia y longitud de dicha
	subsecuencia..
	
   En este programa he procedido de la siguiente forma:
   En primer lugar, he establecido un intervalo de temperaturas constante 
   (he declarado un m�nimo y un m�ximo como constantes). A continuaci�n, he 
   declarado una serie de variables y he definido un vector en el que se 
   guardar�n todas las temperaturas que el usuario introduzca y que tiene 
   como n�mero m�ximo de componentes 100 temperaturas.
   A continuaci�n he establecido un ciclo while que se ejecutar� s� y solo s� 
   las temperatura introducidas en primer lugar cumplen la condici�n de que 
   est�n dentro del rango establecido (dicho rango se le especifica al usuario 
   al principio del programa), y que no sea el TERMINADOR (-1). 
   Dentro del bucle se guardan todas las temperaturas conforme se van leyendo
   en el vector anteriormente definido y se actualiza el n�mero de temperaturas
   le�das, de tal forma que si este n�mero no excede el n�mero m�ximo de 
   componentes del vector, se contin�a con la lectura.
   
   Una vez hecho esto, se pasa a otro ciclo while, dentro del cual, se comprueba
   si la temperatura anterior es menor que la temperatura actual. Si es as�
   la posici�n final se actualiza. En el caso contrario, se hace los calculos
   y las asignaciones pertinentes entre varialbes de longitud y posici�n (ver
   apartado de c�lculos). Todo esto se va repitiendo y se van actualizando los
   contadores de posici�n y longitud hasta que se alcanza el n�mero m�ximo de
   temperaturas, se introduce una fuera de rango, o se introduce el terminador. 
                     
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
	const int TERMINADOR   = -1;
	
	// Datos para el apartado de c�lculos del programa y datos de salida
	
    int posicion_inicial = 0;
    int posicion_final = 0;
    int longitud_sec;
    
    int posicion_i_maxima;
    int posicion_f_maxima;
    int longitud_maxima;
    
    const int MAX_DATOS = 100;
    double temperaturas[MAX_DATOS];
    
    int temperaturas_leidas = 0;
    
    
    // Datos de salida: longitud_maxima y posicion_maxima
    
/******************************************************************************/  
	 
	// Entrada de datos 
	   
	bool continua_leyendo = true; 
	double temperatura; 
	
	cout << "Introduzca una serie de temperatura que deben estar entre -40" 
	     << " y 60 grados centrigrados, ambos inclusive): ";
	cout << endl;     
	cin >> temperatura;
	
	while ((((temperatura >= MIN_RANGO) && 
	       (temperatura <= MAX_RANGO))) && (continua_leyendo)&& 
		   (temperatura != TERMINADOR) ){

		temperaturas[temperaturas_leidas] = temperatura;
		
		temperaturas_leidas++;

		if (temperaturas_leidas == MAX_DATOS) 
		
			continua_leyendo = false;
			
		else 
			cin >> temperatura;
			
	}
	

	int t = 0;
	
	while ( t < temperaturas_leidas){
		
		/* Defino una variable tipo bool que devolver� el valor de verdad si
		   la temperatura anterior es menor que la temperatura actual (orden
		   creciente)
		*/
		
		bool orden_creciente = temperaturas[t] < temperaturas[t+1];  
		
		if (orden_creciente){
			
			posicion_final = (t + 1);
			
		}
		
		else
	    {
	    	
	    	/* Calculo la longitud de la secuencia de temperaturas igual que se
	    	   calcula cualquier longitud o distancia; restando la posici�n
	    	   final menos la inicial.
	    	   De tal forma que si dicha longitud es mayor que la longitud de
	    	   la secuencia m�xima de temperaturas creciente consecutivas, se
	    	   hacen una serie de asociaciones entre la posici�n inicial de la
	    	   cadena y la posici�n inicial de la subsecuencia m�xima y lo mismo
	    	   con la posici�n final, de tal forma que, igual que hemos 
	    	   procedido al principio, la longitud de la mayor subsecuencia de
	    	   temperaturas crecientes en d�as consectivos ser� la mera 
	    	   diferencia entre la posici�n inicial y la final, pero sum�ndole
	    	   la unidad pues la posici�n inicial es cero (dar�a una longitud
	    	   menor que la que verdaderamente tiene).
	    	*/
			   
	    	longitud_sec = (posicion_final - posicion_inicial);
	    	
	    	if (longitud_sec > longitud_maxima){
	    		
	    		posicion_i_maxima = posicion_inicial;
	    		posicion_f_maxima = posicion_final;
	    		
	    		
	    		longitud_maxima = (posicion_f_maxima - 
				                   posicion_i_maxima + 1 );
				                           
			}
			
			posicion_inicial = (t + 1);
			
		}
	
	
		t++;
	}
		

	// Salida de datos
	
	
	cout << endl;
	cout << "La mayor secuencia de d�as consecutivos con temperaturas "
	     << "crecientes es: ";
	     
	/* Aqu�, para mostrar los elementos de la secuencia m�xima, utilizo un
	   cilo for, y har� adem�s uso del vector en el que se han guardado todas
	   las temperaturas.
	*/ 
	
	for (int j = posicion_i_maxima; j <= posicion_f_maxima; j++){
	
		cout << temperaturas[j] << " ";
	}
	
	cout << endl;	       
	cout << "La mayor secuencia de d�as consecutivos con temperaturas "
	     << "crecientes, comienza en la posicion: " << posicion_i_maxima;
	cout << endl;
	cout << "Y la longitud de dicha secuencia es: " << longitud_maxima;
	cout << endl;


	
/******************************************************************************/
	return 0;
}
