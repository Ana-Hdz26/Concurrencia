#include <stdio.h>
#include <unistd.h>

int main() {
    // Crear un proceso hijo
    pid_t child_pid = fork();

    if (child_pid == -1) {
        // Error al crear el proceso hijo
        perror("Error al crear el proceso hijo");
        return 1;
    }

    if (child_pid == 0) {
        // Código ejecutado por el proceso hijo
        printf("Hola desde el proceso hijo!\n");
    } else {
        // Código ejecutado por el proceso padre
        printf("Hola desde el proceso padre!\n");
    }

    return 0;
}
