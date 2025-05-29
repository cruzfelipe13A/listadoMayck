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

void rotacionar_lista(No** inicio, int k) {
    if (!*inicio || k == 0) return;

    int n = tamanho_lista(*inicio);
    k = k % n;
    if (k == 0) return;

    No* atual = *inicio;
    int count = 1;
    while (count < n - k) {
        atual = atual->prox;
        count++;
    }

    No* nova_cabeca = atual->prox;
    atual->prox = NULL;

    No* fim = nova_cabeca;
    while (fim->prox) {
        fim = fim->prox;
    }
    fim->prox = *inicio;
    *inicio = nova_cabeca;
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
    lista->prox->prox->prox = criar_no(4);
    lista->prox->prox->prox->prox = criar_no(5);

    imprimir_lista(lista);
    rotacionar_lista(&lista, 2);
    imprimir_lista(lista);

    liberar_lista(lista);
    return 0;
}
