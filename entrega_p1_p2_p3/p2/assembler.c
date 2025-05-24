#include <stdio.h>
#include "neander.h"

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Uso: %s entrada.asm saida.bin\n", argv[0]);
        return 1;
    }
    
    // Implementação simplificada
    printf("Assembling %s to %s\n", argv[1], argv[2]);
    return 0;
}