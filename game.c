#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

#define MAX_PALAVRAS 1000
#define TAMANHO_PALAVRA 6
#define MAX_USUARIOS 100
#define RANKING_FILE "ranking.txt"
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define PINK "\x1B[35;1m"
#define RESET "\x1B[0m"

typedef struct
{
    char nome[100];
    int pontuacao;
} Usuario;

// ordenar ranking
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
// funcao pra limpar tela
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
    // double total_time_used = 0.0;
    char tentativa[TAMANHO_PALAVRA];
    char palavraSecreta[TAMANHO_PALAVRA];
    char palavras[MAX_PALAVRAS][TAMANHO_PALAVRA];
    int opcao;
    char nomeUser[100];
    Usuario ranking[MAX_USUARIOS];
    int numUsuarios = 0;
    char voltar;
    // clock_t start, end;

    // Ler as palavras do arquivo
    FILE *file = fopen("palavras.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo: %s\n", strerror(errno));
        return 1;
    }

    for (int i = 0; i < MAX_PALAVRAS; i++)
    {
        fscanf(file, "%s", palavras[i]);
    }
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
        printf(MAG "=====================================\n");
        printf(PINK "    BEM VINDA(O)(E) AO GUESSWORD!    \n" RESET);
        printf(MAG "=====================================\n" RESET);
        printf("        Tecle a opção desejada:\n");
        printf("             1. Jogar\n");
        printf("             2. Ranking\n");
        printf("             4. Instruções\n");
        printf("             3. Sair\n");
        printf(MAG "=====================================\n" RESET);
        printf("\n");
        printf("-> ");
        scanf(" %d", &opcao);
        printf("\n");

        if (opcao == 1)
        {
            limparTela(); // limpar tela de menu ao entrar no jogo
            printf("Para começar, digite seu usuário: ");
            scanf("%s", nomeUser);
            printf("\n");
            printf("Seja bem vinda(o)(e)!" PINK " %s " RESET "esperamos que se divirta :)\n", nomeUser);
            int pontos = 600;

            // start = clock(); // Inicia contagem de tempo do jogo

            for (int j = 0; j < 6; j++)
            {
                printf("\n");
                // printf(MAG "=====================================\n" RESET);
                // printf("          Digite uma palavra:        \n");
                // printf(MAG "=====================================\n" RESET);
                printf("-> ");
                scanf("%s", tentativa);
                printf("\n");
                if (strcmp(palavraSecreta, tentativa) == 0)
                {
                    printf(GRN "VOCÊ ACERTOU!!\n" RESET);
                    // end = clock();
                    // total_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
                    // printf("Tempo de jogo: %.2f segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
                    printf("Deseja voltar ao menu inicial? (s-sim, n-não): ");
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
                    printf(RED "TENTATIVA INVÁLIDA, INSIRA UMA PALAVRA DE >CINCO< LETRAS.\n\n" RESET);
                    j--;
                }
                else
                {
                    // Verificar letras corretas na posicao errada
                    int acertou = 0;

                    for (int i = 0; i < 5; i++)
                    // deixando letras coloridas
                    {

                        if (palavraSecreta[i] == tentativa[i])
                        {
                            printf("|");
                            printf(GRN "%c" RESET, tentativa[i]);
                            acertou = 1;
                        }
                        else if (strchr(palavraSecreta, tentativa[i]) != NULL)
                        {
                            printf("|");
                            printf(YEL "%c" RESET, tentativa[i]);
                            acertou = 1;
                        }
                        else
                        {
                            printf("|");
                            printf("%c", tentativa[i]);
                        }
                    }
                    printf("|\n");

                    if (!acertou)
                    {
                        printf("Nenhuma letra está correta.\n");
                    }
                    pontos -= 100;
                }
            }

            if (strcmp(palavraSecreta, tentativa) != 0)
            {
                printf("Você não conseguiu, a palavra secreta é: %s\n", palavraSecreta);
                // end = clock();
                // total_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
                // printf("Tempo de jogo: %.2f segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
                printf("Deseja voltar ao menu inicial? (s-sim, n-não): ");
                scanf(" %c", &voltar);

                if (voltar == 'n')
                {
                    return 0; // Encerrar o programa
                }
            }
        }
        // mostrar ranking
        else if (opcao == 2)
        {
            limparTela(); // Limpar tela ao entrar no ranking
            printf("\n");
            printf(PINK "=====================================\n" RESET);
            printf(MAG "              RANKING                \n" RESET);
            printf(PINK "=====================================\n" RESET);
            for (int i = 0; i < numUsuarios; i++)
            {
                printf("%dÂº %s - %d pontos\n", i + 1, ranking[i].nome, ranking[i].pontuacao);
            }
            printf("\nPressione Enter para voltar ao menu inicial...");
            while (getchar() != '\n')
                ;
            getchar(); // Aguardar Enter
        }
        // instruÃ§Ãµes do jogo/ como jogar?
        else if (opcao == 4)
        {
            limparTela(); // Limpar tela ao entrar nas instruÃ§Ãµes
            printf("\n");
            printf(MAG "=====================================\n" RESET);
            printf(PINK "               INSTRUÇÕES             \n" RESET);
            printf(MAG "=====================================\n" RESET);
            printf("1. O objetivo do jogo é acertar uma palavra secreta.\n");
            printf("2. Descubra a palavra secreta de 5 letras. Você tem 6 tentativas. As cores nas letras mostram o quão perto você está da solução.\n");
            printf("\nLetra branca - Não faz parte da palavra\nLetra amarela - Faz parte da palavra mas está em outra posição\nLetra verde - Faz parte da palavra e está na posição correta\n");
            printf("\n3. Você pode escolher entre jogar, ver o ranking, ver as instruções ou sair.\n");
            printf("\nPressione Enter para voltar ao menu inicial...");
            while (getchar() != '\n')
                ;
            getchar(); // Aguardar Enter
        }
        else if (opcao == 3)
        {
            printf("Saindo...\n");
            // printf("Tempo total jogado: %.2f segundos\n", total_time_used); // Mostra o tempo total ao sair
            return 0; // Encerrar o programa
        }
    }
    return 0;
}