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
#include <string>
using namespace std;  
 
/******************************************************************************/

	/* En primer lugar, definiré una función de tipo bool con el objetivo de
	   determinar si el número introducido es un número entero o no, y la 
	   cual usaré en la función LeeEntero que vendrá a continuación.
	   Esta función me devuelve el valor true si la cadena de caracteres 
	   introducida es un número entero.
	*/
	   
bool EsEntero (string cosa){
	
	/* Declaro una variable contadora de la posición de cada uno de los
	   elementos del string; va a ser un índice que va recorriendo todos
	   los elementos de la cadena en busca de datos numéricos.
	*/
	
	int indice = 0;           // La posición inicial es cero
	char caracter_sub_indice; // Cualquier elemento de la cadena de caracteres

	
	if((cosa.at(0) == '-')|| (cosa.at(0) == '+')){     
	                            
		
		indice = (indice + 1);  // Acutalizo el indice variando
	
	}
	
	/* A continuación establezco un ciclo while, el cual se ejecutará sí y solo
	   sí, se cumple que el índice variando ha alcanzado una posición menor 
	   que la posición del último carácter, en otras palabras, que el índice
	   sea menor que la propia lontitud del string.
	   Parte de dicha condición viene dada por una variable tipo bool que he
	   definido, y a la cual he asginado el valor true, de tal forma que se 
	   entrará al menos una vez, pero claro, sí y solo sí se cumple la otra
	   condición.
	*/
	
	bool entero_ok = true;
	   
	while(entero_ok && indice < cosa.length()){
		
		 caracter_sub_indice = cosa.at(indice);
		 
		// Actualizo la bandera
		
		/* El caracter, para que sea de carácter numérico, ha de ocupar en la
		   página de códigos ASCII, una posición entre la del 0 ('0') y la 
		   del 9 ('9'). Por eso, para que el caracter de la posición que indique
		   el índice sea un número, ha de cumplir que esté entre 0 y 9. Puede 
		   darse el caso de que entre los caracteres halla espacios. Estos
		   se obvian y se incluyen dentro de la condición de que la cadena
		   de caracteres sea un númer entero (luego en la siguiente función
		   se empleará la función stoid que pasa un string a un entero).
		*/   
		
		entero_ok = (caracter_sub_indice >= '0' && caracter_sub_indice <='9')||
					caracter_sub_indice == ' ';
		
		indice = (indice + 1);   // Actualizo el índice.
		
	}
	
	return entero_ok; 	
}

int LeeEntero (string titulo){
	
	string numero;   // Cadena a introducir por el usuario
	
	bool cadena_ok;  /* Declaro una variable tipo bool que emplearé en la 
	                    condición de el ciclo post-test que he establecido
	                    para la determinación de sí la cadena introducida
	                    es un entero o no.
	                 */   
	
	
	/* En este ciclo do while se comprueba si la cadena constituye un entero.
	   Luego, esta estructura entrará en bucle sí y solo sí la cadena de 
	   caracteres no es un número entero, y cada vez que esto ocurra se volverá
	   a pedir que introduzca un número entero.
	   Para comprobarlo, hago un llamamiento a la función tipo bool anterior
	   que estaba dirigida a la determinación de sí la cadena constituye un
	   entero o no. De tal forma que se dicha función devuelve el valor true
	   la función LeeEntero, termina de ejecutarse, y se pasa a la siguiente
	   lectura.
	*/
	   
	do{
		
		cout<< titulo;
		cin >> numero;
		
		cadena_ok = EsEntero(numero);
		
	}while(!cadena_ok);
	

 	/* La función devuelve la cadena introducida, convertida en int mediante
 	   la función stoi.
 	*/
	    
	return stoi(numero);
}


/******************************************************************************/

	/* Esta función lee un entero que se encuentre dentro del rango establecido
	   Si no está dentro o no es un entero, se sigue vuelve a pedir lo mismo.
	   Si se cumplen todas las condiciones se pasa a la siguiente lectura.
	*/
	   
