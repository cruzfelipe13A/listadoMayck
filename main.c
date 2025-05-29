#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

void inicializar(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int fila_vazia(Fila* f) {
    return f->inicio == NULL;
}

void enfileirar(Fila* f, int valor) {
    No* novo = malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    if (fila_vazia(f)) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int desenfileirar(Fila* f, int* valor) {
    if (fila_vazia(f)) return 0;
    No* temp = f->inicio;
    *valor = temp->dado;
    f->inicio = temp->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(temp);
    return 1;
}

int frente(Fila* f, int* valor) {
    if (fila_vazia(f)) return 0;
    *valor = f->inicio->dado;
    return 1;
}

void imprimir_fila(Fila* f) {
    No* atual = f->inicio;
    while (atual) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    Fila f;
    inicializar(&f);

    enfileirar(&f, 5);
    enfileirar(&f, 10);
    enfileirar(&f, 15);

    imprimir_fila(&f);

    int valor;
    if (desenfileirar(&f, &valor)) {
        printf("Desenfileirado: %d\n", valor);
    }
    imprimir_fila(&f);

    if (frente(&f, &valor)) {
        printf("Frente da fila: %d\n", valor);
    }

    return 0;
}
