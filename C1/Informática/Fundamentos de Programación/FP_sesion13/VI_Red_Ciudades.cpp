/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que en el que se introduce una serie de ciudades y las distancias
   entre ellas, pudiendo estar o no conectadas entre sí, y se lleva a cabo
   una serie de cálculos sobre dicha red de ciudades para suplir lo pedido en
   los cuatro apartados de los que consta el ejercicio:
   
   	APARTADO A: Ciudad de la red que tiene más conexiones directas.
   	APARTADO B: Ciudades que están conectadas a una determinada.
   	APARTADO C: Ciudad intermedia entre dos dadas.
   	APARTADO D: Si una serie de ciudades dadas se encuentran conectadas entre 
	            sí.
   	
   Para ello, se ha hecho uso de una clase, que es la MapaDistancias, que
   se basa en la clase TablaRectangularReales, y en la que se han implementado
   una serie de métodos para llevar a cabo los apartados del ejercicio.
         
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;  
 
/******************************************************************************/

class SecuenciaReales
{

private:

	static const int TAMANIO = 50; // Número de casillas disponibles
	double vector_privado[TAMANIO];

	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas

public:

	/***********************************************************************/
	// Constructor sin argumentos

	SecuenciaReales (void)
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

	void Aniade (double nuevo)
	{
		if (total_utilizados < TAMANIO) {
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}

	/***********************************************************************/
	// Devuelve el elemento de la casilla "indice"
	//
	// PRE: 0 <= indice < total_utilizados

	double Elemento (int indice)
	{
		return vector_privado[indice];
	}

	/***********************************************************************/
	// "Limpia" completamente una secuencia

	void EliminaTodos (void)
	{
			total_utilizados = 0;
	}

	/***********************************************************************/
	// Devuelve una cadena de caracteres: la secuencia de reales guardada en
	// el vector_privado, separados sus elementos por un espacio.

	string ToString (void)
	{
		string cadena;
		
		for (int i=0; i<total_utilizados; i++)
		
			cadena = cadena +" " + to_string(vector_privado[i]);

		return (cadena);
	}

	/***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////
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
	// Devuelve una cadena de caracteres: la secuencia de enteros guardada en
	// el vector_privado, separados sus elementos por un espacio.
	
	string ToString (void)
	{
		
		string cadena;
		
		for (int i = 0; i < total_utilizados; i++)
		cadena = cadena + to_string (vector_privado[i]) + " ";
		
		return (cadena);
	} 
		
	/***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class MapaDistancias
{
private:

    static const int NUM_FILS = 50; // Filas disponibles
    static const int NUM_COLS = 40; // Columnas disponibles
    
    double distancias[NUM_FILS][NUM_COLS];
	
    // PRE: 0 <= filas_utilizadas <= NUM_FILS
    // PRE: 0 <= col_utilizadas < NUM_COLS
    
    int filas_utilizadas;
    int cols_utilizadas;

public:
	
	/***********************************************************************/
	// Constructor sin argumentos

	MapaDistancias (void) :filas_utilizadas(0), cols_utilizadas(0)
	{}
	
	/***********************************************************************/
	//Constructor con argumentos
	// PRE: 0 < num_ciudades <= NUM_COLS
	
	MapaDistancias (int num_ciudades) 
	
	:filas_utilizadas(0), cols_utilizadas(num_ciudades)	
	
	{}

	/***********************************************************************/
	// Métodos Get
		
	// Devuelve el número máximo de filas de la matriz
	
	int CapacidadFilas (void)
	{
		return (NUM_FILS);
	}

	/***********************************************************************/
	
	// Devuelve el número máximo de columnas la matriz

	int CapacidadColumnas (void)
	{
		return (NUM_COLS);
	}

	/***********************************************************************/
	
	// Devuelve filas_utilizadas

	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}

	/***********************************************************************/
	
	// Devuelve cols_utilizadas

	int ColumnasUtilizadas (void)
	{
		return (cols_utilizadas);
	}

	/***********************************************************************/
	
	// Devuelve el dato  de coordenadas (fila, columna)
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < cols_utilizadas
		
	double Elemento (int fila, int columna)
	{
		return (distancias[fila][columna]);
	}

	/***********************************************************************/
	
	// Devuelve true si la red está vacía

	bool EstaVacia (void)
	{
		return (filas_utilizadas == 0);
	}
	
	/***********************************************************************/	
	
	// Añade una fila completa (un objeto "SecuenciaReales")
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < NUM_FILS
	
	void Aniade (SecuenciaReales fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		if ((filas_utilizadas < NUM_FILS) &&
			(numero_columnas_fila_nueva == cols_utilizadas)) {

			for (int col = 0; col < numero_columnas_fila_nueva; col++)
				distancias[filas_utilizadas][col] = fila_nueva.Elemento(col);

			filas_utilizadas++;
		}
	}
	
