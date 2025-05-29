#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

No* criar_no(int valor) {
    No* n = malloc(sizeof(No));
    n->dado = valor;
    n->prox = NULL;
    return n;
}

void remover_todas_ocorrencias(No** inicio, int valor) {
    while (*inicio && (*inicio)->dado == valor) {
        No* temp = *inicio;
        *inicio = (*inicio)->prox;
        free(temp);
    }
    No* atual = *inicio;
    while (atual && atual->prox) {
        if (atual->prox->dado == valor) {
            No* temp = atual->prox;
            atual->prox = temp->prox;
            free(temp);
        } else {
            atual = atual->prox;
        }
    }
}

void imprimir_lista(No* l) {
    while (l) {
        printf("%d -> ", l->dado);
        l = l->prox;
    }
    printf("NULL\n");
}

void liberar_lista(No* l) {
    while (l) {
        No* temp = l;
        l = l->prox;
        free(temp);
    }
}

int main() {
    No* lista = criar_no(1);
    lista->prox = criar_no(2);
    lista->prox->prox = criar_no(3);
    lista->prox->prox->prox = criar_no(2);
    lista->prox->prox->prox->prox = criar_no(4);
    lista->prox->prox->prox->prox->prox = criar_no(2);

    imprimir_lista(lista);
    remover_todas_ocorrencias(&lista, 2);
    imprimir_lista(lista);

    liberar_lista(lista);
    return 0;
}
