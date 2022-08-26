/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Este programa: 
	
		a) 	Pide los coeficientes de dos rectas,
		b) 	Muestra los puntos (x, y) por los que pasan las rectas para 
			valores de x = -10, -9, ..., 10 con Incr_x = +1 y para 
			y = -5,- 4, .... 5 con Incr_y = 0.5
			
			Usa las funciones:
				double Ordenada (Recta recta, Punto2D punto);
				double Abscisa  (Recta recta, Punto2D punto);
			
			para calcular la ordenada "y" dada la abscisa "x" (y viceversa)  
			para la recta Ax+By+C=0
			
		c) Escribe la ecuación explícita de las dos rectas
		
			i) con una función que escribe directamente la ecuación:
				void EcuacionExplicita (Recta recta);
		
			ii) con una función que devuelve un string con la expresión de 
				la ecuación:
				string ExpresionEcuacionExplicita (Recta recta);
				
			En ambos casos se calcula la pendiente y la ordenada en el origen 
			con sendas funciones:
				double Pendiente (Recta recta);
				double OrdenadaEnElOrigen (Recta recta);				
					
		d) 	Indica si las rectas son paralelas, secantes o coincidentes 
			usando las funciones:
				bool Coincidentes (recta1, recta2); 			
				bool Paralelas    (recta1, recta2); 			
				bool Secantes     (recta1, recta2); 
				
		e) Calcula el punto de corte de las rectas si son secantes
		
			Punto2D PuntoDeCorte (Recta recta1, Recta recta2)
			
		f) Determina si un punto introducido por el usuario pertenece o no
		   a la primera recta introducida por el usuario.
		
							
   Entradas: 
    Los coeficientes de dos rectas.
    Un punto de R2.
    
   Salidas:
   	Los puntos (x,y) por los que pasan las rectas en el rango de abcisas
   	(-10, 10) con salto de una unidad, y en el rango de ordenadas
   	(-5, 5) con salto de 0.5.
   	
   	La ecuación explícita de las rectas (y = mx +n).
   	
   	Su posición relativa (coincidentes, paralelas, secantes).
   	
   	El punto de corte, si son secantes. Dicho punto de corte lo he calculado
   	mediante una expresión la cual he obtenido a mano previamente en un papel
   	que resulta de la resolución genérica de un sistema de dos ecuaciones
   	con dos incógnitas. Las dos ecuaciones son las propias ecuaciones generales
   	de las rectas introducidas por el usuario, que son de la forma Ax+By+C=0 
   	y Dx+Ey+F=0. De ahí calculo, resolviendo el sistema por cualquier método
   	(yo he escogido el método de sustitución), el valor genérico de la abcisa
   	del punto de corte (x) y el valor genérico de la ordenada en el origen (y).
   	
   	  Punto de corte: (((-B*C + C*B) /(B*A -A*B)), ((A*C - C*A) /(B*A - A*B)))
   	                       
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;  

/******************************************************************************/
/******************************************************************************/
	// Defino el tipo de dato Punto2D, de campos abscisa y ordenada de un punto
	
struct Punto2D {
	
	double x;
	double y; 
	
};

/******************************************************************************/
	// Defino el tipo de dato Recta, de campos los coeficientes de la recta
	
struct Recta {
	
	double A; 
	double B;
	double C; 
	
};

/******************************************************************************/

    /* Defino a continuación una función para el calculo de la ordenada "y" 
	   dada la abscisa "x" para la recta Ax+By+C=0.
	   
	   Se establece la precondición:
	   PRE: B!=0
	*/
	   
double Ordenada (Recta recta, Punto2D punto)
{
	
	return ((-recta.A*punto.x -recta.C) / recta.B);
	
}

/******************************************************************************/

	/* Defino a continuación una función para el cálculo de la abcisa "x" dada 
	   la ordenada "y" para la recta Ax+By+C=0
	   
	   Se establece la precondición:
	   PRE: A != 0
	*/
	   
double Abscisa (Recta recta, Punto2D punto)
{
	
	return ((-recta.B*punto.y -recta.C) / recta.A);	
	
}

/******************************************************************************/

	/* Esta función calcula la pendiente de la recta, como el opuesto del
	   cociente entre los coeficientes A y B.
	   
	   Se establece la precondición:
	   PRE: B != 0
	*/
	   
