/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Este programa consiste en el desarrollo de una funci�n que sirve para 
   redondear un n�mero introducido por el usuario, a un n�mero de cifras
   decimales determinado.
   
   Entradas: 
    N�mero a redondear (numero).
    N�mero de cifras decimales a las que se quiere redondear el n�mero 
    (num_dec).

   Salidas:
    N�mero redondeado a las cifras decimales introducidas (num_redondeado).
    
   Este programa lo he llevado a cabo mediante la definici�n de dos funciones,
   una para c�lculo de una potencia cualquiera y otra para redondear un n�mero
   real cualquiera a una posici�n determinada por el usuario. Dichas funciones
   las he usado, dentro del programa principal, es decir, para calcular el 
   n�mero redondeado, he llamado a la funci�n Redondear, que a su vez tendr� 
   que llamar a la funci�n Potencia.
   La funci�n Potencia la he llevado a cabo mediante una estructura condicional
   doble referida a las caracter�sticas del exponente, que puede ser negativo o
   positivo. Para ambos casos, he establecido un ciclo for, de tal forma que
   las potencias se calcular�n como producto reiterado de la base, para 
   exponentes positivos, y como producto reiterado del inverso de la base para
   exponentes negativos.
   La funci�n redondear, la he implementado mediante una estructura condicional
   doble relativa a la diferencia entre el n�mero real desplazado un n�mero
   de posiciones determinado que introduce el usuario (la posici�n del decimal
   a redondear) y la parte entera de dicho n�mero (todo esto usando la funci�n
   anterior), de manera que si dicha diferencia es mayor o igual que 0.5, se 
   hacen unos c�clulos usando la funci�n potencia y la funci�n floor, y en el
   caso contrario, se procede de la misma forma.
   Finalmente, todas estas funciones, las uso en los c�lculos del programa
   principal, llamando a la funci�n Redondea, trabajando con  los valores 
   que el usuario introduzca.
    
                         
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <cmath>       
#include <iomanip>

using namespace std;  

/******************************************************************************/
/******************************************************************************/


double Potencia (double base, int exp)
{
	double power = 1.0 ;

		// Para el caso en que el exponente sea positivo
		
		if (exp >= 0){
			
			for (int i = 1; i <= exp; i = i +1){
			
				power = power * base;
				
			}
		}
		
		// Para el caso en que el exponente sea negativo
		
		else{
				
			for (int i = 1; i <= abs(exp); i = i +1){
			
			power = (power / base);
			
			}
		}
	
	return (power);
}
		
		
/******************************************************************************/
/******************************************************************************/

double Redondea(double numero, int num_dec)
{
	double num_redondeado;
    double real_desplazado;

		real_desplazado = ( numero * Potencia(10 , num_dec ) );
		
		if ((real_desplazado - floor(real_desplazado)) >= 0.5){
			
           num_redondeado = (floor(real_desplazado)+1)*Potencia(10, -(num_dec));
        	
        }
        
        else
        {
           num_redondeado = (floor(real_desplazado))*Potencia(10, -num_dec);
        	
        }
        
        return (num_redondeado);
}
        
/******************************************************************************/
/******************************************************************************/

int main ()
{

	// Declaraci�n de datos
	
	// Datos de entrada
	
	double numero_a_redondear;
	int numero_decimales_redondeo;  
	
	// Datos de salida
	
	double numero_redondeado;

/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca el numero que desea redondear: ";
	cin  >> numero_a_redondear;
	
	do{
	
		cout <<	"Introduzca el numero de decimales donde desea realizar el "
	     	 << "redondeo: ";
		cin  >> numero_decimales_redondeo;
		
	}while (numero_decimales_redondeo < 0);
	
	// C�lculos
	
	numero_redondeado = Redondea(numero_a_redondear,numero_decimales_redondeo);
	
	// Salida de datos
	
	cout << endl;
	cout << "El numero redondeado es: " << setprecision (15) 
	     << numero_redondeado;
	cout << endl;
	
/******************************************************************************/
	return 0;
}
	 
	     
		
		
		
		
		
		
		
		
	
