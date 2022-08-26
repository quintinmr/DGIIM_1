/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lleva a cabo la conversión entre dos unidades de distancia, las
   cuales serán (milímetros (mm), centímetros (cm), metros (m), y kilómetros
   (km)), y muestra en pantalla el resultado de la conversión.
      
   Entradas: 
    El valor de la unidad inicial ( valor unidad_inicial).
    La unidad a la que quiere transformar el valor inicial (unidad_final).
    
   Salidas: 
    El resultado de la transformación (resultado)
    
                      
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <string>
#include <cmath>
using namespace std;  

/******************************************************************************/
/******************************************************************************/

int main()   // Programa principal
{
	// Declaración de datos
	
	// Datos de entrada
	
	double valor;
	string unidad_inicial;
	string unidad_final;
	char preposicion;     // la preposición es la letra a cuya posición en la 
	                      // página de códigos ASCII es el número 97; el cual
	                      // se asocia a la letra a , poniéndo esta entre 'a'.
	
	int exponente_inicial;
	int exponente_final;
	
	// Declaración de constantes
	
	const int EXPONENTE_MM = -3;  // Porque 1mm = 10^-3 m
	const int EXPONENTE_CM = -2;  // Porque 1cm = 10^-2 m
	const int EXPONENTE_M  =  0;  // Porque 1m  = 10^0 m
	const int EXPONENTE_KM =  3;  // Porque 1km = 10^3 m

	
	// Datos de salida
	
	double valor_convertido;
	
/******************************************************************************/

	// Entrada de datos
	
	cout << ">";
	cout << endl; 
	cin  >> valor >> unidad_inicial >> preposicion >> unidad_final;
	cout << endl;
	
	// Condiciones, cáclulos y salida de datos
	
	if ((valor >= 0) && (preposicion == 'a') && ((unidad_inicial == "mm") ||
	    (unidad_inicial == "cm") || (unidad_inicial == "m") ||
	    (unidad_inicial == "km")) && ((unidad_final == "mm") ||
	    (unidad_final == "cm") || (unidad_final == "m") || 
		(unidad_final == "km"))) {
		
		/* Tomando como referencia la unidad de distancia en el Sistema 
	       Internacional, el exponente al que tengo que elevar la potencia
	       de 10 para pasar de una unidad a metros es el siguiente: 
	    */   
		if (unidad_inicial == "mm") {
			
			exponente_inicial = EXPONENTE_MM ;
			
		}
		
		else
		{
			if (unidad_inicial == "cm") {
				
				exponente_inicial = EXPONENTE_CM ;
			
		    }
		    
		    else
		    {
		    	if (unidad_inicial == "m") {
		    		
		    		exponente_inicial = EXPONENTE_M ;
		    		
		        }
		        
		        else
		        {
		        	if (unidad_inicial == "km") {
		        		
		        		exponente_inicial = EXPONENTE_KM ;
		        		
		            }
		            
		        }
		    }
		    
		}
		
		if (unidad_final == "mm") {
		
			exponente_final = EXPONENTE_MM ;
			
    	}
    	
    	else
    	{
    		if (unidad_final == "cm") {
    			
    			exponente_final = EXPONENTE_CM ;
    			
            }
            
            else
            {
            	if (unidad_final == "m") {
            		
            		exponente_final = EXPONENTE_M ;
            		
                }
                
                else
                {
                	if (unidad_final == "km") {
                		
                		exponente_final = EXPONENTE_KM ;
                		
                	}
                	
                }
                
            }
            
        }
        
        // Cálculos
        
        valor_convertido = valor * pow(10, exponente_inicial - exponente_final);			
		
		cout << endl;
		cout << valor <<" "<< unidad_inicial << "=" << valor_convertido << "  "
		     << unidad_final << endl;  
		
    }
	
	else
	{
		cout << "ERROR: Los datos son incorrectos. Por favor, inicie de nuevo "
		     << "el programa e introduzca los datos correctamente.";
		cout << endl;
		
	}
	
/******************************************************************************/
	return 0;
}
	
