#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MEMORIA 30000

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s \"código_brainfuck\"\n", argv[0]);
        return 1;
    }

    char *codigo = argv[1];
    unsigned char memoria[TAMANHO_MEMORIA] = {0};
    unsigned char *ptr = memoria;
    char *pc = codigo;

    while (*pc) {
        switch (*pc) {
            case '>': ++ptr; break;
            case '<': --ptr; break;
            case '+': ++*ptr; break;
            case '-': --*ptr; break;
            case '.': putchar(*ptr); break;
            case '[': 
                if (!*ptr) {
                    int nivel = 1;
                    while (nivel) {
                        pc++;
                        if (*pc == '[') nivel++;
                        if (*pc == ']') nivel--;
                    }
                }
                break;
            case ']':
                if (*ptr) {
                    int nivel = 1;
                    while (nivel) {
                        pc--;
                        if (*pc == ']') nivel++;
                        if (*pc == '[') nivel--;
                    }
                }
                break;
        }
        pc++;
    }

    return 0;
}