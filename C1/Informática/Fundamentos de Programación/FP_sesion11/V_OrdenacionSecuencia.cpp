/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa en el que se trabaja sobre la clase SecuenciaEnteros, a la que se 
   le han a�adido cuatro m�todos, en los que se han implementado los cuatro
   m�todos de ordenaci�n vistos en clase: 
   	1) Ordenaci�n por selecci�n
   	2) Ordenaci�n por inserci�n
   	3) Ordenaci�n por intercambio
   	4) Ordenaci�n por intercambio, mejorado.
   	
   El programa genera aleatoriamente una secuencia de n�meros (para ello se
   hace uso de la clase GeneradorAleatoriosEnteros), y los ordena mediante
   los cuatro m�todos de ordenaci�n citados anteriormente. Adem�s muestra 
   el tiempo, en milisegundos, que ha tardado el programa en ordenar los n�meros
   mediante cada m�todo de ordenaci�n (para ello se hace uso de los m�todos
   de la clase cron�metro).
    
*/               
/******************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <chrono>
#include <random>
using namespace std;


////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
	
class Cronometro
{
	
private:
	
   typedef std::chrono::time_point<std::chrono::steady_clock>
           Punto_en_el_Tiempo;
   typedef chrono::duration <double, nano> IntervaloTiempo;

   Punto_en_el_Tiempo inicio;
   Punto_en_el_Tiempo final;

public:
	
	/***********************************************************************/
	void Reset() { 
		inicio = chrono::steady_clock::now();
	}
	
	/************************************************************************/
	double NanoSegundosTranscurridos() {
		final = chrono::steady_clock::now();		
		IntervaloTiempo diferencia = final - inicio;
		return (diferencia.count());
	}
	
	/************************************************************************/
	double MiliSegundosTranscurridos() {
		final = chrono::steady_clock::now();		
		IntervaloTiempo diferencia = final - inicio;
		return (diferencia.count()/1e6);
	}
	/************************************************************************/  
};

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

class GeneradorAleatorioEnteros
{  
private:
	
	mt19937 generador_mersenne;    // Mersenne twister
	uniform_int_distribution<int>  distribucion_uniforme;
	
	/************************************************************************/
	
	long long Nanosec(){
		return (chrono::high_resolution_clock::now().time_since_epoch().count());
	}
	
	/************************************************************************/ 
	
public:
	
	/************************************************************************/
		
	GeneradorAleatorioEnteros() : GeneradorAleatorioEnteros(0, 1) 
	{ }
	
	/************************************************************************/  
	GeneradorAleatorioEnteros(int min, int max) {
	
		const int A_DESCARTAR = 70000;
		// ACM TOMS Volume 32 Issue 1, March 2006
		
		auto semilla = Nanosec();
		generador_mersenne.seed(semilla);
		generador_mersenne.discard(A_DESCARTAR);
		distribucion_uniforme = uniform_int_distribution<int> (min, max);
	}
	
	/************************************************************************/
	
	int Siguiente(){
	  return (distribucion_uniforme(generador_mersenne));
	}
	
	/************************************************************************/

};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////


class SecuenciaEnteros {

private:

    static const int TAMANIO = 10000; // N�m.casillas disponibles
    int vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<=TAMANIO

    int total_utilizados; // N�m.casillas ocupadas

public:

    /***********************************************************************/
    // Constructor sin argumentos

    SecuenciaEnteros (void) : total_utilizados (0)
    {}

    /***********************************************************************/
    // Devuelve el n�mero de casillas ocupadas

    int TotalUtilizados (void)
    {
        return (total_utilizados);
    }

    /***********************************************************************/
    // Devuelve el n�mero de casillas disponibles

    int Capacidad (void)
    {
        return (TAMANIO);
    }

    /***********************************************************************/
    // A�ade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // 		La adici�n se realiza si hay alguna casilla disponible.
    // 		El nuevo elemento se coloca al final del vector.
    // 		Si no hay espacio, no se hace nada.

    void Aniade (int nuevo)
    {
        if (total_utilizados < TAMANIO){
            vector_privado[total_utilizados] = nuevo;
            total_utilizados++;
        }
    }

    /***********************************************************************/
    // Devuelve el elemento de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados

    int Elemento (int indice)
    {
        return (vector_privado[indice]);
    }

    /***********************************************************************/
    // Eliminar el car�cter de la posici�n dada por "indice".
    // Realiza un borrado f�sico (desplazamiento y sustituci�n).
    // PRE: 0 <= indice < total_utilizados

    void Elimina (int indice)
    {
        if ((indice >= 0) && (indice < total_utilizados)) {

            int tope = total_utilizados-1; // posic. del �ltimo

            for (int i = indice ; i < tope ; i++)
                vector_privado[i] = vector_privado[i+1];

            total_utilizados--;
        }
    }

    /***********************************************************************/
    // M�todo que se encarga de eliminar los elementos de la secuencia.
    
