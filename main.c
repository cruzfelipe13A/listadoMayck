#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1000

typedef struct Pilha {
    char dados[TAM];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int pilha_vazia(Pilha* p) {
    return p->topo == -1;
}

int empilhar(Pilha* p, char c) {
    if (p->topo >= TAM - 1) return 0;
    p->dados[++(p->topo)] = c;
    return 1;
}

char desempilhar(Pilha* p) {
    if (pilha_vazia(p)) return '\0';
    return p->dados[(p->topo)--];
}

char topo(Pilha* p) {
    if (pilha_vazia(p)) return '\0';
    return p->dados[p->topo];
}

int corresponde(char ab, char fe) {
    return (ab == '(' && fe == ')') || (ab == '{' && fe == '}') || (ab == '[' && fe == ']');
}

int verificar_balanceamento(const char* str) {
    Pilha p;
    inicializar(&p);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            empilhar(&p, str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (pilha_vazia(&p) || !corresponde(desempilhar(&p), str[i])) {
                return 0;
            }
        }
    }
    return pilha_vazia(&p);
}

int main() {
    printf("%d\n", verificar_balanceamento("({[]})")); // 1
    printf("%d\n", verificar_balanceamento("{[()]}")); // 1
    printf("%d\n", verificar_balanceamento("{[(])}")); // 0
    printf("%d\n", verificar_balanceamento("{[}"));    // 0
    printf("%d\n", verificar_balanceamento(""));       // 1
    return 0;
}
