/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que calcula los escaños que corresponen a una serie de partidos
   que se presentan a unas elecciones en las que se han de repartir una serie
   de escaños, en función de los votos obtenidos en dichas elecciones. 
   Para calcular los escaños recibidos, se hace uso de la Ley D'Hont:
   
   La asignación de los escaños se hace a través de un proceso iterativo en 
   el que en cada iteración se asigna un escaño a un partido y así hasta llegar 
   al número total de escaños a repartir. Se calculan cocientes sucesivos para 
   cada partido político. La fórmula de los cocientes es: 
   
                         cociente = Vi/(Si + 1) 
                         
   donde Vi es el número total de votos obtenidos por el partido i y Si es 
   el número de escaños que ha obtenido hasta el momento el partido i.
   El número de votos recibidos por cada partido se divide sucesivamente por 
   cada uno de los divisores, desde 1 hasta el número total de escaños a 
   repartir. La asignación de cada escaño se determina hallando el máximo de 
   los cocientes y asignando a cada uno un escaño, hasta que estos se agoten.

   Entradas: 
    El número de partidos que participan en las elecciones (numero_partidos).
    El número de escaños a repartir (numero_escagnos_a_repartir).
    El número de votos recibidos por cada partido (partidos.votos).
    
   Salidas:
    El número de escaños recibidos por cada uno de los partidos
    (partidos.escagnos).
     
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <string>
using namespace std;  
 
/******************************************************************************/
/******************************************************************************/

	// Defino un registro, Partido constituído por cuatro campos que son
	// la sigla del partido, el número de votos recibidos y por último
	// el número de escaños conseguidos.

struct Partido {
	
	
	string sigla; 		// "Nombre" del partido
	int votos; 			// Votos recibidos
	int escagnos; 		// Escaños conseguidos
	
};

/******************************************************************************/

int main()
{
	
	// Declaración de datos
	
	int numero_partidos;
	int numero_escagnos_a_repartir;
	
	// Entrada de datos
	
	do{
		
		cout << "Introduzca el numero de partidos que participan en las "
	     	 << "elecciones: ";
		cin  >> numero_partidos;
		
	}while (numero_partidos <= 0);
	
	do{
	
		cout << "Introduzca el numero de escagnos a repartir: ";
		cin  >> numero_escagnos_a_repartir;
		
	}while (numero_escagnos_a_repartir <= 0);
	     
	     
	// Defino un vector tipo Partido con un número máximo de componentes igual
	// al número de partidos que se hayan presentado a las elecciones.
	
	Partido partidos[numero_partidos];
	
	/* A continuación, establezco un ciclo for para continuar con la entrada
	de datos. Mientras que el índice variando no llegue al número de partidos
	que se han presentado a las elecciones, se va a ir pidiendo el número de
	votos que ha obtenido cada partido.
	*/
	
	for (int i = 0; i < numero_partidos; i = i + 1){
		
		cout << "Partido numero " << i+1 << " y sigla " ;
		cin  >> partidos[i].sigla;
		
		cout << endl;
		
		cout << "Numero de votos obtenido: ";
		cin  >> partidos[i].votos;
		
		partidos[i].escagnos = 0;  // Se inicializa el número de escaños 
		                           // conseguidos a cero. 
		
	}
	
	// Cálculos
	
	int maximo = 0;
	int posicion_maxima;
	int cociente;
	
	// A continuación se procede a comparar los cocientes.
	
	/* Para ello he establecido un anidamiento de estructuras cíclicas de tipo
	   for. El primero entrará en bucle sí y solo sí el índice variando 
	   no llega al número de escaños a repartir, y el otro cuando no 
	   llegue al número de partidos que participan. Una vez que se llega al
	   número de partidos que participan se cierra el bucle y se actualizan
	   los escaños conseguidos. Dentro de este último ciclo for, he establecido
	   una estructura condicional simple de tal forma que si se cumple que
	   el cociente calculado previamente es mayor que el cociente máximo al
	   que se le ha asignado el valor cero porque incialemente vale cero, 
	   entonces se le asigna a dicho máximo el valor del cociente calculado
	   y a la posición en la que se alcanza el máximo se le asocia el valor del
	   índice variando.
	*/   
	
	
		
	for (int i = 0; i < numero_escagnos_a_repartir; i = i + 1){
		
		for (int p = 0; p < numero_partidos; p = p +1){
			
			/* Cociente entre el número total de votos obtenidos por el partido
			   p y el número de escaños que ha obtenido hasta el momento el 
			   partido p.
			*/    
			
			cociente = ((partidos[p].votos) / (partidos[p].escagnos +1));
			
			if (cociente > maximo)  
			{
				maximo = cociente; 
				
				posicion_maxima = p;
				
			}
			
		}
		
		partidos[posicion_maxima].escagnos++;   // Se aumentan los escaños del
		                                        // partido que tenga mayor
		                                        // cociente.
		maximo = 0;
	}
	
	// Salida de datos
	
	cout << "El reparto de escaños queda de la siguiente forma: ";
	
	for(int q = 0; q < numero_partidos; q = q +1){
		
		cout << endl;
		cout << " El partido " << partidos[q].sigla << " : " ;
		cout << partidos[q].escagnos << " ";
	}
	
/******************************************************************************/
	return 0;
}
	
	
	
	
	
	
	
	
	
