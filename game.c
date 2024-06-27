#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");

    char tentativa[6];
    char palavraSecreta[6];
    char palavras[1000][6];

<<<<<<< HEAD
    FILE *file = fopen("C:\\users\\viana\\OneDrive\\Área de Trabalho\\GuessWord\\palavras.txt", "r");
    for(int i = 0; i < 1000; i++){
=======
    FILE *file = fopen("C:\\users\\pamel\\OneDrive\\Documentos\\GuessWord\\palavras.txt", "r");
    for (int i = 0; i < 1000; i++)
    {
>>>>>>> 3a7086795e3a6096a10e6104eca68b2b764ede7b
        fscanf(file, "%s", palavras[i]);
    }
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
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