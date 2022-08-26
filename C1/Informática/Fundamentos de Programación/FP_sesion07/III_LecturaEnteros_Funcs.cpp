/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa en el que se definen una serie de funciones para la lectura de
   enteros:
   	 -La primera función lee y devuelve un dato int. Si el dato no fuera de tipo
   	 int (sea el caso de 2.4 xAW, o ,----A-, etc.), la función volverá a pedirlo
   	 hasta que se introduzca un valor correcto.
	   
	 -La segunda función lee y devuelve un dato int en un rango dado. Si el 
	  valor leido no fuera int o fuera menor o mayor que el mínimo y el máximo
	  del rango (que he declarado como constantes), respectivamente, la función 
	  volvería a pedirlo hasta que se proporcionara un valor correcto.
	 
	 -La tercera y última función lee y devuelve un dato int que debe ser 
	  mayor o igual que una referencia que he declarado como constante.
	  Si el valor leido no fuera int ó éste fuera menor que la referencia la 
	  función volvería a pedirlo hasta que se proporcionara un valor correcto.
	   
   Entradas: 
    Una cadena de caracteres.
     
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <string>
using namespace std;  
 
/******************************************************************************/
/******************************************************************************/

	/* En primer lugar, definiré una función de tipo bool con el objetivo de
	   determinar si el número introducido es un número entero o no, y la 
	   cual usaré en la función LeeEntero que vendrá a continuación.
	   Esta función me devuelve el valor true si la cadena de caracteres 
	   introducida es un número entero.
	*/
	   
bool EsEntero (string cosa){
	
	/* Declaro una variable contadora de la posición de cada uno de los
	   elementos del string; va a ser un índice que va recorriendo todos
	   los elementos de la cadena en busca de datos numéricos.
	*/
	
	int indice = 0;           // La posición inicial es cero
	char caracter_sub_indice; // Cualquier elemento de la cadena de caracteres

	
	if(cosa[0] == '-'){     /* Si en la posición inicial tiene un - eso puede
	                           significar que la cadena sea un número entero
	                           negativo, luego no puede despreciarlo, así que
	                           el ínidice sigue adelante comprobando el resto
	                           de caracteres de la cadena.
	                        */   
		
		indice = (indice + 1);  // Acutalizo el indice variando
	
	}
	
	/* A continuación establezco un ciclo while, el cual se ejecutará sí y solo
	   sí, se cumple que el índice variando ha alcanzado una posición menor 
	   que la posición del último carácter, en otras palabras, que el índice
	   sea menor que la propia lontitud del string.
	   Parte de dicha condición viene dada por una variable tipo bool que he
	   definido, y a la cual he asginado el valor true, de tal forma que se 
	   entrará al menos una vez, pero claro, sí y solo sí se cumple la otra
	   condición.
	*/
	
	bool entero_ok = true;
	   
	while(entero_ok && indice < cosa.length()){
		
		 caracter_sub_indice = cosa[indice];
		 
		// Actualizo la bandera
		
		/* El caracter, para que sea de carácter numérico, ha de ocupar en la
		   página de códigos ASCII, una posición entre la del 0 ('0') y la 
		   del 9 ('9'). Por eso, para que el caracter de la posición que indique
		   el índice sea un número, ha de cumplir que esté entre 0 y 9. Puede 
		   darse el caso de que entre los caracteres halla espacios. Estos
		   se obvian y se incluyen dentro de la condición de que la cadena
		   de caracteres sea un númer entero (luego en la siguiente función
		   se empleará la función stoid que pasa un string a un entero).
		*/   
		
		entero_ok = (caracter_sub_indice >= '0' && caracter_sub_indice <='9')||
					caracter_sub_indice == ' ';
		
		indice = (indice + 1);   // Actualizo el índice.
		
	}
	
	return entero_ok; 	
}

