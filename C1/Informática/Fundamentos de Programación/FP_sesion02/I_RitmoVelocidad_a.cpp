/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa 1: es un programa que lee el ritmo de un atleta, expresado en 
   minutos y segundos por kilómetro, y muestra la velocidad a la que va, en 
   kilómetros por hora.
   
   Entradas:
    Ritmo del atleta: tiempo que tarda el atleta en recorrer un kilómetro, 
	expresado en minutos y segundos; (minutos),(segundos).

   Salidas:
    Velocidad en kilómetros por hora del atleta; (velocidad).
                       
*/               
/******************************************************************************/

#include <iostream>      //Inclusión de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	
	// DECLARACIÓN DE DATOS
	
	// Datos de entrada
	
	int minutos;
	int segundos;
	
	// Datos de salida
	
	double velocidad;
	
   // Declaración de constantes
   	
	const double UN_MIN_EN_HORAS = 1.0 / 60;       // MIN = minutos
	const double UN_SEG_EN_HORAS = 1.0 / 3600;     // SEG = segundos
	
/******************************************************************************/	
	
	
	// Entrada de datos
	
	cout << "Introduzca los minutos por kilometro transcurridos: ";
	cin >> minutos;
	
	cout << "Introduzca los segundos por kilometro transcurridos: ";
	cin >> segundos;
	
	// Cálculos
	
	velocidad = 1/((minutos * UN_MIN_EN_HORAS) + (segundos * UN_SEG_EN_HORAS));
	
	// Salida de datos
	
	cout <<endl;
	cout << "La velocidad a la que va el atleta es: "<<velocidad<< " km/h" <<
	endl;
	cout <<endl;
	
/******************************************************************************/
	return 0;
}


	
	
