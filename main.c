#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

void inserir_fim(No** l, int v) {
    No* n = malloc(sizeof(No));
    n->dado = v;
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
        printf("%d -> ", l->dado);
        l = l->prox;
    }
    printf("NULL\n");
}

No* encontrar_meio(No* l) {
    if (l == NULL) return NULL;
    No* lento = l;
    No* rapido = l;
    while (rapido && rapido->prox) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }
    return lento;
}

int main() {
    No* lista1 = NULL;
    No* meio1 = encontrar_meio(lista1);
    if (meio1)
        printf("%d\n", meio1->dado);
    else
        printf("NULL\n");

    No* lista2 = NULL;
    inserir_fim(&lista2, 10);
    No* meio2 = encontrar_meio(lista2);
    printf("%d\n", meio2->dado);

    No* lista3 = NULL;
    inserir_fim(&lista3, 1);
    inserir_fim(&lista3, 2);
    inserir_fim(&lista3, 3);
    inserir_fim(&lista3, 4);
    inserir_fim(&lista3, 5);
    imprimir(lista3);
    No* meio3 = encontrar_meio(lista3);
    printf("%d\n", meio3->dado);

    No* lista4 = NULL;
    inserir_fim(&lista4, 10);
    inserir_fim(&lista4, 20);
    inserir_fim(&lista4, 30);
    inserir_fim(&lista4, 40);
    imprimir(lista4);
    No* meio4 = encontrar_meio(lista4);
    printf("%d\n", meio4->dado);

    return 0;
}
