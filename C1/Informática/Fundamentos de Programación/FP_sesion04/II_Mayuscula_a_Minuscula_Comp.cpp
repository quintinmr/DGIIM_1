/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee un carácter (será una letra mayúscula), lo pasa a 
   minúscula y lo imprime en pantalla, comprobando previamente, que el 
   usuario ha introducido una letra mayúscula y no otro carácter.

   Entradas: 
    Una letra en mayúscula.
   
   Salidas: 
    Una letra en minúscula.
    
    En este programa he establecido una condición doble, que se cumplirá
    sí y solo sí el usuario introduce una letra mayúscula como carácter.
    En cualquier otro caso, (he establecido un else), el programa indicará
    al usuario que el carácter que ha introducido es erróneo, y le pedirá 
    que vuelva a iniciar el programa e introduzca una letra mayúscula.
    Por otra parte, si se cumple la condicón, la letra mayúscula se deberá
    transformar en minúscula y para ello, hago uso de la equivalencia entre
    datos de tipo carácter y entero, mediante las comillas simples (se 
	alamacenará la posición (entera) de la letra mayúscula en la tabla de 
	códigos ASCII); la letra mayúscula se traNsformará en minúscula al sumarle 
	la diferencia común entre las letras mayúsculas y minúsculas en la página
	de códigos ASCII, que es de 32 posiciones.
                      
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	
	// DECLARACIÓN DE DATOS
	
	// Datos de entrada
	
    char caracter;
    const int DIFERENCIA = ('a' - 'A');   
    
    // Dato de salida
    
	char minuscula;
    
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca una letra en mayuscula: ";
	cin >> caracter;
	
	// Condiciones, cálculos y salida de datos
	
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
