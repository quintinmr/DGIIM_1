/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// QUINTÍN MESA ROMERO 1º A.2 DGIIM
//
/* Programa que lee un número indeterminado de enteros positivos hasta un
   máximo de 50 y elimina los que están repetidos. 
   Se ha implementado de tres formas distintas. Dos de ellas realizadas por
   el profesor.
   Las versiones que se han llevado a cabo son las siguientes:
   
   	VERSION 1: USANDO UN VECTOR AUXILIAR
   	VERSION 2: BORRAR (DESPLAZAR) REPETIDAMENTE (con algoritmo ineficiente)
   	VERSION 3: UTILIZANDO DOS APUNTADORES
   	
   La última versión, es la que teníamos que implementar nosotros. Esta 
   consiste en llevar a cabo la eliminación de los números repetidos mediante
   el uso de dos apuntadores: posicion_lectura y posicion_escritura, que van
   indicando en cada momento la componente del vector donde se guardan los
   datos introducidos que se está leyendo, y el lugar en el que han de 
   escribirse dichos datos.
   Conforme va leyendo, si hay un dato que está repetido, la posicion de
   lectura sigue avanzando, pero si encuentra un número que aún no está 
   repetido, entonces dicho dato se escribe en la posicion de escritura y ambos
   apuntadores avanzan una unidad, y así sucesivamente.	
   
   Entradas: 
    Un número de enteros positivos (50).
   
   Salidas:
   	La lista de números que no se repiten de los que se han introducido.
     
*/               
/******************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S (entrada/salida)
#include <iomanip>
using namespace std;  
 
/******************************************************************************/
/******************************************************************************/

