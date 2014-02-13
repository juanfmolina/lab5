/*
definicion de la estructura cuenta y la implementacion de sus métodos
*/



#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include<math.h>

int numeroHilos; int tiempoEjecucion; int numeroCuentas; int valorInicial;
 
struct Cuenta{

	int idCuenta;
	int saldo;

};

void *transferir(void *);

struct Cuenta * pCuentas;
sem_t * semaforos;

int main(int argc, char *argv[]){

numeroHilos = atoi(argv[1]);
tiempoEjecucion = atoi(argv[2]);
numeroCuentas = atoi(argv[3]);
valorInicial = atoi(argv[4]);
pthread_t hilos[numeroHilos];


struct Cuenta aCuentas[numeroCuentas];
sem_t sema [numeroCuentas];
	int i=0;
	for(i=0;i<numeroCuentas;i++){
		aCuentas[i].idCuenta= i;
		aCuentas[i].saldo=valorInicial;
	};
pCuentas=&aCuentas[0];

for(i=0; i<numeroHilos; i++){
	if(pthread_create(&hilos[i], NULL, transferir, NULL)!=0){
		printf("Error al crear el Hilo");
	}
}


for(i=0; i<numeroHilos; i++){
	pthread_join(hilos[i], NULL);
}



return 0;
}

void * transferir(void * parametros){
	srand(time(NULL));
	int ordenante =rand()%numeroCuentas;
	int beneficiario=rand()%numeroCuentas;
	while(bebeficiario==ordenante) beneficiario=rand()%numeroCuentas;
	if(ordenante==beneficiario);


}


