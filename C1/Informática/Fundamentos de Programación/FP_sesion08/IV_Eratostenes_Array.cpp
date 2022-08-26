/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que calcula los n�meros primos menores que un n�mero entero
   positivo determinado, primero eliminando los m�ltiplos de dos, despues los
   de tres y as� sucesivamente hasta que se llega al n�mero introducido.
   
   Entradas: Un n�mero entero positivo (n).
   
   Salidas: Los n�meros primos menores que el n�mero introducido.
   
   Este programa lo he llevado a cabo de la siguiente forma:
   
   En primer lugar, he establecido un filtrado del n�mero entero a introducir.
   Para ello, he empleado la funci�n LeeEnteroEnRango (que a su vez usa la 
   funci�n LeeEntero), de tal forma que si el n�mero introducido no cumple
   las condiciones impuestas, se vuelve a pedir que se introduzca dicho n�mero.
   Una vez que se ha filtrado el n�mero, he definido un vector tipo bool para la
   determinaci�n de si el n�mero que ocupe la posici�n i (desde 0 hasta n) es
   primo o no. He establecido un ciclo for el cual entrar� en bucle s� y solo 
   s� el �ndice variando es menor o igual que el n�mero introducido. Cada vez
   que esto se cumpla, a la componente i del vector tipo bool se le asocia el
   valor de verdad, de tal forma que, con este proceso, lo que se hace es
   decir que todos los n�meros menores o iguales que n son primos, y a partir 
   de aqu� comienza la criba.
   Para ello, he establecido un ciclo for que se estar� ejecutando s� y solo s�
   el cuadrado del n�mero que se encuentre en la posici�n i sea menor o igual
   que n, y adem�s se seguir� ejecutando otro ciclo for anidado dentro del
   anterior ciclo, en el que, se ir�n eliminando los m�ltiplos de cada n�mero, 
   conforme vaya avanzando el �ndice variando.
   Finalmente, para que muestre todos los n�meros primos calculados, he 
   establecido un ciclo for en el que se va recorriendo todos los n�meros
   menores o iguales que n (y se comienza en el uno; uno se considera primo)
   de tal forma que si se cumple la condici�n de que los n�meros que recorra
   el �ndice son primos (por el vector bool definido), se muestran en pantalla. 
     
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <string>
using namespace std;  
 
/******************************************************************************/
/******************************************************************************/

	/* En primer lugar, definir� una funci�n de tipo bool con el objetivo de
	   determinar si el n�mero introducido es un n�mero entero o no, y la 
	   cual usar� en la funci�n LeeEntero que vendr� a continuaci�n.
	   Esta funci�n me devuelve el valor true si la cadena de caracteres 
	   introducida es un n�mero entero.
	*/
	   
bool EsEntero (string cosa){
	
	/* Declaro una variable contadora de la posici�n de cada uno de los
	   elementos del string; va a ser un �ndice que va recorriendo todos
	   los elementos de la cadena en busca de datos num�ricos.
	*/
	
	int indice = 0;           // La posici�n inicial es cero
	char caracter_sub_indice; // Cualquier elemento de la cadena de caracteres

	
	if(cosa.at(0) == '-'){     /* Si en la posici�n inicial tiene un - eso puede
	                           significar que la cadena sea un n�mero entero
	                           negativo, luego no puede despreciarlo, as� que
	                           el �nidice sigue adelante comprobando el resto
	                           de caracteres de la cadena.
	                           */   
		
		indice = (indice + 1);  // Acutalizo el indice variando
	
	}
	
	/* A continuaci�n establezco un ciclo while, el cual se ejecutar� s� y solo
	   s�, se cumple que el �ndice variando ha alcanzado una posici�n menor 
	   que la posici�n del �ltimo car�cter, en otras palabras, que el �ndice
	   sea menor que la propia lontitud del string.
	   Parte de dicha condici�n viene dada por una variable tipo bool que he
	   definido, y a la cual he asginado el valor true, de tal forma que se 
	   entrar� al menos una vez, pero claro, s� y solo s� se cumple la otra
	   condici�n.
	*/
	
	bool entero_ok = true;
	   
	while(entero_ok && indice < cosa.length()){
		
		 caracter_sub_indice = cosa.at(indice);
		 
		// Actualizo la bandera
		
		/* El caracter, para que sea de car�cter num�rico, ha de ocupar en la
		   p�gina de c�digos ASCII, una posici�n entre la del 0 ('0') y la 
		   del 9 ('9'). Por eso, para que el caracter de la posici�n que indique
		   el �ndice sea un n�mero, ha de cumplir que est� entre 0 y 9. Puede 
		   darse el caso de que entre los caracteres halla espacios. Estos
		   se obvian y se incluyen dentro de la condici�n de que la cadena
		   de caracteres sea un n�mer entero (luego en la siguiente funci�n
		   se emplear� la funci�n stoid que pasa un string a un entero).
		*/   
		
		entero_ok = (caracter_sub_indice >= '0' && caracter_sub_indice <='9')||
					caracter_sub_indice == ' ';
		
		indice = (indice + 1);   // Actualizo el �ndice.
		
	}
	
	return entero_ok; 	
}

