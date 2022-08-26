/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa 2: es un programa que lee la velocidad a la que va un atleta, 
   expresada en kilómetros por hora, y muestra el ritmo (minutos y segundos por
   kilómetro) al que corre.
   
   Entradas:
	Velocidad en kilómetros por hora del atleta; (velocidad).
  
   Salidas:
    Tiempo que tarda el atleta en recorrer un kilómetro, expresado en minutos y
    segundos; (minutos),(segundos).
    
    En este programa, dado que el ritmo al que va el atleta, dada una velocidad,
    se expresa en minutos y segundos por kilómetro, es necesario tener en cuenta
    que esos datos de tiempo hay que darlos de forma entera. Luego, como a 
    partir de la  velcidad, obtendré unos minutos con decimales, he decidido
    declarar dos datos acerca de los minutos: minutos_reales (que son los 
	minutos con decimales),y minutos (minutos enteros), de tal forma que los
	minutos enteros, seran la parte entera de minutos_reales. A partir de la
	diferencia de estos minutos, obtendré los segundos, unos segundos con
	decimales, que declararé como enteros. Luego tras hacer los cáculos 
	pertinentes, el programa mostrará en pantalla los minutos y segundos, de 
	carácter entero, por kilómetro, correspondientes al ritmo del atleta.
                           
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
	
	double velocidad;
	
	// Datos de salida
	
	int minutos;
	int segundos;
	
	double minutos_reales;  // Minutos con decimales (se usa en los cálculos)

/******************************************************************************/
	
	// Entrada de datos
	
	cout << "Introduzca la velocidad a la que va el atleta: ";
	cin >> velocidad;
	
	// Cálculos
	
	minutos_reales = ((1 / velocidad)*60);
	minutos = (minutos_reales);
	segundos = ((minutos_reales - minutos) * 60);
	
	// Salida de datos
	
	cout <<endl;
	cout << "Los minutos por kilometro transcurridos son: "<< minutos<<endl;
	cout << "Los segundos por kilometro transcurridos son: "<< segundos <<endl;
	cout <<endl;
	cout << "El ritmo al que va el atleta es: "<<minutos<< " min  "<<segundos<<
	" s"<< " por km" <<endl;
	cout <<endl;
	
/******************************************************************************/
	return 0;
}
	
	
