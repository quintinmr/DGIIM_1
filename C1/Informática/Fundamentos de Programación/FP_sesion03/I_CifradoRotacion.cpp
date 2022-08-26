/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee un carácter (una letra mayúscula del alfabeto inglés) y
   una clave, entera, que indica el número de posiciones que habrá que desplazar
   el carácter dentro del abecedario, mostrándolo, una vez aplicada la clave, es
   decir, el programa codifica el carácter y lo muestra en pantalla.
   
   Entradas: 
    Una letra mayúscula (caracter) y un número entero que representa
    la clave (clave).
   
   Salidas: 
    El carácter codificado (caracter_codificado).
                      
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
	
	// Desplazamiento del caracter
	
	caracter_desplazado = ('A' + ((caracter+clave) - 'A') % ('Z'+1-'A'));
	
	/* En este programa he procedido de la misma forma que el en ejercicio del
	intervalo (22) de la relación de ejericicios de la sesión 02, ya que 
	basicamente se pide lo mismo; en un intervalo, que en este caso es el 
	abecedario, hay que desplazar un caracter (una letra mayúscula cualquiera 
	del alfabeto inglés), un número determinado de posiciones dictaminado por 
	una clave que intruduce el usuario. De esta forma, y teniendo en cuenta
	que el minimo y el máximo de este intervalo son A y Z respectivamente, y que
	ambos caracteres ocupan en la pagina de codigos ISO/IEC 8859-1, la
	posición 65 y 90 respectivamente (como bien se puede apreciar, he puesto en 
	los cálculos a las letras A y Z, entre comillas simples, es decir, les estoy
    asignando un valor entero a esos caracteres) puedo entonces proceder de la 
	siguiente forma: el caracter codificado será aquel que se encuentra a un 
	número de posiciones determinado a partir de la letra A (mínimo). Ese número
    de posiciones a partir del mínimo será el resultado del cociente entre la 
	posición del caracter inicial, aplicado el desplazamiento determinado por 
	la clave menos la posición del mínimo, y la diferencia entre los extremos 
	del intervalo agrandado una unidad para empezar así a contar justo a partir
	del mínimo (si no le sumase al intervalo una unidad, o lo que es lo mismo
	no le restase la unidad al mínimo, el carácter codificado estarían en un 
	puesto, más allá del que le corresponde una vez aplicado el desplazamiento).
	*/
	
	// Salida de datos
	
	cout << "El caracter codificado es: " << caracter_desplazado <<endl;
	cout <<endl;
	
/******************************************************************************/
	return 0;
}












