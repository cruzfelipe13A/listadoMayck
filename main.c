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

void inverter_string(char* str) {
    Pilha p;
    inicializar(&p);

    for (int i = 0; str[i]; i++) {
        empilhar(&p, str[i]);
    }

    for (int i = 0; str[i]; i++) {
        str[i] = desempilhar(&p);
    }
}

int main() {
    char s1[] = "";
    inverter_string(s1);
    printf("%s\n", s1); // (vazio)

    char s2[] = "a";
    inverter_string(s2);
    printf("%s\n", s2); // a

    char s3[] = "hello";
    inverter_string(s3);
    printf("%s\n", s3); // olleh

    char s4[] = "abcdef";
    inverter_string(s4);
    printf("%s\n", s4); // fedcba

    return 0;
}
