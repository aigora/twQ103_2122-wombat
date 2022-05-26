#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

#define BUFFER_LEN 1024
#define NUM_PREGUNTAS 20

//INTRODUCIMOS UNA ESTRUCTURA QUE ALMACENA DATOS DEL USUARIO

struct jugador {
	char nombre_jugador[50];
	char contrasena_jugador[50];
	int puntuacionjugador;
	int dificultad;
	int pregunta_actual;
};
//INTRODUCIMOS LA FUNCION DIFICULTAD

int dificultad(){
	
	int opcion2;
	printf("Indique el nivel de dificultad que desea en su partida\n");
	printf("\n");
	printf("1.Facil\n2.Dificil\n");
	fflush(stdin);
	scanf("%d", &opcion2);
	
    return opcion2;
}


//INTRODUCIMOS LA FUNCION PARA IMPRIMIR LAS REGLAS

void reglas(){
			printf("\n");
			printf("\n");
	    	printf("Reglas del juego.\n");
	        printf("Para inciar tu partida en WOMBAT YINCANA, debes regristrarte o iniciar sesion si ya tienes una cuenta.\n");
			printf("El juego consta de 5 pruebas divididas en 5 preguntas cada una.\n");
		    printf("A medida que vayas respondiendo correctamente cada pregunta, se iran sumando tus puntos.\n");
		    printf("Las cuatro primeras preguntas tienen un valor de 5 puntos y la ultima de 10.\n");
		    printf("Para poder continuar con las siguientes pruebas, debes acumular un total minimo de 10 puntos.\n");
			printf("\n");
			printf("MUCHA SUERTE Y QUE COMIENCE EL JUEGO!\n ");
			printf("\n");
			printf("\n");
			printf("Pulsa cualquier caracter para volver al menu:\n ");
			printf("\n");
			printf("\n");
	
}

//INTRODUCIMOS LA FUNCION DEL BANNER PRINCIPAL

/*void banner(){
	printf("--------------------------------------------------*\n");
	char banner[]={"----{ WOMBAT YINCANA }------{ WOMBAT YINCANA }-----{ WOMBAT YINCANA }----"};
	unsigned short longitud, indice, espacio, repite, resto;
	
	//A CONTINUACION SE PROGRAMA EL BANNER
 
	longitud=strlen(banner);
	for (repite=1; repite<=2; repite++) /* repite el proceso 3 veces */
//	{
		// * IMPRIME EN ORDEN DE IZQUIERDA A DERECHA Y LUEGO DESPLAZA * 
	/*	for(resto=0; resto<=longitud; resto++) // para caracteres restantes a imprimir 
		{	for (indice=0; indice<=longitud-1-resto; indice++) // seleccion de indices evitando restantes 
			{
				printf("%c", banner[indice]); // imprime indice 
				if (!resto) usleep(1000); // demora el proceso 
			}
			for(espacio=1; espacio<=longitud-resto-1; espacio++)
				printf("\b"); // retrocede 
 
			if (resto) usleep(2000); // demora el proceso 
			printf("\b "); // borra el caracter actual 
		}
 
		for(espacio=1; espacio<=longitud; espacio++) // borra todos los caracteres presentados 
			printf("\b\b ");
		printf("\b"); // se coloca al inicio del desplegado
	}*/
/*	printf("----{ WOMBAT YINCANA }------{ WOMBAT YINCANA }-----{ WOMBAT YINCANA }----\n");
	printf("--------------------------------------------------*\n");
	
}*/

//INTRODUCIMOS LA FUNCIÓN DE UN BANNER FIJO 

void banner_fijo(){
	printf("--------------------------------------------------*\n");
	printf("-------{ WOMBAT YINCANA }------{ WOMBAT YINCANA }-----{ WOMBAT YINCANA }------*\n");
	printf("--------------------------------------------------*\n");
	
}

