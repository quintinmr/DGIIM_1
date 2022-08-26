/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa en el que se ha definido una clase con una serie de métodos para
   la lectura de datos de tipo entero y de tipo double. Desde métodos para
   la lectura de enteros y reales únicamente, hasta para la lectura de enteros
   y reales en un rango de valores dado, y para la lectura de enteros y reales
   mayores o iguales que una referencia dada. Se han encapsulado en la clase
   que se ha definido, las funciones de los ejercicios 18 y 19.
   Se pide al usuario que introduzca en primer lugar datos de tipo entero:
   una temperatura, entera, una hora determinada, y un ingreso, entero, y
   a continuación se le pide que introduzca datos reales: una temperatrua
   cualquiera, no necesariamente entera, se le pide que introduzca su masa y 
   altura, las cuales tienen un máximo, simulando un peso convencional de 
   farmacia, por ejemplo, y por último se pide que introduzca un ingreso, que
   puede ser un número real positivo cualquiera. 

   Entradas: 
    Una cadena de caracteres.
     
   Salidas:
    El dato entero o real que se ha introducido.
    
     
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
	
	Lector (void)
	
	// Constructor que dará valor al objeto 
	
	Lector (string cadena): titulo (cadena)  {}
	
	// Métodos
	
	/************************************************************************/
	
	// Método único de acceso a escritura
	
	void SetTitulo (string cad)
	{
	
		titulo = cad;
		
	}
	
	/************************************************************************/

	// Método para la lectura de un entero
	
	bool EsEntero (string cosa){

	
		int indice = 0;           // La posición inicial es cero
		char caracter_sub_indice; // Cualquier elemento de la cadena de 
		                          // caracteres

	
		if((cosa.at(0) == '-')|| (cosa.at(0) == '+')){     
	                            
		
			indice = (indice + 1);  // Acutalizo el indice variando
	
		}
	
	
		bool entero_ok = true;
	   
		while(entero_ok && (indice < cosa.length())){
		
		 	caracter_sub_indice = cosa.at(indice);
		 	
			entero_ok = (caracter_sub_indice >= '0' && 
			             caracter_sub_indice <='9')&&caracter_sub_indice != ' ';
		
			indice = (indice + 1);   // Actualizo el índice.
		
		}
	
		return entero_ok; 	
	}

	int LeeEntero (void){
	
		string numero;   // Cadena a introducir por el usuario
	
		bool cadena_ok;  
	   
		do{
		
			cout << titulo;
			getline (cin, numero);
		
			cadena_ok = EsEntero(numero);
		
		}while(!cadena_ok);
	
	    
		return stoi(numero);
	}


	/************************************************************************/

	// Método para la lectura de un entero en un rango establecido

	int LeeEnteroEnRango (int menor, int mayor)
	{
		
		int numero_entero;   
	 
		do {
		
			numero_entero = LeeEntero();	
		
		} while (numero_entero < menor || numero_entero > mayor);
	
	
		return numero_entero;	
	}

	/************************************************************************/
	
	// Método para la lectura de un entero respecto de una referencia
	   
	int LeeEnteroMayorOIgual (int referencia)
	{
		
		int numero_entero;    
	
		do {
		
			numero_entero = LeeEntero();	
			
		} while (numero_entero < referencia);
	
	
		return numero_entero;	
	}

	/***********************************************************************/
	
	// Método para la lectura de un número real

	bool EsDouble (string cosa)
	{

		int indice = 0;           // La posición inicial es cero
		char caracter_sub_indice; // Cualquier elemento de la cadena de 
								  //caracteres

		int contador_puntos = 0;
		
		bool double_ok = true;
	
		if(((cosa.at(0) == '-')|| (cosa.at(0) == '+')) && (cosa.at(0) != '.')){     
	                            
		
			indice = (indice + 1);  // Acutalizo el indice variando
	
		}
	
		if (cosa.at(0) == '.')
		
			double_ok = false;
	
		while(double_ok && (indice < cosa.length())){
		
		 	caracter_sub_indice = cosa.at(indice);
		 	
		 	double_ok = (((caracter_sub_indice >= '0' && 
			             caracter_sub_indice <='9') &&
						 (caracter_sub_indice != ' '))
						 || (caracter_sub_indice == '.'));
		 	
		 	if (caracter_sub_indice == '.')
		 	
		 		contador_puntos++;
		 		
		 		if (contador_puntos == 1)
		 		
		 			double_ok = true;
		 			
		 		if (contador_puntos > 1)
				 
				 	double_ok = false;	
		 	
		 	
		 		
			indice = (indice + 1);   // Actualizo el índice.
		
		}
	
		return double_ok; 	
	}

	double LeeDouble (void){
	
		string numero;   // Cadena a introducir por el usuario
	
		bool cadena_ok;  
	   
		do{
		
			cout<< titulo;
			getline(cin, numero);
		
			cadena_ok = EsDouble(numero);
		
		}while(!cadena_ok);
	
	    
		return stod(numero);
	}
	
	/***********************************************************************/
	
	// Método para la lectura de un número real dentro de un rango determinado

	double LeeDoubleEnRango (double menor, double mayor)
	{
		
		double numero_real;   
	 
		do {
		
			numero_real = LeeDouble();	
		
		} while (numero_real < menor || numero_real > mayor);
	
	
		return numero_real;	
	}
	
	/***********************************************************************/
	
	// Método para la lectura de un número real respecto de una referencia
	   
	double LeeDoubleMayorOIgual (double referencia)
	{
		
		double numero_real;    
	
		do {
		
			numero_real = LeeDouble();	
			
		} while (numero_real < referencia);
	
	
		return (numero_real);	
		
	}

