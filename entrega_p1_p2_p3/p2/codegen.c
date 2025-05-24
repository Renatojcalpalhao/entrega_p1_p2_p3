#include "neander.h"

// Implementação da tabela de símbolos
Symbol symbol_table[MEMORY_SIZE];
int symbol_count = 0;

void add_symbol(const char* name, int address) {
    if (symbol_count < MEMORY_SIZE) {
        strncpy(symbol_table[symbol_count].name, name, MAX_LABEL_LENGTH);
        symbol_table[symbol_count].address = address;
        symbol_count++;
    }
}

int find_symbol_address(const char* name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return symbol_table[i].address;
        }
    }
    return -1; // Não encontrado
}

void generate_arithmetic_expression(FILE* asm_file, const char* expr) {
    // Implementação simplificada - você deve expandir isso
    fprintf(asm_file, "; Expressão: %s\n", expr);
    
    // Exemplo: processa apenas a forma "A * B"
    char var1[16], var2[16];
    if (sscanf(expr, "%[^ *] * %s", var1, var2) == 2) {
        fprintf(asm_file, "LDA %s\n", var1);
        fprintf(asm_file, "ADD %s\n", var2); // Substituir por multiplicação real
    }
}

void generate_code(const char* output_file) {
    FILE* asm_file = fopen(output_file, "w");
    if (!asm_file) {
        perror("Erro ao abrir arquivo de saída");
        exit(EXIT_FAILURE);
    }
    
    // Cabeçalho do assembly
    fprintf(asm_file, "; Código gerado automaticamente\n");
    fprintf(asm_file, "; Arquitetura Neander\n\n");
    
    // Exemplo: tradução de RES = comprimento * largura
    // Adiciona símbolos à tabela
    add_symbol("comprimento", 0x10);
    add_symbol("largura", 0x11);
    add_symbol("RES", 0x00); // Endereço especial para o resultado
    
    // Gera código para a expressão
    generate_arithmetic_expression(asm_file, "comprimento * largura");
    
    // Armazena o resultado em RES
    fprintf(asm_file, "STA RES\n");
    fprintf(asm_file, "HLT\n");
    
    fclose(asm_file);
}