void preguntas_facil(int pregunta_actual){
	
	switch(pregunta_actual){
		case 1:{
			printf("Escribe MMXXVI en números naturales:");
			break;
		}
		case 2:{
			printf("La raiz de 15625 es:");
			break;
		}
		case 3:{
			printf("Halla el valor de x=3(14+12-20):(9+3)x:");
			break;
		}
		case 4:{
			printf("Realiza la siguiente operación: 4/3 - 5/6:");
			break;
		}
		case 5:{
			printf("¿Cuál de las siguientes es una suma y resta de monomios: 1)2xy-2x+2y, 2) 2+2, 3)3x+4:");
			break;
		}	
		case 6:{
			printf("Resuelve esta ecuación: (x+28) + 15 = 2(x+15):");
			break;
		}	
		case 7:{
			printf("Cambia las unidades a m^2: 1005km^2 :");
			break;
		}	
		case 8:{
			printf("¿Cuántas botellas de vino de un litro de capacidad se pueden llenar con un tonel de un hectolitro?:");
			break;
		}	
		case 9:{
			printf("El 60% del cuerpo humano es agua. ¿Qué litros de agua hay en una persona de 75 kg?:");
			break;
		}	
		case 10:{
			printf("Expresa en segundos 2° 3' 40:");
			break;
		}	
		case 11:{
			printf("Obtén el ángulo el suplementario de 75º:");
			break;
		}	
		case 12:{
			printf("¿Cuantos lados tiene un hexagono?:");
			break;
		}	
		case 13:{
			printf("En un triángulo rectángulo, un ángulo mide 30°. ¿Cuánto mide el tercer ángulo?:");
			break;
		}	
		case 14:{
			printf("En un triángulo rectángulo, los catetos miden 5 y 12 cm, respectivamente. ¿Cuántos cm medirá la hipotenusa?:");
			break;
		}	
		case 15:{
			printf("Halla el valor del coseno de 0:");
			break;
		}	
		case 16:{
			printf("Simplifica la siguiente fraccion 24/27:");
			break;
		}	
		case 17:{
			printf("Si la longitud de la circunferencia es 25 cm, ¿cuántos cm mide su radio?:");
			break;
		}	
		case 18:{
			printf("Determina el área (cm2) de un triángulo de base 4 cm y altura 7 cm.:");
			break;
		}	
		case 19:{
			printf("¿Qué número se tiene que restar al cuadrado de 5 para que el resultado sea 10?:");
			break;
		}	
		case 20:{
			printf("Halla el valor de:9/15=x/5:");
			break;
		}		
	
}
}