	/***********************************************************************/
	// Devuelve una fila completa (un objeto "SecuenciaReales")
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaReales Fila (int indice_fila)
	{
		SecuenciaReales fila;

		for (int col=0; col<cols_utilizadas; col++)
			fila.Aniade(distancias[indice_fila][col]);

		return (fila);
	}

	/***********************************************************************/
	// "Vacía" una tabla

	void EliminaTodos (void)
	{
		filas_utilizadas = 0;
	}
	
	/***********************************************************************/
	// Devuelve true si hay conexión entre dos ciudades
	
	bool Conectadas (int ciudad1, int ciudad2)
	{
		return (distancias[ciudad1][ciudad2] > 0);
	}	

	/***********************************************************************/
	// Número de conexiones directas de una ciudad
	
	int ConexionesDirectas (int ciudad)
	{
		int contador_conexiones_directas = 0;
		
		for (int i = 0; i < filas_utilizadas; i++){
			
			if (Conectadas(i, ciudad)) contador_conexiones_directas++;
		}
	
		return (contador_conexiones_directas);
	}	
	
	/***********************************************************************/
	// Devuelve la ciudad (su índice) con mayor número de conexiones directas
	
	int MayorNumConexionesDirectas (void)
	{
		int indice = 0;
		
		for (int i = 1; i < filas_utilizadas; i++)
			
			if (ConexionesDirectas(i) > ConexionesDirectas(indice)) indice = i;
		
		return (indice);
	}
	
	/***********************************************************************/
	// Devuelve las ciudades en una secuencia de enteros que tienen conexión
	// con una dada
	
	SecuenciaEnteros ConectadasDirectamenteCon (int indice)
	{
		SecuenciaEnteros ciudades_conexion;
		
		for (int c = 0; c < filas_utilizadas; c++){
			
			if (Conectadas(c, indice)) ciudades_conexion.Aniade(c+1);
			
		}
		
		return (ciudades_conexion);
	}
	
	/***********************************************************************/
	// Método que devuelve la ciudad intermedia entre dos ciudades. 
	// En el caso de que no se encuentre dicha ciudad, se devuelve -1
	// PRE: No conexión directa entre ciudades
	
	int Intermedia (int i, int j)
	{
		int ciudad;
		double distancia_min = 0;
		double distancia;
		bool ciudad_intermedia_encontrada = false;
		
		for (int k = 0; k < cols_utilizadas; k++)
			
			// Condición de que no haya conexión directa entre las dos ciudades
			// Claramente para poder hallar la intermedia.
			
			if (k != i && k != j)
			
				if (Conectadas(k, i) && Conectadas(k , j)) {
					
					distancia = distancias[k][i] + distancias[k][j];
					
					if (distancia < distancia_min) {
						
						ciudad_intermedia_encontrada = true;
						
						ciudad = k;
						distancia_min = distancia;
					}
				}		
		
		if (!ciudad_intermedia_encontrada)ciudad = -1;
		
		return (ciudad);	
	}	
	
	/***********************************************************************/
	// Devuelve true si una serie de ciudades entán conectadas entre sí
	
	bool EstanTodasConectadas (SecuenciaEnteros ciudades)
	{
		bool la_totalidad_de_las_ciudades = true;
		
		// Se comienza recorriendo la secuencia de ciudades, comenzando por la
		// primera, y a continuación, con otro índice se vuelve a leer, de 
		// tal forma que si la ciudad que se ha comenzado a evaluar con el
		// primer índice está conectada directamenete con una de las que indique
		// el segundo índice, entonces, la variable tipo bool que he declarado
		// al principio, toma el valor true.
		
		for (int i = 0; i < ciudades.TotalUtilizados() &&
		     la_totalidad_de_las_ciudades; i++){
		     	
			for (int j = 0; j < ciudades.TotalUtilizados() && 
			 la_totalidad_de_las_ciudades; j++){
			
				if (!Conectadas(ciudades.Elemento(i), ciudades.Elemento(j)) &&
			    	(i != j))
					la_totalidad_de_las_ciudades = false;
				
			}
		}
					
		return (la_totalidad_de_las_ciudades);
	
	}
	
	/***********************************************************************/
	string ToString (string titulo)
	{
		string cad; 
		
		cad = "\n" + titulo + "\n"; 	
		cad = cad + "\n--------------------------------------\n"; 
	
		for (int fila=0; fila<filas_utilizadas; fila++) {
	
			SecuenciaReales la_secuencia = Fila(fila);
			
			cad = cad + "C" + to_string(fila+1); 
	
			cad = cad + la_secuencia.ToString() + "\n";
		}
		
		cad = cad + "--------------------------------------\n"; 
		cad = cad + "\n\n";
		
		return (cad);
		
	}
	
	/***********************************************************************/
	
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
	
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	// Declaración de datos
	
	int ciudades;
	double distancia;
	
