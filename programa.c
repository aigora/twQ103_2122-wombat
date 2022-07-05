#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>

#define MAX 80
#define ARCHIVO_USUARIOS "usuarios.dat"
#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define LONGITUD 5
#define MAX_INTENTOS 3



struct jugador{
	
	char nombre_jugador[MAX];
	int puntuacionjugador;
	int dificultad;
	int pregunta_actual;
};


/* Estructura de cuentas de usuario */
struct usuario {
	char nombre[MAX];
	char password[MAX];
};

typedef struct usuario Usuario;

/* Funciones de menú */
void menuInicial();
void menuListarUsuarios();
void menuRegistrarUsuario();
void menuIniciarSesion();
void menuSistema();
void reglas();

/* Funciones que manipulan el archivo de usuarios */
char insertarUsuario(Usuario usuario);
char existeUsuario(char nombreUsuario[], Usuario *usuario);
Usuario *obtenerUsuarios(int *);
char logear(char nombreUsuario[], char password[]);

int leerLinea(char *cad, int n);
void leerClave(char *password);

void datoswombat();
void preguntas_facil(int pregunta_actual);
int respuestas_facil(int numero_pregunta,int respuesta_jugador);
void preguntas_dificil(int pregunta_actual);
int respuestas_dificil(int numero_pregunta, int respuesta_jugador);

char linea[MAX];


int main() {
	menuInicial();
	return 0;
}

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
	
}

void menuInicial() {
	
	setlocale(LC_CTYPE,"Spanish");//CODIFICAMOS EL IDIOMA A ESPAÑOL PARA PODER UTILIZAR LETRAS COMO LA Ñ DE ESPAÑA
	
	Usuario usuario;
	char repite = 1;
	int opcion = -1;
	int farandul;
	farandul=1;
	system ("color e0");//CODIFICAMOS EL COLOR: AMARILLO PARA EL FONDO Y EL NEGRO PARA LAS LETRAS

	
	do {
		system("cls");
		
		if(farandul==1){
			banner();
		}else{
		banner_fijo();
		}
				
		printf("\t\t\tMENU PRINCIPAL\n");
		printf("\n\t\t[1]. Ver jugadores registrados\n");
		printf("\t\t[2]. Registrar jugador nuevo\n");
		printf("\t\t[3]. Jugar\n");
		printf("\t\t[4]. Reglas del juego\n");
		printf("\t\t[5]. A cerca de los WOMBAT\n");
		printf("\t\t[0]. Salir\n");
		printf("\n\t\tIngrese su opcion: [ ]\b\b");
		leerLinea(linea, MAX);
		sscanf(linea, "%d", &opcion);
		farandul++;

		switch (opcion) {
			case 1:
				system("cls");		
				banner_fijo();
				menuListarUsuarios();
				farandul++;
				break;

			case 2:
				system("cls");		
				banner_fijo();
				menuRegistrarUsuario();
				farandul++;
				break;

			case 3:
				system("cls");		
				banner_fijo();
				menuIniciarSesion();
				farandul++;
				break;

			case 4:
				system("cls");		
				banner_fijo();
				reglas();
				system("pause");
				break;
				
			case 5:
				system("cls");		
				banner_fijo();
				datoswombat();
				system("pause");
				farandul++;
				break;
				
			case 0:
				system("cls");		
				banner_fijo();
				printf("HASTA PRONTO!!\n");
				repite = 0;
				break;
		}

	} while (repite == 1);
}

void menuRegistrarUsuario() {
	Usuario usuario;
	char nombreUsuario[MAX];
	char respuesta[MAX];
	char repite = 1;
	
	do {
		system("cls");
		printf("\n\t\t\tREGISTRAR JUGADOR\n");
		printf("\t\t\t=================\n");
		printf("\n\tIngrese nombre de usuario: ");
		leerLinea(linea, MAX);
		sscanf(linea, "%s", nombreUsuario);

		/* Se verifica que el nombre de usuario no exista */
		if (!existeUsuario(nombreUsuario, &usuario)) {
			strcpy(usuario.nombre, nombreUsuario);

			printf("\tIngrese la clave: ");
			leerLinea(usuario.password, MAX);

			/* Se inserta el usuario en el archivo de usuarios */
			if (insertarUsuario(usuario)) {
				printf("\n\tEl jugador fue registrado satisfactoriamente!\n");

			} else {
				printf("\n\tOcurrio un error al registrar el jugador\n");
				printf("\nInténtelo mas tarde\n");
			}
		} else {
			printf("\n\tEl usuario \"%s\" ya ha sido registrado previamente\n", usuario.nombre);
			printf("\tNo puede registrar dos usuarios con el mismo nombre de usuario.\n");
		}

		printf("\n\tDesea seguir registrando usuarios? [S/N]: ");
		leerLinea(respuesta, MAX);
 
		if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
			repite = 0;
		}

	} while (repite == 1);
}

