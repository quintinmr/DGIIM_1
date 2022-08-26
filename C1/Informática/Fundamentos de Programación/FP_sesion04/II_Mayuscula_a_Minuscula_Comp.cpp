/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee un car�cter (ser� una letra may�scula), lo pasa a 
   min�scula y lo imprime en pantalla, comprobando previamente, que el 
   usuario ha introducido una letra may�scula y no otro car�cter.

   Entradas: 
    Una letra en may�scula.
   
   Salidas: 
    Una letra en min�scula.
    
    En este programa he establecido una condici�n doble, que se cumplir�
    s� y solo s� el usuario introduce una letra may�scula como car�cter.
    En cualquier otro caso, (he establecido un else), el programa indicar�
    al usuario que el car�cter que ha introducido es err�neo, y le pedir� 
    que vuelva a iniciar el programa e introduzca una letra may�scula.
    Por otra parte, si se cumple la condic�n, la letra may�scula se deber�
    transformar en min�scula y para ello, hago uso de la equivalencia entre
    datos de tipo car�cter y entero, mediante las comillas simples (se 
	alamacenar� la posici�n (entera) de la letra may�scula en la tabla de 
	c�digos ASCII); la letra may�scula se traNsformar� en min�scula al sumarle 
	la diferencia com�n entre las letras may�sculas y min�sculas en la p�gina
	de c�digos ASCII, que es de 32 posiciones.
                      
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	
	// DECLARACI�N DE DATOS
	
	// Datos de entrada
	
    char caracter;
    const int DIFERENCIA = ('a' - 'A');   
    
    // Dato de salida
    
	char minuscula;
    
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca una letra en mayuscula: ";
	cin >> caracter;
	
	// Condiciones, c�lculos y salida de datos
	
	if ((caracter >= 'A') && (caracter <= 'Z')) {
		
		minuscula = caracter + DIFERENCIA;
		
		cout << "La letra es mayuscula y su correspondiente minuscula es: "
		     << minuscula <<endl;
		     
    }
    
    else 
    {
    	cout << "El caracter introducido no es una letra mayuscula. Por favor"
    	     << " inicie de nuevo el programa e introduzca una letra en"
    	     << " mayuscula." <<endl;
    	     
    }
	
/******************************************************************************/    
    return 0;
}
