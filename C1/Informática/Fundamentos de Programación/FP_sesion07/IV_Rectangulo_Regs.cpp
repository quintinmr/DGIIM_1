/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee las coordenadas que definen un rect�ngulo (superior 
   izquierda e inferior derecha) y calcula la circunferencia de centro el punto
   de corte de las diagonales del rect�ngulo y de menor �rea que el mayor
   �rea posible del rect�ngulo.
   
   Entradas: 
    Coordenadas del rect�ngulo (sup_izda, inf_dcha).
    
   Salidas:
    Circunferencia de centro el punto de corte de las diagonales del rect�ngulo
	y de superficie la menor entre todas las circunferencias de
    �rea mayor que la del rect�ngulo (circunferencia).  
                         
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <cmath>
using namespace std;  

/******************************************************************************/
/******************************************************************************/


	/* Defino el struct Punto2D, pues los datos de las coordenadas van a
     a ser de ese tipo (van a tener una abcisa y una ordenada en el origen)
    */ 
    
struct Punto2D {

	double abcisa;
	double ordenada;

};

/******************************************************************************/

	/* A continuaci�n creo otro tipo de dato, que ser� el ser coordenada de
       de las esquinas de un rect�ngulo, y que obviamente ser�n del tipo
       Punto2D
    */
	
struct Rectangulo {
	
	Punto2D sup_izda;
	Punto2D inf_dcha;
	
};

/******************************************************************************/

	/* Defino ahora el tipo de dato circunferencia, el cual estar� constitu�do
	   por dos campos, que son el centro y el radio, que son los dos elementos
	   que se necesitan para definir una circunferencia.
	*/

struct Circunferencia {
 
    double radio;
    Punto2D centro;
    
};

/******************************************************************************/

	/* A continuaci�n procedo al c�clulo del punto de corte de las diagonales
	   del rect�ngulo definido por las coordenadas anteriores. Para ello, 
	   voy a proceder de la siguiente forma:
	                                                        m
	   El rect�ngulo es de la forma        (a,b)  o---------o---------o
	                                              |         |         |
	                                              |         o         |
	                                              |         |         |
	                                              o---------o---------o	(c,d)
											                n
											
		El punto de corte de las diagonales ser� el punto medio del segmento
		de extremos el punto medio de la base inferior y el punto medio de
		la base superior. 
		Para calcular el punto medio de la base inferior calculo el valor del 
		punto de la esquina inferior izquierda y, junto con las coordenadas
		de la esquina inferior derecha, hallo el punto medio del segmento que
		las une:
		   
		   Esquina inferior izquierda =  (a,d)
		   Punto medio de la base inferior = ((a+c)/2 , (d+d)/2).
		
		Para calcular el punto medio de la base superior procedo de la misma
		forma:
		
		   Esquina superior derecha = (c,b)
		   Punto medio de la base superior = ((a+c)/2 , (b+b)/2)
		   
		El punto de corte ser� por lo tanto:
		
			((((a+c)/2) + ((a+c)/2)))/2) , ((((d+d)/2) + ((b+b)/2)))/2))  =
			
			= ((a+c)/2,(d+b)/2)
	*/
	
Punto2D Punto_de_corte_diagonales (Rectangulo poligono)
{
	
	// Delcaro la variable punto_corte
	
	Punto2D punto_corte; 
	
	punto_corte.abcisa   = ((poligono.sup_izda.abcisa + 
	                         poligono.inf_dcha.abcisa)/2);
	punto_corte.ordenada = ((poligono.inf_dcha.ordenada + 
	                         poligono.sup_izda.ordenada)/2);


	return punto_corte;	
}

/******************************************************************************/

	/* A continuaci�n defino una funci�n para calcular el �rea del rect�ngulo.
	   Partiendo del hecho de que el �rea de un rect�ngulo es base por altura,
	   tendr� que hallar el valor de la base y de la altura:
	   
	   	base = c-a
	   	altura = b-d
	   	
	   	area = base * altura = (c-a) * (b-d)
	   	
	   Hemos de tener el cuenta que dichos valores pueden salir negativos, y 
	   como bien sabemos, el valor del lado de un rect�ngulo; el valor de una
	   medida, no puede ser negativo, por lo tanto es condici�n indispensable
	   hacer uso de la funci�n valor absoluto en los c�lculos del �rea.	
	   	
	*/   	
	
