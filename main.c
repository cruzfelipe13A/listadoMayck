#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

No* inverter_grupos(No* head, int k) {
    No *atual = head, *prev = NULL, *prox = NULL;
    int count = 0;

    No* temp = head;
    int nodes = 0;
    while (temp) {
        nodes++;
        temp = temp->prox;
    }
    if (k <= 1 || nodes < k) return head;

    count = 0;
    while (atual && count < k) {
        prox = atual->prox;
        atual->prox = prev;
        prev = atual;
        atual = prox;
        count++;
    }
    if (prox) head->prox = inverter_grupos(prox, k);
    return prev;
}

void imprimir(No* l) {
    while (l) {
        printf("%d -> ", l->dado);
        l = l->prox;
    }
    printf("NULL\n");
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

int main() {
    No* lista = NULL;
    inserir_fim(&lista, 1);
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 3);
    inserir_fim(&lista, 4);
    inserir_fim(&lista, 5);

    lista = inverter_grupos(lista, 2);
    imprimir(lista); 

    return 0;
}
