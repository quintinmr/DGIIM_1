/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que nos pide una distancia en metros (m) y nos la calcula, 
   mostr�ndonosla en pantalla, en pulgadas, pies, yardas y millas.      
   Su finalidad es la de plantear la soluci�n de una doble conversi�n.
   
   Entradas: Una distancia en metros.
   
   Salidas: Distancia en pulgadas, pies, yardas y millas.
     
   En los c�lculos se siguen estos factores  de conversi�n:
    
    pulgadas = metros / 0.0254
    pies = metros / 0.3048
    yardas = metros / 0.9144
    millas = metros / 1609.344
                               
*/               
/******************************************************************************/

#include <iostream>      //Inclusi�n de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
 
    // DECLARACI�N DE DATOS
    
    // Declaraci�n de constantes
    
	const double UNA_PULGADA_EN_METROS = 0.0254;
	const double UN_PIE_EN_METROS = 0.3048;
	const double UNA_YARDA_EN_METROS = 0.9144;
	const double UNA_MILLA_EN_METROS = 1609.344;
	
	//Datos de entrada
	
	double metros;    
	
	//Datos de salida
	 
	double pulgadas;
	double pies;
	double yardas;
	double millas;
	
/******************************************************************************/

    // Entrada de datos
	
	cout << "Introduzca una distancia en metros: ";
	cin >> metros;
	
	//C�lculos
	
	pulgadas = (metros /  UNA_PULGADA_EN_METROS);
	pies = (metros / UN_PIE_EN_METROS);
	yardas = (metros / UNA_YARDA_EN_METROS);
	millas = (metros / UNA_MILLA_EN_METROS);
	
	// Salida de datos
	
	cout <<endl;
	cout << "La distancia equivalente en pulgadas es: "<< pulgadas <<endl;
	cout << "La distancia equivalente en pies es: "<< pies <<endl;
	cout << "La distancia equivalente en yardas es: "<< yardas <<endl;
	cout << "La distancia equivalente en millas es: "<< millas <<endl;
	cout <<endl;
	
/******************************************************************************/	
	return 0;
}
	
