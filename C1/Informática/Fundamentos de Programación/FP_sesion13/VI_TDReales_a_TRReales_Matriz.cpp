/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que crea una tabla rectangular de n�meros reales y la muestra en
   pantalla, a partir de una tabla dentada de n�meros reales. Dicha tabla
   rectangular, tiene el mismo n�mero de filas que la tabla dentada introducida
   por el usuario, y, en cuanto al n�mero de columnas, ser� el correspondiente
   al de la fila que menos tenga. Para ello, se ha implementado un m�todo
   en la clase TablaDentadaReales, que devuelve un objeto de la clase 
   TablaRectangularReales. Adem�s, se ha hecho uso de las clases, Lector 
   (para leer datos enteros y reales en el main) y la clase SecuenciaReales
   que se usa de forma muy recurrente en las clases de las tablas.

   Entradas:
    El n�mero de filas de la tabla dentada, el n�mero de columnas de cada
    una de esas filas, y los elementos que rellenan la matriz.
   
   Salidas:
    Una tabla rectangular a partir de la tabla dentada introducida por el
    usuario.
    
    Se ha seguido el procedimiento:
	 
	  TABLA DENTADA REALES --> TABLA RECTANGULAR REALES   -   MATRIZ CLASICA
       
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;  
 
/******************************************************************************/
class SecuenciaReales
{

private:

	static const int TAMANIO = 50; // N�mero de casillas disponibles
	double vector_privado[TAMANIO];

	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// N�mero de casillas ocupadas

public:

	/***********************************************************************/
	// Constructor sin argumentos

	SecuenciaReales (void)
	{
		total_utilizados = 0;
	}

	/***********************************************************************/
	// Constructor con argumento string
	// Recibe: la_palabra, dato string que se usa para iniciar el objeto.
	// Si "la_palabra" tiene m�s caracteres que caben en el objeto, no se
	// copia nada y se crea un objeto vac�o.
	//
	// PRE: "la_palabra" est� formada por una �nica palabra

	SecuenciaReales (string la_palabra)
	{
		total_utilizados = 0;

		int longitud_la_palabra = la_palabra.length();

		if (longitud_la_palabra <= TAMANIO) {

			for (int i=0; i<longitud_la_palabra; i++){
				if (isdigit(la_palabra[i]))
				vector_privado[i]= la_palabra[i];
			}
				

			total_utilizados = longitud_la_palabra;
		}
	}

	/***********************************************************************/
	// M�todos de lectura (Get) de los datos individuales

	// Devuelve el n�mero de casillas ocupadas
	int TotalUtilizados (void)
	{
		return (total_utilizados);
	}

	// Devuelve el n�mero de casillas disponibles
	int Capacidad (void)
	{
		return (TAMANIO);
	}

	/***********************************************************************/
	// A�ade un elemento al vector.
	// Recibe: nuevo, el elemento que se va a a�adir.
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adici�n se realiza si hay espacio para el nuevo elemento.
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
	// "Limpia" completamente una secuencia

	string ToString (void)
	{
		string cadena;
		
		for (int i=0; i<total_utilizados; i++)
		
			cadena = cadena + " " + to_string(vector_privado[i]);

		return (cadena);
	}

	/***********************************************************************/

};


/////////////////////////////////////////////////////////////////////////////
// Tabla rectangular de reales

class TablaRectangularReales
{

private:

    static const int NUM_FILS = 50; // Filas disponibles
    static const int NUM_COLS = 40; // Columnas disponibles
    
    double  matriz_privada[NUM_FILS][NUM_COLS];

    // PRE: 0 <= filas_utilizadas <= NUM_FILS
    // PRE: 0 <= col_utilizadas < NUM_COLS
    
    int filas_utilizadas;
    int cols_utilizadas;

public:

	/***********************************************************************/
	// Constructor sin argumentos--> Crea matriz nula

	TablaRectangularReales(void): filas_utilizadas(0), cols_utilizadas(0) {}
	
	/***********************************************************************/
	// Constructor--> Recibe "numero_de_columnas" que indica el n�mero de 
	// columnas que deben tener TODAS las filas. 
	// PRE: numero_de_columnas <= MAX_COL

	TablaRectangularReales (int numero_de_columnas) : filas_utilizadas(0), 
		  cols_utilizadas(numero_de_columnas)
	{ }

