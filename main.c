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

void imprimir_fila(FilaCircular* f) {
    if (fila_vazia(f)) {
        printf("Fila vazia\n");
        return;
    }
    int i = f->inicio, count = f->tamanho;
    while (count--) {
        printf("%d ", f->fila[i]);
        i = (i + 1) % TAM;
    }
    printf("\n");
}

void inverter_primeiros_k(FilaCircular* f, int k) {
    if (k <= 0 || k > f->tamanho) return;

    int pilha[TAM];
    int topo = -1;
    int val;

    // Desenfileirar os primeiros k elementos e empilhar
    for (int i = 0; i < k; i++) {
        desenfileirar(f, &val);
        pilha[++topo] = val;
    }

    // Enfileirar os elementos da pilha (invertidos)
    while (topo >= 0) {
        enfileirar(f, pilha[topo--]);
    }

    // Enfileirar os elementos restantes para manter ordem
    int tamanho_restante = f->tamanho - k;
    for (int i = 0; i < tamanho_restante; i++) {
        desenfileirar(f, &val);
        enfileirar(f, val);
    }
}

int main() {
    FilaCircular f;
    inicializar(&f);

    for (int i = 1; i <= 10; i++) {
        enfileirar(&f, i);
    }

    printf("Fila original:\n");
    imprimir_fila(&f);

    inverter_primeiros_k(&f, 5);

    printf("Fila após inverter os primeiros 5 elementos:\n");
    imprimir_fila(&f);

    return 0;
}