    void EliminaSecuencia(void)
    {
    	total_utilizados = 0;
    	
    }
    
    /***********************************************************************/
    
    // Compone un string con todos los caracteres que est�n
    // almacenados en la secuencia y lo devuelve.

    string ToString()
    {
        string cadena;

        for (int i=0; i<total_utilizados; i++)
            cadena = cadena + to_string(vector_privado[i]);

        return (cadena);
    }

	/***********************************************************************/
	
	/* PRIMER M�TODO DE ORDENACI�N: ORDENACI�N POR SELECCI�N
	
	   Este m�todo consiste en buscar la posicion del m�nimo elmento de la 
	   secuencia.Este y el primer elemento intercambian su posici�n, y se vuelve
	   a buscar el m�nimo de las casillas que sobran avanzando una posici�n ya 
	   que ya se tiene en la primera el primer m�nimo. Una vez localizado ese 
	   m�nimo se vuelve a intercambiar y se vuelve a buscar el m�nimo de las 
	   casillas restantes, y as� sucesivamente hasta, claramente, llegar al 
	   final del vector.
	*/     
	
	void OrdenaSeleccion()
	{
	
		for (int izda = 0 ; izda < total_utilizados ; izda++){
			
			// Calcular el m�nimo entre "izda" y "total_utilizados"-1
		
			int minimo = vector_privado[izda]; // Valor del m�nimo
			int pos_min = izda; // Posici�n del m�nimo
		
			for (int i = izda + 1; i < total_utilizados ; i++)
		
				if (vector_privado[i] < minimo){ // Nuevo m�nimo
			
					minimo = vector_privado[i];
					pos_min = i;
				}
				
			// Intercambiar los valores guardados en "izda" y "pos_min"
			
			int intercambia = vector_privado[izda];
			vector_privado[izda] = vector_privado[pos_min];
			vector_privado[pos_min] = intercambia; 
				
		}
	}
	
	/***********************************************************************/
	
	/* SEGUNDO M�TODO DE ORDENACI�N: ORDENACI�N POR INSERCI�N
	   
	   Este m�todo consiste en lo siguiente: Se comienza evaluando la segunda
	   de las casillas del vector, y se compara su contenido con las anteriores,
	   de tal forma que se desplazan los contenidos de las casillas de valor
	   menor que el de la casilla que se est� evaluando, hacia la derecha. De
	   esta manera, se guarda el valor de la casilla que estamos evaluando 
	   detr�s de todas las que se hab�an desplazado hacia la derecha. Este
	   proceso se repite sucesivamente con las dem�s casillas hasta llegar al
	   final del vector.
	*/ 
	
	void OrdenaInsercion()
	{
		
		for (int izda = 1; izda < total_utilizados; izda++){
			
			// "a_insertar" es el valor que se va a insertar en
			// subvector izquierdo. Este subvector est� ordenado y
			// comprende las posiciones entre 0 e "izda"-1
		
			int a_insertar = vector_privado[izda];
		
			// Se busca la posici�n en la zona ordenada
			int i = izda;
			while ((i > 0) && (a_insertar < vector_privado[i-1])) {
				
				vector_privado[i] = vector_privado[i-1]; 
		
				// Desplazar a la derecha los
				// valores mayores que "a_insertar"
		
				i--;
			}
		
			vector_privado[i] = a_insertar; // Copiar -insertar- en el hueco
	
		}
		
	}
	
	/***********************************************************************/
	
	/* TERCER M�TODO DE ORDENACI�N: ORDENACI�N POR INTERCAMBIO
	
	   En este m�todo se comienza evaluando el contenido de las casillas desde
	   el final del vector, de tal forma que si la �ltima es menor que la 
	   anterior, estas se intercambian, y si ocurre lo contrario, simplemente
	   se pasan a evaluar otro par de casillas consecutivas (yendo hacia la
	   izquierda) hasta llegar as� al inicio del vector, consiguiendo as� tener
	   el menor valor del vector en la primera posici�n. A continuaci�n, se
	   vuelve a repetir todo el proceso ,pero esta vez, consider�ndose el inicio
	   del vector en la posici�n 1, y as� sucesivamente.
	*/   

	void OrdenaIntercambio()
	{
	
		for (int izda = 0; izda < total_utilizados; izda++) {
			
			for (int i = total_utilizados-1 ; i > izda ; i--)
			
				if (vector_privado[i] < vector_privado[i-1]){ // Intercambiar
				
					int intercambia = vector_privado[i];
					vector_privado[i] = vector_privado[i-1];
					vector_privado[i-1] = intercambia;
					
					}
					
		}
		
	}
	
	/***********************************************************************/
	
	/* CUARTO M�TODO DE ORDENACI�N: ORDENACI�N POR INTERCAMBIO, MEJORADO
	
	   Este algoritmo de ordenaci�n funciona de la misma forma que el m�todo
	   anteriormente expuesto, pero este difiere del otro en que si se da
	   el caso de que dos elementos del vector, a la derecha de izda, est�n
	   ordenados, entonces el bucle cesa, ya que no es necesario continuar 
	   iterando.
	*/   
	