int LeeEnteroEnRango (string titulo, int menor, int mayor)
{
	int numero_entero;
	
	/* He establecido un ciclo do while, en el que se comprueba , en primer 
	   lugar que la cadena de caracteres introducida sea un número entero. 
	   Si esto se cumple, la primera función me devuelve la cadena convertida
	   a entero y se pasa a evaluar si dicho número está dentro del rango
	   establecido (condición del ciclo do-while). Si la cadena de caracteres
	   no fuera un número entero, se vuelve a pedir que se introduzca un número
	   entero.
	*/   
	 
	do {
		
		numero_entero = LeeEntero(titulo);	
		
	} while (numero_entero < menor || numero_entero > mayor);
	
	
	return numero_entero;	
} 

/******************************************************************************/


	/* En primer lugar, definiré una función de tipo bool con el objetivo de
	   determinar si el número introducido es un número entero o no, y la 
	   cual usaré en la función LeeEntero que vendrá a continuación.
	   Esta función me devuelve el valor true si la cadena de caracteres 
	   introducida es un número entero.
	*/
	   
bool EsDouble (string cosa){
	
	/* Declaro una variable contadora de la posición de cada uno de los
	   elementos del string; va a ser un índice que va recorriendo todos
	   los elementos de la cadena en busca de datos numéricos.
	*/
	
	int indice = 0;           // La posición inicial es cero
	char caracter_sub_indice; // Cualquier elemento de la cadena de caracteres

	
	if((cosa.at(0) == '-')|| (cosa.at(0) == '+')){     
	                            
		
		indice = (indice + 1);  // Acutalizo el indice variando
	
	}
	
	/* A continuación establezco un ciclo while, el cual se ejecutará sí y solo
	   sí, se cumple que el índice variando ha alcanzado una posición menor 
	   que la posición del último carácter, en otras palabras, que el índice
	   sea menor que la propia lontitud del string.
	   Parte de dicha condición viene dada por una variable tipo bool que he
	   definido, y a la cual he asginado el valor true, de tal forma que se 
	   entrará al menos una vez, pero claro, sí y solo sí se cumple la otra
	   condición.
	*/
	
	bool double_ok = true;
	   
	while(double_ok && indice < cosa.length()){
		
		 caracter_sub_indice = cosa.at(indice);
		 
		// Actualizo la bandera
		
		/* El caracter, para que sea de carácter numérico, ha de ocupar en la
		   página de códigos ASCII, una posición entre la del 0 ('0') y la 
		   del 9 ('9'). Por eso, para que el caracter de la posición que indique
		   el índice sea un número, ha de cumplir que esté entre 0 y 9. Puede 
		   darse el caso de que entre los caracteres halla espacios. Estos
		   se obvian y se incluyen dentro de la condición de que la cadena
		   de caracteres sea un númer entero (luego en la siguiente función
		   se empleará la función stoid que pasa un string a un entero).
		*/   
		
		double_ok = (caracter_sub_indice >= '0' && caracter_sub_indice <='9')||
					caracter_sub_indice == ' ';
		
		indice = (indice + 1);   // Actualizo el índice.
		
	}
	
	return double_ok; 	
}

int LeeDouble (string titulo){
	
	string numero;   // Cadena a introducir por el usuario
	
	bool cadena_ok;  /* Declaro una variable tipo bool que emplearé en la 
	                    condición de el ciclo post-test que he establecido
	                    para la determinación de sí la cadena introducida
	                    es un entero o no.
	                 */   
	
	
	/* En este ciclo do while se comprueba si la cadena constituye un entero.
	   Luego, esta estructura entrará en bucle sí y solo sí la cadena de 
	   caracteres no es un número entero, y cada vez que esto ocurra se volverá
	   a pedir que introduzca un número entero.
	   Para comprobarlo, hago un llamamiento a la función tipo bool anterior
	   que estaba dirigida a la determinación de sí la cadena constituye un
	   entero o no. De tal forma que se dicha función devuelve el valor true
	   la función LeeEntero, termina de ejecutarse, y se pasa a la siguiente
	   lectura.
	*/
	   
	do{
		
		cout<< titulo;
		cin >> numero;
		
		cadena_ok = EsDouble(numero);
		
	}while(!cadena_ok);
	

 	/* La función devuelve la cadena introducida, convertida en int mediante
 	   la función stoi.
 	*/
	    
	return stoi(numero);
}


