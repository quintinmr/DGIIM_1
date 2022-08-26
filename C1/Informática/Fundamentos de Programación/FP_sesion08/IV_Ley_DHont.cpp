/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que calcula los esca�os que corresponen a una serie de partidos
   que se presentan a unas elecciones en las que se han de repartir una serie
   de esca�os, en funci�n de los votos obtenidos en dichas elecciones. 
   Para calcular los esca�os recibidos, se hace uso de la Ley D'Hont:
   
   La asignaci�n de los esca�os se hace a trav�s de un proceso iterativo en 
   el que en cada iteraci�n se asigna un esca�o a un partido y as� hasta llegar 
   al n�mero total de esca�os a repartir. Se calculan cocientes sucesivos para 
   cada partido pol�tico. La f�rmula de los cocientes es: 
   
                         cociente = Vi/(Si + 1) 
                         
   donde Vi es el n�mero total de votos obtenidos por el partido i y Si es 
   el n�mero de esca�os que ha obtenido hasta el momento el partido i.
   El n�mero de votos recibidos por cada partido se divide sucesivamente por 
   cada uno de los divisores, desde 1 hasta el n�mero total de esca�os a 
   repartir. La asignaci�n de cada esca�o se determina hallando el m�ximo de 
   los cocientes y asignando a cada uno un esca�o, hasta que estos se agoten.

   Entradas: 
    El n�mero de partidos que participan en las elecciones (numero_partidos).
    El n�mero de esca�os a repartir (numero_escagnos_a_repartir).
    El n�mero de votos recibidos por cada partido (partidos.votos).
    
   Salidas:
    El n�mero de esca�os recibidos por cada uno de los partidos
    (partidos.escagnos).
     
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <string>
using namespace std;  
 
/******************************************************************************/
/******************************************************************************/

	// Defino un registro, Partido constitu�do por cuatro campos que son
	// la sigla del partido, el n�mero de votos recibidos y por �ltimo
	// el n�mero de esca�os conseguidos.

struct Partido {
	
	
	string sigla; 		// "Nombre" del partido
	int votos; 			// Votos recibidos
	int escagnos; 		// Esca�os conseguidos
	
};

/******************************************************************************/

int main()
{
	
	// Declaraci�n de datos
	
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
	     
	     
	// Defino un vector tipo Partido con un n�mero m�ximo de componentes igual
	// al n�mero de partidos que se hayan presentado a las elecciones.
	
	Partido partidos[numero_partidos];
	
	/* A continuaci�n, establezco un ciclo for para continuar con la entrada
	de datos. Mientras que el �ndice variando no llegue al n�mero de partidos
	que se han presentado a las elecciones, se va a ir pidiendo el n�mero de
	votos que ha obtenido cada partido.
	*/
	
	for (int i = 0; i < numero_partidos; i = i + 1){
		
		cout << "Partido numero " << i+1 << " y sigla " ;
		cin  >> partidos[i].sigla;
		
		cout << endl;
		
		cout << "Numero de votos obtenido: ";
		cin  >> partidos[i].votos;
		
		partidos[i].escagnos = 0;  // Se inicializa el n�mero de esca�os 
		                           // conseguidos a cero. 
		
	}
	
	// C�lculos
	
	int maximo = 0;
	int posicion_maxima;
	int cociente;
	
	// A continuaci�n se procede a comparar los cocientes.
	
	/* Para ello he establecido un anidamiento de estructuras c�clicas de tipo
	   for. El primero entrar� en bucle s� y solo s� el �ndice variando 
	   no llega al n�mero de esca�os a repartir, y el otro cuando no 
	   llegue al n�mero de partidos que participan. Una vez que se llega al
	   n�mero de partidos que participan se cierra el bucle y se actualizan
	   los esca�os conseguidos. Dentro de este �ltimo ciclo for, he establecido
	   una estructura condicional simple de tal forma que si se cumple que
	   el cociente calculado previamente es mayor que el cociente m�ximo al
	   que se le ha asignado el valor cero porque incialemente vale cero, 
	   entonces se le asigna a dicho m�ximo el valor del cociente calculado
	   y a la posici�n en la que se alcanza el m�ximo se le asocia el valor del
	   �ndice variando.
	*/   
	
	
		
	for (int i = 0; i < numero_escagnos_a_repartir; i = i + 1){
		
		for (int p = 0; p < numero_partidos; p = p +1){
			
			/* Cociente entre el n�mero total de votos obtenidos por el partido
			   p y el n�mero de esca�os que ha obtenido hasta el momento el 
			   partido p.
			*/    
			
			cociente = ((partidos[p].votos) / (partidos[p].escagnos +1));
			
			if (cociente > maximo)  
			{
				maximo = cociente; 
				
				posicion_maxima = p;
				
			}
			
		}
		
		partidos[posicion_maxima].escagnos++;   // Se aumentan los esca�os del
		                                        // partido que tenga mayor
		                                        // cociente.
		maximo = 0;
	}
	
	// Salida de datos
	
	cout << "El reparto de esca�os queda de la siguiente forma: ";
	
	for(int q = 0; q < numero_partidos; q = q +1){
		
		cout << endl;
		cout << " El partido " << partidos[q].sigla << " : " ;
		cout << partidos[q].escagnos << " ";
	}
	
/******************************************************************************/
	return 0;
}
	
	
	
	
	
	
	
	
	
