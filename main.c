#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

typedef struct Pilha {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int empilhar(Pilha* p, int val) {
    if (p->topo >= MAX - 1) return 0;
    p->dados[++(p->topo)] = val;
    return 1;
}

int desempilhar(Pilha* p) {
    if (p->topo < 0) return -1;
    return p->dados[(p->topo)--];
}

int avaliar_posfixa(const char* expr) {
    Pilha p;
    inicializar(&p);

    char buffer[20];
    int i = 0, j = 0;

    while (1) {
        if (expr[i] == ' ' || expr[i] == '\0') {
            if (j > 0) {
                buffer[j] = '\0';
                if (isdigit(buffer[0]) || (buffer[0] == '-' && isdigit(buffer[1]))) {
                    empilhar(&p, atoi(buffer));
                } else {
                    int b = desempilhar(&p);
                    int a = desempilhar(&p);
                    switch (buffer[0]) {
                        case '+': empilhar(&p, a + b); break;
                        case '-': empilhar(&p, a - b); break;
                        case '*': empilhar(&p, a * b); break;
                        case '/': empilhar(&p, a / b); break;
                    }
                }
                j = 0;
            }
            if (expr[i] == '\0') break;
        } else {
            buffer[j++] = expr[i];
        }
        i++;
    }
    return desempilhar(&p);
}

int main() {
    printf("%d\n", avaliar_posfixa("3 4 + 2 *"));     // 14
    printf("%d\n", avaliar_posfixa("5 1 2 + 4 * + 3 -")); // 14
    return 0;
}
