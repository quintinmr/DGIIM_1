/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee las dimensiones de una matriz cualquiera, y todos sus 
	elementos y calcula, de entre los m�nimos de cada una de la matriz, el 
	mayor de todos ellos.

   Entradas: 
    Dimensiones de la matriz (filas x columnas)
    Elementos de la matriz
    
   Salidas:
    Mayor m�nimo por filas.
    Posicion de dicho m�nimo.
    
     
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <iomanip>
using namespace std;  
 
/******************************************************************************/
 
	/* En primer lugar, definir� una funci�n de tipo bool con el objetivo de
	   determinar si el n�mero introducido es un n�mero entero o no, y la 
	   cual usar� en la funci�n LeeEntero que vendr� a continuaci�n.
	   Esta funci�n me devuelve el valor true si la cadena de caracteres 
	   introducida es un n�mero entero.
	*/
	   
bool EsEntero (string cosa){
	
	/* Declaro una variable contadora de la posici�n de cada uno de los
	   elementos del string; va a ser un �ndice que va recorriendo todos
	   los elementos de la cadena en busca de datos num�ricos.
	*/
	
	int indice = 0;           // La posici�n inicial es cero
	char caracter_sub_indice; // Cualquier elemento de la cadena de caracteres

	
	if((cosa.at(0) == '-')|| (cosa.at(0) == '+')){     
	                            
		
		indice = (indice + 1);  // Acutalizo el indice variando
	
	}
	
	/* A continuaci�n establezco un ciclo while, el cual se ejecutar� s� y solo
	   s�, se cumple que el �ndice variando ha alcanzado una posici�n menor 
	   que la posici�n del �ltimo car�cter, en otras palabras, que el �ndice
	   sea menor que la propia lontitud del string.
	   Parte de dicha condici�n viene dada por una variable tipo bool que he
	   definido, y a la cual he asginado el valor true, de tal forma que se 
	   entrar� al menos una vez, pero claro, s� y solo s� se cumple la otra
	   condici�n.
	*/
	
	bool entero_ok = true;
	   
	while(entero_ok && indice < cosa.length()){
		
		 caracter_sub_indice = cosa.at(indice);
		 
		// Actualizo la bandera
		
		/* El caracter, para que sea de car�cter num�rico, ha de ocupar en la
		   p�gina de c�digos ASCII, una posici�n entre la del 0 ('0') y la 
		   del 9 ('9'). Por eso, para que el caracter de la posici�n que indique
		   el �ndice sea un n�mero, ha de cumplir que est� entre 0 y 9. Puede 
		   darse el caso de que entre los caracteres halla espacios. Estos
		   se obvian y se incluyen dentro de la condici�n de que la cadena
		   de caracteres sea un n�mer entero (luego en la siguiente funci�n
		   se emplear� la funci�n stoid que pasa un string a un entero).
		*/   
		
		entero_ok = (caracter_sub_indice >= '0' && caracter_sub_indice <='9')||
					caracter_sub_indice == ' ';
		
		indice = (indice + 1);   // Actualizo el �ndice.
		
	}
	
	return entero_ok; 	
}

int LeeEntero (string titulo){
	
	string numero;   // Cadena a introducir por el usuario
	
	bool cadena_ok;  /* Declaro una variable tipo bool que emplear� en la 
	                    condici�n de el ciclo post-test que he establecido
	                    para la determinaci�n de s� la cadena introducida
	                    es un entero o no.
	                 */   
	
	
	/* En este ciclo do while se comprueba si la cadena constituye un entero.
	   Luego, esta estructura entrar� en bucle s� y solo s� la cadena de 
	   caracteres no es un n�mero entero, y cada vez que esto ocurra se volver�
	   a pedir que introduzca un n�mero entero.
	   Para comprobarlo, hago un llamamiento a la funci�n tipo bool anterior
	   que estaba dirigida a la determinaci�n de s� la cadena constituye un
	   entero o no. De tal forma que se dicha funci�n devuelve el valor true
	   la funci�n LeeEntero, termina de ejecutarse, y se pasa a la siguiente
	   lectura.
	*/
	   
	do{
		
		cout<< titulo;
		cin >> numero;
		
		cadena_ok = EsEntero(numero);
		
	}while(!cadena_ok);
	

 	/* La funci�n devuelve la cadena introducida, convertida en int mediante
 	   la funci�n stoi.
 	*/
	    
	return stoi(numero);
}


