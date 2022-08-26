/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee una cantidad indeterminada de puntos del plano R2, de
   manera que su lectura termina cuando el usuario introduce el TERMINADOR
   (FIN), en el momento en el el programa pide la abcisa de un nuevo punto.
   Todos estos objetos se almacenan en un objeto ColeccionPuntos2D.
   Adem�s, el programa pide las caracter�sticas que definen una circunferencia
   de manera que se crea una circunferencia y el programa calcula los puntos
   le�dos que est�n contenidos en dicha circunferencia (uso del m�todo Contiene
   de la clase Circunferencia, la cual se ha plasmado en este programa).
   Para que haga esto �ltimo, dentro de la clase ColeccionPuntos2D (tiene como
   datos miembro un vector de Puntos2D (para ello se ha copiado la clase 
   Puntos2D, ya trabajada), se ha definido un m�todo: 
   ColeccionPuntos2D ContenidosEnCircunferencia (Circunferencia circunf), que
   devuelve los puntos 2D tales que est�n contenidos en la circunferencia 
   definida por el usuario.

   Entradas: 
    Una sucesi�n indeterminada de puntos de R2 (cada uno definido por su 
    abcisa y su ordenada).
    Una circunferencia (con su centro (abcisa, ordenada), y su radio.
      
   Salidas:
    Los puntos de los que se hab�an introducido que estan contenidos en la
    circunferencia.
   	
   
    
*/               
/******************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
/***************************************************************************/
// Funci�n global (asociada a la constante PRECISION_SON_IGUALES) que
// permite que dos n�meros reales muy pr�ximos sean considerados iguales.

const double PRECISION_SON_IGUALES = 1e-6; // 0.000001

bool SonIguales(double uno, double otro) 
{
	return (fabs(uno-otro) <= PRECISION_SON_IGUALES);
}

/////////////////////////////////////////////////////////////////////////////

class Punto2D
{
private:
	
	// La pareja (x,y) son las coordenadas de un punto en un espacio 2D
	double x;
	double y;

public:
	
	/***********************************************************************/
	Punto2D (void) : x(0), y(0) {}
	
	// Constructor con argumentos.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// respectivamente del punto que se est� creando.
	
	Punto2D (double abscisaPunto, double ordenadaPunto)
	{
		SetCoordenadas (abscisaPunto, ordenadaPunto);
	}

	/***********************************************************************/
	// M�todo Set para fijar simultaneamente las coordenadas. 
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// respectivamente del punto que se est� modificando.
	
	void SetCoordenadas (double abscisaPunto, double ordenadaPunto)
	{
		x = abscisaPunto;
		y = ordenadaPunto;
	}

	/***********************************************************************/
	// M�todos Get para leer las coordenadas

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
	// Recibe: otro, el punto que se quiere comparar con el objeto impl�cito. 
	// Devuelve: true, si se consideran iguales los dos objetos. 

	bool EsIgual (Punto2D otro)
	{
		return (SonIguales(x,otro.x) && SonIguales(y,otro.y));
	}

	/***********************************************************************/
	// Calcula la distancia Eucl�dea del punto (objeto impl�cito) a otro que 
	// se recibe como argumento. 
	//
	// Recibe: otro, el punto respecto al cual que se quiere calcular la 
	// distancia eucl�dea.
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
// La clase "Circunferencia" representa circunferencias, objetos geom�tricos 
// que verifican la propiedad de que los puntos (x,y) que la forman est�n a 
// la misma distancia de otro punto (el centro).

class Circunferencia
{
private:

	// La constante "PI" es com�n a todos los objetos de la clase.
	static const double PI;		
	
	// Centro de la circunferencia
	Punto2D centro;	
	
	// Longitud del radio
	// PRE: radio >= 0
	double  radio;	

public:

	/***********************************************************************/
	// Constructor con argumentos
	// Recibe:
	//		el_centro, el punto central de la circunferencia. 
	//		radio, el valor del radio.
	// PRE: radio >= 0

	Circunferencia (Punto2D el_centro, double el_radio) : centro (el_centro)
	{
		// Observad c�mo se ha iniciado "centro": como es de clase "Punto2D"
		// se ha empleado la lista de iniciaci�n para que act�e el constructor
		// de la clase "Punto2D" 
		 
		radio  = el_radio; 
	}

	/***********************************************************************/
	// M�todos Get
	
	// Devuelve el punto central de la circunferencia
	Punto2D GetCentro (void)
	{
		return (centro);
	}

	// Devuelve el radio de la circunferencia
	double GetRadio (void)
	{
		return (radio);
	}

	// Devuelve el di�metro de la circunferencia
	double GetDiametro (void)
	{
		return (radio*2);
	}

	/***********************************************************************/
	// Calcula la longitud de la circunferencia

	double Longitud (void)
	{
		return (2.0 * PI * radio);
	}

	/***********************************************************************/
	// Calcula el �rea del c�rculo
	
	double Area (void)
	{
		return (PI * radio * radio);
	}

	/***********************************************************************/
	// Calcular si la circunferencia contiene a un punto dado.
	//
	// Recibe: un_punto, el punto del que se quiere evaluar su pertenencia. 
	/*
		Un punto (x, y) est� dentro de una circunferencia con 
		centro (x_0, y_0) y radio r si se verifica que:
			(x-0 - x)^2 + (y_0 - y)^2 <= r^2
	*/
	/*
	bool Contiene (Punto2D un_punto)
	{
		double dif_x = pow (centro.GetX() - un_punto.GetX(), 2);
		double dif_y = pow (centro.GetY() - un_punto.GetY(), 2);
		return (dif_x + dif_y <= radio*radio);
	}
	*/
	/***********************************************************************/
	// Calcular si la circunferencia contiene a un punto dado usando un 
	// test expl�cito sobre la distancia Eucl�dea del centro de la 
	// circunferencia al punto.
	//
	// Recibe: un_punto, el punto del que se quiere evaluar su pertenencia. 
	/*
		Un punto P(x, y) est� dentro de una circunferencia con centro 
		C(x_0, y_0) y radio r si DistaciaEuclidea (P, C) <= r
	*/
	// Esta implementaci�n es preferible a la anterior ya que no requiere 
	// duplicar (aunque sea de manera indiirecta) el c�digo referido al 
	// c�lculo de la distancia entre dos puntos. 
	
	bool Contiene (Punto2D un_punto)
	{
		Punto2D el_centro = GetCentro();
		double distancia = el_centro.DistanciaEuclidea (un_punto);
		return (distancia <= radio);
	}

	/***********************************************************************/
};

const double Circunferencia :: PI = 3.1415926;

/////////////////////////////////////////////////////////////////////////////

class ColeccionPuntos2D
{
	
private:
	
	static const int MAX = 100;
	Punto2D puntos [MAX];
	
	int total_utilizados;
	
public:
	
	// Constructor sin argumentos
	
	ColeccionPuntos2D (void): total_utilizados(0) {}
	
	/***********************************************************************/
    // Devuelve el n�mero de casillas ocupadas

    int TotalUtilizados (void)
    {
        return (total_utilizados);
    }
	/***********************************************************************/
    // Devuelve el n�mero de casillas disponibles

    int Capacidad (void)
    {
        return (MAX);
    }

    /***********************************************************************/
    // A�ade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // 		La adici�n se realiza si hay alguna casilla disponible.
    // 		El nuevo elemento se coloca al final del vector.
    // 		Si no hay espacio, no se hace nada.

   void Aniade (Punto2D nuevo)
    {
        if (total_utilizados < MAX){
            puntos[total_utilizados] = nuevo;
            total_utilizados++;
        }
    }

    /***********************************************************************/
    // Devuelve el elemento de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados

    Punto2D Elemento (int indice)
    {
        return (puntos[indice]);
    }

    /***********************************************************************/
    string ToString()
    {
        string cadena;

        for (int i=0; i<total_utilizados; i++)
            cadena = cadena + puntos[i].ToString();

        return (cadena);
    }
	/***********************************************************************/
	// M�todo destinado a calcular los puntos de una colecci�n de puntos que
	// est�n contenidos en una circunferencia determinada.
	// Se recorre el vector de puntos 2D en el que se encuentran guardados los
	// puntos y si alguno de ellos esta contenido en la circunferencia, se
	// a�ade a la nueva colecci�n de puntos definida "contenidos" en la que 
	// se guardar�n todos los puntos 2D de esas caracter�sticas.
	
	ColeccionPuntos2D ContenidosEnCircunferencia (Circunferencia circunf)
	{
		ColeccionPuntos2D contenidos;
		
		for (int i = 0; i < total_utilizados; i++){
			
			if (circunf.Contiene(puntos[i]))
			{
				contenidos.Aniade(puntos[i]);
				
			}
		}
		
		return (contenidos);
		
	}
    
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
	
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
		
		// M�todo Set para fijar el campo "titulo"
		
		void SetTitulo (string cad)
		{
			titulo = cad;
		}
		
		/*********************************************************************/
		// Lee un dato int.
		// La lectura est� etiquetada con "titulo"
		// La lectura se efect�a repetidamente hasta que se introduce un valor
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
		// La lectura est� etiquetada con "titulo"
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
		// La lectura est� etiquetada con "titulo"
		
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
		// La lectura est� etiquetada con "titulo"
		// La lectura se efect�a repetidamente hasta que se introduce un valor
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
		// La lectura est� etiquetada con "titulo"
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
		// La lectura est� etiquetada con "titulo"
		
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
		// Devuelve una NUEVA cadena, resultante de eliminar los �ltimos
		// caracteres separadores de "cadena". Los caracteres separadores son
		// el espacio en blanco, el tabulador y el salto de l�nea.
		// Usaremos la funci�n isspace() para simplificar el c�lculo.
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: el resultado de eliminar los �ltimos separadores de 
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
		// el espacio en blanco, el tabulador y el salto de l�nea.
		// Usaremos la funci�n isspace() para simplificar el c�lculo.
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: el resultado de eliminar los �ltimos separadores de 
		// "cadena"
		/*********************************************************************/
		string EliminaPrimerosSeparadores (string cadena)
		{
			// Buscar el primer car�cter no espacio
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
		// �ltimos caracteres separadores de "cadena". Los caracteres 
		// separadores son el espacio en blanco, el tabulador y el salto de
		// l�nea
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: el resultado de eliminar los primeros y los �ltimos
		//           separadores de "cadena".
		/*********************************************************************/
		
		string EliminaPrimerosYUltimosSeparadores (string cadena)
		{
			string cadena_podada = EliminaPrimerosSeparadores (cadena);
			cadena_podada = EliminaUltimosSeparadores (cadena_podada);
			
			return (cadena_podada);
		}
		
		/*********************************************************************/
		// Devuelve "true" si "cadena" es la representaci�n textual de un
		// entero
		//
		// Recibe: cadena, string sobre la que se va a trabajar.
		// Devuelve: "true" si "cadena" es la representaci�n textual de un int
		
		bool EsEntero (string cadena)
		{
			bool es_entero = true;
			
			cadena = EliminaPrimerosSeparadores (cadena);
			cadena = EliminaUltimosSeparadores (cadena);
			
			unsigned int long_cadena = cadena.length();
			
			if (long_cadena == 0) es_entero = false;
			else {
				
				// Si el primer car�cter es '+' � '-', perfecto. En ese caso
				// se pasa al siguiente car�cter (posici�n 19.
				
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
				
				// Si el primer car�cter es '+' � '-', perfecto. En ese caso
				// se pasa al siguiente car�cter (posici�n 19.
				
				unsigned int pos;
				if (cadena.at(0)=='-' || cadena.at(0) == '+') pos = 1;
				else pos = 0;
				
				// Bandera que se activa al encontrar un punto
				bool encontrado_un_punto = false;
				
				while ((pos < long_cadena) && es_real) {
					
					char c = cadena.at(pos);
					
					if (!isdigit(c)) {
						
						// Solo puede haber un punto.
						// Si se ha encontrado un punto y ya se hab�a
						// encontrado otro, error. Si no, activar la bandera
						// "encontrado_un_punto" (ya no puede haber m�s).
						
						if (c == '.') {
							if (encontrado_un_punto) es_real = false;
							else encontrado_un_punto = true;
						}
						
					    // Si no es un punto ni un d�gito --> error
						else es_real = false;
					}
					
					pos++;
					
				}  // while ((pos < long_cadena) && es_real)
				
			}  // else de if (long_cadena == 0)
			
			return (es_real);
		}
		
		/*********************************************************************/

}; 

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////		


int main (void)
{
	
	const string TERMINADOR = "FIN";
	
	double coord_x;
	double coord_y;
	
	Lector lee;
	
	ColeccionPuntos2D coleccion;
	
	// Entrada de datos
	
	cout << "COLECCION DE PUNTOS DEL PLANO 2D";
	cout << endl;
	
	bool continua_leyendo = true;
	
	while ((coleccion.TotalUtilizados() < coleccion.Capacidad()) 
	       && continua_leyendo){
		
		string cadena_abcisa;
		
		cout << "\tIntroduzca la coordenada x de un punto: ";
		cin  >> cadena_abcisa;
		
		if (cadena_abcisa != TERMINADOR){
			
			coord_x = stod(cadena_abcisa);
		}
		
		else
		{
			continua_leyendo = false;
		}
		
		if (continua_leyendo){
			
			cout << "\tIntroduce la coordenada y de un punto: ";
			cin  >> coord_y;
		}
			
			Punto2D point (coord_x, coord_y);
			coleccion.Aniade(point);
		
		
	}
	
	// Se muestran los puntos introducidos
	
	cout << endl;	
	cout << coleccion.ToString();
	cout << endl;	
		
	// Creacion de la circunferencia
	
	double un_radio; 
	
	cout << endl;
	cout << "Introduzca las coordenadas del centro de una circunferencia: ";
	cout << endl;
	
	lee.SetTitulo ("\tCoordenada X del centro = ");
	coord_x = lee.LeeReal();

	lee.SetTitulo("\tCoordenada Y del centro = ");
	coord_y = lee.LeeReal(); 

	// Creamos un dato Punto2D y se rellenan las coordenadas con los 
	// valores leidos, para poder pasarlo al constructor de la 
	// clase Circunferencia

	Punto2D centro (coord_x, coord_y);
	
	// Aseguramos que se cumple la precondici�n sobre el radio

	lee.SetTitulo("\tIntroduzca el radio = ");
	un_radio = lee.LeeRealMayorOIgual(0); 
	

	// Creaci�n de un objeto circunferencia
	
	Circunferencia mi_circunferencia (centro, un_radio);
	
	// Tomamos el centro
	
	Punto2D center = mi_circunferencia.GetCentro();
	
	ColeccionPuntos2D contenidos;
	
	contenidos = coleccion.ContenidosEnCircunferencia(mi_circunferencia);
	
	// Salida de datos
	
	cout << endl;
	cout << "La circunferencia de centro " << center.ToString() << " y radio "
	     << un_radio << " contiene a los puntos: " << endl << endl
	     << contenidos.ToString();
	     
	return 0;     

	
}

		
	
