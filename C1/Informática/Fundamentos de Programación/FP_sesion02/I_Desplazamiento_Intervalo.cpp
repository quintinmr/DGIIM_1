/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee dos n�meros enteros: "m�nimo" y "m�ximo" determinando as�,
   un intervalo [m�nimo , m�ximo], un valor entero asignado a un desplazamiento,
   que ser� entre 0 y m�ximo-m�nimo, y un valor entero (a_desplazar),el cual
   se sumara al desplazamiento introducido anteriormente, dando un entero
   dentro del intervalo.
   
   Entradas:  
    Valor entero del m�nimo (minimo) y el m�ximo (maximo) del intervalo, un 
	valor entero de desplazamiento (desplazamiento) y el valor entero que se va
	a desplazar (a_desplazamiento).
	
   Salidas:
    N�mero entero dentro del intervalo desplazado un numero entero de posiciones
	(numero_desplazado).                          
*/               
/******************************************************************************/

#include <iostream>      //Inclusi�n de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{

	// DECLARACI�N DE DATOS
	
	// Datos de entrada
	
	int minimo;
	int maximo;
	int desplazamiento;
	int a_desplazar;
	
	int aplicado;  //Declaro este dato para que los c�clulos est�n mas reducidos
	
	// Dato de salida
	
	int numero_desplazado;
	
/******************************************************************************/

	// Entrada de datos
    
    cout << "Introduzca el valor entero minimo del intervalo: ";
    cin >> minimo;
    
    cout << "Introduzca el valor entero maximo del intervalo: ";
    cin >> maximo;
    
    cout << "Introduzca el numero de posiciones que desea desplazar el numero: "
    ;
	cin >> desplazamiento;
	
	cout << "Introduzca el numero que desea desplazar dentro del intervalo: ";
	cin >> a_desplazar;
	
    // C�lculos
    
    aplicado = a_desplazar+desplazamiento;
    
    numero_desplazado = (((aplicado-minimo))%(maximo+1-minimo))+minimo;
	
	/* Tras varias consideraciones, dado que el usuario puede introducir un 
	un n�mero a desplazar tal que al aplicarle el desplazamiento se salga del
	intervalo dado, o que el desplazamiento sea tan grande que haga que el 
	n�mero salga fuera del intervalo, es necesario hacer una serie de 
	modificaciones intencionadas en los c�lculos para que todo case 
	correctamente, como son las que se pueden apreciar mas arriba; el resto del
	cociente entre la diferencia del n�mero (una vez aplicado el desplazamiento)
	y el valor m�nimo del intervalo, y la diferencia entre los extremos del
	intervalo agrandado una unidad (para empezar a contar luego a partir del
	m�nimo), indica la posicion que ocupa el n�mero a desplazar, a partir del
	m�nimo (por eso se le suma el resto del cociente al minimo del intervalo).*/
    
    // Salida de datos
    
    cout <<endl;
    cout << "El numero inicial se ha transformado en el: "<<numero_desplazado<<
    endl;
    cout<<endl;
    
/******************************************************************************/
	return 0;
}
	   
    
    
