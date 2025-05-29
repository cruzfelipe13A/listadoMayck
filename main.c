#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct Pilha {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int empilhar(Pilha* p, int val) {
    if (p->topo >= MAX - 1) return 0;
    p->dados[++(p->topo)] = val;
    return 1;
}

int desempilhar(Pilha* p) {
    if (p->topo < 0) return -1;
    return p->dados[(p->topo)--];
}

typedef struct Fila {
    Pilha s1;
    Pilha s2;
} Fila;

void inicializar_fila(Fila* f) {
    inicializar(&f->s1);
    inicializar(&f->s2);
}

void enfileirar(Fila* f, int val) {
    empilhar(&f->s1, val);
}

int desenfileirar(Fila* f) {
    if (f->s2.topo == -1) {
        while (f->s1.topo != -1) {
            empilhar(&f->s2, desempilhar(&f->s1));
        }
    }
    return desempilhar(&f->s2);
}

int frente(Fila* f) {
    if (f->s2.topo == -1) {
        while (f->s1.topo != -1) {
            empilhar(&f->s2, desempilhar(&f->s1));
        }
    }
    if (f->s2.topo == -1) return -1;
    return f->s2.dados[f->s2.topo];
}

int main() {
    Fila f;
    inicializar_fila(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);

    printf("%d\n", frente(&f));
    printf("%d\n", desenfileirar(&f));
    printf("%d\n", desenfileirar(&f));

    enfileirar(&f, 40);
    printf("%d\n", frente(&f));
    printf("%d\n", desenfileirar(&f));
    printf("%d\n", desenfileirar(&f));

    return 0;
}
