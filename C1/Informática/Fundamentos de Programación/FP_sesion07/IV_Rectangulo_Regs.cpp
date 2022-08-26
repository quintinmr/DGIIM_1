/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee las coordenadas que definen un rectángulo (superior 
   izquierda e inferior derecha) y calcula la circunferencia de centro el punto
   de corte de las diagonales del rectángulo y de menor área que el mayor
   área posible del rectángulo.
   
   Entradas: 
    Coordenadas del rectángulo (sup_izda, inf_dcha).
    
   Salidas:
    Circunferencia de centro el punto de corte de las diagonales del rectángulo
	y de superficie la menor entre todas las circunferencias de
    área mayor que la del rectángulo (circunferencia).  
                         
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
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

	/* A continuación creo otro tipo de dato, que será el ser coordenada de
       de las esquinas de un rectángulo, y que obviamente serán del tipo
       Punto2D
    */
	
struct Rectangulo {
	
	Punto2D sup_izda;
	Punto2D inf_dcha;
	
};

/******************************************************************************/

	/* Defino ahora el tipo de dato circunferencia, el cual estará constituído
	   por dos campos, que son el centro y el radio, que son los dos elementos
	   que se necesitan para definir una circunferencia.
	*/

struct Circunferencia {
 
    double radio;
    Punto2D centro;
    
};

/******************************************************************************/

	/* A continuación procedo al cáclulo del punto de corte de las diagonales
	   del rectángulo definido por las coordenadas anteriores. Para ello, 
	   voy a proceder de la siguiente forma:
	                                                        m
	   El rectángulo es de la forma        (a,b)  o---------o---------o
	                                              |         |         |
	                                              |         o         |
	                                              |         |         |
	                                              o---------o---------o	(c,d)
											                n
											
		El punto de corte de las diagonales será el punto medio del segmento
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
		   
		El punto de corte será por lo tanto:
		
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

	/* A continuación defino una función para calcular el área del rectángulo.
	   Partiendo del hecho de que el área de un rectángulo es base por altura,
	   tendré que hallar el valor de la base y de la altura:
	   
	   	base = c-a
	   	altura = b-d
	   	
	   	area = base * altura = (c-a) * (b-d)
	   	
	   Hemos de tener el cuenta que dichos valores pueden salir negativos, y 
	   como bien sabemos, el valor del lado de un rectángulo; el valor de una
	   medida, no puede ser negativo, por lo tanto es condición indispensable
	   hacer uso de la función valor absoluto en los cálculos del área.	
	   	
	*/   	
	
double AreaRectangulo (Rectangulo poligono)
{

	double area;
	
		   area = abs(poligono.inf_dcha.abcisa - poligono.sup_izda.abcisa) *
		          abs(poligono.sup_izda.ordenada - poligono.inf_dcha.ordenada);
		              
		  
	return area;	              
}

/******************************************************************************/

	/* Esta función es para el mero cálculo del área de una circunferencia
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
	
	// Declaración de datos
	
	Rectangulo poligono;
	Circunferencia circunf;
	
	double area_del_rectangulo = 0;
	double area_de_la_circunferencia = 0;
	
	// Declaración de constantes
	
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
	
	// Cálculos
	
	/* Cálculo del centro de la circunferencia (que será el punto de corte de
	   las diagonales del rectángulo que se ha definido), mediante la llamada
	   a la función anteriormente definida Punto_de_corte_diagonales.
	*/ 
	
	circunf.centro =  Punto_de_corte_diagonales (poligono);	      

	/* Cálculo del área del rectángulo, mediante la llamada a la función 
	   Rectángulo.
	*/
	
	area_del_rectangulo = AreaRectangulo (poligono);
	
	/* A continuación, establezco un ciclo while para calcular el área de
	   la menor entre todas las circunferencias de área mayor que la del 
	   rectángulo (circunferencia).
	   Luego, dicho ciclo entrará en bucle sí y solamente sí el área de la
	   circunferencia es menor o igual que el área del rectángulo.
	   Cada vez que se realiza el cálculo del área de la cicunferencia se
	   actualiza el contador del radio, que se va incrementando según la
	   constante VARIANDO, y que tiene un valor original de RADIO_INIC (0.5).
	   En el momento en el que se obtenga un área de circunferencia mayor, el 
	   bucle se cierra pues ya no se cumple la condición y se obtiene la 
	   circunferencia que estábamos buscando.
	*/
	
	while (area_de_la_circunferencia <= area_del_rectangulo) {
	
		// Declaro el dato radio
		
		circunf.radio = radio_de_la_circunferencia;
		
		// Cálculo del área de la circunferencia llamando a la función 
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
