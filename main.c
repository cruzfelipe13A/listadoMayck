#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int val;
    struct No* prox;
} No;

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

void remover_valor(No** l, int v) {
    No* atual = *l;
    No* ant = NULL;

    while (atual) {
        if (atual->val == v) {
            if (ant == NULL) *l = atual->prox;
            else ant->prox = atual->prox;
            free(atual);
            return;
        }
        ant = atual;
        atual = atual->prox;
    }
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
    inserir_fim(&l, 20);
    inserir_fim(&l, 30);
    inserir_fim(&l, 20);

    imprimir(l);
    remover_valor(&l, 20);
    imprimir(l);
    remover_valor(&l, 10);
    imprimir(l);

    return 0;
}