void menuListarUsuarios() {
	int numeroUsuarios;
	Usuario *usuarios;
	int i;

	system("cls");
	usuarios = obtenerUsuarios(&numeroUsuarios); /* Retorna un vector dinámico de usuarios */

	if (numeroUsuarios == 0) {
		printf("\n\tNo existe ningun usuario registrado!\n");

	} else {
		printf("\n\t\t    ==> LISTADO DE JUGADORES <==\n");
		printf(" ------------------------------------------------------------------------------\n");
		printf("%10s%25s%25s\n", "#", "NOMBRE", "CONTRASEÑA");
		printf(" ------------------------------------------------------------------------------\n");

		/* Se recorre el vector dinámico de productos */
		for (i = 0; i < numeroUsuarios; i++) {
			printf("%10d%25s%25s\n", (i + 1), usuarios[i].nombre, usuarios[i].password);
		}
		printf(" ------------------------------------------------------------------------------\n");
	}

	// Se libera la memoria asignada al vector dinámico
	free(usuarios);
	usuarios = NULL;
	getchar();
}

void menuIniciarSesion() {
	
	
	char nombreUsuario[MAX];
	char password[MAX];
	int intento = 0;
	int loginExitoso = 0;

	do {
		system("cls");
		printf("\n\t\t\tINGRESAR AL SISTEMA\n");
		printf("\t\t\t===================\n");

		printf("\n\t\tUSUARIO: ");
		leerLinea(linea, MAX);
		sscanf(linea, "%s", nombreUsuario);

		printf("\t\tCLAVE: ");
		leerClave(password);
		
		if (logear(nombreUsuario, password)) {
			loginExitoso = 1;
		} else {
			printf("\n\n\t\tUsuario y/o password incorrectos");
			intento++;
			getchar();
		}
	} while (intento < MAX_INTENTOS && loginExitoso == 0);

	if (loginExitoso == 1) {
		menuSistema();
		
	} else {
		printf("\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
		getchar();
	}
}

int banner(){
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

int banner_fijo(){
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("*-*-*-*-*-*-*-{ WOMBAT YINCANA }-*-*-*-*-*-{ WOMBAT YINCANA }-*-*-*-*-*{ WOMBAT YINCANA }-*-*-*-*-*-*\n");
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	
}

//INTRODUCIMOS LA FUNCION PARA EL VIDEOJUEGO

void menuSistema() {
	
	int q,i,dificultad_escogida,NUM_PREGUNTAS,respuesta;
	
	
	system("cls");
	banner_fijo();
	printf("\n     =========================================================================\n");
	printf("\t\t\t     BIENVENIDO A LA MADRIGUERA\n");
	printf("\t\t  Deberemos resolver preguntas matematicas para asi conseguir\n");
	printf("\t\t   que nuestro amigo el wombat consiga salir a la superficie\n");

	printf("     =========================================================================\n");

	printf("\n\t\tAqui va todo el contenido del sistema ;)");
	
	
	getchar();
}

/* Retorna 1 si se registró el usuario en el archivo correctamente */
char insertarUsuario(Usuario usuario){
	FILE *archivo;
	char insercion = 0;

	/* Abre el archivo en modo de añadidura, para agregar datos al final. Si no existe es creado*/
	archivo = fopen(ARCHIVO_USUARIOS, "ab");

	if (archivo == NULL) {
		insercion = 0;

	} else {
		/* Registra el struct usuario en el archivo */
		fwrite(&usuario, sizeof(usuario), 1, archivo);
		insercion = 1;

		/* Cierra el archivo */
		fclose(archivo);
	}

	return insercion;
}

/* Retorna 1 si existe el nombre de usuario. Retorna el usuario buscado si existe */
char existeUsuario(char nombreUsuario[], Usuario* usuario){
	FILE *archivo;
	char existe;

	/* Abre el archivo en modo de lectura */
	archivo = fopen(ARCHIVO_USUARIOS, "rb");

	if (archivo == NULL) {
		existe = 0;

	} else {
		existe = 0;

		/* Lee secuencialmente del archivo de usuarios */
		fread(&(*usuario), sizeof(*usuario), 1, archivo);
		while (!feof(archivo)) {
			if (strcmp((*usuario).nombre, nombreUsuario) == 0) {
				/* Encuentra un usuario del archivo con el nombre de usuario buscado */
				existe = 1;
				break;
			}

			fread(&(*usuario), sizeof(*usuario), 1, archivo);
		}

		/* Cierra el archivo*/
		fclose(archivo);
	}

	return existe;
}

Usuario *obtenerUsuarios(int *n) {
	FILE *archivo;
	Usuario usuario;
	Usuario *usuarios; /* Vector dinámico de usuarios */
	int i;

	/* Abre el archivo en modo lectura */
	archivo = fopen(ARCHIVO_USUARIOS, "rb");
 
	if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
		*n = 0; /* No se pudo abrir. Se considera n = 0 */
		usuarios = NULL;
 
	} else {
 
		fseek(archivo, 0, SEEK_END); /* Posiciona el cursor al final del archivo */
		*n = ftell(archivo) / sizeof(Usuario); /* # de usuarios almacenados en el archivo. (# de registros) */
		usuarios = (Usuario *)malloc((*n) * sizeof(Usuario)); /* Se asigna memoria para todos los usuarios almacenados en el archivo */
 
		/* Se recorre el archivo secuencialmente */
		fseek(archivo, 0, SEEK_SET); /* Posiciona el cursor al principio del archivo */
		fread(&usuario, sizeof(usuario), 1, archivo);
		i = 0;
		while (!feof(archivo)) {
			usuarios[i++] = usuario;
			fread(&usuario, sizeof(usuario), 1, archivo);
		}
 
		/* Cierra el archivo */
		fclose(archivo);
	}
 
	return usuarios;
}

/* Retorna 1 o 0 si el usuario y password son correctos para un usuario en particular */
char logear(char nombreUsuario[], char password[]) {
	FILE *archivo;
	char logeoExitoso;
	Usuario usuario;

	/* Abre el archivo en modo de lectura */
	archivo = fopen(ARCHIVO_USUARIOS, "rb");

	if (archivo == NULL) {
		logeoExitoso = 0;

	} else {
		logeoExitoso = 0;

		/* Lee secuencialmente del archivo de usuarios */
		fread(&usuario, sizeof(usuario), 1, archivo);
		while (!feof(archivo)) {
			if (strcmp(usuario.nombre, nombreUsuario) == 0 && strcmp(usuario.password, password) == 0) {
				/* Encuentra un usuario del archivo con el nombre de usuario y password buscado */
				logeoExitoso = 1;
				break;
			}

			fread(&usuario, sizeof(usuario), 1, archivo);
		}

		/* Cierra el archivo*/
		fclose(archivo);
	}

	return logeoExitoso;
}
	
int leerLinea(char *cad, int n)
{
	int i, c;

	/* 1 COMPROBACIÓN DE DATOS INICIALES EN EL BUFFER */
	c = getchar();
	if (c == EOF) {
		cad[0] = '\0';
		return 0;
	}

	if (c == '\n') {
		i = 0;
	} else {
		cad[0] = c;
		i = 1;
	}

	/* 2. LECTURA DE LA CADENA */
	for (; i < n - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		cad[i] = c;
	}
	cad[i] = '\0';

	/*3. LIMPIEZA DEL BUFFER */ 
	if (c != '\n' && c != EOF) /* es un caracter */
		while ((c = getchar()) != '\n' && c != EOF);
 
	return 1;
}

void leerClave(char *password) {
	char caracter;
	int i = 0;

	while (caracter = getch()) {
		if (caracter == TECLA_ENTER) {
			password[i] = '\0';
			break;
			
		} else if (caracter == TECLA_BACKSPACE) {
			if (i > 0) {
				i--;
				printf("\b \b");
			}
			
		} else {
			if (i < MAX) {
				printf("*");
				password[i] = caracter;
				i++;
			}
		}
	}
}


void datoswombat(){
	
	printf("\n");
			printf("\n");
	    	printf("A CERCA DE LOS WOMBAT:\n");
	    	printf("\n");
	        printf("El wombat es un animal mamífero endémico de Australia, de contextura musculosa y\n");
			printf("que pertenece al grupo de los marsupiales. Posee varios rasgos que son únicos y que\n");
			printf(" lo distinguen de otros tipos de marsupiales, como es el caso de sus particulares\n");
			printf("dientes, fuertes garras, la forma de sus heces y el metabolismo ralentizado.\n");
			printf("\n");
			printf("Su apariencia, con su cuerpo ancho y piernas rechonchas, nos haría pensar que no\n");
			printf("debe tratarse de un animal muy veloz. Pues, a pesar de las apariencias y este físico\n");
			printf("tan regordete, los wombats pueden correr hasta 40 km/h en distancias cortas si se\n");
			printf("sienten bajo amenaza.\n");
			printf("\n");
			printf("Entra en wombat.org y ayúdanos a crear un entorno seguro para ellos.\n");		
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
