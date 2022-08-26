/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee un número entero positivo, comprobando previamente que
   dicho número sea de tal condición y compone un string con los dígitos del
   número, separados por una barra vertical (|).
   
   Entradas: 
    Un número entero positivo (numero).
    
   Salidas:
    Una cadena de caracteres constituída por los dígitos del número separados
	por barras verticales (cad_numero). 
   
   En este programa, en primer lugar, he establecido una estructura repetitiva 
   de tipo pre-test, para que en caso de que el número introducido por el
   usuario no sea un entero positivo, el cuerpo del ciclo se repita y vuelva
   a pedirle que introduzca un número. 
   Una vez que el número es correcto, se procede a los cálculos pertinentes
   acerca del número de dígitos del número, y al proceso de transformación
   del número en una cadena de caracteres, constituída por los dígitos del
   número introducido, separados por barras verticales (|). He de decir que 
   he asignado un valor inicial a las variables con el propósito de que el bucle
   que he constituído no fuera un bucle sin fin. Pues bien, a continuación, he 
   establecido un ciclo while, que se desarrollará, al menos una vez porque
   la condición que le he puesto, la he declarado como una variable de tipo
   bool y le he asignado una expresión que consite en que el número introducido 
   ha de tener al menos dos cifras, de esta forma, si se cumple, se entra al 
   bucle y se efectuarán todos los cálculos: en primer lugar, calculo el último 
   dígito del número, independientemente del número de dígitos que tenga, 
   mediante el operador módulo; será el resto de dividir el número introducido 
   entre diez. A continuación acutalizo la variable a la que tengo asociada la 
   cadena de caracteres final, mediante la adición de un espaciador, que declaro 
   como una constante de tipo string, el último dígito del número calculado, 
   convertido a dato de tipo string mediante la función to_string, y el valor
   inicial que tenía asignada la variable de la cadena de caracteres resultante,
   que es una barra vertical. De esta forma, por ahora, el último dígito 
   aparecería en pantalla entre barras. A continuación se actualiza la variable
   contadora, pues, en un principio estaba a cero, pero ahora está a cero más
   uno (el último dígito). Se actualiza finalmente la variable número, que pasa
   a ser el cociente entero del número inicial entre diez; el número tendrá
   una cifra menos que incialemente. Y así sucesivamente. Finalmente actualizo
   la variable tipo bool asignándole la expresión que consite en que el 
   número introducido ha de ser mayor o igual que díez, es decir que tenga un
   número de dígitos mayor o igual que dos. Y se cierra el bucle. 
   Finalmente, se agrega el dígito que hemos obtenido al final del bucle a 
   la cadena resultante, añadiéndose también el dígito al contador.
   Si el número no tiene más de dos cifras, no se cumple la condición del ciclo 
   y se pasa directamente a la sentencia en la que se asigna a la cadena 
   resultante el número que en teoría se obtendría al final del bucle, pero que
   en este caso no es otro que el propio número de un dígito. Así como tambien
   la variable contador indicadrá que el número de dígitos del número 
   introducido es el inicial más uno (o sea, uno).
                         
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <string>
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaración de datos
	
	// Datos de entrada
	
	int numero = 0;
	int contador = 0;
	string cad_result = "|";
	const string ESPACIADOR = "|";
	int ultimo_digito;
		
/******************************************************************************/

	// Entrada de datos
	
	do{
	
		cout << "Introduzca un numero: ";
		cin  >> numero;
			
	}while (numero < 0);
	
	// Cálculos 
	
	bool numero_varias_cifras = (numero >= 10);
	
	while (numero_varias_cifras){
		
		ultimo_digito = (numero % 10);
		
		cad_result = (ESPACIADOR + to_string(ultimo_digito) + cad_result);
		
		contador = (contador + 1);
		
		numero = (numero / 10);
		
		numero_varias_cifras = (numero >= 10);
		
	}
	
	cad_result = (ESPACIADOR + to_string(numero) + cad_result);
	
	contador = (contador + 1);

	// Salida de datos
	
	cout << endl;
	cout << "El numero introducido tiene " << contador <<" digitos, que son los"
	     << " siguientes: " << cad_result <<endl;
	cout << endl;
	
    
	
/******************************************************************************/
	return 0;
}
