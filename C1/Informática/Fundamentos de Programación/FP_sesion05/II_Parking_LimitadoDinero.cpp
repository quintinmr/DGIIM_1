/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee la hora a la que un vehículo accede a un parking, y una
   cantidad de dinero determinada, y calcula la hora hasta la que el vehículo
   puede permanecer en el parking si se va a pagar con dicha cantidad de dinero.
   
   Los precios del minutos de estacia en el parking siguen la siguiente 
   clasificación:
   
   Desde el minuto 0 al 30: 0.0412 euros cada minuto
   Desde el minuto 31 al 90: 0.0370 euros cada minuto 
   Desde el minuto 91 al 120: 0.0311 euros cada minuto 
   Desde el minuto 121 al 660: 0.0305 euros cada minuto 
   Desde el minuto 661 a 900 : 0.0270 euros cada minuto
   Desde el minuto 900 hasta máximo 24 horas: 35.00 euros

   Entradas: 
    Hora de entrada (horas1, minutos1)
	Dinero del que se dispone (dinero).
	 
   Salidas:
    Hora a la que se debe abandonar el parking (horas2, minutos2).
    
   En este programa he procedido de la siguiente forma:
   En primer lugar, he hecho un filtrado de los datos, mediante ciclos de tipo
   post-test, de tal forma que si no se cumple la condición de los bucles
   se procede al cálculo de los minutos que puede permanecer el usuario dentro
   del parking en función del dinero que lleva. He establecido una serie de
   ciclos while en los que se va restando sucesivamente dinero al presupuesto
   de partida, hasta que se agote o se llegue a un número máximo de minutos
   dentro de un intervalo, es decir, si se ha superado  el periodo de 0 a 30 
   minutos,, se pasa al intervalo de 31 a 90, y se sigue restando dinero al
   dinero resultante anterior, a la vez que se va actualizando el contador de
   minutos. Esto se repite hasta que se agote el dinero, y , en el contador
   quedarán guardados los minutos que podrá permanecer.
   De esta forma, una vez que ya tenemos los minutos que el usuario puede 
   permanecer en el parking, he establecido una serie de estructuras 
   condicionales simple para abarcar tres posibles casos que pueden darse
   perfectamente:que los minutos que puede permanecer sean mayores que los
   minutos que posee un día, lo cual querrá decir que deberá abandonar al 
   día siguiente (para ello se hacen cáclulos con el número de minutos que
   tiene un día), que los minutos de salida sean menor que los que tiene un
   día, lo cual quiere decir que entra y debe salir en el mismo día y,
   por ultimo, que el númer ode minutos que puede permanecer en el parking 
   sea el número de minutos que tiene un día (1440), lo cual significa que 
   debe salir a las doce de la noche.
                         
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <cmath>
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaración de datos
	
	// Datos de entrada
	
	int horas1;                 // Horas de entrada al parking
	int minutos1;               // Minutos de salida del parking
    int contador_minutos;       // Contador de minutos
	double dinero_inicial;      // Dinero del que dispone el usuario
	
	// Declaración de constantes
	
	const int MIN_EN_1_H = 60;
	const int MIN_EN_1_DIA = 1440;  // Permanencia maxima 
		
	// Desde el minuto X al minuto Y
	const double DEL_0_AL_30 = 0.0412;        // euros por minuto
	const double DEL_31_AL_90 = 0.0370;		  // euros por minuto
	const double DEL_91_AL_120 = 0.0311;      // euros por minuto
	const double DEL_121_AL_660 = 0.0305;     // euros por minuto
	const double DEL_661_AL_900 = 0.0270;      // euros por minuto
	const double DEL_901_A_24_H = 35.00;      // euros 
	
	// Datos de salida
	
	int horas2;                 // Horas de salida del parking
	int minutos2;               // Minutos de salida del parking
	