/******************************************************************************/

	/* Esta función lee un entero que se encuentre dentro del rango establecido
	   Si no está dentro o no es un entero, se sigue vuelve a pedir lo mismo.
	   Si se cumplen todas las condiciones se pasa a la siguiente lectura.
	*/
	   
int LeeDoubleEnRango (string titulo, double menor, double mayor)
{
	int numero_double;
	
	/* He establecido un ciclo do while, en el que se comprueba , en primer 
	   lugar que la cadena de caracteres introducida sea un número entero. 
	   Si esto se cumple, la primera función me devuelve la cadena convertida
	   a entero y se pasa a evaluar si dicho número está dentro del rango
	   establecido (condición del ciclo do-while). Si la cadena de caracteres
	   no fuera un número entero, se vuelve a pedir que se introduzca un número
	   entero.
	*/   
	 
	do {
		
		numero_double = LeeDouble(titulo);	
		
	} while (numero_double < menor || numero_double > mayor);
	
	
	return numero_double;	
} 

/******************************************************************************/

	/* Esta función determina si un número entero es mayor o igual que una
	   referencia establecida.
	*/
	   
int LeeDoubleMayorOIgual (string titulo, int referencia)
{
	int numero_double; 
	
	/* He establecido un ciclo do-while que entrará en bucle sí y solo sí
	   se cumple que la cadena de caracteres no es un entero. El cuerpo del
	   bucle se evalúa mediante una llamada a la función LeeEntero, que se
	   encargará de comprobar si la cadena de caracteres introducida es o no
	   un número entero. Si lo es, se pasa a evaluar la condición del ciclo, 
	   que es que sea menor que la referencia. Si dicha condición se
	   cumple, se vuelve a ejecutar el bucle. Si no se cumple, querrá decir
	   que el número es mayor o igual que la referencia, y finaliza directamente
	   el programa.
	   En cualquier caso, se vuelve a pedir que introduzca un número entero
	   cada vez que la cadena de caracteres no lo sea.
	*/    
	
	do {
		
		numero_double = LeeDouble(titulo);	
			
	} while (numero_double < referencia);
	
	
	return numero_double;	
}

/******************************************************************************/

struct Ciudad{
	
	int posicion;
	int numero_de_conexiones;
	
};

/******************************************************************************/

	const int MAX_CIUDADES = 50;

/******************************************************************************/	

bool Ciudadesinterconexas (int c1, int c2, double grafo[][MAX_CIUDADES]){
                           	
	return (grafo[c1][c2] > 0);
	
}

/******************************************************************************/

int ConexionesentreCiudades (int ciudad, double grafo[][MAX_CIUDADES], 
                             int num_ciudades_introducidas){
                             	
	int numero_conexiones = 0;
	
	for (int c = 0; c < num_ciudades_introducidas; c++){
	
		if (grafo[ciudad][c] > 0)
		
			numero_conexiones++; 
			
	}
	
	return (numero_conexiones);
	
}

/******************************************************************************/
/******************************************************************************/

