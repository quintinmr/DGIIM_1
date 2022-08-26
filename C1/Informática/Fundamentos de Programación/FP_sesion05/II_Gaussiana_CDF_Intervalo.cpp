/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee la esperanza o media, la desviaci�n t�pica de la funci�n
   gaussiana, y el valor de una abcisa (x) y calcula el �rea que cubre la 
   funci�n gaussiana en el intervalo [-inf, x]. Dicho �rea se calcula con 
   la distribuci�n acumulada; CDF , es decir la integral definida entre
   -inf y x de la funci�n gaussiana. Luego lo que nos va a mostrar el programa
   es el valor de CDF(X), que se llevar� a cabo mediante una serie de sumas
   recorridas por un �ndice que var�a en funci�n de un "salto" constante.
   
   Entradas: 
    Esperanza (esperanza), desviaci�n t�pica (desviacion_tipica), abcisa (x).
    
   Salidas:
    �rea que cubre la funci�n en [-inf, x] (CDF(X))
    
   En este programa, en primer lugar he utilizado un filtro para los datos, en
   particular para la desviaci�n t�pica, que consiste en un ciclo post-test
   que entr� en bucle s� y solamente s� la desviaci�n t�pica introducida por
   el usuario es menor o igual que cero. Si la condici�n no se cumple, entonces
   se procede al c�clulo del �rea bajo la curva. Para ello, he establecido un
   ciclo del tipo for, en el que he establecido un �ndice contador que he
   llamado k al que le he asociado, originalmente el valor x_inicial, le he
   impuesto la condici�n de que sea menor o igual que la abcisa introducida por
   el usuario y la actualizaci�n que he implementado es simplemente la adici�n
   del "salto" al valor incial del contador. De esta forma se van a ir sumando
   prograsivamente todas las �reas de los rect�ngulos infinitesimeles que se
   obtienen al considerar un salto tan peque�o entre las abcisas, obteniendose
   as� el �rea total de la curva; la distribuci�n acumulada CDF; la integral
   desde el menos ifinito al valor de la abcisa x.
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <cmath>
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaraci�n de datos
	
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
    
    // C�lculos
    
    // Declaraci�n de variables que van a ser usadas en los c�lculos
    
    // Le asigno a la abcisa un valor inicial
	double x_inicial   = esperanza - (3 * desviacion_tipica);
	
	/* El c�lculo del �rea se va a realizar por medio de sumas de �reas de 
	   rect�ngulos de base abcisa+(un n�mero muy peque�o). Dicho n�mero es lo
	   que he llamado "salto"; la diferencia entre dos abcisas consecutivas.  */
	   
	double const SALTO = 0.25;
	
	double const PI    = 3.14159265358979323846;  // Valor que le doy a pi
	
	/* Declaro la variable de salida; la distribuci�n acumulada, que me dar�
	   el �rea bajo la curva para los datos introducidos.                     */
	   
	double cdf_de_x    = 0;  // Le asigno el valor inicial cero.
	
	
	double gaussiana_de_x;   // Valor que toma la funci�n guassiana en x.
	
	                        
		
	for(double k = x_inicial; k <= abcisa; k = k + SALTO){
		
		// C�lculo de los valores que toma la funci�n gaussiana 
		
	        // Declaro estas variables para simplificar
	                             // la sentencia. 
		double exponente_e = (-0.5)*(pow((k-esperanza)/desviacion_tipica,2)); 

		
		double aux_gauss = (1 / (desviacion_tipica*sqrt(2*PI)));
		
		gaussiana_de_x = aux_gauss * exp(exponente_e);
		
		/* C�lculo del �rea que cubre la funci�n en el intervalor [-inf, x], 
		   ser� la suma de las �reas de los rect�ngulos infinitesimales que se
		   obtienen al establecer un salto tan peque�o como el que he 
		   establecido entre las abcisas.                                     */
		   		
		double area_bajo_curva = gaussiana_de_x * SALTO;
			
		// La distribuci�n acumulada, por lo tanto ser�: 
		   	
		cdf_de_x = cdf_de_x + area_bajo_curva;
	
	}
    
    // Salida de datos
    
    cout << endl;
    cout << "El area que cubre la funci�n gaussiana en el intervalo "
         << "[-infinito, " << abcisa << "] es CDF("<< abcisa <<") = "
		 << cdf_de_x;
    cout << endl;
    
/******************************************************************************/
	return 0;
	
}
    

    
		
	
	
	
	
	
	
	
	
