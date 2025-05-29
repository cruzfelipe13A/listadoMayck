#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

No* inverter_lista(No* head) {
    No *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->prox;
        curr->prox = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int eh_palindromo(No* head) {
    if (!head || !head->prox) return 1;
    No *slow = head, *fast = head, *prev_slow = NULL;
    while (fast && fast->prox) {
        fast = fast->prox->prox;
        prev_slow = slow;
        slow = slow->prox;
    }
    No* segundo_inicio = (fast) ? slow->prox : slow;
    prev_slow->prox = NULL;
    segundo_inicio = inverter_lista(segundo_inicio);
    No* p1 = head;
    No* p2 = segundo_inicio;
    int res = 1;
    while (p2) {
        if (p1->dado != p2->dado) {
            res = 0;
            break;
        }
        p1 = p1->prox;
        p2 = p2->prox;
    }
    segundo_inicio = inverter_lista(segundo_inicio);
    if (fast) {
        prev_slow->prox->prox = segundo_inicio;
    } else {
        prev_slow->prox = segundo_inicio;
    }
    return res;
}

void inserir_fim(No** l, int v) {
    No* n = malloc(sizeof(No));
    n->dado = v;
    n->prox = NULL;
    if (*l == NULL) {
        *l = n;
    } else {
        No* a = *l;
        while (a->prox) a = a->prox;
        a->prox = n;
    }
}

void imprimir(No* l) {
    while (l) {
        printf("%d -> ", l->dado);
        l = l->prox;
    }
    printf("NULL\n");
}

int main() {
    No* lista = NULL;
    inserir_fim(&lista, 1);
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 3);
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 1);
    printf("%d\n", eh_palindromo(lista));
    inserir_fim(&lista, 0);
    printf("%d\n", eh_palindromo(lista));
    return 0;
}
