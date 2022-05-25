#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <windows.h>

#define BUFFER_LEN 1024


//INTRODUCIMOS UNA ESTRUCTURA QUE ALMACENA DATOS DEL USUARIO

struct jugador {
	char nombre_jugador[50];
	char contrasena_jugador[50];
	char pais_jugador[50];
	char correo_jugador[50];
	int puntuacionjugador;
};
//INTRODUCIMOS LA FUNCION DIFICULTAD

void dificultad(){
	int opcion2;
	printf("Indique el nivel de dificultad que desea en su partida\n");
	printf("\n");
	printf("1.Facil\n2.Medio\n3.Dificil\n");
	fflush(stdin);
	scanf("%d", &opcion2);
}

//INTRODUCIMOS LA FUNCION REGISTRO DE USUARIO

void registro_usuario(){
	
}

//INTRODUCIMOS LA FUNCION DEL BANNER PRINCIPAL

void banner(){
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	char banner[]={"*-*-*-*-{ WOMBAT YINCANA }-*-*-*-*-*-{ WOMBAT YINCANA }-*-*-*-*-*{ WOMBAT YINCANA }-*-*-*-*"};
	unsigned short longitud, indice, espacio, repite, resto;
	
	//A CONTINUACION SE PROGRAMA EL BANNER
 
	longitud=strlen(banner);
	for (repite=1; repite<=2; repite++) /* repite el proceso 3 veces */
	{
		// ******** IMPRIME EN ORDEN DE IZQUIERDA A DERECHA Y LUEGO DESPLAZA ******** 
		for(resto=0; resto<=longitud; resto++) // para caracteres restantes a imprimir 
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
	}
	printf("*-*-*-*-{ WOMBAT YINCANA }-*-*-*-*-*-{ WOMBAT YINCANA }-*-*-*-*-*{ WOMBAT YINCANA }-*-*-*-*\n");
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	
}

//INTRODUCIMOS LA FUNCIÓN DE UN BANNER FIJO 

void banner_fijo(){
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("*-*-*-*-*-*-*-{ WOMBAT YINCANA }-*-*-*-*-*-{ WOMBAT YINCANA }-*-*-*-*-*{ WOMBAT YINCANA }-*-*-*-*-*-*\n");
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	
}

// Main del programa
	
int main(){

 	int numero_jugadores, opcion2;	
	int longitud1,numero, contador=0, imprimirMenu,opcion,salir_del_juego,salir_al_menu, R, U, S;
	int num_jugadores,i,q,zor;
	
		system ("color e0");
	
	struct jugador PLAYER[4];
	
	//Introducimos la funcion que crea el banner
	banner();
		
	
	//MENU : REGLAS, REGISTRO ,SALIR
	
	zor=1;
	
	while(zor=1){
		
	system("cls");
	banner_fijo();
	
	printf("BIENVENIDO AL MENU PRINCIPAL :\n");
	printf("Escoge entre las distintas opciones que presenta el videojuego\n");
	printf(" 1 - Para visualizar las reglas del juego\n 2 - Usuario y contrasena, para a continuacion  jugar\n 3 - Para salir del programa\n");
	fflush(stdin);
	scanf("%d", &opcion);
	system("cls");
	
	
	if(opcion==1){	// REGLAS
		
		banner_fijo();
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
				
			fflush(stdin);
			scanf("%d", &salir_al_menu);
			if(salir_al_menu==1){
				q=1;	
				}
				else{
					q=1;
				}
		}
			    
	else if(opcion==2){ // USUARIO Y CONTRASEÑA
		
		
			banner_fijo();
		
		   	printf("Introduce el numero de jugadores, hay posibilidad de que jueguen\n");
			printf(" hasta 4 personas:\n");
			fflush(stdin);
			scanf("%d", &num_jugadores);
			printf("\n");	
			q++;
	    	struct jugador PLAYER[4];
			i=1;
			
			while(i<=num_jugadores){
				
			system("cls");
			banner_fijo();
				
			printf("Jugador %d Introduzca su nombre de usuario:\n",i);
			fflush(stdin);
			scanf("%s", &PLAYER[i].nombre_jugador);
			printf("\n");
								
			printf("Introduce tu contrasena jugador %d \n",i);
			fflush(stdin);
			scanf("%s", &PLAYER[i].contrasena_jugador);
			printf("\n");
			
			printf("Jugador %d introduce tu pais de origen:\n",i);
			fflush(stdin);
			scanf("%s", &PLAYER[i].pais_jugador);
			printf("\n");
		
			printf("Introduce tu correo jugador %d\n",i);
			fflush(stdin);
			scanf("%s", &PLAYER[i].correo_jugador);
			printf("\n");
			system("cls");		//CON ESTO BORRAMOS LO QUE HAY EN LA PANTALLA
			i++;
				}
				zor++;
				break;
				
		    }
	else if(opcion==3){	// SALIR DEL PROGRAMA
				
		banner_fijo();
		printf("Saliendo del juego...\n");
		printf("Hasta pronto, les esperamos en su proxima partida de WOMBAT.\n");
		printf("Teclea 1 para salir del juego.\n");
		printf("Teclea cualquier caracter para volver al menu del juego.\n");
		fflush(stdin);
		scanf("%d", &salir_del_juego);
		if(salir_del_juego==1){
			printf("leo la s\n");
			
					return 0;
				}
		else{
				zor=1;
				printf("Volviendo al menu...\n");
				}
			}
	
	else{
		zor=1;
		printf("Introduzca de nuevo su respuesta, no he podido comprender la anterior\n");
			
	}
	
	}
	
	system("cls");
	banner_fijo();
	dificultad();
	
	return 0;
	
}
