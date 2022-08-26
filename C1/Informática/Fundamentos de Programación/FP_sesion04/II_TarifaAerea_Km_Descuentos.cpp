
/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee la distancia en kil�metros de un destino en concreto , y 
   un n�mero determinado de puntos de la tarjete de fidelizaci�n del cliente 
   que se dispone a viajar hacia dicho destino y calcula el precio final del
   billete, una vez aplicados una serie de descuentos acumulables, en funci�n
   de la distncia y el n�mero de puntos de la tarjeta.
   
   Entradas: 
    Distancia en kilometros al destino (km).
    N�mero de puntos de la tarjeta de fidelizaci�n del cliente (puntos_tarjeta).
    
   Salidas: 
    Precio final del billete (preci_final).
    
   Este programa se basa en el c�clulo del precio de un billete de avi�n, 
   en funci�n de la distancia al destino, y el n�mero de puntos de la tarjeta
   de fidelizaci�n. Dependiendo de la distancia al destino y de la cantidad
   de puntos de dicha tareta, se le a�adir�n al precio del billete una serie
   de descuentos, que son acumulables; puede haber que el cliente cumpla 
   varias condiciones que amparan varios descuentos, del 0%, 2%%, 3%, 4%, 5% 
   y del 6% (dichos descuentos se acumulan y se aplican al precio del billete).
   
   Pues bien, para calcular el precio final del billete de avi�n del cliente,
   he establecido una estructura de condicionales simples con anidamientos
   (que conste que no he querido violar el principio de una �nica vez, pero en
   el enunciado se dice que la finalidad del ejercicio es la de "Plantear una
   estructura condional simple"). En primer lugar, he establecido una
   restricci�n de los datos: que la distancia en kil�metros y el n�mero de 
   puntos de la tarjeta de fidelizaci�n est�n representados por enteros 
   positivos, de tal forma que si los datos verifican la condici�n se contin�a
   con el proceso y, en caso contrario, el programa da ERROR y dice al usuario
   lo que debe de introducir.
   
   Dentro de la condici�n de que los datos sean correctos, para calcular el 
   precio final del billete, he establecido una serie de condiciones simples
   para todos los posibles casos que puedan establecerse entre distancia y
   n�mero de puntos. En funci�n de los datos introducidos, se cumplir� alguno
   de esos casos y se calcula el precio final, aplicandole los descuentos,
   (que los he declarado como constantes), si es que las condiciones los 
   amparan.                      
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaraci�n de datos
	
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
	
	// Condiciones, c�lculos y salida de datos
	
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
