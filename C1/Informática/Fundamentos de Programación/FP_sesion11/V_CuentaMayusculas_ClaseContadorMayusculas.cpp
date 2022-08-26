/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee una serie de caracteres hasta que se introduce el
   terminador, que es '.', y cuenta y muestra el n�mero de veces que aparece
   cada may�scula.

   Entradas: 
    Una secuencia de caracteres.
    
   Salidas:
    N�mero de veces que aparece cada letra may�scula en la cadena introducida.
  
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <string>
using namespace std;  
 
/******************************************************************************/

class ContadorMayusculas
{
	
private:

	static const int NUM_LETRAS = 26;   // N�mero de letras que tiene el 
									    // abecedario
	int contador[NUM_LETRAS] = {0};     // Se inicializa el vector contador a 0
	
	
public:
	
	/***********************************************************************/
	// M�todo para aumentar el contador
	// Llamo al m�todo tipo bool privado creado para comprobar que es una 
	// letra may�scula.
	
	void IncrementaCuenta (char mayuscula)
	{
		if (EsLetraMayuscula(mayuscula)) contador[ mayuscula - 'A']++;  	
	}
	
	/***********************************************************************/
	// M�todo que devuelve el n�mero de veces que aparece cada letra may�scula
	// PRE: el dato tipo char introducido ha de ser una letra may�scula.
	
	int CuantasHay (char mayuscula)
	{
		
		int cuantas;
		
		cuantas = contador[ mayuscula - 'A'];
		
		return (cuantas);
		
	}
	
	/***********************************************************************/
	
	// M�todo destinado a mostrar en pantalla una cadena de caracteres en la
	// que se muestra el n�mero de veces que aparece cada una de las letras
	// may�sculas (para mostrar el n�mero, se hace un llamamiento al m�todo
	// CuantasHay), recorriendo las letras del abecedario, mediante un ciclo
	// for.
		
	string ToString (void)
		{
			string cadena =  "Generanado numero de apariciones de cada "
			                     " mayuscula: ";
			
			for(int i = 0; i < NUM_LETRAS; i++){
				
				char letra = 'A' + i;
				cadena = cadena + "\n" + "Letra " + letra + ": " +
				to_string(CuantasHay(letra)) + "\n";
			}
			
			return (cadena);
		}
			
	/***********************************************************************/
	
private:

	/***********************************************************************/
	
	// Para asegurar que el car�cter que se est� leyendo es una letra may�scula
	// y se tenga en cuenta para su c�mputo, en primer lugar, hay que asegurarse
	// de que dicho car�cter es una letra. Para ello, se ha de implementar un
	// m�todo que me de una respuesta a dicha pregunta; un m�todo tipo bool
	// que me devuelva un valor de verdad, en caso de que sea una letra, o
	// falso, en caso de que no lo sea.
	// Para ello, simplemente se declara una variable tipo bool, "es_una_letra"
	// A continuaci�n, se convierte el caracter que se ha de introducir (c), 
	// a may�scula, mediante la funci�n toupper(), y se establece una estructura
	// condicional doble tal que si se cumple que el caracter introducido se 
	//encuentra, en la p�gina de c�gidos ASCII, entre las posiciones de la letra 
	//A Y Z, ambas inclusive, entonces, la bandera toma el valor de verdad. 
	// Si esto no se cumple, la bandera torna en false.
	// Finalemente el m�todo devuelve el valor de la bandera.
	
	bool EsUnaLetra (char caracter)
	{
		
		// Declaraci�n de la variable tipo bool es_una_letra
		bool es_una_letra;
		
		char c = toupper(caracter);
		
		if ('A' <= c && c <= 'Z') es_una_letra = true;
			
		else es_una_letra = false;
		
		return (es_una_letra);
		
	}
	
	/***********************************************************************/
	
	// A continuaci�n, como lo que nos interesa es contar el n�mero de veces 
	// que aparece cada letra may�scula en una seucencia de caracteres, es
	// necesario crear un m�todo que determine si un car�cter, siendo letra, 
	// es adem�s may�scula.
	// Para ello, se crea un m�todo EsLetraMayuscula, el cual es de tipo bool
	// como el anterior, y que devolver� un valor de true, o false , en funci�n
	// de si la letra es may�scula o no lo es. Para determinar esto, se 
	// declara una variable tipo bool "es_mayuscula", y se establece una 
	// estructura condicional doble de tal forma que si el car�cter introducido
	// es una letra (se llama al m�todo anterior), y adem�s, se actualiza la 
	// bandera, asign�ndole el caracter convertido a may�scula, con la funci�n
	// toupper antes mencionada. En cualquier otro caso, la bandera toma el
	// valor faslo. Finalmente se devuelven dichos valores l�gicos.
	
	bool EsLetraMayuscula (char may)
	{
		
		// Declaro la variable tipo bool es_mayuscula
		bool es_mayuscula;
		
		if (EsUnaLetra(may)) es_mayuscula = (may = toupper(may)); // Acutalizo
		                                                          // bandera
		                                                          
		else es_mayuscula = false;
		
		return (es_mayuscula);
	}
	
	/***********************************************************************/
	
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main()
{
	
	// Declaraci�n de datos
	
	char caracter;
	
	const char TERMINADOR = '.';
	
	ContadorMayusculas contador;
	
	// Entrada de datos
	
	cout << "Introduzca una cadena de caracteres. ";
	cout << endl;
	cout << "Recuerde que para finalizar la secuencia ha de introducir el "
	        "terminador ("<< TERMINADOR <<"): ";
	cout << endl;	
	
	caracter = cin.get(); // Leo con esta funci�n ya que interesa que lea 
	                      // caracteres que son espacios en blanco.
	                      
	// Mientras que el usuario no introduzca el TERMINADOR, se seguir�n 
	// leyendo caracteres. Por tanto establezco el siguiente ciclo while
	
	while (caracter != TERMINADOR){
	
		// Se aumenta el recuento de may�sculas conforme se va leyendo
		
		contador.IncrementaCuenta(caracter);
		
		// Se contin�a leyendo con la misma funci�n pues, no cesa nuestro 
		// objetivo de contar letras may�sculas
		
		caracter = cin.get();
		
	}
	
	// Una vez introducida la secuencia de caracteres y habiendo realizado 
	// el c�mputo del n�mero de veces que aparece cada may�scula, se lleva
	// a cabo su muestra en pantalla, haciendo un llamamiento al m�todo 
	// ToString() de la clase Contador.
	
	cout << endl;
	cout << contador.ToString();
	cout << endl;
	
	/***********************************************************************/
	return 0;
}

		
		
		                    
	
	
	
	 
	 

	
		
	
			
					
			
			
			
			
	
	
			
