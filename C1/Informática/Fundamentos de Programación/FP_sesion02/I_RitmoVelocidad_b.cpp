/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa 2: es un programa que lee la velocidad a la que va un atleta, 
   expresada en kil�metros por hora, y muestra el ritmo (minutos y segundos por
   kil�metro) al que corre.
   
   Entradas:
	Velocidad en kil�metros por hora del atleta; (velocidad).
  
   Salidas:
    Tiempo que tarda el atleta en recorrer un kil�metro, expresado en minutos y
    segundos; (minutos),(segundos).
    
    En este programa, dado que el ritmo al que va el atleta, dada una velocidad,
    se expresa en minutos y segundos por kil�metro, es necesario tener en cuenta
    que esos datos de tiempo hay que darlos de forma entera. Luego, como a 
    partir de la  velcidad, obtendr� unos minutos con decimales, he decidido
    declarar dos datos acerca de los minutos: minutos_reales (que son los 
	minutos con decimales),y minutos (minutos enteros), de tal forma que los
	minutos enteros, seran la parte entera de minutos_reales. A partir de la
	diferencia de estos minutos, obtendr� los segundos, unos segundos con
	decimales, que declarar� como enteros. Luego tras hacer los c�culos 
	pertinentes, el programa mostrar� en pantalla los minutos y segundos, de 
	car�cter entero, por kil�metro, correspondientes al ritmo del atleta.
                           
*/               
/******************************************************************************/

#include <iostream>      //Inclusi�n de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	
	// DECLARACI�N DE DATOS
	
	// Datos de entrada
	
	double velocidad;
	
	// Datos de salida
	
	int minutos;
	int segundos;
	
	double minutos_reales;  // Minutos con decimales (se usa en los c�lculos)

/******************************************************************************/
	
	// Entrada de datos
	
	cout << "Introduzca la velocidad a la que va el atleta: ";
	cin >> velocidad;
	
	// C�lculos
	
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
	
	