double Pendiente (Recta recta)
{
	
	return (-recta.A/recta.B);
	
}

/******************************************************************************/

	/* Esta función calcula la ordenada en el origen de la recta, como el 
	   opuesto del cociente entre los coeficientes C y B.
	   
	   Se establece la precondición:
	   PRE: B != 0
	*/
	
double OrdenadaEnElOrigen (Recta recta)
{

	return (-recta.C/recta.B);
		
}

/******************************************************************************/

	/* Esta función simplemente devuelve la expresión de la ecuación explícita
	   de la recta, y es de la forma y = mx + n, donde m es la pendiente de
	   la recta y n la ordenada en el origen.
	   
	   Se establece la precondición:
	   PRE: B != 0
	*/
	   
void EcuacionExplicita (Recta recta)
{
	double slope = Pendiente (recta);
	double ordenada = OrdenadaEnElOrigen (recta);	
	
	cout << " y = ";
	
	if (slope!=0){
		
		cout << setw(5) << setprecision(2) << slope <<  " x ";	
		
	}

	if (ordenada != 0) {
		
		if (ordenada>0){
		
			 cout << " +";
			 
		}
		else
		{
		     cout << " -";
		     
		 }
		
		// cout << ((n > 0) ? " +" : " -");
	}
	
	cout << setw(5) << setprecision(2) << fabs(ordenada);	
}
	
/******************************************************************************/		

	/* La siguiente función está destinada a devolver un string con la expresión
	   de la ecuación explícita de la recta.
	   
	   Se establece la precondición:
	   PRE: B! = 0
	*/

string ExpresionEcuacionExplicita (Recta recta)
{
	double slope    = Pendiente (recta);
	double ordenada = OrdenadaEnElOrigen (recta);	
	
	string ec_explicita;
	
	ec_explicita = "La ecuación explicita de la recta es: y = ";
	
	if (slope != 0){
	
		ec_explicita = ec_explicita + to_string (slope) + " x ";
		
	}
	
	if (ordenada != 0) {
		
		if (ordenada > 0){
		
			 ec_explicita = ec_explicita + " +";
			 
		}
		
		else 
		{
		    ec_explicita = ec_explicita + " -";
		    
		}
		
		// explicita = explicita + ((n > 0) ? " +" : " -");
	}
	
	ec_explicita = ec_explicita + to_string (fabs(ordenada));	
	
	return (ec_explicita);
}

/******************************************************************************/

	/* Esta función determina si dos rectas son coincidentes (son la misma 
	   recta y por tanto la razón entre el primer coeficiente de una 
	   y el primer coeficiente de otra, , la razón entre el segundo coeficiente
	   de una y el segundo coeficiente y la razón entre el tercer coeficiente
	   de una y el tercer coeficiente de la otras son iguales).
       Devuelve el valor "true" si las rectas son coincidentes.
       Para ello la función ha de ser de tipo bool.
    */
    
    
	   
bool Coincidentes (Recta recta1, Recta recta2)
{
	
	double razon = recta1.A /recta2.A;
	
	return ((razon == recta1.B / recta2.B) && (razon == recta1.C / recta2.C));
}
					 			
/******************************************************************************/
	/* Esta función determina si dos rectas son paralelas (tienen la misma 
	   pendiente, y por tanto la razón entre el primer coeficiente de una 
	   y el primer coeficiente de otra, y la razón entre el segundo coeficiente
	   de una y el segundo coeficiente de la otra son iguales).
       Devuelve el valor "true" si las rectas son paralelas.
       Para ello la función ha de ser de tipo bool.
    */
/******************************************************************************/

bool Paralelas  (Recta recta1, Recta recta2)		
{
	double razon = recta1.A /recta2.A;
	
	return ((razon == recta1.B / recta2.B) && (razon != recta1.C / recta2.C));
}

/******************************************************************************/
	/* Esta función determina si dos rectas son secantes (se cortan en un punto
	   y por tanto la razón entre el primer coeficiente de una 
	   y el primer coeficiente de otra, y la razón entre el segundo coeficiente
	   de una y el segundo coeficiente no son iguales).
       Devuelve el valor "true" si las rectas son secantes.
       Para ello la función ha de ser de tipo bool
    */

