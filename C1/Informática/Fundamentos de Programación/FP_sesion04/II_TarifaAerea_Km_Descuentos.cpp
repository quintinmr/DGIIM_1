
/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee la distancia en kilómetros de un destino en concreto , y 
   un número determinado de puntos de la tarjete de fidelización del cliente 
   que se dispone a viajar hacia dicho destino y calcula el precio final del
   billete, una vez aplicados una serie de descuentos acumulables, en función
   de la distncia y el número de puntos de la tarjeta.
   
   Entradas: 
    Distancia en kilometros al destino (km).
    Número de puntos de la tarjeta de fidelización del cliente (puntos_tarjeta).
    
   Salidas: 
    Precio final del billete (preci_final).
    
   Este programa se basa en el cáclulo del precio de un billete de avión, 
   en función de la distancia al destino, y el número de puntos de la tarjeta
   de fidelización. Dependiendo de la distancia al destino y de la cantidad
   de puntos de dicha tareta, se le añadirán al precio del billete una serie
   de descuentos, que son acumulables; puede haber que el cliente cumpla 
   varias condiciones que amparan varios descuentos, del 0%, 2%%, 3%, 4%, 5% 
   y del 6% (dichos descuentos se acumulan y se aplican al precio del billete).
   
   Pues bien, para calcular el precio final del billete de avión del cliente,
   he establecido una estructura de condicionales simples con anidamientos
   (que conste que no he querido violar el principio de una única vez, pero en
   el enunciado se dice que la finalidad del ejercicio es la de "Plantear una
   estructura condional simple"). En primer lugar, he establecido una
   restricción de los datos: que la distancia en kilómetros y el número de 
   puntos de la tarjeta de fidelización estén representados por enteros 
   positivos, de tal forma que si los datos verifican la condición se continúa
   con el proceso y, en caso contrario, el programa da ERROR y dice al usuario
   lo que debe de introducir.
   
   Dentro de la condición de que los datos sean correctos, para calcular el 
   precio final del billete, he establecido una serie de condiciones simples
   para todos los posibles casos que puedan establecerse entre distancia y
   número de puntos. En función de los datos introducidos, se cumplirá alguno
   de esos casos y se calcula el precio final, aplicandole los descuentos,
   (que los he declarado como constantes), si es que las condiciones los 
   amparan.                      
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
	
	const double PRECIO_BASE = 150.0;
	const double PRECIO_KM_ADICIONAL = 0.1;
	const double DESCUENTO1 = 0.98;  // Descuento del 2%
	const double DESCUENTO2 = 0.97;  // Descuento del 3%
	const double DESCUENTO3 = 0.96;  // Descuento del 4%
	const double DESCUENTO4 = 0.95;  // Descuento del 5%
	const double DESCUENTO5 = 0.94;  // Descuento del 6%
	
	int km;
	int puntos_tarjeta;
	double precio_final;
	
/******************************************************************************/	
	
	// Entrada de datos
	
	cout << "Introduzca la distancia al destino: ";
	cin>> km;
	
	cout << "Introduzca el numero de puntos de la tarjeta de fidelizacion: ";
	cin >> puntos_tarjeta;
	
	// Condiciones, cálculos y salida de datos
	
	if ((km >= 0) && (puntos_tarjeta >= 0)) {
	
		if ((km <= 300) && (puntos_tarjeta > 100) && (puntos_tarjeta <=200)) {
		
	     precio_final = (DESCUENTO2 * PRECIO_BASE);
		
		
	   	 cout << "El precio final del billete es: " << precio_final << " euros" 
	          <<endl;
	        
        }
	
	    if ((km <= 300) && (puntos_tarjeta <= 100)) {
		
		 precio_final = PRECIO_BASE;
		
	     cout << "El precio final del billete es: " << precio_final << " euros" 
	          <<endl;
	        
        }
    
        if ((km <= 300) && (puntos_tarjeta > 200)) {
		
		 precio_final = (DESCUENTO3 * PRECIO_BASE);
		
	     cout << "El precio final del billete es: " << precio_final << " euros" 
	          <<endl;
	
        }
    
    	if (km > 300) {
    
         precio_final = (PRECIO_BASE + (0.1 * km));	
		
		
	     if ((km <= 700) && (puntos_tarjeta > 100) && (puntos_tarjeta <=200)) {
	   	
	   	  precio_final = (DESCUENTO2 * precio_final);
	   	
	   	  cout << "El precio final del billete es: " << precio_final << " euros" 
	           <<endl;
	        
         }

		 if ((km <= 700) && (puntos_tarjeta <= 100)) {
	
		  precio_final = (PRECIO_BASE + 0.1 * km);
		 
		  cout << "El precio final del billete es: " << precio_final << " euros" 
	           <<endl;
	        
	     }
	    
	     if ((km <= 700) && (puntos_tarjeta > 200)) {
	    	
	      precio_final = (DESCUENTO3 * (precio_final));
		  
		  cout << "El precio final del billete es: " << precio_final << " euros" 
	           <<endl;
			  
         } 
	   
	     if ((km > 700) && (puntos_tarjeta > 100) && (puntos_tarjeta <=200)) {
	   	
	      precio_final = DESCUENTO4 * (precio_final);	
	   
	      cout << "El precio final del billete es: " << precio_final << " euros" 
	           <<endl;
	   
         } 
       
	     if ((km > 700) && (puntos_tarjeta <= 100)) {
	   	
	      precio_final = DESCUENTO1 * (precio_final);
	   
	      cout << "El precio final del billete es: " << precio_final << " euros" 
	           <<endl;
	   
         }
       
         if ((km > 700) && (puntos_tarjeta > 200)) {
       	
       	  precio_final = (DESCUENTO5 * (precio_final));

	      cout << "El precio final del billete es: " << precio_final << " euros" 
	           <<endl;
	         
       	 }
	   }
    }
    
	if ((km < 0) || (puntos_tarjeta < 0)) {
		
		cout << "ERROR: Debe introducir una distancia en km positiva y un"
		     << " numero de puntos de tarjeta positivo.";
		cout <<endl;
		
    }
	
/******************************************************************************/
	return 0;
}
