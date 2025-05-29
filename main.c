#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int val;
    struct No* prox;
} No;

void inserir_inicio(No** l, int v) {
    No* n = malloc(sizeof(No));
    n->val = v;
    n->prox = *l;
    *l = n;
}

void inserir_fim(No** l, int v) {
    No* n = malloc(sizeof(No));
    n->val = v;
    n->prox = NULL;
    if (*l == NULL) *l = n;
    else {
        No* a = *l;
        while (a->prox) a = a->prox;
        a->prox = n;
    }
}

void inserir_posicao(No** l, int v, int pos) {
    if (pos == 0) {
        inserir_inicio(l, v);
        return;
    }
    
    No* atual = *l;
    for (int i = 0; i < pos - 1; i++) {
        if (atual == NULL) {
            printf("Posição inválida\n");
            return;
        }
        atual = atual->prox;
    }
    
    if (atual == NULL) {
        printf("Posição inválida\n");
        return;
    }
    
    No* novo = malloc(sizeof(No));
    novo->val = v;
    novo->prox = atual->prox;
    atual->prox = novo;
}

void imprimir(No* l) {
    while (l) {
        printf("%d -> ", l->val);
        l = l->prox;
    }
    puts("NULL");
}

int main() {
    No* l = NULL;
    inserir_fim(&l, 10);
    inserir_inicio(&l, 5);
    inserir_fim(&l, 20);

    imprimir(l);  

    inserir_posicao(&l, 15, 2);  
    imprimir(l);  

    inserir_posicao(&l, 1, 0);   
    imprimir(l);  

    return 0;
}
