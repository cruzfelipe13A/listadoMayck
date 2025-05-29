#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char* dado;
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

void enfileirar(Fila* f, const char* valor) {
    No* novo = malloc(sizeof(No));
    novo->dado = strdup(valor);
    novo->prox = NULL;
    if (fila_vazia(f)) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

char* desenfileirar(Fila* f) {
    if (fila_vazia(f)) return NULL;
    No* temp = f->inicio;
    char* dado = temp->dado;
    f->inicio = temp->prox;
    if (f->inicio == NULL) f->fim = NULL;
    free(temp);
    return dado;
}

void liberar_fila(Fila* f) {
    while (!fila_vazia(f)) {
        char* val = desenfileirar(f);
        free(val);
    }
}

void gerar_binarios(int N) {
    if (N <= 0) return;
    Fila fila;
    inicializar(&fila);
    enfileirar(&fila, "1");

    for (int i = 0; i < N; i++) {
        char* atual = desenfileirar(&fila);
        printf("%s\n", atual);

        // Gerar próxima sequência: atual + "0" e atual + "1"
        int len = strlen(atual);
        char* s0 = malloc(len + 2);
        char* s1 = malloc(len + 2);

        strcpy(s0, atual);
        s0[len] = '0';
        s0[len+1] = '\0';

        strcpy(s1, atual);
        s1[len] = '1';
        s1[len+1] = '\0';

        enfileirar(&fila, s0);
        enfileirar(&fila, s1);

        free(atual);
        // s0 and s1 freed later when dequeued
    }
    liberar_fila(&fila);
}

int main() {
    int N = 10;
    gerar_binarios(N);
    return 0;
}
