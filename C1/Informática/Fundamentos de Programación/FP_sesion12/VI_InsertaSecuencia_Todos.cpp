/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee una secuencia de caracteres e inserta otra secuencia nueva
   en una posici�n determinada por el usuario.
   
   Para ello, se ha hecho uso de la clase SecuenciaCaracteres, a la cual se le
   han a�adido tres m�todos nuevos:
   
   1�)void InsertaSecuenciaCaracteres(int pos_insercion, 
      SecuenciaCaracteres otra) 
      
      Este m�todo recibe una posici�n determinada por un n�mero entero, y 
      un objeto de la clase SecuenciaCaracteres; la secuencia a introducir en
      la inicial. Adem�s, se hace uso del m�todo Inserta(int pos_insercion, 
	  char valor_nuevo), para llevar a cabo dicha inserci�n.
	  
	2�)void InsertaSecuenciaCaracteres2(int pos_insercion, 
	   SecuenciaCaracteres otra) 
	   
	   Este m�todo es una evoluci�n del m�todo 1�). Ambos difieren en que en 
	   este �ltimo no se hace ning�n llamamiento al m�todo Inserta.
	   
	3�)SecuenciaCaracteres InsertaSecuenciaCaracteres3 (int pos_insercion,
	   SecuenciaCaracteres otra)  
	   
	   Este m�todo devuelve una nueva secuencia de tal forma que las secuencia 
	   original (la impl�cita) y la secuencia "otra" no se modifican. 
	     
