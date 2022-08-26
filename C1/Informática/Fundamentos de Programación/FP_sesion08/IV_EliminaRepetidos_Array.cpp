/******************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// QUINT�N MESA ROMERO 1� A.2 DGIIM
//
/* Programa que lee un n�mero indeterminado de enteros positivos hasta un
   m�ximo de 50 y elimina los que est�n repetidos. 
   Se ha implementado de tres formas distintas. Dos de ellas realizadas por
   el profesor.
   Las versiones que se han llevado a cabo son las siguientes:
   
   	VERSION 1: USANDO UN VECTOR AUXILIAR
   	VERSION 2: BORRAR (DESPLAZAR) REPETIDAMENTE (con algoritmo ineficiente)
   	VERSION 3: UTILIZANDO DOS APUNTADORES
   	
   La �ltima versi�n, es la que ten�amos que implementar nosotros. Esta 
   consiste en llevar a cabo la eliminaci�n de los n�meros repetidos mediante
   el uso de dos apuntadores: posicion_lectura y posicion_escritura, que van
   indicando en cada momento la componente del vector donde se guardan los
   datos introducidos que se est� leyendo, y el lugar en el que han de 
   escribirse dichos datos.
   Conforme va leyendo, si hay un dato que est� repetido, la posicion de
   lectura sigue avanzando, pero si encuentra un n�mero que a�n no est� 
   repetido, entonces dicho dato se escribe en la posicion de escritura y ambos
   apuntadores avanzan una unidad, y as� sucesivamente.	
   
   Entradas: 
    Un n�mero de enteros positivos (50).
   
   Salidas:
   	La lista de n�meros que no se repiten de los que se han introducido.
     
*/               
/******************************************************************************/

#include <iostream>    //Inclusi�n de los recursos de E/S (entrada/salida)
#include <iomanip>
using namespace std;  
 
/******************************************************************************/
/******************************************************************************/

int main()
{
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	 
	
	// Defino el vector de los datos num�ricos a introducir.
	
	// Declaro el n�mero de componentes del vector como constante
	
	const int MAXIMO = 50;
	
	int datos[MAXIMO];
	
	int numeros_leidos = 0;
	
	/* Defino una variable tipo bool que emplear� como condici�n de un ciclo
	   while que establecer� a continuaci�n.
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
	// Sobre el array "copia1_datos" se emplear� un algoritmo ineficiente
	// mientras que sobre "copia2_datos" se usar� otro m�s eficiente.
	
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
	 
	// Se muestran los datos del vector copia (1) despu�s de procesarlos 
	
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
 	
 	// Empezamos a buscar repetidos desde la posici�n "pos_del_buscado" 
	// hacia arriba. Damos por hecho que los que est�n por debajo no est�n 
	// repetidos. Cuando "pos_del_buscado"=1 solo hay uno por debajo, 
	// el de la posici�n 0 y evidentemente no est� repetido (solo hay 
	// uno por debajo del que ocupa la posici�n "pos_del_buscado"). 
 	
 	int pos_del_num_buscado = 1;
		
	while (pos_del_num_buscado < numeros_leidos_copia2) {

		int numero_buscado = copia2_datos[pos_del_num_buscado];

		// Busco "numero_buscado" (el de "pos_del_num_buscado") en el 
		// subvector izquierdo (posiciones: 0 hasta "pos_del_num_buscado"-1)
		
  		int posicion = 0;
		bool numero_encontrado = false;
    
		while ((posicion < pos_del_num_buscado) && (!numero_encontrado))

			if (copia2_datos[posicion] == numero_buscado) 
				numero_encontrado = true; //�xito: terminar
			else
				posicion++; // Siguiente posici�n

		if (numero_encontrado) {
		
			int tope = (numeros_leidos_copia2 - 1); // posici�n del �ltimo 
    
    		// Desplazar hacia la izquierda los valores que est�n a 
    		// la derecha del que ocupa la posici�n "pos_del_buscado"
    		
			for (int i = pos_del_num_buscado ; i < tope ; i++)
				copia2_datos[i] = copia2_datos[i+1];  
    
			numeros_leidos_copia2--;  // Ya hay uno menos
		}
		else
			pos_del_num_buscado++; // Procesar el siguiente

	} // while (pos_del_num_buscado < numeros_leidos_copia1)
		
			
	// Se muestran los datos del vector copia (1) despu�s de procesarlos 
	
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
	// de la posici�n cero no va a ser igual que otro anterior.
	
	int posicion_escritura = 1;
	
	/* A continuaci�n se establece un ciclo for en el que se inicializa 
	   el contador posicion_lectura en uno por la misma raz�n que el anterior
	   y que entrar� en bucle s� y solo s� se cumple la condici�n de que
	   en cada caso la posici�n de lectura sea menor que la cantidad de numeros
	   utilizados en la copia 3. Cada vez que esto se cumpla se actualiza la
	   posici�n de lectura, increment�ndose una unidad.
	*/ 
	
	for (int posicion_lectura=1; posicion_lectura<numeros_leidos_copia3;
		 posicion_lectura = posicion_lectura + 1){	
	
		// Declaro un dato de tipo int que me va a servir de �ndice variando
									
		int indice_variando = 0 ;
		
		/* A continuaci�n, voy a establecer un ciclo do while que se estar� 
		   ejecutando siempre que el n�mero que se est� leyendo no se repita
		   y ademas que la posici�n que indique el �ndice variando sea menor
		   que la posici�n de escritura.
		*/   
		
		bool condicion;   
		
		bool es_numero_distinto ;
		
		do{
			
			es_numero_distinto = (copia3_datos[posicion_lectura]!=
			                      copia3_datos[indice_variando]);
			                      
			// Acutalizo el �ndice variando                      
			                      
			indice_variando = indice_variando +1;
			
			// Acutalizo la bandera condicion
		 	/* Se ha de cumplir que el �ncide variando sea menor estricto que
		 	   la posici�n de escritura y adem�s que se cumpla 
			   es_numero_distinto.
			*/   
			
			condicion = ((indice_variando < posicion_escritura) &&
			             (es_numero_distinto)) ;
			             
		}while (condicion);
		
		 /* A continuaci�n, si se cumple es_numero_distinto resulta que
		   el contenido del vector de la copia de datos 3 de n�mero de 
		   componentes el indicado por la posici�n de escritura, se guarda
		   en el vector copia de datos 3 de n�mero de componentes el indicado
		   por la posici�n de lectura.
		*/ 
		
		if (es_numero_distinto) {
			
			copia3_datos[posicion_escritura] = copia3_datos[posicion_lectura] ;
			
			// Y por supuesto, se actualiza la posici�n de escritura.
			// Y as� sucesivamente
			 
			posicion_escritura = posicion_escritura + 1;
		}
	}
	
	/* Una vez que se ha salido del ciclo for, es porque se cumple que
	   la posici�n de lectura es mayor o igual que el n�mero de datos le�dos
	   en la copia 3, luego, es condici�n indispensable actualizar la posici�n
	   de escritura disminuy�ndola una unidad.
	*/
	
	posicion_escritura = (posicion_escritura - 1);
	
	/* A continuaci�n se actuliza el valor de la cantidad de datos utilizados
	   (numeros_leidos_copia3). Para ello simplemnte se le asigna el valor de
	   la posici�n de escritura desplazada una unidad a la derecha.
	*/
	
	numeros_leidos_copia3 = posicion_escritura +1 ;
	
	
	// Salida de datos
	    
	// Se muestran los datos del vector copia (3) despu�s de procesarlos 
	
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
  	
