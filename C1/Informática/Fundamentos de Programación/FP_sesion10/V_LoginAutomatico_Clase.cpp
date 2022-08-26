/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que convierte una cadena de caracters consitituída por el nombre
   del usuario, en un nombre de usuario sugerido para un login automático.
   Dicho nombre de usuario sugerido dependerá del número de caracteres a coger;
   estará formado por los n primeros caracteres de cada una de las palabras del
   nombre.

   Entradas: 
    Una cadena de caracteres (el nombre completo del usuario)
    Los n caracteres a tener en cuenta para la formación del nombre de usuario.
   Salidas:
    Un nombre de usuario sugerido.
    
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <string>
#include <cctype>
using namespace std;  
 
/******************************************************************************/

bool EsEntero (string cosa){

	
	int indice = 0;           // La posición inicial es cero
	char caracter_sub_indice; // Cualquier elemento de la cadena de caracteres

	
	if((cosa.at(0) == '-')|| (cosa.at(0) == '+')){     
	                            
		
		indice = (indice + 1);  // Acutalizo el indice variando
	
	}
	
	
	bool entero_ok = true;
	   
	while(entero_ok && (indice < cosa.length())){
		
		 caracter_sub_indice = cosa.at(indice);
		 	
		entero_ok = (caracter_sub_indice >= '0' && caracter_sub_indice <='9')||
					caracter_sub_indice == ' ';
		
		indice = (indice + 1);   // Actualizo el índice.
		
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

/******************************************************************************/

	/* Defino una clase Login con un dato miembro solamente, que es el número de
	   caracters a coger en cada una de las palabras que conforman el nombre
	   del usuario. Solo hay un único método, que es el encargado de codificar
	   el nombre completo del usuario en el nombre de usuario sugerido para el
	   login.
	*/ 
	  
class Login
{
	
private:
	
	// PRE: num_caracteres_a_coger > 0;
	int num_caracteres_a_coger;
	
public:
	
	
/******************************************************************************/

	// Constructor
	
	// PRE: num_caracteres_a_coger > 0;
	
	Login (int n) : num_caracteres_a_coger (n) { }
	
/******************************************************************************/	
	
	// PRE: num_caracteres_a_coger > 0;
	
	string Codifica(string nombre_completo)
	{ 
		
		string usuario;
		int contador = 0;
		
		/* Establezco un ciclo for que se va a ejecutar siempre y cuando el
		   indice que recorre el nombre completo se encuentre evaluando una 
		   posición menor que la longitud del nombre completo. Se evalúa
		   carácter a caracter de tal forma que si el caracter que se encuentra
		   en la posición que indica el índice no es un espacio, y además el 
		   contador que se inicializa a cero, es menor que el número de 
		   caracteres a coger, indicado por el usuario, entonces, se coge ese
		   carácter y, con la función push_back se añade el carácter al usuario,
		   conviertiendolo en minúscula con la función tolower, y se acualiza
		   el contador.
		*/   
		   
		for (int i = 0; i < nombre_completo.length(); i++){
			
			
			if ((nombre_completo.at(i) != ' ') && 
			   (contador < num_caracteres_a_coger )){
			   	
			   	usuario.push_back(tolower(nombre_completo.at(i)));
			   	contador ++;
			   	
			}
			   	
			else
			{
			    /* Si el índice se encuentra evaluando un espacio en blanco, y 
			       de todas formas se sigue cumpliendo que el contador es menor
			       que n, entonces simplemente no se tiene en cuenta ese espacio
			       en blanco y el contador se pone a cero.
			    */
				   
				if ((nombre_completo.at(i) == ' ') && 
			   	   (contador < num_caracteres_a_coger)){
			   	   	
			   	   	contador = 0;
			   	   	
			   }

				else
				{
				    // Todo espacio en blanco se desecha
				    
					if (nombre_completo.at(i) == ' '){
					
						contador = 0;
						
					}
				}
			}
			}
		
		
		return (usuario);
	}
	
};

/******************************************************************************/

int main ()
{
	
	// Datos de entrada
	
	string nombre;
	int num_caracteres;
	
	// Entrada de datos
	
	cout << "LOGIN AUTOMATICO";
	cout << endl;
	cout << endl;
	
	cout << "\t Introduzca su nombre completo: ";
	getline (cin, nombre);
	
	num_caracteres = LeeEnteroMayorOIgual ("\t Introduzca el numero de "
	                                       "caracteres a coger: ", 0);
	
	// Creación del objeto Login
	
	Login log (num_caracteres);
	
	// Salida de datos
	
	cout << endl;
	cout << "\t Su nombre de usuario sugerido es: " << log.Codifica(nombre);
	cout << endl;
	
/******************************************************************************/
	return 0;
}
	
	                                      
	
	
