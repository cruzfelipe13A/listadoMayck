#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
    int* dados;
    int topo;
    int capacidade;
} Pilha;

void inicializar(Pilha* p, int cap) {
    p->dados = malloc(sizeof(int) * cap);
    p->topo = -1;
    p->capacidade = cap;
}

int esta_vazia(Pilha* p) {
    return p->topo == -1;
}

void empilhar(Pilha* p, int val) {
    if (p->topo < p->capacidade - 1) {
        p->dados[++(p->topo)] = val;
    }
}

int desempilhar(Pilha* p) {
    if (esta_vazia(p)) return -1;
    return p->dados[(p->topo)--];
}

int topo(Pilha* p) {
    if (esta_vazia(p)) return -1;
    return p->dados[p->topo];
}

int trap(int* height, int n) {
    Pilha s;
    inicializar(&s, n);
    int i = 0, res = 0;
    while (i < n) {
        while (!esta_vazia(&s) && height[i] > height[topo(&s)]) {
            int top = desempilhar(&s);
            if (esta_vazia(&s)) break;
            int dist = i - topo(&s) - 1;
            int h = (height[i] < height[topo(&s)] ? height[i] : height[topo(&s)]) - height[top];
            res += dist * h;
        }
        empilhar(&s, i++);
    }
    free(s.dados);
    return res;
}

int main() {
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", trap(arr, n)); // 6
    return 0;
}
