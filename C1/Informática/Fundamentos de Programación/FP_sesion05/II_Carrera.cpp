/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee un la hora de inicio de una carrera (en horas, minutos y
   segundos) y la distancia de la misma. A continuación, se pide, por orden
   de llegada, el dorsal de cada corredor y la hora de llegada (en horas, 
   minutos y segundos). Finalmente, el programa muestra en pantalla el tiempo
   empleado por el corredor para completar la carrera (en horas, minutos y
   segundos), y su ritmo (en km/h y minutos/km).El programa termina cuando
   se introduzca un número de dorsal negativo.
   
   Entradas: 
    Hora de inicio de la carrera (horas_inic, minutos_inic, segundos_inic).
    Distancia de la carrera (distancia).
    Número de dorsal (dorsal).
    Hora de llegada (horas_fin, minutos_fin, segundos_fin).
    
   Salidas:
    Tiempo empleado en completar la carrera (horas_total, minutos_total, 
    segundos_total).
    Ritmo (km/h y min/km).
   
   En este programa he procedido de la siguiente forma:
   En primer lugar, he establecido un filtrado de los datos mediante ciclos
   while cuya condición he declarado previamente en una variable tipo bool a 
   la que le he asginado el valor de verdad, por lo que entrará al ciclo al 
   menos una vez, y dentro de él la actualizo, de tal forma que si no se 
   cumple dicha condición se va a estar repitiendo el ciclo hasta que se 
   introduzcan los datos según dictamina la condición. Cuando se llega al dato
   del dorsal, se hace una lectura anticipada del mismo y se establece un while
   con la condición de que el dorsal sea mayor o igual que cero y se continúa 
   con el filtrado de los datos, pero ahora dentro del while del dorsal.
   Una vez filtrados todos los datos, se procede al cáclulo de la velocidad
   y el ritmo del atleta en minutos por kilómetro, que vendrá dado en función
   de lo que haya tardado en completar la carrera. De esta forma, en primer 
   lugar, se pasa el tiempo de inicio de la carrera a segundos, así como también
   la hora de finalización de la carrera, y se calcula su diferencia.   
   En virtud de dicha diferencia cabe tener en consideración tres casos 
   posibles: que sea mayor que cero, lo cual significa que empieza y termina
   la carrera en el mismo día, que sea menor que cero, lo cual querrá decir
   que empienza y termina en días distintos, y, por último, que sea cero, lo 
   cual implica que el corredor justamente acaba de empezar la carrera, con lo 
   cual no se pueden mostrar datos al respecto. Para los otros dos casos, se 
   hacen cáclulos con el tiempo total empleado, se trabaja con conversiones
   y equivalencias y con los operadores módulo y cociente (ver apartado de 
   cálculos). En el caso de los días consecutivos se trabaja con los días
   que tiene un día y se recurre también a los mismos operadores.
   Una vez finalizados todos los cálculos y la impresión en pantalla, se 
   reinicia el bucle justo en la parte del dorsal.
   Si no se quiere seguir introduciendo datos cuando el programa pida
   el dorsal del atleta solo tendrá que introducir mal dicho dorsal, y se
   finaliza el programa.
                        
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
	
	int horas_inic;
	int minutos_inic;
	int segundos_inic;
	
	int tiempo1 ;        // Hora de comienzo de la carrera pasada a segundos.
	
	double distancia;
	int dorsal;
	
	int horas_fin;
	int minutos_fin;
	int segundos_fin;
	
	int tiempo2;        // Hora a la que el atleta acaba la carrera en segundos.
	
	// Datos de salida
	
	int tiempo_total;  //Tiempo total en segundos.
	int horas_total;
	int minutos_total;
	int segundos_total;
	double velocidad;  // km/h
	double ritmo;         // min/km
	
	// Declaración de constantes
	
	const double SEG_EN_H = 3600.0;
	const double SEG_EN_MIN = 60.0;
	const int SEG_EN_UN_DIA = 86400;
	 
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca la hora de inicio de la carrera: ";
	cout << endl;
	
	
	bool horas_inic_no_ok = true;
		
    while (horas_inic_no_ok){
		
		cout << "Introduzca el numero de horas inicial: ";
		cin  >> horas_inic;
		
		horas_inic_no_ok = ((horas_inic < 0) || (horas_inic > 23));
		
	}
	
	bool minutos_inic_no_ok = true;
	
	while (minutos_inic_no_ok){
		
		cout << "Introduzca el numero de minutos inicial: ";
		cin  >> minutos_inic;
		
        minutos_inic_no_ok = (minutos_inic < 0) || (minutos_inic > 59);
        
    }
    
    bool segundos_inic_no_ok = true;
	
	while (segundos_inic_no_ok){
	
		cout << "Introduzca el numero de segundos iniciales: ";
		cin  >> segundos_inic;
		 
	    segundos_inic_no_ok = (segundos_inic < 0) || (segundos_inic > 59);
	    
	}
	
	bool distancia_no_ok = true;
	
	while (distancia_no_ok){
		
		cout << "Introduzca la distancia de la carrera: ";
		cin  >> distancia;
		
		distancia_no_ok = (distancia < 0);
		
	}
		
		cout << endl;
		cout << "Introduzca el dorsal del atleta: ",
		cin  >> dorsal;
		
		
	bool dorsal_ok = (dorsal >= 0);
		
	while (dorsal_ok ){
    
    
     	cout << endl;
	    cout << "Introduzca la hora a la que termina la carrera el atleta: ";
	    cout << endl;
	
		bool horas_fin_no_ok = true;
	
		while (horas_fin_no_ok){
		
			cout << "Introduzca el numero de horas finales: ";
			cin  >> horas_fin;
		
			horas_fin_no_ok = (horas_fin < 0) || (horas_fin > 23);
		
		}
	
		bool minutos_fin_no_ok = true;
	
		while (minutos_fin_no_ok){
		
			cout << "Introduzca el numero de minutos finales: ";
			cin  >> minutos_fin;
		
	   		minutos_fin_no_ok = (minutos_fin < 0) || (minutos_fin > 59);
	    
		}	
	
		bool segundos_fin_no_ok = true;
	
		while (segundos_fin_no_ok){
		
			cout << "Introduzca el numero de segundos finales: ";
			cin  >> segundos_fin;
	    
	    	segundos_fin_no_ok = (segundos_fin < 0) || (segundos_fin > 59); 
		
		}
	
		// Cálculos
	
		// Para calcular el tiempo que tarda en terminar la carrera:
	
		tiempo1 = (horas_inic * SEG_EN_H) + (minutos_inic * SEG_EN_MIN) + 
	          	  (segundos_inic);
		tiempo2 = (horas_fin * SEG_EN_H) + (minutos_fin * SEG_EN_MIN) + 
	              (segundos_fin);
	          
		tiempo_total = ((tiempo2) - (tiempo1)); 
		
		if (tiempo_total > 0){  // Empieza y acaba la carrera en el mismo día.         
	
			segundos_total = (tiempo_total % 60);
			minutos_total = ((tiempo_total / 60) % 60);
			horas_total = ((tiempo_total / 3600) % 24);
	
			// Para calcular el ritmo al que va:
	
			// Velocidad en km/h
	
			velocidad = ((distancia / (tiempo_total / SEG_EN_H)));
	
			// Ritmo en min/km
	
			ritmo = (((tiempo_total) / SEG_EN_MIN) / distancia);
	
    
			// Salida de datos
	
			cout << endl;
			cout << "El tiempo empleado por el atleta en llevar a cabo la "
			"carrera es: " << horas_total << " horas " << minutos_total << 
			" minutos " << segundos_total << " segundos";
	     
	
			cout << endl;
			cout << "La velocidad media a la que ha ido el atleta es: " 
			     << velocidad << " km/h";
			cout << endl;
	
			cout << "El ritmo del atleta, medido en minutos por kilótetro ha "
			     << "sido: " << ritmo << " min/km" <<endl;
	    
		}
	
		if (tiempo_total < 0){  //Empezó y acabó la carrera en días consecutivos
	
			tiempo_total = (SEG_EN_UN_DIA - (tiempo_total) + (tiempo2)); 
		
			segundos_total = (tiempo_total % 60);
			minutos_total = ((tiempo_total / 60) % 60);
			horas_total = ((tiempo_total / 3600) % 24);
	
			// Para calcular el ritmo al que va:
	
			// Velocidad en km/h
	
			velocidad = ((distancia / (tiempo_total / SEG_EN_H)));
	
			// Ritmo en min/km
	
			ritmo = (((tiempo_total) / SEG_EN_MIN) / distancia);
			
			// Salida de datos
	
			cout << endl;
			cout << "El tiempo empleado por el atleta en llevar a cabo la "
			"carrera es: " << horas_total << " horas " << minutos_total << 
			" minutos " << segundos_total << " segundos";
	     
	
			cout << endl;
			cout << "La velocidad media a la que ha ido el atleta es: " 
			     << velocidad << " km/h";
			cout << endl;
	
			cout << "El ritmo del atleta, medido en minutos por kilótetro ha "
			     << "sido: " << ritmo <<endl;
			     
		}
		
		if (tiempo_total == 0){  // Justo acaba de comenzar la carrera
		
			cout << endl;
			cout << "El atleta acaba de comenzar la carrera; no podemos mostrar"
			     << " datos acerca del tiempo empleado, su velocidad y ritmo.";
			cout << endl;
			
		}
		
		cout << endl;
		cout << "Introduzca el dorsal del atleta: ";
		cin  >> dorsal;
		
		dorsal_ok = (dorsal >= 0);

		/* En el caso de que no se introduzca el número de dorsal correctamente		
		   se muestra un mensaje en pantalla que indica que el programa finaliza
		*/
	}
		
		if (!(dorsal >= 0)){
		
			cout << endl;
			cout << "FIN DEL PROGRAMA";
			cout << endl;  
			
		}
			
/******************************************************************************/
	return 0;
}

