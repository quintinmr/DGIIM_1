/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee un tiempo de entrada y otro de salida de un parking y 
   calcula la tarifa final en euros a cobrar, en función del tiempo de 
   permanencia del vehículo en el parking.
   
   Entradas: 
	Número de horas del instante 1 (horas1).
	Número de minutos del instante 1 (minutos1).
	Número de segundos del instante 1 (segundos1).
	
	Número de horas del instnate 2 (horas2).   
	Número de minutos del instante 2 (minutos2).
	Número de segundos del instante 2 (segundos2).
	  
   Salidas: 
    Tarifa final en euros (tarifa_final)
    
   Este programa lo he realizado estableciendo una serie de estructuras
   condicionales simples con anidamiento, para  abarcar todos los casos 
   posibles, y los casos en los que el programa dará error, es decir, he
   establecido una serie de restricciones en los datos que hacen que cuando
   el usuario introduzca un dato de forma incorrecta, el programa avise que
   ha cometido un error, y pide que se inicie de nuevo el programa. Dichas
   restricciones son, en primer lugar, que las horas, minutos y segundos
   introducidos sean enteros positivos (el tiempo no puede ser negativo).
   Además, otra de las restricciones, que se encuentra dentro de la anterior,
   es que dicho tiempo se encuentre dentro de su rango correspondiente, 
   es decir, que horas <= 23, minutos <= 59, y segundos <= 59.
   
   A continuación, a partir de estas condiciones, he establecido otras que 
   me permiten tener en consideración una serie de casos acerca del tiempo
   que permanece el vehículo en el parking, el cual lo he calculado de la 
   siguiente forma:
    
   tiempo1 = ((horas1 * MIN_EN_1_H) + minutos1 + (segundos1 * MIN_EN_1_SEG))
   tiempo2 = ((horas2 * MIN_EN_1_H) + minutos2 + (segundos2 * MIN_EN_1_SEG))
   
   minutos_permanencia = (tiempo2 - tiempo1)
   
   Este cálculo permite barajar varios supuestos casos:
   Si la diferencia entre el tiempo de entrada y de salida es cero, eso querrá
   decir que el vehículo ha ermanecido 24 horas en el parking y, por
   consiguiente, tendrá que pagar la tarifa máxima, que es 24 euros.
   
   Si la diferencia es mayor que cero, eso querrá decir que el vehículo ha
   salido del parking el mismo día que entró, por lo tanto la tarifa final 
   que tendrá que pagar vendrá dada en función de los minutos que haya 
   permanecido aparcado. El cáclulo de la tarifa final en este caso viene
   dado en funicón de una serie de estructuras condicionales simples que he
   establecido y que pueden verse en el apartado de condiciones, cálculos y
   salida de datos.
   
   Si la diferencia es menor que cero, significará que el vehículo ha salido 
   del parking al día siguiente, de tal forma que el instante de entrada es
   mayor que el instante de salida. En este caso, para calcular la tarifa 
   final del parking, es necesario realizar unos cálculos nuevos para que
   los minutos de permanencia (la diferencia entre el instante de entrada y
   el de salida) sean positivos. Para ello, simplemente se le suma a los
   minutos del instante de salida, la diferencia entre los minutos que tiene
   un día y los minutos del instante de entrada. Finalmente, la tarifa final
   vendrá dada en función de dichos minutos de permanencia, para lo cual
   he establecido de nuevo una serie de condiones simples.
                         
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
	
	int horas2;
	int minutos2;
	int segundos2;
	
	int tiempo1;    // Instante de entrada pasado a minutos
	int tiempo2;    // Instante de salida pasado a minutos
	
	int minutos_permanencia; // Minutos que pasa el vehículo en el parking
	
	// Declaración de constantes
	
	const double MIN_EN_1_H = 60;
	const double MIN_EN_1_SEG = 1.0/60;
	const int MIN_EN_1_DIA = 1440;
		
	// Desde el minuto X al minuto Y
	const double DEL_0_AL_30 = 0.0412;        // euros por minuto
	const double DEL_31_AL_90 = 0.0370;		  // euros por minuto
	const double DEL_91_AL_120 = 0.0311;      // euros por minuto
	const double DEL_121_AL_660 = 0.0305;     // euros por minuto
	const double DEL_661_A_24_H = 24.00;      // euros 
	 										  	
	// Datos de salida
	
	double tarifa_final;
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca el instante de entrada al parking: " <<endl;
	
	cout << "Introduzca el numero de horas del instante de entrada: ";
	cin  >> horas1;
	
	cout << "Introduzca el numero de minutos del instante de entrada: ";
	cin  >> minutos1;
	
	cout << "Introduzca el numero de segundos del instante de entrada: ";
	cin  >> segundos1;
	
	cout <<endl;
	
	cout << "Introduzca el instante de salida del parking: " <<endl;
	
	cout << "Introduzca el numero de horas del instante de salida: ";
	cin  >> horas2;
	
	cout << "Introduzca el numero de minutos del instante de salida: ";
	cin  >> minutos2;
	
	cout << "Introduzca el numero de segundos del instante de salida: ";
	cin  >> segundos2;
	
	

	
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
	
	
	       // Paso a minutos del instante de entrada y del de salida
	
	  tiempo1 = ((horas1 * MIN_EN_1_H) + minutos1 + (segundos1 * MIN_EN_1_SEG));
	  tiempo2 = ((horas2 * MIN_EN_1_H) + minutos2 + (segundos2 * MIN_EN_1_SEG));
	
	
	      // Cálculo de los minutos de permanencia en el parking
	
	    minutos_permanencia = (tiempo2 - tiempo1);   // Tiempo que el vehículo
													 //	está en el parking.      
	 
	 
	      // Condiciones, cálculos y salida de datos  II
		
		if (minutos_permanencia == 0) {   // tiempo1 = tiempo2
			
      	 tarifa_final = DEL_661_A_24_H ;
			
		 cout << "La tarifa final del parking es de: " <<tarifa_final 
			  << " euros" <<endl; 
		
		}
		    
		if (minutos_permanencia > 0 ) {   // tiempo1 < tiempo2
	
			if (minutos_permanencia <= 30) {
	
			 tarifa_final = (minutos_permanencia * DEL_0_AL_30);
		
		     cout << "La tarifa final del parking es de: " <<tarifa_final 
			      << " euros" <<endl;
			     
	        }
	
			if ((minutos_permanencia >= 31) && (minutos_permanencia <= 90)) {
	
		     tarifa_final = ((30 * DEL_0_AL_30) + (minutos_permanencia - 30) * 
			                 DEL_31_AL_90);
		
		     cout << "La tarifa final del parking es de: " <<tarifa_final 
			      << " euros" <<endl;
			      
	        }
	
			if ((minutos_permanencia >= 91) && (minutos_permanencia <= 120)) {
	
		     tarifa_final = ((30 * DEL_0_AL_30) + (60 * DEL_31_AL_90) + 
			                ((minutos_permanencia - 90) * DEL_91_AL_120));
		
		     cout << "La tarifa final del parking es de: " <<tarifa_final 
			      << " euros" <<endl;
			      
	    	}
	
	       if ((minutos_permanencia >= 121) && (minutos_permanencia <= 660)) {
	
			 tarifa_final = ((30 * DEL_0_AL_30) + (60 * DEL_31_AL_90) +
			                (30 * DEL_91_AL_120) +  ((minutos_permanencia - 120)
							* DEL_121_AL_660));
		
			 cout << "La tarifa final del parking es de: " <<tarifa_final 
			      << " euros" <<endl;
			     
	     	}	
	
			if ((minutos_permanencia >= 660) && (minutos_permanencia <= 1140)) {
	
		     tarifa_final = DEL_661_A_24_H;
		
			 cout << "La tarifa final del parking es de: " <<tarifa_final 
			      << " euros" <<endl;
			      
		    }
		}
		
		if (minutos_permanencia < 0) {  // tiempo1 > tiempo2 (sale al dia  
			                            // siguiente del parking).
			
			// Cálculos, condiciones y salida de datos
			
			minutos_permanencia = (MIN_EN_1_DIA - tiempo1 +tiempo2);
			
			if (minutos_permanencia <= 30) {
	
			 tarifa_final = (minutos_permanencia * DEL_0_AL_30);
		
		     cout << "La tarifa final del parking es de: " <<tarifa_final 
			      << " euros" <<endl;
			     
	        }
	
			if ((minutos_permanencia >= 31) && (minutos_permanencia <= 90)) {
	
		     tarifa_final = ((30 * DEL_0_AL_30) + (minutos_permanencia - 30) * 
			                 DEL_31_AL_90);
		
		     cout << "La tarifa final del parking es de: " <<tarifa_final 
			      << " euros" <<endl;
			      
	        }
	
			if ((minutos_permanencia >= 91) && (minutos_permanencia <= 120)) {
	
		     tarifa_final = ((30 * DEL_0_AL_30) + (60 * DEL_31_AL_90) + 
			                ((minutos_permanencia - 90) * DEL_91_AL_120));
		
		     cout << "La tarifa final del parking es de: " <<tarifa_final 
			      << " euros" <<endl;
			      
	    	}
	
	       if ((minutos_permanencia >= 121) && (minutos_permanencia <= 660)) {
	
			 tarifa_final = ((30 * DEL_0_AL_30) + (60 * DEL_31_AL_90) +
			                (30 * DEL_91_AL_120) +  ((minutos_permanencia - 120)
							* DEL_121_AL_660));
		
			 cout << "La tarifa final del parking es de: " <<tarifa_final 
			      << " euros" <<endl;
			     
	     	}	
	
			if ((minutos_permanencia >= 660) && (minutos_permanencia <= 1140)) {
	
		     tarifa_final = DEL_661_A_24_H;
		
			 cout << "La tarifa final del parking es de: " <<tarifa_final 
			      << " euros" <<endl;
			      
		    }
      	}
	}
	
}
/******************************************************************************/
	return 0;
}

	
