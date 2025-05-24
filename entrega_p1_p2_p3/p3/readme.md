brainfuck-tools/
├── Makefile
├── bfc.c         # Compilador Brainfuck
├── bfe.c         # Interpretador Brainfuck
└── exemplo.bf    # Exemplo de código

O compilador (bfc):

Recebe a string "CRÉDITO:2*5+10"

Extrai e calcula a expressão matemática (2*5+10 = 20)

Gera código Brainfuck que imprime o caractere ASCII 20 (caractere de controle)

O interpretador (bfe):

Executa o código Brainfuck gerado

Imprime o resultado na saída padrão

O pipeline completo:

echo envia a string para o primeiro programa

bfc compila para Brainfuck

bfe executa o código gerado