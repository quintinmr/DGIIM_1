/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee la esperanza o media y la desviaci�n t�pica de la funci�n
   gaussiana, y a continuaci�n un valor de abcisa x, e imprime el valor que toma
   la funci�n en esa absica x.
   
   Entradas: esperanza, desviaci�n t�pica y x.
   Salidas: valor de la funci�n en x (gaussiana_de_x)).
                               
*/               
/******************************************************************************/

#include <iostream>      //Inclusi�n de los recursos de E/S (entrada/salida)
#include <cmath>         //Inclusi�n de los recursos matem�ticos
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{

	// DECLARACI�N DE DATOS
	
	// Datos de entrada
	
	double esperanza;
	double desviacion_tipica;
	double x;
	
	const double PI = 3.1415927;  // Declaraci�n de la constante PI
	
	double exponente_e;    /* Declaro este dato para que los calulos queden m�s
	simplificados y no salgan del margen da�ando as� la estetica del programa */
	
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
	
	// C�lculos
	
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
	
