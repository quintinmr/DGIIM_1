/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que crea una tabla rectangular de números reales y la muestra en
   pantalla, a partir de una tabla dentada de números reales. Dicha tabla
   rectangular, tiene el mismo número de filas que la taBla dentada introducida
   por el usuario, y, en cuanto al número de columnas, será el correspondiente
   al de la fila que menos tenga. Para ello, se ha implementado un método
   en la clase TablaDentadaReales, que devuelve un objeto de la clase 
   TablaRectangularReales. Además, se ha hecho uso de las clases, Lector 
   (para leer datos enteros y reales en el main) y la clase SecuenciaReales
   que se usa de forma muy recurrente en las clases de las tablas.

   Entradas:
    El número de filas de la tabla dentada, el número de columnas de cada
    una de esas filas, y los elementos que rellenan la matriz.
   
   Salidas:
    Una tabla rectangular a partir de la tabla dentada introducida por el
    usuario.
    
    Se ha seguido el procedimiento:
	 
	  TABLA DENTADA REALES --> TABLA RECTANGULAR REALES   -   SECUENCIA DE 
	  SECUENCIAS
   
       
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;  
 
/******************************************************************************/
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
	// Constructor con argumento string
	// Recibe: la_palabra, dato string que se usa para iniciar el objeto.
	// Si "la_palabra" tiene más caracteres que caben en el objeto, no se
	// copia nada y se crea un objeto vacío.
	//
	// PRE: "la_palabra" está formada por una única palabra

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
	// "Limpia" completamente una secuencia

	string ToString (void)
	{
		string cadena;
		
		for (int i=0; i<total_utilizados; i++)
		
			cadena = cadena + " " + to_string(vector_privado[i]);

		return (cadena);
	}

	/***********************************************************************/
	/***********************************************************************/
	// Compara dos secuencias
	
	bool EsIgual (SecuenciaReales otra_secuencia) 
	{
		bool son_iguales = true; 
		
		if (total_utilizados != otra_secuencia.total_utilizados)
		
			son_iguales = false;
		
		else {
				
			bool sigo = true;
			int pos = 0;
			
			while (sigo && (pos < total_utilizados)) {
	
				if (vector_privado[pos]!=otra_secuencia.vector_privado[pos]) {
					sigo = false;
					son_iguales = false;
				}
				else
					pos++; 
			} // while (sigo && pos < total_utilizados) 
		}
			
		return (son_iguales);
	}
	
	/***********************************************************************/

};


/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// Tabla rectangular de reales

class TablaRectangularReales
{

private:

    static const int MAX_FIL = 50; // "filas" disponibles
    static const int MAX_COL = 40;

    SecuenciaReales vector_privado[MAX_FIL];

    // PRE: 0 <= filas_utilizadas <= MAX_FIL
    // PRE: 0 <= cols_utilizadas <= MAX_COL
    
    int filas_utilizadas;
    int cols_utilizadas;

public:
	
	
	/***********************************************************************/
	// Constructor sin argumentos--> Crea matriz nula

	TablaRectangularReales(void): filas_utilizadas(0),cols_utilizadas(0) { }

	/***********************************************************************/
	// Constructor--> Recibe "numero_de_columnas" que indica el número de 
	// columnas que deben tener TODAS las filas. 
	// PRE: numero_de_columnas <= MAX_COL


	TablaRectangularReales (int numero_de_columnas)
		: filas_utilizadas(0), cols_utilizadas(numero_de_columnas)
	{ }

	/***********************************************************************/
	// Constructor--> Recibe una secuencia de reales.  El número de 
	// elementos de la secuencia es el valor que se usa como "col_utilizadas"
	// PRE: primera_fila.TotalUtilizados() <= MAX_COL

