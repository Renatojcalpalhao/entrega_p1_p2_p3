#include <stdio.h>
#include "neander.h"

void generate_code(const char* output_file) {
    FILE* asm_file = fopen(output_file, "w");
    
    // Código de inicialização
    fprintf(asm_file, "; Código gerado automaticamente\n");
    
    // Exemplo: tradução de RES = comprimento * largura
    fprintf(asm_file, "LDA comprimento\n");
    fprintf(asm_file, "ADD largura\n"); // Simplificação - deveria ser multiplicação
    fprintf(asm_file, "STA RES\n");
    fprintf(asm_file, "HLT\n");
    
    fclose(asm_file);
}