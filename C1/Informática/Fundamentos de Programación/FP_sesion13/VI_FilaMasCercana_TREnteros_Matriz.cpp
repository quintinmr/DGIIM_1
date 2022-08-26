/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee los datos de una tabla rectangular (su dimensión y sus
   elementos, la muestra en pantalla (adicional) y calcula la fila que más 
   se asemeja a un vector dado, en función de las filas que se escojan para
   la comparación. Tanto el vector, como las filas que se desean analizar
   vienen dados mediante una secuencia de enteros. La determinación de cúal
   es la fila de la tabla que más se asemeja al vector consiste en calcular
   la distancia euclídea entre el vector y cada una de las filas a analizar,
   de tal forma que la que menos diste del vector, será la que más se asemeje
   a él y por tanto será la que se muestre en pantalla. Para ello, en la clase 
   TablaRectangular se ha implementado un método que devuelve un objeto de la
   clase SecuenciaEnteros (la fila más parecida), y al que le entran como 
   parámetros dos objetos de la clase SecuenciaEnteros: el vector y las filas
   a analizar.

*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;  
 
/******************************************************************************/
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class SecuenciaEnteros
{

private:

	static const int TAMANIO = 50; // Número de casillas disponibles
	int vector_privado[TAMANIO];

	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas

public:

	/***********************************************************************/
	// Constructor sin argumentos

	SecuenciaEnteros (void)
	{
		total_utilizados = 0;
	}
	
	/***********************************************************************/
	// Métodos de lectura (Get) de los datos individuales

	// Devuelve el número de casillas ocupadas
	int TotalUtilizados (void)
	{
		return (total_utilizados);
	}

	// Devuelve el número de casillas disponibles
	int Capacidad (void)
	{
		return (TAMANIO);
	}

	/***********************************************************************/
	// Añade un elemento al vector.
	// Recibe: nuevo, el elemento que se va a añadir.
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adición se realiza si hay espacio para el nuevo elemento.
	// 		El nuevo elemento se coloca al final del vector.
	// 		Si no hay espacio, no se hace nada.

	void Aniade (int nuevo)
	{
		if (total_utilizados < TAMANIO) {
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}

	/***********************************************************************/
	// Eliminar el dato de la posición dada por "indice".
	// Realiza un borrado físico (con desplazamiento y sustitución).
	//
	// PRE: 0 <= indice < total_utilizados

	void Elimina (int indice)
	{
		// Recorremos de izquierda a derecha toda las componentes
		// que hay a la derecha de la posición a eliminar
		//		Le asignamos a cada componente la que hay a su derecha

		if ((indice >= 0) && (indice < total_utilizados)) {

			int tope = total_utilizados-1; // posición del último

			for (int i = indice ; i < tope ; i++)
				vector_privado[i] = vector_privado[i+1];

			total_utilizados--;
		}
	}

	/***********************************************************************/
	// Devuelve el elemento de la casilla "indice"
	//
	// PRE: 0 <= indice < total_utilizados

	int Elemento (int indice)
	{
		return vector_privado[indice];
	}

	/***********************************************************************/
	// Devuelve true si la secuencia está vacía

	bool EstaVacia (void)
	{
		return (total_utilizados == 0);
	}

	/***********************************************************************/
	// "Vacía" una secuencia

	void EliminaTodos (void)
	{
		total_utilizados = 0;
	}

	/***********************************************************************/
	// Devuelve la posición del mínimo valor de la secuencia
	//
	// PRE: 0 <= izda <= dcha < total_utilizados

	int PosicionMinimo (int izda, int dcha)
	{
		int posicion_minimo;
		int minimo;

		minimo = vector_privado[izda];
		posicion_minimo = izda;

		for (int i = izda; i <= dcha ; i++) {

			if (vector_privado[i] < minimo){
				minimo = vector_privado[i];
				posicion_minimo = i;
			}
		}

		return (posicion_minimo);
	}

	/***********************************************************************/
	// Devuelve la posición del máximo valor de la secuencia
	//
	// PRE: 0 <= izda <= dcha < total_utilizados

	int PosicionMaximo (int izda, int dcha)
	{
		int posicion_maximo;
		int maximo;

		maximo = vector_privado[izda];
		posicion_maximo = izda;

		for (int i = izda; i <= dcha ; i++) {

			if (vector_privado[i] > maximo){
				maximo = vector_privado[i];
				posicion_maximo = i;
			}
		}

		return (posicion_maximo);
	}

	/***********************************************************************/
	// Devuelve el mínimo de la secuencia.
	//
	// PRE: 0 <= izda <= dcha < total_utilizados

	int Minimo (int izda, int dcha)
	{
		return (vector_privado[PosicionMinimo(izda, dcha)]);
	}


	/***********************************************************************/
	// Devuelve el máximo de la secuencia.
	//
	// PRE: 0 <= izda <= dcha < total_utilizados

	int Maximo (int izda, int dcha)
	{
		return (vector_privado[PosicionMaximo(izda, dcha)]);
	}

	/***********************************************************************/
	
	string ToString (void)
	{
		
		string cadena;
		
		for (int i = 0; i < total_utilizados; i++)
		cadena = cadena + " " + to_string (vector_privado[i]);
		
		return (cadena);
	} 
		

};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

// Tabla rectangular de enteros

class TablaRectangularEnteros
{

private:

    static const int NUM_FILS = 50; // Filas disponibles
    static const int NUM_COLS = 40; // Columnas disponibles
    
    int  matriz_privada[NUM_FILS][NUM_COLS];

    // PRE: 0 <= filas_utilizadas <= NUM_FILS
    // PRE: 0 <= col_utilizadas < NUM_COLS
    
    int filas_utilizadas;
    int cols_utilizadas;

public:

	/***********************************************************************/
	// Constructor sin argumentos--> Crea matriz nula

	TablaRectangularEnteros(void): filas_utilizadas(0), cols_utilizadas(0) {}
	
	/***********************************************************************/
	// Constructor--> Recibe "numero_de_columnas" que indica el número de 
	// columnas que deben tener TODAS las filas. 
	// PRE: numero_de_columnas <= MAX_COL

	TablaRectangularEnteros (int numero_de_columnas) : filas_utilizadas(0), 
		  cols_utilizadas(numero_de_columnas)
	{ }

	/***********************************************************************/
	// Constructor--> Recibe una secuencia de enteros.  El número de 
	// elementos de la secuencia es el valor que se usa como "col_utilizadas"
	// PRE: primera_fila.TotalUtilizados() <= MAX_COL

	TablaRectangularEnteros (SecuenciaEnteros primera_fila)
		: filas_utilizadas(0), cols_utilizadas (primera_fila.TotalUtilizados())
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}

	/***********************************************************************/
	// Método de lectura: número máximo de filas

	int CapacidadFilas (void)
	{
		return (NUM_FILS);
	}

	/***********************************************************************/
	// Método de lectura: número máximo de columnas

	int CapacidadColumnas (void)
	{
		return (NUM_COLS);
	}

	/***********************************************************************/
	// Método de lectura: número real de filas usadas

	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}

	/***********************************************************************/
	// Método de lectura: número real de columnas usadas

	int ColumnasUtilizadas (void)
	{
		return (cols_utilizadas);
	}

	/***********************************************************************/
	// Método de lectura: devuelve el dato que ocupa la casilla 
	// de coordenadas (fila, columna)
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < cols_utilizadas	
	
	int Elemento (int fila, int columna)
	{
		return (matriz_privada[fila][columna]);
	}

	/***********************************************************************/
	// Devuelve true si la tabla está vacía

	bool EstaVacia (void)
	{
		return (filas_utilizadas == 0);
	}
	
	/*****************************************************************/
	// Devuelve una fila completa (un objeto "SecuenciaEnteros")
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaEnteros Fila (int indice_fila)
	{
		SecuenciaEnteros fila;

		for (int col=0; col<cols_utilizadas; col++)
			fila.Aniade(matriz_privada[indice_fila][col]);

		return (fila);
	}

	/***********************************************************************/
	// Devuelve una columna completa (un objeto "SecuenciaEnteros")
	// PRE: 0 <= indice_columna < cols_utilizadas
	
	SecuenciaEnteros Columna (int indice_columna)
	{
		SecuenciaEnteros columna;

		for (int fil=0; fil<filas_utilizadas; fil++)
			columna.Aniade (matriz_privada[fil][indice_columna]);

		return (columna);
	}

	/***********************************************************************/
	// Añade una fila completa (un objeto "SecuenciaEnteros")
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	
	void Aniade (SecuenciaEnteros fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		if ((filas_utilizadas < NUM_FILS) &&
			(numero_columnas_fila_nueva == cols_utilizadas)) {

			for (int col = 0; col < numero_columnas_fila_nueva; col++)
				matriz_privada[filas_utilizadas][col]=fila_nueva.Elemento(col);

			filas_utilizadas++;
		}
	}

	/***********************************************************************/
	void AniadeElemento (int elemento)
    {
            matriz_privada[filas_utilizadas][cols_utilizadas] = elemento;
            filas_utilizadas++;
        	cols_utilizadas++;
    }
    
    /***********************************************************************/

	// "Vacía" una tabla

	void EliminaTodos (void)
	{
		filas_utilizadas = 0;
	}
	
	/***********************************************************************/
	// Calcula si dos matrices rectangulares son iguales
	// Compara la tabla implícita con "otra" (tabla explícita) 

	bool EsIgual (TablaRectangularEnteros otra_tabla)
	{
		bool son_iguales = true; 
		
		if ((filas_utilizadas != otra_tabla.FilasUtilizadas()) ||  
			 (cols_utilizadas != otra_tabla.ColumnasUtilizadas()))		
			
			son_iguales = false;
		
		else {
			
			int f=0; 
			
			while (f<filas_utilizadas && son_iguales) {
				
				int c=0; 
				
				while (c<cols_utilizadas && son_iguales) {
			
					if (matriz_privada[f][c] != otra_tabla.Elemento(f,c)) 
						son_iguales = false;
						
					c++;
					
				} // while c
	
				f++;
					
			} // while f
					
		} // else 
	
		return (son_iguales);
	}
	
	/***********************************************************************/
	// Devuelve la traspuesta de la matriz (si es posible calcularse)
	// PRE: filas_utilizadas <= MAX_COL
	// PRE: cols_utilizadas  <= MAX_FIL
	// Si no se puede calcular la traspuesta se devuelve una matriz nula. 

	TablaRectangularEnteros Traspuesta (void)
	{		
	    TablaRectangularEnteros traspuesta; // Inicialmente vacía
		
		if ((filas_utilizadas <= NUM_COLS) && (cols_utilizadas  <= NUM_FILS)) {
		
			// La traspuesta tiene tantas filas como columnas tiene la
			// matriz original
	
			TablaRectangularEnteros solucion (filas_utilizadas);
	
	
			SecuenciaEnteros columna; // Las filas de "traspuesta" serán las
										 // columnas de la tabla implícita
	
			for (int col = 0; col < cols_utilizadas; col++){
	
				columna = Columna(col);
				solucion.Aniade(columna);
			}
			
			traspuesta = solucion;
		} 

		return (traspuesta);
	}			
	

	/***********************************************************************/
	// Calcula si una matriz es simétrica.
	// CONDICIÓN NECESARIA: debe ser cuadrada. 
	// Este método comprueba directamente si cada componente es igual a
	// su simétrica, parando el recorrido cuando encuentre una componente
	// que no lo verifique.
	//
	// Evita el cálculo de la traspuesta, y el problema que puede surgir
	// si no se puede calcular la traspuesta de la matriz por problemas de
	// capacidad.

	bool EsSimetrica (void)
	{
		bool es_simetrica = true;

		// Si el número de filas y columnas no coinciden, no hay que seguir
		// porque la matriz no es simétrica.

		es_simetrica = (filas_utilizadas == cols_utilizadas);

		if (es_simetrica) {

			int f=0;

			while (f<filas_utilizadas && es_simetrica) {

				int c=0;

				while (c<cols_utilizadas && es_simetrica) {

					if (matriz_privada[f][c] != matriz_privada[c][f])
						es_simetrica = false;

					c++;

				} // while c

				f++;

			} // while f

		} // if (es_simetrica)

		return (es_simetrica);
	}
					
	/***********************************************************************/
	// Inserta una fila completa en una posición dada. 
	// La fila se porporciona en un objeto "SecuenciaEnteros".
	// 
	// Recibe: num_fila, la posición que ocupará "fila_nueva" cuando se 
	//		 		inserte en la tabla.
	//		   fila_nueva, la secuencia que se va a insertar. Se trata 
	//				de un objeto de la clase "SecuenciaEnteros". 
	//
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	// PRE:  0 <= num_fila <= TotalUtilizados()
	//		 Si num_fila = 0, "nueva_fila" será la nueva primera fila. 
	//		 Si num_fila = TotalUtilizados(), "nueva_fila" será la nueva 
	//		 última fila (el resultado será equivalente al de "Aniade()" 
	
	void Inserta (int num_fila, SecuenciaEnteros fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		// Comprobar precondiciones
		
		if ((filas_utilizadas < NUM_FILS) &&
			(numero_columnas_fila_nueva == cols_utilizadas) && 
			(0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones altas. 
			// La última fila se copia en una NUEVA FILA que ocupa la 
			// posición "filas_utilizadas", la penúltima se copia en 
			// "filas_utilizadas"-1, ... y se queda un "hueco" en 
			// la fila "num_fila ".
			// NOTA: no se modifica (todavía) "filas_utilizadas" 
			
			for (int fil=filas_utilizadas; fil>num_fila; fil--) {
				
				for (int col = 0; col < numero_columnas_fila_nueva; col++)
					matriz_privada[fil][col]=matriz_privada[fil-1][col];
			}
			
			// Copiar en el "hueco" (fila "num_fila") el contenido de 
			// la secuencia "fila_nueva"
			
			for (int col = 0; col < numero_columnas_fila_nueva; col++)
				matriz_privada[num_fila][col]=fila_nueva.Elemento(col);	
			
			filas_utilizadas++; // Actualización del tamaño de la tabla.
		}
	}

	/***********************************************************************/
	// Elimina una fila completa, dada una posición. 
	// 
	// Recibe: num_fila, la posición de la fila a eliminar.
	// PRE:  0 <= num_fila < TotalUtilizados()
	
	void Elimina (int num_fila)
	{		
		// Comprobar precondiciones
		
		if ((0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones bajas. 
			// En la posición "num_fila" se copia la que está en la posición
			// siguiente ("num_fila"+1), en su lugar se copia que está en 
			// "num_fila"+2, ... y en la posición "total_utilizados"-2 se 
			// copia la de "total_utilizados"-1. 
			
			for (int fil=num_fila; fil<filas_utilizadas-1; fil++) {
			
				int num_columnas = cols_utilizadas;
					
				for (int c=0; c<num_columnas; c++) 
					matriz_privada[fil][c]=matriz_privada[fil+1][c];
			}
			
			filas_utilizadas--; // Actualización del tamaño de la tabla.
		}
	}	
	
	/***********************************************************************/
	// Devuelve TRUE si la matriz contiene el valor "buscado"
	
	bool Contiene (int buscado)
	{
		bool encontrado = false;

		// Recorrido por columnas 

		int col = 0;

		while (col < cols_utilizadas && !encontrado) {

			int fil=0;

			while (fil < filas_utilizadas && !encontrado) {

				if (matriz_privada[fil][col] == buscado)
					encontrado = true;
				
				fil++;

			} // while fil

			col++; 

		} // while col

		return (encontrado);
	}
		
	
	/***********************************************************************/
	// Método que consiste en la búsqueda de la fila de una matríz que más se 
	// aproxime a un vector dado.
	// PRE: vector_a_comparar.TotalUtilizados() = cols_utilizadas
	// PRE: filas_a_analizar.TotalUtilizados() <= filas_utilizadas

	
	SecuenciaEnteros FilaParecida (SecuenciaEnteros vector_a_comparar,
	                  SecuenciaEnteros filas_a_analizar)
	{
		
		// En este método se trabaja con distancias euclídeas entre vectores.
		// Se declaran dos variables para la distancia: una que representa la
		// distancia entre dos elementos de dos vectores y otra que representa
		// la distancia mínima entre los vectores (el vector que se va a 
		// comparar, que en realidad es una secuencia de enteros, y la fila
		// de la tabla rectangular que estemos analizando).
		// Ambas distancias se inicializan a cero.
		
		double distancia_entre_elementos = 0;
		double distancia_minima = 0;
		
		// Creo un objeto de la clase SecuenciaEnteros, que es el objeto que
		// va a ser devuelto en este método; la secuencia que, en términos 
		// de distancia euclídea se asemeje más al vector a comparar.
		
		SecuenciaEnteros fila_parecida;
		
		// En primer lugar, se comienza analizando el caso en el que la 
		//secuencia de filas a comparar solo esté consituída por una única fila. 
		// En tal caso, la distancia mínima será la propia a la distancia 
	    // euclídea entre el vector y la única fila que hay. Se va recorriendo 
		// cada uno de los elementos de la fila 0 (se van recorriendo las 
		// columnas) y se calcula la distancia como la suma de los cuadrados de
		// las diferencias entre los elementos de los vectores. Una vez 
		// calculada esta distancia, se guarda la fila en la secuencia 
		// fila_parecida (pues es la única que de momento se asemeja al vector),
		// y finalmente, una vez fuera del ciclo, se calcula la distancia
		//  mínima, que no es otra cosa que la raíz cuadrada de la suma de
		// los cuadrados de las diferencias entre los elementos de los
		// vectores, es decir, se le hace la raíz cuadrada a la distancia
		// previamente calculada.
		
		for (int k = 0; k < cols_utilizadas; k++){
			
			distancia_minima = distancia_minima + 
			                   pow((vector_a_comparar.Elemento(k),
			                   matriz_privada[filas_a_analizar.Elemento(0)][k]),
							    2);
			                       
			
		  fila_parecida.Aniade(matriz_privada[filas_a_analizar.Elemento(0)][k]);
			
		}
		
		distancia_minima = sqrt(distancia_minima);
		
		// Por otra parte, en el momento en el que la secuencia de filas a 
		// analizar pase a tener más de una fila, comenzamos analizando 
		// ya la segunda de las filas que se han de analizar. 
		// Para el cálculo de la distancia se procede de la misma forma que en 
		// el caso anterior.
		// Se evalúa cada fila de la secuencia de filas a analizar, comenzando
		// por la segunda (1), y cada columna de dicha fila, y se calcula
		// la distancia del vector a la fila, y así sucesivamente, hasta acabar
		// con las filas indicadas en la secuencia de filas a analizar.
			
		for (int f = 1; f < filas_a_analizar.TotalUtilizados(); f++){
		
			for (int c = 0; c < cols_utilizadas; c++){
			
				distancia_entre_elementos = (distancia_entre_elementos + 
				    pow((vector_a_comparar.Elemento(c) -
				    matriz_privada[filas_a_analizar.Elemento(f)][c]), 2));
									   
			}
			
			distancia_entre_elementos = sqrt(distancia_entre_elementos);
			
			// A continuación, como hemos de buscar la fila que más se asemeje
			// al vector a comparar, es decir, la fila que se encuentre a menor
			// distancia del vector, tenemos que buscar la mínima de las
			// distancias, es decir, si se verifica el hecho de que la distancia
			// entre los vectores es menor que la distancia a la que previamente
			// se le había asignado la distancia respecto a la primera fila a 
			// analizar, entonces, se le asgina a dicha distancia mínima el 
			// valor de la nueva distancia calculada, y se vuelve a añadir a 
			// la secuencia de enteros que representa la fila parecida al vector
			// habiendo antes eliminado los elementos de dicha secuencia, pues
			// estaban guardados los elementos de la fila anterior, que no 
			// cumplen la condición.
			
				if (distancia_entre_elementos < distancia_minima){
				
					distancia_minima = distancia_entre_elementos;
				
					fila_parecida.EliminaTodos();
				
					for (int k = 0; k < cols_utilizadas; k++){
					
					fila_parecida.Aniade(Elemento(filas_a_analizar.Elemento(f), 
					                     k));
					
					}
				}
			
			// Es importante resaltar este paso: Cada vez que se acabe de 
			// analizar una de las filas de la secuencia de filas a analizar, 
			// se debe de volver a inicializar la distancia entre los vectores
			// a cero, para volver a calcular la distancia euclídea y poder 
			// posteriormente comparar. De lo contrario, se estaría trabajando
			// con la distancia anterior y los resultados no saldría en 
			// condiciones.
			
			distancia_entre_elementos = 0;
			
		}
		
		return (fila_parecida);
		
	}
			
	/***********************************************************************/
	// Método ToString que devuelve un string en representación de la tabla
	// rectangular.
		
	string ToString (string titulo)
	{
		string cad; 
		
		cad = "\n" + titulo + "\n"; 	
		cad = cad + "\n--------------------------------------\n"; 
		
		for (int fila=0; fila<filas_utilizadas; fila++) {
	
			SecuenciaEnteros la_secuencia = Fila(fila);
	
			cad = cad + la_secuencia.ToString() + "\n";
		}
		
		cad = cad + "--------------------------------------\n"; 
		cad = cad + "\n\n";
		
		return (cad); 
	}
			
		
};

/////////////////////////////////////////////////////////////////////////////
class Lector
{
	private:
		
		string titulo;
	
	public:
		
		// Constructor sin argumentos
		
		Lector (void) : titulo ("")
		{ }
		
		// Constructor con argumentos
		
		Lector (string cad) : titulo (cad)
		{ }
		
		// Método Set para fijar el campo "titulo"
		
		void SetTitulo (string cad)
		{
			titulo = cad;
		}
		
		/*********************************************************************/
		// Lee un dato int.
		// La lectura está etiquetada con "titulo"
		// La lectura se efectúa repetidamente hasta que se introduce un valor
		// int correcto.
		
		int LeeEntero (void)
		{
			string cadena;
			
			do{
				cout << titulo;
				getline(cin, cadena);
			}
			while (!EsEntero(cadena));
			
			return (stoi(cadena));
		}
		
		/*********************************************************************/
		// Lee un dato int.
		// La lectura está etiquetada con "titulo"
		// PRE: menor <= mayor
		// POST: menor <= valor devuelto <= mayor
		
		int LeeEnteroEnRango (int menor, int mayor)
		{
			int numero;
			
			do{
				
				numero = LeeEntero ();
			}
			while ((numero<menor) || (numero>mayor));
			
			return (numero);
		}
		
		/*********************************************************************/
		// Lee un dato int que debe ser mayor o igual que "menor" y lo devuelve.
		// La lectura está etiquetada con "titulo"
		
		int LeeEnteroMayorOIgual (int menor)
		{
			int numero;
			
			do{
				numero = LeeEntero ();
			}
			while (numero < menor);
			
			return (numero);
		}
		
		/*********************************************************************/
		// Lee un dato double.
		// La lectura está etiquetada con "titulo"
		// La lectura se efectúa repetidamente hasta que se introduce un valor
		// double correcto.
		
		double LeeReal (void)
		{
			string cadena;
			
			do{
				cout << titulo;
				getline(cin, cadena);
			}
			while (!EsReal(cadena));
			
			return (stod(cadena));
		}
		
		/*********************************************************************/
		// Lee un dato double.
		// La lectura está etiquetada con "titulo"
		// PRE: menor <= mayor
		// POST: menor <= valor devuelto <= mayor
		
		double LeeRealEnRango (int menor, int mayor)
		{
			double numero;
			
			do{
				
				numero = LeeReal ();
			}
			while ((numero<menor) || (numero>mayor));
			
			return (numero);
		}

		/*********************************************************************/
		// Lee un dato double que debe ser mayor o igual que "menor" y lo 
		// devuelve. 
		// La lectura está etiquetada con "titulo"
		
		double LeeRealMayorOIgual (int menor)
		{
			double numero;
			
			do{
				numero = LeeReal ();
			}
			while (numero < menor);
			
			return (numero);
		}

		/*********************************************************************/
	
	private:
		
		/*********************************************************************/
		// Devuelve una NUEVA cadena, resultante de eliminar los últimos
		// caracteres separadores de "cadena". Los caracteres separadores son
		// el espacio en blanco, el tabulador y el salto de línea.
		// Usaremos la función isspace() para simplificar el cálculo.
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: el resultado de eliminar los últimos separadores de 
		// "cadena"
		/*********************************************************************/
		
		string EliminaUltimosSeparadores (string cadena)
		{
			while (cadena.length()>0 && isspace(cadena.back()))
				cadena.pop_back();
			
			return (cadena);
		}
		
		/*********************************************************************/
		// Devuelve una NUEVA cadena, resultante de eliminar los primeros
		// caracteres separadores de "cadena". Los caracteres separadores son
		// el espacio en blanco, el tabulador y el salto de línea.
		// Usaremos la función isspace() para simplificar el cálculo.
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: el resultado de eliminar los últimos separadores de 
		// "cadena"
		/*********************************************************************/
		string EliminaPrimerosSeparadores (string cadena)
		{
			// Buscar el primer carácter no espacio
			unsigned int pos = 0;
			while (pos < cadena.length() && isspace(cadena.at(pos))) pos++;
			
			string local;
			
			// Copiar todos los que quedan
			while (pos < cadena.length()) {
				local.push_back(cadena.at(pos));
				pos++;
			}
			
			return (local);
		}
		
		/*********************************************************************/
		// Devuelve una NUEVA cadena, resultante de eliminar los primeros 
		// últimos caracteres separadores de "cadena". Los caracteres 
		// separadores son el espacio en blanco, el tabulador y el salto de
		// línea
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: el resultado de eliminar los primeros y los últimos
		//           separadores de "cadena".
		/*********************************************************************/
		
		string EliminaPrimerosYUltimosSeparadores (string cadena)
		{
			string cadena_podada = EliminaPrimerosSeparadores (cadena);
			cadena_podada = EliminaUltimosSeparadores (cadena_podada);
			
			return (cadena_podada);
		}
		
		/*********************************************************************/
		// Devuelve "true" si "cadena" es la representación textual de un
		// entero
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: "true" si "cadena" es la representación textual de un int
		
		bool EsEntero (string cadena)
		{
			bool es_entero = true;
			
			cadena = EliminaPrimerosSeparadores (cadena);
			cadena = EliminaUltimosSeparadores (cadena);
			
			unsigned int long_cadena = cadena.length();
			
			if (long_cadena == 0) es_entero = false;
			else {
				
				// Si el primer carácter es '+' ó '-', perfecto. En ese caso
				// se pasa al siguiente carácter (posición 19.
				
				unsigned int pos;
				if (cadena.at(0)=='-' || cadena.at(0) == '+') pos = 1;
				else pos = 0;
				
				while ((pos < long_cadena) && es_entero) {
					if(!isdigit(cadena.at(pos))) es_entero = false;
					else pos++;
				}
			}
			
			return (es_entero);
		}
		
		/*********************************************************************/

		bool EsReal (string cadena)
		{
			bool es_real = true;
			
			cadena = EliminaPrimerosSeparadores (cadena);
			cadena = EliminaUltimosSeparadores (cadena);
			
			unsigned int long_cadena = cadena.length();
			
			if (long_cadena == 0) es_real = false;
			else {
				
				// Si el primer carácter es '+' ó '-', perfecto. En ese caso
				// se pasa al siguiente carácter (posición 19.
				
				unsigned int pos;
				if (cadena.at(0)=='-' || cadena.at(0) == '+') pos = 1;
				else pos = 0;
				
				// Bandera que se activa al encontrar un punto
				bool encontrado_un_punto = false;
				
				while ((pos < long_cadena) && es_real) {
					
					char c = cadena.at(pos);
					
					if (!isdigit(c)) {
						
						// Solo puede haber un punto.
						// Si se ha encontrado un punto y ya se había
						// encontrado otro, error. Si no, activar la bandera
						// "encontrado_un_punto" (ya no puede haber más).
						
						if (c == '.') {
							if (encontrado_un_punto) es_real = false;
							else encontrado_un_punto = true;
						}
						
					    // Si no es un punto ni un dígito --> error
						else es_real = false;
					}
					
					pos++;
					
				}  // while ((pos < long_cadena) && es_real)
				
			}  // else de if (long_cadena == 0)
			
			return (es_real);
		}
		
		/*********************************************************************/

};


////////////////////////////////////////////////////////////////////////////////

int main ()
{
	
	// Declaración de datos
	
	//Declaración de datos
	
	Lector lee;
	
	int numero_filas;
	int numero_columnas;
	
	const int MAX_FILS = 50;
	const int MAX_COLS = 40;	
	// Entrada de datos
	
	lee.SetTitulo("Introduzca el numero de filas que tiene la matriz: ");
	numero_filas = lee.LeeEnteroEnRango(1, MAX_FILS);
	
	cout << endl;
	
	lee.SetTitulo("Introduzca el numero de columnas de la matriz: ");
		              
	numero_columnas = lee.LeeEnteroEnRango(1, MAX_COLS);
	
	// Creación del objeto TablaRectangularEnteros, utilizando el construcor
	// con argumentos que recibe como parámetro el número de columnas de la 
	// tabla.
	
	TablaRectangularEnteros tabla (numero_columnas);
	
	for (int f = 0; f < numero_filas; f++){
		
		SecuenciaEnteros rellenador;
		
		lee.SetTitulo("Introduzca un elemento de la fila "+to_string(f)+": ");
		
		cout << endl;
		
		for (int i =0; i < numero_columnas; i++){
			
			rellenador.Aniade(lee.LeeEntero());
		}
		
		tabla.Aniade(rellenador);
	}
	
	// MOSTRAR MATRIZ
	
	cout << tabla.ToString("Matriz de enteros");
	
	// Creación de los objetos de la clase SecuenciaEnteros con los que se va
	// a trabajar: las filas que se van a analizar y el vector que se va a 
	// comparar.
	
	SecuenciaEnteros filas_analisis;
	SecuenciaEnteros vector_analisis;
	
	int filitas;
	
	lee.SetTitulo("Introduzca el numero de filas que desea analizar: ");
	filitas = lee.LeeEnteroEnRango(1, tabla.CapacidadFilas());
	
	cout << "Introduzca las filas de la matriz que desea analizar: ";
	cout << endl;
	
	for (int i = 0; i < filitas; i++){ 
	
		lee.SetTitulo("Fila: ");
		filas_analisis.Aniade(lee.LeeEntero());
		
	}
	
	cout << endl;
	
	
	cout << "Introduzca el vector que desea comparar: ";
	cout << endl;
	
	for (int i = 0; i < numero_columnas; i++){ 
		
		lee.SetTitulo("Introduzca elemento: ");
		vector_analisis.Aniade(lee.LeeEntero());
		
	}
	
	
	cout << endl;
	
	// Salida de resultados
	
	cout << endl;
	cout << "La fila que mas se asemeja al vector es la: " 
	     << tabla.FilaParecida(vector_analisis, filas_analisis).ToString();
	cout << endl;
	
	return 0;
}
	
  
