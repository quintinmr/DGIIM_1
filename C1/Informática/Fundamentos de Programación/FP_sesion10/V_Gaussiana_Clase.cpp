/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/*  Programa que calcula e imprime:
	a) el valor de una gaussiana, dados sus par�metros (desviaci�n t�pica -s-   
	   y esperanza -m-) modularizando con funciones.
	b) el valor aproximado de la CDF(x) modularizando con funciones.
	para distintos valores de x comprendidos entre m-3s y m+3s.

	Entradas: par�metros de la gaussiana (desviacion -s-, y esperanza -m-) 
	Salidas:  Para valores de x entre m-3s y m+3s: 	

		a) El valor de la gaussiana g(x)

                                                {        (x-esperanza)^2 }
                                                { -0.5 * (-----------)   }
                            1                   {        (desviacion )   }
                g(x) = ----------------------  * e^
                                     ______
                       desviacion * V 2*PI     
	
		
		b) La aproximaci�n de la CDF(x) por: 
			  
	                      ( x
				          |
				CDF(x) =  |  g(x) d(x)
				          |
	                     _) x = -oo
                 
			donde g(x) es el valor de la funci�n gaussiana en x.

			Puede obtenerse un valor aproximado de CDF(x) como la suma de 
			valores de g(x), empezando por valores alejados de la media 
			(y menores que ella). Para el c�lculo pr�ctico de CDF(x) 
			la integral se convierte en una suma, y se requiere concretar 
			cu�ntas sumas se van a realizar. Basta con indicar:
				a) un valor inicial para x (tomaremos m-3s).
				b) un �salto� entre dos valores consecutivos de x 
				   (en una constante).		  
		
		c) La aproximaci�n de la CDF(x) por una aproximaci�n num�rica. 
		
			Previamente tenemos que transformar la variable x que sigue una 
			distribuci�n N(m, s) en otra variable z que siga una distribuci�n 
			estandarizada N(0,1) con la operaci�n:
            
            	z = (x-m)/s  
            
            Entonces: 
		            
			w = 1 - Gauss(|z|, 0, 1)(b1*t + b2*t^2 + b3*t^3 + b4*t^4 + b5*t^5)
			
			d�nde:
                      1 
               t = ----------
                   1 + b0*|z|
                
            b0 = 0.231641900	b1 = 0.319381530	b2 = -0.356563782
            b3 = 1.781477937	b4 = -1.821255978	b5 = 1.330274429
            
            Finalmente, si x>=0, CDF(x)=w. Si no, CDF(x)=1-w  
     
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <cmath>       //Inclusi�n de los recursos matem�ticos
#include <iomanip>
#include <string>
using namespace std;  
 
/******************************************************************************/

	// Funci�n para el c�clulo de una potencia.

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
class Gaussiana
{
	
private:
		
		double esperanza;
		double desviacion_tipica;
		
	/************************************************************************/
	
public:
	
	/************************************************************************/
	// Constructor con argumentos
	// Con este constructor se inicializar� un objeto.
	// PRE: La desviaci�n t�pica ha de ser mayor estricto que cero
	

	Gaussiana (double esperanza_gauss, double desv_tipica):
	
		esperanza (esperanza_gauss), desviacion_tipica (desv_tipica)
	{	
	}
	
	/************************************************************************/
	/* M�todos de lectura (Get) de los datos individuales, para poder trabajar
	   con los datos miebro en el main, dado, su car�cter privado
	*/   
	
	double Esperanza()
	{
		return esperanza;
	}

	double Desviacion()
	{
		return desviacion_tipica;
	}

	/***********************************************************************/
		
	/* M�todo para el c�clulo del valor que toma la gaussiana para un valor de
	   abcisa determinado.
	*/
	   
	double Gaussiana_de_x (double x)
	{
	
		const double PI    = 3.14159265358979323846;  // Valor que le doy a pi
	
		// C�lculo del valor que toma la funcion en x
	
		double exponente_e = (-0.5)*(Potencia((x-esperanza)/
		                      desviacion_tipica,2)); 
    	double aux_gauss   = (1 / (desviacion_tipica*sqrt(2*PI)));
		
		
    	double gauss_de_x = aux_gauss * exp(exponente_e);
    
    	return (gauss_de_x);
    	
    }
    
    /***********************************************************************/

	// M�TODO APARTADO B (para el c�lculo de CDF(x))
	
