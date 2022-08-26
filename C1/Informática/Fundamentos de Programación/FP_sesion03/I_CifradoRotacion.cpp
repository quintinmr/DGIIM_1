/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee un car�cter (una letra may�scula del alfabeto ingl�s) y
   una clave, entera, que indica el n�mero de posiciones que habr� que desplazar
   el car�cter dentro del abecedario, mostr�ndolo, una vez aplicada la clave, es
   decir, el programa codifica el car�cter y lo muestra en pantalla.
   
   Entradas: 
    Una letra may�scula (caracter) y un n�mero entero que representa
    la clave (clave).
   
   Salidas: 
    El car�cter codificado (caracter_codificado).
                      
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
	intervalo (22) de la relaci�n de ejericicios de la sesi�n 02, ya que 
	basicamente se pide lo mismo; en un intervalo, que en este caso es el 
	abecedario, hay que desplazar un caracter (una letra may�scula cualquiera 
	del alfabeto ingl�s), un n�mero determinado de posiciones dictaminado por 
	una clave que intruduce el usuario. De esta forma, y teniendo en cuenta
	que el minimo y el m�ximo de este intervalo son A y Z respectivamente, y que
	ambos caracteres ocupan en la pagina de codigos ISO/IEC 8859-1, la
	posici�n 65 y 90 respectivamente (como bien se puede apreciar, he puesto en 
	los c�lculos a las letras A y Z, entre comillas simples, es decir, les estoy
    asignando un valor entero a esos caracteres) puedo entonces proceder de la 
	siguiente forma: el caracter codificado ser� aquel que se encuentra a un 
	n�mero de posiciones determinado a partir de la letra A (m�nimo). Ese n�mero
    de posiciones a partir del m�nimo ser� el resultado del cociente entre la 
	posici�n del caracter inicial, aplicado el desplazamiento determinado por 
	la clave menos la posici�n del m�nimo, y la diferencia entre los extremos 
	del intervalo agrandado una unidad para empezar as� a contar justo a partir
	del m�nimo (si no le sumase al intervalo una unidad, o lo que es lo mismo
	no le restase la unidad al m�nimo, el car�cter codificado estar�an en un 
	puesto, m�s all� del que le corresponde una vez aplicado el desplazamiento).
	*/
	
	// Salida de datos
	
	cout << "El caracter codificado es: " << caracter_desplazado <<endl;
	cout <<endl;
	
/******************************************************************************/
	return 0;
}












