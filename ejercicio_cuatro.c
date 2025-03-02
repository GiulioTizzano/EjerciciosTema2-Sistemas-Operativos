#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>



int main(int argc, char *argv[]) {
    int fd, fd_dos;
    char buffer[20];



    if(argc != 3) {
        return 1;
    }
    fd = open(argv[1], O_RDWR | O_CREAT, 0666);
    fd_dos = open(argv[2], O_RDWR | O_CREAT, 0666);

    while(read(fd, buffer, 20) > 0) {
        write(fd_dos, buffer, 20);
    }
    return 0;
}