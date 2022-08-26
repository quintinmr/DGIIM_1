/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que realiza una aproximaci�n del n�mero Pi a trav�s del arcotangente
   de Madhava (matem�tico idio del siglo XIV):
   
   a) Lee un valor tope entre 1 y 100000 y calcula la aproximaci�n mediante un
      desarrollo de Taylor; mediante una serie de sumas, y muestra dicha
      aproximaci�n en pantalla.
      
      Entradas:
       Un tope (tope), entre 1 y 100000.
       
      Salidas:
	   La aproximacion de pi (aproximacion_pi). 
      
    b) Lee un entero que indica la cantidad de decimales de precisi�n que 
	   deseamos, calcula la aproximaci�n mediante un serie de sumas 
	   correspondientes a un desarrollo de Taylor, y nos indica las iteraciones 
	   que ha tenido que hacer para conseguir dicha aproximaci�n.
   
   	  Entradas: 
   	   Un entero que indica las cifras decimales de precisi�n (precision).
    
   	  Salidas:
   	   Numero de iteraciones realizadas para llevar a cabo la aproximaci�n
   	   (contador_iteraciones)
                         
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <cmath>       //Inclusi�n de los recursos matem�ticos
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{

    // APARTADO a)
    
	// DECLARACI�N DE DATOS
	
	// Datos de entrada
	
	int tope;
		
/******************************************************************************/

	// Entrada de datos
	
	cout << "APARTADO A";
	cout << endl;
	
	do{
	
		cout << "Indique el valor del tope; especifique el numero de sumas "
	     	 << "que desea realiza para llevar a cabo la aproximacion: ";
		cin  >> tope;
		
    }while((tope < 1) || (tope > 100000));
	
	// C�lculos
	
	/* En primer lugar, dado que en el enunciado me dicen que no puedo hacer 
	   uso de la funci�n pow, he de recurrir a otro procedimiento. Dicho 
	   procedimiento puede ser el establecer dos estructuras repetitivas
	   para las potencias que aparecen en el desarrollo de Taylor, una
	   para cuando dichas potencias son pares o impares.
	   Para ello recurro a la sentencia "for", que me permite una construcci�n
	   de los ciclos de una forma m�s compacta.
	*/
	
	/* Declaro las variables principales que van a regir los c�clulos del 
	   programa; la aproximaci�n de pi la calculo con la suma de todas las
	   iteraciones pares e impares que se han producido en funci�n de la
	   variaci�n del �ndice i, multiplicada por seis.
	*/   	
	
	double suma_pares = 0;
	double suma_impares = 0;
	
	for(int i=0; i <= tope; i = i+2){  // i es el contador, al que se le asigna
	                                   // un valor inicial (solo se ejecuta una
	                                   // vez, 1<=tope es la condici�n sobre el
	                                   // contador (si es cierta se entra), e 
	                                   // i=1+2 es la actualizaci�n del contador
	
	    // En este caso, como i es par, (-1)^i es 1, que multiplicado por 
	    // la siguiente potencia , esta permanece invariante. Por eso 
	    // en estos c�lculos trabajo solo la potencia de base  inverso
	    // de la ra�z de tres elevado a 2i+1.
	    
	    /* Declaro las potencias pares e impares porque voy a trabajar
	       a continuaci�n con ellas. He decidido declarar todas estas variables
	       que voy a emplear en estos c�lculos en los propios c�lculos por la
	       sencilla raz�n de que me es m�s f�cil comprobar de un vistazo las
	       caracter�sticas de los datos con los que estoy trabajando, sin tener
	       la necesidad de subir al apartado de declaraci�n de datos.         */
	       
	       double potencias_pares = 1;      // Les asigno un valor original
		   double potencias_impares = 1;    // Si fuera cero, la suma da cero
	    
	    /* A continuaci�n procedo al c�lculo de las potencias pares de 
		   exponente 2i+1 (ver desarr. Taylor)                                */
	
		
		for(int j=0; j < ((2*i)+1); j = j + 1){
			
			potencias_pares = (potencias_pares * (1/sqrt(3)));
			
		}
		
		// C�lculo de las potencias impares de exponente 2i+1
		
		for(int j=0; j < (2*(i+1)+1); j = j + 1){
			
			potencias_impares = (potencias_impares * (1/sqrt(3)));
		}
		
		suma_pares = (suma_pares + (potencias_pares / ((2*i)+1)));
		suma_impares = (suma_impares - (potencias_impares / (2*(i+1)+1)));
	}
	
	/* Haciendo el desarrollo de Taylor para un valor de x igual a 1/ra�z(3)
	   y con un �ndice variando desde cero al infinito se obtiene pi/6
	   Luego, en funci�n del n�mero de sumas que el usuario haya introducido
	   el valor de la suma se aproximar� o m�s o menos a pi/6. Luego, en
	   cualquier caso, la aproximaci�n del n�mero pi ser� la resultante de
	   multiplicar 6 por dicha suma (que tiende a pi/6), porque haciendo
	   infinitas sumas, se obtiene el valor casi excato de pi/6, luego, pi 
	   tendr� que ser, 6*(pi/6)
	 */
	   	
	double suma = (suma_pares + suma_impares);
	
    double  aproximacion_pi = (6 * suma);  
	
	// Salida de datos
	
	cout << endl;
	cout <<"La aproximacion de numero pi llevando a cabo " << tope << " sumas"
	     << " es: " << aproximacion_pi;
	cout << endl;
	

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

	// APARTADO b)
	
	// DECLARACI�N DE DATOS
	
	// Datos de entrada
	
	int precision;               // N�mero de cifras decimales de precisi�n
	const double PI = 3.14159265358979323846;
	
	double truncador = 1;        // potencia de diez "truncadora"
	double pi_trunc;             // pi truncado
	
	double aproximacion = 0;    // Aproximaci�n normal de pi
	double aprox_trunc = 0;     // Aproximaci�n de pi truncada
	
	int contador_sumas = 0;     // Contador del n�mero de sumas
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "APARTADO B";
	cout << endl;
	
	do{
		
		cout << "Introduzca el numero de decimales de precision: ";
		cin  >> precision;
		
    }while(precision < 0 );
    
    // Hago uso de nuevo de los ciclos for, por simplicidad
    
    for(int i=0; i < precision; i = i + 1)
    	
    	truncador = truncador * 10;
	
	pi_trunc = int (PI*truncador)/truncador;
	
	
	suma_pares = 0;
	suma_impares = 0;
	suma = 0;
	
	while(aprox_trunc != pi_trunc){
		
		double potencias_pares = 1;
		double potencias_impares = 1;
		
		// C�lculo de las potencias pares de exponente 2i+1 (ver desarr. Taylor)
		
		for(int i=0; i < (2*contador_sumas + 1); i = i + 1){
			
			potencias_pares = (potencias_pares * (1/sqrt(3)));
			
		}
		
		for(int i=0; i < (2*(contador_sumas + 1) + 1); i = i + 1){
			
			potencias_impares = (potencias_impares * (1/sqrt(3)));
			
		}
		
		suma_pares = suma_pares + (potencias_pares/((2 * contador_sumas) + 1));
		
		suma_impares = suma_impares-
		              (potencias_impares/((2 * (contador_sumas + 1)) +1));
						  
		suma = (suma_pares + suma_impares);
		
		aproximacion = (6 * suma);  // Por la misma raz�n de antes
	
		// Con el objetivo de comparar la aproximaci�n, debemos de truncar
		// la aproximaci�n de pi al mismo n�mero de decimales de precisi�n
		
		double pow_aprox = 1;
	
		for(int i=0; i < precision; i = i + 1)
		
			pow_aprox = (pow_aprox * 10);

		aprox_trunc = int (aproximacion * pow_aprox);
		aprox_trunc = (aprox_trunc / pow_aprox);
								
		contador_sumas = (contador_sumas + 2); // Se suman un par y un impar
		                                       			  
	}
	
	//Salida de datos
	
	cout << "El numero de iteraciones realizadas para aproximar PI con "
	     << precision << " decimales de precision es: "<<contador_sumas;
	cout << endl;
	
/******************************************************************************/	   
	
	return 0;
}
    
    
			
		 	
			
	
	
	
	
