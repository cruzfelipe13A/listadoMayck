#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1000

typedef struct Pilha {
    char dados[TAM];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int empilhar(Pilha* p, char c) {
    if (p->topo >= TAM - 1) return 0;
    p->dados[++(p->topo)] = c;
    return 1;
}

char desempilhar(Pilha* p) {
    if (p->topo < 0) return '\0';
    return p->dados[(p->topo)--];
}

int verificar_palindromo(const char* str) {
    Pilha p;
    inicializar(&p);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        empilhar(&p, str[i]);
    }

    for (int i = 0; i < len; i++) {
        if (str[i] != desempilhar(&p)) {
            return 0;
        }
    }

    return 1;
}

int main() {
    printf("%d\n", verificar_palindromo(""));         // 1
    printf("%d\n", verificar_palindromo("a"));        // 1
    printf("%d\n", verificar_palindromo("radar"));    // 1
    printf("%d\n", verificar_palindromo("level"));    // 1
    printf("%d\n", verificar_palindromo("hello"));    // 0
    printf("%d\n", verificar_palindromo("abba"));     // 1
    printf("%d\n", verificar_palindromo("abcba"));    // 1
    printf("%d\n", verificar_palindromo("abccba"));   // 1
    printf("%d\n", verificar_palindromo("abcd"));     // 0
    return 0;
}
