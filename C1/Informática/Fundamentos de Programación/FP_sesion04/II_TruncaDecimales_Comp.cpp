/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee un n�mero real y un n�mero entero , y trunca el n�mero 
   real a tantos decimales con indique el n�mero entero, comprobando 
   previamente que dicho entero es positivo.
   
   Entradas:
    Un n�mero real (numero_real) y un n�mero entero (numero_entero)
	positivo que indica el lugar donde se desea realizar el truncamiento. 
   
   Salidas: 
    El n�mero truncado (numero_truncado).
    
    En este programa he establecido una condici�n doble enfocada al n�mero 
    entero que indique el lugar donde se desea realizar el truncamiento en 
    el numero decimal introducido. Si se verifica, es decir, que el usuario
    introduce un numero entero positivo, entonces se procede al truncamiento
    el cual lo he realizado mediante movimientos de la coma, a traves de
    multiplicaciones con potencias de diez: en primer lugar, el numero dado 
	se multimplica por una potencia de diez elevada al numero entero positivo 
	introducido. A continuaci�n, del numero que resulta, el cual previamente
	est� delcarado como entero, se multiplica la parte entera por una potencia
	de diez elevada al opuesto del numero entero positivo, resultando as�
	el n�mero truncado.
                      
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
	
	// Condiciones, truncamiento, y salida de datos
	
	if (numero_entero >= 0) {
	
		real_desplazado = ( numero_real * pow( 10 , numero_entero ) );
	
		numero_truncado = real_desplazado * (pow( 10 , ( -numero_entero ) ) );
	
	    cout << "El numero truncado es: "<<numero_truncado<<endl;
	 
    }
    
    else
    { 
    	cout << "ERROR: el lugar donde desea truncar el n�mero real anterior "
	         << "debe estar representado por un numero entero positivo"<<endl;
	
    }

/******************************************************************************/	
	return 0;
	
}
