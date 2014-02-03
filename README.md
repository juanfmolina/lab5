lab5
====

Este laboratorio utiliza todos los conocimientos aprendidos en los laboratorios de la asignatura Sistemas Operativos, esta escrito en el lenguaje de programación C y es para familiarizarse con todas las primitivas de sincronización y los problemas de concurrencia que pueden presentarse.

La estrategia de solución inicial es la siguiente:
- Las cuentas serán creadas por el hilo principal como un arreglo del tamaño igual al numero de cuentas a crear, asignando un valor inicial a todas, según indique la varaible de valor inicial.
- Los hilos harán las transferencias por un tiempo determinado, se sugiere que el hilo principal utilice la funcion sleep() para esperar a los demás hilos que estarán alojados igualmente en un arreglo de tipo pthread_t.
- Para el problema de sincronización se utilizaran semáforos (implementación por idear).
- El programa de prueba leerá los vectores de prueba desde el archivo, creará procesos dependiendo del numero de repeticiones para cada vector de prueba. La ejecución de estos procesos se hará con una llamada al sistema del tipo exec().
