#include <iostream>
#include <unistd.h>
#include "exception/SysCallException.h"

int main(int argc, char *argv[]) {
    if(argc != 2){
        throw SysCallException(EINVAL, argv[0]);
    }
    long bufferSize = std::stoi(argv[1]);
    if(bufferSize < 1){
        throw SysCallException(EINVAL, argv[0]);
    }
    char buffer[bufferSize];

    long int cyclesCounter = 0;

    ssize_t readBytes;
    while ((readBytes = read(STDIN_FILENO, buffer, bufferSize)) > 0) {
        if (write(STDOUT_FILENO, buffer, readBytes) != readBytes) {
            throw SysCallException(EIO);
        }
        cyclesCounter++;
    }
    std::cerr << "Cycles: " << cyclesCounter;
}
