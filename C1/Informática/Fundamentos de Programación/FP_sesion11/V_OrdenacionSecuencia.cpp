/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa en el que se trabaja sobre la clase SecuenciaEnteros, a la que se 
   le han añadido cuatro métodos, en los que se han implementado los cuatro
   métodos de ordenación vistos en clase: 
   	1) Ordenación por selección
   	2) Ordenación por inserción
   	3) Ordenación por intercambio
   	4) Ordenación por intercambio, mejorado.
   	
   El programa genera aleatoriamente una secuencia de números (para ello se
   hace uso de la clase GeneradorAleatoriosEnteros), y los ordena mediante
   los cuatro métodos de ordenación citados anteriormente. Además muestra 
   el tiempo, en milisegundos, que ha tardado el programa en ordenar los números
   mediante cada método de ordenación (para ello se hace uso de los métodos
   de la clase cronómetro).
    
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

    static const int TAMANIO = 10000; // Núm.casillas disponibles
    int vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<=TAMANIO

    int total_utilizados; // Núm.casillas ocupadas

public:

    /***********************************************************************/
    // Constructor sin argumentos

    SecuenciaEnteros (void) : total_utilizados (0)
    {}

    /***********************************************************************/
    // Devuelve el número de casillas ocupadas

    int TotalUtilizados (void)
    {
        return (total_utilizados);
    }

    /***********************************************************************/
    // Devuelve el número de casillas disponibles

    int Capacidad (void)
    {
        return (TAMANIO);
    }

    /***********************************************************************/
    // Añade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // 		La adición se realiza si hay alguna casilla disponible.
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
    // Eliminar el carácter de la posición dada por "indice".
    // Realiza un borrado físico (desplazamiento y sustitución).
    // PRE: 0 <= indice < total_utilizados

    void Elimina (int indice)
    {
        if ((indice >= 0) && (indice < total_utilizados)) {

            int tope = total_utilizados-1; // posic. del último

            for (int i = indice ; i < tope ; i++)
                vector_privado[i] = vector_privado[i+1];

            total_utilizados--;
        }
    }

    /***********************************************************************/
    // Método que se encarga de eliminar los elementos de la secuencia.
    
    void EliminaSecuencia(void)
    {
    	total_utilizados = 0;
    	
    }
    
    /***********************************************************************/
    
    // Compone un string con todos los caracteres que están
    // almacenados en la secuencia y lo devuelve.

    string ToString()
    {
        string cadena;

        for (int i=0; i<total_utilizados; i++)
            cadena = cadena + to_string(vector_privado[i]);

        return (cadena);
    }

	/***********************************************************************/
	
	/* PRIMER MÉTODO DE ORDENACIÓN: ORDENACIÓN POR SELECCIÓN
	
	   Este método consiste en buscar la posicion del mínimo elmento de la 
	   secuencia.Este y el primer elemento intercambian su posición, y se vuelve
	   a buscar el mínimo de las casillas que sobran avanzando una posición ya 
	   que ya se tiene en la primera el primer mínimo. Una vez localizado ese 
	   mínimo se vuelve a intercambiar y se vuelve a buscar el mínimo de las 
	   casillas restantes, y así sucesivamente hasta, claramente, llegar al 
	   final del vector.
	*/     
	
	void OrdenaSeleccion()
	{
	
		for (int izda = 0 ; izda < total_utilizados ; izda++){
			
			// Calcular el mínimo entre "izda" y "total_utilizados"-1
		
			int minimo = vector_privado[izda]; // Valor del mínimo
			int pos_min = izda; // Posición del mínimo
		
			for (int i = izda + 1; i < total_utilizados ; i++)
		
				if (vector_privado[i] < minimo){ // Nuevo mínimo
			
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
	
	/* SEGUNDO MÉTODO DE ORDENACIÓN: ORDENACIÓN POR INSERCIÓN
	   
	   Este método consiste en lo siguiente: Se comienza evaluando la segunda
	   de las casillas del vector, y se compara su contenido con las anteriores,
	   de tal forma que se desplazan los contenidos de las casillas de valor
	   menor que el de la casilla que se está evaluando, hacia la derecha. De
	   esta manera, se guarda el valor de la casilla que estamos evaluando 
	   detrás de todas las que se habían desplazado hacia la derecha. Este
	   proceso se repite sucesivamente con las demás casillas hasta llegar al
	   final del vector.
	*/ 
	
	void OrdenaInsercion()
	{
		
		for (int izda = 1; izda < total_utilizados; izda++){
			
			// "a_insertar" es el valor que se va a insertar en
			// subvector izquierdo. Este subvector está ordenado y
			// comprende las posiciones entre 0 e "izda"-1
		
			int a_insertar = vector_privado[izda];
		
			// Se busca la posición en la zona ordenada
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
	
	/* TERCER MÉTODO DE ORDENACIÓN: ORDENACIÓN POR INTERCAMBIO
	
	   En este método se comienza evaluando el contenido de las casillas desde
	   el final del vector, de tal forma que si la última es menor que la 
	   anterior, estas se intercambian, y si ocurre lo contrario, simplemente
	   se pasan a evaluar otro par de casillas consecutivas (yendo hacia la
	   izquierda) hasta llegar así al inicio del vector, consiguiendo así tener
	   el menor valor del vector en la primera posición. A continuación, se
	   vuelve a repetir todo el proceso ,pero esta vez, considerándose el inicio
	   del vector en la posición 1, y así sucesivamente.
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
	
	/* CUARTO MÉTODO DE ORDENACIÓN: ORDENACIÓN POR INTERCAMBIO, MEJORADO
	
	   Este algoritmo de ordenación funciona de la misma forma que el método
	   anteriormente expuesto, pero este difiere del otro en que si se da
	   el caso de que dos elementos del vector, a la derecha de izda, están
	   ordenados, entonces el bucle cesa, ya que no es necesario continuar 
	   iterando.
	*/   
	
	void OrdenaIntercambioMejorado()
	{
		
		bool cambio = true; // Para entrar
		
		for (int izda = 0; izda < total_utilizados && cambio; izda++){
			
			// En cada pasada iniciamos "cambio" a false.
			// Se pondrá true si y solo si hay algún intercambio
		
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
	
	// Declaración de datos
	
	// Declaración del objeto de la clase SecuenciaEnteros
	
	SecuenciaEnteros secuencia;
	
	const int MIN = 0;
	const int MAX = 10000;
	
	// Declaración del objeto de la clase GeneradorAleatoriosEnteros
	
	GeneradorAleatorioEnteros generador (MIN, MAX);
	
	// Declaración del objeto de la clase Cronometro
	
	Cronometro crono;

	
	// Entrada de datos
	
	cout << "Generando secuencia de enteros";
	cout << endl;
	
	for(int i = 0; i < secuencia.Capacidad(); i++)
		secuencia.Aniade(generador.Siguiente());
	
	
	cout << endl;


	/* Copiamos el objeto secuencia en otros 3 objetos nuevos, para probar los
	   distintos métodos de ordenación
    */
	 
	SecuenciaEnteros sec_enteros2 (secuencia);
	SecuenciaEnteros sec_enteros3 (secuencia);
	SecuenciaEnteros sec_enteros4 (secuencia);
	
	cout << "Ordenacion de los numeros";
	cout << endl<<endl;
	
	/***********************************************************************/

	// Primer algoritmo de ordenación de los números generados
	
	cout << "Primer algoritmo: ORDENACION POR SELECCION: ";
	cout << endl;
	
	crono.Reset();
	
	secuencia.OrdenaSeleccion();
	
	for(int i = 0; i < MAX; i++)
	
		cout << secuencia.Elemento(i) << " ";
		
	cout << endl << endl;
	
	// Tiempo empleado en llevar a cabo la ordenación
	
	cout << endl;
	cout << "Se han empleado " << crono.MiliSegundosTranscurridos() <<
	        " milisegundos en llevar a cabo la ordenacion";
	        
		
	/***********************************************************************/
	
	// Segundo algoritmo de ordenación de los números aleatorios generados
	
	cout << endl;
	cout << "Segundo algoritmo: ORDENACION POR INSERCION: ";
	cout << endl;
	
	crono.Reset();
	sec_enteros2.OrdenaInsercion();
	
	for(int i = 0; i < MAX; i++)
	
		cout << sec_enteros2.Elemento(i) << " ";
		
	cout << endl << endl; 
	
	// Tiempo empleado en llevar a cabo la ordenación con este algoritmo
	
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
	
	// Tiempo empleado en llevar a cabo la ordenación con este algoritmo
	
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
	
	// Tiempo empleado en llevar a cabo la ordenación con este algoritmo
	
	cout << "Se han empleado " << crono.MiliSegundosTranscurridos() <<
	        " milisegundos en llevar a cabo la ordenacion";
	
	cout << endl;
	
	/***********************************************************************/
	return 0;	
}
	
	
	
	        
	
	    
	
	
	
	
	
	
	
	



	
	
			

