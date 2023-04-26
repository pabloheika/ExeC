#include <stdio.h>

int main(void)
{
    char nome[102];
    int a;
    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        scanf("%s", nome);
        int b = 0;
        for (int j = 0; nome[j] != '\0'; j++)
        {
            if (nome[j] >= '0' && nome[j] <= '9')
            {
                b += (nome[j] - '0');
            }
        }
        printf("%d\n",b);
    }

    return 0;
}