/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee la esperanza o media y la desviación típica de la función
   gaussiana, y a continuación un valor de abcisa x, e imprime el valor que 
   toma la función en esa absica x, comprobando previamente que la desviación
   típica de la función no es nula.
   
   Entradas: 
    esperanza, desviación típica y x.
   Salidas: 
    valor de la función en x (gaussiana_de_x)).
                               
   En este programa he establecido una condición doble, enfocada a la
   desviación típica que introduce el usuario, pues este puede introducir
   el valor cero, para el cual la función gaussiana no toma ningún valor,
   independientemente del valor de x que introduzca pues, depende inversamente
   de la desviación típica, y hay que tener en mente que no se puede dividir
   por cero. De esta forma, la condición que se establece es que la desviación
   típica sera mayor estricto que cero, y si se cumple, se continua con el 
   proceso de cáclulo del valor que toma la función gaussiana para un valor de
   x determinado. Por otra parte, si la condición no se cumple, es decir, la
   desviación típica introducida es cero, el programa indica al usuario que
   ha cometido un error y que vuelva a introducir la desviación típica.                             
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
	                       simplificados y no salgan del margen dañando así la 
						   estetica del programa */
	
	// Datos de salida
	
	double gaussiana_de_x;
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca el valor de la esperanza o media: ";
	cin  >> esperanza;
	
	cout << "Introduzca el valor de la desviacion tipica: ";
	cin  >> desviacion_tipica;
	
	
	// Condiciones, cálculos y salida de datos
	
	if (desviacion_tipica > 0) {
		
		cout << "Introduzca un valor de x: ";
	    cin  >> x;
	
		exponente_e = (-1.0/2) * pow(((x-esperanza)/desviacion_tipica),2);
	
		gaussiana_de_x = (1/(desviacion_tipica*sqrt(2*PI))) * exp(exponente_e);
	
		cout << endl;
		cout << "El valor que toma la funcion gaussiana en x es: "
		     << gaussiana_de_x <<endl;
		cout << endl;
		
    }
    
    else 
    {
    	cout << endl;
    	cout << "ERROR : la desviacion tipica no puede valer cero. Vuelva a"
    	     << " iniciar el programa e introduzca otro valor.";
    	cout << endl;
	}
    	
/******************************************************************************/
	return 0;
}
