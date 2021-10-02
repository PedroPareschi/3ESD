#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

void janelaMinima(char *s, char *t, char *resultado);

int compararLetras(char c, char *t);

int pegarJanela(int i, char *s, char *t, char primeiraLetra, char *janela);

int main() {
    char resultado[MAX];
    janelaMinima("ADOBECODEBANC", "ABC", resultado);
    printf("%s\n", resultado);
    return 0;
}

void janelaMinima(char *s, char *t, char *resultado) {
    int i, res;
    int janelaTam;
    char janela[MAX];
    char janelaMinima[MAX];
    strcpy(janelaMinima, s);
    for (i = 0; i < strlen(s); i++) {
        if (compararLetras(s[i], t)) {
            res = pegarJanela(i + 1, s, t, s[i], janela);
            if (strlen(janela) < strlen(janelaMinima) && res) {
                strcpy(janelaMinima, janela);
            }
            memset(janela, 0, sizeof(janela));
        }
    }
    strcpy(resultado, janelaMinima);
}

int compararLetras(char c, char *t) {
    int i;
    for (i = 0; i < strlen(t); i++) {
        if (c == t[i]) {
            return 1;
        }
    }
    return 0;
}

int pegarJanela(int inicio, char *s, char *t, char primeiraLetra, char *janela) {
    janela[0] = primeiraLetra;
    int i, j = 1, aux;
    int flag = 1;
    for (i = inicio; i < strlen(s); i++) {
        aux = !compararLetras(s[i], janela);
        janela[j] = s[i];
        j++;
        if (compararLetras(s[i], t) && aux) {
            flag++;
            if (flag == strlen(t)) {
                return 1;
            }
        }
    }
    return 0;
}
