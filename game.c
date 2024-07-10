#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <errno.h>

#define MAX_PALAVRAS 1000
#define TAMANHO_PALAVRA 6
#define MAX_USUARIOS 100
#define RANKING_FILE "ranking.txt"

typedef struct
{
    char nome[100];
    int pontuacao;
} Usuario;

void ordenarRanking(Usuario ranking[], int numUsuarios)
{
    Usuario temp;
    for (int i = 0; i < numUsuarios - 1; i++)
    {
        for (int j = 0; j < numUsuarios - i - 1; j++)
        {
            if (ranking[j].pontuacao < ranking[j + 1].pontuacao)
            {
                temp = ranking[j];
                ranking[j] = ranking[j + 1];
                ranking[j + 1] = temp;
            }
        }
    }
}

void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    double total_time_used = 0.0;

    char tentativa[TAMANHO_PALAVRA];
    char palavraSecreta[TAMANHO_PALAVRA];
    char palavras[MAX_PALAVRAS][TAMANHO_PALAVRA];
    int opcao;
    char nomeUser[100];
    Usuario ranking[MAX_USUARIOS];
    int numUsuarios = 0;
    char voltar;

<<<<<<< HEAD
    // Ler as palavras do arquivo
    FILE *file = fopen("palavras.txt", "r");
=======
    clock_t start, end;

    // Ler as palavras do arquivo
    FILE *file = fopen("palavras.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo: %s\n", strerror(errno));
        return 1;
    }
>>>>>>> 6e2862b3fcdc3f9bbfab6ab8d2f8724070adeb66

    for (int i = 0; i < MAX_PALAVRAS; i++)
    {
        fscanf(file, "%s", palavras[i]);
    }
