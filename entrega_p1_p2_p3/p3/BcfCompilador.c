#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s \"expressão\"\n", argv[0]);
        return 1;
    }

    char *expr = argv[1];
    printf("Processando: %s\n", expr);

    // Extrai a parte numérica após "CRÉDITO:"
    char *calculos = strchr(expr, ':');
    if (!calculos) {
        fprintf(stderr, "Formato inválido. Use CRÉDITO:expressão\n");
        return 1;
    }
    calculos++;

    // Remove o pipe final se existir
    char *pipe = strchr(calculos, '|');
    if (pipe) *pipe = '\0';

    // Avalia a expressão matemática simples
    int resultado = 0;
    char operador = '+';
    char *token = strtok(calculos, "+-*/");
    
    while (token) {
        int num = atoi(token);
        switch (operador) {
            case '+': resultado += num; break;
            case '*': resultado *= num; break;
        }

        operador = calculos[token - calculos + strlen(token)];
        token = strtok(NULL, "+-*/");
    }

    // Gera código Brainfuck que imprime o resultado
    printf("Gerando código Brainfuck para resultado %d...\n", resultado);
    
    // Código Brainfuck para imprimir o número ASCII
    for (int i = 0; i < resultado; i++) {
        printf("+");
    }
    printf(".[-]");

    return 0;
}