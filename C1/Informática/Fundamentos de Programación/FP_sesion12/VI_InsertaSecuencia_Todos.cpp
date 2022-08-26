/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee una secuencia de caracteres e inserta otra secuencia nueva
   en una posición determinada por el usuario.
   
   Para ello, se ha hecho uso de la clase SecuenciaCaracteres, a la cual se le
   han añadido tres métodos nuevos:
   
   1º)void InsertaSecuenciaCaracteres(int pos_insercion, 
      SecuenciaCaracteres otra) 
      
      Este método recibe una posición determinada por un número entero, y 
      un objeto de la clase SecuenciaCaracteres; la secuencia a introducir en
      la inicial. Además, se hace uso del método Inserta(int pos_insercion, 
	  char valor_nuevo), para llevar a cabo dicha inserción.
	  
	2ª)void InsertaSecuenciaCaracteres2(int pos_insercion, 
	   SecuenciaCaracteres otra) 
	   
	   Este método es una evolución del método 1ª). Ambos difieren en que en 
	   este último no se hace ningún llamamiento al método Inserta.
	   
	3ª)SecuenciaCaracteres InsertaSecuenciaCaracteres3 (int pos_insercion,
	   SecuenciaCaracteres otra)  
	   
	   Este método devuelve una nueva secuencia de tal forma que las secuencia 
	   original (la implícita) y la secuencia "otra" no se modifican. 
	     
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
		
		// Método Set para fijar el campo "titulo"
		
		void SetTitulo (string cad)
		{
			titulo = cad;
		}
		
		/*********************************************************************/
		// Lee un dato int.
		// La lectura está etiquetada con "titulo"
		// La lectura se efectúa repetidamente hasta que se introduce un valor
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
		// La lectura está etiquetada con "titulo"
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
		// La lectura está etiquetada con "titulo"
		
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
		// La lectura está etiquetada con "titulo"
		// La lectura se efectúa repetidamente hasta que se introduce un valor
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
		// La lectura está etiquetada con "titulo"
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
		// La lectura está etiquetada con "titulo"
		
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
		// Devuelve una NUEVA cadena, resultante de eliminar los últimos
		// caracteres separadores de "cadena". Los caracteres separadores son
		// el espacio en blanco, el tabulador y el salto de línea.
		// Usaremos la función isspace() para simplificar el cálculo.
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: el resultado de eliminar los últimos separadores de 
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
		// el espacio en blanco, el tabulador y el salto de línea.
		// Usaremos la función isspace() para simplificar el cálculo.
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: el resultado de eliminar los últimos separadores de 
		// "cadena"
		/*********************************************************************/
		string EliminaPrimerosSeparadores (string cadena)
		{
			// Buscar el primer carácter no espacio
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
		// últimos caracteres separadores de "cadena". Los caracteres 
		// separadores son el espacio en blanco, el tabulador y el salto de
		// línea
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: el resultado de eliminar los primeros y los últimos
		//           separadores de "cadena".
		/*********************************************************************/
		
		string EliminaPrimerosYUltimosSeparadores (string cadena)
		{
			string cadena_podada = EliminaPrimerosSeparadores (cadena);
			cadena_podada = EliminaUltimosSeparadores (cadena_podada);
			
			return (cadena_podada);
		}
		
		/*********************************************************************/
		// Devuelve "true" si "cadena" es la representación textual de un
		// entero
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: "true" si "cadena" es la representación textual de un int
		
		bool EsEntero (string cadena)
		{
			bool es_entero = true;
			
			cadena = EliminaPrimerosSeparadores (cadena);
			cadena = EliminaUltimosSeparadores (cadena);
			
			unsigned int long_cadena = cadena.length();
			
			if (long_cadena == 0) es_entero = false;
			else {
				
				// Si el primer carácter es '+' ó '-', perfecto. En ese caso
				// se pasa al siguiente carácter (posición 19.
				
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
				
				// Si el primer carácter es '+' ó '-', perfecto. En ese caso
				// se pasa al siguiente carácter (posición 19.
				
				unsigned int pos;
				if (cadena.at(0)=='-' || cadena.at(0) == '+') pos = 1;
				else pos = 0;
				
				// Bandera que se activa al encontrar un punto
				bool encontrado_un_punto = false;
				
				while ((pos < long_cadena) && es_real) {
					
					char c = cadena.at(pos);
					
					if (!isdigit(c)) {
						
						// Solo puede haber un punto.
						// Si se ha encontrado un punto y ya se había
						// encontrado otro, error. Si no, activar la bandera
						// "encontrado_un_punto" (ya no puede haber más).
						
						if (c == '.') {
							if (encontrado_un_punto) es_real = false;
							else encontrado_un_punto = true;
						}
						
					    // Si no es un punto ni un dígito --> error
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
	// Desplaza todos los caracteres una posición a la derecha
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
	// Método que consiste en la inserción de "otra" sobre la secuencia 
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
			
		} // Fin de la estructura condicional simple que se cumple sí y solo sí
		  // el número total de casillas empleadas no supera al tamaño del 
		  // vector.De lo contrario, no se lleva a cabo la inserción.
		
	}
	
	/***********************************************************************/
	// Método que inserta la secuencia de caracteres "otra" en la cadena
	// de caracteres principal, pero sin hacer uso del método Inserta. 
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
				  // hacia atrás
				
					vector_privado[pos_insercion] = otra.vector_privado[i];
				
					pos_insercion++;  // Se actualiza la posición de inserción
					total_utilizados++;  // Se actualiza total_utilizados
				
			}  // Fin del ciclo for que recorre la "otra" secuencia.
			
		} // Fin de la estructura condicional simple que se cumple sí y solo sí
		  // el número total de casillas empleadas no supera al tamaño del 
		  // vector. De lo contrario, no se lleva a cabo la inserción.
				
	}
	
	/***********************************************************************/
	// Método que devuelve la secuencia de caracteres que resulta de insertar
	// la secuencia "otra" en la cadena introducida incicialmente.
	// PRE: total_utilizados + otra.total_utilizados <= TAMANIO
    // PRE: 0 <= pos_insercion < total_utilizados	
	
	SecuenciaCaracteres InsertaSecuenciaCaracteres3 (int pos_insercion,
	                                                 SecuenciaCaracteres otra)
	{
		
		// Defino la nueva secuencia de caracteres que devolverá esta versión
		// número 3 del método InsertaSecuenciaCaracteres
		
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
				
				// Actualizamos la posición de inserción
				
				pos_insercion++;
				
				// Actualizamos total_utilizados de la secuencia de salida
				
				cad_out.total_utilizados++;
			}
		}
		
		// Hasta aquí todo bien, pero... ¿y si se da el caso de que al insertar
		// la "otra" secuencia, esta con la inicial sumen un número de casillas
		// en el vector que almacena los caracteres, mayor que 50, que es el
		// número máximo de casillas de las que dispone el vector en memoria.?
		// La respuesta está en devolver simplemente la cadena introducida 
		// inicialemente, sin llevarse a cabo la inserción de la "otra" cadena
		// de caracteres.
		
		else{
			
			for(int i = 0; i < total_utilizados; i++)
				cad_out.Aniade(vector_privado[i]);
		}
	
			return (cad_out);
	}
	

private:
    	
    	// Método que rellena el vector privado del objeto a partir de un
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
	
	// Declaración de datos
	
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
			
