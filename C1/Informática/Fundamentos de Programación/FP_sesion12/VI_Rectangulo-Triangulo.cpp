/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee una secuencia de caracteres           *POR HACER*

   Entradas: 
    Una secuencia de caracteres.
    
   Salidas:
    Una secuencia de caracteres 
   	
   
    
*/               
/******************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
using namespace std;

////////////////////////////////////////////////////////////////////////////////

// Función global (asociada a la constante PRECISION_SON_IGUALES) que
// permite que dos números reales muy próximos sean considerados iguales.

const double PRECISION_SON_IGUALES = 1e-6; // 0.000001

bool SonIguales(double uno, double otro) 
{
	return (fabs(uno-otro) <= PRECISION_SON_IGUALES);
}

class Punto2D
{
private:
	
	// La pareja (x,y) son las coordenadas de un punto en un espacio 2D
	double x;
	double y;

public:
	
	/***********************************************************************/
	// Constructor con argumentos.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// respectivamente del punto que se está creando.
	
	Punto2D (double abscisaPunto, double ordenadaPunto)
	{
		SetCoordenadas (abscisaPunto, ordenadaPunto);
	}

	/***********************************************************************/
	// Método Set para fijar simultaneamente las coordenadas. 
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// respectivamente del punto que se está modificando.
	
	void SetCoordenadas (double abscisaPunto, double ordenadaPunto)
	{
		x = abscisaPunto;
		y = ordenadaPunto;
	}

	/***********************************************************************/
	// Métodos Get para leer las coordenadas

	double GetX (void)
	{
		return (x);
	}
	double GetY (void)
	{
		return (y);
	}

	/***********************************************************************/
	// Calcula si dos puntos son iguales 
	//
	// Recibe: otro, el punto que se quiere comparar con el objeto implícito. 
	// Devuelve: true, si se consideran iguales los dos objetos. 

	bool EsIgual (Punto2D otro)
	{
		return (SonIguales(x,otro.x) && SonIguales(y,otro.y));
	}

	/***********************************************************************/
	// Calcula la distancia Euclídea del punto (objeto implícito) a otro que 
	// se recibe como argumento. 
	//
	// Recibe: otro, el punto respecto al cual que se quiere calcular la 
	// distancia euclídea.
	// Devuelve: la distancia entre los dos puntos. 

	double DistanciaEuclidea (Punto2D otro)
	{
		double dif_x = pow (x - otro.x, 2);
		double dif_y = pow (y - otro.y, 2);

		return (sqrt(dif_x + dif_y));
	}

	/***********************************************************************/

	string ToString ()
	{
		return ("["+to_string(x)+", "+to_string(y)+"]");
	}
	
	/***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Triangulo
{
	
private: 

	Punto2D A;
	Punto2D B;
	Punto2D C;

	
public:
	
	/***********************************************************************/
	
	// Constructor con argumentos
	
	Triangulo (Punto2D vertice_a, Punto2D vertice_b, Punto2D vertice_c)
	
	: A(vertice_a), B(vertice_b), C(vertice_c) {}
	
	/***********************************************************************/		
	
	// Métodos get
	
	Punto2D GetA (void)
	{
		return (A);
	}
	
	Punto2D GetB (void)
	{
		return (B);
	}
	
	Punto2D GetC (void)
	{
		return (C);
	}
	
	/***********************************************************************/
	
	string ToString (void)
	{
		
		string cadena = ("Triangulo de vertices " + A.ToString() + ", " 
		                 + B.ToString() + ", " + C.ToString());
	
		return (cadena);
		
	}
	
	/***********************************************************************/	
	
	double Perimetro (void)
	{
		
		double perimetro;
		Punto2D punto1 = GetA();
		Punto2D punto2 = GetB();
		Punto2D punto3 = GetC();
		
		perimetro = (punto1.DistanciaEuclidea(punto2) + 
		             punto1.DistanciaEuclidea(punto3) +
		             punto2.DistanciaEuclidea(punto3));
		             
		return (perimetro);
		
	}
	
	/***********************************************************************/	
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Rectangulo
{
	
private:

	Punto2D esquina_sup_izda;
	
	// PRE: 0 <= base, 0 <= altura
	double base;
	double altura;
	
public: 
		
	/***********************************************************************/
		
	// Constructor con argumentos
	
	Rectangulo (Punto2D esqu_sup_izda, double b, double h)
	: esquina_sup_izda(esqu_sup_izda) 
	{
		base = b;
		altura = h; 
	}
	
	/***********************************************************************/	
	// Métodos get
	
	Punto2D GetEsquina (void)
	{
		return (esquina_sup_izda);
	}
	
	double GetBase (void)
	{
		return (base);
	}
	
	double GetAltura (void)
	{
		return (altura);
	}
	
	/***********************************************************************/
	
	string ToString (void)
	{
		string cadena = "El rectángulo introducido es el de base " + 
		                to_string (base) + ", altura " + to_string (altura)
		                + " y esquina superior izquierda "
		                + esquina_sup_izda.ToString();
		                
		return (cadena);                
		
	}
	
	/***********************************************************************/
	
	double Area (void)
	{
		double area;
		
		if ((altura >= 0) && (base >= 0)) area = (base*altura);
		
		return (area);
	}
	
	/***********************************************************************/
	
	double Perimetro (void)
	{
		double perimetro;
		
		if ((altura >= 0) && (base >= 0)) perimetro = (2*base + 2*altura);
		
		return (perimetro);
	}
	
	/***********************************************************************/
	
	double Diagonal (void)
	{
		double la_base = GetBase();
		double la_altura = GetAltura();
		
		Punto2D el_punto (esquina_sup_izda.GetX() + la_base,
		                  esquina_sup_izda.GetY() - la_altura);
		                  
		double diagonal = esquina_sup_izda.DistanciaEuclidea(el_punto);
		
		return (diagonal);
		
	}
	
	/***********************************************************************/
	
	bool Contiene (Punto2D punto)
	{
		bool contiene;
		
		if ((punto.GetX() >= esquina_sup_izda.GetX()) && 
		    (punto.GetY() <= esquina_sup_izda.GetY()) &&
		    (punto.GetX() <= (esquina_sup_izda.GetX() +base) &&
		    (punto.GetY() >= (esquina_sup_izda.GetY() - altura))))
		    	
		    contiene = true;
			
		else contiene = false;
		
		return (contiene);
		
	}
	/***********************************************************************/
	
	Triangulo TrianguloInferior (void)
	{ 
		double x,y;
		
		Punto2D a (x,y);
		Punto2D b (x,y); 
		Punto2D c (x,y);
		
		Triangulo (a,b,c);
		
		if ((base>= 0) && (altura >= 0)){
	
	    	Punto2D esq_inf_dcha (esquina_sup_izda.GetX() + base,
							      esquina_sup_izda.GetY() - altura);
		                      
			Punto2D esq_inf_izda (esquina_sup_izda.GetX(),
			                      esq_inf_dcha.GetY());                       
	
			a = esquina_sup_izda;
			b = esq_inf_dcha;
			c = esq_inf_izda;
		}
		
		Triangulo inferior (a, b, c);
		
		return (inferior);
		
	}
	
	/***********************************************************************/
	
	Triangulo TrianguloSuperior (void)
	{
		
		double x,y;
		
		Punto2D a (x,y);
		Punto2D b (x,y); 
		Punto2D c (x,y);
		
		Triangulo (a,b,c);
		
		if ((base >= 0) && (altura >= 0)){
		
		    Punto2D esq_inf_izda (esquina_sup_izda.GetX(),
			                      esquina_sup_izda.GetY() - altura);
		                      
			Punto2D esq_sup_dcha (esquina_sup_izda.GetX() + base, 
			                      esquina_sup_izda.GetY());                     
	
			 a = esquina_sup_izda;
			 b = esq_inf_izda;
			 c = esq_sup_dcha;
		}
		
		Triangulo superior (a, b, c);
		
		return (superior);
		
	}
	/***********************************************************************/
	
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Lector
{
	private:
		
		string titulo;
	
	public:
		
		// Constructor sin argumentos
		
		Lector (void) : titulo ("")
		{ }
		
		// Constructor con argumentos
		
		Lector (string cad) : titulo (cad)
		{ }
		
		// Método Set para fijar el campo "titulo"
		
		void SetTitulo (string cad)
		{
			titulo = cad;
		}
		
		/*********************************************************************/
		// Lee un dato int.
		// La lectura está etiquetada con "titulo"
		// La lectura se efectúa repetidamente hasta que se introduce un valor
		// int correcto.
		
		int LeeEntero (void)
		{
			string cadena;
			
			do{
				cout << titulo;
				getline(cin, cadena);
			}
			while (!EsEntero(cadena));
			
			return (stoi(cadena));
		}
		
		/*********************************************************************/
		// Lee un dato int.
		// La lectura está etiquetada con "titulo"
		// PRE: menor <= mayor
		// POST: menor <= valor devuelto <= mayor
		
		int LeeEnteroEnRango (int menor, int mayor)
		{
			int numero;
			
			do{
				
				numero = LeeEntero ();
			}
			while ((numero<menor) || (numero>mayor));
			
			return (numero);
		}
		
		/*********************************************************************/
		// Lee un dato int que debe ser mayor o igual que "menor" y lo devuelve.
		// La lectura está etiquetada con "titulo"
		
		int LeeEnteroMayorOIgual (int menor)
		{
			int numero;
			
			do{
				numero = LeeEntero ();
			}
			while (numero < menor);
			
			return (numero);
		}
		
		/*********************************************************************/
		// Lee un dato double.
		// La lectura está etiquetada con "titulo"
		// La lectura se efectúa repetidamente hasta que se introduce un valor
		// double correcto.
		
		double LeeReal (void)
		{
			string cadena;
			
			do{
				cout << titulo;
				getline(cin, cadena);
			}
			while (!EsReal(cadena));
			
			return (stod(cadena));
		}
		
		/*********************************************************************/
		// Lee un dato double.
		// La lectura está etiquetada con "titulo"
		// PRE: menor <= mayor
		// POST: menor <= valor devuelto <= mayor
		
		double LeeRealEnRango (int menor, int mayor)
		{
			double numero;
			
			do{
				
				numero = LeeReal ();
			}
			while ((numero<menor) || (numero>mayor));
			
			return (numero);
		}

		/*********************************************************************/
		// Lee un dato double que debe ser mayor o igual que "menor" y lo 
		// devuelve. 
		// La lectura está etiquetada con "titulo"
		
		double LeeRealMayorOIgual (int menor)
		{
			double numero;
			
			do{
				numero = LeeReal ();
			}
			while (numero < menor);
			
			return (numero);
		}

		/*********************************************************************/
	
	private:
		
		/*********************************************************************/
		// Devuelve una NUEVA cadena, resultante de eliminar los últimos
		// caracteres separadores de "cadena". Los caracteres separadores son
		// el espacio en blanco, el tabulador y el salto de línea.
		// Usaremos la función isspace() para simplificar el cálculo.
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: el resultado de eliminar los últimos separadores de 
		// "cadena"
		/*********************************************************************/
		
		string EliminaUltimosSeparadores (string cadena)
		{
			while (cadena.length()>0 && isspace(cadena.back()))
				cadena.pop_back();
			
			return (cadena);
		}
		
		/*********************************************************************/
		// Devuelve una NUEVA cadena, resultante de eliminar los primeros
		// caracteres separadores de "cadena". Los caracteres separadores son
		// el espacio en blanco, el tabulador y el salto de línea.
		// Usaremos la función isspace() para simplificar el cálculo.
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: el resultado de eliminar los últimos separadores de 
		// "cadena"
		/*********************************************************************/
		string EliminaPrimerosSeparadores (string cadena)
		{
			// Buscar el primer carácter no espacio
			unsigned int pos = 0;
			while (pos < cadena.length() && isspace(cadena.at(pos))) pos++;
			
			string local;
			
			// Copiar todos los que quedan
			while (pos < cadena.length()) {
				local.push_back(cadena.at(pos));
				pos++;
			}
			
			return (local);
		}
		
		/*********************************************************************/
		// Devuelve una NUEVA cadena, resultante de eliminar los primeros 
		// últimos caracteres separadores de "cadena". Los caracteres 
		// separadores son el espacio en blanco, el tabulador y el salto de
		// línea
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: el resultado de eliminar los primeros y los últimos
		//           separadores de "cadena".
		/*********************************************************************/
		
		string EliminaPrimerosYUltimosSeparadores (string cadena)
		{
			string cadena_podada = EliminaPrimerosSeparadores (cadena);
			cadena_podada = EliminaUltimosSeparadores (cadena_podada);
			
			return (cadena_podada);
		}
		
		/*********************************************************************/
		// Devuelve "true" si "cadena" es la representación textual de un
		// entero
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: "true" si "cadena" es la representación textual de un int
		
		bool EsEntero (string cadena)
		{
			bool es_entero = true;
			
			cadena = EliminaPrimerosSeparadores (cadena);
			cadena = EliminaUltimosSeparadores (cadena);
			
			unsigned int long_cadena = cadena.length();
			
			if (long_cadena == 0) es_entero = false;
			else {
				
				// Si el primer carácter es '+' ó '-', perfecto. En ese caso
				// se pasa al siguiente carácter (posición 19.
				
				unsigned int pos;
				if (cadena.at(0)=='-' || cadena.at(0) == '+') pos = 1;
				else pos = 0;
				
				while ((pos < long_cadena) && es_entero) {
					if(!isdigit(cadena.at(pos))) es_entero = false;
					else pos++;
				}
			}
			
			return (es_entero);
		}
		
		/*********************************************************************/

		bool EsReal (string cadena)
		{
			bool es_real = true;
			
			cadena = EliminaPrimerosSeparadores (cadena);
			cadena = EliminaUltimosSeparadores (cadena);
			
			unsigned int long_cadena = cadena.length();
			
			if (long_cadena == 0) es_real = false;
			else {
				
				// Si el primer carácter es '+' ó '-', perfecto. En ese caso
				// se pasa al siguiente carácter (posición 19.
				
				unsigned int pos;
				if (cadena.at(0)=='-' || cadena.at(0) == '+') pos = 1;
				else pos = 0;
				
				// Bandera que se activa al encontrar un punto
				bool encontrado_un_punto = false;
				
				while ((pos < long_cadena) && es_real) {
					
					char c = cadena.at(pos);
					
					if (!isdigit(c)) {
						
						// Solo puede haber un punto.
						// Si se ha encontrado un punto y ya se había
						// encontrado otro, error. Si no, activar la bandera
						// "encontrado_un_punto" (ya no puede haber más).
						
						if (c == '.') {
							if (encontrado_un_punto) es_real = false;
							else encontrado_un_punto = true;
						}
						
					    // Si no es un punto ni un dígito --> error
						else es_real = false;
					}
					
					pos++;
					
				}  // while ((pos < long_cadena) && es_real)
				
			}  // else de if (long_cadena == 0)
			
			return (es_real);
		}
		
		/*********************************************************************/

}; 

	
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
	
int main (void)
{
    cout.setf(ios::fixed);        // Notación de punto fijo para los reales
    cout.setf(ios::showpoint);    // Mostrar siempre decimales 

	// Datos de entrada rectangulo
	
	double abcisa_esquina, ordenada_esquina;
	double base_rect, altura_rect;
	
	Lector lee;
	
	
	// Entrada de datos
	
	cout << "Introduzca la esquina superior derecha del rectangulo: ";
	cout << endl;
	
	lee.SetTitulo("\tIntroduzca la abcisa de la esquina superior izquierda: ");
	abcisa_esquina = lee.LeeReal();
	
	lee.SetTitulo("\tIntroduzca la ordenada de la esquina superior izquierda: ");
	ordenada_esquina = lee.LeeReal();
	
	Punto2D esquina_superior_izda (abcisa_esquina, ordenada_esquina);
	
	cout << endl; 
	
	lee.SetTitulo ("Introduzca la base del rectangulo: ");
	base_rect = lee.LeeRealMayorOIgual(0);
	
	lee.SetTitulo("Introduzca la altura del rectangulo: ");
	altura_rect = lee.LeeRealMayorOIgual(0);
	
	
	
	// Crear un rectángulo
	
	Rectangulo rectangulo (esquina_superior_izda, base_rect, altura_rect); 
	
	cout << endl;
	cout << "Rectangulo:" << endl;
    cout << rectangulo.ToString()<< endl;

    cout << "Area = " << rectangulo.Area() << "unidades cuadradas" << endl;
    cout << "Perimetro = " << rectangulo.Perimetro() << " unidades" << endl;
    cout << endl << endl;
    
    // Pruebas de pertenencia a un rectángulo
    
    double abcisa_punto, ordenada_punto;
    

    
    cout << "Pertenencia a Rectangulo: " << endl;
    	
    lee.SetTitulo("\tIntroduzca la abcisa de un punto: ");
    abcisa_punto = lee.LeeReal();
    	
    cout << endl;
    	
    lee.SetTitulo("\tIntroduzca la ordenada de un punto: ");
    ordenada_punto = lee.LeeReal();
    	
    Punto2D point (abcisa_punto, ordenada_punto);
	
	cout << endl;  
    cout << (point.ToString()) << " --> " 
         << ((rectangulo.Contiene (point)) ? "SI":"NO") << endl;
         
	
	
	cout << endl;
	
	double abcisa_a, abcisa_b, abcisa_c;
	double ordenada_a, ordenada_b, ordenada_c;
	
	cout << "Introduzca los vertices de un trinagulo: ";
	cout << endl;
	
	lee.SetTitulo ("\tIntroduzca la abcisa del vertice A: ");
    abcisa_a = lee.LeeReal();
	
	lee.SetTitulo("\tIntroduzca la ordenada del vertice A: ");
    ordenada_a = lee.LeeReal();
	
	Punto2D vertice_a (abcisa_a, ordenada_a);
	
	lee.SetTitulo( "\tIntroduzca la abcisa del vertice B: ");
    abcisa_b = lee.LeeReal();
    
    lee.SetTitulo("\tIntroduzca la ordenada del vertice B: ");
    ordenada_b = lee.LeeReal();
	
	Punto2D vertice_b (abcisa_b, ordenada_b);
	
	lee.SetTitulo("\tIntroduzca la abcisa del vertice C: ");
    abcisa_c = lee.LeeReal();
	
	lee.SetTitulo("\tIntroduzca la abcisa del vertice C: ");
    ordenada_c = lee.LeeReal();
	
	Punto2D vertice_c (abcisa_c, ordenada_c);
	
	// Crear triangulo
	
	Triangulo triangulo (vertice_a, vertice_b, vertice_c);
	
	cout << "Triangulo:" << endl;
    cout << triangulo.ToString() << endl;        
    cout << "Perimetro = " << triangulo.Perimetro() << endl;    
    cout << endl << endl;    
    
    // Crear otro triángulo    (rectángulo)
    
    double abcisa_otra_a, abcisa_otra_b, abcisa_otra_c;
	double ordenada_otra_a, ordenada_otra_b, ordenada_otra_c;
	
	cout << "Introduzca los vertices de un triangulo rectangulo: ";
	cout << endl;
	cout << "RECUERDE que un triangulo rectangulo deber de tener unos vertices"
	        " tales que dos de ellos tengan la misma abcisa, y dos de ellos la"
	        " misma ordenada";
	        
	cout << endl;        
	
	lee.SetTitulo("\tIntroduzca la abcisa del vertice A: ");
    abcisa_otra_a = lee.LeeReal();
	
	lee.SetTitulo("\tIntroduzca la ordenada del vertice A: ");
    ordenada_otra_a = lee.LeeReal();
	
	Punto2D vertice_otro_a (abcisa_otra_a, ordenada_otra_a);
	
	lee.SetTitulo("\tIntroduzca la abcisa del vertice B: ");
    abcisa_otra_b = lee.LeeReal();
    
    lee.SetTitulo("\tIntroduzca la ordenada del vertice B: ");
    ordenada_otra_b = lee.LeeReal();
	
	Punto2D vertice_otro_b (abcisa_otra_b, ordenada_otra_b);
	
	lee.SetTitulo("\tIntroduzca la abcisa del vertice C: ");
    abcisa_otra_c = lee.LeeReal();
	
	lee.SetTitulo("\tIntroduzca la abcisa del vertice C: ");
    ordenada_otra_c = lee.LeeReal();
	
	Punto2D vertice_otro_c (abcisa_otra_c, ordenada_otra_c);
	
	// Creacion del triangulo rectangulo
	
	Triangulo tr_rect (vertice_otro_a, vertice_otro_b, vertice_otro_c);
	 
	cout << "Triangulo rectangulo:" << endl;    
    cout << tr_rect.ToString() << endl;    
    cout << endl << endl;
    
    // Crear un triángulo a partir de un rectángulo (triángulo inferior) 
    Triangulo t_inf = rectangulo.TrianguloInferior();

    cout << "Triangulo inferior del rectangulo:" << endl;    
    cout << t_inf.ToString() << endl;    
    cout << endl << endl;
    
    // Crear otro triángulo a partir de un rectángulo (triángulo superior) 
    Triangulo t_sup = rectangulo.TrianguloSuperior();

    cout << "Triangulo superior del rectangulo:" << endl;    
    cout << t_sup.ToString() << endl;    
    cout << endl << endl;
    
        
    return 0;
}
