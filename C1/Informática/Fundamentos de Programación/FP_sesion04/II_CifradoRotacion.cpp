/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee un car�cter (una letra may�scula del alfabeto ingl�s) y
   una clave, entera, que indica el n�mero de posiciones que habr� que 
   desplazar el car�cter dentro del abecedario, mostr�ndolo, una vez aplicada 
   la clave, es decir, el programa codifica el car�cter y lo muestra en 
   pantalla.
   
   Entradas: 
    Una letra may�scula (caracter) y un n�mero entero que representa
    la clave (clave).
   
   Salidas: 
    El car�cter codificado (caracter_codificado).
    
    En este programa, dado que no se puede hacer uso del operador m�dulo,
    he procedido de la siguiente manera: he establecido dos condiciones 
    simples, una para el caso en el que el carcter, al aplicarle el 
    desplazamiento determinado por la clave, no se salga del intervalo (el 
    abecedario), es decir, que la posici�n del caracter una vez aplicado el 
	desplazamiento en la p�gina de c�digos ASCII es menor o igual que la 
	posici�n del m�ximo del intervalo, que es Z (las posiciones no las he puesto
	explicitamente con n�meros (lo que se lama "n�meros m�gicos"), sino que 
	he hecho uso de las comillas simples para se�alar la posici�n de la Z y de
	la A (m�nimo delintervalo), evidenciando la equivalencia entre datos de
	tipo entero y de tipo car�cter. Pues bien, en este caso, el car�cter 
	codificado ser� simplemente el correspondiente al aplicarle al car�cter 
	de partida, la clave. Por otra parte, la segunda condici�n simple que 
	he establecido se centra en el caso en el que el car�cter se salga del 
	intervalo al aplicarle la clave, es decir, que la posici�n del car�cter
	una vez aplicado el desplazamiento sea mayor estricto que la posici�n
	de Z. En este caso, el car�cter codificado ser� aquel que se encuentre
	a un n�mero de posiciones determinado a partir del m�nimo (A), (que puede
	ser cero, perfectamente). Ese n�mero de posiciones resulta de la 
	diferencia entre la posici�n del car�cter con la clave aplicada, y el
	el m�ximo del intervalo, agrandado una unidad (porque si no, la posici�n
	del car�cter codificado ser�a una m�s de la correspondiente; contar�amos 
	el m�nimo dos veces, por as� decirlo).
	De esta forma, en funci�n de lo que el usuario introduzca se cumplir�
	una condici�n u otra, y se ejecutar�n las sentencias pertinentes.                     
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
	
	
	//  Condiciones, c�lculos y salida de datos
	

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
	
