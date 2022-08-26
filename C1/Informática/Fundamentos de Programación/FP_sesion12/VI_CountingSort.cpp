/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee una secuencia de caracteres y crea una secuencia de 
   caracteres final, en la que todos los caracteres se encuentran ordenados 
   alfabéticamente, mostrándose dicha secuencia en pantalla.
   
   Para llevar a cabo el programa se ha trabajado sobre la clase 
   SecuenciaCaracteres, a la que se le han añadido dos métodos nuevos, para 
   poder llevar a cabo el objetivo del programa:
   
   1ª)SecuenciaCaracteres CountingSortEntre (char el_minimo, char el_maximo)
   2ª)SecuenciaCaracteres CountingSort(void)
   	
   Entradas: 
    Una secuencia de caracteres.
    
   Salidas:
    Una secuencia de caracteres ordenada .
   	  
*/               
/******************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

////////////////////////////////////////////////////////////////////////////////

	// Defino la clase Secuencia de caracteres

class SecuenciaCaracteres {

private:

    static const int TAMANIO = 50; // Núm.casillas disponibles
    char vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<=TAMANIO

    int total_utilizados; // Núm.casillas ocupadas

public:

    /***********************************************************************/
    // Constructor sin argumentos

    SecuenciaCaracteres (void) : total_utilizados (0)
    {}
    
    /***********************************************************************/
    // Constructor con argumentos
    	
    SecuenciaCaracteres (string cadena) : total_utilizados (0)
    {
    	TransStringChar (cadena);
    }

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

    void Aniade (char nuevo)
    {
        if (total_utilizados < TAMANIO){
            vector_privado[total_utilizados] = nuevo;
            total_utilizados++;
        }
    }

    /***********************************************************************/
    // Devuelve el elemento de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados

    char Elemento (int indice)
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
    // Inserta el carácter "nuevo" en la posición dada por "indice".
    // Desplaza todos los caracteres una posición a la derecha antes de 
	// copiar en "indice" en valor "nuevo".
	// PRE: 0 <= pos_insercion < total_utilizados
    // PRE: total_utilizados < TAMANIO
    // 		La inserción se realiza si hay alguna casilla disponible.
    // 		Si no hay espacio, no se hace nada.
    
	void Inserta (int pos_insercion, char valor_nuevo)
	{
        if ((pos_insercion >= 0) && (pos_insercion < total_utilizados) 
		    && (total_utilizados < TAMANIO)) {
		
			for (int i = total_utilizados; i > pos_insercion; i--)
				vector_privado[i] = vector_privado[i-1];
			
			vector_privado[pos_insercion] = valor_nuevo;
			total_utilizados++;		
		}
	}
	
    /***********************************************************************/	
    // Compone un string con todos los caracteres que están
    // almacenados en la secuencia y lo devuelve.

    string ToString()
    {
        string cadena;

        for (int i=0; i<total_utilizados; i++)
            cadena = cadena + vector_privado[i];

        return (cadena);
    }

	/***********************************************************************/
	SecuenciaCaracteres CountingSortEntre (char el_minimo, char el_maximo)
    {
    	
    	// Creación del vector de frecuencias
    	
    	const int MAX = (el_maximo - el_minimo + 1);
    	int frecuencias_caracteres [MAX] = {0};
    	
    	// Se recorre la secuencia de caracteres y se recorre el vector de 
    	// las frecuencias, de tal forma que si el elemento que se encuentra
    	// en la posición que indique el índice que va recorriendo la secuencia
		// coincide con el elemento que el vector
    	// de las frecuencias, más la posición en la página de códigos ASCII
    	// del mínimo de la secuencia de caracteres, entonces, simplemente se
    	// actualiza el vector de las frecuencias; se actualiza el número de
    	// veces que aparece el caracter de la posición indicada en ese momento.
    	
		for (int i = 0; i < total_utilizados; i++){
    		
    		for (int k = 0; k < MAX; k++){
    			
    			if (vector_privado[i] == (el_minimo + k)){
    				
    				frecuencias_caracteres[k]++;
    				
    			}
    			
    		}
    		
    	}
    	
    	// A continuación se va a crear el objeto de la clase 
    	// SecuenciaCaracteres el cual devolverá este método.
    	
    	SecuenciaCaracteres cad_out;
    	
    	// Se recorre de nuevo el vector que contiene a las frecuencias de
    	// tal forma que si el elemento de la posición que indique en cada
    	// caso el índice variando, tiene frecuencia distinta de cero, es decir,
    	// aparece más de una vez en la secuencia de caracteres introducida, 
        // entonces, cada uno de esos elementos que se repiten se van a ir
		// añadiendo a la cadena resultante (cad_out), mediante el método
		// Aniade de esta misma clase, al que le entra un dato tipo char, que 
		// en cada caso será el elemento que indique el índice variando, a 
		// partir del mínimo.  
    	
    	for (int i = 0; i < MAX; i++){
			
			if (frecuencias_caracteres[i] != 0){
			
				for(int f = 0; f < frecuencias_caracteres[i]; f++)
				
					cad_out.Aniade(el_minimo + i);
			}
		}
		
		return(cad_out);
    }
    			
 	/***********************************************************************/   			
	
	SecuenciaCaracteres CountingSort()
	{
		
		char minimo, maximo;
		
		//Búsqueda del mínimo 
		
		if (total_utilizados > 0){
			
			minimo = vector_privado[0];
			
			for (int i = 1; i < total_utilizados ; i++){
				
				if (vector_privado[i] < minimo){
					
					minimo = vector_privado[i];
					
				}
			}
		}
			
		// Búsqueda del máximo
		
		if (total_utilizados > 0){
			
			maximo = vector_privado[0];
			
			for (int i = 1; i < total_utilizados ; i++){
				
				if (vector_privado[i] > maximo){
					
					maximo = vector_privado[i];
					
				}
			}
		}
			
		// A continuación se va a crear el objeto de la clase 
    	// SecuenciaCaracteres el cual devolverá este método.	
			
		SecuenciaCaracteres cad_final (CountingSortEntre (minimo, maximo));
		
		return (cad_final);
		
	}
	
private:
    	
    	// Método que completar el vector en el que se alamcenan los caracteres
    	// de la secuencia de caracteres, a partir de un string
		
		void TransStringChar (string cadena)
		{
			for(int i = 0; i < cadena.length(); i++){
				
				Aniade(cadena.at(i));
			}
		}	
	
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main ()
{
	
	// Datos de entrada
	
	string cadena;
	
	// Entrada de datos
	
	cout << "COUNTING SORT";
	cout << endl;
	
	cout << "Introduzca una secuencia de caracteres: ";
	getline (cin, cadena);
	
	// Defino un objeto de la clase SecuenciaCaracteres
	
	SecuenciaCaracteres cad (cadena);
	
	// Cálculos
	
	// Defino el objeto de la clase SecuenciaCaracteres que contendrá a los
	// elementos de la cadena inicial, ordenados
	
	SecuenciaCaracteres cad_ordenada (cad.CountingSort());
	
	// Salida de datos
	
	cout << endl;
	cout << "Secuencia ordenada: " << cad_ordenada.ToString();
	
	return 0;
	
}
		
			
			
			
