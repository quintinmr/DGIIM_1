/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee un instante inicial, expresado en horas, minutos y segundos,
   y otro instante final, expresado de la misma forma, y muestra en pantalla el 
   número de segundos entre ambos instantes de tiempo.                       
   
   Entradas: 
   Instante de tiempo inicial (instante1: horas1, minutos1, segundos1).
   Instante de tiempo final (instante2: horas2, minutos2, segundos2).
             
   Salidas: segundos comprendidos entre el instante inicial (instante1) y el
   instante final (instante2). 
   
   Conversión horas y minutos a segundos:
   
    segundos = horas * 3600   (1 hora = 3600 segundos)             
    segundos = minutos * 60   (1 minuto = 60 segundos)             

segundos entre ambos instantes = segundos del instante2 - segundos del instante1    
                      
*/               
/******************************************************************************/

#include <iostream>      //Inclusión de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	
	//Datos de entrada
	
	int horas1;
	int minutos1;
	int segundos1;
	
	int segundos_del_instante_1;
	
	int horas2;
	int minutos2;
	int segundos2;
	
	int segundos_del_instante_2;
	
	//Datos de salida
	
	int segundos_entre_ambos_instantes;
	
/******************************************************************************/	

	// Entrada de datos
	
	cout << "Introduzca el numero de horas del instante 1: ";
	cin >> horas1;
	
	cout << "Introduzca el numero de minutos del instante 1: ";
	cin >> minutos1;
	
	cout << "Introduzca el numero de segundos del instante 1: ";
	cin >> segundos1;
	cout <<endl;
	cout << "Introduzca el numero de horas del instante 2: ";
	cin >> horas2;
	
	cout << "Introduzca el numero de minutos del instante 2: ";
	cin >> minutos2;
	
	cout << "Introduzca el numero de segundos del instante 2: ";
	cin >> segundos2;
	
	// Cálculos
	
	segundos_del_instante_1 = (horas1 * 3600) + (minutos1 * 60) + (segundos1);
	segundos_del_instante_2 = (horas2 * 3600) + (minutos2 * 60) + (segundos2);
	
	segundos_entre_ambos_instantes = abs((segundos_del_instante_2) - 
	(segundos_del_instante_1));
	
  /* Nótese que he considerado los segundos_ente_ambos_instantes en valor 
   absoluto por la sencilla razón de que el usuario puede introducir un 
   instante 2 menor que el instante 1, de tal forma que los segundos 
   comprendidos entre ambos instantes serían negativos. */
	
	// Salida de datos
	
	cout <<endl;
	cout << "Los segundos que transcurren entre ambos instantes de tiempo son: "
	<< segundos_entre_ambos_instantes <<endl;
	cout <<endl;
	
/******************************************************************************/
	return 0;
}
