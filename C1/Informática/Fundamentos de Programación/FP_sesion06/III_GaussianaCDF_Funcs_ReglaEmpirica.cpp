/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que pide la media, y la desviación típica de una función gaussiana,
   calculando todos los valores de x que toma dicha función en el intervalo
   [esperanza - 3*desviacion_tipica , esperanza + 3*desviacion_tipica], y además
   calcula la distribución acumulada (CDF(x)) de dos formas distintas, que 
   irán implementadas mediante funciones.
   La primera forma es el cáclulo del área bajo la curva mediante la integral
   definida entre menos infinito y x, de la función gaussiana.
   La segunda forma es un método de aproximación de CDF(x), conocida como 
   "mejor aproximación de Hastings", definida por una serie de constantes.
   
   Entradas: 
    Esperanza (esperanza) y desviación típica (desviacion_tipica)
    
   Salidas:
    Valores de x que toma la función en el intervalo [esperanza - 
	3*desviacion_tipica , esperanza + 3*desviacion_tipica] (g_de_x)
	La CDF(x) de la primera forma (cálculo integral) (cdf_de_x_1)
	La CDF(x) de la segunda forma (formula de aproximación) (cdf_de_x_2)
	
   En este programa he procedido de la siguiente forma:
   
   En primer lugar, he difinido una serie de funciones las cuales he usado
   posteriormente en el programa principal, y son las siguientes:
   
   1) La primera función está destinada al mero cáclulo de potencias (así evito
   utilizar la función "pow" de <cmath>  y la he llevado a cabo mediante una
   estructura condicional doble relativa a las características del exponente;
   si es negativo o es positivo. Para ambos casos he establecido un ciclo for
   en el que se llevan a cabo los cáclulos pertinentes.
   
   2) La segunda función, la he definido para el cálculo del valor que toma
   la función gaussiana para una abcisa determinada. Para ello, he transcrito
   directamente la función gaussiana, dividiendola en dos partes, para que 
   la largura de dicha función no estropease la estética del programa, 
   saliéndose del márgen establecido.
   
   3) La tercera función está dirigida al cálculo de la CDF(x) mediante cálculo
   integral. En particular, los cálculos los he llevado a cabo mediante una 
   de suma de Riemann, es decir, la integral bajo la curva se calcula como la
   suma de las áreas de rectángulos cuyas bases difieren en un valor muy pequeño 
   (en este caso dicha diferencia es SALTO = 0.25). De esta forma, para poder
   calcular esa suma reiterada de áreas, he establecido un ciclo while, que
   entrará en bucle siempre y cuando la abcisa a evalar sea menor o igual que
   el extremo superior del intervalo establecido. Al final del bucle se 
   actualiza la variable abcisa, sumándole el valor del salto. De esta forma
   una vez que se llega al valor máximo, se cierra el bucle y ya tendríamos el
   valor de la suma de las áreas (CDF(x)).
   
   4) La cuarta función se basa en el cálculo de la CDF(x) mediante la fórmula
   de "mejor aproximación de Hastings". Básicamente consiste en transcribir
   dicha fórmula, pero teniendo en cuenta el detalle de que hay que estandarizar
   la variable x (recurrir a la normalización), e incluir en los cálculos dicha
   normalización para que la distribución normal sea de la forma N(0,1).
   Finalmente, según el enunciado, si la abcisa es mayor o igual que 0, entonces
   el valor de CDF(X) coincide con el valor que resulta de aplicar la fórmula.
   Si es lo contrario, el valor de CDF(x) valdrá 1 - el valor obtenido en la
   fórmula. 
   
   Comentar que en todas estas funciones, se hacen llamamientos a las funciones 
   anteriores en los cálculos.
   
   Una vez definidas todas estas funciones, se pasa al programa principal
   (función main) en el cual he llevado a cabo una entrada de datos, en la que
   he filtrado mediante un ciclo post-test el valor de la desviación típica, 
   pues es el único dato que requiere comprobación (ha de ser mayor estricto que
   cero). Una vez filtrado dicho dato, se procede al cálculo de los valores que
   toma la función en el intervalo [esperanza - 3*desviacion_tipica , 
   esperanza + 3*desviacion_tipica], en función de los datos introducidos por
   el usuario. Para ello he establecido un ciclo while que entrará en bucle sí
   y solo sí la abcisa es menor o igual que el extremo superior del intervalo.
   Una vez dentro, se calculan dichos valores, utilizando la función creada
   anteriormente mostrándose en pantalla, tras su determinación, y una vez hecho
   esto, se actualiza la variable contadora de abcisas, mediante la suma del
   salto correspondiente (0.25). Una vez que se cierra el bucle, se procede
   a calcular el valor de CDF(x) por ambos métodos, mediante las funciones 
   correspondientes.
                         
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <cmath>      
#include <iomanip>