<<<<<<< HEAD
    //verificando se o arquivo foi lido
    if (file == NULL) {
    printf("Erro ao abrir o arquivo: %s\n", strerror(errno));
    }

    fclose(file);
    
    // Sortear uma palavra aleatï¿½ria do arquivo
    srand(time(NULL));
    int randomIndex = rand() % 1000;
    strcpy(palavraSecreta, palavras[randomIndex]);

    printf("=== BEM VINDO AO GUESSWORD! ===\n     tecle a opção desejada:\n      1. Jogar\n      2. Ranking \n      3. Sair");


    for (int j = 0; j < 6; j++)
    {
        printf("\n--------Digite uma palavra: ");
        scanf("%s", tentativa);
        printf("\n");
        if (strcmp(palavraSecreta, tentativa) == 0)
        {
            printf("VOCÊ ACERTOU!!\n");
            return 0;
        }
=======
    fclose(file);

    // Carregar o ranking do arquivo
    file = fopen(RANKING_FILE, "r");
    if (file != NULL)
    {
        while (fscanf(file, "%s %d", ranking[numUsuarios].nome, &ranking[numUsuarios].pontuacao) != EOF)
        {
            numUsuarios++;
        }
        fclose(file);
    }

    while (1)
    {
        limparTela(); // Limpar tela ao entrar no menu inicial

        srand(time(NULL));
        int randomIndex = rand() % MAX_PALAVRAS;
        strcpy(palavraSecreta, palavras[randomIndex]);

        printf("\n");
        printf("=== BEM VINDO AO GUESSWORD! ===\n");
        printf("Tecle a opção desejada:\n");
        printf("1. Jogar\n");
        printf("2. Ranking\n");
        printf("3. Sair\n");
        scanf(" %d", &opcao);
        printf("\n");
>>>>>>> 6e2862b3fcdc3f9bbfab6ab8d2f8724070adeb66

        if (opcao == 1)
        {
            printf("Para começar, digite seu usuário: ");
            scanf("%s", nomeUser);
            printf("%s\n", nomeUser);
            int pontos = 600;

            start = clock(); // Inicia contagem de tempo do jogo

            for (int j = 0; j < 6; j++)
            {
                printf("\n--------Digite uma palavra: ");
                scanf("%s", tentativa);
                printf("\n");

                if (strcmp(palavraSecreta, tentativa) == 0)
                {
                    printf("VOCÊ ACERTOU!!\n");
                    end = clock();
                    total_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
                    printf("Tempo de jogo: %.2f segundos\n", ((double) (end - start)) / CLOCKS_PER_SEC);
                    printf("Deseja voltar ao menu inicial? (s-sim, n-nÃ£o): ");
                    scanf(" %c", &voltar);

                    // Adicionar ao ranking
                    strcpy(ranking[numUsuarios].nome, nomeUser);
                    ranking[numUsuarios].pontuacao = pontos;
                    numUsuarios++;

                    // Ordenar o ranking
                    ordenarRanking(ranking, numUsuarios);

                    // Salvar o ranking no arquivo
                    file = fopen(RANKING_FILE, "w");
                    if (file != NULL)
                    {
                        for (int i = 0; i < numUsuarios; i++)
                        {
                            fprintf(file, "%s %d\n", ranking[i].nome, ranking[i].pontuacao);
                        }
                        fclose(file);
                    }

                    if (voltar == 's')
                    {
                        break; // Sair do loop de jogo e voltar ao menu inicial
                    }
                    else if (voltar == 'n')
                    {
                        return 0; // Encerrar o programa
                    }
                }

                int TAM = strlen(tentativa);
                // Verificar se a palavra tem 5 letras
                if (TAM != 5)
                {
                    printf("TENTATIVA INVÁLIDA, INSIRA UMA PALAVRA DE >CINCO< LETRAS.\n\n");
                    j--;
<<<<<<< HEAD
        }
        
        else
        {
            // Verificar letras corretas na posiï¿½ï¿½o errada
            int acertou = 0;
            for (int i = 0; i < 5; i++)
            {   
                
                if (palavraSecreta[i] == tentativa[i])
                {
                    printf("Letra %c no índice %d: CORRETA\n", tentativa[i], i);
                    acertou = 1;
=======
>>>>>>> 6e2862b3fcdc3f9bbfab6ab8d2f8724070adeb66
                }
                else
                {
                    // Verificar letras corretas na posicaoo errada
                    int acertou = 0;
                    for (int i = 0; i < 5; i++)
                    {
                        if (palavraSecreta[i] == tentativa[i])
                        {
                            printf("Letra %c no índice %d: CORRETA\n", tentativa[i], i);
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
                    pontos -= 100;
                }
            }
<<<<<<< HEAD
            if(!acertou){
                printf("Nenhuma letra está correta.\n");
=======

            if (strcmp(palavraSecreta, tentativa) != 0)
            {
                printf("Você não conseguiu, a palavra secreta é: %s\n", palavraSecreta);
                end = clock();
                total_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Tempo de jogo: %.2f segundos\n", ((double) (end - start)) / CLOCKS_PER_SEC);
                printf("Deseja voltar ao menu inicial? (s-sim, n-nÃ£o): ");
                scanf(" %c", &voltar);

                if (voltar == 'n')
                {
                    return 0; // Encerrar o programa
                }
>>>>>>> 6e2862b3fcdc3f9bbfab6ab8d2f8724070adeb66
            }
        }
        else if (opcao == 2)
        {
            printf("=== RANKING ===\n");
            for (int i = 0; i < numUsuarios; i++)
            {
                printf("%d. %s - %d pontos\n", i + 1, ranking[i].nome, ranking[i].pontuacao);
            }
            printf("\nPressione Enter para voltar ao menu inicial...");
            while (getchar() != '\n')
                ;
            getchar(); // Aguardar Enter
        }
        else if (opcao == 3)
        {
            printf("Saindo...\n");
            printf("Tempo total jogado: %.2f segundos\n", total_time_used); // Mostra o tempo total ao sair
            return 0; // Encerrar o programa
        }
    }
    return 0;
}
