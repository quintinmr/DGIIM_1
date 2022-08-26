/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa en el que confluyen cinco expresiones lógicas diferentes que, a
   partir de una serie de datos de entrada (diferentes en todas las expresiones)
   devuelven 1s o 0s ,en función de si para los datos que ha introducido el 
   usuario, las variables lógicas declaradas se cumplen ( True (1) ) o no (False
   (0) ).
   
   Entradas: 
    Expresión lógica 1: una letra (letra).
    Expresión lógica 2: un número entero que indica una edad (edad).
    Expresión lógica 3: un año cualquiera (annus).
    Expresión lógica 4: una distancia cualquiera (distancia) y una constante 
    (LIMITE).
    Expresión lógica 5: dos números enteros (numero1, y numero2).
   
   Salidas: 
    True (1) o False (0)
                      
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	
	// Primera expresión lógica
	
	// Declaración de datos
	
	// Datos de entrada
	
	char letra;
	const int DIFERENCIA = 32;

	bool mayuscula;
	
	// Datos de salida
	
	// True (1) o False (0)	
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "¿Mayuscula o no mayuscula?" <<endl;
	
	cout <<endl;
		
	cout << "Introduzca una letra: ";
	cin >> letra;
	
	// Letra mayuscula
	
	mayuscula = (letra / DIFERENCIA) == 2;	
	
	/* Todas las letras mayúsculas se encuentran en la página de cógigos ISO/IEC
	8859-1, en una posición tal que la parte entera del cociente entre su 
	posición y el número de posiciones que separa a las mayúsculas de las 
	minúsculas (32 posiciones) es 2, evidenciándose así la equivalencia entre
	los tipos enteros y caracteres.                                           */
	
	// Salida de datos
	
	cout << "Es mayuscula si sale 1, y no lo es si sale 0:" <<endl;
	
	cout << mayuscula <<endl;
	
	cout <<endl;
	
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/	
	// Segunda expresión lógica
	
    // Daclaración de datos
	
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
	
	// Comparación
	
	mayor_o_igual_y_menor = (edad >= 18) && (edad < 67);
	
	// Salida de datos
	
	cout << "Es mayor o igual que 18 y menor estrito que 67 si sale 1, y si es "
	"lo contrario, sale 0:" <<endl;
	
	cout << mayor_o_igual_y_menor <<endl;
	
	cout <<endl;
	
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

	// Tercera expresión lógica
	
	// Declaración de datos
	
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
	
	// Cálculo
	
	bisiesto = ((annus % 4 == 0) && !(annus % 100 == 0)) || (annus % 400 == 0);
	
	/* Un año es bisiesto sí y solo sí es divisible por 4 pero no por 100 o
	bien es divisible por 400.                                                */
	
	// Salida de datos
	
	cout << "El annus es bisiesto si sale 1, y no lo es si sale 0:" <<endl;
	
	cout << bisiesto <<endl;
	
	cout <<endl;
	
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/	

	// Cuarta expresión lógica
	
	// Declaración de datos
	
	// Datos de entrada
	
	double distancia;	
	const double LIMITE = 56.89;   // Declaración de una constante
	
	bool condicion;
	
	// Datos de salida
	
	//True (1) o false (0)
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Comparacion entre una distancia y una constante LIMITE" <<endl;
	
	cout <<endl;
	
	cout << "Introduzca una distancia cualquiera: ";
	cin >> distancia;
	
	// Comparación de los datos
	
    condicion = distancia < LIMITE;
	
	// Salida de datos
	
	cout << "La distancia es menor que LIMITE si sale 1 y 0 si es lo contrario:"
	<<endl;
	
	cout << condicion <<endl;
	
	cout <<endl;
	
/******************************************************************************/
/******************************************************************************/		
/******************************************************************************/

	// Quinta expresión lógica

	// Declaración de datos
	
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
	
	// Comparación de los datos
	
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
    
