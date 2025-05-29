#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct DuasPilha {
    int dados[MAX];
    int topo1;
    int topo2;
} DuasPilha;

void inicializar(DuasPilha* p) {
    p->topo1 = -1;
    p->topo2 = MAX;
}

int push1(DuasPilha* p, int valor) {
    if (p->topo1 + 1 == p->topo2) return 0;
    p->dados[++(p->topo1)] = valor;
    return 1;
}

int push2(DuasPilha* p, int valor) {
    if (p->topo2 - 1 == p->topo1) return 0;
    p->dados[--(p->topo2)] = valor;
    return 1;
}

int pop1(DuasPilha* p) {
    if (p->topo1 == -1) return -1;
    return p->dados[(p->topo1)--];
}

int pop2(DuasPilha* p) {
    if (p->topo2 == MAX) return -1;
    return p->dados[(p->topo2)++];
}

int main() {
    DuasPilha p;
    inicializar(&p);

    push1(&p, 1);
    push1(&p, 2);
    push2(&p, 100);
    push2(&p, 200);

    printf("%d\n", pop1(&p));
    printf("%d\n", pop2(&p));
    printf("%d\n", pop1(&p));
    printf("%d\n", pop2(&p));
    printf("%d\n", pop1(&p));

    return 0;
}
