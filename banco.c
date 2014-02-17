/*
definicion de la estructura cuenta y la implementacion de sus métodos
*/



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <math.h>
#include <semaphore.h>


int numeroHilos; int tiempoEjecucion; int numeroCuentas; int valorInicial;
int bandera =0;
 
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
//Creando las cuentas...


	int i=0;
	for(i=0;i<numeroCuentas;i++){
		aCuentas[i].idCuenta= i;
		aCuentas[i].saldo=valorInicial;
	};
//Inicializacion de semaforos.
	for(i=0;i<numeroCuentas;i++){
		sem_init(&sema[i], 0, 1);
	};
	
//Aquí se asigna el array de cuentas a la varible global.
pCuentas=&aCuentas[0];
semaforos=&sema[0];
//Creando los hilos...
for(i=0; i<numeroHilos; i++){
	if(pthread_create(&hilos[i], NULL, transferir, (void*)&i)!=0){
		printf("Error al crear el Hilo");
	}
}
//Esperando los hilos
for(i=0; i<numeroHilos; i++){
	pthread_join(hilos[i], NULL);
}

int balanceGeneral=0;
for(i=0; i<numeroCuentas; i++){
	printf("Cuenta %d tiene un saldo de %d\n", pCuentas[i].idCuenta, pCuentas[i].saldo);
	balanceGeneral+= pCuentas[i].saldo;
}
printf("Balance general: %d\n", balanceGeneral);


return 0;
}

void * transferir(void * parametros){
	//int hilo= *((int *)parametros) ;
	srand(time(NULL));
	int i;
	for(i=0; i<= tiempoEjecucion; i++){
		
		int ordenante =rand()%numeroCuentas;
		int beneficiario=rand()%numeroCuentas;
		while(beneficiario==ordenante) beneficiario=rand()%numeroCuentas;
		if(sem_trywait(&semaforos[beneficiario])== 0 && sem_trywait(&semaforos[ordenante])== 0){
			int monto= rand() % pCuentas[ordenante].saldo;
			pCuentas[ordenante].saldo-=monto;
			pCuentas[beneficiario].saldo+=monto;
			/*printf("Hilo %d\n Monto a transferir %d\nBeneficiario %d -> Saldo %d\nOrdenante %d ->Saldo %d\n",hilo, monto,
			pCuentas[beneficiario].idCuenta,pCuentas[beneficiario].saldo, pCuentas[ordenante].idCuenta,pCuentas[ordenante].saldo);*/
			sem_post(&semaforos[ordenante]);
			sem_post(&semaforos[beneficiario]);
		}
		
	}
	return NULL;


}



