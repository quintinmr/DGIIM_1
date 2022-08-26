/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa en el que se definen una serie de funciones para la lectura de
   enteros:
   	 -La primera funci�n lee y devuelve un dato int. Si el dato no fuera de tipo
   	 int (sea el caso de 2.4 xAW, o ,----A-, etc.), la funci�n volver� a pedirlo
   	 hasta que se introduzca un valor correcto.
	   
	 -La segunda funci�n lee y devuelve un dato int en un rango dado. Si el 
	  valor leido no fuera int o fuera menor o mayor que el m�nimo y el m�ximo
	  del rango (que he declarado como constantes), respectivamente, la funci�n 
	  volver�a a pedirlo hasta que se proporcionara un valor correcto.
	 
	 -La tercera y �ltima funci�n lee y devuelve un dato int que debe ser 
	  mayor o igual que una referencia que he declarado como constante.
	  Si el valor leido no fuera int � �ste fuera menor que la referencia la 
	  funci�n volver�a a pedirlo hasta que se proporcionara un valor correcto.
	   
   Entradas: 
    Una cadena de caracteres.
     
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

	
	if(cosa[0] == '-'){     /* Si en la posici�n inicial tiene un - eso puede
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
		
		 caracter_sub_indice = cosa[indice];
		 
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

	/* Esta funci�n determina si un n�mero entero es mayor o igual que una
	   referencia establecida.
	*/
	   
int LeeEnteroMayorOIgual (string titulo, int referencia)
{
	int numero_entero; 
	
	/* He establecido un ciclo do-while que entrar� en bucle s� y solo s�
	   se cumple que la cadena de caracteres no es un entero. El cuerpo del
	   bucle se eval�a mediante una llamada a la funci�n LeeEntero, que se
	   encargar� de comprobar si la cadena de caracteres introducida es o no
	   un n�mero entero. Si lo es, se pasa a evaluar la condici�n del ciclo, 
	   que es que sea menor que la referencia. Si dicha condici�n se
	   cumple, se vuelve a ejecutar el bucle. Si no se cumple, querr� decir
	   que el n�mero es mayor o igual que la referencia, y finaliza directamente
	   el programa.
	   En cualquier caso, se vuelve a pedir que introduzca un n�mero entero
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
