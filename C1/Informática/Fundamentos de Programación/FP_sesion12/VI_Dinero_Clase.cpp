/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* En este programa se presenta una versión ampliada de la clase "Dinero"
	que será útil para trabajar de forma precisa con datos monetarios.

	La clase tiene dos datos miembro: "euros" y "centimos", además de 12 métodos
	nuevos, con los que se hacen distintas acciones y comparaciones con los
	datos monetarios introducidos. Dichos métodos, se pueden localizar más
	abajo.
	
	Est programa está basado en la comprobación del funcionamiento de los 
	distintos métodos definidos en la clase Dinero.
	Dichos métodos están basados en el incremento y decremento de la cantidad
	incial introducida (de dos formas distintas: con un ojeto como dato de 
	entrada, y con una cantidad decimal), en la modificación de dicha cantidad
	mediante su incremento o decremento en función de si la cantidad (decimal)
	que se introcude es positiva o negativa (atendiendo a unas condiciones 
	previas), a la comparación entre cantidades (si la cantidad inicial es 
	mayor, menor o igual que la que se ha introducido en ese mismo momento), y
	en el cálculo de la diferencia entre la cantidad inicial y otra, que ha de
	ser menor o igual que la introducida.
       
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <string>
#include <cmath>
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
       
class Dinero
{

private:

	// PRE: 0 <= euros
	int euros;  // Num. de euros

	// PRE: 0 <= centimos < 100
	int centimos; // Num. de céntimos
	
public:

	/***********************************************************************/
	// Constructor sin argumentos.
	
	Dinero (void) : euros(0), centimos(0)
	{ }
	
	/***********************************************************************/
	// Constructor con un argumento.
	// Recibe: cantidad, número de euros (double). 
	// 		   Si es un valor con decimales indica que tiene céntimos. 
	//         Por ejemplo: 7.45 indicará 7 euros y 45 céntimos. 
	//
	// PRE:  0 <= cantidad

	Dinero (double cantidad) 
	{	
		euros = (cantidad*100) / 100; 
		centimos = ((int) (cantidad*100)) % 100;
	}		
			
	/***********************************************************************/
	// Constructor con dos argumentos.
	// Recibe: los_euros, núm. de euros
	//		   los_centimos, el núm. de céntimos. Si "los_centimos" es mayor 
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
	// Métodos Get

	// Devuelve el número de euros completos
	
	int GetEuros (void)
	{
		return (euros);
	}

	// Devuelve el número de céntimos
	
	int GetCentimos (void)
	{
		return (centimos);
	}

	// Devuelve el valor numérico del dato "Dinero". 
	// Por ejemplo, Si el estado del objeto es {euros=7, centimos=45} 
	// devuelve 7.45 
	
	double GetValor (void)
	{
		return (euros+(centimos/100.0));
	}
	
