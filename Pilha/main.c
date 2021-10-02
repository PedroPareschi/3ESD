#include <stdio.h>

#define MAX 3

struct pilha {
    int corpo[MAX];
    int topo;
};

typedef struct pilha PILHA;

void estados(PILHA **end_end_pilhas) {
    printf("A\tB\tC\n");
    for (int i=MAX-1; i>=0; i--){
        for (int ip=0; ip<3; ip++){
            PILHA **end_end_pilha = &end_end_pilhas[ip];
            PILHA p = **end_end_pilha;
            if (i <= p.topo) {
                printf("%d\t", p.corpo[i]);
            } else {
                printf("-\t");
            }
        }
        printf("\n");
    }
    printf("\n");
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

void hanoi(int n, PILHA* end_O, PILHA* end_D, PILHA* end_T, PILHA** estado){
    if(n>0){
        hanoi(n-1, end_O, end_T, end_D, estado);
        int d = tira(end_O);
        coloca(end_D, d);
        estados(estado);
        hanoi(n-1, end_T, end_D, end_O, estado);
    }
    return;
}

int main() {
    PILHA A, B, C;
    A.topo = -1;
    B.topo = -1;
    C.topo = -1;
    coloca(&A, 5);
    coloca(&A, 10);
    estados(&A);

    printf("\n");
    int v = tira(&A);
    printf("v = %d\n\n", v);
    estados(&A);
    return 0;
}