int LeeEntero (string titulo){
	
	string numero;   // Cadena a introducir por el usuario
	
	bool cadena_ok;  /* Declaro una variable tipo bool que emplear� en la 
	                    condici�n de el ciclo post-test que he establecido
	                    para la determinaci�n de s� la cadena introducida
	                    es un entero o no.
	                 */   
	
	
	/* En este ciclo do while se comprueba si la cadena constituye un entero.
	   Luego, esta estructura entrar� en bucle s� y solo s� la cadena de 
	   caracteres no es un n�mero entero, y cada vez que esto ocurra se volver�
	   a pedir que introduzca un n�mero entero.
	   Para comprobarlo, hago un llamamiento a la funci�n tipo bool anterior
	   que estaba dirigida a la determinaci�n de s� la cadena constituye un
	   entero o no. De tal forma que se dicha funci�n devuelve el valor true
	   la funci�n LeeEntero, termina de ejecutarse, y se pasa a la siguiente
	   lectura.
	*/
	   
	do{
		
		cout<< titulo;
		cin >> numero;
		
		cadena_ok = EsEntero(numero);
		
	}while(!cadena_ok);
	

 	/* La funci�n devuelve la cadena introducida, convertida en int mediante
 	   la funci�n stoi.
 	*/
	    
	return stoi(numero);
}


/******************************************************************************/

	/* Esta funci�n lee un entero que se encuentre dentro del rango establecido
	   Si no est� dentro o no es un entero, se sigue vuelve a pedir lo mismo.
	   Si se cumplen todas las condiciones se pasa a la siguiente lectura.
	*/
	   
int LeeEnteroEnRango (string titulo, int menor, int mayor)
{
	int numero_entero;
	
	/* He establecido un ciclo do while, en el que se comprueba , en primer 
	   lugar que la cadena de caracteres introducida sea un n�mero entero. 
	   Si esto se cumple, la primera funci�n me devuelve la cadena convertida
	   a entero y se pasa a evaluar si dicho n�mero est� dentro del rango
	   establecido (condici�n del ciclo do-while). Si la cadena de caracteres
	   no fuera un n�mero entero, se vuelve a pedir que se introduzca un n�mero
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

	// Defino el vector que emplear� para cribar
	
	const int MAX_DATOS = 5000;
	
	bool es_primo [MAX_DATOS];

	
/******************************************************************************/
	
	// Entrada de datos
	
		
	n = LeeEnteroEnRango("Introduzca un numero entero positivo: ",1, MAX_DATOS);
		
	
	// C�lculos
	

		for (int i = 0; i <= n; i++){ 
			
			es_primo[i] = true;        // Pongo a todas las componentes del
			                           // vector como verdad y luego paso a
			                           // su criba.
				                              
			
		}
			
		for (int i = 2; i*i <= n; i++){  // El proceso termina cuando el  
		                                 // cuadrado de i es mayor que n
			
			for (int j = 2; j*i <= n; j++){  // Se van cribando los m�ltiplos
				
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
