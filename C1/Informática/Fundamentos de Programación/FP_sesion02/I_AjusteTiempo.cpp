/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee un n�mero de horas, minutos y segundos, y que calcula las 
   horas, minutos y segundos dentro de su rango correspondiente, dando los d�as
   correspondientes si hay m�s de 24 horas.
   
   Entradas: horas, minutos y segundos de entrada (horas1, minutos1, segundos1).
   
   Salidas = horas, minutos y segundos en su rango correspondiente (horas2, 
   minutos2, segundos2).
   
   En los c�lculos utilizar� las siguientes sentencias:
   
   segundos2 = (segundos1%60)
   minutos2 = ((minutos1+(segundos1/60))%60)
   horas2 = horas1 + ((minutos1+(segundos1/60))/60)
   
   dias = (horas1+((minutos1+(segundos1/60))/60))/24
   
   Las expresiones (a la derecha de las asignaciones) se basan en c�lculos con
   cocientes, residuos de cocientes y sumas.
                     
*/               
/******************************************************************************/

#include <iostream>      //Inclusi�n de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{

	//DECLARACI�N DE DATOS

	// Datos de entrada

	int horas1;
	int minutos1;
	int segundos1;
	
	// Datos de salida
	
	int horas2;
	int minutos2;
	int segundos2;
	
	int dias;
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca un numero de horas determinado: ";
	cin >> horas1;
	
	cout << "Introduzca un numero de minutos determinado: ";
	cin >> minutos1;
	
	cout << "Introduzca un numero de segundos determinado: ";
	cin >> segundos1;
	
	// C�lculos
	
	segundos2 = (segundos1%60);
	minutos2 = ((minutos1+(segundos1/60))%60);
	horas2 = (horas1 + ((minutos1+(segundos1/60))/60))%24;
	dias = (horas1+((minutos1+(segundos1/60))/60))/24;
	
	// Salida de datos
	
	cout<<endl,
	cout << "El numero de dias que transcurren es: "<< dias << "  dias" <<endl;
	cout << "El numero de horas dentro de su rango correspondiente es: "<<horas2
	<< "  horas" <<endl;
	cout << "El numero de minutos dentro de su rango correspondiente es: "<<
	minutos2<< "  minutos" <<endl;
	cout << "El numero de segundos dentro de su rango correspondiente es: "<<
	segundos2<< "  segundos" <<endl;
	cout<<endl;
	
/******************************************************************************/
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