/******************************************************************************/

};
/******************************************************************************/


int main ()
{
	
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	cout << "--------------------------------------------------------------";
	cout << endl;
	cout << "                      LECTURA DE ENTEROS                      ";
	cout << endl;
	cout << "--------------------------------------------------------------";
	cout << endl;
	
	cout << "Lectura de un entero";
	cout << endl;
	
	// Defino objeto lector_temp
	
	Lector lector_temp("\tTemperatura: ");
	
	int temp = lector_temp.LeeEntero();
	
	cout << "\tTemperatura leida = " << temp << endl;
	cout << endl;
	
	/***********************************************************************/
	
	cout << "Lectura de enteros acotados superior e inferiormente";
	cout << endl;
	
	int hora, minuto, segundo;
	string cad;
	
	// Defino el objeto lector_hora
	
	Lector lector_hora (cad);
	
	lector_hora.SetTitulo ("\tIntroduzca hora: ");
	hora = lector_hora.LeeEnteroEnRango (0, 23);
	
	lector_hora.SetTitulo ("\tIntroduzca minuto: ");
	minuto = lector_hora.LeeEnteroEnRango (0, 59);
	
	lector_hora.SetTitulo ("\tIntroduzca segundo: ");
	segundo = lector_hora.LeeEnteroEnRango (0, 59);
	
	cout << "\tHora: " << hora << ":" << minuto << ":"
	<< segundo << endl;
	cout << endl;
	
	/************************************************************************/
	
	cout << "Lectura de un entero acotado inferiormente";
	cout << endl;
	
	int ingreso;
	
	// Defino el objeto ingreso
	
	Lector lector_ingreso("\tCantidad a ingresar: ");
	
	ingreso = lector_ingreso.LeeEnteroMayorOIgual (0);
	
	cout << "\tValor del ingreso = " << ingreso << endl;
	cout << endl;
	
	/***********************************************************************/
	/***********************************************************************/
	
	cout << endl;
	cout << "--------------------------------------------------------------";
	cout << endl;
	cout << "                     LECTURA DE DATOS REALES                  ";
	cout << endl;
	cout << "--------------------------------------------------------------";
	cout << endl;
	
	cout << "Lectura de un numero real";
	cout << endl;
	
	// Defino el objeto lector_temp
	
	Lector lector_tempe("\tTemperatura: ");
	
	double tempe = lector_tempe.LeeDouble();
	
	cout << "\tTemperatura leida = " << tempe << endl;
	cout << endl;
	
	/***********************************************************************/
	cout << "Lectura de numeros reales acotados superior e inferiormente";
	cout << endl;
	double masa, altura;
	string msg;
	
	// Defino el objeto lector_masa
	
	Lector lector_masa (msg);
	
	lector_masa.SetTitulo ("\tIntroduzca su masa (max 150 kg): ");
	masa = lector_masa.LeeDoubleEnRango (0, 150);
	
    // Defino el objeto lector_altura
    
	Lector lector_altura (msg);
	
	lector_altura.SetTitulo("\tIntroduzca su altura (max 2.20 m): ");
	altura = lector_altura.LeeDoubleEnRango(0, 2.20);
	
	cout << "\tMasa: " << masa << " kg, " <<"altura: "<< altura << " m";
	cout << endl;

	/***********************************************************************/
	
	cout << "Lectura de un numero real acotado inferiormente";
	cout << endl;
	
	double ingreso_2;
	
	// Defino el objeto lector_ingreso
	
	Lector lector_ingreso_2("\tCantidad a ingresar: ");
	
	ingreso_2 = lector_ingreso_2.LeeDoubleMayorOIgual (0);
	
	cout << "\tValor del ingreso = " << ingreso_2 << endl;
	cout << endl;


/******************************************************************************/
	return 0;	
}


