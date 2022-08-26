/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Este es un programa en el que se trabaja con la clase DepositoBancario, y 
   se llevan a cabo dos operaciones:
   
   	1�) Se calcula el capital final que hay en el dep�sito en funci�n del 
       inter�s aplicado y el n�mero de a�os durante los cuales se ha aplicado
       dicho inter�s. Para ello, se ha implementado en la clase un m�todo
       void IncrementaCapitalEnAnios (int anios).
    
	2�) Se calculan los a�os que han de transcurrir para que, partiendo de 
	    un capital incial no nulo, y aplicando un determinado inter�s, se 
		llegue a tener como capital, al menos el doble de capital de partida. 

   PDA: Se ha hecho uso tanto de la clase Lector como de la clase Dinero.
	
   Entradas: 
    El capital incial (euros y centimos).
    El interes a aplicar.
    El n�mero de a�os durante los que se va a estar aplicando el inter�s.
    
   Salidas:
    El capital final.
    El n�mero de a�os para doblar el capital.
   	
   
    
*/               
/******************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
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


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////  
       
class Dinero
{

private:

	// PRE: 0 <= euros
	int euros;  // Num. de euros

	// PRE: 0 <= centimos < 100
	int centimos; // Num. de c�ntimos
	
public:

	/***********************************************************************/
	// Constructor sin argumentos.
	
	Dinero (void) : euros(0), centimos(0)
	{ }
	
	/***********************************************************************/
	// Constructor con un argumento.
	// Recibe: cantidad, n�mero de euros (double). 
	// 		   Si es un valor con decimales indica que tiene c�ntimos. 
	//         Por ejemplo: 7.45 indicar� 7 euros y 45 c�ntimos. 
	//
	// PRE:  0 <= cantidad

	Dinero (double cantidad) 
	{	
		euros = (cantidad*100) / 100; 
		centimos = ((int) (cantidad*100)) % 100;
	}		
			
	/***********************************************************************/
	// Constructor con dos argumentos.
	// Recibe: los_euros, n�m. de euros
	//		   los_centimos, el n�m. de c�ntimos. Si "los_centimos" es mayor 
	//				o igual que 100 ajusta su valor para garantizar la validez 
	//				del campo "centimos" (entre 0 y 99) y actualiza el valor 
	//				del campo "euros" coherentemente. 
	// PRE:  0 <= los_euros
	// PRE:  0 <= los_centimos
	// POST: 0 <= centimos < 100

	Dinero (int los_euros, int los_centimos)
	{
		centimos = los_centimos%100;
		euros    = los_euros + (los_centimos/100);
	}

	/***********************************************************************/
	// M�todos Get

	// Devuelve el n�mero de euros completos
	
	int GetEuros (void)
	{
		return (euros);
	}

	// Devuelve el n�mero de c�ntimos
	
	int GetCentimos (void)
	{
		return (centimos);
	}

	// Devuelve el valor num�rico del dato "Dinero". 
	// Por ejemplo, Si el estado del objeto es {euros=7, centimos=45} 
	// devuelve 7.45 
	
	double GetValor (void)
	{
		return (euros+(centimos/100.0));
	}
	
	/***********************************************************************/
	// Modifica el valor de los dos campos, sumando los valores dados en 
	// los par�metros "euros_suman" y "centimos_suman".  

	void Incrementa (int euros_suman, int centimos_suman) {
		IncrementaCentimos (centimos_suman);
		IncrementaEuros (euros_suman);
	}
	
	/***********************************************************************/	
	// Modifica el valor guardado en el objeto, sumando la cantidad dada 
	// en el valor num�rico "cantidad_suma"

	void Incrementa (double cantidad_suma) 
	{	
		int los_euros = (cantidad_suma*100) / 100; 
		int los_centimos = (cantidad_suma - los_euros)*100;
		
		Incrementa (los_euros, los_centimos); 
	}
	
	
	// MEJOR ESTO   NO REPETIR C�DIGO
	
	/* Dinero Incrementa (double cantidad_suma)
	{
		return (Incrementa (Dinero (cantidad_suma)));
	}
	
	Todas las sobrecargas de una misma funci�n al final se van a traducir en 
	que si tengo n sobrecargas, n-1 van a convertirse unicamente en funcones 
	que trabajan sobre otra.
	
	/***********************************************************************/
	// Calcula y devuelve el resultado de sumar cantidad a la cantidad de 
	// dinero del objeto impl�cito. 
	// PRE: 0 <= cantidad
	
	Dinero Incrementa (Dinero cantidad)
	{
		int les_euros    = euros + cantidad.euros;
		int les_centimos = centimos + cantidad.centimos;
		
		Dinero cant_final (les_euros, les_centimos);
		
		return (cant_final);
		
	}
	
	/***********************************************************************/

	Dinero Decrementa (Dinero cantidad)
	{
		
		int les_euros;
		int les_centimos;
	
		if (cantidad.euros > euros){
		
			les_euros    = euros;
			les_centimos = centimos;
			
		}
			
		else
		{
			if (cantidad.centimos <= centimos){
				
				les_euros    = (euros - cantidad.euros);
				les_centimos = (centimos - cantidad.centimos);

			}
			
			else 
			{
				if(cantidad.centimos > centimos){
			
			
				les_euros    = euros - cantidad.euros;
				les_centimos = 100 + centimos - cantidad.centimos;	
				
				}
				
			}
			
			if (euros == cantidad.euros){
				
				if (centimos < cantidad.centimos){
					
					les_euros = euros;
					les_centimos = centimos;
				}
				
				else{
					
					les_euros = euros - cantidad.euros;
					les_centimos = centimos - cantidad.centimos;
				}
			}
			
	
		}
		
		Dinero cant_final (les_euros, les_centimos);
		
		return (cant_final);
		
	}
	
	/***********************************************************************/
	// Calcula y devuelve el resultado de restar cantidad a la cantidad de 
	// dinero del objeto impl�cito. 
	// PRE: 0 <= cantidad
	
	Dinero Decrementa (double cantidad)  
	{
		
		int les_euros;
		int les_centimos;
		
		Dinero otra_cantidad (cantidad);
		
		if (euros < otra_cantidad.euros){
			
			les_euros = euros;
			les_centimos = centimos;
			
		}
		
		else
		{
			if (otra_cantidad.centimos <= centimos){
				
				les_euros    = euros - otra_cantidad.euros;
				les_centimos = centimos - otra_cantidad.centimos;
			
		
			}
		
			
			else 
			{
				if (otra_cantidad.centimos > centimos){
			
				les_euros    = euros - otra_cantidad.euros;
				les_centimos = 100 + centimos - otra_cantidad.centimos;	
				
				}
			}
			
			
			if (euros == otra_cantidad.euros){
				
				if (centimos < otra_cantidad.centimos){
					
					les_euros = euros;
					les_centimos = centimos;
				}
				
				else{
					
					les_euros = euros - otra_cantidad.euros;
					les_centimos = centimos - otra_cantidad.centimos;
				}
			}	
			
		
		}
		
		Dinero cant_final (les_euros, les_centimos);
		
		return (cant_final);
		
	}
	
	/***********************************************************************/
	
	Dinero Modifica (double cantidad)
	{
		
		int euross;
		int centimoss;
		
		if (cantidad >= 0){
			
			Dinero incrementar (cantidad);
			
			euross = euros + incrementar.GetEuros();
			centimoss = centimos + incrementar.GetCentimos();
		}
		
		else{
			
			cantidad = abs(cantidad);
			Dinero decrementar (cantidad);
			
			bool mayor_o_igual = (EsMayor(decrementar)||EsIgual(decrementar));
			
			if (mayor_o_igual){
				
				euross    = euros;
				centimoss = centimos;
			}
			
			else{
				
				Dinero cant_final (Diferencia (decrementar));
				
				euross    = cant_final.GetEuros();
				centimoss = cant_final.GetCentimos();
			}
		}
		
		Dinero modifica (euross, centimoss);
		
		return (modifica);
	}
	
	/***********************************************************************/	
	
	bool EsMayor (Dinero otro)
	{
		
		bool mayor;
		
		if (otro.euros < euros) mayor = true;
		
		else
		{
			if (otro.euros >= euros) mayor = false;
			
			else
			{
				if (otro.centimos >= centimos) mayor = false;
				
				else mayor = true;
				
			}
		}
		
		return (mayor);
	}
	
	/***********************************************************************/	
		
	
	bool EsMayor (double cantidad)
	{
	
		Dinero otro (cantidad);
		
		bool mayor;
		
		if (otro.euros < euros) mayor = true;
		
		else
		{
			if (otro.euros >= euros) mayor = false;
			
			else
			{
				if (otro.centimos >= centimos) mayor = false;
				
				else mayor = true;
				
			}
		}
		
		return (mayor);
		
	}
	
	/***********************************************************************/		
	
	bool EsMenor (Dinero otro)
	{
		
		bool menor;
		
		if (otro.euros > euros) menor = true;
		
		else
		{
			if (otro.euros < euros) menor = false;
			
			else
			{
				if (otro.centimos > centimos) menor = true;
			
				if (otro.centimos < centimos) menor = false;
					
				if (otro.centimos == centimos ) menor = false;
				
			}
			
		}
		
		return (menor);	
		
	}
	
	/***********************************************************************/		
	
	bool EsMenor (double cantidad)
	{
		
		Dinero otro (cantidad);
		bool menor;
		
		if (otro.euros > euros) menor = true;
		
		else
		{
			if (otro.euros < euros) menor = false;
			
			else
			{
				if (otro.centimos > centimos) menor = true;
			
				if (otro.centimos < centimos) menor = false;
					
				if (otro.centimos == centimos ) menor = false;
				
			}
			
		}
		
		return (menor);	
		
	}
	
	/***********************************************************************/		
	
	bool EsIgual (Dinero otro)
	{
		
		return ((otro.euros == euros) && (otro.centimos == centimos));
		
	}
	
	/***********************************************************************/	
	
	
	bool EsIgual (double cantidad)
	{
		
		Dinero cant (cantidad);
		
		return ((cant.euros == euros) && (cant.centimos == centimos));
		
	}
	
	/***********************************************************************/		
	
	Dinero Diferencia (Dinero otro)
	{
		
		int les_euros;
		int les_centimos;
		
		if (otro.centimos <= centimos){
				
				les_euros    = euros - otro.euros;
				les_centimos = centimos - otro.centimos;
		
		}
		
			
		else 
		{
			if(otro.centimos > centimos){
			
			les_euros    = euros - otro.euros - 1;
			les_centimos = 100 + centimos - otro.centimos;	
			
			}
		}
			
		Dinero cant_final (les_euros, les_centimos);
		
		
		return (cant_final);
		
	}
	
	/***********************************************************************/		
	
	Dinero Diferencia (double otro)
	{
	
		Dinero diferencia (otro);
		
		int les_euros;
		int les_centimos;
		
		if (diferencia.centimos <= centimos){
				
				les_euros    = euros - diferencia.euros;
				les_centimos = centimos - diferencia.centimos;
		
		}
		
			
		else 
		{
			if(diferencia.centimos > centimos)
			{
			
			les_euros    = euros - diferencia.euros -1;
			les_centimos = 100 + centimos - diferencia.centimos;	
			
			}
		}
			
		Dinero cant_final (les_euros, les_centimos);
		
		
		return (cant_final);
		
	}
	
	/***********************************************************************/

	// Representar en forma de cadena el valor de un dato "Dinero"
	// Recibe: num_casillas_euros, el n�mero de casillas con el que queremos 
	// formatear el valor de los euros. Si el n�mero de casillas 
	// es mayor que el n�mero de d�gitos se rellenar�n con 
	// el car�cter "hueco"
	// hueco, caractere que se usar� para rellenar los huecos. 
	// 
	// Devuelve: un string con la representaci�n textual de un dato Dinero.  

	string ToString (void)
	{
		string cadena;
			
		cadena = to_string(euros) + " euros y " + to_string(centimos) + 
		" centimos";
			
		return(cadena);
	
	}

	/***********************************************************************/
	
