#include <stdio.h>
#include <stdlib.h>

#define TAM 100

typedef struct {
    int fila[TAM];
    int inicio;
    int fim;
    int tamanho;
} FilaCircular;

void inicializar(FilaCircular* f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

int fila_vazia(FilaCircular* f) {
    return f->tamanho == 0;
}

int fila_cheia(FilaCircular* f) {
    return f->tamanho == TAM;
}

int enfileirar(FilaCircular* f, int valor) {
    if (fila_cheia(f)) return 0;
    f->fila[f->fim] = valor;
    f->fim = (f->fim + 1) % TAM;
    f->tamanho++;
    return 1;
}

int desenfileirar(FilaCircular* f, int* valor) {
    if (fila_vazia(f)) return 0;
    *valor = f->fila[f->inicio];
    f->inicio = (f->inicio + 1) % TAM;
    f->tamanho--;
    return 1;
}

int frente(FilaCircular* f, int* valor) {
    if (fila_vazia(f)) return 0;
    *valor = f->fila[f->inicio];
    return 1;
}

void imprimir_fila(FilaCircular* f) {
    if (fila_vazia(f)) {
        printf("Fila vazia\n");
        return;
    }
    int i = f->inicio;
    int count = f->tamanho;
    while (count--) {
        printf("%d ", f->fila[i]);
        i = (i + 1) % TAM;
    }
    printf("\n");
}

int main() {
    FilaCircular f;
    inicializar(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);
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
