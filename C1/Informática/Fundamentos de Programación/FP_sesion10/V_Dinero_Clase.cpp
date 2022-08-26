/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que calcula el precio final de un producto a partir de su precio
   inicial, de un incremento fijo, que se estar� aplicando durante un n�mero
   determinado de meses. El programa, me es mes, ir� mostrando el precio del
   producto.

   Entradas:
    Precio inicial del producto (en euros y c�ntimos).
    Incremento mensual (real).
    N�mero de meses (entero) durante los que se va a estar aplicando el 
    incremento.
    
   Salidas:
    Precio del producto mese a mes.
       
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;  
 
/******************************************************************************/

	/* He definidido las siguientes funciones ya que las voy a emplear en la
	   entrada de datos, para as� filtrar los datos, sin necesidad de establecer
	   ciclos post test en el main, quedando as� el c�digo mas limpio.
	   Adem�s, he definido una funci�n LeeDouble para leer y filtrar datos de
	   tipo real, como es en este caso el incremento mensual.
	*/   
	   
bool EsEntero (string cosa){

	
	int indice = 0;           // La posici�n inicial es cero
	char caracter_sub_indice; // Cualquier elemento de la cadena de caracteres

	
	if((cosa.at(0) == '-')|| (cosa.at(0) == '+')){     
	                            
		
		indice = (indice + 1);  // Acutalizo el indice variando
	
	}
	
	
	bool entero_ok = true;
	   
	while(entero_ok && (indice < cosa.length())){
		
		 caracter_sub_indice = cosa.at(indice);
		 	
		entero_ok = (caracter_sub_indice >= '0' && caracter_sub_indice <='9')||
					caracter_sub_indice == ' ';
		
		indice = (indice + 1);   // Actualizo el �ndice.
		
	}
	
	return entero_ok; 	
}

int LeeEntero (string titulo){
	
	string numero;   // Cadena a introducir por el usuario
	
	bool cadena_ok;  
	   
	do{
		
		cout<< titulo;
		cin >> numero;
		
		cadena_ok = EsEntero(numero);
		
	}while(!cadena_ok);
	
	    
	return stoi(numero);
}


/******************************************************************************/
	   
int LeeEnteroMayorOIgual (string titulo, int referencia)
{
	int numero_entero;    
	
	do {
		
		numero_entero = LeeEntero(titulo);	
			
	} while (numero_entero < referencia);
	
	
	return numero_entero;	
}

/******************************************************************************/

bool EsDouble (string cosa)
{

	int indice = 0;           // La posici�n inicial es cero
	char caracter_sub_indice; // Cualquier elemento de la cadena de 
							  //caracteres

		int contador_puntos = 0;
		
		bool double_ok = true;
	
		if(((cosa.at(0) == '-')|| (cosa.at(0) == '+')) && (cosa.at(0) != '.')){     
	                            
		
			indice = (indice + 1);  // Acutalizo el indice variando
	
		}
	
		if (cosa.at(0) == '.')
		
			double_ok = false;
	
		while(double_ok && (indice < cosa.length())){
		
		 	caracter_sub_indice = cosa.at(indice);
		 	
		 	double_ok = (((caracter_sub_indice >= '0' && 
			             caracter_sub_indice <='9') &&
						 (caracter_sub_indice != ' '))
						 || (caracter_sub_indice == '.'));
		 	
		 	if (caracter_sub_indice == '.')
		 	
		 		contador_puntos++;
		 		
		 		if (contador_puntos == 1)
		 		
		 			double_ok = true;
		 			
		 		if (contador_puntos > 1)
				 
				 	double_ok = false;	
		 	
		 		
			indice = (indice + 1);   // Actualizo el �ndice.
		
		}
	
		return double_ok; 	
	}

double LeeDouble (string titulo){
	
	string numero;   // Cadena a introducir por el usuario
	
	bool cadena_ok;  
	   
	do{
		
		cout<< titulo;
		cin >> numero;
		
		cadena_ok = EsDouble(numero);
		
	}while(!cadena_ok);
	
	    
	return stod(numero);
}


/******************************************************************************/
	   
double LeeDoubleMayorOIgual (string titulo, int referencia)
{
	double numero_real;    
	
	do {
		
		numero_real = LeeDouble(titulo);	
			
	} while (numero_real < referencia);
	
	
	return numero_real;	
}

