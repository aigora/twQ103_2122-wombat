#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <windows.h>

#define BUFFER_LEN 1024


struct jugador {
	char numero_jugadores[2];
	char nombre_jugador[50];
	char contrasena_jugador[6];
	
};

// Main del programa
	
int main(){

 	int numero_jugadores, jugador1, jugador2, opcion1, opcion2, nombre_jugador1, nombre_jugador2,contrasena_jugador1,contrasena_jugador2;	
	int longitud1,numero, contador=0, imprimirMenu, opcion, R, U, S, r, s, u;
 	jugador1=1;
 	jugador2=1;
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
				if (!resto) usleep(100); // demora el proceso 
			}
			for(espacio=1; espacio<=longitud-resto-1; espacio++)
				printf("\b"); // retrocede 
 
			if (resto) usleep(200); // demora el proceso 
			printf("\b "); // borra el caracter actual 
		}
 
		for(espacio=1; espacio<=longitud; espacio++) // borra todos los caracteres presentados 
			printf("\b\b ");
		printf("\b"); // se coloca al inicio del desplegado
	}
	printf("*-*-*-*-{ WOMBAT YINCANA }-*-*-*-*-*-{ WOMBAT YINCANA }-*-*-*-*-*{ WOMBAT YINCANA }-*-*-*-*\n");
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	
	//MENU : REGLAS, REGISTRO
	
	// Menú de opciones
	printf("Imprimir menu de opciones:\n");
	printf("R - Reglas del juego\nU - Usuario y contrasena para jugar\nS - Salir del programa\n");
	fflush(stdin);
	scanf("%c", &opcion);
	   
	    switch (opcion) {
		    case 'R' :  // REGLAS
		        printf("Reglas del juego.\n");
		        printf("\n");
			    printf("Bienvenido a Wombat.\n");
			    printf("\n");
			    printf("\n ");
			    printf("\n");
				printf("\n ");
			    
		    case 'U' :
		    	// USUARIO Y CONTRASEÑA
		    	printf("Introduce el numero de jugadores 1 (solitario) o 2 (1v1):\n");
				fflush(stdin);
				scanf("%c", &opcion1);
				printf("\n");
		
				switch(opcion1){
					case '1':
						printf("1 jugador. Introduzca su nombre de usuario:\n");
						fflush(stdin);
						scanf("%s", &nombre_jugador1);
					
						printf("Introduce tu contrasena jugador 1\n");
	        			fflush(stdin);
		        		scanf("%c", &contrasena_jugador1);
		        		printf("\n");
		        
		        	break;
			
			
					case '2':
						printf("Jugador 1. Introduzca su nombre de usuario:\n");
						fflush(stdin);
						scanf("%s", &nombre_jugador1);
						printf("\n");
				
						printf("Introduce tu contrasena jugador 1\n");
	         			fflush(stdin);
						scanf("%c", &contrasena_jugador1);
						printf("\n");
				
						printf("Jugador 2. Introduzca su nombre de usuario:\n");
						fflush(stdin);
						scanf("%s", &nombre_jugador2);
						printf("\n");
				
						printf("Introduce tu contrasena jugador 2\n");
						fflush(stdin);
						scanf("%c", &contrasena_jugador2);
						printf("\n");
						
				} break;

			case 'S': // SALIR DEL PROGRAMA
				printf("Salir del juego");
				printf("Hasta pronto, les esperamos en su proxima partida de WOMBAT");
				return 0;
				
		}
		
		printf("Indique el nivel de dificultad que desea en su partida\n");
		printf("\n");
		printf("1.Facil\n2.Medio\n3.Dificil\n");
		scanf("%d", &opcion2);
	
	
	return 0;
}