/******************************************************************************/

	// Entrada de datos
	
    /* Establezco una serie de filtros para los datos de entrada mediante
	   ciclos post-test (se ejecuta después de evaluar la parte iterativa)
	*/
	   	 
    do{
	
		cout << "Introduzca las horas del instante de entrada: ";
		cin  >> horas1;
		
		
    }while ((horas1 < 0) || (horas1 > 23));
    
    do {
		
		cout << "Introduzca los minutos del instante de entrada: ";
		cin  >> minutos1;
		
    }while ((minutos1 < 0) || (minutos1 > 59));
    
    
    do{
    	
    	cout << "Introduzca el dinero del que dispone: ";
    	cin  >> dinero_inicial;
    	
    }while (dinero_inicial < 0);
    
    
    // Cálculos
    
    /* Establezco una serie de estructuras condicionales dobles, en las que se
	   abarcan todos los casos posibles acerca de las características del dinero
	   del usuario y en las que se incluyen ciclos pre-test que se ejecutarán
	   bajo una serie de condiciones acerca del dinero y de los minutos de
	   permanencia.
	*/
	 
	double dinero = dinero_inicial;
	
	if (dinero < DEL_901_A_24_H){  // Si lleva menos que la tarifa máxima (35)
    
   
    	
    	while ((dinero >= DEL_0_AL_30) && ( contador_minutos <= 30)){
    		
    		dinero  = (dinero - DEL_0_AL_30);
    		contador_minutos ++;
        }
        
        while ((dinero >= DEL_31_AL_90) && (contador_minutos <= 90)){
        	
        	dinero  = (dinero - DEL_31_AL_90);
        	contador_minutos ++;
        	
        }
    	
    	while ((dinero > DEL_91_AL_120) && (contador_minutos <= 120)){
    		
    		dinero  = (dinero - DEL_91_AL_120);
    		contador_minutos ++;
    		
    	}
    	
    	while ((dinero > DEL_121_AL_660) && (contador_minutos <= 660)){
    		
    		dinero = (dinero - DEL_121_AL_660);
    		contador_minutos ++;
    		
    	}
    	
    	while ((dinero > DEL_661_AL_900) && (contador_minutos <= 900)){
    		
    		dinero  = (dinero - DEL_661_AL_900);
    		contador_minutos ++;
    		
    	}
    }
    
    else
    {
    	contador_minutos = MIN_EN_1_DIA;
    	
    }
    	
    // Salida de datos 1
	
	cout << endl;
	cout << "De acuerdo con la cantidad de diner que posee solo podra " 
	     << "permanecer en el parking " << contador_minutos << " minutos.";	
	cout << endl;
	
	 	// Cálclo del tiempo de estancia en el parking en horas y minutos
		 
		 horas2    = (contador_minutos / MIN_EN_1_H);
    	 minutos2  = (contador_minutos % MIN_EN_1_H);   
    	 
    	 // Salida de datos
    	 
    	 cout << "Debe abandonar el parking en: " << horas2 << " horas y "
    	      << minutos2 << " minutos";
    	 cout << endl;
		 
		      
    	/* A continuación calculo los minutos del instante de salida mediante la
    	   suma de los minutos correspondientes al instante de entras y los 
    	   minutos guardados en el contador.
    	*/
		
		  
    	
        int minutos_de_entrada = ((horas1 * MIN_EN_1_H) + minutos1);
    	                     
        int minutos_de_salida = (minutos_de_entrada + contador_minutos);
        
        /* LLegados a este punto, es necesario tener bajo consideración 
           tres posibles casos en cuanto a este último dato; el de los 
           minutos de salida y son: que dichos minutos sean inferiores a los
           que tiene un día (1440), es decir, que el usuario entra y sale del
           parking el mismo día, que dichos minutos sean mayores que los 
           minutos que tiene un día, es decir, entra y sale en días distintos
           y, finalmente, que los minutos sean justamente los que tiene un día, 
		   lo que querrá decir que el usuario sale del parking a media noche.
		*/
    
    	if (minutos_de_salida < MIN_EN_1_DIA){
    		
    		horas2 = ((horas1 + horas2) + ((minutos1 + minutos2)/ MIN_EN_1_H));
    		minutos2 = ((minutos1 + minutos2) % MIN_EN_1_H);
    		
    		cout << endl;
    		cout << "Debera abandonar el parking a las " << horas2 << " horas "
    		     << minutos2 << " minutos";
    		cout << endl;
			     
    	}
    	
    	if (minutos_de_salida > MIN_EN_1_DIA){
    		
    		minutos_de_salida = (minutos_de_salida - MIN_EN_1_DIA);
    		
    		horas2   = (minutos_de_salida / MIN_EN_1_H);
    		minutos2 = (minutos_de_salida % MIN_EN_1_H);
    		
    		cout << endl;
    		cout << "Debera abandonar el parking a las " << horas2 << " horas "
    		     << minutos2 << " minutos del dia siguiente.";
    		cout << endl;
    		
    	}
    	
    	if (minutos_de_salida == MIN_EN_1_DIA){
    		
    		cout << endl;
    		cout << "Debera abandonar el parking a las 0 horas 0 minutos";
    		cout << endl;
    		
    	}
    	
    
/******************************************************************************/
	return 0;
}
