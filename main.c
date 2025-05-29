#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int val;
    struct No* prox;
} No;

void inserir_inicio(No** l, int v) {
    No* n = malloc(sizeof(No));
    n->val = v;
    n->prox = *l;
    *l = n;
}

void inserir_fim(No** l, int v) {
    No* n = malloc(sizeof(No));
    n->val = v;
    n->prox = NULL;
    if (*l == NULL) *l = n;
    else {
        No* a = *l;
        while (a->prox) a = a->prox;
        a->prox = n;
    }
}

int contar_nos(No* l) {
    int cont = 0;
    while (l) {
        cont++;
        l = l->prox;
    }
    return cont;
}

void imprimir(No* l) {
    while (l) {
        printf("%d -> ", l->val);
        l = l->prox;
    }
    puts("NULL");
}

int main() {
    No* l = NULL;
    inserir_fim(&l, 10);
    inserir_inicio(&l, 5);
    inserir_fim(&l, 20);

    imprimir(l);
    printf("Total de nós: %d\n", contar_nos(l));

    return 0;
}
