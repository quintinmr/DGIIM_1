/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que recibe los datos correspondientes a una tabla dentada de números
   reales (número de filas, número de columnas de cada fila, y los elementos de
   de cada una de las filas que constituyen la tabla); todos estos datos que 
   dan forma a la tabla se han de introducir en una sola línea, de la siguiente
   forma: 
   	nºfilas  nº columnas fila 0  elementos fila 0  nºcolumnas fila 1 
   	elementos fila 1,  y así sucesivamente...
   	
   Una vez definida la tabla dentada se lleva a cabo la suma de los elementos
   de cada una de las filas y se devuelven dichas sumas en una sola secuencia
   de reales.
   Para ello, se ha hecho uso de la clase SecuenciReales, y de la clase
   TablaDentadaReales, que se ha implementado un método para el cálculo
   y devolución de la suma de los elementos de cada una de las filas.
   
   Se ha seguido el procedimiento: TABLA DENTADA - SECUENCIA DE SECUENCIAS.
   
       
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
	// Método de lectura: número real de columnas usadas en la fila "fila"
	// PRE: 0 <= fila < filas_utilizadas
	
	int ColumnasUtilizadas (int fila)
	{
		return (num_cols_utilizadas[fila]);
	}
	
	/*****************************************************************/

	// Devuelve true si la tabla está vacía

	bool EstaVacia (void) 
	{
		return (filas_utilizadas == 0);
	}
	
	/***********************************************************************/
	
	// "Vacía" una tabla
	
	void EliminaTodos (void)
	{
		filas_utilizadas = 0;
	}
	
	/*****************************************************************/
	// Devuelve el dato que ocupa la casilla de coordenadas (fila, columna)
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < num_cols_utilizadas[fila]	
	
	char Elemento (int fila, int columna)
	{
		return (vector_privado[fila].Elemento(columna));
	}

	/***********************************************************************/
	
	// Devuelve una fila completa (un objeto "SecuenciaReales")
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaReales Fila (int indice_fila)
	{
		SecuenciaReales la_fila;
				
		int num_columnas = num_cols_utilizadas[indice_fila];
			
		for (int c = 0; c < num_columnas; c++) 
			la_fila.Aniade(vector_privado[indice_fila].Elemento(c));
		
		return la_fila;
	}

	/*****************************************************************/
	
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
				
				if (num_cols_utilizadas[f]!=otra_tabla.ColumnasUtilizadas(f)) 
				
					son_iguales = false;	
				
				else {
					
					int c = 0; 
					
					while (c < num_cols_utilizadas[f] && son_iguales) {
				
						if (Elemento(f,c) != otra_tabla.Elemento(f,c)) 
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
	
	// Inserta una fila completa en una posición dada. 
	// La fila se porporciona en un objeto "SecuenciaReales".
	// 
	// Recibe: num_fila, la posición que ocupará "fila_nueva" cuando se 
	//		 		inserte en la tabla.
	//		   fila_nueva, la secuencia que se va a insertar. Se trata 
	//				de un objeto de la clase SecuenciaReales. 
	//
	// PRE:  fila_nueva.TotalUtilizados() <= NUM_COLS
	// PRE:  filas_utilizadas <= NUM_FILS
	// PRE:  0 <= num_fila <= TotalUtilizados()
	//		 Si num_fila = 0, "nueva_fila" será la nueva primera fila. 
	//		 Si num_fila = TotalUtilizados(), "nueva_fila" será la nueva 
	//		 última fila (el resultado será equivalente al de "Aniade()" 
	
	void Inserta (int num_fila, SecuenciaReales fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		// Comprobar precondiciones
		
		if ((filas_utilizadas < MAX_FIL) &&
			(numero_columnas_fila_nueva <= MAX_COL) &&
			(0 <= num_fila) && (num_fila <= filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones altas. 
			// La última fila se copia en una NUEVA FILA que ocupa la 
			// posición "filas_utilizadas", la penúltima se copia en 
			// "filas_utilizadas"-1, ... y se queda un "hueco" en 
			// la fila "num_fila ".
			// NOTA: no se modifica (todavía) "filas_utilizadas" 
			
			for (int fil = filas_utilizadas; fil > num_fila; fil--) {	
			
				vector_privado[fil] = vector_privado[fil-1]; 
					
				num_cols_utilizadas[fil] = num_cols_utilizadas[fil-1];
			}
					
			// Copiar en el "hueco" (fila "num_fila") el contenido de 
			// la secuencia "fila_nueva"
			
			for (int c = 0; c < numero_columnas_fila_nueva; c++) 
				vector_privado[num_fila] = fila_nueva;
			
			num_cols_utilizadas[num_fila] = numero_columnas_fila_nueva;
			
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
		
		if ((0 <= num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones bajas. 
			// En la posición "num_fila" se copia la que está en la posición
			// siguiente ("num_fila"+1), en su lugar se copia que está en 
			// "num_fila"+2, ... y en la posición "total_utilizados"-2 se 
			// copia la de "total_utilizados"-1. 
			
			for (int fil = num_fila; fil < filas_utilizadas-1; fil++) {
					
				vector_privado[fil] = vector_privado[fil+1];
					
				num_cols_utilizadas[fil] = num_cols_utilizadas[fil+1];
			}
			
			filas_utilizadas--; // Actualización del tamaño de la tabla.
		}
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
	// Método que devuelve una secuencia de reales en la que están guardadas
	// las sumas de los elementos de las filas de una tabla dentada de reales.
	
	SecuenciaReales SumaFilas (void)
	{
		
		SecuenciaReales suma;
		
		// Se van evaluando cada una de las filas de la tabla y se incializa
		// logicamente la suma de los elementos de las filas a cero, para
		// a continuación recorrer cada una de las columnas de cada fila de la
		// tabla, y sumar cada uno de sus elementos.
		
		for (int f = 0; f < filas_utilizadas; f++) {
			
			double suma_filas = 0;
			
			for (int c = 0; c < num_cols_utilizadas[f]; c++)
				suma_filas = suma_filas + vector_privado[f].Elemento(c);
				
			suma.Aniade(suma_filas);
		}
		
		return (suma);
	}
	
	/*****************************************************************/
	
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////

int main ()
{
	
	// Declaración de datos
	
	// Declaración del ojeto de la clase TablaDentadaReales
	
	TablaDentadaReales tabla_dentada;
	
	// Delcaración del objeto de la clase SecuenciaReales en la que se 
	// guardan las filas
	
	SecuenciaReales fila;
	
	int filas;
	int columnas;
	double elementos;
	
	// Entrada de datos
	
	cout << "SUMA FILAS TABLA DENTADA REALES MATRIZ";
	cout << endl << endl;
	cout << "ATENCION: ";
	cout << endl;
	cout << "Introduzca los datos correspondientes a la matriz dentada en el"
	     << " siguiente orden, en una sola linea y cada dato separado por un"
		 << " espacio: ";
	cout << endl;
	cout << "\tNº filas de la matriz "    << endl;
	cout << "\tNº columnas de la fila 0 " << endl;
	cout << "\tElementos de la fila 0 "   << endl;
	cout << "\tNº columnas de la fila 1 " << endl;
	cout << "\tElementos de la fila 1 "   << endl;
	cout << "Y ASI SUCESIVAMENTE"         << endl;  
	cout << endl;
	
	
	cin >> filas;
	
	for (int i = 0; i < filas; i++){
		
		cin >> columnas;
		
		for (int j = 0; j < columnas; j++){
			
			cin >> elementos;
			fila.Aniade(elementos);
		}
		
		tabla_dentada.Aniade(fila);
		
		fila.EliminaTodos();
	}	
	
	// MOSTRAR MATRIZ
	
	cout << tabla_dentada.ToString("Matriz dentada de reales: ");
	
	cout << endl;
	
	// Cálculos y salida de datos
	
	cout << "La suma de los elementos de las filas son: "
	     << tabla_dentada.SumaFilas().ToString();
	     
	
	return 0;
	
}
		
           
