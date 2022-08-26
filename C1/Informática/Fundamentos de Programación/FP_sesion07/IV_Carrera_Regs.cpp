/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee un la hora de inicio de una carrera (en horas, minutos y
   segundos) y la distancia de la misma. A continuaci�n, se pide, por orden
   de llegada, el dorsal de cada corredor y la hora de llegada (en horas, 
   minutos y segundos). Finalmente, el programa muestra en pantalla el tiempo
   empleado por el corredor para completar la carrera (en horas, minutos y
   segundos), y su ritmo en minutos/km y su valocidad en en km/h). 
   A continuaci�n, se vuelve a pedir el dorsal del siguiente atleta y se hacen 
   los mismos c�culos, y as� sucesivamente. El programa termina cuando se 
   introduzca un n�mero de dorsal negativo.
   
   Entradas: 
    Hora de inicio de la carrera (horas_inic, minutos_inic, segundos_inic).
    Distancia de la carrera (distancia).
    N�mero de dorsal (dorsal).
    Hora de llegada (horas_fin, minutos_fin, segundos_fin).
    
   Salidas:
    Tiempo empleado en completar la carrera (horas_total, minutos_total, 
    segundos_total).
    Ritmo (min/km).
    Velocidad (km/h).
   
   En este programa he procedido de la siguiente forma:
   En primer lugar, he definido un struct Instante, que he utilizado para
   almacenar las ternas de datos constitu�das por las horas, minutos y segundos.
   Por lo tanto, este tipo de dato estar� consitu�do por tres campos, que son
   horas, minutos, y segundos. Este tipo de dato Instante lo usar� tanto para
   la introducci�n de la hora a la que el atleta comenz� la carrera, como en la
   introducci�n del instante en el que el corredor termina de correr. Adem�s
   tambi�n lo emplear� en la declaraci�n del tiempo total que ha empleado el
   corredor en completar la carrera, medido en horas, minutos y segundos. 
   En segundo lugar, he definido una serie de funciones de tipo void (porque no 
   devuelven nada), con el objetivo de filtrar los datos relativos al tiempo en
   que comienza la carrera. Dichas funciones hacen que el programa pida los 
   datos de nuevo s� y solo s� los datos temporales introducidos no est�n 
   dentro de su rango correspondiente. 
   Una vez filtrados dichos datos, se realiza otro filtrado pero ahora mediante 
   ciclos while, los cuales se ejecutar�n s� y solo s� se cumplen una serie de 
   condiciones que he declarado previamente mediante una variable tipo bool a
   la que le he asginado el valor de verdad, por lo que entrar� al ciclo al 
   menos una vez, y dentro de �l la actualizo, de tal forma que si no se 
   cumple dicha condici�n se va a estar repitiendo el ciclo hasta que se 
   introduzcan los datos seg�n dictamina la condici�n. Cuando se llega al dato
   del dorsal, se hace una lectura anticipada del mismo y se establece un while
   con la condici�n de que el dorsal sea mayor o igual que cero y se contin�a 
   con el filtrado de los datos, pero ahora dentro del while del dorsal.
   Una vez filtrados todos los datos, se procede al c�clulo de la velocidad
   y el ritmo del atleta en minutos por kil�metro, que vendr� dado en funci�n
   de lo que haya tardado en completar la carrera. De esta forma, en primer 
   lugar, se pasa el tiempo de inicio de la carrera a segundos, as� como tambi�n
   la hora de finalizaci�n de la carrera, y se calcula su diferencia.   
   En virtud de dicha diferencia cabe tener en consideraci�n tres casos 
   posibles: que sea mayor que cero, lo cual significa que empieza y termina
   la carrera en el mismo d�a, que sea menor que cero, lo cual querr� decir
   que empienza y termina en d�as distintos, y, por �ltimo, que sea cero, lo 
   cual implica que el corredor justamente acaba de empezar la carrera, con lo 
   cual no se pueden mostrar datos al respecto. Para los otros dos casos, se 
   hacen c�clulos con el tiempo total empleado, se trabaja con conversiones
   y equivalencias y con los operadores m�dulo y cociente (ver apartado de 
   c�lculos). En el caso de los d�as consecutivos se trabaja con los segundos
   que tiene un d�a y se recurre tambi�n a los mismos operadores.
   Una vez finalizados todos los c�lculos y la impresi�n en pantalla, se 
   reinicia el bucle justo en la parte del dorsal.
   Si no se quiere seguir introduciendo datos cuando el programa pida
   el dorsal del atleta solo tendr� que introducir mal dicho dorsal, y se
   finaliza el programa.
                        
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

	/*Defino un dato de tipo Instante, para registrar ternas de datos, que
	  estar�n constitu�das por horas, minutos, y segundos.
	*/
	
struct Instante{

	int horas;
	int minutos;
	int segundos;
	
};

/******************************************************************************/

  /* Defino una serie de funciones las cuales utilizar�s a la hora de filtrar
     los datos temporales de entrada de este ejericio.
     Estas funciones van a ser de tipo void porque en realidad no devuelven 
     nada (no hay un return), simplemente filtran los datos.
  */
/******************************************************************************/
  
void Horas_ok (Instante instante)
{
	while ((instante.horas < 0) || (instante.horas > 23)){
	    
		cout << "ERROR: las horas est�n fuera de su rango correspondiente."
		     << " Por favor, introduzca de nuevo las horas: ";
		cin  >> instante.horas;
		
	}
		
}

