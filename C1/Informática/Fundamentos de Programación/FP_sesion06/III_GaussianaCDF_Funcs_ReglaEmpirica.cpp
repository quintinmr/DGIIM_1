/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que pide la media, y la desviaci�n t�pica de una funci�n gaussiana,
   calculando todos los valores de x que toma dicha funci�n en el intervalo
   [esperanza - 3*desviacion_tipica , esperanza + 3*desviacion_tipica], y adem�s
   calcula la distribuci�n acumulada (CDF(x)) de dos formas distintas, que 
   ir�n implementadas mediante funciones.
   La primera forma es el c�clulo del �rea bajo la curva mediante la integral
   definida entre menos infinito y x, de la funci�n gaussiana.
   La segunda forma es un m�todo de aproximaci�n de CDF(x), conocida como 
   "mejor aproximaci�n de Hastings", definida por una serie de constantes.
   
   Entradas: 
    Esperanza (esperanza) y desviaci�n t�pica (desviacion_tipica)
    
   Salidas:
    Valores de x que toma la funci�n en el intervalo [esperanza - 
	3*desviacion_tipica , esperanza + 3*desviacion_tipica] (g_de_x)
	La CDF(x) de la primera forma (c�lculo integral) (cdf_de_x_1)
	La CDF(x) de la segunda forma (formula de aproximaci�n) (cdf_de_x_2)
	
   En este programa he procedido de la siguiente forma:
   
   En primer lugar, he difinido una serie de funciones las cuales he usado
   posteriormente en el programa principal, y son las siguientes:
   
   1) La primera funci�n est� destinada al mero c�clulo de potencias (as� evito
   utilizar la funci�n "pow" de <cmath>  y la he llevado a cabo mediante una
   estructura condicional doble relativa a las caracter�sticas del exponente;
   si es negativo o es positivo. Para ambos casos he establecido un ciclo for
   en el que se llevan a cabo los c�clulos pertinentes.
   
   2) La segunda funci�n, la he definido para el c�lculo del valor que toma
   la funci�n gaussiana para una abcisa determinada. Para ello, he transcrito
   directamente la funci�n gaussiana, dividiendola en dos partes, para que 
   la largura de dicha funci�n no estropease la est�tica del programa, 
   sali�ndose del m�rgen establecido.
   
   3) La tercera funci�n est� dirigida al c�lculo de la CDF(x) mediante c�lculo
   integral. En particular, los c�lculos los he llevado a cabo mediante una 
   de suma de Riemann, es decir, la integral bajo la curva se calcula como la
   suma de las �reas de rect�ngulos cuyas bases difieren en un valor muy peque�o 
   (en este caso dicha diferencia es SALTO = 0.25). De esta forma, para poder
   calcular esa suma reiterada de �reas, he establecido un ciclo while, que
   entrar� en bucle siempre y cuando la abcisa a evalar sea menor o igual que
   el extremo superior del intervalo establecido. Al final del bucle se 
   actualiza la variable abcisa, sum�ndole el valor del salto. De esta forma
   una vez que se llega al valor m�ximo, se cierra el bucle y ya tendr�amos el
   valor de la suma de las �reas (CDF(x)).
   
   4) La cuarta funci�n se basa en el c�lculo de la CDF(x) mediante la f�rmula
   de "mejor aproximaci�n de Hastings". B�sicamente consiste en transcribir
   dicha f�rmula, pero teniendo en cuenta el detalle de que hay que estandarizar
   la variable x (recurrir a la normalizaci�n), e incluir en los c�lculos dicha
   normalizaci�n para que la distribuci�n normal sea de la forma N(0,1).
   Finalmente, seg�n el enunciado, si la abcisa es mayor o igual que 0, entonces
   el valor de CDF(X) coincide con el valor que resulta de aplicar la f�rmula.
   Si es lo contrario, el valor de CDF(x) valdr� 1 - el valor obtenido en la
   f�rmula. 
   
   Comentar que en todas estas funciones, se hacen llamamientos a las funciones 
   anteriores en los c�lculos.
   
   Una vez definidas todas estas funciones, se pasa al programa principal
   (funci�n main) en el cual he llevado a cabo una entrada de datos, en la que
   he filtrado mediante un ciclo post-test el valor de la desviaci�n t�pica, 
   pues es el �nico dato que requiere comprobaci�n (ha de ser mayor estricto que
   cero). Una vez filtrado dicho dato, se procede al c�lculo de los valores que
   toma la funci�n en el intervalo [esperanza - 3*desviacion_tipica , 
   esperanza + 3*desviacion_tipica], en funci�n de los datos introducidos por
   el usuario. Para ello he establecido un ciclo while que entrar� en bucle s�
   y solo s� la abcisa es menor o igual que el extremo superior del intervalo.
   Una vez dentro, se calculan dichos valores, utilizando la funci�n creada
   anteriormente mostr�ndose en pantalla, tras su determinaci�n, y una vez hecho
   esto, se actualiza la variable contadora de abcisas, mediante la suma del
   salto correspondiente (0.25). Una vez que se cierra el bucle, se procede
   a calcular el valor de CDF(x) por ambos m�todos, mediante las funciones 
   correspondientes.
                         
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <cmath>      
#include <iomanip>

