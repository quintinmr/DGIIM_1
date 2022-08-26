/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee un caracter determinado, dice si es una letra may�scula, 
   min�scula u otro car�cter diferente y, si la letra es may�scula, la
   convierte a min�scula y si es min�scula, la convierte a may�scula.
   
   Entradas:
    Un car�cter (letra_original). 
    
   Salidas: 
    Un mensaje indicando si el car�cter es una may�scula, una min�scula u otro.
    Un car�cter que puede ser una may�scula o una min�scula (letra_convertida)
	si se ha determinado que el car�cter es una may�scula o una min�scula.
    
   En este programa, para conseguir que me determine si el car�cter introducido
   por el usuario es una letra may�scula, min�scula u otro car�cter, he
   empleado un tipo enumerado, ya que tenemos entre manos informaci�n que 
   tiene unos cu�ntos valores posibles. Pues bien, en primer lugar, he definido
   el tipo (TipoCaracter), que contiene los posibles casos {May�scula, 
   Min�scula, Otro}, y, a continucaci�n he definido la variable de dicho tipo
   (TipoCaracter caracter;). A partir de aqu�, he establecido un anidamiento
   de estructuras condiconales dobles en la que se contemplan los posibles 
   casos, mediante una red de ifs y else, que son los siguientes: que el 
   car�cter introducido sea may�scula (si su posici�n en la tabla de c�digos 
   ASCII est� entre 'A' Y 'Z', ambos inclusive), min�scula (si su posici�n en 
   la tabla est� entre 'a' y 'z', ambos inclusive), o es otro car�cter (este 
   caso se contempla en el �ltimo else, al que se llega cuando no se verifica 
   ni la condici�n de que sea may�scula ni la de min�scula).
   Una vez asignado a la variable del tipo enumerado, el tipo de car�cter del 
   que se trata, cuando se verifica la condici�n, se procede a la conversi�n de
   la letra (ha de verificarse la condici�n de que sea una letra para hacer 
   este proceso), en min�scula, si es may�scula y en may�scula, si es min�scula.
   
   Finalmente, para que todo esto se muestre en pantalla he hecho uso de
   una estructura condicional m�ltiple (switch) en la que se contemplan todos
   los casos del tipo enumerado. De tal forma que si se cumple algunos de dichos
   casos al introducir el usuario los datos, se mostrar� en pantalla el mensaje
   correspondiente, en el cual se dice si el car�cter introducido es una letra
   may�scula, min�scula, u otro car�cter y, si es una may�scula o una min�scula
   , se muestra su conversi�n al tipo de letra correspondiente.
    
                      
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
	
	char letra_original;
	
	// Declaraci�n de una constante
	
	const char DIFERENCIA = 'a'-'A';   // Diferencia entre las may�sculas y 
	                                   // min�sculas en la p�gina de c�digos
	                                   // ASCII (32 posiciones de diferencia). 
	
	// Datos de salida
	
	char letra_convertida;
	
/******************************************************************************/

	// Entrada de datos	
	
	cout << "Introduzca un car�cter (letra may�scula, min�scula u otro): ";
	cin  >> letra_original;
	
	// Condiciones y c�lculos 
	
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
    	
    		cout << "El caracter es una letra may�scula. Una vez convertida a "
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
    
   		
			
		
	
