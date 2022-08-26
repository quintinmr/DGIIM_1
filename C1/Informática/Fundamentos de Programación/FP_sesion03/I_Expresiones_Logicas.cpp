/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa en el que confluyen cinco expresiones l�gicas diferentes que, a
   partir de una serie de datos de entrada (diferentes en todas las expresiones)
   devuelven 1s o 0s ,en funci�n de si para los datos que ha introducido el 
   usuario, las variables l�gicas declaradas se cumplen ( True (1) ) o no (False
   (0) ).
   
   Entradas: 
    Expresi�n l�gica 1: una letra (letra).
    Expresi�n l�gica 2: un n�mero entero que indica una edad (edad).
    Expresi�n l�gica 3: un a�o cualquiera (annus).
    Expresi�n l�gica 4: una distancia cualquiera (distancia) y una constante 
    (LIMITE).
    Expresi�n l�gica 5: dos n�meros enteros (numero1, y numero2).
   
   Salidas: 
    True (1) o False (0)
                      
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	
	// Primera expresi�n l�gica
	
	// Declaraci�n de datos
	
	// Datos de entrada
	
	char letra;
	const int DIFERENCIA = 32;

	bool mayuscula;
	
	// Datos de salida
	
	// True (1) o False (0)	
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "�Mayuscula o no mayuscula?" <<endl;
	
	cout <<endl;
		
	cout << "Introduzca una letra: ";
	cin >> letra;
	
	// Letra mayuscula
	
	mayuscula = (letra / DIFERENCIA) == 2;	
	
	/* Todas las letras may�sculas se encuentran en la p�gina de c�gigos ISO/IEC
	8859-1, en una posici�n tal que la parte entera del cociente entre su 
	posici�n y el n�mero de posiciones que separa a las may�sculas de las 
	min�sculas (32 posiciones) es 2, evidenci�ndose as� la equivalencia entre
	los tipos enteros y caracteres.                                           */
	
	// Salida de datos
	
	cout << "Es mayuscula si sale 1, y no lo es si sale 0:" <<endl;
	
	cout << mayuscula <<endl;
	
	cout <<endl;
	
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/	
	// Segunda expresi�n l�gica
	
    // Daclaraci�n de datos
	
	// Datos de entrada
	
	int edad;        
	
	bool mayor_o_igual_y_menor;
	
	// Datos de salida
	
	//True (1) o false (0)
	
/******************************************************************************/
    
	// Entrada de datos
	
	cout << "Comparacion edad (mayor o igual que 18 y menor que 67)" <<endl;
	
	cout <<endl;
	
	cout << "Introduzca una edad determinada: ";
	cin >> edad;
	
	// Comparaci�n
	
	mayor_o_igual_y_menor = (edad >= 18) && (edad < 67);
	
	// Salida de datos
	
	cout << "Es mayor o igual que 18 y menor estrito que 67 si sale 1, y si es "
	"lo contrario, sale 0:" <<endl;
	
	cout << mayor_o_igual_y_menor <<endl;
	
	cout <<endl;
	
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

	// Tercera expresi�n l�gica
	
	// Declaraci�n de datos
	
	// Datos de entrada

	int annus;
 
    bool bisiesto;
    
    // Datos de salida
	
	//True (1) o false (0)
    
/******************************************************************************/    

	// Entrada de datos
	
	cout << "Annus bisiesto" <<endl;
	
	cout <<endl;
	
	cout << "Introduzca un annus cualquiera: ";
	cin >> annus;
	
	// C�lculo
	
	bisiesto = ((annus % 4 == 0) && !(annus % 100 == 0)) || (annus % 400 == 0);
	
	/* Un a�o es bisiesto s� y solo s� es divisible por 4 pero no por 100 o
	bien es divisible por 400.                                                */
	
	// Salida de datos
	
	cout << "El annus es bisiesto si sale 1, y no lo es si sale 0:" <<endl;
	
	cout << bisiesto <<endl;
	
	cout <<endl;
	
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/	

	// Cuarta expresi�n l�gica
	
	// Declaraci�n de datos
	
	// Datos de entrada
	
	double distancia;	
	const double LIMITE = 56.89;   // Declaraci�n de una constante
	
	bool condicion;
	
	// Datos de salida
	
	//True (1) o false (0)
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Comparacion entre una distancia y una constante LIMITE" <<endl;
	
	cout <<endl;
	
	cout << "Introduzca una distancia cualquiera: ";
	cin >> distancia;
	
	// Comparaci�n de los datos
	
    condicion = distancia < LIMITE;
	
	// Salida de datos
	
	cout << "La distancia es menor que LIMITE si sale 1 y 0 si es lo contrario:"
	<<endl;
	
	cout << condicion <<endl;
	
	cout <<endl;
	
/******************************************************************************/
/******************************************************************************/		
/******************************************************************************/

	// Quinta expresi�n l�gica

	// Declaraci�n de datos
	
	// Datos de entrada
	
	int numero1;
	int numero2;
	
	bool menor, mayor, iguales;
	
	// Datos de salida
	
	//True (1) o false (0)
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Comparacion de dos numeros enteros positivos" <<endl;
	
	cout <<endl;
	
	cout << "Introduzca un numero: ";
	cin >> numero1;
	
	cout << "Introduzca otro numero: ";
	cin >> numero2;
	
	// Comparaci�n de los datos
	
	menor = numero1 < numero2;
	mayor = numero1 > numero2;
	iguales = numero1 == numero2;
	
	// Salida de datos
	
	cout << "Si el primer numero es menor que el segundo, sale 1,0,0. Si el "
	"primer numero es mayor que el segundo, sale 0,1,0, y si son iguales,0,0,1:"
	<<endl;
	
	cout << menor <<endl;
	
	cout << mayor <<endl;
	
	cout << iguales <<endl;
	
	cout <<endl;

/******************************************************************************/	
	return 0;
}
    
