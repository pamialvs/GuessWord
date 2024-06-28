#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
//TENTANDO EDITAR O ARQUIVO
    char tentativa[6];
    char palavraSecreta[6];
    char palavras[1000][6];

    FILE *file = fopen("C:\\Users\\viana\OneDrive\\Área de Trabalho\\GuessWord\\palavras.txt", "r");
    for(int i = 0; i < 1000; i++){
        fscanf(file, "%s", palavras[i]);
    }
    
    if (file == NULL) {
    printf("Erro ao abrir o arquivo: %s\n", strerror(errno));
    }

    fclose(file);
    srand(time(NULL));
    int randomIndex = rand() % 1000;
    strcpy(palavraSecreta, palavras[randomIndex]);

    for (int j = 0; j < 6; j++)
    {
        printf("====== Digite uma palavra: ");
        scanf("%s", tentativa);

        if (strcmp(palavraSecreta, tentativa) == 0)
        {
            printf("VOCÊ ACERTOU!!\n");
            return 0;
        }
        else
        {
            for (int i = 0; i < 5; i++)
            {
                if (palavraSecreta[i] == tentativa[i])
                {
                    printf("letra %c\nno indice %d\n", tentativa[i], i);
                }
            }
        }
    }
    printf("Voce não conseguiu, a palavra secreta é: %s", palavraSecreta);

    return 0;
}