/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee una secuencia de caracteres, en la que puede haber cualquier
   tipo de carácter, y puede repetirse cuantas veces se desee, pero sin 
   rebasar el máximo de caracteres permitido (100), de tal forma que el programa
   elimina de la secuencia el exceso de espacios en blanco (que son también 
   caracteres), si los hubiera; si hay dos o más espacios consecutivos se 
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

    static const int TAMANIO = 100; // Núm.casillas disponibles
    char vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<=TAMANIO

    int total_utilizados; // Núm.casillas ocupadas

public:

    /***********************************************************************/
    // Constructor sin argumentos

    SecuenciaCaracteres (void) : total_utilizados (0)
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
	
	/* Método destinado a la eliminación del exceso de espacios en blanco
	 Consiste en inr recorriendo el vector en el que se guardan los 
	 caracteres introcucidos, de tal forma que si en una posición determinada
	 se encuentra un espacio en blanco, y además en la posición antrior 
	 aparece otro espacio en blanco, se elimina, llamando al metodo Elimina,
	 que aparece más arriba, el espacio en blanco de la posición inicial, y
	 así sucesivamente.
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
	
	// Declaración de datos
	
	// Declaración del objeto de la clase SecuenciaCaracteres
	SecuenciaCaracteres sec;
	
	string secuencia;

	// Entrada de datos
	
	cout << "Introduzca una secuencia de caracteres."<< endl;
	getline(cin, secuencia);
	
	cout << endl;
	
	for(int i=0; i < secuencia.length(); i++){
		
		sec.Aniade(secuencia.at(i));
	}
	
	// Se muestra la cadena introducida con el método ToString
	
	cout << endl;
	cout << "La secuencia de caracteres introducida es la siguiente: "
	     << sec.ToString();
	     
	cout << endl;   
	  
	// Para eliminar de la secuencia introducida los espacios en blanco en
	// exceso (más de uno consecutivos), se llama al método 
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
	    	


	
	
