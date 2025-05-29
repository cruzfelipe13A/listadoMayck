#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    int minimo;
    struct No* prox;
} No;

typedef struct Pilha {
    No* topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = NULL;
}

void push(Pilha* p, int valor) {
    No* n = malloc(sizeof(No));
    n->valor = valor;
    n->minimo = (!p->topo || valor < p->topo->minimo) ? valor : p->topo->minimo;
    n->prox = p->topo;
    p->topo = n;
}

int pop(Pilha* p) {
    if (!p->topo) return -1;
    No* temp = p->topo;
    int valor = temp->valor;
    p->topo = temp->prox;
    free(temp);
    return valor;
}

int top(Pilha* p) {
    if (!p->topo) return -1;
    return p->topo->valor;
}

int obter_minimo(Pilha* p) {
    if (!p->topo) return -1;
    return p->topo->minimo;
}

int main() {
    Pilha p;
    inicializar(&p);
    push(&p, 3);
    push(&p, 5);
    printf("%d\n", obter_minimo(&p));
    push(&p, 2);
    push(&p, 1);
    printf("%d\n", obter_minimo(&p));
    pop(&p);
    printf("%d\n", obter_minimo(&p));
    pop(&p);
    printf("%d\n", top(&p));
    printf("%d\n", obter_minimo(&p));
    return 0;
}