private: 

	/***********************************************************************/
	// Modifica �nicamente el valor del campo "euros" 

	void IncrementaEuros (int euros_suman) {
		euros = euros + euros_suman;
	}

	// Modifica el valor del campo "centimos". Si "centimos_suman" es mayor 
	// o igual que 100 ajusta su valor para garantizar la validez del campo 
	// "centimos" (entre 0 y 99) y actualiza el valor del campo "euros".
	 
	void IncrementaCentimos (int centimos_suman) {
		int total_centimos = centimos + centimos_suman;
		centimos = total_centimos % 100;
		euros    = euros + (total_centimos / 100);
	}

	/***********************************************************************/
	// Calcula y devuelve en n�mero de d�gitos de "num"
	
	int NumDigitos (int num) 
	{	
		int	num_digitos = 1; 
		 
		while (num/10 > 0) {
			num /= 10; 
			num_digitos++;
		}
		return (num_digitos); 
	}
	
	/***********************************************************************/	
		
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

class DepositoBancario {
	
private:
	
	Dinero capital; // PRE: 0 < capital.GetValor()
	
	double interes; // PRE: 0 < interes <= 100
	
public:

	/***********************************************************************/
	// Constructor con argumentos
	
	DepositoBancario (Dinero el_capital, double el_interes)
	