	void OrdenaIntercambioMejorado()
	{
		
		bool cambio = true; // Para entrar
		
		for (int izda = 0; izda < total_utilizados && cambio; izda++){
			
			// En cada pasada iniciamos "cambio" a false.
			// Se pondr� true si y solo si hay alg�n intercambio
		
			cambio = false;
		
			for (int i = total_utilizados-1 ; i > izda ; i--)
			
				if (vector_privado[i] < vector_privado[i-1]){ // Intercambiar
				
					int intercambia = vector_privado[i];	
					vector_privado[i] = vector_privado[i-1];
					vector_privado[i-1] = intercambia;
					
				cambio = true; // Se ha hecho un intercambio
			
			}
			
		}
		
	}
	
	/***********************************************************************/
	
};

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

int main ()
{
	
	// Declaraci�n de datos
	
	// Declaraci�n del objeto de la clase SecuenciaEnteros
	
	SecuenciaEnteros secuencia;
	
	const int MIN = 0;
	const int MAX = 10000;
	
	// Declaraci�n del objeto de la clase GeneradorAleatoriosEnteros
	
	GeneradorAleatorioEnteros generador (MIN, MAX);
	
	// Declaraci�n del objeto de la clase Cronometro
	
	Cronometro crono;

	
	// Entrada de datos
	
	cout << "Generando secuencia de enteros";
	cout << endl;
	
	for(int i = 0; i < secuencia.Capacidad(); i++)
		secuencia.Aniade(generador.Siguiente());
	
	
	cout << endl;


	/* Copiamos el objeto secuencia en otros 3 objetos nuevos, para probar los
	   distintos m�todos de ordenaci�n
    */
	 
	SecuenciaEnteros sec_enteros2 (secuencia);
	SecuenciaEnteros sec_enteros3 (secuencia);
	SecuenciaEnteros sec_enteros4 (secuencia);
	
	cout << "Ordenacion de los numeros";
	cout << endl<<endl;
	
	/***********************************************************************/

	// Primer algoritmo de ordenaci�n de los n�meros generados
	
	cout << "Primer algoritmo: ORDENACION POR SELECCION: ";
	cout << endl;
	
	crono.Reset();
	
	secuencia.OrdenaSeleccion();
	
	for(int i = 0; i < MAX; i++)
	
		cout << secuencia.Elemento(i) << " ";
		
	cout << endl << endl;
	
	// Tiempo empleado en llevar a cabo la ordenaci�n
	
	cout << endl;
	cout << "Se han empleado " << crono.MiliSegundosTranscurridos() <<
	        " milisegundos en llevar a cabo la ordenacion";
	        
		
	/***********************************************************************/
	
	// Segundo algoritmo de ordenaci�n de los n�meros aleatorios generados
	
	cout << endl;
	cout << "Segundo algoritmo: ORDENACION POR INSERCION: ";
	cout << endl;
	
	crono.Reset();
	sec_enteros2.OrdenaInsercion();
	
	for(int i = 0; i < MAX; i++)
	
		cout << sec_enteros2.Elemento(i) << " ";
		
	cout << endl << endl; 
	
	// Tiempo empleado en llevar a cabo la ordenaci�n con este algoritmo
	
	cout << "Se han empleado " << crono.MiliSegundosTranscurridos() <<
	        " milisegundos en llevar a cabo la ordenacion";
	        
	/***********************************************************************/
	
	cout << endl;	
	cout << "Tercer algoritmo de ordenacion: ORDENACION POR INTERCAMBIO ";
	cout << endl;
	
	crono.Reset();
	sec_enteros3.OrdenaIntercambio();
	
	for(int i = 0; i < MAX; i++)
	
		cout << sec_enteros3.Elemento(i) << " ";
		
	cout << endl << endl;
	
	// Tiempo empleado en llevar a cabo la ordenaci�n con este algoritmo
	
	cout << "Se han empleado " << crono.MiliSegundosTranscurridos() <<
	        " milisegundos en llevar a cabo la ordenacion";
	
/***********************************************************************/
	
	cout << endl;	
	cout << "Cuarto algoritmo de ordenacion: ORDENACION POR INTERCAMBIO" 
	       " MEJORADO ";
	cout << endl;
	
	crono.Reset();
	sec_enteros4.OrdenaIntercambioMejorado();
	
	for(int i = 0; i < MAX; i++)
	
		cout << sec_enteros4.Elemento(i) << " ";
		
	cout << endl << endl; 
	
	// Tiempo empleado en llevar a cabo la ordenaci�n con este algoritmo
	
	cout << "Se han empleado " << crono.MiliSegundosTranscurridos() <<
	        " milisegundos en llevar a cabo la ordenacion";
	
	cout << endl;
	
	/***********************************************************************/
	return 0;	
}
	
	
	
	        
	
	    
	
	
	
	
	
	
	
	



	
	
			

