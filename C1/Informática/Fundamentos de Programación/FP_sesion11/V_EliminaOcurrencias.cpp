/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee una secuencia de caracteres, y elimina uno de los caracteres
   de dicha secuencia tantas veces como aparezca en ella. Dicho car�cter es
   elegido por el usuario. Finalmente se muestra en pantalla la cadena final,
   con el sin el car�cter que se haya elegido.
   En este programa se trabaja sobre la clase SecuenciaCaracteres, a la que
   se le ha a�adido un m�todo de aspecto p�blico, destinado a la eliminaci�n
   de ocurrencias; a eliminar un car�cter de la secuencia de caracteres en
   espec�fico, tantas veces como aparezca.
   
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
    // Contructor con argumentos
    
    SecuenciaCaracteres (string cadena): total_utilizados (0)
    {
    	TransStringChar(cadena);
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
	
	// M�todo destinado a la eliminaci�n de un car�cter en concreto de una 
	// secuencia de caracteres introducida
	
	/* En este m�todo se utilizan dos apuntadores (pos_lectura y pos_escritura)
	   de tal forma que se va a ir recorriendo el vector en el que se guardan
	   los caracteres de la secuencia, con los apuntadores. Si se da el caso de
	   que el contenido de la casilla que apunta la posici�n de lectura no
	   es el car�cter que se quiere borrar, se copia dicho contenido en la
	   la casilla que indique el otro apuntador: la posici�n de escritura, y 
	   se actualiza dicho apuntador. Si ocurre lo contrario, es decir que
	   la posici�n de lectura est� sobre una casilla que contegna el car�cter
	   que queremos eliminar, simplemente se sigue leyendo, obvi�ndose dicho
	   car�cter, es decir, se actualiza la posici�n de lectura.
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
    	
    	// M�todo que rellena el vector privado del objeto a partir de un
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
	
	// Declaraci�n de datos
	
	string cadena;
	
	// Entrada de datos
	
	cout << "Introduzca una secuencia de caracteres."<< endl;
	getline(cin, cadena);
	
	// Declaraci�n del objeto de la clase SecuenciaCaracteres
	
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
	
	// Para eliminar el car�cter de la secuencia, se llama al m�todo de la
	// clase SecuenciaCaracteres, EliminaOcurrencias, pas�ndole el car�cter a
	// borrar.
	
	sec.EliminaOcurrencias(a_borrar);
	
	cout << endl;
	cout << "La secuencia de caracteres resultante es la siguiente: "
	     << sec.ToString();
	cout << endl;
	
/******************************************************************************/	
	
	return 0;	
}
	    	
	