	/***********************************************************************/
	// Constructor--> Recibe una secuencia de reales.  El n�mero de 
	// elementos de la secuencia es el valor que se usa como "col_utilizadas"
	// PRE: primera_fila.TotalUtilizados() <= MAX_COL

	TablaRectangularReales (SecuenciaReales primera_fila)
		: filas_utilizadas(0), cols_utilizadas (primera_fila.TotalUtilizados())
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}

	/***********************************************************************/
	// M�todo de lectura: n�mero m�ximo de filas

	int CapacidadFilas (void)
	{
		return (NUM_FILS);
	}

	/***********************************************************************/
	// M�todo de lectura: n�mero m�ximo de columnas

	int CapacidadColumnas (void)
	{
		return (NUM_COLS);
	}

	/***********************************************************************/
	// M�todo de lectura: n�mero real de filas usadas

	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}

	/***********************************************************************/
	// M�todo de lectura: n�mero real de columnas usadas

	int ColumnasUtilizadas (void)
	{
		return (cols_utilizadas);
	}

	/***********************************************************************/
	// M�todo de lectura: devuelve el dato que ocupa la casilla 
	// de coordenadas (fila, columna)
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < cols_utilizadas	
	
	double Elemento (int fila, int columna)
	{
		return (matriz_privada[fila][columna]);
	}

	/***********************************************************************/
	// Devuelve true si la tabla est� vac�a

	bool EstaVacia (void)
	{
		return (filas_utilizadas == 0);
	}
	
	/*****************************************************************/
	// Devuelve una fila completa (un objeto "SecuenciaReales")
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaReales Fila (int indice_fila)
	{
		SecuenciaReales fila;

		for (int col=0; col<cols_utilizadas; col++)
			fila.Aniade(matriz_privada[indice_fila][col]);

		return (fila);
	}

	/***********************************************************************/
	// Devuelve una columna completa (un objeto "SecuenciaReales")
	// PRE: 0 <= indice_columna < cols_utilizadas
	
	SecuenciaReales Columna (int indice_columna)
	{
		SecuenciaReales columna;

		for (int fil=0; fil<filas_utilizadas; fil++)
			columna.Aniade (matriz_privada[fil][indice_columna]);

		return (columna);
	}

	/***********************************************************************/
	// A�ade una fila completa (un objeto "SecuenciaReales")
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	
	void Aniade (SecuenciaReales fila_nueva)
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
	// "Vac�a" una tabla

	void EliminaTodos (void)
	{
		filas_utilizadas = 0;
	}
	
	/***********************************************************************/
	// Calcula si dos matrices rectangulares son iguales
	// Compara la tabla impl�cita con "otra" (tabla expl�cita) 

	bool EsIgual (TablaRectangularReales otra_tabla)
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
	// Inserta una fila completa en una posici�n dada. 
	// La fila se porporciona en un objeto "SecuenciaEnteros".
	// 
	// Recibe: num_fila, la posici�n que ocupar� "fila_nueva" cuando se 
	//		 		inserte en la tabla.
	//		   fila_nueva, la secuencia que se va a insertar. Se trata 
	//				de un objeto de la clase "SecuenciaEnteros". 
	//
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	// PRE:  0 <= num_fila <= TotalUtilizados()
	//		 Si num_fila = 0, "nueva_fila" ser� la nueva primera fila. 
	//		 Si num_fila = TotalUtilizados(), "nueva_fila" ser� la nueva 
	//		 �ltima fila (el resultado ser� equivalente al de "Aniade()" 
	
	void Inserta (int num_fila, SecuenciaReales fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		// Comprobar precondiciones
		
		if ((filas_utilizadas < NUM_FILS) &&
			(numero_columnas_fila_nueva == cols_utilizadas) && 
			(0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones altas. 
			// La �ltima fila se copia en una NUEVA FILA que ocupa la 
			// posici�n "filas_utilizadas", la pen�ltima se copia en 
			// "filas_utilizadas"-1, ... y se queda un "hueco" en 
			// la fila "num_fila ".
			// NOTA: no se modifica (todav�a) "filas_utilizadas" 
			
			for (int fil=filas_utilizadas; fil>num_fila; fil--) {
				
				for (int col = 0; col < numero_columnas_fila_nueva; col++)
					matriz_privada[fil][col]=matriz_privada[fil-1][col];
			}
			
			// Copiar en el "hueco" (fila "num_fila") el contenido de 
			// la secuencia "fila_nueva"
			
			for (int col = 0; col < numero_columnas_fila_nueva; col++)
				matriz_privada[num_fila][col]=fila_nueva.Elemento(col);	
			
			filas_utilizadas++; // Actualizaci�n del tama�o de la tabla.
		}
	}

	/***********************************************************************/
	// Elimina una fila completa, dada una posici�n. 
	// 
	// Recibe: num_fila, la posici�n de la fila a eliminar.
	// PRE:  0 <= num_fila < TotalUtilizados()
	
	void Elimina (int num_fila)
	{		
		// Comprobar precondiciones
		
		if ((0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones bajas. 
			// En la posici�n "num_fila" se copia la que est� en la posici�n
			// siguiente ("num_fila"+1), en su lugar se copia que est� en 
			// "num_fila"+2, ... y en la posici�n "total_utilizados"-2 se 
			// copia la de "total_utilizados"-1. 
			
			for (int fil=num_fila; fil<filas_utilizadas-1; fil++) {
			
				int num_columnas = cols_utilizadas;
					
				for (int c=0; c<num_columnas; c++) 
					matriz_privada[fil][c]=matriz_privada[fil+1][c];
			}
			
			filas_utilizadas--; // Actualizaci�n del tama�o de la tabla.
		}
	}	

	/***********************************************************************/
	
	string ToString (string titulo)
	{
		string cad; 
		
		cad = "\n" + titulo + "\n"; 	
		cad = cad + "\n--------------------------------------\n"; 
		
		for (int fila=0; fila<filas_utilizadas; fila++) {
	
			SecuenciaReales la_secuencia = Fila(fila);
	
			cad = cad + la_secuencia.ToString() + "\n";
		}
		
		cad = cad + "--------------------------------------\n"; 
		cad = cad + "\n\n";
		
		return (cad);
		
	}
		
	/***********************************************************************/	

};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Tabla dentada de reales
//
// Representaci�n: matriz "cl�sica"

class TablaDentadaReales
{
	
private:

    static const int NUM_FILS = 50;  // Filas disponibles
    static const int NUM_COLS = 40;  // Columnas disponibles

    double matriz_privada[NUM_FILS][NUM_COLS];

    // PRE: 0 <= filas_utilizadas <= NUM_FILS

    int filas_utilizadas;

    // PRE: 0 <= num_cols_utilizadas[i] <= NUM_COLS
    //      para i=0,1,...,filas_utilizadas-1
    // N�mero de columnas ocupadas en cada fila

    int num_cols_utilizadas[NUM_FILS] = {0};

public:

	/***********************************************************************/
	// Constructor sin argumentos--> Crea matriz nula

	TablaDentadaReales (void) : filas_utilizadas(0) { }
	
	/***********************************************************************/
	// Constructor--> Recibe una secuencia de caracteres que ser� la primera 
	// fila de la tabla. 

	TablaDentadaReales (SecuenciaReales primera_fila)
		: filas_utilizadas(0)
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}
	
	/***********************************************************************/
	// M�todo de lectura: n�mero m�ximo de filas

	int CapacidadFilas (void)
	{
		return (NUM_FILS);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero m�ximo de columnas

	int CapacidadColumnas (void)
	{
		return (NUM_COLS);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero entero de filas usadas

	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero entero de columnas usadas en la fila "fila"
	// PRE: 0 <= fila < filas_utilizadas
	
	int ColumnasUtilizadas (int fila)
	{
		return (num_cols_utilizadas[fila]);
	}

	/*****************************************************************/
	// M�todo de lectura: devuelve el dato que ocupa la casilla 
	// de coordenadas (fila, columna)
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < num_cols_utilizadas[fila]	
	
	double Elemento (int fila, int columna)
	{
		return (matriz_privada[fila][columna]);
	}

	/***********************************************************************/
	// Devuelve true si la tabla est� vac�a

	bool EstaVacia (void) 
	{
		return (filas_utilizadas == 0);
	}
	
	/***********************************************************************/
	// "Vac�a" una tabla
	
	void EliminaTodos (void)
	{
		filas_utilizadas = 0;
	}
	
	/*****************************************************************/
	// Devuelve una fila completa (un objeto "SecuenciaReales")
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaReales Fila (int indice_fila)
	{
		SecuenciaReales la_fila;
				
		int num_columnas = num_cols_utilizadas[indice_fila];
			
		for (int c=0; c<num_columnas; c++) 
			la_fila.Aniade (matriz_privada[indice_fila][c]);
		
		return (la_fila);
	}

	/*****************************************************************/
	// A�ade una fila completa. La fila se porporciona en un objeto de 
	// la clase "SecuenciaCaracteres".
	// PRE:  fila_nueva.TotalUtilizados() <= NUM_COLS
	// PRE:  filas_utilizadas < NUM_FILS
	
	void Aniade (SecuenciaReales fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		if ((filas_utilizadas < NUM_FILS) &&
			(numero_columnas_fila_nueva <= NUM_COLS)) {

			for (int c=0; c<numero_columnas_fila_nueva; c++) 
				matriz_privada[filas_utilizadas][c] = fila_nueva.Elemento(c);

			num_cols_utilizadas[filas_utilizadas]=numero_columnas_fila_nueva;
			
			filas_utilizadas++;
		}
	}

	/*****************************************************************/
	// Calcula si dos matrices dentadas son iguales

	bool EsIgual (TablaDentadaReales otra_tabla)
	{
		bool son_iguales = true; 
		
		if (filas_utilizadas != otra_tabla.FilasUtilizadas())
			
			son_iguales = false;
		
		else {
			
			int f=0; 
			
			while (f<filas_utilizadas && son_iguales) {
				
				if (num_cols_utilizadas[f] != otra_tabla.ColumnasUtilizadas(f)) 
				
					son_iguales = false;	
				
				else {
					
					int c=0; 
					
					while (c<num_cols_utilizadas[f] && son_iguales) {
				
						if (matriz_privada[f][c] != otra_tabla.Elemento(f,c)) 
							son_iguales = false;
							
						c++;
						
					} // while c
		
					f++;
					
				} // else 
					
			} // while f
					
		} // else 
	
		return (son_iguales);
	}
	
	/*****************************************************************/
	// Inserta una fila completa en una posici�n dada. 
	// La fila se porporciona en un objeto "SecuenciaCaracteres".
	// 
	// Recibe: num_fila, la posici�n que ocupar� "fila_nueva" cuando se 
	//		 		inserte en la tabla.
	//		   fila_nueva, la secuencia que se va a insertar. Se trata 
	//				de un objeto de la clase SecuenciaCaracteres. 
	//
	// PRE:  fila_nueva.TotalUtilizados() <= NUM_COLS
	// PRE:  filas_utilizadas <= NUM_FILS
	// PRE:  0 <= num_fila <= TotalUtilizados()
	//		 Si num_fila = 0, "nueva_fila" ser� la nueva primera fila. 
	//		 Si num_fila = TotalUtilizados(), "nueva_fila" ser� la nueva 
	//		 �ltima fila (el resultado ser� equivalente al de "Aniade()" 
	
	void Inserta (int num_fila, SecuenciaReales fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		// Comprobar precondiciones
		
		if ((filas_utilizadas < NUM_FILS) &&
			(numero_columnas_fila_nueva <= NUM_COLS) &&
			(0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones altas. 
			// La �ltima fila se copia en una NUEVA FILA que ocupa la 
			// posici�n "filas_utilizadas", la pen�ltima se copia en 
			// "filas_utilizadas"-1, ... y se queda un "hueco" en 
			// la fila "num_fila ".
			// NOTA: no se modifica (todav�a) "filas_utilizadas" 
			
			for (int fil=filas_utilizadas; fil>num_fila; fil--) {	
			
				int num_columnas = num_cols_utilizadas[fil-1];
					
				for (int c=0; c<num_columnas; c++) 
					matriz_privada[fil][c] = matriz_privada[fil-1][c]; 
					
				num_cols_utilizadas[fil] = num_cols_utilizadas[fil-1];
			}
					
			// Copiar en el "hueco" (fila "num_fila") el contenido de 
			// la secuencia "fila_nueva"
			
			for (int c=0; c<numero_columnas_fila_nueva; c++) 
				matriz_privada[num_fila][c] = fila_nueva.Elemento(c);
			
			num_cols_utilizadas[num_fila] = numero_columnas_fila_nueva;
			
			filas_utilizadas++; // Actualizaci�n del tama�o de la tabla.
		}
	}

	/*****************************************************************/
	// Elimina una fila completa, dada una posici�n. 
	// 
	// Recibe: num_fila, la posici�n de la fila a eliminar.
	// PRE:  0 <= num_fila < TotalUtilizados()
	
	void Elimina (int num_fila)
	{		
		// Comprobar precondiciones
		
		if ((0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones bajas. 
			// En la posici�n "num_fila" se copia la que est� en la posici�n
			// siguiente ("num_fila"+1), en su lugar se copia que est� en 
			// "num_fila"+2, ... y en la posici�n "total_utilizados"-2 se 
			// copia la de "total_utilizados"-1. 
			
			for (int fil=num_fila; fil<filas_utilizadas-1; fil++) {
			
				int num_columnas = num_cols_utilizadas[fil+1];
					
				for (int c=0; c<num_columnas; c++) 
					matriz_privada[fil][c]=matriz_privada[fil+1][c];
					
				num_cols_utilizadas[fil] = num_cols_utilizadas[fil+1];
			}
			
			filas_utilizadas--; // Actualizaci�n del tama�o de la tabla.
		}
	}
		
	/*********************************************************************/
	// M�todo que devuelve una tabla rectangular de reales, a partir de una 
	// tabla dentada, de tal forma que dicha tabla rectangular ha de tener
	// el mismo n�mero de filas que la tabla dentada y un n�mero de colunas
	// igual al de la fila que menos tenga.
	
	TablaRectangularReales DevuelveTRR (void)
	{
		
		int numero_columnas_minimo_fila = num_cols_utilizadas[0];
		
		// B�squeda del n�mero m�nimo de columnas (se eval�a cada fila)
		
		for (int f = 1; f < filas_utilizadas; f++){
			
			if (num_cols_utilizadas[f] < numero_columnas_minimo_fila)
			
				numero_columnas_minimo_fila = num_cols_utilizadas[f];
				
		}
		
		// Una vez que ya tenemos el n�mero de columnas de la tabla 
		// rectangular, se procede a crear el objeto TablaRectangularReales
		// por medio del n�mero de columnas calculado y a rellenar dicha tabla.
		
		TablaRectangularReales tablilla (numero_columnas_minimo_fila);
		
		// Dado que tenemos un m�todo "Aniade" que a�ade una secuencia de 
		// reales, lo usar� para rellenar la tabla por medio de secuencias
		// de reales (cada elemento de la secuencia es un elemento de la matriz
		// del objeto impl�cito); las filas se ir�n guardando en la secuencia
		// de caracteres y se ir� a�adiendo a la matr�z que estamos creando.
		
		SecuenciaReales secuencia;
		
		for (int fr = 0; fr < filas_utilizadas; fr++){
		
			for (int cr = 0; cr < numero_columnas_minimo_fila; cr++){
				
				secuencia.Aniade(matriz_privada[fr][cr]);
				
			}
			
			tablilla.Aniade(secuencia);
			
			// Una vez que ya se haya a�adido una fila, se elimina la secuencia 
			// de reales para volver a rellenarse y seguir el proceso. Para 
			// ello se hace uso del m�todo "EliminaTodos()".
			
			secuencia.EliminaTodos();
			
		}
		
		return (tablilla);
		
	
	}
	
	/*********************************************************************/

	// Forma un string con el contenido de la tabla.  
	// La primera l�nea es el encabezamiento indicado en "titulo".
	
	string ToString (string titulo)
	{
		string cad; 
		
		cad = "\n" + titulo + "\n"; 	
		cad = cad + "\n--------------------------------------\n"; 
		
		for (int fila=0; fila<filas_utilizadas; fila++) {
	
			SecuenciaReales la_secuencia = Fila(fila);
	
			cad = cad + la_secuencia.ToString() + "\n";
		}
		
		cad = cad + "--------------------------------------\n"; 
		cad = cad + "\n\n";
		
		return (cad); 
	}
	
	/*****************************************************************/

};

///////////////////////////////////////////////////////////////////////
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
		
		// M�todo Set para fijar el campo "titulo"
		
		void SetTitulo (string cad)
		{
			titulo = cad;
		}
		
		/*********************************************************************/
		// Lee un dato int.
		// La lectura est� etiquetada con "titulo"
		// La lectura se efect�a repetidamente hasta que se introduce un valor
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
		// La lectura est� etiquetada con "titulo"
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
		// La lectura est� etiquetada con "titulo"
		
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
		// La lectura est� etiquetada con "titulo"
		// La lectura se efect�a repetidamente hasta que se introduce un valor
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
		// La lectura est� etiquetada con "titulo"
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
		// La lectura est� etiquetada con "titulo"
		
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
		// Devuelve una NUEVA cadena, resultante de eliminar los �ltimos
		// caracteres separadores de "cadena". Los caracteres separadores son
		// el espacio en blanco, el tabulador y el salto de l�nea.
		// Usaremos la funci�n isspace() para simplificar el c�lculo.
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: el resultado de eliminar los �ltimos separadores de 
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
		// el espacio en blanco, el tabulador y el salto de l�nea.
		// Usaremos la funci�n isspace() para simplificar el c�lculo.
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: el resultado de eliminar los �ltimos separadores de 
		// "cadena"
		/*********************************************************************/
		string EliminaPrimerosSeparadores (string cadena)
		{
			// Buscar el primer car�cter no espacio
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
		// �ltimos caracteres separadores de "cadena". Los caracteres 
		// separadores son el espacio en blanco, el tabulador y el salto de
		// l�nea
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: el resultado de eliminar los primeros y los �ltimos
		//           separadores de "cadena".
		/*********************************************************************/
		
		string EliminaPrimerosYUltimosSeparadores (string cadena)
		{
			string cadena_podada = EliminaPrimerosSeparadores (cadena);
			cadena_podada = EliminaUltimosSeparadores (cadena_podada);
			
			return (cadena_podada);
		}
		
		/*********************************************************************/
		// Devuelve "true" si "cadena" es la representaci�n textual de un
		// entero
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: "true" si "cadena" es la representaci�n textual de un int
		
		bool EsEntero (string cadena)
		{
			bool es_entero = true;
			
			cadena = EliminaPrimerosSeparadores (cadena);
			cadena = EliminaUltimosSeparadores (cadena);
			
			unsigned int long_cadena = cadena.length();
			
			if (long_cadena == 0) es_entero = false;
			else {
				
				// Si el primer car�cter es '+' � '-', perfecto. En ese caso
				// se pasa al siguiente car�cter (posici�n 19.
				
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
				
				// Si el primer car�cter es '+' � '-', perfecto. En ese caso
				// se pasa al siguiente car�cter (posici�n 19.
				
				unsigned int pos;
				if (cadena.at(0)=='-' || cadena.at(0) == '+') pos = 1;
				else pos = 0;
				
				// Bandera que se activa al encontrar un punto
				bool encontrado_un_punto = false;
				
				while ((pos < long_cadena) && es_real) {
					
					char c = cadena.at(pos);
					
					if (!isdigit(c)) {
						
						// Solo puede haber un punto.
						// Si se ha encontrado un punto y ya se hab�a
						// encontrado otro, error. Si no, activar la bandera
						// "encontrado_un_punto" (ya no puede haber m�s).
						
						if (c == '.') {
							if (encontrado_un_punto) es_real = false;
							else encontrado_un_punto = true;
						}
						
					    // Si no es un punto ni un d�gito --> error
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
	
	//Declaraci�n de datos
	
	Lector lee;
	
	TablaDentadaReales tabla_dentada;
	
	int numero_filas;
	int columnas_cada_fila;
	
	// Entrada de datos
	
	lee.SetTitulo("Introduzca el numero de filas que tiene la matriz: ");
	numero_filas = lee.LeeEnteroEnRango(1,tabla_dentada.CapacidadFilas());
	
	for (int f = 0; f < numero_filas; f++){
		
		cout << endl;
		
		lee.SetTitulo("Introduzca el numero de columnas de la fila " 
		              + to_string(f) + ": ");
		              
		columnas_cada_fila = lee.LeeEnteroEnRango(1, 
		                     tabla_dentada.CapacidadColumnas());
		                     
		// Una vez definida la tabla, se rellena, mediante secuencias de
		// n�meros reales
		
		SecuenciaReales rellenador;
		
		lee.SetTitulo("Introduzca un elemento: ");
		
		cout << endl;
		
		for (int i =0; i < columnas_cada_fila; i++){
			
			rellenador.Aniade(lee.LeeReal());
		}
		
		tabla_dentada.Aniade(rellenador);
	}
	
	// A continuaci�n se muestra en pantalla la tabla dentada
	
	cout <<	tabla_dentada.ToString("Matriz dentada");
	
	// C�lculo de la tabla rectangular de reales a partir de la dentada:
	
	cout << tabla_dentada.DevuelveTRR().ToString("Matriz rectangular a partir "
	                                             "de la dentada");
	
	return 0;
}
		
		                     
	
	
	
		
		
		
