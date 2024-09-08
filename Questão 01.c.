#include <stdio.h>                                                                                     
#include <string.h> 
#include <ctype.h>

#define MAX_TAMANHO_PALAVRA 10

void exibir_status(char palavra[], char letras_adivinhadas[], int tamanho_palavra) {
    int i;
    printf("palavra: ");
    for (i = 0; i < tamanho_palavra; i++) {
        if (letras_adivinhadas[i]) {
            printf("%c ", palavra[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
    
}
    
    int main() {
        
        char palavra[MAX_TAMANHO_PALAVRA + 1];
        char letras_adivinhadas[MAX_TAMANHO_PALAVRA];
        char tentativa;
        int tamanho_palavra, tentativas_restantes, i, letra_encontrada;
        int todas_letras_adivinhadas; 
        
        memset(letras_adivinhadas, 0, sizeof(letras_adivinhadas));

        printf("Digite a palavra (máximo %d caracteres): ", MAX_TAMANHO_PALAVRA);
        scanf("%s", palavra);
        
        tamanho_palavra = strlen(palavra);
        tentativas_restantes = tamanho_palavra + 2;
        
        while (tentativas_restantes > 0) {
            exibir_status(palavra, letras_adivinhadas, tamanho_palavra);
            
            printf("tentativas restantes: %d\n", tentativas_restantes);
            printf("Digite uma letra: ");
            scanf(" %c", &tentativa);
            tentativa = tolower(tentativa);
            
            letra_encontrada = 0;
            for (i = 0; i < tamanho_palavra; i++) {
                if (tolower(palavra[i]) == tentativa) {
                   letras_adivinhadas[i] = 1;
                    letra_encontrada = 1;
                    printf("letra '%c' encontrada na posição %d.\n", tentativa, i);
                    
                    
                }
            }
            
            if (!letra_encontrada) {
                tentativas_restantes--;
                printf("Letra '%c' não encontrada.\n", tentativa);
            }
            
            todas_letras_adivinhadas = 1;
            for (i = 0; i < tamanho_palavra; i++) {
                if (letras_adivinhadas[i] == 0) {
                    todas_letras_adivinhadas = 0;
                    break;
                }
            }
            
            if (todas_letras_adivinhadas) {
                exibir_status(palavra, letras_adivinhadas, tamanho_palavra);
                printf("Parabéns! Você ganhou!\n");
                break;
    
            }
        }
        
        if (!todas_letras_adivinhadas) {
            printf("Você perdeu! A palavra era: %s\n", palavra);
        }
        
        return 0;
        
    }