	/***********************************************************************/
	// Calcula y devuelve el resultado de sumar cantidad a la cantidad de 
	// dinero del objeto implícito. 
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
	// dinero del objeto implícito. 
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
	// Recibe: num_casillas_euros, el número de casillas con el que queremos 
	// formatear el valor de los euros. Si el número de casillas 
	// es mayor que el número de dígitos se rellenarán con 
	// el carácter "hueco"
	// hueco, caractere que se usará para rellenar los huecos. 
	// 
	// Devuelve: un string con la representación textual de un dato Dinero.  

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
	// Modifica únicamente el valor del campo "euros" 

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
	// Calcula y devuelve en número de dígitos de "num"
	
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

int main ()
{
	
	// Declaración de los datos
	
	int euros_inic;
	int euros_sec;
	int centimos_inic;
	int centimos_sec;
	double cantidad_dinero;
	
	// Declaración del objeto de la clase lectora
	
	Lector lector;
	
	
	// Entrada de datos
	
	cout << "PRUEBA LOS METODOS DE LA CLASE DINERO";
	cout << endl << endl;
	
	
	lector.SetTitulo("\tIntroduzca un numero de euros: ");
	euros_inic = lector.LeeEnteroMayorOIgual(0);
	
	lector.SetTitulo("\tIntroduzca un numero de centimos: ");
	centimos_inic = lector.LeeEnteroMayorOIgual(0);
	
	/***********************************************************************/	
	
	cout << endl;
	cout << "METODO INCREMENTA";
	cout << endl;
	
	lector.SetTitulo("\tIntroduzca un numero de euros a incrementar: " );
	euros_sec = lector.LeeEnteroMayorOIgual(0);
	
	lector.SetTitulo("\tIntroduzca un numero de centimos a incrementar: ");
	centimos_sec = lector.LeeEnteroMayorOIgual(0);
	
	// Cálculos
	
	// Defino los objetos de la calse Dinero que voy a emplear
	
	Dinero dinero (euros_inic, centimos_inic);
	
	Dinero incremento (euros_sec, centimos_sec);
	
	Dinero cantidad_final (dinero.Incrementa(incremento));
	
	// Salida de datos
	
	cout << endl;
	cout << "Resultado del incremento: " << cantidad_final.ToString();
	cout << endl;                                    
	
	/***********************************************************************/
	
	cout << endl;
	cout << "METODO DECREMENTA I";
	cout << endl;
	
	lector.SetTitulo("\tIntroduzca un numero de euros a decrementar: " );
	euros_sec = lector.LeeEnteroMayorOIgual(0);
	
	lector.SetTitulo("\tIntroduzca un numero de centimos a decrementar: ");
	centimos_sec = lector.LeeEnteroMayorOIgual(0); 
	
	Dinero decremento (euros_sec, centimos_sec);
	
	Dinero cantidad_final1 (dinero.Decrementa(decremento));
	
	// Salida de datos
	
	cout << endl;
	cout << "Resultado del decremento: " << cantidad_final1.ToString();
	cout << endl;
	
	/***********************************************************************/

	cout << endl;
	cout << "METODO DECREMENTA II";
	cout << endl;
	
	lector.SetTitulo("\tIntroduzca la cantidad a decrementar: " );
	cantidad_dinero = lector.LeeRealMayorOIgual(0);
	
	Dinero cantidad_final2 (dinero.Decrementa(cantidad_dinero));
	
	// Salida de datos
	
	cout << endl;
	cout << "\tResultado del decremento: " << cantidad_final2.ToString();
	cout << endl;
	
	/***********************************************************************/
	
	cout << endl;
	cout << "METODO 4: MODIFICA I";
	cout << endl;
	
	cout << "Modifique la cantidad inicial introducida, bien introduciendo" 
	        " una cantidad positiva (se sumara), o bien una negativa (se"
			" sustraera): " << endl;
	
	lector.SetTitulo("\tIntroduzca una cantidad de dinero: ");
	cantidad_dinero = lector.LeeReal();
	
	Dinero cantidad_final3 (dinero.Modifica(cantidad_dinero));
	
	// Salida de resultados
	
	cout << endl;
	cout << "\tResultado del decremento: " << cantidad_final3.ToString();
	cout << endl;
	
	/***********************************************************************/
	
	cout << endl;
	cout << "METODO 5: EsMayor I";
	cout << endl;
	
	lector.SetTitulo("\tIntroduzca los euros de la cantidad que desea"
	                 " comparar: ");
	euros_sec = lector.LeeEnteroMayorOIgual(0);
	
	lector.SetTitulo("\tIntroduzca los céntimos de la cantidad que desea"
	                 " comparar: ");
	centimos_sec = lector.LeeEnteroMayorOIgual(0);
	
	Dinero comparacion (euros_sec, centimos_sec);
	
	bool mayor = dinero.EsMayor(comparacion);
	
	// Salida de datos (caben dos opciones: que sea mayor, o no lo sea)
	
	if (mayor){
	
		cout << endl;
		cout << "\tCantidad incial mayor que la recientemente introducida";
		cout << endl;
	}
	
	else
	{
		cout << endl;
		cout << "\tLa cantidad incial no es mayor que esta cantidad";
		cout << endl;
	}
	
	/***********************************************************************/
	
	cout << endl;
	cout << "METODO 6: EsMayor II";
	cout << endl;
	
	lector.SetTitulo("\tIntroduzca la cantidad de dinero que desea comparar: ");
	cantidad_dinero = lector.LeeRealMayorOIgual(0);
	
	
	bool mayor2 = dinero.EsMayor(cantidad_dinero);
	
	// Salida de datos (caben dos opciones: que sea mayor, o no lo sea)
	
	if (mayor2){
	
		cout << endl;
		cout << "\tCantidad incial mayor que la recientemente introducida";
		cout << endl;
	}
	
	else
	{
		cout << endl;
		cout << "\tLa cantidad incial no es mayor que esta cantidad";
		cout << endl;
	}
	
	/***********************************************************************/	

	cout << endl;
	cout << "METODO 7: EsMenor I";
	cout << endl;
	
	lector.SetTitulo("\tIntroduzca los euros de la cantidad que desea"
	                 " comparar: ");
	euros_sec = lector.LeeEnteroMayorOIgual(0);
	
	lector.SetTitulo("\tIntroduzca los centimos de la cantidad que desea"
	                 " comparar: ");
	centimos_sec = lector.LeeEnteroMayorOIgual(0);
	
	Dinero comparacion2 (euros_sec, centimos_sec);
	
	bool menor = dinero.EsMenor(comparacion2);
	
	// Salida de datos (caben dos opciones: que sea mayor, o no lo sea)
	
	if (menor){
	
		cout << endl;
		cout << "\tCantidad incial menor que la recientemente introducida";
		cout << endl;
	}
	
	else
	{
		cout << endl;
		cout << "\tLa cantidad incial no es menor que esta cantidad";
		cout << endl;
	}
	
	/***********************************************************************/		
	cout << endl;
	cout << "METODO 8: EsMenor II";
	cout << endl;
	
	lector.SetTitulo("\tIntroduzca la cantidad de dinero que desea comparar: ");
	cantidad_dinero = lector.LeeRealMayorOIgual(0);
	
	
	bool menor2 = dinero.EsMenor(cantidad_dinero);
	
	// Salida de datos (caben dos opciones: que sea mayor, o no lo sea)
	
	if (menor2){
	
		cout << endl;
		cout << "\tCantidad incial menor que la recientemente introducida";
		cout << endl;
	}
	
	else
	{
		cout << endl;
		cout << "\tLa cantidad incial no es menor que esta cantidad";
		cout << endl;
	}
	
	/***********************************************************************/
	cout << endl;
	cout << "METODO 9: EsIgual I";
	cout << endl;
	
	lector.SetTitulo("\tIntroduzca los euros de la cantidad que desea"
	                 " comparar: ");
	euros_sec = lector.LeeEnteroMayorOIgual(0);
	
	lector.SetTitulo("\tIntroduzca los centimos de la cantidad que desea"
	                 " comparar: ");
	centimos_sec = lector.LeeEnteroMayorOIgual(0);
	
	Dinero comparacion3 (euros_sec, centimos_sec);
	
	bool igual = dinero.EsIgual(comparacion3);
	
	if (igual){
	
		cout << endl;
		cout << "\tCantidad incial igual a la recientemente introducida";
		cout << endl;
	}
	
	else
	{
		cout << endl;
		cout << "\tEsta cantidad de dinero no es igual a la introducida";
		cout << endl;
	}
	/***********************************************************************/
	
	cout << endl;
	cout << "METODO 9: EsIgual II";
	cout << endl;
	
	lector.SetTitulo("\tIntroduzca la cantidad de dinero que desea comparar: ");
	cantidad_dinero = lector.LeeRealMayorOIgual(0);
	
	
	Dinero comparacion4 (cantidad_dinero);
	
	bool igual2 = dinero.EsIgual(comparacion4);
	
	if (igual2){
	
		cout << endl;
		cout << "\tCantidad incial igual a la recientemente introducida";
		cout << endl;
	}
	
	else
	{
		cout << endl;
		cout << "\tEsta cantidad de dinero no es igual a la introducida";
		cout << endl;
	}

	/***********************************************************************/

	cout << endl;
	cout << "METODO 11: Diferencia I";
	cout << endl;
	
	cout << "ATENCION: Solo es posible efectuar la diferencia si y solo si se"
	        " verifica que la cantidad a introducir sea menor o igual que la"
	        " introducida inicialmente";
	cout << endl;        
	
	lector.SetTitulo("\tIntroduzca el numero de euros: ");
	euros_sec = lector.LeeEnteroMayorOIgual(0);
	
	lector.SetTitulo("\tIntroduzca el numero de centimos: ");
	centimos_sec = lector.LeeEnteroMayorOIgual(0);
	
	Dinero comparacion5 (euros_sec, centimos_sec);
	
	bool mayor_o_igual = (dinero.EsMayor(comparacion5) || 
	                      dinero.EsIgual(comparacion5));
	                         
	Dinero diferencia_entre_cantidades;
	                         
	if (mayor_o_igual){
		
		diferencia_entre_cantidades = dinero.Diferencia(comparacion5);
		
		cout << endl;
		cout << "\tDiferencia entre cantidades: " 
		     << diferencia_entre_cantidades.ToString();
		cout << endl;     
	}
	
	else{
		
		cout << endl;
		cout << "\tError: Cantidad mayor que la inicial";
		cout << endl;
	}
	
	/***********************************************************************/
	
	cout << endl;
	cout << "METODO 12: Diferencia II";
	cout << endl;
	
	cout << "ATENCION: Solo es posible efectuar la diferencia si y solo si se"
	        " verifica que la cantidad a introducir sea menor o igual que la"
	        " introducida inicialmente";
	cout << endl;        
	
	lector.SetTitulo("\tIntroduzca la cantidad de dinero: ");
	cantidad_dinero = lector.LeeRealMayorOIgual(0);
	
	bool mayor_o_igual2 = (dinero.EsMayor(cantidad_dinero) || 
	                       dinero.EsIgual(cantidad_dinero));
	                         
	Dinero diferencia_entre_cantidades2;
	                         
	if (mayor_o_igual2){
		
		diferencia_entre_cantidades2 = dinero.Diferencia(cantidad_dinero);
		
		cout << endl;
		cout << "\tDiferencia entre cantidades: " 
		     << diferencia_entre_cantidades2.ToString();
		cout << endl;     
	}
	
	else{
		
		cout << endl;
		cout << "\tError: Cantidad mayor que la inicial";
		cout << endl;
	}
	
	/***********************************************************************/	
	return 0;	
}
	
	
	
		
			
			
			
			
			
		
		
		
	
	
	
	
 	
 	
	
	
		
			