	: capital(el_capital), interes(el_interes)  {}
	
	/***********************************************************************/
	// APARTADO A):
	
	// M�todo que incrementa el capital del dep�sito bancario, en funci�n del
	// inter�s que se le vaya a aplicar, y el n�mero de a�os durante los que
	// se va a estar aplicando dicho inter�s
	// PRE: 0 <= anios <= 20
	
	void IncrementaCapitalEnAnios (int anios)
	{
		
		double incremento;
		
		// Cada a�o, voy incrementando el capital, en funci�n del inter�s
		
		for (int i = 0; i < anios; i++){
			
			incremento = (capital.GetValor() * (interes/100));
			
			capital.Incrementa(incremento);
			
		}
		
	}
	
	/***********************************************************************/
	// APARTADO B)
	
	// M�todo que calcula el n�mero de a�os que han de pasar hasta llegar a 
	// doblar como m�nimo el capital de partida de un dep�sito bancario.
	
	int AniosDoblarCapital (void)
	{
	
		int contador_anios_doblaje = 0;  // Se inicializa el n�mero de a�os a 0
		double incremento_capital;
		double doble_capital = 2*capital.GetValor();
 
		for (int i = 0; capital.GetValor() < doble_capital; i++){
			
			incremento_capital = ((capital.GetValor() )* (interes/100));
			
			capital.Incrementa(incremento_capital);
			
			contador_anios_doblaje++;
			
		}
		
		return (contador_anios_doblaje);
		
	}
	