/******************************************************************************/

void Minutos_ok (Instante instante)
{
	while ((instante.minutos < 0) || (instante.minutos > 59)){
		
		cout << "ERROR: los minutos estan fuera de su rango correspondiente."
		     << " Por favor, introduzca de nuevo los minutos: ";
		cin  >> instante.minutos;
		
	}
}

/******************************************************************************/

void Segundos_ok (Instante instante)
{
	while ((instante.segundos < 0) || (instante.segundos > 59)){
		
		cout << "ERROR: los segundos est�n fuera de su rango correspondiente."
		     << " Por favor, introduzca de nuevo los segundos: ";
		cin  >> instante.segundos;
		
	}
}
  
/******************************************************************************/  

int main()   // Programa principal
{
	// Declaraci�n de datos
	
	// Datos de entrada
	
	Instante instante1;
	
	int tiempo1 ;        // Hora de comienzo de la carrera pasada a segundos.
	
	double distancia;
	int dorsal;
	
	Instante instante2;
	
	int tiempo2;        // Hora a la que el atleta acaba la carrera en segundos.
	
	// Datos de salida
	
	int tiempo_total;  //Tiempo total en segundos.
	Instante instante_total;
	
	double velocidad;     // km/h
	double ritmo;         // min/km
	
	// Declaraci�n de constantes
	
	const double SEG_EN_H = 3600.0;
	const double SEG_EN_MIN = 60.0;
	const int SEG_EN_UN_DIA = 86400;
	 
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca la hora de inicio de la carrera (h,min,s): ";
	cout << endl;
	cin  >> instante1.horas; 
	Horas_ok (instante1);
	cin  >> instante1.minutos; 
	Minutos_ok(instante1);
	cin  >> instante1.segundos;
	Segundos_ok(instante1);
	cout << endl;
	
	
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
	    cout << "Introduzca la hora a la que termina la carrera el atleta "
		     << "(h,min,s): ";
		cout << endl;     
	    cin  >> instante2.horas;
	    Horas_ok(instante2);
		cin  >> instante2.minutos;
		Minutos_ok(instante2);
		cin  >>instante2.segundos;
		Segundos_ok(instante2);
	    cout << endl;
	
		
		// C�lculos
	
		// Para calcular el tiempo que tarda en terminar la carrera:
	
		tiempo1 = (instante1.horas * SEG_EN_H) + 
		          (instante1.minutos * SEG_EN_MIN) + (instante1.segundos);
		tiempo2 = (instante2.horas * SEG_EN_H) + 
		          (instante2.minutos * SEG_EN_MIN) + (instante2.segundos);
	          
		tiempo_total = ((tiempo2) - (tiempo1)); 
		
		if (tiempo_total > 0){  // Empieza y acaba la carrera en el mismo d�a.         
	
			instante_total.segundos = (tiempo_total % 60);
			instante_total.minutos  = ((tiempo_total / 60) % 60);
			instante_total.horas    = ((tiempo_total / 3600) % 24);
	
			// Para calcular el ritmo al que va:
	
			// Velocidad en km/h
	
			velocidad = ((distancia / (tiempo_total / SEG_EN_H)));
	
			// Ritmo en min/km
	
			ritmo = (((tiempo_total) / SEG_EN_MIN) / distancia);
	
    
			// Salida de datos
	
			cout << endl;
			cout << "El tiempo empleado por el atleta en llevar a cabo la "
					"carrera es: " << instante_total.horas << " horas " 
			     << instante_total.minutos << " minutos " 
				 << instante_total.segundos << " segundos";
	     
	
			cout << endl;
			cout << "La velocidad media a la que ha ido el atleta es: " 
			     << velocidad << " km/h";
			cout << endl;
	
			cout << "El ritmo del atleta, medido en minutos por kil�tetro ha "
			     << "sido: " << ritmo << " min/km" <<endl;
	    
		}
	
		if (tiempo_total < 0){  //Empez� y acab� la carrera en d�as consecutivos
	
			tiempo_total = ((SEG_EN_UN_DIA - tiempo1) + (tiempo2)); 
		
			instante_total.segundos = (tiempo_total % 60);
			instante_total.minutos  = ((tiempo_total / 60) % 60);
			instante_total.horas    = ((tiempo_total / 3600) % 24);
	
			// Para calcular el ritmo al que va:
	
			// Velocidad en km/h
	
			velocidad = ((distancia / (tiempo_total / SEG_EN_H)));
	
			// Ritmo en min/km
	
			ritmo = (((tiempo_total) / SEG_EN_MIN) / distancia);
			
			// Salida de datos
	
			cout << endl;
			cout << "El tiempo empleado por el atleta en llevar a cabo la "
					"carrera es: " << instante_total.horas << " horas " 
			     << instante_total.minutos << " minutos " 
				 << instante_total.segundos << " segundos";
	     
	
			cout << endl;
			cout << "La velocidad media a la que ha ido el atleta es: " 
			     << velocidad << " km/h";
			cout << endl;
	
			cout << "El ritmo del atleta, medido en minutos por kil�tetro ha "
			     << "sido: " << ritmo <<" min/km" <<endl;
			     
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

		/* En el caso de que no se introduzca el n�mero de dorsal correctamente		
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