	Lector lee; // Objeto de la clase Lector para la lectura y filtrado de datos
	
	// Entrada de datos
	
	lee.SetTitulo("Introduzca el numero de ciudades de la red. Tenga en cuenta"
	              " que debe ser entre 1 y 50: ");
	ciudades = lee.LeeEnteroEnRango(1, 50);
	
	// Declaración del objeto de la clase MapaDistancias sobre el que se 
	// va a trabajar. Recibe como parámetro el número de ciudades
	
	MapaDistancias mapa_distancias(ciudades);
	
	
	cout << endl ;
	cout << "Introduzca las distancias entre las ciudades (0 si no hay "
		 << "conexión directa): ";
	cout << endl;
		 
	for (int i = 0; i < mapa_distancias.ColumnasUtilizadas(); i++) {
		
		SecuenciaReales secuencia_ciudades;
		
		if (i < (ciudades -1))
		
		cout << "\tDistancias a la ciudad " << (i+1) << ":" << endl;
		
		for (int j = 0; j < mapa_distancias.ColumnasUtilizadas(); j++) {
			
			if (j >= i) {
				
				lee.SetTitulo("\tCiudad " + to_string(j+1) + ": ");
				
				if (i != j) distancia = lee.LeeRealMayorOIgual(0);
				
				else distancia = 0;
				
				secuencia_ciudades.Aniade(distancia);
			}
			
			else secuencia_ciudades.Aniade(mapa_distancias.Elemento(j, i));
		}
		
		mapa_distancias.Aniade(secuencia_ciudades);
	}
	
	// MOSTRAR RED DE CIUDADES
	
	cout << mapa_distancias.ToString("RED DE CIUDADES");


	// CÁLCULOS Y RESULTADOS
	
	/**********************************************************************/
	// APARTADO A
	
	int ciudad_mas_conexiones = mapa_distancias.MayorNumConexionesDirectas()+1;
	
	cout << endl;
	cout << "La ciudad con mas conexiones directas es la "
		 << ciudad_mas_conexiones << " ,con un total de " 
		 << mapa_distancias.ConexionesDirectas(ciudad_mas_conexiones - 1)
		 << " conexiones." << endl;
	
	/**********************************************************************/
	// APARTADO B
	
	lee.SetTitulo("Introduzca una ciudad de la red: ");
	int i = lee.LeeEnteroEnRango(1, mapa_distancias.ColumnasUtilizadas());
	
	cout << endl << "Esta ciudad se encuentra conectada con " << endl
		 << mapa_distancias.ConectadasDirectamenteCon(i-1).ToString() << endl;
		 
	/**********************************************************************/	 
	// APARTADO C
	
	cout << "Introduzca dos ciudades que no esten conectadas directamente: "; 
	cout << endl;
	
	lee.SetTitulo("\tCiudad numero 1: ");
	int ciudad_1 = lee.LeeEnteroEnRango(1, 
	               mapa_distancias.ColumnasUtilizadas());
	
	lee.SetTitulo("\tCiudad numero 2: ");
	int ciudad_2 = lee.LeeEnteroEnRango(1, 
	               mapa_distancias.ColumnasUtilizadas());
	
	ciudad_1 = ciudad_1 - 1;
	ciudad_2 = ciudad_2 - 1;
	
	if (!mapa_distancias.Conectadas(ciudad_1, ciudad_2))
	
		if (mapa_distancias.Intermedia(ciudad_1, ciudad_2) != -1)
		
			cout << "\tCiudad intermedia: "
				 << (mapa_distancias.Intermedia(ciudad_1, ciudad_2) + 1);
				 
		else cout << "\tNo existe ciudad intermedia.";
	
	else cout << "\tLas ciudades tienen conexion." << endl;
	
	/**********************************************************************/	 
	// APARTADO D
	
	SecuenciaEnteros sec_ciudades;
	
	cout << "Introduzca indices de ciudades. En caso de que quiera finalizar"
	        " la lectura, introduzca -1: ";
	cout << endl;
	
	lee.SetTitulo("\tCiudad: ");
	int cities = lee.LeeEnteroEnRango(-1, 
	             mapa_distancias.ColumnasUtilizadas());
	
	while (cities != -1) {
		
		sec_ciudades.Aniade(cities - 1);
		
		cities = lee.LeeEnteroEnRango(-1, 
		         mapa_distancias.ColumnasUtilizadas());
	}
	
	if (sec_ciudades.TotalUtilizados() > 1)
	
		cout << "¿Es cierto que todas las ciudades estan conectadas? "
			 << (mapa_distancias.EstanTodasConectadas(sec_ciudades) 
			 ? "SI, ES CIERTO":"NO, NO ES CIERTO");
			 
	else cout << "\tError: No ha introducido suficientes ciudades.";
	
	/**********************************************************************/	 
	
	return 0;
}
	
	
	
