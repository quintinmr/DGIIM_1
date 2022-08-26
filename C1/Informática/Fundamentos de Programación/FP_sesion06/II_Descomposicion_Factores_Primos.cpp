/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee un número entero positivo y muestra su descomposición en
   factores primos. El resultado se muestra de dos formas:
    
   - La primera consiste en enumerar todos los primos de la descomposición,
     mostrándolos tantas veces como sea preciso.
   - La segunda consiste en expresar el reusltado como producto de potencias
     de números primos.
   	    
   Entradas: 
    Un entero positivo (numero)
    
   Salidas:
    Su descomposición en factores primos (descomposición).
    
   Este programa lo he llevado a cabo de la siguiente forma:
   En primer lugar, he establecido un filtro para el número, mediante un
   ciclo do-while. Una vez filtrado el número, se procede a descomponer dicho
   número como producto de números primos (apartado a).Para ello, he establecido 
   anidamientos de estructuras cíclicas (de tipo while) y estructuras
   condicionales dobles, de tal forma que, una vez introducido el número, se
   asigna su valor a otro dato el cual se divide tantas veces como sea posible
   entre los sucesivos números primos (2, 3, 5, 7,...), hasta el momento en el
   que el número sea 1. Conforme el número se vaya dividiendo por cada número
   primo, este se mostrará en pantalla, seguido de un asterisco (producto).
   Para que no se imprimiese un asterisco delante del primer factor primo, he
   definido una variable contadora (cont_asterisco), y he establecido una 
   estructura condicional en la que si se cumple que el contador está a cero,
   se imprime el primer factor sin el asterisco delante. Una vez que se imprime
   el primer número primo, se actualiza el contador y ya sí se imprime el 
   asterisco seguido del número primo.
   En el apartado b) en lo relativo al producto de potencias de números primos
   se le tendrá que sumar uno al exponente tras las sucesivas divisiones, hasta
   que el número alcance el valor 1. En el caso en el que el exponente que se
   alcance sea cero, es decir, que no se ha podido dividir el númer por ningún 
   número, no se va a imprimir nada (cout << "";).
    
                         
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)

using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// APARTADO A 
	
	// Declaración de datos
	
	// Datos de entrada
	
	int numero;
	int num_inic;
	int cont_asterisco = 0;   // Establezco una variable contadora relativa
	                          // a los asteriscos con el fin de que el primer
							  // factor primo no aparezca con un * delante.   
	int num_primo;
	
/******************************************************************************/

	// Entrada de datos	
	
	do{
		
   		cout << "Introduzca un numero entero positivo: ";
		cin  >> numero;
		cout << endl;
	
	}while (numero <= 1);   // El 1 no puede descomponerse en factores primos
	
	cout << "---------------------------------";
	cout << endl;
	cout << " PRIMERA FORMA DE DESCOMPOSICION";
	cout << endl;
	cout << "---------------------------------";
	cout << endl;

	
	// Cálculos
	
	num_inic = numero;      // Le doy un valor inicial a la variable

	num_primo = 2;          // Inicializo la variable contadora en 2 (porque
	                        // el dos es el primer número primo)
	                      
						                   
	while (num_inic > 1){
		
		while ((num_inic % num_primo) == 0){
				
			if (cont_asterisco == 0){
					
				cout << numero << " = ";
				cout << num_primo;
			}
				
			else
			{
		        cout << " * "<< num_primo  ;
					
			}
				
		num_inic = (num_inic / num_primo);
				
		cont_asterisco = (cont_asterisco + 1);         // Acutalizo esta 
				                                       // variable contadora
					 
			}
	
	num_primo = (num_primo + 1);  // Actualización de la variable contadora
		
	}	

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
	 
	// APARTADO B
	
	// Declaración de datos
	
	int power;
	int num_inic_bis;
	int num_primo_bis;
	int cont_asterisco_bis = 0;
	
/******************************************************************************/	
	
	cout << endl;
	cout << "---------------------------------";
	cout << endl;
	cout << " SEGUNDA FORMA DE DESCOMPOSICION";
	cout << endl;
	cout << "---------------------------------";
	cout << endl;
	
	
	
	// Cálculos
	
	power = 0;
	num_inic_bis = numero;
	num_primo_bis = 2;
	
	while (num_inic_bis > 1){
		
		while ((num_inic_bis % num_primo_bis) == 0){
			
			// Actualizo la variable contadora relativa al exponente al 
			// que habrá que elevar cada factor primo, siempre y cuando el
			// número introducido sea divisible por el número primo.
			
			power = (power + 1);
			
			// Se actualiza el número tras haber llevado a cabo el primer
			// cociente.
			
			num_inic_bis = (num_inic_bis / num_primo_bis);
			
		}
		
		/* A continuación, establezco una serie de estructuras condicionales
		dobles para tener en consideranción los posibles casos que pueden
		darse en función del exponente.
		*/
		
		if (power == 0){
		
			cout <<"";   // Para el caso en el que el número no se haya dividido
			
		}
			
		else
		{
			
			/* Para que en la descomposición del número en productos de
			   potencias de factores primos no aparezca un asterisco al
			   inicio, es necesario establecer la condición de que cuando
			   está el contador que hemos establecido como variable auxiliar
			   está a cero, simplemente se imprime el primer primo y el
			   exponente al que está elevado (de ahí también que estemos dentro
			   del else en el que el exponente no es cero). Una vez que se
			   actualiza el el contador , ya no vale cero, y se pasa al else
			   en el que ya si que se imprime en pantalla el asterisco seguido
			   del número primo elevado al exponente.
			*/
			   
			if (cont_asterisco_bis == 0){
				
				cout << numero << " = ";
				cout << num_primo_bis << "^" << power;
				cont_asterisco_bis = (cont_asterisco_bis + 1);
				
			}
			
			else
			{
				cout << " * " << num_primo_bis << "^" << power;
				
			}
			
		}
			
			/* Una vez hecho todo este proceso, para un primer número primo
			   pasamos al siguiente, y para ello, hay que poner el contador
			   del exponente a cero y actualizar, como es obvio, el contador de
			   los números primos.
			*/
			
			power = 0;
			num_primo_bis = (num_primo_bis + 1);   
			
		
	}
	
	
/******************************************************************************/
	return 0;
}
			     
			
			
			
	
	
		
	

	
	
	
	
	
	
	
	
