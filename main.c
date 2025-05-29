#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_PILHA 100

typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct {
    int dados[TAMANHO_PILHA];
    int topo;
} PilhaArray;

void inicializar_pilha(PilhaArray* p) {
    p->topo = -1;
}

int empilhar(PilhaArray* p, int valor) {
    if (p->topo >= TAMANHO_PILHA - 1) return 0;
    p->dados[++(p->topo)] = valor;
    return 1;
}

int desempilhar(PilhaArray* p, int* valor) {
    if (p->topo < 0) return 0;
    *valor = p->dados[(p->topo)--];
    return 1;
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

void imprimir_reverso_com_array(No* l) {
    PilhaArray pilha;
    inicializar_pilha(&pilha);
    while (l) {
        empilhar(&pilha, l->dado);
        l = l->prox;
    }
    int valor;
    while (desempilhar(&pilha, &valor)) {
        printf("%d -> ", valor);
    }
    printf("NULL\n");
}

int main() {
    No* lista1 = NULL;
    imprimir_reverso_com_array(lista1);

    No* lista2 = NULL;
    inserir_fim(&lista2, 7);
    imprimir_reverso_com_array(lista2);

    No* lista3 = NULL;
    inserir_fim(&lista3, 10);
    inserir_fim(&lista3, 20);
    inserir_fim(&lista3, 30);
    inserir_fim(&lista3, 40);
    imprimir(lista3);
    imprimir_reverso_com_array(lista3);

    return 0;
}