using namespace std;  

/******************************************************************************/
/******************************************************************************/

	// Funci�n para el c�clulo de una potencia

double Potencia (double base, int exp)
{
	double power = 1.0 ;

		// Para el caso en que el exponente sea positivo
		
		if (exp >= 0){
			
			for (int i = 1; i <= exp; i = i +1){
			
				power = power * base;
				
			}
		}
		
		// Para el caso en que el exponente sea negativo
		
		else{
				
			for (int i = 1; i <= abs(exp); i = i +1){
			
			power = (power / base);
			
			}
		}
	
	return (power);
}


/******************************************************************************/

	// FUNCI�N APARTADO A

	/* Esta funci�n calcula el valor que toma la gaussiana en una valor de
	   abcisa determinado, para una esperanza y desviaci�n t�pica concretas.
	*/

double Gaussiana_de_x (double x, double esperanza, double desviacion_tipica)
{
	
	const double PI    = 3.14159265358979323846;  // Valor que le doy a pi
	
	// C�lculo del valor que toma la funcion en x
	
	double exponente_e = (-0.5)*(Potencia((x-esperanza)/desviacion_tipica,2)); 
    double aux_gauss   = (1 / (desviacion_tipica*sqrt(2*PI)));
		
		
    double gauss_de_x = aux_gauss * exp(exponente_e);
    
    return (gauss_de_x);
    
}

/******************************************************************************/

	// FUNCI�N APARTADO B (para el c�lculo de CDF(x))
	
double Cdf_de_x_B (double esperanza, double desviacion_tipica, double SALTO)
{
	
	// Declaraci�n de datos
	
	double x_inicial   = esperanza - (3 * desviacion_tipica);
	double x_final     = esperanza + (3 * desviacion_tipica);
	double abcisa = x_inicial;
	double cdf_de_x    = 0;
	
	/* Establezco un ciclo while, cuya condici�n de ejecuci�n es que la abcisa
	   sea menor o igual que el extremo superior del intervalo en el que est�
	   contenida.
	*/   
	
	while (abcisa <= x_final){
		
		double area_bajo_curva = (Gaussiana_de_x(abcisa, esperanza,  
		                         desviacion_tipica) * SALTO);
		                         
		// La distribuci�n acumulada, por lo tanto ser�: 
		   	
		cdf_de_x = cdf_de_x + area_bajo_curva;
	
	    // Actualizo el contador de la abcisa (que ir� increment�ndose en 
	    // funci�n de la constante SALTO).
	    
	    abcisa = (abcisa + SALTO);
	}
	
	return (cdf_de_x);
	
}

/******************************************************************************/

	// FUNCION APARTADO C (para el c�clulo de la aproximaci�n de CDF(x))
	
