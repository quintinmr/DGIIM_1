/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee una distancia en millas y muestra la cantidad equivalente
   en kilómetros, y, al contario, lee una distancia en kilómetros y la muestra
   en millas.
   
   Entradas: 1ª(distancia en millas), 2ª(distancia en kilómetros).
   
   Salidas: 1ª(distancia equivalente en kilómetros), 2ª(distancia equivalente en
   millas).
 
   En los cáclulos se siguen estos factores de conversion:
    
    kilometros = millas * 1.609344 
    millas = kilometros / 1.609344                      
                      
*/               
/******************************************************************************/

#include <iostream>      //Inclusión de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
 
    // DELCARACIÓN DE DATOS
    
	const double UNA_MILLA_EN_KM = 1.609344;   // Declaración de una constante   
	
	double kilometros;    // Dato de salida 1 y dato de entrada 2
	double millas;       // Dato de entrada 1 y dato de salida 2
	
	
/******************************************************************************/
	
	// Entrada de datos 1
	
	cout << "Introduzca una distancia en millas: ";
	cin >> millas;
	
	// Cálculos 1
	
    kilometros = (millas * UNA_MILLA_EN_KM);
    
    // Salida 1
    
    cout <<endl;
    cout << "La distancia equivalente en kilometros es: "<< kilometros << " km"
	<<endl;
    cout <<endl;
    
/******************************************************************************/
    
    // Entrada de datos 2
    
    cout << "Introduzca una distancia en kilometros: ";
    cin >> kilometros;
    
    // Cálculos 2
    
    millas = (kilometros / UNA_MILLA_EN_KM);
    
    //Salida 2
    
    cout << endl;
    cout << "La distancia equivalente en millas es: "<< millas <<" millas"<<
	endl;
    cout << endl;
    
/******************************************************************************/   
	return 0;
}


