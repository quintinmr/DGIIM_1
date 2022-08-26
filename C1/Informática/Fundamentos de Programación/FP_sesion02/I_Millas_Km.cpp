/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee una distancia en millas y muestra la cantidad equivalente
   en kil�metros, y, al contario, lee una distancia en kil�metros y la muestra
   en millas.
   
   Entradas: 1�(distancia en millas), 2�(distancia en kil�metros).
   
   Salidas: 1�(distancia equivalente en kil�metros), 2�(distancia equivalente en
   millas).
 
   En los c�clulos se siguen estos factores de conversion:
    
    kilometros = millas * 1.609344 
    millas = kilometros / 1.609344                      
                      
*/               
/******************************************************************************/

#include <iostream>      //Inclusi�n de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
 
    // DELCARACI�N DE DATOS
    
	const double UNA_MILLA_EN_KM = 1.609344;   // Declaraci�n de una constante   
	
	double kilometros;    // Dato de salida 1 y dato de entrada 2
	double millas;       // Dato de entrada 1 y dato de salida 2
	
	
/******************************************************************************/
	
	// Entrada de datos 1
	
	cout << "Introduzca una distancia en millas: ";
	cin >> millas;
	
	// C�lculos 1
	
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
    
    // C�lculos 2
    
    millas = (kilometros / UNA_MILLA_EN_KM);
    
    //Salida 2
    
    cout << endl;
    cout << "La distancia equivalente en millas es: "<< millas <<" millas"<<
	endl;
    cout << endl;
    
/******************************************************************************/   
	return 0;
}


