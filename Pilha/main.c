#include <stdio.h>

#define MAX 3

struct pilha {
    int corpo[MAX];
    int topo;
};

typedef struct pilha PILHA;

void estado(PILHA *end_pilha) {
    PILHA p = *end_pilha;
    printf("A\n");
    for (int i = (MAX - 1); i >= 0; i--) {
        if (i <= p.topo) {
            printf("%d\n", p.corpo[i]);
        } else {
            printf("-\n");
        }
        printf("");
    }
}

void coloca(PILHA *p, int n) {
    if (p->topo == (MAX - 1)) {
        printf("Pilha cheia!\n");
    } else {
        p->topo++;
        p->corpo[p->topo] = n;
    }
}

int tira(PILHA *p) {
    int n = 0;
    if (p->topo < 0) {
        printf("Pilha vazia!\n");
    } else {
        n = p->corpo[p->topo];
        p->topo--;
    }
    return (n);
}

int main() {
    PILHA A, B, C;
    A.topo = -1;
    B.topo = -1;
    C.topo = -1;
    coloca(&A, 5);
    coloca(&A, 10);
    estado(&A);
    printf("\n");
    int v = tira(&A);
    printf("v = %d\n\n", v);
    estado(&A);
    return 0;
}
