#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct Pilha {
    int valor;
    struct Pilha* prox;
} Pilha;

void empilhar(Pilha** topo, int v) {
    Pilha* novo = malloc(sizeof(Pilha));
    novo->valor = v;
    novo->prox = *topo;
    *topo = novo;
}

int desempilhar(Pilha** topo) {
    if (*topo == NULL) return -1;
    Pilha* temp = *topo;
    int v = temp->valor;
    *topo = temp->prox;
    free(temp);
    return v;
}

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

void imprimir_reverso_com_pilha(No* l) {
    Pilha* pilha = NULL;
    while (l) {
        empilhar(&pilha, l->dado);
        l = l->prox;
    }
    while (pilha) {
        printf("%d -> ", desempilhar(&pilha));
    }
    printf("NULL\n");
}

int main() {
    No* lista1 = NULL;
    imprimir_reverso_com_pilha(lista1);

    No* lista2 = NULL;
    inserir_fim(&lista2, 42);
    imprimir_reverso_com_pilha(lista2);

    No* lista3 = NULL;
    inserir_fim(&lista3, 1);
    inserir_fim(&lista3, 2);
    inserir_fim(&lista3, 3);
    inserir_fim(&lista3, 4);
    imprimir(lista3);
    imprimir_reverso_com_pilha(lista3);

    return 0;
}
