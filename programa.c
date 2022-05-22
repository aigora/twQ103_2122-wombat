#include <stdio.h>

struct jugador {
	char numero_jugadores[2];
	char nombre_jugador[50];
	
};


// Main del programa

int main () {
	
	int i, numero_jugadores, jugador1, jugador2, opcion1, nombre_jugador1, nombre_jugador2;
	
	do{
		printf("Introduce el numero de jugadores 1 (solitario) o 2 (1v1):\n");
		fflush(stdin);
		scanf("%c", &numero_jugadores);
		printf("\n");
		
		switch(opcion1){
			case '1':
				printf("1 jugador. Introduzca su nombre de usuario:\n");
				fflush(stdin);
				scanf("%s", &nombre_jugador1);
				
			case '2':
				printf("1 jugador. Introduzca su nombre de usuario:\n");
				fflush(stdin);
				scanf("%s", &nombre_jugador1);
				printf("\n");
				
				printf("1 jugador. Introduzca su nombre de usuario:\n");
				fflush(stdin);
				scanf("%s", &nombre_jugador2);
				printf("\n");
		}
		
	}
	while (jugador1 == 1 && jugador2 == 1);
	
	printf(".....Inicio de la partida.....\n");
	printf("\n");
	printf("Comencemos con la primera prueba:\n");
	printf("\n");
	printf("..........PRUEBA 1..........\n");
	printf("\n");
	
	
	
	return 0;
}
