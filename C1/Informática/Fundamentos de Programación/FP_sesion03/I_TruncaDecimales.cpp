/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee un n�mero real y un n�mero entero , y trunca el n�mero 
   real a tantos decimales con indique el n�mero entero.
   
   Entradas:
    Un n�mero real cualquiera (numero_real) y un n�mero entero (numero_entero)
	cualquiera que indica el lugar donde se desea realizar el truncamiento. 
   
   Salidas: 
    El n�mero truncado (numero_truncado).
                      
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <cmath>       //Inclusi�n de los recursos matem�ticos
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	
	// DECLARACI�N DE DATOS
	
	// Datos de entrada
	
	double numero_real;
	int numero_entero;
	
	// Datos de salida
	
	double numero_truncado;
	
	int real_desplazado;     // Declaro este dato a parte, para usarlo en los
	                         // en los c�lculos.
	
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca un n�mero real cualquiera: ";
	cin >> numero_real;
	
	cout << "Introduzca un n�mero entero que indique el lugar donde desea " 
	"truncar el n�mero real anterior: ";
	cin >> numero_entero;
	
	// Truncamiento
	
	real_desplazado = ( numero_real * pow( 10 , numero_entero ) );
	
	numero_truncado = real_desplazado * (pow( 10 , ( -numero_entero ) ) );
	
	
	// Salida de datos
	
	cout << "El numero truncado es: "<<numero_truncado<<endl;

/******************************************************************************/	
	return 0;
	
}
	