bool Secantes  (Recta recta1, Recta recta2)
{
	double razon = recta1.A/recta2.A;	
	return (razon != recta1.B / recta2.B);
}
									  
									  				
/******************************************************************************/

	/* Esta función va destinada al cálculo del punto de corte de dos rectas
	   secantes.
	*/
	   
Punto2D PuntoDeCorte (Recta recta1, Recta recta2)
{

	Punto2D punto_de_corte;
	
		punto_de_corte.x = (-recta1.B*recta2.C + recta1.C*recta2.B) /
						   (recta1.B*recta2.A - recta1.A*recta2.B);
						   
		punto_de_corte.y = (recta1.A*recta2.C - recta1.C*recta2.A) /
						   (recta1.B*recta2.A - recta1.A*recta2.B);
							
	return (punto_de_corte);
	
}

/******************************************************************************/

	/* Esta función está destinada a la determinación de la pertenencia de 
	   un punto en una recta.
	   Esta función es de tipo bool, y me devuelve el valor true sí y solo
	   sí la evaluación del punto en la recta es cero.
	   Recordemos que la recta es de la forma Ax+By+C=0
	   Luego, el punto pertenece sí y solo sí se cumple esa igualdad.
	*/
	
bool PuntoPertenece (Recta recta, Punto2D punto)
{
	
	return ((((recta.A*punto.x) + (recta.B*punto.y) + recta.C) == 0));
	
}

/******************************************************************************/	
/******************************************************************************/		
/******************************************************************************/
		
int main()
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 
	
	// DECLARACIÓN DE DATOS
	
	Recta recta_1;  
	// PRE: recta_1.A y recta_1.B no pueden ser 0 
	
	Recta recta_2;  
	// PRE: recta_2.A y recta_2.B no pueden ser 0 
	
	Punto2D point;   // Variable auxiliar
	
	Punto2D punto_de_corte_rectas; // Punto de corte de las rectas secantes
	
