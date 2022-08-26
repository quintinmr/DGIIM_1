/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee la esperanza o media y la desviaci�n t�pica de la funci�n
   gaussiana, y a continuaci�n un valor de abcisa x, e imprime el valor que 
   toma la funci�n en esa absica x, comprobando previamente que la desviaci�n
   t�pica de la funci�n no es nula.
   
   Entradas: 
    esperanza, desviaci�n t�pica y x.
   Salidas: 
    valor de la funci�n en x (gaussiana_de_x)).
                               
   En este programa he establecido una condici�n doble, enfocada a la
   desviaci�n t�pica que introduce el usuario, pues este puede introducir
   el valor cero, para el cual la funci�n gaussiana no toma ning�n valor,
   independientemente del valor de x que introduzca pues, depende inversamente
   de la desviaci�n t�pica, y hay que tener en mente que no se puede dividir
   por cero. De esta forma, la condici�n que se establece es que la desviaci�n
   t�pica sera mayor estricto que cero, y si se cumple, se continua con el 
   proceso de c�clulo del valor que toma la funci�n gaussiana para un valor de
   x determinado. Por otra parte, si la condici�n no se cumple, es decir, la
   desviaci�n t�pica introducida es cero, el programa indica al usuario que
   ha cometido un error y que vuelva a introducir la desviaci�n t�pica.                             
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
	                       simplificados y no salgan del margen da�ando as� la 
						   estetica del programa */
	
	// Datos de salida
	
	double gaussiana_de_x;
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca el valor de la esperanza o media: ";
	cin  >> esperanza;
	
	cout << "Introduzca el valor de la desviacion tipica: ";
	cin  >> desviacion_tipica;
	
	
	// Condiciones, c�lculos y salida de datos
	
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