int main()
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	 
	
	// Defino el vector de los datos numéricos a introducir.
	
	// Declaro el número de componentes del vector como constante
	
	const int MAXIMO = 50;
	
	int datos[MAXIMO];
	
	int numeros_leidos = 0;
	
	/* Defino una variable tipo bool que emplearé como condición de un ciclo
	   while que estableceré a continuación.
	*/   
	   
	bool continua_leyendo = true; 
	int number; 
	
	cin >> number;
	
	while ((number >= 0) && (continua_leyendo)) {

		datos[numeros_leidos]	= number;
		numeros_leidos++;

		if (numeros_leidos == MAXIMO) 
			continua_leyendo = false;
		else 
			cin >> number;
	}

	// Se muestran los datos originales
	
	cout << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl;	
 	cout << "Numeros originales: " << "(" << setw(3) 
	 	 << numeros_leidos << " numeros): " << endl;	
	 	 
	for (int i = 0; i < numeros_leidos; i++)
	 
		cout << setw(3) << datos[i] << "  "; 
		
	cout << endl;
			
	cout << "--------------------------------------------------------" << endl;
	cout << endl;

	// Copia de los datos originales en dos vectores para trabajar sobre 
	// los nuevos vectores y no perder los datos originales
	// Sobre el array "copia1_datos" se empleará un algoritmo ineficiente
	// mientras que sobre "copia2_datos" se usará otro más eficiente.
	
	int copia1_datos[MAXIMO];
	int numeros_leidos_copia1 = 0;	

	int copia2_datos[MAXIMO];
	int numeros_leidos_copia2 = 0;	
	
	int copia3_datos[MAXIMO];
	int numeros_leidos_copia3 = 0;

	for (int i = 0; i < numeros_leidos; i++) 
		copia1_datos[i] = copia2_datos[i] = copia3_datos[i] = datos[i];
		
	numeros_leidos_copia1 = numeros_leidos;
	numeros_leidos_copia2 = numeros_leidos;
	numeros_leidos_copia3 = numeros_leidos;

 	/***********************************************************************/
 	// VERSION 1: USANDO UN VECTOR AUXILIAR
 	
	// Se muestran los datos del vector copia (1) antes de procesarlos 
	
	cout << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "          VERSION 1: USANDO UN VECTOR AUXILIAR          " << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl;
 	cout << "Copia 1 antes de eliminar repetidos usando vector auxiliar"
	     << " (" << setw(3) << numeros_leidos_copia1 << " numeros):" << endl;	

	for (int i = 0; i < numeros_leidos_copia1; i++) 
	
		cout << setw(3) << copia1_datos[i] << "  "; 
		
	cout << endl;


	int sin_repetidos[MAXIMO];
	int numeros_leidos_sin_repetidos = 0;

	sin_repetidos[0] = copia1_datos[0]; 
	
	numeros_leidos_sin_repetidos = 1;
	
	for (int i = 1; i < numeros_leidos_copia1; i++) {
		
		// Buscar copia1_datos[i] en sin_repetidos
		
		int posicion = 0; 
		bool numero_encontrado = false;
		
		while ((posicion < numeros_leidos_sin_repetidos) &&
		       (!numero_encontrado)) {
		       	
			if (sin_repetidos[posicion] == copia1_datos[i])
			
				numero_encontrado = true;
				
			else 
				posicion++;
		}
		if (!numero_encontrado) {
			
			sin_repetidos[numeros_leidos_sin_repetidos] = copia1_datos[i];
			
			numeros_leidos_sin_repetidos++;
		}
	
	} // for 
	 
	// Copia desde sin_repetidos a copia1
	 
	for (int i = 0; i < numeros_leidos_sin_repetidos; i++) 
	
		 copia1_datos[i] = sin_repetidos[i];
		 
	numeros_leidos_copia1 = numeros_leidos_sin_repetidos;
	 
	// Se muestran los datos del vector copia (1) después de procesarlos 
	
	cout << endl;	
 	cout << "Copia 1 despues de eliminar repetidos con vector auxiliar"
	     << " (" << setw(3) << numeros_leidos_copia1 << " numeros):" << endl;

	for (int i = 0; i < numeros_leidos_copia1; i++) 
		cout << setw(3) << copia1_datos[i] << "  "; 
	cout << endl;
	
	cout << "--------------------------------------------------------" << endl;
	cout << endl;



 	/***********************************************************************/
  	// VERSION 2: BORRAR (DESPLAZAR) REPETIDAMENTE
	
	// Se muestran los datos del vector copia (1) antes de procesarlos 
	
	cout << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "       VERSION 2: BORRAR (DESPLAZAR) REPETIDAMENTE      " << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl;
 	cout << "Copia 2 antes de eliminar repetidos con algoritmo ineficiente"
	     << " (" << setw(3) << numeros_leidos_copia2 << " numeros):" << endl;	

	for (int i = 0; i < numeros_leidos_copia2; i++) 
	
		cout << setw(3) << copia2_datos[i] << "  "; 
		
	cout << endl;
 
 	// Borrado con desplazamiento
 	
 	// Empezamos a buscar repetidos desde la posición "pos_del_buscado" 
	// hacia arriba. Damos por hecho que los que están por debajo no están 
	// repetidos. Cuando "pos_del_buscado"=1 solo hay uno por debajo, 
	// el de la posición 0 y evidentemente no está repetido (solo hay 
	// uno por debajo del que ocupa la posición "pos_del_buscado"). 
 	
 	int pos_del_num_buscado = 1;
		
	while (pos_del_num_buscado < numeros_leidos_copia2) {

		int numero_buscado = copia2_datos[pos_del_num_buscado];

		// Busco "numero_buscado" (el de "pos_del_num_buscado") en el 
		// subvector izquierdo (posiciones: 0 hasta "pos_del_num_buscado"-1)
		
  		int posicion = 0;
		bool numero_encontrado = false;
    
		while ((posicion < pos_del_num_buscado) && (!numero_encontrado))

			if (copia2_datos[posicion] == numero_buscado) 
				numero_encontrado = true; //Éxito: terminar
			else
				posicion++; // Siguiente posición

		if (numero_encontrado) {
		
			int tope = (numeros_leidos_copia2 - 1); // posición del último 
    
    		// Desplazar hacia la izquierda los valores que están a 
    		// la derecha del que ocupa la posición "pos_del_buscado"
    		
			for (int i = pos_del_num_buscado ; i < tope ; i++)
				copia2_datos[i] = copia2_datos[i+1];  
    
			numeros_leidos_copia2--;  // Ya hay uno menos
		}
		else
			pos_del_num_buscado++; // Procesar el siguiente

	} // while (pos_del_num_buscado < numeros_leidos_copia1)
		
			
	// Se muestran los datos del vector copia (1) después de procesarlos 
	
	cout << endl;	
 	cout << "Copia 2 despues de eliminar repetidos con algoritmo ineficiente"
	     << " (" << setw(3) << numeros_leidos_copia2 << " numeros):" << endl;

	for (int i = 0; i < numeros_leidos_copia2; i++) 
	
		cout << setw(3) << copia2_datos[i] << "  "; 
		
	cout << endl;
		
	cout << "--------------------------------------------------------" << endl;
	cout << endl;
	
	
	
	/***********************************************************************/
  	// VERSION 3: UTILIZANDO DOS APUNTADORES
  	
  	// Se muestran los datos del vector copia (3) antes de procesarlos 
	
	cout << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "          VERSION 3: UTILIZANDO DOS APUNTADORES         " << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl;
 	cout << "Copia 3 antes de eliminar repetidos utilizando dos apuntadores"
	     << " (" << setw(3) << numeros_leidos_copia3 << " numeros):" << endl;	

	for (int i = 0; i < numeros_leidos_copia3; i++) 
	
		cout << setw(3) << copia3_datos[i] << "  "; 
		
	cout << endl;
	
	// Se declara el primer apuntador y se inicializa en 1 porque el contenido
	// de la posición cero no va a ser igual que otro anterior.
	
	int posicion_escritura = 1;
	
	/* A continuación se establece un ciclo for en el que se inicializa 
	   el contador posicion_lectura en uno por la misma razón que el anterior
	   y que entrará en bucle sí y solo sí se cumple la condición de que
	   en cada caso la posición de lectura sea menor que la cantidad de numeros
	   utilizados en la copia 3. Cada vez que esto se cumpla se actualiza la
	   posición de lectura, incrementándose una unidad.
	*/ 
	
	for (int posicion_lectura=1; posicion_lectura<numeros_leidos_copia3;
		 posicion_lectura = posicion_lectura + 1){	
	
		// Declaro un dato de tipo int que me va a servir de índice variando
									
		int indice_variando = 0 ;
		
		/* A continuación, voy a establecer un ciclo do while que se estará 
		   ejecutando siempre que el número que se esté leyendo no se repita
		   y ademas que la posición que indique el índice variando sea menor
		   que la posición de escritura.
		*/   
		
		bool condicion;   
		
		bool es_numero_distinto ;
		
		do{
			
			es_numero_distinto = (copia3_datos[posicion_lectura]!=
			                      copia3_datos[indice_variando]);
			                      
			// Acutalizo el índice variando                      
			                      
			indice_variando = indice_variando +1;
			
			// Acutalizo la bandera condicion
		 	/* Se ha de cumplir que el íncide variando sea menor estricto que
		 	   la posición de escritura y además que se cumpla 
			   es_numero_distinto.
			*/   
			
			condicion = ((indice_variando < posicion_escritura) &&
			             (es_numero_distinto)) ;
			             
		}while (condicion);
		
		 /* A continuación, si se cumple es_numero_distinto resulta que
		   el contenido del vector de la copia de datos 3 de número de 
		   componentes el indicado por la posición de escritura, se guarda
		   en el vector copia de datos 3 de número de componentes el indicado
		   por la posición de lectura.
		*/ 
		
		if (es_numero_distinto) {
			
			copia3_datos[posicion_escritura] = copia3_datos[posicion_lectura] ;
			
			// Y por supuesto, se actualiza la posición de escritura.
			// Y así sucesivamente
			 
			posicion_escritura = posicion_escritura + 1;
		}
	}
	
	/* Una vez que se ha salido del ciclo for, es porque se cumple que
	   la posición de lectura es mayor o igual que el número de datos leídos
	   en la copia 3, luego, es condición indispensable actualizar la posición
	   de escritura disminuyéndola una unidad.
	*/
	
	posicion_escritura = (posicion_escritura - 1);
	
	/* A continuación se actuliza el valor de la cantidad de datos utilizados
	   (numeros_leidos_copia3). Para ello simplemnte se le asigna el valor de
	   la posición de escritura desplazada una unidad a la derecha.
	*/
	
	numeros_leidos_copia3 = posicion_escritura +1 ;
	
	
	// Salida de datos
	    
	// Se muestran los datos del vector copia (3) después de procesarlos 
	
	cout << endl;	
 	cout << "Copia 3 despues de eliminar repetidos utilizando dos apuntadores"
	     << " (" << setw(3) << numeros_leidos_copia3 << " numeros):" << endl;

	for (int i = 0; i < numeros_leidos_copia3; i++) 
	
		cout << setw(3) << copia3_datos[i] << "  "; 
			
	cout << endl;
		
	cout << "--------------------------------------------------------" << endl;
	cout << endl;    
	    
	/*************************************************************************/
	
	return 0;
}
  	
