/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee una secuencia de caracteres, y elimina uno de los caracteres
   de dicha secuencia tantas veces como aparezca en ella. Dicho carácter es
   elegido por el usuario. Finalmente se muestra en pantalla la cadena final,
   con el sin el carácter que se haya elegido.
   En este programa se trabaja sobre la clase SecuenciaCaracteres, a la que
   se le ha añadido un método de aspecto público, destinado a la eliminación
   de ocurrencias; a eliminar un carácter de la secuencia de caracteres en
   específico, tantas veces como aparezca.
   
   Entradas:
    Una secuencia de caracteres. 

   Salidas:
    La secuencia de caracteres sin el caracter que el usuario ha decidido 
    eliminar.
    
*/               
/******************************************************************************/

#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

////////////////////////////////////////////////////////////////////////////////

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
    // Contructor con argumentos
    
    SecuenciaCaracteres (string cadena): total_utilizados (0)
    {
    	TransStringChar(cadena);
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
	
	// Método destinado a la eliminación de un carácter en concreto de una 
	// secuencia de caracteres introducida
	
	/* En este método se utilizan dos apuntadores (pos_lectura y pos_escritura)
	   de tal forma que se va a ir recorriendo el vector en el que se guardan
	   los caracteres de la secuencia, con los apuntadores. Si se da el caso de
	   que el contenido de la casilla que apunta la posición de lectura no
	   es el carácter que se quiere borrar, se copia dicho contenido en la
	   la casilla que indique el otro apuntador: la posición de escritura, y 
	   se actualiza dicho apuntador. Si ocurre lo contrario, es decir que
	   la posición de lectura esté sobre una casilla que contegna el carácter
	   que queremos eliminar, simplemente se sigue leyendo, obviándose dicho
	   carácter, es decir, se actualiza la posición de lectura.
	*/   
	
	void EliminaOcurrencias (char a_borrar)
	{
		int pos_lectura = 0;
		int pos_escritura = 0;
		
		while(pos_lectura < total_utilizados){
		
			if (vector_privado[pos_lectura] != a_borrar){
				
				vector_privado[pos_escritura] = vector_privado[pos_lectura];
				
				pos_escritura++;	
				
			}
			
			pos_lectura++;
			
		}
		
		total_utilizados = pos_escritura;
	}
	
private:
    	
    	// Método que rellena el vector privado del objeto a partir de un
		// dato string
		
		void TransStringChar (string cad)
		{
			for(int i = 0; i < cad.length(); i++){
				
				Aniade(cad.at(i));
			}
		}	
	
	
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main()
{
	
	// Declaración de datos
	
	string cadena;
	
	// Entrada de datos
	
	cout << "Introduzca una secuencia de caracteres."<< endl;
	getline(cin, cadena);
	
	// Declaración del objeto de la clase SecuenciaCaracteres
	
	SecuenciaCaracteres sec (cadena);
	
	cout << endl;
	cout << "La secuencia de caracteres introducida es la siguiente: "
	     << sec.ToString();
	     
	cout << endl << endl;   
	  
	 char a_borrar; 
	 
	cout << "De los caracteres que conforman la secuencia, introduzca aquel que"
	        " desee eliminar: ";
	cin  >> a_borrar; 
	
	cout << endl;
	
	// Para eliminar el carácter de la secuencia, se llama al método de la
	// clase SecuenciaCaracteres, EliminaOcurrencias, pasándole el carácter a
	// borrar.
	
	sec.EliminaOcurrencias(a_borrar);
	
	cout << endl;
	cout << "La secuencia de caracteres resultante es la siguiente: "
	     << sec.ToString();
	cout << endl;
	
/******************************************************************************/	
	
	return 0;	
}
	    	
	
