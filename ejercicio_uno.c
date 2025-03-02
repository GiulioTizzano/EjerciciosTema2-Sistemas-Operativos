#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

char name[] = "archivo.txt";

int main() {
    int fd;
    // umask(0) por defecto pone los permisos a 0022, así lo desactivamos temporalmente.
    umask(0); 
    fd = creat(name, 0666);
    printf("El valor de la tabla de descriptor de ficheros es %i \n", fd);
    return 0;
}


// El valor que devuelve es el número 3 porque es la primera posición
// libre en la tabla del descriptor de ficheros. Dado que las posiciones 
// 0, 1 y 2 están reservadas.




