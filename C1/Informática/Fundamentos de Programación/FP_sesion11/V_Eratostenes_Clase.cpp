/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que pide un número entero positivo y se calculan todos sus primos
   menores o iguales que él, mostrándose en pantalla. Además, se muestra
   cuántos primos se han calculado en total, y cuál es el mayor de todos 
   ellos. Finalmente se pide que introduzca la posición del primo que desea 
   que se muestre, para finalemente mostrar el número primo que se encuentra 
   en dicha posición. 
   Todo esto se realiza mediante métodos de la clase Eratostenes, que se ha
   definido más abajo. La lectura del número entero positivo que ha de 
   introducir el usuario se ha realizado mediante dos de los métodos de la
   clase Lector.
   
   Entradas: 
    Un número entero positivo.
    
   Salidas:
    Los números primos menores o iguales que el número introducido.
    El total de números primos calculados.
    El mayor de los primos.
    El elemento de que ocupa la posición k-ésima, elegida por el usuario.
   
    
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <string>
#include <iomanip>
using namespace std;  
 
/******************************************************************************/

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


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


class Eratostenes
{
	
private: 


	// Mostrar DATOS_POR_LINEA núms. por línea
	static const int DATOS_POR_LINEA = 10; 

	// Todos los primos calculados serán menores que TAMANIO.
	static const int TAMANIO = 500;
	
	int vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados; // Número de casillas ocupadas


public:

	/***********************************************************************/

	// Constructor sin argumentos
	
	Eratostenes (): total_utilizados (0)
	{}
	
	/***********************************************************************/

	void CalculaHasta(int n)
	{
		
		// Empleremos un vector de datos lógicos para la criba de manera que  
		// "es_primo[i]" será TRUE si "i" es primo. 
		
		bool es_primo[TAMANIO+1];
	
		// Inicialmente se considerarán todos primos y se irán "tachando" 
		// (fijándose a FALSE) los valores no-primos. 
	
		for (int i = 0; i < n; i++) 
		
			es_primo[i] = true;

		// Criba 
	
		for (int i=2; i*i <= n; i++) { // empezar por num=2 y 
										        // terminar si num^2 > limite		
			if (es_primo[i]) {

				for (int k=2; k*i <= n; k++) { // marcar los múltiplos de   
					es_primo[k*i] = false;		  // num como no-primos
				}
			} // if (es_primo[num])

		} // for num
		
		// Si los primos caben en el vector "primos", escribirlos en dicho 
		// vector, en orden. SOLO SE ESCRIBEN LOS PRIMOS. 
		
		int contador_primos = 0;
	
		if (contador_primos <= TAMANIO) {
		
			// Ya están "tachados" los números no-primos en "es_primo".  
			// Ahora recorremos "es_primo" completamente y copiamos a 
			// "primos" únicamente los que permacenen a "true". 
	
			for (int i = 1; i <= n; i++) { 
										
				if (es_primo[i]) {			 
					vector_privado[total_utilizados] = i; // Añadir i a primos
					total_utilizados++;  		   		  // Actualizar 
												   		  // "total_utilizados"
				}
			
			} // for
		
			// Mostrar los primos calculados 
	
			for (int i=1; i<=total_utilizados; i++) 
				cout <<setw(4) << vector_privado[i-1] 
				               << ((i%DATOS_POR_LINEA!=0)?" ":"\n");
			cout << endl;
		
		
		}
		
	}
	
	/***********************************************************************/

	// Consultar cuántos primos se han calculado en total; equivalente a que
	// nos devuelva el número de casillas que se han empleado en el vector, de
	// entre las que están disponibles.

	int TotalCalculados(void)
	{
		return(total_utilizados);
		
	}
	
	/***********************************************************************/
	
	// Método destinado a la devolución del elemento que ocupe la posición
	// k-ésima en el vector en el que se almancenan los primos.
	
	int Elemento(int k)
	{
		return (vector_privado[k]);
			
	}
	
	/***********************************************************************/
	
	// Método para la extracción del número primo mayor ( simplemente devuelve
	// el último primo calculado)
	
	int GetMaximo()
	{
		return (vector_privado[total_utilizados-1]);
		
	}
	
	/***********************************************************************/
	
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main()
{
	
	// Datos de entrada
	
	int numero;
	
	const int MAX_PRIMOS = 500;
	
	Lector lector;
	
	// Entrada de datos
	
	cout << "CRIBA DE ERATOSTENES";
	cout << endl;
	
	lector.SetTitulo("\tIntroduzca un numero entero positivo: ");
	numero = lector.LeeEnteroEnRango(1, MAX_PRIMOS);
	                                
	Eratostenes criba;                             
	                                
	// Cálculos
	
	cout <<endl<<endl;
	
	cout << "Los numeros primos menores que " << numero << " son: ";
	cout << endl << endl;
	
	// Se llama al método CalculaHata para que calcule y muestre los números
	// primos menores o iguales que el número introducido por el usuario.
	
	criba.CalculaHasta(numero);

	cout << endl;
	
	// Se muestra el número de primos calculados mediante el llamamiento al
	// método TotalCalculados
	
	int tope = criba.TotalCalculados();
	cout << "Hay calculados un total de " << tope << " numeros primos.";
	
	cout << endl<<endl;
	
	// Se obtiene el mayor de los primos mediante el método GetMaximo
	
	int max = criba.GetMaximo();
	cout << "El mayor de los primos es: " << max; 
	
	cout <<endl<<endl;
	
	// A continuación, se pide que se introduzca la posición en el vector de
	// un número primo, para posteriormente mostrar en pantalla el número
	// primo que ocupaba dicha posición en el vector.
	
	int posicion;
	cout << "Introduzca la posicion del termino que desea buscar: ";
	cin  >> posicion;

	cout << criba.Elemento(posicion);
	cout << endl;
	
	/***********************************************************************/
	return 0;
	
}
	
	

