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

No* unir_listas_ordenadas(No* l1, No* l2) {
    No* inicio = NULL;
    No** atual = &inicio;

    while (l1 && l2) {
        if (l1->dado <= l2->dado) {
            *atual = l1;
            l1 = l1->prox;
        } else {
            *atual = l2;
            l2 = l2->prox;
        }
        atual = &((*atual)->prox);
    }

    if (l1) *atual = l1;
    else *atual = l2;

    return inicio;
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
    No* l1 = criar_no(1);
    l1->prox = criar_no(3);
    l1->prox->prox = criar_no(5);

    No* l2 = criar_no(2);
    l2->prox = criar_no(4);
    l2->prox->prox = criar_no(6);

    No* unida = unir_listas_ordenadas(l1, l2);
    imprimir_lista(unida);

    liberar_lista(unida);
    return 0;
}
