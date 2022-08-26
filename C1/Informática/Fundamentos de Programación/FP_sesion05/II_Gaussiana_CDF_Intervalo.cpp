/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee la esperanza o media, la desviación típica de la función
   gaussiana, y el valor de una abcisa (x) y calcula el área que cubre la 
   función gaussiana en el intervalo [-inf, x]. Dicho área se calcula con 
   la distribución acumulada; CDF , es decir la integral definida entre
   -inf y x de la función gaussiana. Luego lo que nos va a mostrar el programa
   es el valor de CDF(X), que se llevará a cabo mediante una serie de sumas
   recorridas por un índice que varía en función de un "salto" constante.
   
   Entradas: 
    Esperanza (esperanza), desviación típica (desviacion_tipica), abcisa (x).
    
   Salidas:
    Área que cubre la función en [-inf, x] (CDF(X))
    
   En este programa, en primer lugar he utilizado un filtro para los datos, en
   particular para la desviación típica, que consiste en un ciclo post-test
   que entrá en bucle sí y solamente sí la desviación típica introducida por
   el usuario es menor o igual que cero. Si la condición no se cumple, entonces
   se procede al cáclulo del área bajo la curva. Para ello, he establecido un
   ciclo del tipo for, en el que he establecido un índice contador que he
   llamado k al que le he asociado, originalmente el valor x_inicial, le he
   impuesto la condición de que sea menor o igual que la abcisa introducida por
   el usuario y la actualización que he implementado es simplemente la adición
   del "salto" al valor incial del contador. De esta forma se van a ir sumando
   prograsivamente todas las áreas de los rectángulos infinitesimeles que se
   obtienen al considerar un salto tan pequeño entre las abcisas, obteniendose
   así el área total de la curva; la distribución acumulada CDF; la integral
   desde el menos ifinito al valor de la abcisa x.
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <cmath>
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaración de datos
	
	// Datos de entrada
	
	double esperanza;
	double desviacion_tipica;
	double abcisa;

	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca el valor de la esperanza o media: ";
	cin  >> esperanza;
	
	do{
				
		cout << "Introduzca el valor de la desviacion tipica: ";
		cin  >> desviacion_tipica;
		
    }while (desviacion_tipica <= 0);
    
    cout << "Introduzca una abcisa: ";
    cin  >> abcisa;
    
    // Cálculos
    
    // Declaración de variables que van a ser usadas en los cálculos
    
    // Le asigno a la abcisa un valor inicial
	double x_inicial   = esperanza - (3 * desviacion_tipica);
	
	/* El cálculo del área se va a realizar por medio de sumas de áreas de 
	   rectángulos de base abcisa+(un número muy pequeño). Dicho número es lo
	   que he llamado "salto"; la diferencia entre dos abcisas consecutivas.  */
	   
	double const SALTO = 0.25;
	
	double const PI    = 3.14159265358979323846;  // Valor que le doy a pi
	
	/* Declaro la variable de salida; la distribución acumulada, que me dará
	   el área bajo la curva para los datos introducidos.                     */
	   
	double cdf_de_x    = 0;  // Le asigno el valor inicial cero.
	
	
	double gaussiana_de_x;   // Valor que toma la función guassiana en x.
	
	                        
		
	for(double k = x_inicial; k <= abcisa; k = k + SALTO){
		
		// Cálculo de los valores que toma la función gaussiana 
		
	        // Declaro estas variables para simplificar
	                             // la sentencia. 
		double exponente_e = (-0.5)*(pow((k-esperanza)/desviacion_tipica,2)); 

		
		double aux_gauss = (1 / (desviacion_tipica*sqrt(2*PI)));
		
		gaussiana_de_x = aux_gauss * exp(exponente_e);
		
		/* Cálculo del área que cubre la función en el intervalor [-inf, x], 
		   será la suma de las áreas de los rectángulos infinitesimales que se
		   obtienen al establecer un salto tan pequeño como el que he 
		   establecido entre las abcisas.                                     */
		   		
		double area_bajo_curva = gaussiana_de_x * SALTO;
			
		// La distribución acumulada, por lo tanto será: 
		   	
		cdf_de_x = cdf_de_x + area_bajo_curva;
	
	}
    
    // Salida de datos
    
    cout << endl;
    cout << "El area que cubre la función gaussiana en el intervalo "
         << "[-infinito, " << abcisa << "] es CDF("<< abcisa <<") = "
		 << cdf_de_x;
    cout << endl;
    
/******************************************************************************/
	return 0;
	
}
    

    
		
	
	
	
	
	
	
	
	