/******************************************************************************/
	/**********************************************************************/
/******************************************************************************/

	/* A continuaci�n, defino una clase Dinero, constitu�da por dos datos
	   miembro, privados, un constructor y una serie de m�todos, de caracter 
	   p�blico y uno de car�cter privado que ser� el encargado de ajustar el 
	   dinero.
	*/   
	
class Dinero
{
	
private:
	
	// PRE: euros >= 0 
	int euros;
	
	// PRE: centimos >= 0
	int centimos;
	
public:

	// M�todos
	
	/***********************************************************************/
	
	// Constructor con argumentos
	// PRE: los euros y los c�ntimos han de ser n�meros enteros positivos.

	Dinero (int euros_I, int centimos_I) :
		
			euros (euros_I), centimos (centimos_I)
			
		{
			ReajustaDinero (euros, centimos);
		}
	
	/***********************************************************************/
    
    // M�todo para hallar el precio del producto al aplicarle el incremento
    
    void IncrementoPrecio (double incremento)
		{
			/* El razonamiento que he seguido es el siguiente:
			   Si el precio inicial es x euros e y centimos, al aplicarle
			   el incremento:  t.p euros,  el precio queda as�:
			   
			   	euros    = x + (parte entera de incremento (t))
			   	centimos = y + (el incremento como dato real, menos su parte
			   	           entera), multiplicado todo por 100.	           
			*/
			   	           
			euros = euros + int(incremento);
			
			centimos = centimos + (incremento - int(incremento))*100;
			
			// Ajusto el precio incrementado
			
			ReajustaDinero (euros, centimos);
			
		}
		
	/***********************************************************************/
		
	/* Defino un m�todo ToString, para que el precio del producto se muestre
	   en pantalla como una cadena de caracteres. Se usar� en la salida de datos
	*/   	
    
    string ToString(void)
	{
		
		string cadena;
		
		cadena = to_string(euros) + " euros y " + to_string(centimos)
		         + " centimos";
		
		return (cadena);
		
	}
		
	/***********************************************************************/
	
	/* A continuaci�n, defino un m�todo de car�cter privado, destinado al ajuste
	   del dinero. Con ajuste me refiero al establecimiento del dinero dentro
	   de su rango correspondiente
	*/   
	
private:
	 
	void ReajustaDinero (int euross, int centimoss)
	{
		const int CENTS_1_EURO = 100;
		
		euros    = (euross + (centimoss / CENTS_1_EURO));
		centimos = (centimoss% CENTS_1_EURO);
		
	}
	
   	/***********************************************************************/
	
};

/******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/******************************************************************************/

int main ()
{

	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 
	
	int euros_iniciales, centimos_iniciales, months;
	double increment;
	
	/***********************************************************************/	
	
	// Entrada de datos
	
	cout << "Introduzca el precio incial del producto:";
	cout << endl;
	cout << endl;
	
	euros_iniciales    = LeeEnteroMayorOIgual ("\t Euros: ", 0);
	
	centimos_iniciales = LeeEnteroMayorOIgual ("\t Centimos: ", 0);
	
	cout << endl;
	
	increment = LeeDoubleMayorOIgual ("Introduzca el incremento que desea "
									  "realizar al precio del producto: ", 0);
	
	months  = LeeEnteroMayorOIgual ("Introduzca el numero de meses durante los" 
								   " que quiere aplicar el aumento: ", 0);
	 
	
	// Creaci�n del objeto Dinero
	
	Dinero dinerito (euros_iniciales, centimos_iniciales); 
		
	// C�lculos y salida de datos
	
	cout << endl;
	cout <<"PRECIO DEL PRODUCTO";
	cout << endl;
	
	/* Para que el precio del producto se muestre mes a mes, he definido un 
	   ciclo for que se va a ir ejecutando s� y solo s� el �ndice variando es
	   menor o igual que el n�mero de meses que el usuario ha establecido.
	   El precio del dinero se muestra mediante el m�todo ToString.
	*/   
	
	for(int i = 1; i <= months ; i++){
		
		dinerito.IncrementoPrecio (increment);
		
		cout <<"\t Mes " << i << ": " << dinerito.ToString();
		cout << endl;
	}
				
	
/******************************************************************************/

return 0;	
}


		
		
