/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee una cantidad capital y un inter�s determinado y 
  calcula el n�mero de a�os que han de pasar hasta llegar a doblar como m�nimo 
  el capital de partida.
   
   Entradas: 
    Capital inicial (capital_inicial)
    El inter�s que se va a aplicar al capital (interes)
    
   Salidas:
    N�mero de a�os que han de pasar hasta doblar, como m�nimo el capital (anios)
   
   
   En este programa, he establecido una serie de estructuras repetitivas, en
   primer lugar, para las restricciones de los datos a introducir por el 
   usuario, las cuales son bucles controlados por una condici�n; exactamente
   he establecido bucles post-test, porque se evalua primero el cuerpo del
   bloque y luego la condic�n, de forma que si dicha condici�n no se cumple
   se repite el cuerpo del bucle, es decir, si los datos introducidos son 
   incorrectos, se vuelve a pedir que introduzca el dato que anteriormente
   hab�a introducido err�neamente.
   Restricciones: capital inicial >=0
                  inter�s 0<I<=10
   A continuaci�n, una vez filtrados los datos, se procede al c�lculo del
   n�mero de a�os. Para ello, en primer lugar le he asignado un valor a 
   la subida producida por el inter�s; calculo el factor de subida que se aplica 
   al capital inicial una vez aplicado el inter�s y le he asignado al valor 
   final del capital el valor inicial del mismo, por el simple hecho de evitar 
   que el bucle no tenga fin. Adem�s, he le he asignado a la variable a�os el
   valor original cero (inicio el contador a�os). Finalmente he establecido una 
   estructura repetitiva de tipo post-test que entrar� en bucle s� y solo s� el
   capital total; una vez aplicado el inter�s, es menor o igual que el doble del 
   capital inicial. Y actualizo el contador de a�os. De tal forma que, una vez
   se llegue a doblar el capital inicial, el contador de a�os se para y se sale
   del bucle.
    
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
    
	
	// C�lculos 
	
	/* El tanto porciento que aumenta el capital inicial al aplicarle el
       inter�s es el siguiente: 
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
	
	
	
	