/******************************************************************************/	
	
	// Entrada de datos
	
	cout << endl;	
	cout << "Introduzca los coeficientes de la primera recta: ";

	do 	{
		cout << endl; 
		cout << "\tA: ";
		cin >> recta_1.A;
		cout << "\tB: ";
		cin >> recta_1.B;
	} while (recta_1.A == 0 && recta_1.B == 0);

	cout << "\tC: ";
	cin >> recta_1.C;
	
	cout << endl;	
	cout << "Introduzca los coeficientes de la segunda recta: ";
	
	do 	{
		cout << endl; 
		cout << "\tA: ";
		cin >> recta_2.A;
		cout << "\tB: ";
		cin >> recta_2.B;
	} while (recta_2.A == 0 && recta_2.B == 0);

	cout << "\tC: ";
	cin >> recta_2.C;
	
	cout << endl;	


	// b) Mostrar puntos (x,y) por los que pasan las rectas
	
	if (recta_1.B != 0) {
		cout << endl;	
		cout << "Recta 1. x=-10.0, -9.0, ..., 10.0" << endl;
		cout << endl;
			
		Punto2D point;   // Variable auxiliar
		
		for (point.x =-10.0; point.x<=10.0; point.x++) {
			
			cout << "\t(" << setw(6) << setprecision(2) << point.x << ", " 
			     << setw(6) << setprecision(2) 
				 << Ordenada (recta_1, point) 
				 << ")" << endl;
		}
	}
	else // B1==0
		cout << "Recta 1 paralela al eje Y--> x = " 
		     << setw(6) << setprecision(2) << (-recta_1.C/recta_1.A) << endl;
	cout << endl;	
	
	if (recta_1.A != 0) {
		cout << endl;
		cout << "Recta 1. y=-5.0, -4.5, -4.0, ..., 5.0" << endl; 
		cout << endl;	
		
		for (point.y =-5.0; point.y <=5.0; point.y += 0.5) {
			
			cout << "\t(" << setw(6) << setprecision(2) 
			     << Abscisa (recta_1, point)  << ", " 
			     << setw(6) << setprecision(2) << point.y << ")" << endl;
		}
	}
	else // A1==0
		cout << "Recta 1 paralela al eje X--> y = " 
		     << setw(6) << setprecision(2) << (-recta_1.C/recta_1.B) << endl;
	cout << endl;
		
	if (recta_2.B!=0) {
		cout << endl;		
		cout << "Recta 2. x=-10.0, -9.0, ..., 10.0" << endl;
		cout << endl;	
		
		for (point.x = -10.0; point.x <= 10.0; point.x++) {
			
			cout << "\t(" << setw(6) << setprecision(2) << point.x << ", " 
			     << setw(6) << setprecision(2) 
				 << Ordenada (recta_2, point) 
				 << ")" << endl;
		}
	}
	else // B2==0
		cout << "Recta 2 paralela al eje Y--> x = " 
		     << setw(6) << setprecision(2) << (-recta_2.C/recta_2.A) << endl;
	cout << endl;

	if (recta_2.A != 0) {			 	
		cout << endl;
		cout << "Recta 2. y=-5.0, -4.5, -4.0, ..., 5.0" << endl; 
		cout << endl;	
	
		for (point.y = -5.0; point.y <=5.0; point.y += 0.5) {
			
			cout << "\t(" << setw(6) << setprecision(2) 
			     << Abscisa (recta_2, point)  << ", " 
			     << setw(6) << setprecision(2) << point.y << ")" << endl;
		}
	}
	else
		cout << "Recta 2 paralela al eje X--> y = " 
		     << setw(6) << setprecision(2) << (-recta_2.C/recta_2.B) << endl;
	cout << endl;	
				
					 		
	// c) Escribir la ecuación explícita de las dos rectas
	
	if (recta_1.B != 0) {
		cout << "Recta 1: " << endl;
		EcuacionExplicita (recta_1);
		cout << endl;
		
		cout << endl;
		cout << "Recta 1: " 
		<< ExpresionEcuacionExplicita (recta_1) << endl;
		cout << endl;
	}
	
	if (recta_2.B != 0) {		
		cout << endl;
		cout << "Recta 2: " << endl;
		EcuacionExplicita (recta_2);
		cout << endl;
	
		cout << endl;
		cout << "Recta 2: " 
		<< ExpresionEcuacionExplicita (recta_2) << endl;
		cout << endl;
	}

	// d) Posición relativa de las dos rectas
	
	cout << endl;
	cout << "Las rectas son ";	
	
	if (Coincidentes (recta_1, recta_2)){
	                  
		cout << " COINCIDENTES" << endl;
		
	}
		 
	else 
	{
		if (Paralelas (recta_1, recta_2)){
		
			cout << " PARALELAS" << endl;
			
		}
			 
	
		else 
		{
			
		if (Secantes (recta_1, recta_2)){
		              
			cout << " SECANTES" << endl;
			
			// e) Cálculo del punto de corte
			
			punto_de_corte_rectas = PuntoDeCorte(recta_1, recta_2);
			
			cout << "Su punto de corte es: ("<< punto_de_corte_rectas.x <<", "
			     << punto_de_corte_rectas.y <<")";	
			cout << endl << endl;
			
		}
	
		}
	}
	
	// f) Determinación de la pertenencia de un punto a la primera recta.

	/* A continuación, amplío el main escribiendo código que lea un número 
	   indeterminado de puntos y nos diga si forman parte de la primera recta 
	   (finaliza cuando se escriba FIN al leer el valor de la coordenada x).
	*/
	
	string abcisa;
	bool fin = (abcisa == "FIN");
	
	cout << endl;
	cout << "A continuacion se procede a comprobar si un punto pertenece a"
	     << " la primera recta";
	do{
		cout << endl;
		cout << "Introduzca la abscisa del punto que desea comprobar: ";
		cin >> abcisa;
	
		
		if (!(fin)){
			
			point.x = stod(abcisa);
			cout << "Introduza la ordenada del punto a comprobar: ";
			cin >> point.y;
			
			if (PuntoPertenece (recta_1, point)){
				
				cout << "El punto (" << point.x << ", " << point.y
				<< ") pertenece a la recta 1";
			}
		}
	}
	while (!(fin));

	return 0;
	
/******************************************************************************/
	return 0;
}

/***************************************************************************/
/***************************************************************************/
		
