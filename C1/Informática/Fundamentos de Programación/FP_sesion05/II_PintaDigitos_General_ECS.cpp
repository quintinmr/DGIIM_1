/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee un n�mero entero positivo, comprobando previamente que
   dicho n�mero sea de tal condici�n y compone un string con los d�gitos del
   n�mero, separados por una barra vertical (|).
   
   Entradas: 
    Un n�mero entero positivo (numero).
    
   Salidas:
    Una cadena de caracteres constitu�da por los d�gitos del n�mero separados
	por barras verticales (cad_numero). 
   
   En este programa, en primer lugar, he establecido una estructura repetitiva 
   de tipo pre-test, para que en caso de que el n�mero introducido por el
   usuario no sea un entero positivo, el cuerpo del ciclo se repita y vuelva
   a pedirle que introduzca un n�mero. 
   Una vez que el n�mero es correcto, se procede a los c�lculos pertinentes
   acerca del n�mero de d�gitos del n�mero, y al proceso de transformaci�n
   del n�mero en una cadena de caracteres, constitu�da por los d�gitos del
   n�mero introducido, separados por barras verticales (|). He de decir que 
   he asignado un valor inicial a las variables con el prop�sito de que el bucle
   que he constitu�do no fuera un bucle sin fin. Pues bien, a continuaci�n, he 
   establecido un ciclo while, que se desarrollar�, al menos una vez porque
   la condici�n que le he puesto, la he declarado como una variable de tipo
   bool y le he asignado una expresi�n que consite en que el n�mero introducido 
   ha de tener al menos dos cifras, de esta forma, si se cumple, se entra al 
   bucle y se efectuar�n todos los c�lculos: en primer lugar, calculo el �ltimo 
   d�gito del n�mero, independientemente del n�mero de d�gitos que tenga, 
   mediante el operador m�dulo; ser� el resto de dividir el n�mero introducido 
   entre diez. A continuaci�n acutalizo la variable a la que tengo asociada la 
   cadena de caracteres final, mediante la adici�n de un espaciador, que declaro 
   como una constante de tipo string, el �ltimo d�gito del n�mero calculado, 
   convertido a dato de tipo string mediante la funci�n to_string, y el valor
   inicial que ten�a asignada la variable de la cadena de caracteres resultante,
   que es una barra vertical. De esta forma, por ahora, el �ltimo d�gito 
   aparecer�a en pantalla entre barras. A continuaci�n se actualiza la variable
   contadora, pues, en un principio estaba a cero, pero ahora est� a cero m�s
   uno (el �ltimo d�gito). Se actualiza finalmente la variable n�mero, que pasa
   a ser el cociente entero del n�mero inicial entre diez; el n�mero tendr�
   una cifra menos que incialemente. Y as� sucesivamente. Finalmente actualizo
   la variable tipo bool asign�ndole la expresi�n que consite en que el 
   n�mero introducido ha de ser mayor o igual que d�ez, es decir que tenga un
   n�mero de d�gitos mayor o igual que dos. Y se cierra el bucle. 
   Finalmente, se agrega el d�gito que hemos obtenido al final del bucle a 
   la cadena resultante, a�adi�ndose tambi�n el d�gito al contador.
   Si el n�mero no tiene m�s de dos cifras, no se cumple la condici�n del ciclo 
   y se pasa directamente a la sentencia en la que se asigna a la cadena 
   resultante el n�mero que en teor�a se obtendr�a al final del bucle, pero que
   en este caso no es otro que el propio n�mero de un d�gito. As� como tambien
   la variable contador indicadr� que el n�mero de d�gitos del n�mero 
   introducido es el inicial m�s uno (o sea, uno).
                         
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <string>
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaraci�n de datos
	
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
	
	// C�lculos 
	
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
