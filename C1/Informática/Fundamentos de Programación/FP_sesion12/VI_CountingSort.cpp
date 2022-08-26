/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee una secuencia de caracteres y crea una secuencia de 
   caracteres final, en la que todos los caracteres se encuentran ordenados 
   alfab�ticamente, mostr�ndose dicha secuencia en pantalla.
   
   Para llevar a cabo el programa se ha trabajado sobre la clase 
   SecuenciaCaracteres, a la que se le han a�adido dos m�todos nuevos, para 
   poder llevar a cabo el objetivo del programa:
   
   1�)SecuenciaCaracteres CountingSortEntre (char el_minimo, char el_maximo)
   2�)SecuenciaCaracteres CountingSort(void)
   	
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

    static const int TAMANIO = 50; // N�m.casillas disponibles
    char vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<=TAMANIO

    int total_utilizados; // N�m.casillas ocupadas

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
    // Inserta el car�cter "nuevo" en la posici�n dada por "indice".
    // Desplaza todos los caracteres una posici�n a la derecha antes de 
	// copiar en "indice" en valor "nuevo".
	// PRE: 0 <= pos_insercion < total_utilizados
    // PRE: total_utilizados < TAMANIO
    // 		La inserci�n se realiza si hay alguna casilla disponible.
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
    // Compone un string con todos los caracteres que est�n
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
    	
    	// Creaci�n del vector de frecuencias
    	
    	const int MAX = (el_maximo - el_minimo + 1);
    	int frecuencias_caracteres [MAX] = {0};
    	
    	// Se recorre la secuencia de caracteres y se recorre el vector de 
    	// las frecuencias, de tal forma que si el elemento que se encuentra
    	// en la posici�n que indique el �ndice que va recorriendo la secuencia
		// coincide con el elemento que el vector
    	// de las frecuencias, m�s la posici�n en la p�gina de c�digos ASCII
    	// del m�nimo de la secuencia de caracteres, entonces, simplemente se
    	// actualiza el vector de las frecuencias; se actualiza el n�mero de
    	// veces que aparece el caracter de la posici�n indicada en ese momento.
    	
		for (int i = 0; i < total_utilizados; i++){
    		
    		for (int k = 0; k < MAX; k++){
    			
    			if (vector_privado[i] == (el_minimo + k)){
    				
    				frecuencias_caracteres[k]++;
    				
    			}
    			
    		}
    		
    	}
    	
    	// A continuaci�n se va a crear el objeto de la clase 
    	// SecuenciaCaracteres el cual devolver� este m�todo.
    	
    	SecuenciaCaracteres cad_out;
    	
    	// Se recorre de nuevo el vector que contiene a las frecuencias de
    	// tal forma que si el elemento de la posici�n que indique en cada
    	// caso el �ndice variando, tiene frecuencia distinta de cero, es decir,
    	// aparece m�s de una vez en la secuencia de caracteres introducida, 
        // entonces, cada uno de esos elementos que se repiten se van a ir
		// a�adiendo a la cadena resultante (cad_out), mediante el m�todo
		// Aniade de esta misma clase, al que le entra un dato tipo char, que 
		// en cada caso ser� el elemento que indique el �ndice variando, a 
		// partir del m�nimo.  
    	
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
		
		//B�squeda del m�nimo 
		
		if (total_utilizados > 0){
			
			minimo = vector_privado[0];
			
			for (int i = 1; i < total_utilizados ; i++){
				
				if (vector_privado[i] < minimo){
					
					minimo = vector_privado[i];
					
				}
			}
		}
			
		// B�squeda del m�ximo
		
		if (total_utilizados > 0){
			
			maximo = vector_privado[0];
			
			for (int i = 1; i < total_utilizados ; i++){
				
				if (vector_privado[i] > maximo){
					
					maximo = vector_privado[i];
					
				}
			}
		}
			
		// A continuaci�n se va a crear el objeto de la clase 
    	// SecuenciaCaracteres el cual devolver� este m�todo.	
			
		SecuenciaCaracteres cad_final (CountingSortEntre (minimo, maximo));
		
		return (cad_final);
		
	}
	
private:
    	
    	// M�todo que completar el vector en el que se alamcenan los caracteres
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
	
	// C�lculos
	
	// Defino el objeto de la clase SecuenciaCaracteres que contendr� a los
	// elementos de la cadena inicial, ordenados
	
	SecuenciaCaracteres cad_ordenada (cad.CountingSort());
	
	// Salida de datos
	
	cout << endl;
	cout << "Secuencia ordenada: " << cad_ordenada.ToString();
	
	return 0;
	
}
		
			
			
			
