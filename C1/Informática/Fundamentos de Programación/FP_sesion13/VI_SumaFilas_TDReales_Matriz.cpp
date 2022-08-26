/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que recibe los datos correspondientes a una tabla dentada de n�meros
   reales (n�mero de filas, n�mero de columnas de cada fila, y los elementos de
   de cada una de las filas que constituyen la tabla); todos estos datos que 
   dan forma a la tabla se han de introducir en una sola l�nea, de la siguiente
   forma: 
   	n�filas  n� columnas fila 0  elementos fila 0  n�columnas fila 1 
   	elementos fila 1,  y as� sucesivamente...
   	
   Una vez definida la tabla dentada se lleva a cabo la suma de los elementos
   de cada una de las filas y se devuelven dichas sumas en una sola secuencia
   de reales.
   Para ello, se ha hecho uso de la clase SecuenciReales, y de la clase
   TablaDentadaReales, en la que se ha implementado un m�todo para el c�lculo
   y devoluci�n de la suma de los elementos de cada una de las filas.
   
   Se ha seguido el procedimiento TABLA DENTADA - MATRIZ CL�SICA	
   
       
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;  
 
/******************************************************************************/
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

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
        	if (total_utilizados < TAMANIO){
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
			cadena = cadena + to_string(vector_privado[i]) + " ";

		return (cadena);
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
    // para i=0,1,...,filas_utilizadas-1
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
	// M�todo de lectura: n�mero real de filas usadas

	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero real de columnas usadas en la fila "fila"
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
	// Devuelve una fila completa (un objeto "SecuenciaCaracteres")
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
	// la clase "SecuenciaReales".
	// PRE:  fila_nueva.TotalUtilizados() <= NUM_COLS
	// PRE:  filas_utilizadas < NUM_FILS
	
	void Aniade (SecuenciaReales fila_nueva)
		{
			int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
			if ((filas_utilizadas < NUM_FILS) &&
				(numero_columnas_fila_nueva <= NUM_COLS)) {
				
				// El n�mero de columnas de la nueva fila se guarda en el 
				// vector que almacena el n�mero de columnas de cada fila
					
				num_cols_utilizadas[filas_utilizadas] =
				numero_columnas_fila_nueva;

				for (int col = 0; col < numero_columnas_fila_nueva; col++){
					
					matriz_privada[filas_utilizadas][col]=
					fila_nueva.Elemento(col);
				}

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
	// La fila se porporciona en un objeto "SecuenciaReales".
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
	// Forma un string con el contenido de la tabla.  
	// La primera l�nea es el encabezamiento indicado en "titulo".
	
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
	// M�todo que devuelve una secuencia de reales en la que est�n guardadas
	// las sumas de los elementos de las filas de una tabla dentada de reales.
	
	SecuenciaReales SumaFilas (void)
	{
		
		SecuenciaReales suma;
		
		// Se van evaluando cada una de las filas de la tabla y se incializa
		// logicamente la suma de los elementos de las filas a cero, para
		// a continuaci�n recorrer cada una de las columnas de cada fila de la
		// tabla, y sumar cada uno de sus elementos.
		
		for (int f = 0; f < filas_utilizadas; f++) {
			
			double suma_filas = 0;
			
			for (int c = 0; c < num_cols_utilizadas[f]; c++)
				suma_filas = suma_filas + matriz_privada[f][c];
			
			// La suma se va a�adiendo a la secuencia de reales que se va a 
			// devolver.
				
			suma.Aniade(suma_filas);
		}
		
		return (suma);
	}
	
	/*****************************************************************/	

};

///////////////////////////////////////////////////////////////////////

int main ()
{
	
	// Declaraci�n de datos
	
	int filas;
	int columnas;
	double elementos;
	
	// Declaraci�n del ojeto de la clase TablaDentadaReales
	
	TablaDentadaReales tabla_dentada;
	
	// Delcaraci�n del objeto de la clase SecuenciaReales en la que se 
	// guardan las filas
	
	SecuenciaReales fila;
	
	
	// Entrada de datos
	
	cout <<"SUMA DE LOS ELEMENTOS DE LAS FILAS DE UNA TABLA DENTADA DE REALES ";
	cout << endl << endl;
	cout << "ATENCION: ";
	cout << endl;
	cout << "Introduzca los datos correspondientes a la matriz dentada en el"
	     << " siguiente orden, en una sola linea y cada dato separado por un"
		 << " espacio: ";
	cout << endl;
	cout << "\tN� filas de la matriz "    << endl;
	cout << "\tN� columnas de la fila 0 " << endl;
	cout << "\tElementos de la fila 0 "   << endl;
	cout << "\tN� columnas de la fila 1 " << endl;
	cout << "\tElementos de la fila 1 "   << endl;
	cout << "Y ASI SUCESIVAMENTE"         << endl;  
	cout << endl << endl;
	
	
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
	
	// C�lculos y salida de datos
	
	cout << "La suma de los elementos de las filas es: "
	     << tabla_dentada.SumaFilas().ToString();
	     
	
	return 0;
	
}
		
            