	/***********************************************************************/
	// M�todo ToString , que deuvelve una cadena en el que se informa del
	// n�mero de euros y c�ntimos del dep�sito y el inter�s que se va a 
	// aplicar
	
	string ToString ()
	{
		
		string cadena;
		
		cadena = ("El dinero del que se dispone en el deposito bancario "
		 "tras la aplicacion de un interes del " + to_string (interes) + "%" +
		" es " + to_string(capital.GetEuros()) + " euros y " + 
		to_string (capital.GetCentimos()) + " centimos." );
		
		return (cadena);
		
	}
	
	/***********************************************************************/
	
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main ()
{
	
	// Declaraci�n de datos
	
	int euros_deposito, centimos_deposito;
	double interes;
	int anios;
	
	Lector lee;
	
	// Entrada de datos
	
	lee.SetTitulo("Introduzca el numero de euros que hay en el deposito: ");
	euros_deposito = lee.LeeEnteroMayorOIgual(0);
	
	lee.SetTitulo("Introduzca el numero de centimos que hay en el deposito: ");
	
	// Ahora caben dos casos: 
	// 		- Si el numero de euros introducidos es cero, se ha de leer el
	//       numero de c�ntimos como un entero mayor o igual que 1, porque no
	//       tiene sentido usar la aplicaci�n de un inter�s anual si se 
	//       el dep�sito est� vac�o.
	//      - En otro caso, si el n�mero de euros no es cero, ya s� que puede
	//       leerse el n�mero de c�ntimos como un entero mayor o igual que cero.
	
	// Por lo tanto hay que establecer una estructura condicional doble de la
	// siguiente forma:
	
	if (euros_deposito == 0) centimos_deposito = lee.LeeEnteroMayorOIgual(1);
	else centimos_deposito = lee.LeeEnteroMayorOIgual(0);
	
	lee.SetTitulo("Introduzca el interes que desea aplicar al capital: ");
	interes = lee.LeeEnteroEnRango(0,10);
		
	lee.SetTitulo("Introduzca el numero de a�os durante los que desea aplicar "
	              "el capital: ");
    anios = lee.LeeEnteroEnRango(1, 20);
	
	cout << endl;
	cout << endl;
	
	// Operaciones y salida de datos
	
	// Creaci�n del objeto Dinero
	
	Dinero capital (euros_deposito, centimos_deposito);
	
	// Creaci�n de objetos DepositoBancario
	
	DepositoBancario deposito (capital, interes);
	
	// Creaci�n de otro objeto DepositoBancario como copia del anterior, con
	// el objetivo de conservar el capital incial del dep�sito sin haberle 
	// aplicado en inter�s. Esto lo hago para usar el capital incial en el 
	// apartado B)
	
	DepositoBancario deposito2 (deposito); 
	
	
	// APARTADO A)
	
	cout << endl;
	cout << "CAPITAL FINAL";
	cout << endl;
		 
	deposito.IncrementaCapitalEnAnios(anios);
	
	cout << deposito.ToString();
	cout << endl<<endl;
	
	// APARTADO B)
	
	// Asignamos el valor del objeto en el que hemos guardado el valor inicial
	// del capital, al objeto deposito
	
	deposito = deposito2;  // De esta forma ya tenemos al dep�sito con el
	                       // capital incial, listos para abordar este apartado
	
	cout << "ANIOS PARA DOBLAR";
	cout << endl;
	cout << "El numero de anios que han de pasar para que el capital del"
	        " deposito sea el doble es: ";
	        
	cout << deposito.AniosDoblarCapital();
	
	
	
	return 0;

}

