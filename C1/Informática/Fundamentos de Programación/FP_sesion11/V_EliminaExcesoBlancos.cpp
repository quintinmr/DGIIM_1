/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee una secuencia de caracteres, en la que puede haber cualquier
   tipo de car�cter, y puede repetirse cuantas veces se desee, pero sin 
   rebasar el m�ximo de caracteres permitido (100), de tal forma que el programa
   elimina de la secuencia el exceso de espacios en blanco (que son tambi�n 
   caracteres), si los hubiera; si hay dos o m�s espacios consecutivos se 
   eliminan los consecutivos y se deja el primero, de tal forma que haya un 
   espacio solo entre otros dos caracteres que no sean espacios.

   Entradas: 
    Una secuencia de caracteres.
    
   Salidas:
    Una secuencia de caracteres sin exceso de espacios en blanco, si los 
	hubiera.
   	
   
    
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

    static const int TAMANIO = 100; // N�m.casillas disponibles
    char vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<=TAMANIO

    int total_utilizados; // N�m.casillas ocupadas

public:

    /***********************************************************************/
    // Constructor sin argumentos

    SecuenciaCaracteres (void) : total_utilizados (0)
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
	
	/* M�todo destinado a la eliminaci�n del exceso de espacios en blanco
	 Consiste en inr recorriendo el vector en el que se guardan los 
	 caracteres introcucidos, de tal forma que si en una posici�n determinada
	 se encuentra un espacio en blanco, y adem�s en la posici�n antrior 
	 aparece otro espacio en blanco, se elimina, llamando al metodo Elimina,
	 que aparece m�s arriba, el espacio en blanco de la posici�n inicial, y
	 as� sucesivamente.
	*/ 
	
	void EliminaExcesoBlancos (void)
	{

		int pos = 0;
		
		while (pos < total_utilizados){
			
			if ((vector_privado [pos] == ' ')&&(vector_privado[pos-1] == ' ')){
				
				Elimina (pos);
			}
			
			else
			{
				pos++;
			}
		}
	}
	
	/***********************************************************************/

};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main()
{
	
	// Declaraci�n de datos
	
	// Declaraci�n del objeto de la clase SecuenciaCaracteres
	SecuenciaCaracteres sec;
	
	string secuencia;

	// Entrada de datos
	
	cout << "Introduzca una secuencia de caracteres."<< endl;
	getline(cin, secuencia);
	
	cout << endl;
	
	for(int i=0; i < secuencia.length(); i++){
		
		sec.Aniade(secuencia.at(i));
	}
	
	// Se muestra la cadena introducida con el m�todo ToString
	
	cout << endl;
	cout << "La secuencia de caracteres introducida es la siguiente: "
	     << sec.ToString();
	     
	cout << endl;   
	  
	// Para eliminar de la secuencia introducida los espacios en blanco en
	// exceso (m�s de uno consecutivos), se llama al m�todo 
	// EliminaExcesosBlancos, de la clase SecuenciaCaracteres.   
	  
	sec.EliminaExcesoBlancos();
	
	cout << endl;
	cout << "La secuencia de caracteres resultante de eliminar el exceso de" 
	        " exceso de espacios en blanco es la siguiente: "
	     << sec.ToString();
	cout << endl;
	
/******************************************************************************/	
	
	return 0;	
}
	    	


	
	