int LeeEntero (string titulo){
	
	string numero;   // Cadena a introducir por el usuario
	
	bool cadena_ok;  /* Declaro una variable tipo bool que emplearé en la 
	                    condición de el ciclo post-test que he establecido
	                    para la determinación de sí la cadena introducida
	                    es un entero o no.
	                 */   
	
	
	/* En este ciclo do while se comprueba si la cadena constituye un entero.
	   Luego, esta estructura entrará en bucle sí y solo sí la cadena de 
	   caracteres no es un número entero, y cada vez que esto ocurra se volverá
	   a pedir que introduzca un número entero.
	   Para comprobarlo, hago un llamamiento a la función tipo bool anterior
	   que estaba dirigida a la determinación de sí la cadena constituye un
	   entero o no. De tal forma que se dicha función devuelve el valor true
	   la función LeeEntero, termina de ejecutarse, y se pasa a la siguiente
	   lectura.
	*/
	   
	do{
		
		cout<< titulo;
		cin >> numero;
		
		cadena_ok = EsEntero(numero);
		
	}while(!cadena_ok);
	

 	/* La función devuelve la cadena introducida, convertida en int mediante
 	   la función stoi.
 	*/
	    
	return stoi(numero);
}


/******************************************************************************/

	/* Esta función lee un entero que se encuentre dentro del rango establecido
	   Si no está dentro o no es un entero, se sigue vuelve a pedir lo mismo.
	   Si se cumplen todas las condiciones se pasa a la siguiente lectura.
	*/
	   
int LeeEnteroEnRango (string titulo, int menor, int mayor)
{
	int numero_entero;
	
	/* He establecido un ciclo do while, en el que se comprueba , en primer 
	   lugar que la cadena de caracteres introducida sea un número entero. 
	   Si esto se cumple, la primera función me devuelve la cadena convertida
	   a entero y se pasa a evaluar si dicho número está dentro del rango
	   establecido (condición del ciclo do-while). Si la cadena de caracteres
	   no fuera un número entero, se vuelve a pedir que se introduzca un número
	   entero.
	*/   
	 
	do {
		
		numero_entero = LeeEntero(titulo);	
		
	} while (numero_entero < menor || numero_entero > mayor);
	
	
	return numero_entero;	
}

/******************************************************************************/

	/* Esta función determina si un número entero es mayor o igual que una
	   referencia establecida.
	*/
	   
int LeeEnteroMayorOIgual (string titulo, int referencia)
{
	int numero_entero; 
	
	/* He establecido un ciclo do-while que entrará en bucle sí y solo sí
	   se cumple que la cadena de caracteres no es un entero. El cuerpo del
	   bucle se evalúa mediante una llamada a la función LeeEntero, que se
	   encargará de comprobar si la cadena de caracteres introducida es o no
	   un número entero. Si lo es, se pasa a evaluar la condición del ciclo, 
	   que es que sea menor que la referencia. Si dicha condición se
	   cumple, se vuelve a ejecutar el bucle. Si no se cumple, querrá decir
	   que el número es mayor o igual que la referencia, y finaliza directamente
	   el programa.
	   En cualquier caso, se vuelve a pedir que introduzca un número entero
	   cada vez que la cadena de caracteres no lo sea.
	*/    
	
	do {
		
		numero_entero = LeeEntero(titulo);	
			
	} while (numero_entero < referencia);
	
	
	return numero_entero;	
}

/******************************************************************************/
/******************************************************************************/

int main()
{
	
	//Declaracion de constantes
	
	const int MIN = 0;
	const int MAX = 100;
	const int REFERENCIA = 7;
	
	// Entrada de datos
	
	LeeEntero ("Introduzca un numero entero: ");
	
	cout << endl;
	
	LeeEnteroEnRango ("Introduzca un numero entero que se encuente en [0,100]: "
	                  , MIN, MAX);
	                  
	cout << endl;                  
	                  
	LeeEnteroMayorOIgual ("Introduzca un numero entero mayor o igual que 7: ",
	                     REFERENCIA);
	                     
	                     
/******************************************************************************/	                     
	return 0;
}
