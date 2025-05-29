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
    if (*l == NULL) {
        *l = n;
    } else {
        No* a = *l;
        while (a->prox) a = a->prox;
        a->prox = n;
    }
}

void imprimir(No* l) {
    while (l) {
        printf("%d -> ", l->val);
        l = l->prox;
    }
    printf("NULL\n");
}

void inverter_lista(No** l) {
    No *ant = NULL, *atual = *l, *prox = NULL;
    while (atual) {
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }
    *l = ant;
}

int main() {
    No* lista = NULL;
    inserir_fim(&lista, 1);
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 3);

    imprimir(lista);       // 1 -> 2 -> 3 -> NULL
    inverter_lista(&lista);
    imprimir(lista);       // 3 -> 2 -> 1 -> NULL

    return 0;
}
