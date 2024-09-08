#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 100
#define MAX_PRIMOS 25

bool eh_primo(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    
    return true;
}  

void gerar_primos(int primos[], int *n) {
    *n = 0;
    for (int i = 2; i <= MAX_NUM; i++) {
        if (eh_primo(i)) {
            primos[(*n)++] =i;
        }
    }
}

int busca_binaria(int arr[], int tamanho, int alvo) {
    int esquerda = 0;
    int direita = tamanho - 1;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        if (arr[meio] == alvo) {
            return meio;
        } else if (arr[meio] < alvo) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}

int main() {
    int primos[MAX_PRIMOS];
    int num_primos;
    
    gerar_primos(primos, &num_primos);
    
    printf("Números primos entre 1 e 100:\n");
    for (int i = 0; i < num_primos; i++) {
        printf("%d ", primos[i]);
    }
    printf("\n");
    
    int numero_usuario;
    printf("Digite um número entre 1 e 100: ");
    scanf("%d", &numero_usuario);
    
    if (numero_usuario < 1 || numero_usuario > 100) {
        printf("Número fora do intervalo permitido (1 a 100).\n");
    } else {
        int resultado = busca_binaria(primos, num_primos, numero_usuario);
        if (resultado != -1) {
            printf("O número %d está na lista de primos.\n", numero_usuario);
        } else {
        printf("O número %d não está na lista de primos,\n", numero_usuario);  
        
            
        }
        
    }
    
    return 0;
}
