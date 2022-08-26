/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee un n�mero de horas, minutos y segundos iniciales, y finales
   calcula el n�mero de segundos que hay de diferencia entre ambos instantes de
   tiempo, e imprime en pantalla los segundos y minutos de diferencia entre
   ambos instantes. Finalmente, se muestra dicha diferencia de tiempo en
   horas minutos y segundos. (Para ello se usa el m�todo ToString de la clase
   que se ha definido en el programa).
   
   Entradas: 
    Dos instantes de tiempo (en horas, minutos y segundos)
    
   Salidas:
    Los segundos que transcurren entre ambos instantes de tiempo.
    Los minutos que transcurren entre ambos instantes de tiempo.
    La diferencia de tiempo entre ambos instantes expresada en horas, minutos 
    y segundos.
    
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <string>
using namespace std;  
 
/******************************************************************************/

	/* Defino una serie de funciones para la lectura de enteros, las cuales 
	   usar� en el main, para la entrada de datos.
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

int LeeEnteroEnRango (string titulo, int menor, int mayor)
{
	int numero_entero;   
	 
	do {
		
		numero_entero = LeeEntero(titulo);	
		
	} while (numero_entero < menor || numero_entero > mayor);
	
	
	return numero_entero;	
}

/******************************************************************************/

	/* Defino la clase Instante, constitu�da por tres datos miembro de caracter
	   privado, que no son m�s que los datos mediante los que un instante de
	   tiempo queda definido (horas, minutos, y segundos). Adem�s, he definido
	   dos constructores con los que se incializar� un objeto, y una serie de
	   m�todos, de car�cter p�blico y privado que se ver�n a continuaci�n.
    */   

class Instante
{
	
private:

	int horas;
	int minutos;
	int segundos;
	
public:

	// M�todos
	
	/***********************************************************************/
	
	/* Este constructor se encargar� de inicializar objetos Instante como son
	   el instante inicial y el instante final.
	   PRE: horas, minutos y segundos >= 0
	*/
	
	Instante (int h, int min, int s):
	
		horas (h), minutos (min), segundos (s)
	
	{	
	}
	
	/* Este constructor se encargar� de dar valor al objeto que se definir� 
	   para la diferencia de tiempo. Dicho constructor llama a las funciones
	   que calculan los segundos, minutos, y horas, del instante diferencia 
	   de tiempo, a partir de los segundos de diferencia.
	   PRE: horas, minutos, y segundos >=0
	*/   
	
	Instante (int segunditos):
	
	    /* Se le asocia el valor 0 a las horas y los minutos porque estamos
	       trabajando en funci�n de los segundos de diferencia entre los dos
	       instantes de tiempo.
	    */   
		horas (0), minutos(0), segundos(segunditos)
		
		/* Se llama a los m�todos privados, de m�s abajo, destinados al c�lculo
		   de los segundos minutos y horas de la diferencia de tiempo entre los
		   dos instante de tiempo, en funci�n de los segundos que transcurren
		   entre ambos instantes.
		*/   
	{
	 SegundosInstante (segunditos);
	 MinutosInstante  (segunditos);
	 HorasInstante    (segunditos);
	}
			

	
	/***********************************************************************/
	
	// Declaraci�n de las constantes con las que se va a trabajar
	
	const int SEGS_1_H = 3600;
	const int MINS_1_H = 60;

	/***********************************************************************/
	
	/* M�todo destinado al c�lculo de los segundos que hay en un instante de 
	   tiempo determinado.
	*/   
	int SegundosUnInstante (void)
	{
		
		return ((horas*SEGS_1_H) + (minutos*MINS_1_H) + segundos);
		
	}
	
	/* M�todo destinado al c�lculo de los minutos que hay en un instante de 
	   tiempo determinado.
	*/ 
	
	int MinutosUnInstante (void)
	{
		
		return ((horas*MINS_1_H) + minutos + (segundos/60));
		
	}
	
	/***********************************************************************/
	
