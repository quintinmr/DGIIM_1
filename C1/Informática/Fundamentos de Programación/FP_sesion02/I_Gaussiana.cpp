/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee la esperanza o media y la desviación típica de la función
   gaussiana, y a continuación un valor de abcisa x, e imprime el valor que toma
   la función en esa absica x.
   
   Entradas: esperanza, desviación típica y x.
   Salidas: valor de la función en x (gaussiana_de_x)).
                               
*/               
/******************************************************************************/

#include <iostream>      //Inclusión de los recursos de E/S (entrada/salida)
#include <cmath>         //Inclusión de los recursos matemáticos
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{

	// DECLARACIÓN DE DATOS
	
	// Datos de entrada
	
	double esperanza;
	double desviacion_tipica;
	double x;
	
	const double PI = 3.1415927;  // Declaración de la constante PI
	
	double exponente_e;    /* Declaro este dato para que los calulos queden más
	simplificados y no salgan del margen dañando así la estetica del programa */
	
	// Datos de salida
	
	double gaussiana_de_x;
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca el valor de la esperanza o media: ";
	cin >> esperanza;
	
	cout << "Introduzca el valor de la desviacion tipica: ";
	cin >> desviacion_tipica;
	
	cout << "Introduzca un valor de x: ";
	cin >> x;
	
	// Cálculos
	
	exponente_e = (-1.0/2) * pow(((x-esperanza)/desviacion_tipica),2);
	
	gaussiana_de_x = (1/(desviacion_tipica*sqrt(2*PI))) * exp(exponente_e);
	
	
	// Salida de datos
	
	cout <<endl;
	cout << "El valor que toma la funcion gaussiana en x es: "<<gaussiana_de_x<<
	endl;
	cout <<endl;
	
/******************************************************************************/
	return 0;
}
	
