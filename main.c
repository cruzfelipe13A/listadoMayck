#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

int detectar_ciclo(No* inicio) {
    No *lento = inicio, *rapido = inicio;
    while (rapido && rapido->prox) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
        if (lento == rapido) {
            return 1;
        }
    }
    return 0;
}

// Função auxiliar para criar um nó
No* criar_no(int valor) {
    No* n = malloc(sizeof(No));
    n->dado = valor;
    n->prox = NULL;
    return n;
}

int main() {
    No* inicio = criar_no(1);
    inicio->prox = criar_no(2);
    inicio->prox->prox = criar_no(3);
    inicio->prox->prox->prox = criar_no(4);
    inicio->prox->prox->prox->prox = criar_no(5);

    printf("Detectar ciclo (sem ciclo): %d\n", detectar_ciclo(inicio)); // 0

    // Criar ciclo: apontar o último nó para o segundo nó
    inicio->prox->prox->prox->prox->prox = inicio->prox;

    printf("Detectar ciclo (com ciclo): %d\n", detectar_ciclo(inicio)); // 1

    // Atenção: não liberando memória pois há ciclo na lista.

    return 0;
}
