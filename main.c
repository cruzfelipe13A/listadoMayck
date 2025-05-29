#include <stdio.h>
#include <stdlib.h>

#define TAM 1000

typedef struct Pilha {
    int dados[TAM];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int pilha_vazia(Pilha* p) {
    return p->topo == -1;
}

int empilhar(Pilha* p, int valor) {
    if (p->topo >= TAM - 1) return 0;
    p->dados[++(p->topo)] = valor;
    return 1;
}

int desempilhar(Pilha* p, int* valor) {
    if (pilha_vazia(p)) return 0;
    *valor = p->dados[(p->topo)--];
    return 1;
}

void imprimir_pilha(Pilha* p) {
    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

void ordenar_pilha(Pilha* p) {
    Pilha aux;
    inicializar(&aux);

    int temp;
    while (!pilha_vazia(p)) {
        desempilhar(p, &temp);
        while (!pilha_vazia(&aux) && aux.dados[aux.topo] > temp) {
            int val;
            desempilhar(&aux, &val);
            empilhar(p, val);
        }
        empilhar(&aux, temp);
    }

    // Transferir de volta para p para que p fique ordenada (topo com maior)
    while (!pilha_vazia(&aux)) {
        desempilhar(&aux, &temp);
        empilhar(p, temp);
    }
}

int main() {
    Pilha p;
    inicializar(&p);

    empilhar(&p, 3);
    empilhar(&p, 1);
    empilhar(&p, 4);
    empilhar(&p, 2);
    empilhar(&p, 5);

    printf("Pilha antes da ordenacao:\n");
    imprimir_pilha(&p);

    ordenar_pilha(&p);

    printf("Pilha depois da ordenacao:\n");
    imprimir_pilha(&p);

    return 0;
}
