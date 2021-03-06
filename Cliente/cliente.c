/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "local.h"

CLIENT *clnt;
int  *result_1;
char *getidlocal_1_arg;
idEsclavos_sx  *result_2;
char *getid_esclavos_1_arg;
int  *result_3;
int  getidslove_1_arg;
char * *result_4;
int  getnomslove_1_arg;
char * *result_5;
int  getdirslove_1_arg;
float  *result_6;
int  getlecslove_1_arg;


int getIdEsc(int i);
char *getIdNom(int i);
char *getIdDir(int i);
float getIdLec(int i);


char *getIdNom(int i){
	getnomslove_1_arg=i;
	result_4 = getnomslove_1(&getnomslove_1_arg, clnt);
	if (result_4 == (char **) NULL) {
		clnt_perror (clnt, "call failed");
		return (char*)-1;
	}
	return *result_4;

}

char *getIdDir(int i){
	getdirslove_1_arg=i;
	result_5 = getdirslove_1(&getdirslove_1_arg, clnt);
	if (result_5 == (char **) NULL) {
		clnt_perror (clnt, "call failed");
		return (char*)-1;
	}
	return *result_5;

}

float getIdLec(int i){
	getlecslove_1_arg=i;
	result_6 = getlecslove_1(&getlecslove_1_arg, clnt);
	if (result_6 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
		return -1;
	}
	return *result_6;

}

void imprimirIdes() {
	result_2 = getid_esclavos_1((void*)&getid_esclavos_1_arg, clnt);
	if (result_2 == (idEsclavos_sx *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	int i;
	for(i=0;i<5;i++)
		printf("Id Esclavo [%i]: %i\n",(i+1),(*result_2).idProcEsclavos[i]);
}

void imprimirIdLocal() {
	result_1 = getidlocal_1((void*)&getidlocal_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("Id Local: %i", *result_1);
}



int
main (int argc, char *argv[])
{
	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	char *host;
	int ide=-1;
	float lectura=0.0;
	char nombreU[20], contrasenia[20], nombreUIn[20], contraseniaIn[20]; 
	strcpy(nombreU,"admin");
	strcpy(contrasenia,"root");
	host = argv[1];
	int opcion=-1, variable=0;
	
	while(opcion!=0)
	{
		printf("======== MENU DE OPCIONES SERVIDOR LOCAL ========\n");
		if(variable != 1)
			printf("1.- Iniciar Sesión.\n");
		if(variable==1){
			printf("2.- Obtener ides.\n");
			printf("3.- Obtener dir.\n");
			printf("4.- Obtener lec.\n");
			printf("5.- Obtener nom.\n");
		}
		printf("0.- Salir.\n");
		printf("=================================================\n");
		printf("Ingrese una opción: \n");
		scanf("%d",&opcion);
		if(opcion == 1 && variable == 1)
			opcion = -1;
		switch(opcion){
			case 1:
				if(variable != 1) {
					printf("Ingrese el nombre de usuario \n");
					scanf("%s",&nombreUIn);
					printf("Ingrese la contraseña \n");
					scanf("%s",&contraseniaIn);
					if(strcmp(nombreU,nombreUIn)==0){
						if(strcmp(contrasenia,contraseniaIn)==0){
							variable=1;
							clnt = clnt_create (host, LOCAL_SX, LOCAL_SX_VERSION, "udp");
							if (clnt == NULL) {
								clnt_pcreateerror (host);
								exit (1);
								
							}
							break;
						}
					}
					printf("\n");			
					printf("Nombre de usuario o contraseña incorrectos \n");
				}
				break;
			case 2:
				imprimirIdes();
				break;
			case 3:
				printf("Ingresa el ID para conectarte: ");
				scanf("%i",&ide);
				char *direccion = getIdDir(ide);
				printf("%s\n",direccion);
				break;
			case 4:
				printf("Ingresa el ID para conectarte: ");
				scanf("%i",&ide);
				lectura = getIdLec(ide);
				printf("%f\n",lectura);
				
				break;
			case 5:
				printf("Ingresa el ID para conectarte: ");
				scanf("%i",&ide);
				char *nombre = getIdNom(ide);
				printf("%s\n",nombre);
				break;
			case 0:
				clnt_destroy (clnt);
				printf("Adiós...\n");
				break;
			default: printf("Opcion no valida.\n");
		}
	}
exit (0);
}
