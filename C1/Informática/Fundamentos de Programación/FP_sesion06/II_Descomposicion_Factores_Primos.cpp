/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee un n�mero entero positivo y muestra su descomposici�n en
   factores primos. El resultado se muestra de dos formas:
    
   - La primera consiste en enumerar todos los primos de la descomposici�n,
     mostr�ndolos tantas veces como sea preciso.
   - La segunda consiste en expresar el reusltado como producto de potencias
     de n�meros primos.
   	    
   Entradas: 
    Un entero positivo (numero)
    
   Salidas:
    Su descomposici�n en factores primos (descomposici�n).
    
   Este programa lo he llevado a cabo de la siguiente forma:
   En primer lugar, he establecido un filtro para el n�mero, mediante un
   ciclo do-while. Una vez filtrado el n�mero, se procede a descomponer dicho
   n�mero como producto de n�meros primos (apartado a).Para ello, he establecido 
   anidamientos de estructuras c�clicas (de tipo while) y estructuras
   condicionales dobles, de tal forma que, una vez introducido el n�mero, se
   asigna su valor a otro dato el cual se divide tantas veces como sea posible
   entre los sucesivos n�meros primos (2, 3, 5, 7,...), hasta el momento en el
   que el n�mero sea 1. Conforme el n�mero se vaya dividiendo por cada n�mero
   primo, este se mostrar� en pantalla, seguido de un asterisco (producto).
   Para que no se imprimiese un asterisco delante del primer factor primo, he
   definido una variable contadora (cont_asterisco), y he establecido una 
   estructura condicional en la que si se cumple que el contador est� a cero,
   se imprime el primer factor sin el asterisco delante. Una vez que se imprime
   el primer n�mero primo, se actualiza el contador y ya s� se imprime el 
   asterisco seguido del n�mero primo.
   En el apartado b) en lo relativo al producto de potencias de n�meros primos
   se le tendr� que sumar uno al exponente tras las sucesivas divisiones, hasta
   que el n�mero alcance el valor 1. En el caso en el que el exponente que se
   alcance sea cero, es decir, que no se ha podido dividir el n�mer por ning�n 
   n�mero, no se va a imprimir nada (cout << "";).
    
                         
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)

using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// APARTADO A 
	
	// Declaraci�n de datos
	
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

	
	// C�lculos
	
	num_inic = numero;      // Le doy un valor inicial a la variable

	num_primo = 2;          // Inicializo la variable contadora en 2 (porque
	                        // el dos es el primer n�mero primo)
	                      
						                   
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
	
	num_primo = (num_primo + 1);  // Actualizaci�n de la variable contadora
		
	}	

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
	 
	// APARTADO B
	
	// Declaraci�n de datos
	
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
	
	
	
	// C�lculos
	
	power = 0;
	num_inic_bis = numero;
	num_primo_bis = 2;
	
	while (num_inic_bis > 1){
		
		while ((num_inic_bis % num_primo_bis) == 0){
			
			// Actualizo la variable contadora relativa al exponente al 
			// que habr� que elevar cada factor primo, siempre y cuando el
			// n�mero introducido sea divisible por el n�mero primo.
			
			power = (power + 1);
			
			// Se actualiza el n�mero tras haber llevado a cabo el primer
			// cociente.
			
			num_inic_bis = (num_inic_bis / num_primo_bis);
			
		}
		
		/* A continuaci�n, establezco una serie de estructuras condicionales
		dobles para tener en consideranci�n los posibles casos que pueden
		darse en funci�n del exponente.
		*/
		
		if (power == 0){
		
			cout <<"";   // Para el caso en el que el n�mero no se haya dividido
			
		}
			
		else
		{
			
			/* Para que en la descomposici�n del n�mero en productos de
			   potencias de factores primos no aparezca un asterisco al
			   inicio, es necesario establecer la condici�n de que cuando
			   est� el contador que hemos establecido como variable auxiliar
			   est� a cero, simplemente se imprime el primer primo y el
			   exponente al que est� elevado (de ah� tambi�n que estemos dentro
			   del else en el que el exponente no es cero). Una vez que se
			   actualiza el el contador , ya no vale cero, y se pasa al else
			   en el que ya si que se imprime en pantalla el asterisco seguido
			   del n�mero primo elevado al exponente.
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
			
			/* Una vez hecho todo este proceso, para un primer n�mero primo
			   pasamos al siguiente, y para ello, hay que poner el contador
			   del exponente a cero y actualizar, como es obvio, el contador de
			   los n�meros primos.
			*/
			
			power = 0;
			num_primo_bis = (num_primo_bis + 1);   
			
		
	}
	
	
/******************************************************************************/
	return 0;
}
			     
			
			
			
	
	
		
	

	
	
	
	
	
	
	
	
