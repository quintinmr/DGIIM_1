/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee un número real y un número entero , y trunca el número 
   real a tantos decimales con indique el número entero, comprobando 
   previamente que dicho entero es positivo.
   
   Entradas:
    Un número real (numero_real) y un número entero (numero_entero)
	positivo que indica el lugar donde se desea realizar el truncamiento. 
   
   Salidas: 
    El número truncado (numero_truncado).
    
    En este programa he establecido una condición doble enfocada al número 
    entero que indique el lugar donde se desea realizar el truncamiento en 
    el numero decimal introducido. Si se verifica, es decir, que el usuario
    introduce un numero entero positivo, entonces se procede al truncamiento
    el cual lo he realizado mediante movimientos de la coma, a traves de
    multiplicaciones con potencias de diez: en primer lugar, el numero dado 
	se multimplica por una potencia de diez elevada al numero entero positivo 
	introducido. A continuación, del numero que resulta, el cual previamente
	está delcarado como entero, se multiplica la parte entera por una potencia
	de diez elevada al opuesto del numero entero positivo, resultando así
	el número truncado.
                      
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
	
	// Condiciones, truncamiento, y salida de datos
	
	if (numero_entero >= 0) {
	
		real_desplazado = ( numero_real * pow( 10 , numero_entero ) );
	
		numero_truncado = real_desplazado * (pow( 10 , ( -numero_entero ) ) );
	
	    cout << "El numero truncado es: "<<numero_truncado<<endl;
	 
    }
    
    else
    { 
    	cout << "ERROR: el lugar donde desea truncar el número real anterior "
	         << "debe estar representado por un numero entero positivo"<<endl;
	
    }

/******************************************************************************/	
	return 0;
	
}
