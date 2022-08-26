/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee una cantidad capital y un interés determinado y 
  calcula el número de años que han de pasar hasta llegar a doblar como mínimo 
  el capital de partida.
   
   Entradas: 
    Capital inicial (capital_inicial)
    El interés que se va a aplicar al capital (interes)
    
   Salidas:
    Número de años que han de pasar hasta doblar, como mínimo el capital (anios)
   
   
   En este programa, he establecido una serie de estructuras repetitivas, en
   primer lugar, para las restricciones de los datos a introducir por el 
   usuario, las cuales son bucles controlados por una condición; exactamente
   he establecido bucles post-test, porque se evalua primero el cuerpo del
   bloque y luego la condicón, de forma que si dicha condición no se cumple
   se repite el cuerpo del bucle, es decir, si los datos introducidos son 
   incorrectos, se vuelve a pedir que introduzca el dato que anteriormente
   había introducido erróneamente.
   Restricciones: capital inicial >=0
                  interés 0<I<=10
   A continuación, una vez filtrados los datos, se procede al cálculo del
   número de años. Para ello, en primer lugar le he asignado un valor a 
   la subida producida por el interés; calculo el factor de subida que se aplica 
   al capital inicial una vez aplicado el interés y le he asignado al valor 
   final del capital el valor inicial del mismo, por el simple hecho de evitar 
   que el bucle no tenga fin. Además, he le he asignado a la variable años el
   valor original cero (inicio el contador años). Finalmente he establecido una 
   estructura repetitiva de tipo post-test que entrará en bucle sí y solo sí el
   capital total; una vez aplicado el interés, es menor o igual que el doble del 
   capital inicial. Y actualizo el contador de años. De tal forma que, una vez
   se llegue a doblar el capital inicial, el contador de años se para y se sale
   del bucle.
    
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
	
	double capital_inicial;
	double interes;
	int anios;
	
	double subida; 
	
	// Datos de salida
	
	double total; 
	
/******************************************************************************/

	// Entrada de datos
	
	do{
	
		cout << "Introduzca el capital inicial: ";
		cin  >> capital_inicial;
		
    }while (capital_inicial < 0 );
    
    do{
    	
    	cout << "Introduzca el interes que se aplicara al capital inicial: ";
    	cin  >> interes;
    	
    }while ((interes <= 0) || (interes > 10));
    
	
	// Cálculos 
	
	/* El tanto porciento que aumenta el capital inicial al aplicarle el
       interés es el siguiente: 
    */
	
	subida = 1 + (interes / 100.0);
	
	total = capital_inicial;   
	anios = 0;
	
	do{
		
		total = total * subida;
		anios = (anios + 1);  //Se reinvierte el dinero obtenido
	
    }while (total <= (2 * capital_inicial));
     
     
    // Salida de datos
	 
    cout << endl;
    cout << "El numero de anios que han de pasar para que el capital de partida"
	         " hasta doblar como minimo dicho capital es: " << anios; 
	cout <<	endl;

  	
/******************************************************************************/
	return 0;
}
	
	
	
	