int main ()
{
	
	// Declaración de los datos
	
	// Declaración de la matriz en la que se guardarán las ciudades
	// Es una matriz cuadrada, pues ha de ser simétrica.
	
	int grafo [MAX_CIUDADES][MAX_CIUDADES];
	
	int numero_de_ciudades = LeeEnteroEnRango("Introduzca el numero de ciudades"
											  " que desea analizar: ", 1, 
											  MAX_CIUDADES);
											  
	string msg; 
	int inicio = 1;
	
	cout << endl; 	
	cout << "Introduzca la distancia entre las ciudades";
	cout << endl << endl; 

	//Como es una matriz simétrica con una diagonal nula, no tenemos que pedir 
	//los datos de todas las celdas.  (modificar)
	
	for (int f = 0; f < numero_de_ciudades; f++) {
		
		for (int c = inicio; c < numero_de_ciudades; c++) {
			
			if (c == f){
				
				grafo [f][c] = 0;	//Formamos la diagonal nula
				
			}
			
			else {
				msg = "Distancia de la ciudad "+to_string(f+1)
					  +" a la ciudad "+to_string(c+1)+" : ";
					  
				//Aprovechamos la simetría y damos valor a dos celdas a la vez
				
				grafo [f][c] = LeeDoubleMayorOIgual(msg, 0);
				
				grafo [c][f] = grafo [f][c];
			}
		}
		inicio++;	
	}
	
	
	//b)
	//Pedimos el indice de la ciudad de la cual queremos saber su numero de 
	//conexiones. La llamaremos ciudad a.
	
	int index_ciudad = LeeEnteroEnRango("Indice de una ciudad: ", 1, 
	                   numero_de_ciudades)-1;
	
	int num_conexiones_ciudad = 0;
	
	
	//c)
	//Pedimos dos ciudades que no estén unidas directamente y para calcular el
	//viaje pasando por una ciudad intermedia más económico. Las llamaremos
	//ciudad b y ciudad c.
	
	int indice_ciudad_b, indice_ciudad_c;
	
	cout << endl << "Introduzca dos ciudades que no tengán conexión directa.";
	cout << endl;
	bool sigo=true;
	
	do {
		
		indice_ciudad_b = 
			LeeEnteroEnRango("Indice de la primera ciudad: ", 1, numero_de_ciudades)-1;
			
		indice_ciudad_c = 
			LeeEnteroEnRango("Indice de la segunda ciudad: ", 1, numero_de_ciudades)-1;
		
		cout << endl;
		
		sigo = Ciudadesinterconexas(indice_ciudad_b, indice_ciudad_c, grafo)
			   && indice_ciudad_b!=indice_ciudad_c;
			
	} while(sigo);										  


	//d)
	//Vamos a pedir índices de ciudades hasta que nos den un negativo. 
	//Esos datos los vamos gaurdar en un array para poder decir cuales
	//de las ciudades estan directamente conectadas.
	
	int ind_ciudades[MAX_CIUDADES];
	int util_indices = 0;
	sigo = true;
	
	do {
		msg = "Indice de la ciudad numero "+to_string(util_indices+1)
			 +" de la lista: ";
			 
		ind_ciudades[util_indices] = LeeEntero(msg)-1;
		
		util_indices++;
	
		sigo = ind_ciudades[util_indices-1]>=0 
			   && ind_ciudades[util_indices-1]<numero_de_ciudades;
	} while(sigo);
	

/*------------------------------Operaciones-------------------------------*/
	
	Ciudad ciudad_max_conexiones;		 //Datos de la ciudad con más conexiones 
	ciudad_max_conexiones.posicion = 0;
	ciudad_max_conexiones.numero_de_conexiones = 0;	
	int conexiones_siguiente = 0;		 //Conexiones de la siguiente 
										 //ciudad a comprobar
	
	//Buscamos las conexiones de la primera ciudad
	ciudad_max_conexiones.numero_de_conexiones = ConexionesentreCiudades(0, grafo, numero_de_ciudades);
	
	//a)
	//Vamos comparando el numero de conexiones de cada ciudad con el máximo que
	//tengamos, y si es mayor esta pasa a ser máximo, así obtenemos la ciudad
	//con más conexiones. 
	for (int fila=0; fila<numero_de_ciudades; fila++) {
		conexiones_siguiente = 0;
		
		conexiones_siguiente = ConexionesentreCiudades(fila, grafo, numero_de_ciudades);
				
		if (ciudad_max_conexiones.numero_de_conexiones<conexiones_siguiente) {
			ciudad_max_conexiones.numero_de_conexiones = conexiones_siguiente;
			ciudad_max_conexiones.posicion = fila;
		}
	}
	
	//b)
	//Calculamos cuantas conexiones tiene la ciudad que se nos indicó
	num_conexiones_ciudad1 = ConexionesentreCiudades(index_ciudad, grafo, numero_de_ciudades);
	
	//c)
	//Vamos a calcular cual es la ruta más corta entre las ciudades b y c 
	//pasando por una única ciudad intermedia
	int intermedias[MAX_CIUDADES]; //Ciudades intermedias
	int util_inter = 0; 
	
	//Guardamos en un array las ciudades intermedias entre b y c
	bool es_intermedia = false;
	for (int fila=0; fila<numero_de_ciudades; fila++){
		
		es_intermedia = Ciudadesinterconexas(indice_ciudad_c, fila, grafo) 
		
						&& grafo[indice_ciudad_b][fila]>0;
		if (es_intermedia) {
			
			intermedias[util_inter] = fila;
			util_inter++;
		}
	}	
	
	//Distancia del camino más corto entre las ciudades b y c
	int distancia_min = grafo[indice_ciudad_c][intermedias[0]] 
						+ grafo[indice_ciudad_b][intermedias[0]];
	int ciudad_intermedia; //índice de la ciudad con el camino más corto
	int distancia;		   //Distancia del camino actual
	
	for (int i=0; i<util_inter; i++){
		
		distancia = grafo[indice_ciudad_c][intermedias[i]] 
					+ grafo[indice_ciudad_b][intermedias[i]];
					
		if (distancia_min>distancia){
			distancia_min = distancia;
			ciudad_intermedia = i;				
		}	
	}

	//d)
	//Ahora vamos a comrpbar si todas las ciudades de la lista de 
	//indices_ciudades están cocentadas entre sí
	bool todas_conectadas = true;
	bool estan_conectadas;
	
	for (int i=0; i<util_inter; i++)
		for(int n=i+1; i<util_inter; i++){
			
			estan_conectadas = ind_ciudades[i]==ind_ciudades[n] ||
					ConexionesentreCiudades(ind_ciudades[i], ind_ciudades[n], grafo);
					
			if (!estan_conectadas){
				todas_conectadas=false;
			}			
		}


							
	
	/*----------------------------Salida de datos-----------------------------*/
	
	//Mostramos los datos de la matriz, es decir, de la distancia entre ciudades
	cout << endl;
	cout << "Datos de distancia entre ciudades: ";
	cout << endl;
		
	cout << "  ";
	for (int fila=0; fila<numero_de_ciudades; fila++)
		cout << setw(3) << "C" << fila+1 ;
	cout << endl;
	
	for (int fila=0; fila<numero_de_ciudades; fila++) {
		cout << "C" << fila+1 ;
		for (int col=0; col<numero_de_ciudades; col++) 
			cout << setw(4) << grafo [fila][col];
		cout << endl;
	}
	cout << endl;
	
	//a)
	//Mostramos los datos de la ciudad con más conexiones
	cout << endl;
	cout << endl << "La ciudad con mas conexiones es C" 
				 <<  ciudad_max_conexiones.posicion+1 << " y esta conectada con "
				 <<  ciudad_max_conexiones.numero_de_conexiones << " ciudades.";

	//b)
	//Mostramos el número de conexiones que tenía la ciudad a
	cout << endl;
	cout << endl << "La ciudad " << indice_ciudad_a+1 << " tiene " 
		 << conexiones_ciudad_a << " uniones directas.";
	//c)
	//Mostramos la ciudad intermedia con el camino más corto entre b y c
	cout << endl;
	if (util_inter>0){
		cout << endl << "El camino mas corto entre las ciudades " 
			 << indice_ciudad_b+1 << " y " << indice_ciudad_c+1 << " es de " 
			 << distancia_min << " y es necasrio pasar por la ciudad " 
			 << ciudad_intermedia+1;		
	}
	else 
		cout << endl << "No existe una ciudad intermedia entre las ciudades " 
		<< indice_ciudad_b+1 << " y " << indice_ciudad_c+1;

	//d)
	//Vamos a mostrar si todas las ciudades de la lista que pedimos están
	//conectadas directamente
	cout << endl;
	if (todas_conectadas)
		cout << endl << "Todas las ciudades de la lista estan conectadas.";
	else
		cout << endl <<  "No todas las ciudades de la lista estan conectadas.";		
	
	
	return 0;
}