	/* M�todo ToString, destinado a mostrar en pantalla la diferencia de tiempo 
	 en horas minutos y segundos, aunque tambi�n se usar� para representar cada
	 instante de tiempo como una cadena de caracteres de la forma:
		(---h : --- m : --- s:)
	*/	
	
	string ToString ()
	{
		
		string cadena;
		
		cadena = "(" + to_string(horas) + " h : " + to_string(minutos) + " m : " 
		          + to_string(segundos) + " s)";
		          
		return (cadena);
		
	}
	
	
	/***********************************************************************/
	
	/* A continuaci�n se definen una serie de m�todos de car�cter privado, los
	   cuales son usados por el constructor que da valor al objeto diferencia
	   de tiempo, a partir de los segundos de dicha diferencia de tiempo. De ah�
	   que se encuentren como instrucciones del constructor, entre las llaves
	   del mismo. 
	   Est�n destinados al c�lculo de los segundos, minutos, y horas, de dicha
	   diferencia, en su rango correspondiente.
	*/   
	
private:
	
	// M�todo para el c�lculo de segundos 
	
	void SegundosInstante (int seconds)
		{
			int secondos;
			
			secondos = (seconds % 60);
			
			segundos = secondos;
		}
		
	// M�todo para el c�lculo de minutos
		
	void MinutosInstante (int seconds)
		{
			int minuti;
			
			minuti = ((seconds / 60) % 60);
			
			minutos = minuti;
		}
		
	// M�todo para el c�lculo de horas
		
	void HorasInstante (int seconds)
		{
			int hours;
			
			hours = ((seconds / 60) / 60);
			
			horas = hours;
		}

};

////////////////////////////////////////////////////////////////////////////////

int main()   // Programa principal
{
	
	// Declaraci�n de datos
	
	// Datos de entrada
	
	int horas1;
	int minutos1;
	int segundos1;
	
	int horas2;
	int minutos2;
	int segundos2;

/******************************************************************************/	

	// Entrada de datos
	
	horas1    = LeeEnteroEnRango ("Introduzca el numero de horas del instante "
								  "1: ", 0, 23);
	minutos1  = LeeEnteroEnRango ("Introduzca el numero de minutos del instante" 
	                              " 1 : ", 0, 59);
	segundos1 = LeeEnteroEnRango ("Introduzca el numero de segundos del "
	                              "instante 1 : ", 0, 59);
								  
	cout << endl;
	
	horas2    = LeeEnteroEnRango ("Introduzca el numero de horas del instante "
							      "2: ",0, 23);
	minutos2  = LeeEnteroEnRango ("Introduzca el numero de minutos del instante"
								  " 2: ", 0, 59);
	segundos2 = LeeEnteroEnRango ("Introduzca el numero de segundos del "
								  "instante 2: ", 0, 59); 							 						   							   							                          
	
    
    // C�lculos, condiciones y salida de datos
    
    Instante instante1 (horas1, minutos1, segundos1);
    Instante instante2 (horas2, minutos2, segundos2);
	       	
	
	int segundos_entre_ambos_instantes = abs(instante2.SegundosUnInstante() -
	                                      instante1.SegundosUnInstante());
	
	                                 
   cout <<endl;											
   cout << "Los segundos que transcurren entre ambos instantes de"
		<< " tiempo son: " << segundos_entre_ambos_instantes <<endl; 
		
	Instante instante_diferencia (segundos_entre_ambos_instantes);
									 
	cout <<endl;											
    cout << "Los minutos que transcurren entre ambos instantes de"
		 << " tiempo son: " << instante_diferencia.MinutosUnInstante() <<endl; 
		 								 	
		

	cout <<endl;
	cout << "El tiempo que separa a los dos instantes introducidos, "
		 << instante1.ToString() <<", " << instante2.ToString() <<" es: "
		 << instante_diferencia.ToString();
	cout <<endl;
		   

/******************************************************************************/
	return 0;	                
}
	    
