#include <stdio.h>
#include <pthread.h>

// Función que será ejecutada por los hilos
void *funcionDelHilo(void *arg) {
    char *mensaje = (char *)arg;
    printf("%s\n", mensaje);
    pthread_exit(NULL);
}

int main() {
    // Declaración de variables para los hilos
    pthread_t hilo1, hilo2;

    // Mensajes para los hilos
    char *mensaje1 = "Hola desde el Hilo 1!";
    char *mensaje2 = "Hola desde el Hilo 2!";

    // Crear los hilos y pasarles los mensajes
    pthread_create(&hilo1, NULL, funcionDelHilo, (void *)mensaje1);
    pthread_create(&hilo2, NULL, funcionDelHilo, (void *)mensaje2);

    // Esperar a que los hilos terminen
    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);

    return 0;
}