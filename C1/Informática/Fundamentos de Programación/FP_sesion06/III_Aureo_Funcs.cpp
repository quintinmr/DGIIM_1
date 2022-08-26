/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que calcula el menor valor del orden de un n�mero de la sucesi�n 
   de Fibonacci que hace que la aproximaci�n del n�mero �ureo, dada por 
   an = (termino / termino anterior), tenga un error, respecto del n�mero �ureo 
   de menos de "delta",teniendo en cuenta que n >= 1. 
   Todo esto queda implementado mediante funciones.
   
   Entradas: 
    El valor del error en la aproximaci�n (error; "delta").
    
   Salidas:
    Valor de n (orden).
   
   En este programa he procedido de la siguiente forma:
   En primer lugar, he definido tres funciones relativas a la determinaci�n de 
   los t�rminos de la sucesi�n de Fibonacci, al c�lculo del cociente entre un 
   t�rmino y su anterior, y a la cota de error entre el valor original del 
   n�mero �ureo y dicho cociente (resulta que cuanto mayor es el t�rmino de la 
   sucesi�n de Fibonaccci con el que estemos tratando, el cociente entre �l y 
   su anterior se acerca m�s al N�mero de Oro).
   Dichas funciones las he creado mediante un ciclo for para la primera, y en
   las dem�s he llevado a cabo sentencias sencillas.
   Posteriormente, en el programa  principal, he establecido una estructura 
   repetitiva, de tipo while, en la cual he establecido una estructura 
   condicional doble donde se llama a las funciones creadas (en realidad solo 
   se llama a una en concreto, pero como cada una necesita de la otra, si
   llamo a una, estoy llamando a las dem�s (desde la funci�n main llamo a la
   funci�n que est� justo encima, y esta a su vez a la que est� m�s arriba y
   y as�, hasta que se obtienen los resultados). Dicha estructura condicional
   est� referida a la cota de error establecida por el usuario al principio, la
   cual ha sido filtrada mediante un ciclo post-test, que entrar� en bucle s�
   y solamente s� la cota de error introducida es mayor o igual que 1. De manera
   que, si dicha cota es mayor o igual que el error que existe entre el 
   valor real del n�mero �ureo y el cociente calculado en la funci�n 
   correspondiente entre los t�rminos que me determine la primera funci�n,
   entonces, la condici�n mediante la cual se ha entrado al bucle se cancela
   y se cierra el bucle, pues en ese momento se ha alcanzado justamente la 
   precisi�n que se estaba buscando. Si no es as�, entonces se guarda el error
   comentado anteriormente en una variable de "error previo", y se actualiza 
   el contador del t�rmino de sucesi�n, volviendose al mismo proceso.
                         
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <cmath>        //Inclusi�n de los recursos matem�ticos
#include <iomanip>


using namespace std;  

/******************************************************************************/
/******************************************************************************/

	/* A continuaci�n, defino una serie de funciones: una acerca de los 
	   t�rminos de la sucesi�n de Fibonacci, otra para la funci�n de fibonacci 
	   (t�rmino n+1 entre t�rmino n), y otra para el c�lculo de la diferencia
	   entre el valor real del n�mero �ureo y el valor del cociente calculado
	   en la funci�n anterior.
	*/
	   
	/* Los t�rminos de la sucesi�n de Fibonacci son enteros positivos, as� que 
	  esta funci�n ser� de tipo entero.
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

	/* La siguiente funci�n va destinada al c�lculo del n�mero �ureo utilizando
	   la f�rmula de la sucesi�n de Fibonacci (el cociente de un t�rmino entre
	   su anterior)
	*/
	
double Asubn (int dato)
{
	double result = (TermFibonacci(dato +1) / (double) TermFibonacci(dato));
	   
	return (result);
}

/******************************************************************************/

	/* Esta funci�n va dirigida al c�lculo de la diferencia entre el valor real
	   del n�mero �ureo y el valor obtenido de la funci�n anterior (Asubn)
	   Como saldr� negativa, le pongo valor absoluto.
	*/   

double Error (double dato, double dato2)
{
	double resultado = (abs(Asubn(dato) - dato2));
	
	return (resultado);
}


/******************************************************************************/

int main ()  // Programa principal
{
	// DECLARACI�N DE DATOS
	
	/* El n�mero �ureo se obtiene de la ecuaci�n: phi^2 - phi = 1
	
	                1 + raiz(5)
	  		phi = -------------
	                    2
	*/                   
	const double AUREO = ((1 + sqrt(5.0)) / 2.0);
	
	// Entrada de datos
	
	double error;  // Cota de error para la aproximaci�n
	
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
	
	
	// C�lculos
	
	int termino = 1;
	double error_prev;
	
	bool condicion_bucle = true;
	
	while (condicion_bucle){
		
		/* Una vez dentro de este bucle, al que se entra al menos una vez, por
		   haberle asignado el valor de verdad a la variable tipo bool que 
		   tiene por condici�n este bucle, he establecido una estructura 
		   condicional doble relativa a la cota de error entre el n�mero
		   aureo y el n�mero resultante del cociente entre un t�rmino de la
		   sucesi�n de Fibonacci y el anterior (calculado mediante las funciones
		   creadas anteriormente), de manera que si el error, es decir, la
		   diferencia entre ese numero y el n�mero aureo es menor o igual que 
		   la cota de error introducida por el usuario, entonces se para el 
		   bucle porque ya se ha conseguido la precisi�n que se buscaba.
		   Si no ocurre esto (else), se actualiza el valor del t�rmino de la
		   sucesi�n as� como tambi�n la cota de error anterior.
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
			                                     // actualiz�ndose.
			                                     
			termino = (termino + 1); // Actualizdo la variable t�rmino de la 
			                         // sucesi�n
			                         
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
		     
	
	
	
