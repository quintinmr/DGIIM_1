/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee dos instantes de tiempo (en horas, minutos y segundos) y 
   calcula 
   
   Entradas: 
    
   
   Salidas: 
    
                      
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaración de datos
	
	// Datos de entrada
	
	int horas1;
	int minutos1;
	int segundos1;
	
	int segundos_del_instante_1;
	
	int horas2;
	int minutos2;
	int segundos2;
	
	int segundos_del_instante_2;
	
	
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
	
    
    // Cálculos, condiciones y salida de datos
	
	if ((horas1 < 0) || (minutos1 < 0) || (segundos1 < 0) || (horas2 < 0) ||
	   (minutos2 < 0) || (segundos2 < 0)) {
	   	
	   	cout << "ERROR: Debe introducir datos temporales positivos. Incie "
	   	     << "de nuevo el programa." <<endl;
	   	     
    }
    
    if ((horas1 >= 0 ) && (minutos1 >= 0) && (segundos1 >= 0) && (horas2 >= 0)
       && (minutos2 >= 0) && (segundos2 >= 0)) {
       	
       	
       	if ((horas1 > 23) || (minutos1 >= 60) || (segundos1 >= 60) || 
       	   (horas2 > 23) || (minutos2 >= 60) || (segundos2 >= 60)) {
       	   	
       	   	cout << "ERROR: Los datos temporales no estan detro de su rango"
				 << " correspondiente. Inicie de nuevo el programa." <<endl;
				 
	    }
	    
	    if ((horas1 <= 23) && (minutos1 <= 59) && (segundos1 <= 59) &&
	       (horas2 <= 23) && (minutos2 <= 59) && (segundos2 <= 59)){
	       	
		    // Cálculos
	
	segundos_del_instante_1 = (horas1 * 3600) + (minutos1 * 60) + (segundos1);
	segundos_del_instante_2 = (horas2 * 3600) + (minutos2 * 60) + (segundos2);
	
	int segundos_entre_ambos_instantes;
	
	segundos_entre_ambos_instantes = ((segundos_del_instante_2) - 
	                                 (segundos_del_instante_1));
	                                 
	 	  if (segundos_entre_ambos_instantes > 0) { //Instante 1 < Instante2        
													//Ambos instantes pertenecen
													// al mismo día.
			
		   cout <<endl;											
		   cout << "Los segundos que transcurren entre ambos instantes de"
		        << " tiempo son: " << segundos_entre_ambos_instantes <<endl; 
				
		   // Paso los segundos entre ambos instante a horas, minutos y segundos
		   
		   int segundos_inter = (segundos_entre_ambos_instantes % 60);
		   int minutos_inter = ((segundos_entre_ambos_instantes / 60) % 60);
		   int horas_inter = ((segundos_entre_ambos_instantes / 3600) % 24);
		   
		   cout <<endl;
		   cout << "El tiempo que separa a los dos instantes introducidos es: "
		        << horas_inter <<" horas, " << minutos_inter <<" minutos, " << 
		        segundos_inter <<" segundos.";
		   cout <<endl;
		   
	        }
		   
		  if (segundos_entre_ambos_instantes < 0) { //Instante 1 > Instante 2
		  										    //Ambos instantes pertenecen
													// a dias distintos.
													
		   // Cálculos
			
		  /*Declaro la constante que tiene el valor de los segundos que tiene
			  un día.
		  */  
		  const int SEG_UN_DIA = 86400;
			 
		  segundos_entre_ambos_instantes = (SEG_UN_DIA - segundos_del_instante_1
		                                   + segundos_del_instante_2);	
		                                   
		   cout <<endl;											
		   cout << "Los segundos que transcurren entre ambos instantes de"
		        << " tiempo son: " << segundos_entre_ambos_instantes <<endl; 
				
		   // Paso los segundos entre ambos instante a horas, minutos y segundos                                
										   
		   int segundos_inter = (segundos_entre_ambos_instantes % 60);
		   int minutos_inter = ((segundos_entre_ambos_instantes / 60) % 60);
		   int horas_inter = ((segundos_entre_ambos_instantes / 3600) % 24);	
		  
		   cout <<endl;
		   cout << "El tiempo que separa a los dos instantes introducidos es: "
		        << horas_inter <<" horas, " << minutos_inter <<" minutos, " << 
		        segundos_inter <<" segundos.";
		   cout <<endl;
		   
	       }
	       
	       if (segundos_entre_ambos_instantes == 0) {
	       	
	       	cout <<endl;
	       	cout << "Los segundos que transcurren entre ambos instantes es 0"
	       	     << " lo que puede significar que ambos instantes sean iguales"
	       	     << " o que sean instantes iguales pero de días consecutivos"
	       	     << " lo cual querrá decir que la diferencia entre ambos"
	       	     << " instantes es de 24 horas.";
	       	cout <<endl;     
	       	     
	        }
	    }
	}
	
/******************************************************************************/
	return 0;	
}
		 						   										       
		   
	
	
