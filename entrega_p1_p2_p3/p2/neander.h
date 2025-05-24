#define NEANDER_H
#define NEANDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definições para a arquitetura Neander
#define MEMORY_SIZE 256
#define MAX_LABEL_LENGTH 32
#define MAX_OPERAND_LENGTH 16

// Tipos de instruções suportadas
typedef enum {
    OP_LDA,
    OP_STA,
    OP_ADD,
    OP_OR,
    OP_AND,
    OP_NOT,
    OP_JMP,
    OP_JN,
    OP_JZ,
    OP_HLT,
    OP_NOP
} OpCode;

// Estrutura para representar uma instrução assembly
typedef struct {
    OpCode opcode;
    char operand[MAX_OPERAND_LENGTH];
    int address;  // Endereço na memória
} Instruction;

// Estrutura para representar símbolos (labels/variáveis)
typedef struct {
    char name[MAX_LABEL_LENGTH];
    int address;
} Symbol;

// Protótipos de funções
void generate_code(const char* output_file);
void add_symbol(const char* name, int address);
int find_symbol_address(const char* name);
void generate_arithmetic_expression(FILE* asm_file, const char* expr);

// Variáveis globais (implementadas no .c)
extern Symbol symbol_table[MEMORY_SIZE];
extern int symbol_count;

