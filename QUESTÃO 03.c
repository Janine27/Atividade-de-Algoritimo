#include <stdio.h>

#define NUM_CONTAS 100

int busca_binaria(int contas[], int tamanho, int conta_procurada, int *comparacoes) {
    int esquerda = 0;
    int direita = tamanho - 1;
    *comparacoes = 0; 
    
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        (*comparacoes)++;
        
        if (contas[meio] == conta_procurada) {
            return meio;
        }
        if (contas[meio] < conta_procurada) {
            esquerda = meio +1;
        } else {
            direita = meio -1;
        
        }
    }
    
    return -1;
    
}

int main() {
    int contas[NUM_CONTAS];
    int conta_procurada;
    int comparacoes;
    
    for (int i = 0; i < NUM_CONTAS; i++) {
        contas[i] = 1000 + i;
    }
    
    printf("Digite o número da conta a ser veridicada: ");
    scanf("%d", &conta_procurada);
    
    int resultado = busca_binaria(contas, NUM_CONTAS, conta_procurada, &comparacoes);
    if (resultado != -1) {
        printf("conta %d encontrada na posição %d.\n", conta_procurada, resultado);
    
} else {
    printf("Conta %d não encontrada.\n", conta_procurada);
    
}

printf("Número de comparações realizadas: %d\n", comparacoes);

return 0;
}