double Cdf_de_x_C (double abcisa, double esperanza, double desviacion_tipica)
{
	// Declaraci�n de constantes, proporcionadas por el problema
	
	const double B0 = 0.2316419;
	const double B1 = 0.319381530;
	const double B2 = -0.356563782;
	const double B3 = 1.781477937;
	const double B4 = -1.821255978;
	const double B5 = 1.330274429;
	
	// C�lculos
	
	double t = (1 / (1 + (B0 * abs(abcisa))));
	
		// Tengo que normalizar la x
	
		double normalizacion = ((abcisa - esperanza) / desviacion_tipica);
		
	double gauss_de_x = Gaussiana_de_x(abs(normalizacion), 0, 1);	
	
	
	double cdf;
	double w = (1 - (gauss_de_x) * ((B1 * t) + (B2 * Potencia(t, 2)) +
	           (B3 * Potencia(t, 3)) + (B4 * Potencia(t, 4)) +
	           (B5 * Potencia(t,5))));
	           
	// Si x >= 0 , cdf = w , si no cdf = 1-w
	
	if (abcisa >= 0){
	
		cdf = w;
		
	}
	
	else
	{
		cdf = (1 - w);
		
	}
	
	return (cdf);
	
}

/******************************************************************************/

int main ()
{
	// DECLARACI�N DE DATOS
	
	double abcisa; // No tengo que leerla porque est� entre valores determinados
	double esperanza;
	double desviacion_tipica;
	
	const double SALTO = 0.25;
	
	Gaussiana g_de_x;
	double cdf_x_1;  // Apartado B
	double cdf_x_2;  // Apartado C
	
/******************************************************************************/
	
	// Entrada de datos


	cout << endl;
	cout << "----------------------------------------------------";
	cout << endl;
	cout << "           GAUSSIANA CDF REGLA EMPIRICA"            ;
	cout << endl;
	cout << "----------------------------------------------------";
	

	cout << endl;
	cout << "Introduzca el valor de la media o esperanza: ";
	cin  >> esperanza;
	
	do{
		
		cout << "Introduzca el valor de la desviacion tipica: ";
		cin  >> desviacion_tipica;
		
	}while (desviacion_tipica <= 0);
	
	
	// C�lculos
	
	/* El valor de la abcisa se encuentra en el intervalo [(esperanza -
	   3*desviacion_tipica), esparanza + 3*desviacion_tipica)]
	   De esta forma, he de considerar las siguientes declaraciones y 
	   agiganciones.
	*/   
	
	double x_inicial   = esperanza - (3 * desviacion_tipica);
	double x_final     = esperanza + (3 * desviacion_tipica);
	abcisa = x_inicial; 
	
	/* Establezco un ciclo while para que me calcule todos los valores que
	   que toma la funci�n gaussiana en el intervalo dado, siendo la diferencia
	   entre los valores de x, el propio SALTO (0.25).
	   La condici�n que ha de cumplir dicho ciclo while es que la abcisa no
	   supere al m�ximo del intervalo, pues como m�nimo es el valor de x_inicial
	   luego, cuando se alcance dicho m�ximo, se cierra el bucle y se procede a
	   llevar a cabo los c�clulos pertinentes de la distribuci�n acumulada,
	   seg�n el apartado b y c.
	*/
	
	
	
	cout << endl;
	cout << "Valores que toma la funci�n en el intervalo: ";
	cout << endl;
	
	while (abcisa <= x_final){
		
		//C�lculos	
		
		g_de_x = Gaussiana_de_x (abcisa, esperanza, desviacion_tipica); 
		
		// Salida de datos (todos los valores de g(x) en el intervalo)
		
		cout << "El valor que toma g(x) en (" << abcisa << ")es:  " << g_de_x;
		cout << endl;
		
		// Se actualiza la x, sum�ndolel el salto correspondiente (0.25)
		
		abcisa = (abcisa + SALTO);
		
	}
	
	// C�lculo de las distribuciones acumuladas para el apartado b y c
	
		// APARTADO B (c�lculo de CDF(x))
		
		cdf_x_1 = Cdf_de_x_B (esperanza, desviacion_tipica, SALTO);
		                      
		// APARTADO C (c�lculo de la aproximaci�n de CDF(x))
		
		cdf_x_2 = Cdf_de_x_C (abcisa, esperanza, desviacion_tipica);
							                       
	
	// Salida de datos
	
		// APARTADO B
	
		cout << endl;
		cout << "La distribucion acumulada CDF("<<abcisa<<") es: " << cdf_x_1;
		cout << endl;
		
		// APARTADO C
		
		cout << endl;
		cout << "El valor aproximado de CDF("<<abcisa<<") es: " << cdf_x_2;
		cout << endl;
		
/******************************************************************************/
	return 0;
}
		