using namespace std;  

/******************************************************************************/
/******************************************************************************/

	// Función para el cáclulo de una potencia

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

	// FUNCIÓN APARTADO A

	/* Esta función calcula el valor que toma la gaussiana en una valor de
	   abcisa determinado, para una esperanza y desviación típica concretas.
	*/

double Gaussiana_de_x (double x, double esperanza, double desviacion_tipica)
{
	
	const double PI    = 3.14159265358979323846;  // Valor que le doy a pi
	
	// Cálculo del valor que toma la funcion en x
	
	double exponente_e = (-0.5)*(Potencia((x-esperanza)/desviacion_tipica,2)); 
    double aux_gauss   = (1 / (desviacion_tipica*sqrt(2*PI)));
		
		
    double gauss_de_x = aux_gauss * exp(exponente_e);
    
    return (gauss_de_x);
    
}

/******************************************************************************/

	// FUNCIÓN APARTADO B (para el cálculo de CDF(x))
	
double Cdf_de_x_B (double esperanza, double desviacion_tipica, double SALTO)
{
	
	// Declaración de datos
	
	double x_inicial   = esperanza - (3 * desviacion_tipica);
	double x_final     = esperanza + (3 * desviacion_tipica);
	double abcisa = x_inicial;
	double cdf_de_x    = 0;
	
	/* Establezco un ciclo while, cuya condición de ejecución es que la abcisa
	   sea menor o igual que el extremo superior del intervalo en el que está
	   contenida.
	*/   
	
	while (abcisa <= x_final){
		
		double area_bajo_curva = (Gaussiana_de_x(abcisa, esperanza,  
		                         desviacion_tipica) * SALTO);
		                         
		// La distribución acumulada, por lo tanto será: 
		   	
		cdf_de_x = cdf_de_x + area_bajo_curva;
	
	    // Actualizo el contador de la abcisa (que irá incrementándose en 
	    // función de la constante SALTO).
	    
	    abcisa = (abcisa + SALTO);
	}
	
	return (cdf_de_x);
	
}

/******************************************************************************/

	// FUNCION APARTADO C (para el cáclulo de la aproximación de CDF(x))
	
double Cdf_de_x_C (double abcisa, double esperanza, double desviacion_tipica)
{
	// Declaración de constantes, proporcionadas por el problema
	
	const double B0 = 0.2316419;
	const double B1 = 0.319381530;
	const double B2 = -0.356563782;
	const double B3 = 1.781477937;
	const double B4 = -1.821255978;
	const double B5 = 1.330274429;
	
	// Cálculos
	
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
	// DECLARACIÓN DE DATOS
	
	double abcisa; // No tengo que leerla porque está entre valores determinados
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
	
	
	// Cálculos
	
	/* El valor de la abcisa se encuentra en el intervalo [(esperanza -
	   3*desviacion_tipica), esparanza + 3*desviacion_tipica)]
	   De esta forma, he de considerar las siguientes declaraciones y 
	   agiganciones.
	*/   
	
	double x_inicial   = esperanza - (3 * desviacion_tipica);
	double x_final     = esperanza + (3 * desviacion_tipica);
	abcisa = x_inicial; 
	
	/* Establezco un ciclo while para que me calcule todos los valores que
	   que toma la función gaussiana en el intervalo dado, siendo la diferencia
	   entre los valores de x, el propio SALTO (0.25).
	   La condición que ha de cumplir dicho ciclo while es que la abcisa no
	   supere al máximo del intervalo, pues como mínimo es el valor de x_inicial
	   luego, cuando se alcance dicho máximo, se cierra el bucle y se procede a
	   llevar a cabo los cáclulos pertinentes de la distribución acumulada,
	   según el apartado b y c.
	*/
	
	
	
	cout << endl;
	cout << "Valores que toma la función en el intervalo: ";
	cout << endl;
	
	while (abcisa <= x_final){
		
		//Cálculos	
		
		g_de_x = Gaussiana_de_x (abcisa, esperanza, desviacion_tipica); 
		
		// Salida de datos (todos los valores de g(x) en el intervalo)
		
		cout << "El valor que toma g(x) en (" << abcisa << ")es:  " << g_de_x;
		cout << endl;
		
		// Se actualiza la x, sumándolel el salto correspondiente (0.25)
		
		abcisa = (abcisa + SALTO);
		
	}
	
	// Cálculo de las distribuciones acumuladas para el apartado b y c
	
		// APARTADO B (cálculo de CDF(x))
		
		cdf_x_1 = Cdf_de_x_B (esperanza, desviacion_tipica, SALTO);
		                      
		// APARTADO C (cálculo de la aproximación de CDF(x))
		
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
		
