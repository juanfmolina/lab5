lab5
====

Este laboratorio utiliza todos los conocimientos aprendidos en los laboratorios de la asignatura Sistemas Operativos, esta escrito en el lenguaje de programación C y es para familiarizarse con todas las primitivas de sincronización y los problemas de concurrencia que pueden presentarse.

La estrategia de solución inicial es la siguiente:
- Las cuentas serán creadas por el hilo principal como un arreglo del tamaño igual al numero de cuentas a crear, asignando un valor inicial a todas, según indique la varaible de valor inicial.
- Los hilos harán las transferencias por un tiempo determinado, se sugiere que el hilo principal utilice la funcion sleep() para esperar a los demás hilos que estarán alojados igualmente en un arreglo de tipo pthread_t.
- Para el problema de sincronización se utilizaran semáforos (implementación por idear).
- El programa de prueba leerá los vectores de prueba desde el archivo, creará procesos dependiendo del numero de repeticiones para cada vector de prueba. La ejecución de estos procesos se hará con una llamada al sistema del tipo exec().

Problemas:

-Teniamos problema para inicializar el array de cuentas sin conocer el numero inicial, se crea una variable global que apunte al array creado en el main.

-Se tiene un problema con la escogencia de la herramienta para los problemas de sincronización, se escogen semaforos.

- Hay un problema con deadlock, no hemos podido encontrar la solución, hemos hecho la siguiente implementación con los semaforos:
		sem_wait(&semaforos[beneficiario]);
		sem_wait(&semaforos[ordenante]);
		//código dentro de la espera
		sem_post(&semaforos[beneficiario]);
		sem_post(&semaforos[ordenante]);
Para la solución a este problema, cambiamos la funcion   int sem_wait(sem_t *sem); por la función  int sem_trywait(sem_t *sem); la diferencia es que si el decremento no pude ser realizado inmediatamente, entonces la llamada retorna error en vez de bloquear el hilo.

- Existe un problema cuando se ejecuta el programa; a veces, el balance general está siendo mayor o menor, también las cuentas no están en el rango pedido, como si existiese un overflow:

	Cuenta 0 tiene un saldo de 10
	Cuenta 1 tiene un saldo de 27080482
	Cuenta 2 tiene un saldo de 3483267
	Cuenta 3 tiene un saldo de -454665138
	Cuenta 4 tiene un saldo de 2
	Cuenta 5 tiene un saldo de 120
	Cuenta 6 tiene un saldo de 130264460
	Cuenta 7 tiene un saldo de 4
	Cuenta 8 tiene un saldo de 6566808
	Cuenta 9 tiene un saldo de 287271327
	Balance general: 1342

- Existen problemas para concatenar char, nombre del problema: "segmentation fault"
