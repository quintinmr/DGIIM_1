/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee los datos de un alumno: nombre, primer apellido, DNI, y las
   notas que ha obtenido en una serie de pruebas, que son las siguientes:
   
   		1) Examen teorico --> 60%
		2) Examen practico 1 --> 10%
		3) Examen practico 2 --> 20%
		4) Evaluacion continua --> 10%
		
    y calcula y muestra la nota que tendrá en la asigntatura, atendiendo a unos
	criterios: si en el examen teórico, el alumno obtiene una nota inferior a
	4, la nota final de la evaluación será la que haya obtenido en dicho examen,
	si por el contrario tiene al menos un cuatro, se le hace media con las
	notas de las otras pruebas, motrándose en pantalla las preubas que tenga 
	suspensas.
   
   Entradas: 
   	El nombre, primer apellido, DNI y las notas del alumno.
    
   Salidas:
   	Nota final en la asignatura.
   	Pruebas suspensas,y su nota, si es que las hay.
   	
   En este programa se ha establecido una clase, de datos miembro de aspecto
   privado, en la que se incluyen tres métodos: uno destinado a la adición de
   las notas del alumno, otro, al cálculo de la nota final, y otro para mostrar
   el nombre del alumno.
   
    
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <string>
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

class AlumnosFP
{
	
private: 

	// PRE: las notas deben ser mayores o iguales que 0 y menores o iguales que
	// 10

	const string NOMBRE;
	const string PRIMER_APELLIDO;
	const int DNI;
	
	static const int NUM_NOTAS = 4;
	
	static const double PORCENTAJES [NUM_NOTAS];
	double notas [NUM_NOTAS] = {0};
	int indice_variando;
	
	
public:

	// Constructor
	
	AlumnosFP (string name, string apellido_1, int identidad)
	
			:NOMBRE(name), PRIMER_APELLIDO(apellido_1), DNI(identidad),
			indice_variando(0) {}
			 
	/*********************************************************************/
			  
	// Método Set.

	void SetNota(double mark) {
		
		if (0 <= mark && mark <= 10 && indice_variando < NUM_NOTAS) {
			
			notas[indice_variando] = mark;
			
			indice_variando++;
		}
	}		 
			
	/*********************************************************************/
	
	double CalculoNota(void)
	{
		
		double nota_final = 0;
		int indice = 0;
		
		// Si se obtiene en el teórico menos de un 4, la nota final es la de
		// ese examen
			
		if (notas[indice] < 4){
				
			nota_final = notas[indice];
				
		}
		
		// Si por el contrario se obtiene al menos un 4, se hace media.
		
		else
		{
			for (indice; indice < NUM_NOTAS; indice++)	
			nota_final += (notas[indice] * (PORCENTAJES[indice]/ 100.0));
				
		}
	
		
		return (nota_final);
	}
	
	/*********************************************************************/
	
	// Método que muestra las notas suspensas y su nota
	
	void MuestraSuspensas(void)
	{
		
		for (int j = 0; j < NUM_NOTAS; j++){
			
			if (notas[j] < 5) {
				
			cout << "La prueba " << j+1 << " esta suspensa ";
			cout << endl; 
			cout << "Nota: " << notas[j];
			cout << endl;
			
			}
		}
	}
	
	// Método que devuelve en un string el nombre y el primer apellido
	
	string DevuelveNombre (void)
	{
		return (NOMBRE + " " + PRIMER_APELLIDO);
	}
	
	/*********************************************************************/
	
	
};

const double AlumnosFP::PORCENTAJES[] = {60, 10, 20, 10};
	
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
	
int main ()
{

	// Datos de entrada
	
	const int NUM_CALIFICACIONES = 4;
	
	string nombre_alumno; 
	string primer_apellido_alumno;
	int documnento_nacional_de_identidad; 
	double nota;
	
	double nota_evaluacion;
	
	// Declaración del objeto de la clse Lector para filtrar las notas y el DNI
	Lector lee;
	
	/*********************************************************************/
	
	// Entrada de datos
	
	cout << "CUADERNO DEL PROFESOR";
	cout << endl;
	cout << "\tIntroduzca el nombre del alumno: ";
	getline (cin, nombre_alumno);
	
	cout << "\tIntroduzca el primer apellido del alumno: ";
	getline (cin, primer_apellido_alumno);
	
	lee.SetTitulo("\tIntroduzca el DNI del alumno: ");
	documnento_nacional_de_identidad = lee.LeeEnteroEnRango(00000001,99999999);
		

	// Declaración del objeto de la clase AlumnosFP
	
	AlumnosFP alumno (nombre_alumno, primer_apellido_alumno, 
	                  documnento_nacional_de_identidad); 
	                  
	    cout << endl;
		cout << "Listado de calificaciones a tener en cuenta: ";
		cout << endl;
		cout << "1) Calificacion examen teorico" << endl;
		cout << "2) Calificacion examen practico 1" << endl;
		cout << "3) Calificacion examen practico 2" << endl;
		cout << "4) Calificacion evaluacion continua" << endl;
		cout << endl;              
	
		
	lee.SetTitulo("Introduzca la calificación: ");
		 
	for (int i = 0; i < NUM_CALIFICACIONES; i++) {
		
		cout << "Nota" << i+1 <<": "<< endl;
		
		nota = lee.LeeRealEnRango(0, 10);
		
		alumno.SetNota(nota);
		
	}
	
	// Salida de datos
	
	cout << endl;
	
	// Se muestran las pruebas suspensas junto con su nota, mediante el método
	// MuestraSuspensas de la calse AlumnoFP
	
	alumno.MuestraSuspensas();
	
	// Se calcula la nota final de la asignatura llamando al método CalculaNota
	
	nota_evaluacion = alumno.CalculoNota();
	
	// Salida de datos
	
	cout << endl;
	cout << "Nota final del alumno "<< alumno.DevuelveNombre() <<" en la "
        	"asignatura: " << nota_evaluacion;
	cout << endl;
	
	
/******************************************************************************/
	return 0;
}
		
		
		
		
		
	
 

				
				
			
			
		
