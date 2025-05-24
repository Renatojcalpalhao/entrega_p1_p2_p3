#include <stdio.h>
#include "neander.h"

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Uso: %s programa.bin\n", argv[0]);
        return 1;
    }
    
    // Implementação simplificada
    printf("Executando %s na VM Neander\n", argv[1]);
    return 0;
}