double AreaRectangulo (Rectangulo poligono)
{

	double area;
	
		   area = abs(poligono.inf_dcha.abcisa - poligono.sup_izda.abcisa) *
		          abs(poligono.sup_izda.ordenada - poligono.inf_dcha.ordenada);
		              
		  
	return area;	              
}

/******************************************************************************/

	/* Esta funci�n es para el mero c�lculo del �rea de una circunferencia
	usando el dato tipo Circunferencia.
	*/
	
double AreaCircunferencia (Circunferencia circunf)
{
	
	// Le doy un valor a la constante PI
	
	const double PI = 3.14159265358979323846264338327950288;
	
	double area;
	
	area = (PI * ((circunf.radio) * (circunf.radio)));
	
	return area;
	
}

/******************************************************************************/

int main ()
{
	
	// Declaraci�n de datos
	
	Rectangulo poligono;
	Circunferencia circunf;
	
	double area_del_rectangulo = 0;
	double area_de_la_circunferencia = 0;
	
	// Declaraci�n de constantes
	
	const double RADIO_INIC = 0.5;
	const double VARIANDO = 0.25;
	
	double radio_de_la_circunferencia = RADIO_INIC; // Inicio el contador del 
	                                                // radio
	                                                
/******************************************************************************/	                                                
																										                                                
	// Entrada de datos                                                
		
	cout << "Introduzca las coordenadas de la esquina superior izquierda" 
		 << " del rectangulo: ";
	cin  >>  poligono.sup_izda.abcisa >> poligono.sup_izda.ordenada;
	
	cout << "Introduzca las coordenadas de la esquina inferior derecha del "
	     << "rectangulo: ";
	cin  >> poligono.inf_dcha.abcisa >> poligono.inf_dcha.ordenada;
	
	cout << endl;
	
	// C�lculos
	
	/* C�lculo del centro de la circunferencia (que ser� el punto de corte de
	   las diagonales del rect�ngulo que se ha definido), mediante la llamada
	   a la funci�n anteriormente definida Punto_de_corte_diagonales.
	*/ 
	
	circunf.centro =  Punto_de_corte_diagonales (poligono);	      

	/* C�lculo del �rea del rect�ngulo, mediante la llamada a la funci�n 
	   Rect�ngulo.
	*/
	
	area_del_rectangulo = AreaRectangulo (poligono);
	
	/* A continuaci�n, establezco un ciclo while para calcular el �rea de
	   la menor entre todas las circunferencias de �rea mayor que la del 
	   rect�ngulo (circunferencia).
	   Luego, dicho ciclo entrar� en bucle s� y solamente s� el �rea de la
	   circunferencia es menor o igual que el �rea del rect�ngulo.
	   Cada vez que se realiza el c�lculo del �rea de la cicunferencia se
	   actualiza el contador del radio, que se va incrementando seg�n la
	   constante VARIANDO, y que tiene un valor original de RADIO_INIC (0.5).
	   En el momento en el que se obtenga un �rea de circunferencia mayor, el 
	   bucle se cierra pues ya no se cumple la condici�n y se obtiene la 
	   circunferencia que est�bamos buscando.
	*/
	
	while (area_de_la_circunferencia <= area_del_rectangulo) {
	
		// Declaro el dato radio
		
		circunf.radio = radio_de_la_circunferencia;
		
		// C�lculo del �rea de la circunferencia llamando a la funci�n 
	    // AreaCircunferencia
		
		area_de_la_circunferencia = AreaCircunferencia(circunf);
		
		// Actualizo el radio
		
		radio_de_la_circunferencia = radio_de_la_circunferencia + VARIANDO;
		
	}
	
	// Salida de datos
	
	cout << "De acuerdo con las coordenadas introducidas, el area del "
	     << " rectangulo resultante es: " << area_del_rectangulo
	     << " unidades cuadradas";
	cout << endl;     
	cout << "La circunferencia que buscamos es la de de centro " 
	     << "("<<circunf.centro.abcisa << " ," << circunf.centro.ordenada
		 << ")""," 
		 << " radio "<< circunf.radio <<" unidades y area: " 
		 << area_de_la_circunferencia << " unidades cuadradas";
    cout << endl;
	
/******************************************************************************/
	return 0;
}   
