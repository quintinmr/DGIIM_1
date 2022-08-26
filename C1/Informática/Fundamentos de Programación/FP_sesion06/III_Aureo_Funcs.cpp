/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que calcula el menor valor del orden de un número de la sucesión 
   de Fibonacci que hace que la aproximación del número áureo, dada por 
   an = (termino / termino anterior), tenga un error, respecto del número áureo 
   de menos de "delta",teniendo en cuenta que n >= 1. 
   Todo esto queda implementado mediante funciones.
   
   Entradas: 
    El valor del error en la aproximación (error; "delta").
    
   Salidas:
    Valor de n (orden).
   
   En este programa he procedido de la siguiente forma:
   En primer lugar, he definido tres funciones relativas a la determinación de 
   los términos de la sucesión de Fibonacci, al cálculo del cociente entre un 
   término y su anterior, y a la cota de error entre el valor original del 
   número áureo y dicho cociente (resulta que cuanto mayor es el término de la 
   sucesión de Fibonaccci con el que estemos tratando, el cociente entre él y 
   su anterior se acerca más al Número de Oro).
   Dichas funciones las he creado mediante un ciclo for para la primera, y en
   las demás he llevado a cabo sentencias sencillas.
   Posteriormente, en el programa  principal, he establecido una estructura 
   repetitiva, de tipo while, en la cual he establecido una estructura 
   condicional doble donde se llama a las funciones creadas (en realidad solo 
   se llama a una en concreto, pero como cada una necesita de la otra, si
   llamo a una, estoy llamando a las demás (desde la función main llamo a la
   función que está justo encima, y esta a su vez a la que está más arriba y
   y así, hasta que se obtienen los resultados). Dicha estructura condicional
   está referida a la cota de error establecida por el usuario al principio, la
   cual ha sido filtrada mediante un ciclo post-test, que entrará en bucle sí
   y solamente sí la cota de error introducida es mayor o igual que 1. De manera
   que, si dicha cota es mayor o igual que el error que existe entre el 
   valor real del número áureo y el cociente calculado en la función 
   correspondiente entre los términos que me determine la primera función,
   entonces, la condición mediante la cual se ha entrado al bucle se cancela
   y se cierra el bucle, pues en ese momento se ha alcanzado justamente la 
   precisión que se estaba buscando. Si no es así, entonces se guarda el error
   comentado anteriormente en una variable de "error previo", y se actualiza 
   el contador del término de sucesión, volviendose al mismo proceso.
                         
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <cmath>        //Inclusión de los recursos matemáticos
#include <iomanip>


using namespace std;  

/******************************************************************************/
/******************************************************************************/

	/* A continuación, defino una serie de funciones: una acerca de los 
	   términos de la sucesión de Fibonacci, otra para la función de fibonacci 
	   (término n+1 entre término n), y otra para el cálculo de la diferencia
	   entre el valor real del número áureo y el valor del cociente calculado
	   en la función anterior.
	*/
	   
	/* Los términos de la sucesión de Fibonacci son enteros positivos, así que 
	  esta función será de tipo entero.
	*/  
	 
int TermFibonacci(int dato){
	
	int fibonacci_n;
	int fibonacci_n_prev;
	int fibonacci_final;
	
	fibonacci_n_prev = 1;
	fibonacci_n = 1;
	
	for (int i = 2; i <= dato; i++){
		
		fibonacci_final = fibonacci_n + fibonacci_n_prev;
		
		fibonacci_n_prev = fibonacci_n;
		fibonacci_n = fibonacci_final;
	}
	
	return (fibonacci_n_prev);
}

/******************************************************************************/

	/* La siguiente función va destinada al cálculo del número áureo utilizando
	   la fórmula de la sucesión de Fibonacci (el cociente de un término entre
	   su anterior)
	*/
	
double Asubn (int dato)
{
	double result = (TermFibonacci(dato +1) / (double) TermFibonacci(dato));
	   
	return (result);
}

/******************************************************************************/

	/* Esta función va dirigida al cálculo de la diferencia entre el valor real
	   del número áureo y el valor obtenido de la función anterior (Asubn)
	   Como saldrá negativa, le pongo valor absoluto.
	*/   

double Error (double dato, double dato2)
{
	double resultado = (abs(Asubn(dato) - dato2));
	
	return (resultado);
}


/******************************************************************************/

int main ()  // Programa principal
{
	// DECLARACIÓN DE DATOS
	
	/* El número áureo se obtiene de la ecuación: phi^2 - phi = 1
	
	                1 + raiz(5)
	  		phi = -------------
	                    2
	*/                   
	const double AUREO = ((1 + sqrt(5.0)) / 2.0);
	
	// Entrada de datos
	
	double error;  // Cota de error para la aproximación
	
	cout << endl;
	cout << "------------------------------";
	cout << "APROXIMACION DEL NUMERO AUERO";
	cout << "------------------------------";
	cout << endl;
	cout << endl;
	
	do{
		
		cout << "Introduca la cota de error con la que quiere aproximar el" 
		     << " numero aureo ( "<< setw(14) << setprecision (15) << AUREO 
			 << " ) : ";     
		cin  >> error;
		cout << endl;
		
	}while (error >= 1);
	
	
	// Cálculos
	
	int termino = 1;
	double error_prev;
	
	bool condicion_bucle = true;
	
	while (condicion_bucle){
		
		/* Una vez dentro de este bucle, al que se entra al menos una vez, por
		   haberle asignado el valor de verdad a la variable tipo bool que 
		   tiene por condición este bucle, he establecido una estructura 
		   condicional doble relativa a la cota de error entre el número
		   aureo y el número resultante del cociente entre un término de la
		   sucesión de Fibonacci y el anterior (calculado mediante las funciones
		   creadas anteriormente), de manera que si el error, es decir, la
		   diferencia entre ese numero y el número aureo es menor o igual que 
		   la cota de error introducida por el usuario, entonces se para el 
		   bucle porque ya se ha conseguido la precisión que se buscaba.
		   Si no ocurre esto (else), se actualiza el valor del término de la
		   sucesión así como también la cota de error anterior.
		*/
		
		if (Error(termino, AUREO) <= error){
		
			condicion_bucle = false;  // (al asignarle el valor false se cierra 
			                          // el bucle)   	
	
		}
		
		else
		{
			error_prev = Error(termino, AUREO);  // Asigno el valor del error
			                                     // inicial, a una variable
			                                     // en la que se guarda el error
			                                     // como anterior, 
			                                     // actualizándose.
			                                     
			termino = (termino + 1); // Actualizdo la variable término de la 
			                         // sucesión
			                         
		}
			
	} // Fin del bucle 
	
	
	// Salida de datos
	
	cout << endl;
	cout << "El numero aureo aproximado es: " <<setw(14)<<setprecision(15)
	     << Asubn(termino);
	cout << endl;
	cout << "El menor valor del orden de n en la sucesion, para el cual la "
	     << "aproximacion es esta, es: " << termino;
	cout << endl;
	cout << "El error que se comete es: " << Error(termino, AUREO);
	cout <<endl;
	cout << "Frente al error que se comete si se toma el termino anterior: "
	     << error_prev << ". Por eso se toma el siguiente, porque ha de ser"
		 << " menor que la cota de error establecida: " <<error;
	cout << endl;     
	
/******************************************************************************/
	return 0;
}
		     
	
	
	
