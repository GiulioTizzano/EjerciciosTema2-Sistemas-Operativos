#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(void) {
    // Abrir archivo:
    int file_desc;
    char mensaje[]= "HOLA";
    file_desc = open("escribe.txt", O_CREAT | O_RDWR, 0666);
    
    for(int i = 0; i <= strlen(mensaje); i++) {
        write(file_desc, &mensaje[i], 1);
    }
    // El lseek nos permite mover el puntero del archivo al principio
    // Después de escribir, el puntero está al final al fichero.


    // Para solucionar esto se puede utilizar el lseek o
    // close() y luego open().
    lseek(file_desc, 0, SEEK_SET);
    char c;
    // El read lo que hace es ller de un fichero, y se guarda en un buffer el caracter que está leyendo.

    // while(read(file_desc, &desc, 1) > 0)
    // printf("%c", c);
    // putchar(c)
    // write(1, &c, 1);


    for(int i = 0; i <= strlen(mensaje); i++) {
        read(file_desc, &c, 1);
        printf("%c \n", c);
        sleep(1);
    }
    // Para cerrar y desocupar una de las posiciones de la tabla del descriptor de ficheros 
    // utilizamos el close(fd)
    close(file_desc);
    return 0;
}
    