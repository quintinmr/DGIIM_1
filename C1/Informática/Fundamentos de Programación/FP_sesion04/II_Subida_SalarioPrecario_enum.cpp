/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee la edad y el salario de una persona y que imprime en
   pantalla su salario final, una vez aplicados una serie de aumentos que
   vienen dados en funci�n de la edad de la persona y de si cobra menos de 300
   euros o m�s de 300 pero menos de 900.
   
   Entradas: 
    Edad (edad) y salario (salario) de una persona.
    
   Salidas: 
    Salario final (salario_final).
    
   Este programa lo he realizado mediante anidamiento de estructuras 
   condicionales dobles, usando el tipo enumerado para la gesti�n de las
   posibles categor�as en las que pueden clasifircarse los datos 
   correspondientes a las variables declaradas, y por �ltimo, he hecho uso de
   una estructura condicional m�ltiple para la salida de datos, en la que se
   contemplan todos los casos del tipo enumerado, y se muestra en pantalla
   los resultados pertinentes.
   Una vez dicho esto, en primer lugar, he definido los tipos (TipoEdad) y
   (TipoSalario), con los posibles casos TipoEdad {Menor_de_35_o_mayor_de_65, 
   Mayor_o_igual_35_y_menor_o_igual_65}, y TipoSalario {Menor_300, 
   Mayor_o_igual_300_y_menor_900, Mayor_o_igual_900}, y a continuaci�n he
   definido las variables de dichos tipos (TipoEdad edad_tipo) y (TipoSalario
   salario_tipo).
   
   A partir de aqu�, he establecido las condiciones, en primer lugar he
   establecido la restricci�n de que los datos de la variable edad y los de
   la variable salario ha de ser enteros positivos; mayores que cero. En caso
   contrario se muestra en pantalla un mensaje de ERROR en el que se informa
   al usuario de que os datos son err�neos y le dice que inice de nuevo el 
   programa. Si la condici�n previa se verifica, se pasa a las condiciones
   establecidas acerca a de la edad y el salario, las cuales, si se verifican
   pasan a la determinaci�n del tipo de car�cter del que se trata, y a 
   continuaci�n, se procede al c�clulo del salario final de la persona el cual
   podr� verse aumentado en funci�n de si cumple las condiciones establecidas
   para que puedan aplicarse los aumentos, que pueden ser del 0%, 1.5%, 3% y 4%.
   
   Finalmente, para la salida de los resultados, he empleado una estructura
   condicional m�ltiple (una para la edad y otra para el salario) en la que se
   contemplan los m�ltiple casos que se han establecido en el tipo enumerado,
   de tal forma que si los datos introducidos por el usuario verifican una 
   condici�n determinada, se verificar� el caso correspondiente a dicha 
   condici�n en el switch, y se mostrar� en pantalla el mensaje correspondiente
   en el cual se dice el aumento que se le ha aplicado al salario y por qu�, es 
   decir, se especifica la condici�n que cumplen los datos. Finalmente, en dicho
   mensaje se muestra el valor del salario, una vez aplicado el descuento, si es
   que los datos lo merecen.
   
   
    
                      
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaraci�n de datos
	
	// Datos de entrada
	
	int edad;
	double salario;
	
	/*Declaraci�n de constantes
	
    Declaro los aumentos que se aplican al salario en funci�n de las 
	condiciones.                                                              */
	
	const double AUMENTO1 = 0.04;   // Aumento del 4%
	const double AUMENTO2 = 0.03;   // Aumento del 3% 
	const double AUMENTO3 = 0.015;  // Aumento del 1.5%
	
	// Datos de salida
	
	double salario_final;
	
/******************************************************************************/

	// Entrada de datos
	
	cout << "Introduzca la edad de una persona: ";
	cin >> edad;
	
	cout << "Introduzca el salario de una persona: ";
	cin >> salario;
	
	// Condiciones, c�lculos y salida de datos
	
	enum class TipoEdad {Menor_de_35_o_mayor_de_65, 
	                   Mayor_o_igual_35_y_menor_o_igual_65};
	
	enum class TipoSalario {Menor_300, Mayor_o_igual_300_y_menor_900,
	                        Mayor_o_igual_900};
	                       
	TipoEdad edad_tipo;
	TipoSalario salario_tipo;
	
	if ((edad > 0) && (salario > 0)) {
	
	  if ((edad < 35) || (edad > 65)) {
		
		edad_tipo     = TipoEdad::Menor_de_35_o_mayor_de_65;
	
		salario_final = ((AUMENTO1 * salario) + salario);
		
		if (salario < 300) {
			
		 salario_tipo = TipoSalario::Menor_300;
		
		salario_final = (AUMENTO2 * salario) + (AUMENTO1 * salario) + salario ; 
		
	    }
	    
	    else 
	    {
	    
	    	if ((salario >= 300) && (salario < 900)) {
	    	
	           salario_tipo = TipoSalario::Mayor_o_igual_300_y_menor_900;
		
		       salario_final = ((AUMENTO3 * salario) + 
		                        (AUMENTO1 * salario) + salario);
		
			} 
		
			else
		    {
		   		if (salario >= 900){
		   	
		   			 salario_tipo  = TipoSalario::Mayor_o_igual_900;
		   
		    	     salario_final = ((AUMENTO1 * salario) + salario);
		   
		  		 }
		        
			}
	
        }
        
   }
        
	 else 
	 {
		edad_tipo     = TipoEdad::Mayor_o_igual_35_y_menor_o_igual_65;
	
		salario_final = salario;
		
     }
    
   }
   
   else 
   {
   		cout << "ERROR: Debe introducir una edad y un salario positivos. Inicie"
		     << " de nuevo el programa e introduzca los datos correctamente"
			 <<endl;
			 
	}
   	
    // Salida de datos
    
    switch (edad_tipo) {
    	
    	case (TipoEdad::Menor_de_35_o_mayor_de_65):
    		
    		switch (salario_tipo) {
    			
    			case (TipoSalario::Menor_300):
    			
				cout << "El salario final de la persona, una vez aplicado un 4%"  
				" de aumento por tener menos de 35 a�os o m�s de 65, y otro 3%"
		        " por cobrar menos de 300 euros es: "<< salario_final <<" euros"
		        <<endl;	
		        
		        break;
		        
		        case (TipoSalario::Mayor_o_igual_300_y_menor_900):
		        
				cout << "El salario final de la persona, una vez aplicado un 4%"  
				" de aumento por tener menos de 35 a�os o m�s de 65, y otro " 
				"1.5% por cobrar mas de 300 euros (inclusive) y menos de 900 " 
				"es: " << salario_final <<" euros" <<endl;	
				
				break;
				
				case (TipoSalario::Mayor_o_igual_900):
				
				cout << "El salario final de la persona, una vez aplicado un 4%" 
				" de aumento por tener menos de 35 a�os o m�s de 65, �nicamente"
		        " por cobrar mas de 900 (inclusive) es: " << salario_final <<
		        " euros" <<endl; 
		        
		        break;
		        
		    }
		    
		    break;
	
		case (TipoEdad::Mayor_o_igual_35_y_menor_o_igual_65):
			
			cout << "El salario final de la persona es el mismo que de partida"
			" porque no se le ha podido aplicar ning�n descuento debido a que"
			" no cumple los requisitos de edad. Y es: "<< salario_final << 
			" euros" <<endl;
			
			break;	
	
	
	}
	
/******************************************************************************/

	return 0;
}
	
	
	
