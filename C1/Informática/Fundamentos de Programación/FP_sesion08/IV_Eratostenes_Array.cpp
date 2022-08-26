/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que calcula los números primos menores que un número entero
   positivo determinado, primero eliminando los múltiplos de dos, despues los
   de tres y así sucesivamente hasta que se llega al número introducido.
   
   Entradas: Un número entero positivo (n).
   
   Salidas: Los números primos menores que el número introducido.
   
   Este programa lo he llevado a cabo de la siguiente forma:
   
   En primer lugar, he establecido un filtrado del número entero a introducir.
   Para ello, he empleado la función LeeEnteroEnRango (que a su vez usa la 
   función LeeEntero), de tal forma que si el número introducido no cumple
   las condiciones impuestas, se vuelve a pedir que se introduzca dicho número.
   Una vez que se ha filtrado el número, he definido un vector tipo bool para la
   determinación de si el número que ocupe la posición i (desde 0 hasta n) es
   primo o no. He establecido un ciclo for el cual entrará en bucle sí y solo 
   sí el índice variando es menor o igual que el número introducido. Cada vez
   que esto se cumpla, a la componente i del vector tipo bool se le asocia el
   valor de verdad, de tal forma que, con este proceso, lo que se hace es
   decir que todos los números menores o iguales que n son primos, y a partir 
   de aquí comienza la criba.
   Para ello, he establecido un ciclo for que se estará ejecutando sí y solo sí
   el cuadrado del número que se encuentre en la posición i sea menor o igual
   que n, y además se seguirá ejecutando otro ciclo for anidado dentro del
   anterior ciclo, en el que, se irán eliminando los múltiplos de cada número, 
   conforme vaya avanzando el índice variando.
   Finalmente, para que muestre todos los números primos calculados, he 
   establecido un ciclo for en el que se va recorriendo todos los números
   menores o iguales que n (y se comienza en el uno; uno se considera primo)
   de tal forma que si se cumple la condición de que los números que recorra
   el índice son primos (por el vector bool definido), se muestran en pantalla. 
     
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

	
	if(cosa.at(0) == '-'){     /* Si en la posición inicial tiene un - eso puede
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
		
		 caracter_sub_indice = cosa.at(indice);
		 
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
/******************************************************************************/

int main()
{
	
	int n;

	// Defino el vector que emplearé para cribar
	
	const int MAX_DATOS = 5000;
	
	bool es_primo [MAX_DATOS];

	
/******************************************************************************/
	
	// Entrada de datos
	
		
	n = LeeEnteroEnRango("Introduzca un numero entero positivo: ",1, MAX_DATOS);
		
	
	// Cálculos
	

		for (int i = 0; i <= n; i++){ 
			
			es_primo[i] = true;        // Pongo a todas las componentes del
			                           // vector como verdad y luego paso a
			                           // su criba.
				                              
			
		}
			
		for (int i = 2; i*i <= n; i++){  // El proceso termina cuando el  
		                                 // cuadrado de i es mayor que n
			
			for (int j = 2; j*i <= n; j++){  // Se van cribando los múltiplos
				
				es_primo[i*j] = false ;
					
			}
			
		}
	
    	
    cout << "Los numeros primos menores que " << n << " son: ";
    
    for (int i = 1; i <= n; i++){
    
		if (es_primo[i]){ 
        
			cout << endl;
			cout <<"  "<< i;
		
			
		}
		
		else
		{
			cout << "";
			
		}
				
	}
	
/******************************************************************************/
	return 0;
}
