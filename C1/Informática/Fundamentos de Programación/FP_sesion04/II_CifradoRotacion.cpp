/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee un carácter (una letra mayúscula del alfabeto inglés) y
   una clave, entera, que indica el número de posiciones que habrá que 
   desplazar el carácter dentro del abecedario, mostrándolo, una vez aplicada 
   la clave, es decir, el programa codifica el carácter y lo muestra en 
   pantalla.
   
   Entradas: 
    Una letra mayúscula (caracter) y un número entero que representa
    la clave (clave).
   
   Salidas: 
    El carácter codificado (caracter_codificado).
    
    En este programa, dado que no se puede hacer uso del operador módulo,
    he procedido de la siguiente manera: he establecido dos condiciones 
    simples, una para el caso en el que el carcter, al aplicarle el 
    desplazamiento determinado por la clave, no se salga del intervalo (el 
    abecedario), es decir, que la posición del caracter una vez aplicado el 
	desplazamiento en la página de códigos ASCII es menor o igual que la 
	posición del máximo del intervalo, que es Z (las posiciones no las he puesto
	explicitamente con números (lo que se lama "números mágicos"), sino que 
	he hecho uso de las comillas simples para señalar la posición de la Z y de
	la A (mínimo delintervalo), evidenciando la equivalencia entre datos de
	tipo entero y de tipo carácter. Pues bien, en este caso, el carácter 
	codificado será simplemente el correspondiente al aplicarle al carácter 
	de partida, la clave. Por otra parte, la segunda condición simple que 
	he establecido se centra en el caso en el que el carácter se salga del 
	intervalo al aplicarle la clave, es decir, que la posición del carácter
	una vez aplicado el desplazamiento sea mayor estricto que la posición
	de Z. En este caso, el carácter codificado será aquel que se encuentre
	a un número de posiciones determinado a partir del mínimo (A), (que puede
	ser cero, perfectamente). Ese número de posiciones resulta de la 
	diferencia entre la posición del carácter con la clave aplicada, y el
	el máximo del intervalo, agrandado una unidad (porque si no, la posición
	del carácter codificado sería una más de la correspondiente; contaríamos 
	el mínimo dos veces, por así decirlo).
	De esta forma, en función de lo que el usuario introduzca se cumplirá
	una condición u otra, y se ejecutarán las sentencias pertinentes.                     
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
	
	int clave;
	char caracter;
	
	// Datos de salida
	
	char caracter_desplazado;
	
/******************************************************************************/	

	// Entrada de datos
	
	cout << "Introduzca una letra mayuscula: ";
	cin >> caracter;
	
	cout << "Introduzca la clave: ";
	cin >> clave;
	
	
	//  Condiciones, cálculos y salida de datos
	

    if ((caracter < 'A') || (caracter > 'Z')) {
	
		cout << "ERROR: Caracter incorrecto, inicie de nuevo el programa e"
		     << " introduzca una letra mayuscula." <<endl;
		
    }

    if ((caracter >= 'A') && (caracter <= 'Z')) {  

	
		if ((caracter + clave) > 'Z') {
		
		  caracter_desplazado = ((caracter + clave - 'Z' - 1) + 'A') ;
		
		  cout << "El caracter codificado es: " << caracter_desplazado <<endl;
    
	    }
		
		if ((caracter + clave) <= 'Z') {
	
		  caracter_desplazado = ( caracter + clave );
		
		  cout << "El caracter codificado es: " << caracter_desplazado <<endl;
	
     	}
    }
	
		
/******************************************************************************/

	return 0;
}
	
