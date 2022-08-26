/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee un número indeterminado de caracteres (termina de leer
   cuando se introduce el caracter * ), muestra el número total de apariciones
   de cada letra, indica cuantos de los caracteres introducidos son letras
   cuántos son separadores, y cuántos son otros caracteres.
   A continuación se indicará qué letras no han aparecido ni una vez, y cuáles 
   son dichas letras, y finalmente indicará qué letras son las que han 
   aparecido con más y menos frecuencia y el número de veces que han aparecido.

   Entradas: 
    Un número indeterminado de caracteres.
   
   Salidas:
    Número de caracteres que se introducen.
    Número total de apariciones de cada letra.
    Número de letras.
    Número de separadores.
    Número de otros caracteresque aparezcan.
    Letras más frecuentes y menos frecuentes.
    Número de letras más frecuentes.
    Número de letras menos freucentes
    Letras que no han aparecido.
	Número de letras que no han aparecido.
     
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;  
 
/******************************************************************************/
/******************************************************************************/

int main()
{
	
	
	const int MAXIMO = 2500000;     // Tamaño máximo del vector
	char texto [MAXIMO];             // Vector texto
	const char TERMINADOR = '*';     // Se finaliza la lectura cuando se 
	                                 // introduce *
	const int LETRAS = 'Z' - 'A' + 1;;                                 
	int letras [LETRAS];                 // Vector contador
	
	string letras_que_no_aparecen;
	char letra;
	
	// Declaración e inicialización de los contadores
	
	int contador_espacios = 0;
	int contador_letras = 0;
	int contador_otros_caracteres = 0;
	int contador_letras_que_no_aparecen = 0;
	int contador_total_caracteres = 0;
	
	
	
	// Entrada de datos
	
	cout << "Introduzca el texto que desea analizar. ";
	cout << "Recuerde que para finalizar la lectura es necesario que pulse * ";
	cout << endl;
	
	
	/* A continuación establezco un ciclo for al que se entrará al menos una
	   vez y en el que se evaluzarán una serie de condiciones acerca del
	   contenido del texto.
	*/ 
	
	bool los_caracteres_ok = true; // Por esto se accede al menos una vez
	
	for (int i = 0; los_caracteres_ok; i = i + 1 ){ 
	
		/* Como interesa leer un carácter separador no se puede emplear 
		   cin >> texto[i] , sino texto[i] = cin.get(). 
		   Cada vez que se ejecuta cin.get() se lee un carácter (incluido 
		   el espacio en blanco, tabulador ó salto de línea) desde la entrada 
		   de datos por defecto. 
		*/
	
		// Cada carácter se guarda en un hueco del vector texto[i]
		// Con este ciclo for se va a ir leyendo hasta que se introduzca el
		// terminador (*)
		
		texto[i] = cin.get();
		
		
		if (texto[i] != TERMINADOR){
			
			// Mientras que no se introduzca el terminador se va actualizando
			// el contador de caracteres totales.
			
			contador_total_caracteres = (contador_total_caracteres + 1);
			
			
			if ((((texto[i] >= 'a') && (texto[i] <= 'z')) || (texto[i] == ' '))
				||  ((texto[i] >= 'A') && (texto[i] <= 'Z'))){
					
				if (((texto[i] >= 'a') && (texto[i] <= 'z')) || 
				   ((texto[i] >= 'A') && (texto[i] <= 'Z'))){
					
					// Si el caracter en la posición i es una letra se
					// actualiza el contador de las letras.
					contador_letras = (contador_letras + 1);
					
					// Para el caso de que las letras puedan ser mayúsculas
					// empleo la función toupper
					
					texto[i] = toupper(texto[i]);
					 
					
					for (int q = 0; q < LETRAS; q = q + 1){
						
						if (texto[i] == ('A' + q)){
							
							letras[q] = (letras[q] + 1);
							
						}
						
					} // Fin del ciclo for 2
					
				} // Fin del if de condición que sea letra
				
				else
				{
					
					contador_espacios = (contador_espacios + 1);
					
				}
				
			} // Fin del if de condición que sea letra o espacio
			
			else
			{
				
				contador_otros_caracteres = (contador_otros_caracteres + 1);
				
			}
			
		} // Fin del if inicial de condición que el texto introducido no sea *
		
	
	
		else
		{
		
			// En este caso la bandera toma el valor de falso, porque se ha
	    	// introducido el TERMINADOR (*)
	    
	    	los_caracteres_ok = false;
	    
		}
	
	}
	
	/* Finalmente para contabilizar las LETRAS que no han aparecido en el 
	   texto, es necesario establecer otro ciclo for de índice contador 
	   variando y de valor inicial cero, y cuya condición es la de no revasar
	   el número de componentes del vector letras[LETRAS].
	*/  
	
	for (int n = 0; n < LETRAS ; n = n + 1){
		
		/* Debe darse el caso de que la posición de los caracteres en la 
		   posición que indique el índice n sea cero
		*/
		
	   if (letras[n] == 0){  
	
			 letra = 'A' + n;
		
		// Variable en la que se guardarán las letras que no han aparecido.
	
		letras_que_no_aparecen = letras_que_no_aparecen + letra + ' ';
		
		// Actualizo el contador de letras que no han aparecido.
		
		contador_letras_que_no_aparecen = (contador_letras_que_no_aparecen + 1);
		
		} // Fin del if de condición que la posición de los caracteres en la 
		  // posición que indique el índice n sea cero.
		
	}
	
	// A continuación procedo a la determinación de la letra más y menos 
	// frecuente
	
	int menos_frecuente = 0;
	int mas_frecuente = 0;
	
	for(int i = 0; i < LETRAS; i++) {
		
		if	(letras[menos_frecuente] > letras[i] && letras[i] != 0){
			
			menos_frecuente = i;
			
		}
			
		if	(letras[mas_frecuente]<letras[i]){
			
			mas_frecuente = i;
			
		}
	}
	
	// Convierto a dato de tipo char las letras más y menos frecuente ya 
    // determinadas
	
	char more_frecuent;  // Será aquella que se encuentre a una posición de la 
	                     // A determinada por mas_frecuente
	char less_frecuent;
	
	more_frecuent = mas_frecuente + 'A';
	
	less_frecuent = menos_frecuente + 'A';
	
	
	// Salida de datos
	
	cout << endl;
	cout << "El numero total de caracteres que se han leido es: " 
	     << contador_total_caracteres;
	cout << endl;     
	cout << "En este texto han aparecido un total de " << contador_letras 
	     << " letras." << endl;
	     
	cout << "En el texto aparecen las siguientes letras: " << endl;
	
	/* Establezco este ciclo for para que se muestre en pantalla las veces que
	   cada letra del abecedario aparece en el texto introducido. 
	*/   
	
	for (int k = 0; k < LETRAS; k++) {
		
		if (letras[k] != 0) {
			
			letra = 'A' + k;
			
			cout << letra << ": " << setw(6) << letras[k] << " veces" << endl;
		}
	}
	
	cout << endl;
	
	cout << "Han aparecido un total de " << contador_espacios
	     << " espacios." ;
	cout << endl;     
	cout << "Otros caracteres: " << contador_otros_caracteres;
	cout << endl;
	cout <<	"El numero de letras que no han aparecido es: "
	     << contador_letras_que_no_aparecen << " y son: "
	     << letras_que_no_aparecen;
	cout << endl;     
	cout << "La letra mas frecuente es: " << more_frecuent
	     << " Aparece "<< letras[mas_frecuente] << " veces." ;
	cout << endl;     
	cout << "La letra menos frecuente es: " << less_frecuent 
	     << " Aparece "<< letras[menos_frecuente] << " veces." ;   
	     
	  
/******************************************************************************/
	return 0;
}
		
		 
		
		 
				
				
		
		
	
			
	
	
