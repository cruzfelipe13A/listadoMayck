#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct Pilha {
    No* topo;
} Pilha;

void inicializar_pilha(Pilha* p) {
    p->topo = NULL;
}

int pilha_vazia(Pilha* p) {
    return p->topo == NULL;
}

void empilhar(Pilha* p, int valor) {
    No* novo = malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

int desempilhar(Pilha* p, int* valor) {
    if (pilha_vazia(p)) return 0;
    No* temp = p->topo;
    *valor = temp->dado;
    p->topo = temp->prox;
    free(temp);
    return 1;
}

void imprimir_pilha(Pilha* p) {
    No* atual = p->topo;
    while (atual) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    Pilha p;
    inicializar_pilha(&p);

    int valor;

    desempilhar(&p, &valor);

    empilhar(&p, 5);
    imprimir_pilha(&p);

    empilhar(&p, 10);
    empilhar(&p, 15);
    imprimir_pilha(&p);

    desempilhar(&p, &valor);
    printf("Desempilhado: %d\n", valor);
    imprimir_pilha(&p);

    return 0;
}