*/               
/******************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

////////////////////////////////////////////////////////////////////////////////

class Lector
{
	private:
		
		string titulo;
	
	public:
		
		// Constructor sin argumentos
		
		Lector (void) : titulo ("")
		{ }
		
		// Constructor con argumentos
		
		Lector (string cad) : titulo (cad)
		{ }
		
		// M�todo Set para fijar el campo "titulo"
		
		void SetTitulo (string cad)
		{
			titulo = cad;
		}
		
		/*********************************************************************/
		// Lee un dato int.
		// La lectura est� etiquetada con "titulo"
		// La lectura se efect�a repetidamente hasta que se introduce un valor
		// int correcto.
		
		int LeeEntero (void)
		{
			string cadena;
			
			do{
				cout << titulo;
				getline(cin, cadena);
			}
			while (!EsEntero(cadena));
			
			return (stoi(cadena));
		}
		
		/*********************************************************************/
		// Lee un dato int.
		// La lectura est� etiquetada con "titulo"
		// PRE: menor <= mayor
		// POST: menor <= valor devuelto <= mayor
		
		int LeeEnteroEnRango (int menor, int mayor)
		{
			int numero;
			
			do{
				
				numero = LeeEntero ();
			}
			while ((numero<menor) || (numero>mayor));
			
			return (numero);
		}
		
		/*********************************************************************/
		// Lee un dato int que debe ser mayor o igual que "menor" y lo devuelve.
		// La lectura est� etiquetada con "titulo"
		
		int LeeEnteroMayorOIgual (int menor)
		{
			int numero;
			
			do{
				numero = LeeEntero ();
			}
			while (numero < menor);
			
			return (numero);
		}
		
		/*********************************************************************/
		// Lee un dato double.
		// La lectura est� etiquetada con "titulo"
		// La lectura se efect�a repetidamente hasta que se introduce un valor
		// double correcto.
		
		double LeeReal (void)
		{
			string cadena;
			
			do{
				cout << titulo;
				getline(cin, cadena);
			}
			while (!EsReal(cadena));
			
			return (stod(cadena));
		}
		
		/*********************************************************************/
		// Lee un dato double.
		// La lectura est� etiquetada con "titulo"
		// PRE: menor <= mayor
		// POST: menor <= valor devuelto <= mayor
		
		double LeeRealEnRango (int menor, int mayor)
		{
			double numero;
			
			do{
				
				numero = LeeReal ();
			}
			while ((numero<menor) || (numero>mayor));
			
			return (numero);
		}

		/*********************************************************************/
		// Lee un dato double que debe ser mayor o igual que "menor" y lo 
		// devuelve. 
		// La lectura est� etiquetada con "titulo"
		
		double LeeRealMayorOIgual (int menor)
		{
			double numero;
			
			do{
				numero = LeeReal ();
			}
			while (numero < menor);
			
			return (numero);
		}

		/*********************************************************************/
	
	private:
		
		/*********************************************************************/
		// Devuelve una NUEVA cadena, resultante de eliminar los �ltimos
		// caracteres separadores de "cadena". Los caracteres separadores son
		// el espacio en blanco, el tabulador y el salto de l�nea.
		// Usaremos la funci�n isspace() para simplificar el c�lculo.
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: el resultado de eliminar los �ltimos separadores de 
		// "cadena"
		/*********************************************************************/
		
		string EliminaUltimosSeparadores (string cadena)
		{
			while (cadena.length()>0 && isspace(cadena.back()))
				cadena.pop_back();
			
			return (cadena);
		}
		
		/*********************************************************************/
		// Devuelve una NUEVA cadena, resultante de eliminar los primeros
		// caracteres separadores de "cadena". Los caracteres separadores son
		// el espacio en blanco, el tabulador y el salto de l�nea.
		// Usaremos la funci�n isspace() para simplificar el c�lculo.
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: el resultado de eliminar los �ltimos separadores de 
		// "cadena"
		/*********************************************************************/
		string EliminaPrimerosSeparadores (string cadena)
		{
			// Buscar el primer car�cter no espacio
			unsigned int pos = 0;
			while (pos < cadena.length() && isspace(cadena.at(pos))) pos++;
			
			string local;
			
			// Copiar todos los que quedan
			while (pos < cadena.length()) {
				local.push_back(cadena.at(pos));
				pos++;
			}
			
			return (local);
		}
		
		/*********************************************************************/
		// Devuelve una NUEVA cadena, resultante de eliminar los primeros 
		// �ltimos caracteres separadores de "cadena". Los caracteres 
		// separadores son el espacio en blanco, el tabulador y el salto de
		// l�nea
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: el resultado de eliminar los primeros y los �ltimos
		//           separadores de "cadena".
		/*********************************************************************/
		
		string EliminaPrimerosYUltimosSeparadores (string cadena)
		{
			string cadena_podada = EliminaPrimerosSeparadores (cadena);
			cadena_podada = EliminaUltimosSeparadores (cadena_podada);
			
			return (cadena_podada);
		}
		
		/*********************************************************************/
		// Devuelve "true" si "cadena" es la representaci�n textual de un
		// entero
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: "true" si "cadena" es la representaci�n textual de un int
		
		bool EsEntero (string cadena)
		{
			bool es_entero = true;
			
			cadena = EliminaPrimerosSeparadores (cadena);
			cadena = EliminaUltimosSeparadores (cadena);
			
			unsigned int long_cadena = cadena.length();
			
			if (long_cadena == 0) es_entero = false;
			else {
				
				// Si el primer car�cter es '+' � '-', perfecto. En ese caso
				// se pasa al siguiente car�cter (posici�n 19.
				
				unsigned int pos;
				if (cadena.at(0)=='-' || cadena.at(0) == '+') pos = 1;
				else pos = 0;
				
				while ((pos < long_cadena) && es_entero) {
					if(!isdigit(cadena.at(pos))) es_entero = false;
					else pos++;
				}
			}
			
			return (es_entero);
		}
		
		/*********************************************************************/

		bool EsReal (string cadena)
		{
			bool es_real = true;
			
			cadena = EliminaPrimerosSeparadores (cadena);
			cadena = EliminaUltimosSeparadores (cadena);
			
			unsigned int long_cadena = cadena.length();
			
			if (long_cadena == 0) es_real = false;
			else {
				
				// Si el primer car�cter es '+' � '-', perfecto. En ese caso
				// se pasa al siguiente car�cter (posici�n 19.
				
				unsigned int pos;
				if (cadena.at(0)=='-' || cadena.at(0) == '+') pos = 1;
				else pos = 0;
				
				// Bandera que se activa al encontrar un punto
				bool encontrado_un_punto = false;
				
				while ((pos < long_cadena) && es_real) {
					
					char c = cadena.at(pos);
					
					if (!isdigit(c)) {
						
						// Solo puede haber un punto.
						// Si se ha encontrado un punto y ya se hab�a
						// encontrado otro, error. Si no, activar la bandera
						// "encontrado_un_punto" (ya no puede haber m�s).
						
						if (c == '.') {
							if (encontrado_un_punto) es_real = false;
							else encontrado_un_punto = true;
						}
						
					    // Si no es un punto ni un d�gito --> error
						else es_real = false;
					}
					
					pos++;
					
				}  // while ((pos < long_cadena) && es_real)
				
			}  // else de if (long_cadena == 0)
			
			return (es_real);
		}
		
		/*********************************************************************/

};

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
	// Desplaza todos los caracteres una posici�n a la derecha
	// antes de copiar en "indice" en valor "nuevo".
	// PRE: 0 <= indice < total_utilizados
	
	void Inserta (int indice, char valor_nuevo)
	{
		if ((total_utilizados < TAMANIO) && (indice >= 0)
			&& (indice < total_utilizados)) {
			
			for (int i = total_utilizados ; i > indice ; i--)
				vector_privado[i] = vector_privado[i-1];
		
			vector_privado[indice] = valor_nuevo;
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
	// M�todo que consiste en la inserci�n de "otra" sobre la secuencia 
	// principal.
	// PRE: total_utilizados + otra.total_utilizados <= TAMANIO
    // PRE: 0 <= pos_insercion < total_utilizados 
	
	void InsertaSecuenciaCaracteres(int pos_insercion, SecuenciaCaracteres otra)
	{
		
		if (total_utilizados + otra.total_utilizados <= TAMANIO){
		                 
			for (int i = 0; i < otra.total_utilizados; i++){
			
				Inserta (pos_insercion, otra.vector_privado[i]);
				pos_insercion++;
			
			} // Fin del ciclo for que recorre la "otra" secuencia de caracteres
			
		} // Fin de la estructura condicional simple que se cumple s� y solo s�
		  // el n�mero total de casillas empleadas no supera al tama�o del 
		  // vector.De lo contrario, no se lleva a cabo la inserci�n.
		
	}
	
	/***********************************************************************/
	// M�todo que inserta la secuencia de caracteres "otra" en la cadena
	// de caracteres principal, pero sin hacer uso del m�todo Inserta. 
	// PRE: total_utilizados + otra.total_utilizados <= TAMANIO
    // PRE: 0 <= pos_insercion < total_utilizados
	
	void InsertaSecuenciaCaracteres2(int pos_insercion, 
	                                 SecuenciaCaracteres otra)
	{
		
		if (total_utilizados + otra.total_utilizados <= TAMANIO){
		                 
			for (int i = 0; i < otra.total_utilizados; i++){
			
				for (int j = total_utilizados; j > pos_insercion; j--){
				
					vector_privado[j] = vector_privado[j-1];
					
				} // Fin del ciclo for que recorre el la secuencia de caracteres
				  // hacia atr�s
				
					vector_privado[pos_insercion] = otra.vector_privado[i];
				
					pos_insercion++;  // Se actualiza la posici�n de inserci�n
					total_utilizados++;  // Se actualiza total_utilizados
				
			}  // Fin del ciclo for que recorre la "otra" secuencia.
			
		} // Fin de la estructura condicional simple que se cumple s� y solo s�
		  // el n�mero total de casillas empleadas no supera al tama�o del 
		  // vector. De lo contrario, no se lleva a cabo la inserci�n.
				
	}
	
	/***********************************************************************/
	// M�todo que devuelve la secuencia de caracteres que resulta de insertar
	// la secuencia "otra" en la cadena introducida incicialmente.
	// PRE: total_utilizados + otra.total_utilizados <= TAMANIO
    // PRE: 0 <= pos_insercion < total_utilizados	
	
	SecuenciaCaracteres InsertaSecuenciaCaracteres3 (int pos_insercion,
	                                                 SecuenciaCaracteres otra)
	{
		
		// Defino la nueva secuencia de caracteres que devolver� esta versi�n
		// n�mero 3 del m�todo InsertaSecuenciaCaracteres
		
		SecuenciaCaracteres cad_out;
	
		if (total_utilizados + otra.total_utilizados <= TAMANIO){
		
			for(int i = 0; i < total_utilizados; i++){
			
				cad_out.Aniade(vector_privado[i]);
			}
		
			for(int j = 0; j < otra.total_utilizados; j++){
			
				for (int k = cad_out.total_utilizados; k > pos_insercion; k--)
				
					cad_out.vector_privado[k] = cad_out.vector_privado[k-1];
			
				cad_out.vector_privado[pos_insercion] = 
				otra.vector_privado[j];
				
				// Actualizamos la posici�n de inserci�n
				
				pos_insercion++;
				
				// Actualizamos total_utilizados de la secuencia de salida
				
				cad_out.total_utilizados++;
			}
		}
		
		// Hasta aqu� todo bien, pero... �y si se da el caso de que al insertar
		// la "otra" secuencia, esta con la inicial sumen un n�mero de casillas
		// en el vector que almacena los caracteres, mayor que 50, que es el
		// n�mero m�ximo de casillas de las que dispone el vector en memoria.?
		// La respuesta est� en devolver simplemente la cadena introducida 
		// inicialemente, sin llevarse a cabo la inserci�n de la "otra" cadena
		// de caracteres.
		
		else{
			
			for(int i = 0; i < total_utilizados; i++)
				cad_out.Aniade(vector_privado[i]);
		}
	
			return (cad_out);
	}
	

private:
    	
    	// M�todo que rellena el vector privado del objeto a partir de un
		// dato string
		
		void TransStringChar (string cadena)
		{
			for(int i = 0; i < cadena.length(); i++){
				
				Aniade(cadena.at(i));
			}
		}	
		
		
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main()
{
	
	// Declaraci�n de datos
	
	string cadena;
	string insercion;
	int posicion;
	
	Lector lector;

	// Entrada de datos
	
	cout << "Introduzca una secuencia de caracteres: ";
	getline(cin, cadena);
	
	SecuenciaCaracteres sec(cadena);
	SecuenciaCaracteres sec_1(sec);
	SecuenciaCaracteres sec_2(sec);
	
	cout << "Introduzca la secuencia que desee insertar en la anterior: ";
	getline(cin, insercion);
	
	SecuenciaCaracteres secuencia (insercion);
	
	// pos_insercion
	
	lector.SetTitulo("Introduzca la posicion de insercion: ");
	posicion = lector.LeeEnteroEnRango(0, sec.TotalUtilizados() - 1);
	
	/***********************************************************************/
	
	cout << "PRUEBA DE METODOS DESTINADOS A LA INSERCION DE UNA SECUENCIA EN"
	        " OTRA";
	cout << endl;
	cout << endl;
	
	/***********************************************************************/
	  
	cout << "METODO DE INSERCION NUMERO 1";
	cout << endl;
	
	sec.InsertaSecuenciaCaracteres(posicion, secuencia);
	
	cout << "Secuencia final: " << sec.ToString();
	cout << endl;
	
	/***********************************************************************/
	
	cout << "METODO DE INSERCION NUMERO 2";
	cout << endl;
	
	sec_1.InsertaSecuenciaCaracteres2(posicion, secuencia);
	
	cout << "Secuencia final: " << sec_1.ToString();
	cout << endl;
	
	/***********************************************************************/
	
	cout << "METODO DE INSERCION NUMERO 3";
	cout << endl;
	
	SecuenciaCaracteres sec_3
	(sec_2.InsertaSecuenciaCaracteres3(posicion, secuencia));
	
	cout << "Secuencia final: " 
	<< sec_3.ToString() << endl << endl;
	
	
	return 0;
}			
			
