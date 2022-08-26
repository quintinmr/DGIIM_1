/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee un caracter determinado, dice si es una letra mayúscula, 
   minúscula u otro carácter diferente y, si la letra es mayúscula, la
   convierte a minúscula y si es minúscula, la convierte a mayúscula.
   
   Entradas:
    Un carácter (letra_original). 
    
   Salidas: 
    Un mensaje indicando si el carácter es una mayúscula, una minúscula u otro.
    Un carácter que puede ser una mayúscula o una minúscula (letra_convertida)
	si se ha determinado que el carácter es una mayúscula o una minúscula.
    
   En este programa, para conseguir que me determine si el carácter introducido
   por el usuario es una letra mayúscula, minúscula u otro carácter, he
   empleado un tipo enumerado, ya que tenemos entre manos información que 
   tiene unos cuántos valores posibles. Pues bien, en primer lugar, he definido
   el tipo (TipoCaracter), que contiene los posibles casos {Mayúscula, 
   Minúscula, Otro}, y, a continucación he definido la variable de dicho tipo
   (TipoCaracter caracter;). A partir de aquí, he establecido un anidamiento
   de estructuras condiconales dobles en la que se contemplan los posibles 
   casos, mediante una red de ifs y else, que son los siguientes: que el 
   carácter introducido sea mayúscula (si su posición en la tabla de códigos 
   ASCII está entre 'A' Y 'Z', ambos inclusive), minúscula (si su posición en 
   la tabla está entre 'a' y 'z', ambos inclusive), o es otro carácter (este 
   caso se contempla en el último else, al que se llega cuando no se verifica 
   ni la condición de que sea mayúscula ni la de minúscula).
   Una vez asignado a la variable del tipo enumerado, el tipo de carácter del 
   que se trata, cuando se verifica la condición, se procede a la conversión de
   la letra (ha de verificarse la condición de que sea una letra para hacer 
   este proceso), en minúscula, si es mayúscula y en mayúscula, si es minúscula.
   
   Finalmente, para que todo esto se muestre en pantalla he hecho uso de
   una estructura condicional múltiple (switch) en la que se contemplan todos
   los casos del tipo enumerado. De tal forma que si se cumple algunos de dichos
   casos al introducir el usuario los datos, se mostrará en pantalla el mensaje
   correspondiente, en el cual se dice si el carácter introducido es una letra
   mayúscula, minúscula, u otro carácter y, si es una mayúscula o una minúscula
   , se muestra su conversión al tipo de letra correspondiente.
    
                      
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
	
	char letra_original;
	
	// Declaración de una constante
	
	const char DIFERENCIA = 'a'-'A';   // Diferencia entre las mayúsculas y 
	                                   // minúsculas en la página de códigos
	                                   // ASCII (32 posiciones de diferencia). 
	
	// Datos de salida
	
	char letra_convertida;
	
/******************************************************************************/

	// Entrada de datos	
	
	cout << "Introduzca un carácter (letra mayúscula, minúscula u otro): ";
	cin  >> letra_original;
	
	// Condiciones y cálculos 
	
	enum class TipoCaracter { Mayuscula, Minuscula, Otro };
	
	TipoCaracter caracter;
	
	if ((letra_original >= 'A') && (letra_original <= 'Z')){
		
		caracter = TipoCaracter::Mayuscula;
		
		letra_convertida = (letra_original + DIFERENCIA);
     	     
    }       
    
	else	     
	{
		if ((letra_original >= 'a') && (letra_original <= 'z')) {
		
		caracter = TipoCaracter::Minuscula;
		
		letra_convertida = (letra_original - DIFERENCIA);
	 	     
        }
        
        else
        {
        	caracter = TipoCaracter::Otro;
        	    	
       }
       
    }
    
    // Salida de datos
    
    switch (caracter) {
    	
    	case (TipoCaracter::Mayuscula):
    	
    		cout << "El caracter es una letra mayúscula. Una vez convertida a "
     	         << "minuscula es: " << letra_convertida <<endl;
     	
			break;
		
		case (TipoCaracter::Minuscula):
			
			cout << "El caracter es una letra minuscula. Una vez convertida a "
     	         << "mayuscula es: " << letra_convertida <<endl;
     	     
        	break;
		
		
		case (TipoCaracter::Otro):
		     
			cout << "El caracter introducido no es una letra mayuscula "
             	 << "o minuscula." << endl;    
             	 
            break; 	 
   
    }
    
    cout << endl;
    
/******************************************************************************/
	return 0;
}
    
   		
			
		
	