	double CDF_1 (double x)
	{
		const double PI = 6 * asin(0.5);
		const double SALTO_CDF = 0.001;	

		// C�lculos de la CDF (fuerza bruta, no est� optimizado)
	
		double abscisa_inic = esperanza-(3*desviacion_tipica); 
		double abscisa_fin  = x; 
	
		// Valor com�n que puede precalcularse  
		 
		double d = desviacion_tipica*sqrt(2*PI);

		// Acumular g(x)
	
		double suma_g_abs = 0.0; 
	
		for (double abs=abscisa_inic; abs<abscisa_fin; abs+=SALTO_CDF) {
	
			double g_abs = exp (-0.5*Potencia((abs-esperanza)/desviacion_tipica,
			                     2))
			               / d;
			suma_g_abs += g_abs; 
			
		}

		return (suma_g_abs * SALTO_CDF); 
	}

	/***********************************************************************/

	// M�TODO APARTADO C (para el c�clulo de la aproximaci�n de CDF(x))
	
	double CDF_2 (double abcisa)
	{
		
		const double B0 =  0.231641900;
		const double B1 =  0.319381530;
		const double B2 = -0.356563782;
		const double B3 =  1.781477937;
		const double B4 = -1.821255978;
		const double B5 =  1.330274429;

		// Estandarizar la distribuci�n gaussiana  
		// Si x -> N(m,s) y z = (x-m)/s entonces z -> N(0,1)    
	
		double z = (abcisa-esperanza)/desviacion_tipica; // variable aleatoria 
		                                                 // N(0,1)  
	
		double t = 1.0 / (1 + B0*fabs(z));
		double t2 = t*t;
		double t3 = t2*t; // t*t*t
		double t4 = t3*t; // t*t*t*t
		double t5 = t4*t; // t*t*t*t*t

		Gaussiana gauss (0,1);
	
		double g_std_x = gauss.Gaussiana_de_x(abs(z)); 
	
		double w = 1.0 - g_std_x * (B1*t + B2*t2 + B3*t3 + B4*t4 + B5*t5);

		return (abcisa>=0.0 ? w : 1.0-w);
	}
 

	/**********************************************************************/
	
	// M�todo ToString para mostrar la distribuci�n normal que sigue la 
	// gaussiana en cada caso
	
	string ToString ()
	{
		
		string cadena;
		
		cadena = "N (" + to_string(esperanza) + ", " + 
		         to_string(desviacion_tipica) + ")";
		         
		return (cadena);
		
	}
	
	/**********************************************************************/

};

/******************************************************************************/

////////////////////////////////////////////////////////////////////////////////

/******************************************************************************/

	int main (void)
{
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	// Declaraci�n de datos
	
	const double NUM_STDV = 3.0; 
	double media;
	double desv_tipica;
	
	const double SALTO = 0.25;

	/************************************************************************/
	
	// Entrada de datos


	cout << endl;
	cout << "----------------------------------------------------";
	cout << endl;
	cout << "           GAUSSIANA CDF REGLA EMPIRICA"            ;
	cout << endl;
	cout << "----------------------------------------------------";
  		
	// Lectura
	
	cout << endl;
	cout << "Introduzca los parametros de la gaussiana." << endl;
	cout << endl; 
			
	cout << "\tEsperanza:  ";
	cin >> media;
		
	do {
			
		cout << "\tDesviacion tipica: ";
		cin >> desv_tipica;
			
	} while (desv_tipica <= 0);
	
	cout << endl << endl; 
		
	// Creaci�n de un objeto Gaussiana
		
	Gaussiana g (media, desv_tipica);
		
	// Se muestra en pantalla la distribuci�n normal que sigue la funci�n
		
	cout << endl;
	cout << "Esta funcion gaussiana sigue una distribucion normal: ";
	cout << g.ToString();
	cout << endl;
	cout << endl;
		
		
	// C�lculos y salida de datos
		
	double min_x = g.Esperanza() - NUM_STDV*g.Desviacion();
	double max_x = g.Esperanza() + NUM_STDV*g.Desviacion();
		
	for (double x = min_x; x <= max_x; x += SALTO) {
	
		double g_x;	    // g(x)
		double cdf_1_x; // CDF_1(x) // "integral"
		double cdf_2_x; // CDF_2(x) // aproximaci�n de Hastings
		
		// C�lculo de g(x) y CDFs(x)
			
		g_x     = g.Gaussiana_de_x(x);
		cdf_1_x = g.CDF_1(x);
		cdf_2_x = g.CDF_2(x);
	
		// Presentaci�n de resultados
		
		cout << "G(" << setw(11) << setprecision(7) << x << ") = " 
			 << setw(10) << setprecision(7) << g_x << " ----- ";
		cout << "CDF_1 (" << setw(11) << setprecision(7) << x << ") = " 
			 << setw(10) << setprecision(7) << cdf_1_x << " ----- ";
		cout << "CDF_2 (" << setw(11) << setprecision(7) << x << ") = " 
			 << setw(10) << setprecision(7) << cdf_2_x;			
		cout << endl;
		
	} // for x
		
	cout << endl;
		 			 
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/	
				
