/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee dos números enteros: "mínimo" y "máximo" determinando así,
   un intervalo [mínimo , máximo], un valor entero asignado a un desplazamiento,
   que será entre 0 y máximo-mínimo, y un valor entero (a_desplazar),el cual
   se sumara al desplazamiento introducido anteriormente, dando un entero
   dentro del intervalo.
   
   Entradas:  
    Valor entero del mínimo (minimo) y el máximo (maximo) del intervalo, un 
	valor entero de desplazamiento (desplazamiento) y el valor entero que se va
	a desplazar (a_desplazamiento).
	
   Salidas:
    Número entero dentro del intervalo desplazado un numero entero de posiciones
	(numero_desplazado).                          
*/               
/******************************************************************************/

#include <iostream>      //Inclusión de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{

	// DECLARACIÓN DE DATOS
	
	// Datos de entrada
	
	int minimo;
	int maximo;
	int desplazamiento;
	int a_desplazar;
	
	int aplicado;  //Declaro este dato para que los cáclulos estén mas reducidos
	
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
	
    // Cálculos
    
    aplicado = a_desplazar+desplazamiento;
    
    numero_desplazado = (((aplicado-minimo))%(maximo+1-minimo))+minimo;
	
	/* Tras varias consideraciones, dado que el usuario puede introducir un 
	un número a desplazar tal que al aplicarle el desplazamiento se salga del
	intervalo dado, o que el desplazamiento sea tan grande que haga que el 
	número salga fuera del intervalo, es necesario hacer una serie de 
	modificaciones intencionadas en los cálculos para que todo case 
	correctamente, como son las que se pueden apreciar mas arriba; el resto del
	cociente entre la diferencia del número (una vez aplicado el desplazamiento)
	y el valor mínimo del intervalo, y la diferencia entre los extremos del
	intervalo agrandado una unidad (para empezar a contar luego a partir del
	mínimo), indica la posicion que ocupa el número a desplazar, a partir del
	mínimo (por eso se le suma el resto del cociente al minimo del intervalo).*/
    
    // Salida de datos
    
    cout <<endl;
    cout << "El numero inicial se ha transformado en el: "<<numero_desplazado<<
    endl;
    cout<<endl;
    
/******************************************************************************/
	return 0;
}
	   
    
    
