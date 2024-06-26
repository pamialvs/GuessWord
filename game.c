#include <stdio.h>
#include <string.h>
int main()
{
    char tentativa[6];
    char palavra[6] = "areio";

    for (int j = 0; j < 6; j++){
        printf("====== Digite uma palavra: ");
        scanf("%s", tentativa);

        if (!strcmp(palavra, tentativa) == 1){
            printf("VOCE ACERTOU!!\n");
            return 0;
            break;
        }else{
            for (int i = 0; i < 5; i++){
                if (palavra[i] == tentativa[i]){
                    printf("letra %c\nno indice %d\n", tentativa[i], i);
                }
            }
        }
    }

    return 0;
}