int respuestas_facil(int numero_pregunta, int respuesta_jugador){
	
	int solucion=0;
	
	switch(numero_pregunta){
		case 1:{
			if(numero_pregunta == 2026){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
		}
	
		case 2:{
			if(respuesta_jugador == 125){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
		}
		case 3:{
			if(respuesta_jugador == 1){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
				break;
			}
		}
			case 4:{
			if(respuesta_jugador == 3/6){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 5:{
			if(respuesta_jugador == 1){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 6:{
			if(respuesta_jugador == 13){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 7:{
			if(respuesta_jugador == 1005000000){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }case 8:{
			if(respuesta_jugador == 100){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 9:{
			if(respuesta_jugador ==45 ){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 10:{
			if(respuesta_jugador == 7.420){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 11:{
			if(respuesta_jugador ==105 ){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 12:{
			if(respuesta_jugador ==6 ){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 13:{
			if(respuesta_jugador == 60){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 14:{
			if(respuesta_jugador == 13){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 15:{
			if(respuesta_jugador == 1){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 16:{
			if(respuesta_jugador == 8/9){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 17:{
			if(respuesta_jugador == 3,98){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 18:{
			if(respuesta_jugador == 14){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 19:{
			if(respuesta_jugador == 10){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 20:{
			if(respuesta_jugador ==3 ){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
		  }
          
	
	
	return solucion;
}


void preguntas_dificil(int pregunta_actual){

 switch(pregunta_actual){
		case 1:{
			printf("¿Cuánto son tres quintos del tercio de 55?:");
			break;
		}
		case 2:{
			printf("Si en una carrera vas tres puntos por delante del vigésimo segundo,¿en que puesto vas?:");
			break;
		}
		case 3:{
			printf("¿Cuántos mentros tiene un hectometro?:");
			break;
		}
		case 4:{
			printf("¿Cuántos años son un lustro?:");
			break;
		}
		case 5:{
			printf("¿Cuanto es el valor de la tangente de pi/4?:");
			break;
		}	
		case 6:{
			printf("¿Cuantas caras tiene un icosaedro?:");
			break;
		}	
		case 7:{
			printf("Halla el valor de x en la siguiente ecuacion:sen(x)+8=16:");
			break;
		}	
		case 8:{
			printf("¿Tienes solución:arctg(x)=38? 1 si 2 no");
			break;
		}	
		case 9:{
			printf("El tablero de ajedrez es un cuadrado formado por 8 filas,con 8 cuadrados en cada fila,¿cuántos cuadrados hay en total?:");
			break;
		}	
		case 10:{
			printf("VERDADERO 1 O FALSO 2, La sumade los ángulos externos de un tria´ngulo es 180:");
			break;
		}	
		case 11:{
			printf("¿Cuánto vale -[-(-6+4)]?:");
			break;
		}	
		case 12:{
			printf("Euclides,fanoso geómetra,murió en el añ 265a.C y vivió 60 años,¿en que año nació?");
			break;
		}	
		case 13:{
			printf("Opera:(16-x)/7=1:");
			break;
		}	
		case 14:{
			printf("Calcula (dm3):17hm3+340dm3:");
			break;
		}	
		case 15:{
			printf("Con un consumo de 3 horas diarias, un depósito de gas dura 20 días. ¿Cuántas horas duraría con un consumo de 6 horas diarias?:");
			break;
		}	
		case 16:{
			printf("Calcula el 30% de 40:");
			break;
		}	
		case 17:{
			printf("Halla el perímetro (cm) de un rombo cuyo lado mide 10 cm:");
			break;
		}	
		case 18:{
			printf(" Determina el área (cm2) de un romboide de base 8 cm y altura 5 cm:");
			break;
		}	
		case 19:{
			printf("¿Cuál es el número mínimo de vértices y de caras de una pirámide?:");
			break;
		}	
		case 20:{
			printf("PERTENECE 1 O NO PERTENCE 2 la siguiente función al punto (5, -2) y = 2x – 3:");
			break;
		}		
	
}
}

int respuestas_dificil(int numero_pregunta, int respuesta_jugador){
	
	int solucion=0;
	
	switch(numero_pregunta){
		case 1:{
			if(numero_pregunta == 11){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
		}
	
		case 2:{
			if(respuesta_jugador == 19){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
		}
		case 3:{
			if(respuesta_jugador == 100){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
				break;
			}
		}
			case 4:{
			if(respuesta_jugador == 5){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 5:{
			if(respuesta_jugador == 1){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 6:{
			if(respuesta_jugador == 20){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 7:{
			if(respuesta_jugador == 8){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }case 8:{
			if(respuesta_jugador == 2){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 9:{
			if(respuesta_jugador ==64 ){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 10:{
			if(respuesta_jugador == 2){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 11:{
			if(respuesta_jugador ==-2 ){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 12:{
			if(respuesta_jugador ==325){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 13:{
			if(respuesta_jugador == 9){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 14:{
			if(respuesta_jugador == 17000000000340){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 15:{
			if(respuesta_jugador == 10){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 16:{
			if(respuesta_jugador == 12){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 17:{
			if(respuesta_jugador == 40){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 18:{
			if(respuesta_jugador == 40){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 19:{
			if(respuesta_jugador == 4){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
          case 20:{
			if(respuesta_jugador ==1 ){
				printf("\nRespuesta correcta.\n");
				solucion = 1;
			}else{
				printf("\nRespuesta incorrecta.\n");
			}
			break;
          }
		  }
          
	
	
	return solucion;
}

// Main del programa
	
int main(){
	
	setlocale(LC_CTYPE,"Spanish");//CODIFICAMOS EL IDIOMA A ESPAÑOL PARA PODER UTILIZAR LETRAS COMO LA Ñ DE ESPAÑA
	
	system ("color e0");//CODIFICAMOS EL COLOR: AMARILLO PARA EL FONDO Y EL NEGRO PARA LAS LETRAS

 	int num_jugadores=0,i=0,q,zor,opcion2, dificultad_escogida, respuesta;	
	int longitud1,numero, contador=0, imprimirMenu,opcion,salir_del_juego=0,salir_al_menu, R, U, S;
	
	
	struct jugador PLAYER[4];
	
	//Introducimos la funcion que crea el banner
	// banner();
		
	
	//MENU : REGLAS, REGISTRO ,SALIR
	
	zor=1;		//Inicializamos el bucle while
	
	while(zor=1){
		
	system("cls");
	banner_fijo();
	
	printf("BIENVENIDO AL MENU PRINCIPAL :\n");
	printf("Escoge entre las distintas opciones que presenta el videojuego\n");
	printf(" 1 - Para visualizar las reglas del juego\n 2 - Registrate , para a continuacion  jugar\n 3 - Para salir del programa\n");
	fflush(stdin);
	scanf("%d", &opcion);
	system("cls");
	
	
	switch(opcion){
		case 1: {
			banner_fijo();
			reglas();	
			fflush(stdin);
			system("pause");
			system("cls");
			break;
		}
	
		case 2:{
			
			struct jugador PLAYER[4]={{" "," ",0,0,1},{" "," ",0,0,1},{" "," ",0,0,1},{" "," ",0,0,1}};
			
			banner_fijo();
					
			do{
		    	printf("Introduce el numero de jugadores, hay posibilidad de que jueguen (solo se puede hasta 4 personas):");
				scanf("%d", &num_jugadores);
				
				if(num_jugadores>0 || num_jugadores < 5){
					printf("El numero de jugadores debe estar entre uno y cuatro jugadores.\n\n");
			}
				
			}while(num_jugadores<0 || num_jugadores > 5);
				
			q++;
	    	
			i=0;
			
			system("cls");
			banner_fijo();	
			// Registro de jugadores
			for(i=0;i<num_jugadores;i++){
					
				printf("Jugador %d Introduzca su nombre de usuario:\n",i+1);
				fflush(stdin);
				scanf("%[^\n]s", PLAYER[i].nombre_jugador);
				printf("\n");
	
				printf("Introduce tu contrasena jugador %d \n",i+1);
				fflush(stdin);
				scanf("%[^\n]s", PLAYER[i].contrasena_jugador);
				printf("\n");
				
			}
	
			system("cls");		//CON ESTO BORRAMOS LO QUE HAY EN LA PANTALLA
			i=0;
			// Con esta función indicamos el nivel de dificultad.
			dificultad_escogida = dificultad();
			
			for(i=0;i<num_jugadores;i++){
				PLAYER[i].dificultad = dificultad_escogida;
			}
			system("pause");
	
			// INICIAR EL JUEGO AQUI.
			
			for(i=0;i<num_jugadores;i++){
				int j=0, solucionario;
				
				if(PLAYER[i].dificultad == 1){
				// Abrimos aquí la dificultad de fácil.
					for(j=0;j<NUM_PREGUNTAS;j++){
						
						preguntas_facil(PLAYER[i].pregunta_actual);
						
						printf("\nRespuesta:");
						scanf("%d",&respuesta);
						
						solucionario = respuestas_facil(PLAYER[i].pregunta_actual, respuesta);
						if(solucionario == 1){
							PLAYER[i].puntuacionjugador += 10;
						}
						
						PLAYER[i].pregunta_actual += 1;
						system("pause");	
					}
					
					if(PLAYER[i].pregunta_actual == 20){
						printf("\nEs el turno del siguiente jugador.\n\n%cPreparado, jugador %s?", 168, PLAYER[i+1].nombre_jugador);
					}
								
				}else{
				// Abrimos aquí la dificultad dificil.	
					if(PLAYER[i].dificultad == 1){
				
					for(j=0;j<NUM_PREGUNTAS;j++){
						
						preguntas_dificil(PLAYER[i].pregunta_actual);
						
						printf("\nRespuesta:");
						scanf("%d",&respuesta);
						
						solucionario = respuestas_dificil(PLAYER[i].pregunta_actual, respuesta);
						if(solucionario == 1){
							PLAYER[i].puntuacionjugador += 10;
						}
						
						PLAYER[i].pregunta_actual += 1;
						system("pause");	
					}
					
					if(PLAYER[i].pregunta_actual == 20){
						printf("\nEs el turno del siguiente jugador.\n\n%cPreparado, jugador %s?", 168, PLAYER[i+1].nombre_jugador);
					}	
					
				}
			
				// Aquí recogemos los datos uno a uno de los jugadores según vayan acabando. Quita el comentario para probar que compila.
				// recoger_datos(PLAYER[i].nombre_jugador, PLAYER[i].dificultad, PLAYER[i].puntuacionjugador);

				
			}
			
			// Aquí se ha acabado el juego y recogeriamos los datos de los jugadores.
	
			zor=0;
			break;
				
		} 
	case 3 :{
		banner_fijo();
		printf("¿Seguro que desea salir del juego?\n");
		do{
			printf("Teclea '1' para salir del juego.\n");
			printf("Teclea '2' para volver al menu del juego.\n");
			fflush(stdin);
			scanf("%d", &salir_del_juego);
			if(salir_del_juego==1){
				printf("Saliendo del juego...\n");
				printf("Hasta pronto, les esperamos en su proxima partida de WOMBAT.\n");
				exit(0);
					}
			else if(salir_del_juego==2){
					printf("Volviendo al menu...\n");
					zor=1;
					break;
			}else{
				printf("El caracter/numero introducido no es una opcion posible a escoger.\n\n");
			}
				
		}while(salir_del_juego<1 || salir_del_juego > 2);
		
		}
			
		default:{
			printf("El numero introducido es erroneo para el programa. Asegurese de que el numero este bien escrito.\n");
			system("pause");
			opcion=0;
			break;
		}
	}
}
	
	
	system("cls");
	banner_fijo();
	dificultad();
	
	
	return 0;
	
}
