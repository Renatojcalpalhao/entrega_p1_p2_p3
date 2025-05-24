
neander-compiler/
├── README.md
├── Makefile
├── gramatica.pdf
├── assembler.pdf
├── programa.lpn (exemplo)
├── src/
│   ├── compilador/
│   │   ├── lexer.l
│   │   ├── parser.y
│   │   ├── codegen.c
│   │   └── main.c
│   ├── assembler/
│   │   ├── assembler.c
│   │   └── neander.h
│   └── executor/
│       ├── vm.c
│       └── neander.h
└── bin/
    ├── compilador
    ├── assembler
    └── executor

    # Compilador para Arquitetura Neander

ALUNO: Renato Alpalhão

 Instruções de Uso

1. Compilar o projeto:
```bash
make all

bash:
make clean
