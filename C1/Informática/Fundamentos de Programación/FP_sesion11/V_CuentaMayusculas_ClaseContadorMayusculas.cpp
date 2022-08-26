/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee una serie de caracteres hasta que se introduce el
   terminador, que es '.', y cuenta y muestra el número de veces que aparece
   cada mayúscula.

   Entradas: 
    Una secuencia de caracteres.
    
   Salidas:
    Número de veces que aparece cada letra mayúscula en la cadena introducida.
  
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <string>
using namespace std;  
 
/******************************************************************************/

class ContadorMayusculas
{
	
private:

	static const int NUM_LETRAS = 26;   // Número de letras que tiene el 
									    // abecedario
	int contador[NUM_LETRAS] = {0};     // Se inicializa el vector contador a 0
	
	
public:
	
	/***********************************************************************/
	// Método para aumentar el contador
	// Llamo al método tipo bool privado creado para comprobar que es una 
	// letra mayúscula.
	
	void IncrementaCuenta (char mayuscula)
	{
		if (EsLetraMayuscula(mayuscula)) contador[ mayuscula - 'A']++;  	
	}
	
	/***********************************************************************/
	// Método que devuelve el número de veces que aparece cada letra mayúscula
	// PRE: el dato tipo char introducido ha de ser una letra mayúscula.
	
	int CuantasHay (char mayuscula)
	{
		
		int cuantas;
		
		cuantas = contador[ mayuscula - 'A'];
		
		return (cuantas);
		
	}
	
	/***********************************************************************/
	
	// Método destinado a mostrar en pantalla una cadena de caracteres en la
	// que se muestra el número de veces que aparece cada una de las letras
	// mayúsculas (para mostrar el número, se hace un llamamiento al método
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
	
	// Para asegurar que el carácter que se está leyendo es una letra mayúscula
	// y se tenga en cuenta para su cómputo, en primer lugar, hay que asegurarse
	// de que dicho carácter es una letra. Para ello, se ha de implementar un
	// método que me de una respuesta a dicha pregunta; un método tipo bool
	// que me devuelva un valor de verdad, en caso de que sea una letra, o
	// falso, en caso de que no lo sea.
	// Para ello, simplemente se declara una variable tipo bool, "es_una_letra"
	// A continuación, se convierte el caracter que se ha de introducir (c), 
	// a mayúscula, mediante la función toupper(), y se establece una estructura
	// condicional doble tal que si se cumple que el caracter introducido se 
	//encuentra, en la página de cógidos ASCII, entre las posiciones de la letra 
	//A Y Z, ambas inclusive, entonces, la bandera toma el valor de verdad. 
	// Si esto no se cumple, la bandera torna en false.
	// Finalemente el método devuelve el valor de la bandera.
	
	bool EsUnaLetra (char caracter)
	{
		
		// Declaración de la variable tipo bool es_una_letra
		bool es_una_letra;
		
		char c = toupper(caracter);
		
		if ('A' <= c && c <= 'Z') es_una_letra = true;
			
		else es_una_letra = false;
		
		return (es_una_letra);
		
	}
	
	/***********************************************************************/
	
	// A continuación, como lo que nos interesa es contar el número de veces 
	// que aparece cada letra mayúscula en una seucencia de caracteres, es
	// necesario crear un método que determine si un carácter, siendo letra, 
	// es además mayúscula.
	// Para ello, se crea un método EsLetraMayuscula, el cual es de tipo bool
	// como el anterior, y que devolverá un valor de true, o false , en función
	// de si la letra es mayúscula o no lo es. Para determinar esto, se 
	// declara una variable tipo bool "es_mayuscula", y se establece una 
	// estructura condicional doble de tal forma que si el carácter introducido
	// es una letra (se llama al método anterior), y además, se actualiza la 
	// bandera, asignándole el caracter convertido a mayúscula, con la función
	// toupper antes mencionada. En cualquier otro caso, la bandera toma el
	// valor faslo. Finalmente se devuelven dichos valores lógicos.
	
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
	
	// Declaración de datos
	
	char caracter;
	
	const char TERMINADOR = '.';
	
	ContadorMayusculas contador;
	
	// Entrada de datos
	
	cout << "Introduzca una cadena de caracteres. ";
	cout << endl;
	cout << "Recuerde que para finalizar la secuencia ha de introducir el "
	        "terminador ("<< TERMINADOR <<"): ";
	cout << endl;	
	
	caracter = cin.get(); // Leo con esta función ya que interesa que lea 
	                      // caracteres que son espacios en blanco.
	                      
	// Mientras que el usuario no introduzca el TERMINADOR, se seguirán 
	// leyendo caracteres. Por tanto establezco el siguiente ciclo while
	
	while (caracter != TERMINADOR){
	
		// Se aumenta el recuento de mayúsculas conforme se va leyendo
		
		contador.IncrementaCuenta(caracter);
		
		// Se continúa leyendo con la misma función pues, no cesa nuestro 
		// objetivo de contar letras mayúsculas
		
		caracter = cin.get();
		
	}
	
	// Una vez introducida la secuencia de caracteres y habiendo realizado 
	// el cómputo del número de veces que aparece cada mayúscula, se lleva
	// a cabo su muestra en pantalla, haciendo un llamamiento al método 
	// ToString() de la clase Contador.
	
	cout << endl;
	cout << contador.ToString();
	cout << endl;
	
	/***********************************************************************/
	return 0;
}

		
		
		                    
	
	
	
	 
	 

	
		
	
			
					
			
			
			
			
	
	
			
