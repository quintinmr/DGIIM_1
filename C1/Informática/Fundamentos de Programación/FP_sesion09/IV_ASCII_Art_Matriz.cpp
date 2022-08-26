/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que 

   Entradas: 
    
    
   Salidas:
    
     
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <cmath>       //Inclusión de los recursos matemáticos 
using namespace std;  
 
/******************************************************************************/


	/* Defino el struct Punto2D, pues los datos de las coordenadas van a
     a ser de ese tipo (van a tener una abcisa y una ordenada en el origen)
    */ 
    
struct Punto2D {

	int x;
	int y;

};

/******************************************************************************/
    
struct Elementomatriz {

	int fila;
	int columna;

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

bool PerteneceAlCirculo (Circunferencia circulo, Punto2D punto)
{
	int dist_centro_punto_x = pow(punto.x - circulo.centro.x, 2);
	int dist_centro_punto_y = pow(punto.y - circulo.centro.y, 2);
	int dist_centro_punto = dist_centro_punto_x + dist_centro_punto_y;
	
	return (pow(circulo.radio, 2) >= dist_centro_punto);
}

/******************************************************************************/

bool PerteneceAlRectangulo (Rectangulo rec, Punto2D punto)
{
	bool x = (punto.x>=rec.sup_izda.x && punto.x<=rec.inf_dcha.x);
	bool y = (punto.y<=rec.sup_izda.y && punto.y>=rec.inf_dcha.y);
	
	return (x && y);
}
/******************************************************************************/

int main ()
{
	
	// DECLARACIÓN DE LOS DATOS
	
	// Datos de entrada
	
	Circunferencia circulo;
	Rectangulo rectangulo;
	
	// Declaración de constantes
	
	const char PUNTO     = '.';
	const char ASTERISCO = '*';
	const char CRUZ      = 'x';
	
	const int NUM_FILAS  = 51;
	const int NUM_COLS   = 51;
	
	char tablero [NUM_FILAS][NUM_COLS];
	
	double ancho;
	double alto;
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca el centro del circulo que desea representar: ";
	
	cout << endl;
	
	cout << "\tAbcisa centro: ";
	cin  >> circulo.centro.x;
	cout << "\tOrdenada centro: ";
	cin  >> circulo.centro.y;
	
	cout << "Introduzca el radio del circulo que desea representar: ";
	cin  >> circulo.radio;
	
	// Representación del círculo
	
	Punto2D point;
	
	for (point.y = 0; point.y < NUM_FILAS; point.y++){
		
		for (point.x = 0; point.x < NUM_COLS; point.x++){
			
			if (PerteneceAlCirculo (circulo, point))
				
				tablero [point.y][point.x] = ASTERISCO;
				
			else tablero[point.y][point.x] = PUNTO;
		}
		
	}
	
	for (int i = NUM_FILAS -1; i>=0; i--){
		
		for (int j = 0; j < NUM_COLS; j++){
			
			cout << tablero[i][j];
		}
		
		cout << endl;
	}
	

	// Representación del rectángulo
	
	cout << "Introduzca la esquina superior izquierda del rectangulo: ";
	cout << endl;
	cout << "\tIntroduzca la abcisa: ";
	cin  >> rectangulo.sup_izda.x;
	cout << endl;
	cout << "\tIntroduzca la ordenada: ";
	cin  >> rectangulo.inf_dcha.y;
	
	cout << endl;
	
	cout << "Introduzca la esquina inferior derecha del rectangulo: ";
	cout << endl;
	cout << "\tIntroduzca la abcisa: ";
	cin  >> rectangulo.inf_dcha.x;
	cout << endl;
	cout << "\tIntroduzca la ordenada: ";
	cin  >> rectangulo.inf_dcha.y;
	
	cout << endl;
	
	for (point.y = 0; point.y < NUM_FILAS; point.y++){
		
		for (point.x = 0; point.x < NUM_COLS; point.x++){
			
			if (PerteneceAlRectangulo(rectangulo, point)){
			
				tablero[point.y][point.x] = ASTERISCO;
				
				if (PerteneceAlCirculo(circulo, point)){
					
					tablero[point.y][point.x] = CRUZ;
				}
			}
		}
	}
	
	for (int i = NUM_FILAS-1; i >= 0; i--){
		
		for (int j = 0; j < NUM_COLS; j++){
			
			cout << tablero[i][j];
		}
		
		cout << endl;
	}
	
/******************************************************************************/	
	return 0;
}
			

				
				
