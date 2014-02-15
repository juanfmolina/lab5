#include <stdio.h>
#include <unistd.h> 
#include <string.h>

int main(int argc, char *argv[]){

	char * programaPrincipal = argv[1];
	char * archivoVectores = argv[2];
	FILE * ficheroVectores;

	ficheroVectores = fopen(archivoVectores,"r");
	
	if((ficheroVectores == NULL)){
		
		printf("El archivo de prueba no se puede abrir. \n");
		return 0;
	}
	
	char linea[20];
	while(fgets(linea,20,ficheroVectores) != NULL){
		char * prueba;
		char parametros[50];
		prueba = strtok(linea," ");
		strncpy(parametros, prueba, sizeof(prueba));
		strcat(parametros, " ");  
		while(prueba != NULL){
			printf("prueba: %s  linea:  %s    parametros %s \n", prueba,linea, parametros);
			prueba = strtok(NULL," ");
			strncat(parametros, prueba, sizeof(prueba));
			strcat(parametros, " ");  
		}	

	}
	
	return 0;	
	
} 