	TablaRectangularReales (SecuenciaReales primera_fila)
		: filas_utilizadas(0), cols_utilizadas (primera_fila.TotalUtilizados())
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}

	/***********************************************************************/
	// Método de lectura: número máximo de filas

	int CapacidadFilas (void)
	{
		return (MAX_FIL);
	}

	/*****************************************************************/
	// Método de lectura: número máximo de columnas

	int CapacidadColumnas (void)
	{
		return (MAX_COL);
	}

	/*****************************************************************/
	// Método de lectura: número real de filas usadas

	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}

	/*****************************************************************/
	// Método de lectura: número real de columnas usadas

	int ColumnasUtilizadas (void)
	{
		return (cols_utilizadas);
	}

	/*****************************************************************/
	// Método de lectura: devuelve el dato que ocupa la casilla 
	// de coordenadas (fila, columna)
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < cols_utilizadas	
	
	double Elemento (int fila, int columna)
	{
		return ((vector_privado[fila]).Elemento(columna));
	}

	/*****************************************************************/
	// Devuelve una fila completa (un objeto "SecuenciaReales")
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaReales Fila (int indice_fila)
	{
		return (vector_privado[indice_fila]);
	}

	/*****************************************************************/
	// Devuelve una columna completa (un objeto "SecuenciaReales")
	// PRE: 0 <= indice_columna < cols_utilizadas
	
	SecuenciaReales Columna (int indice_columna)
	{
		SecuenciaReales columna;

		for (int fil=0; fil<filas_utilizadas; fil++)
			columna.Aniade ((vector_privado[fil]).Elemento(indice_columna));

		return (columna);
	}

	/***********************************************************************/
	// Añade una fila completa (un objeto "SecuenciaReales")
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	
	void Aniade (SecuenciaReales fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		if ((filas_utilizadas < MAX_FIL) && 
			(numero_columnas_fila_nueva == cols_utilizadas)) {

			vector_privado[filas_utilizadas] = fila_nueva;

			filas_utilizadas++;
		}
	}


	/***********************************************************************/
	// "Vacía" una tabla

	void EliminaTodos (void)
	{
		filas_utilizadas = 0;
	}
	
	/*****************************************************************/
	// Calcula si dos matrices rectangulares son iguales
	// Compara la tabla implícita con "otra" (tabla explícita) 

	bool EsIgual (TablaRectangularReales otra)
	{
		bool son_iguales = true; 
		
		if ((filas_utilizadas != otra.FilasUtilizadas()) ||  
			 (cols_utilizadas != otra.ColumnasUtilizadas()))		
			
			son_iguales = false;
		
		else {
			
			// Recorrido por filas 
	
			int fil = 0;
			
			while (fil < filas_utilizadas && !son_iguales) {
	
				SecuenciaReales una_fila = Fila (fil);
				SecuenciaReales otra_fila = otra.Fila (fil);	
				
				if (una_fila.EsIgual(otra_fila))
					fil++;
				else
					son_iguales = false;
					
			} // while fil
					
		} // else 
	
		return (son_iguales);
	}
	
	/***********************************************************************/
	// Devuelve la traspuesta de la matriz (si es posible calcularse)
	// PRE: filas_utilizadas <= MAX_COL
	// PRE: cols_utilizadas  <= MAX_FIL
	// Si no se puede calcular la traspuesta se devuelve una matriz nula. 
	
	TablaRectangularReales Traspuesta (void)
	{
	    TablaRectangularReales traspuesta; // Inicialmente vacía
			    
		if ((filas_utilizadas <= MAX_COL) && (cols_utilizadas <= MAX_FIL)) {
		
			// La traspuesta tiene tantas filas como columnas tiene la 
			// matriz original

			TablaRectangularReales solucion (filas_utilizadas);


			SecuenciaReales columna; // Las filas de "traspuesta" serán las 
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
			
					if (Elemento(f,c) != Elemento(c,f)) 
						es_simetrica = false;
						
					c++;
					
				} // while c
	
				f++;
					
			} // while f
			
		} // if (es_simetrica)
		
		return (es_simetrica);
	}
	
	
	/*****************************************************************/
	// Inserta una fila completa en una posición dada. 
	// La fila se porporciona en un objeto "SecuenciaReales".
	// 
	// Recibe: num_fila, la posición que ocupará "fila_nueva" cuando se 
	//		 		inserte en la tabla.
	//		   fila_nueva, la secuencia que se va a insertar. Se trata 
	//				de un objeto de la clase SecuenciaReales. 
	//
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	// PRE:  0 <= num_fila <= TotalUtilizados()
	//		 Si num_fila = 0, "nueva_fila" será la nueva primera fila. 
	//		 Si num_fila = TotalUtilizados(), "nueva_fila" será la nueva 
	//		 última fila (el resultado será equivalente al de "Aniade()" 
	
	void Inserta (int num_fila, SecuenciaReales fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		// Comprobar precondiciones
		
		if ((filas_utilizadas < MAX_FIL) && 
			(numero_columnas_fila_nueva == cols_utilizadas) && 
			(0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones altas. 
			// La última fila se copia en una NUEVA FILA que ocupa la 
			// posición "filas_utilizadas", la penúltima se copia en 
			// "filas_utilizadas"-1, ... y se queda un "hueco" en 
			// la fila "num_fila ".
			// NOTA: no se modifica (todavía) "filas_utilizadas" 
			
			for (int fil=filas_utilizadas; fil>num_fila; fil--) 			
				vector_privado[fil]=vector_privado[fil-1];
			
			// Copiar en el "hueco" (fila "num_fila") el contenido de 
			// la secuencia "fila_nueva"
			
			vector_privado[num_fila]=fila_nueva;	
			
			filas_utilizadas++; // Actualización del tamaño de la tabla.
		}
	}

	/*****************************************************************/
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
			
			for (int fil=num_fila; fil<filas_utilizadas-1; fil++) 
				vector_privado[fil]=vector_privado[fil+1];
			
			filas_utilizadas--; // Actualización del tamaño de la tabla.
		}
	}
	
	/*****************************************************************/
	// Devuelve true si la tabla está vacía

	bool EstaVacia (void) 
	{
		return (filas_utilizadas == 0);
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
			
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class TablaDentadaReales
{
	
private:
		
	static const int MAX_FIL = 50; 
    static const int MAX_COL = 40;

    SecuenciaReales vector_privado[MAX_FIL];

    // PRE: 0 <= filas_utilizadas <= MAX_FIL
    // PRE: 0 <= cols_utilizadas <= MAX_COL
    
    int filas_utilizadas;
    	
    // PRE: 0 <= num_cols_utilizadas[i] <= MAX_COL
	//     para i = 0,1,...,filas_utilizadas-1
	// Número de columnas ocupadas en cada fila
		
	int num_cols_utilizadas[MAX_FIL] = {0};
	
		
public:
		
	// Constructor sin argumentos
		
	TablaDentadaReales (void)
	: filas_utilizadas(0)
		
	{}
		
	// Recibe "primera_fila" (una secuencia de reales)
	// PRE: primera_fila.TotalUtilizados() <= MAX_COL
		
	TablaDentadaReales (SecuenciaReales primera_fila)
	: filas_utilizadas(0)
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}
		
	/*******************************************************************/
	// Método de lectura: número máximo de filas

	int CapacidadFilas (void)
	{
			return (MAX_FIL);
	}	

	/*******************************************************************/
	// Método de lectura: número máximo de columnas

	int CapacidadColumnas (void)
	{
		return (MAX_COL);
	}

	/*******************************************************************/
	// Método de lectura: número real de filas usadas

	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}
	/*****************************************************************/
	// Devuelve una fila completa (un objeto "SecuenciaReales")
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaReales Fila (int indice_fila)
	{
		return (vector_privado[indice_fila]);
	}

	/*****************************************************************/
	// Devuelve una columna completa (un objeto "SecuenciaReales")
	// PRE: 0 <= indice_columna < cols_utilizadas
	
	SecuenciaReales Columna (int indice_columna)
	{
		SecuenciaReales columna;

		for (int fil=0; fil<filas_utilizadas; fil++)
			columna.Aniade ((vector_privado[fil]).Elemento(indice_columna));

		return (columna);
	}
	
	/*******************************************************************/
	// Añade una fila completa (un objeto "SecuenciaReales")
	// PRE:  filas_utilizadas < NUM_FILS
	// PRE:  fila_nueva.TotalUtilizados() <= NUM_COLS
	
	void Aniade (SecuenciaReales fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		if ((filas_utilizadas < MAX_FIL) &&
			(numero_columnas_fila_nueva <= MAX_COL)) {
				
			// El número de columnas de la nueva fila se guarda en el 
			// vector que almacena el número de columnas de cada fila
					
			num_cols_utilizadas[filas_utilizadas] =
			numero_columnas_fila_nueva;

			vector_privado[filas_utilizadas] = fila_nueva;

			filas_utilizadas++;
			
			}
	}
	
	/*********************************************************************/
	// Método que devuelve una tabla rectangular de reales, a partir de una 
	// tabla dentada, de tal forma que dicha tabla rectangular ha de tener
	// el mismo número de filas que la tabla dentada y un número de colunas
	// igual al de la fila que menos tenga.
	
	TablaRectangularReales DevuelveTRR (void)
	{
		
		int numero_columnas_minimo_fila = num_cols_utilizadas[0];
		
		// Búsqueda del número mínimo de columnas (se evalúa cada fila)
		
		for (int f = 1; f < filas_utilizadas; f++){
			
			if (num_cols_utilizadas[f] < numero_columnas_minimo_fila)
			
				numero_columnas_minimo_fila = num_cols_utilizadas[f];
				
		}
		
		// Una vez que ya tenemos el número de columnas de la tabla 
		// rectangular, se procede a crear el objeto TablaRectangularReales
		// por medio del número de columnas calculado y a rellenar dicha tabla.
		
		TablaRectangularReales tablilla (numero_columnas_minimo_fila);
		
		// Dado que tenemos un método "Aniade" que añade una secuencia de 
		// reales, lo usaré para rellenar la tabla por medio de secuencias
		// de reales (cada elemento de la secuencia es un elemento de la matriz
		// del objeto implícito); las filas se irán guardando en la secuencia
		// de caracteres y se irá añadiendo a la matríz que estamos creando.
		
		SecuenciaReales secuencia;
		
		for (int fr = 0; fr < filas_utilizadas; fr++){
		
			for (int cr = 0; cr < numero_columnas_minimo_fila; cr++){
				
				secuencia.Aniade(vector_privado[fr].Elemento(cr));
				
			}
			
			tablilla.Aniade(secuencia);
			
			// Una vez que ya se haya añadido una fila, se elimina la secuencia 
			// de reales para volver a rellenarse y seguir el proceso. Para 
			// ello se hace uso del método "EliminaTodos()".
			
			secuencia.EliminaTodos();
			
		}
		
		return (tablilla);
		
	
	}

	/*********************************************************************/

	// Forma un string con el contenido de la tabla.  
	// La primera línea es el encabezamiento indicado en "titulo".
	
	string ToString (string titulo)
	{
		string cad; 
		
		cad = "\n" + titulo + "\n"; 	
		cad = cad + "\n--------------------------------------\n"; 
		
		for (int fila=0; fila<filas_utilizadas; fila++) {
	 
			SecuenciaReales la_secuencia = Fila(fila); ;
			cad = cad + la_secuencia.ToString() + "\n";
		}
		
		cad = cad + "--------------------------------------\n"; 
		cad = cad + "\n\n";
		
		return (cad); 
	}
	
	/*****************************************************************/
		
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
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

/***************************************************************************/

int main ()
{

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
		// números reales
		
		SecuenciaReales rellenador;
		
		lee.SetTitulo("Introduzca un elemento: ");
		
		cout << endl;
		
		for (int i =0; i < columnas_cada_fila; i++){
			
			rellenador.Aniade(lee.LeeReal());
		}
		
		tabla_dentada.Aniade(rellenador);
	}
	
	// A continuación se muestra en pantalla la tabla dentada
	
	cout <<	tabla_dentada.ToString("Matriz dentada");
	
	// Cálculo de la tabla rectangular de reales a partir de la dentada:
	
	cout << tabla_dentada.DevuelveTRR().ToString("Matriz "
	        "rectangular a partir de la dentada");
	
	return 0;
}
		
	
