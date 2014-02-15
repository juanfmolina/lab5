#include <stdio.h>
#include <unistd.h> 
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	char * programaPrincipal = argv[1];
	char * archivoVectores = argv[2];
	FILE * ficheroVectores;

	ficheroVectores = fopen(archivoVectores,"r");
	
	if((ficheroVectores == NULL)){
		
		printf("El archivo de prueba no se puede abrir. \n");
		return 0;
	}
	
	char linea[20]="";
	char vector[20]="";
	while(fgets(linea,20,ficheroVectores)!= NULL){
		strncpy(vector,linea, strlen(linea)-1); 
		char * prueba;
		char parametros[50]="";
		char numero[5]="";
		prueba = strtok(linea," ");
		int numeroCuentas, valorInicial;
		strncpy(parametros, prueba, strlen(prueba));
		strcat(parametros, " "); 
		int i=0;
		while(prueba != NULL){
			prueba = strtok(NULL," ");
			if (prueba==NULL) break;
			if(i<3){
				strncat(parametros, prueba, sizeof(prueba));
				strcat(parametros, " ");  
			} else{
				strncpy(numero, prueba,strlen(prueba)-1);
			}
			switch(i){
				case 1:
					numeroCuentas= atoi(prueba);
				break;
				case 2:
					valorInicial= atoi(prueba);					
				break;
					
			}
			i++;
		}
		int balanceGeneral;
		char comando[100]="";
		int repeticiones = atoi(numero);
		int k=0;
		int fallos=0, aciertos=0;
		for(k=0;k<repeticiones;k++){
				strcat(comando,"./");
				strncat(comando, programaPrincipal, strlen(programaPrincipal));
				strcat(comando, " ");
				strncat(comando, parametros, strlen(parametros));
				strcat(comando,"> out.txt \n");				
				system(comando);
				FILE * ficheroSalida;
				char fcontent [100];
				char faux[100];
				ficheroSalida=fopen("out.txt", "r");
				while(fgets(fcontent, 100, ficheroSalida)!= NULL){
					strncpy(faux, fcontent, strlen(fcontent));
				}
				fclose(ficheroSalida);
				char *balance;
				balance = strtok(faux, "Balance general: ");
				char charBalance [20];
				strncpy(charBalance, balance, strlen(balance)-1);
				balanceGeneral= atoi(charBalance);
				if(balanceGeneral==(numeroCuentas*valorInicial)) aciertos++;
				else fallos++;
		}
		printf("Vector %s tuvo %d fallos y %d aciertos.\n", vector, fallos, aciertos);
		
	}
	fclose(ficheroVectores);
	
	return 0;	
	
} 
