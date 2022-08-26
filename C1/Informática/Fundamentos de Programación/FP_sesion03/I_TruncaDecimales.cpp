/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee un número real y un número entero , y trunca el número 
   real a tantos decimales con indique el número entero.
   
   Entradas:
    Un número real cualquiera (numero_real) y un número entero (numero_entero)
	cualquiera que indica el lugar donde se desea realizar el truncamiento. 
   
   Salidas: 
    El número truncado (numero_truncado).
                      
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <cmath>       //Inclusión de los recursos matemáticos
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	
	// DECLARACIÓN DE DATOS
	
	// Datos de entrada
	
	double numero_real;
	int numero_entero;
	
	// Datos de salida
	
	double numero_truncado;
	
	int real_desplazado;     // Declaro este dato a parte, para usarlo en los
	                         // en los cálculos.
	
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca un número real cualquiera: ";
	cin >> numero_real;
	
	cout << "Introduzca un número entero que indique el lugar donde desea " 
	"truncar el número real anterior: ";
	cin >> numero_entero;
	
	// Truncamiento
	
	real_desplazado = ( numero_real * pow( 10 , numero_entero ) );
	
	numero_truncado = real_desplazado * (pow( 10 , ( -numero_entero ) ) );
	
	
	// Salida de datos
	
	cout << "El numero truncado es: "<<numero_truncado<<endl;

/******************************************************************************/	
	return 0;
	
}
	