/******************************************************************************/

	/* Esta funci�n lee un entero que se encuentre dentro del rango establecido
	   Si no est� dentro o no es un entero, se sigue vuelve a pedir lo mismo.
	   Si se cumplen todas las condiciones se pasa a la siguiente lectura.
	*/
	   
int LeeEnteroEnRango (string titulo, int menor, int mayor)
{
	int numero_entero;
	
	/* He establecido un ciclo do while, en el que se comprueba , en primer 
	   lugar que la cadena de caracteres introducida sea un n�mero entero. 
	   Si esto se cumple, la primera funci�n me devuelve la cadena convertida
	   a entero y se pasa a evaluar si dicho n�mero est� dentro del rango
	   establecido (condici�n del ciclo do-while). Si la cadena de caracteres
	   no fuera un n�mero entero, se vuelve a pedir que se introduzca un n�mero
	   entero.
	*/   
	 
	do {
		
		numero_entero = LeeEntero(titulo);	
		
	} while (numero_entero < menor || numero_entero > mayor);
	
	
	return numero_entero;	
} 

/******************************************************************************/
  
struct Elementomatriz {

	int fila;
	int columna;

};

/******************************************************************************/

int main ()
{
	
	// Declaraci�n de datos
	
	// Datos de entrada
	
	int filas;
	int columnas;
	
	// Declaraci�n de constantes
	
	const int NUM_FILAS    = 50;
	const int NUM_COLUMNAS = 50;
	
	// Declaraci�n de la matriz
	
	int matriz[NUM_FILAS][NUM_COLUMNAS];
	
	
	
/******************************************************************************/

	// Entrada de datos
	
	filas = LeeEnteroEnRango("N�mero de filas de la matriz 1 [1-"
		                        "50]: ", 1, NUM_FILAS);
		                         
	columnas = LeeEnteroEnRango ("N�mero de columnas de la matriz 1 [1-"
		                             "50]: ", 1, NUM_COLUMNAS);                        


	// Lectura de los datos de la matriz
	
	for (int f = 0; f < filas; f++)
	
		for (int c = 0; c < columnas; c++) {
		
			cout << "Elemento (" << f << ", " << c << ") = ";
			cin >> matriz [f][c];
		}
		
		
	cout << endl;
	cout << "La matriz ";
	cout << "(" <<filas << "x"<< columnas << "), es la siguiente: "<< endl;	
	cout << endl;

	for (int fila = 0; fila < filas; fila++){
		
		for (int col = 0; col < columnas; col++) 
		
			cout << setw(3) << matriz [fila][col];
			
		cout << endl;
	}
	cout << endl;
	

	double minimo_en_filas [filas];
	
	for (int f=0; f < filas; f++)
	{
		minimo_en_filas[f] = matriz[f][0] ;
		
		for (int c=1; c < columnas; c++)
		{
			if (matriz[f][c] < minimo_en_filas[f])
				minimo_en_filas[f] = matriz[f][c] ;
		}
	}
	
	double maximo_minimo_en_filas = minimo_en_filas[0] ;
	
	for (int f = 1; f < filas; f++)
	{
		if (minimo_en_filas[f]> maximo_minimo_en_filas)
			maximo_minimo_en_filas = minimo_en_filas[f] ;
	}
	
	Elementomatriz posicion_maximo_minimo;
	
	for (int f = 0; f < filas; f++)
	{
		for (int c = 0; c < columnas; c++)
		{
			if (matriz[f][c] == maximo_minimo_en_filas)
			{
				posicion_maximo_minimo.fila = f ;
				posicion_maximo_minimo.columna = c ;
			}
		}
	}

	
	// Salida de datos
	
	cout << "El mayor de los minimos de cada una de las filas de la matriz, que"
		 << " son " ;
		 
		for (int f = 0; f < filas; f++){
		
			cout << minimo_en_filas[f] ;
			
			if (f < filas-1)
			
				cout << ", " ;
		}
		
	cout << " es " << maximo_minimo_en_filas;
	cout << endl;
	cout << "Se encuentra en la posicion (" << posicion_maximo_minimo.fila 
		 << "," << posicion_maximo_minimo.columna <<")";
	
/******************************************************************************/
	return 0;
}
