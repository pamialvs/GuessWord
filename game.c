#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    char tentativa[6];
    char palavraSecreta[6];
    char palavras[1000][6];

    FILE *file = fopen("palavras.txt", "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo palavras.txt.\n");
        return 1;
    }

    for (int i = 0; i < 1000; i++)
    {
        fscanf(file, "%s", palavras[i]);
    }

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo: %s\n", strerror(errno));
    }

    fclose(file);
    srand(time(NULL));
    int randomIndex = rand() % 1000;
    strcpy(palavraSecreta, palavras[randomIndex]);

    printf("=== BEM VINDO AO GUESSWORD! ===\n");
    for (int j = 0; j < 6; j++)
    {
        printf("\n--------Digite uma palavra: ");
        scanf("%s", tentativa);
        if (strlen(tentativa) != 0)
        {
            printf("Erro: a palavra deve ter 5 letras. Tente novamente.\n");
            j--;
            continue;
        }

        if (strcmp(palavraSecreta, tentativa) == 0)
        {
            printf("VOCÊ ACERTOU!!\n");
            return 0;
        }

        int TAM = strlen(tentativa);
        // Verificar se a palavra tem 5 letras
        if (TAM != 5)
        {
            printf("TENTATIVA INVÁLIDA, INSIRA UMA PALAVRA DE >CINCO< LETRAS.\n\n");
            j--;
        }

        else
        {
            int acertou = 0;
            for (int i = 0; i < 5; i++)
            {

                if (palavraSecreta[i] == tentativa[i])
                {
                    printf("Letra %c no índice %d: CORRETO\n", tentativa[i], i);
                    acertou = 1;
                }
                else if (strchr(palavraSecreta, tentativa[i]) != NULL)
                {
                    printf("Letra %c no índice errado.\n", tentativa[i]);
                    acertou = 1;
                }
            }

            if (!acertou)
            {
                printf("Nenhuma letra está correta.\n");
            }
        }
    }
    printf("Você não conseguiu, a palavra secreta é: %s\n", palavraSecreta);

    return 0;
}
