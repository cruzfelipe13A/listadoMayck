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

int tamanho_lista(No* l) {
    int cont = 0;
    while (l) {
        cont++;
        l = l->prox;
    }
    return cont;
}

No* encontrar_intersecao(No* l1, No* l2) {
    int t1 = tamanho_lista(l1);
    int t2 = tamanho_lista(l2);
    int diff = t1 - t2;
    if (diff < 0) {
        No* temp = l1; l1 = l2; l2 = temp;
        diff = -diff;
    }
    for (int i = 0; i < diff; i++) {
        l1 = l1->prox;
    }
    while (l1 && l2) {
        if (l1 == l2) return l1;
        l1 = l1->prox;
        l2 = l2->prox;
    }
    return NULL;
}

int main() {
    No* comum = criar_no(7);
    comum->prox = criar_no(8);
    comum->prox->prox = criar_no(9);

    No* l1 = criar_no(1);
    l1->prox = criar_no(2);
    l1->prox->prox = criar_no(3);
    l1->prox->prox->prox = comum;

    No* l2 = criar_no(4);
    l2->prox = criar_no(5);
    l2->prox->prox = comum;

    No* intersecao = encontrar_intersecao(l1, l2);
    if (intersecao) printf("%d\n", intersecao->dado);
    else printf("0\n");

    free(l1->prox->prox);
    free(l1->prox);
    free(l1);
    free(l2->prox);
    free(l2);
    free(comum->prox->prox);
    free(comum->prox);
    free(comum);

    return 0;
}
