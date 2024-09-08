#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CRIANÇAS 50
#define MIN_NOTA 1
#define MAX_NOTA 5

void contar_notas(int notas[], int contagem[], int num_notas) {
    for (int i = 0; i < num_notas; i++) {
        if (notas[i] >= MIN_NOTA && notas[i] <= MAX_NOTA) {
            contagem[notas[i] - MIN_NOTA] ++;
        }
    }
}

void exibir_resultado(int contagem[]) {
    printf("resultado da pesquisa:\n");
    for (int i = MIN_NOTA; i <= MAX_NOTA; i++) {
        printf("Nota %d: %d vezes\n", i, contagem[i - MIN_NOTA]);
    }
}

int main() {
    
    int notas[NUM_CRIANÇAS];
    int contagem[MAX_NOTA - MIN_NOTA + 1] = {0};
    
    srand(time(NULL));
    
    for (int i = 0; i < NUM_CRIANÇAS; i++) {
        notas[i] = rand() % (MAX_NOTA - MIN_NOTA + 1) + MIN_NOTA;
    }
    
    contar_notas(notas, contagem, NUM_CRIANÇAS);
    
    exibir_resultado(contagem);
    
    return 0;
    
}
