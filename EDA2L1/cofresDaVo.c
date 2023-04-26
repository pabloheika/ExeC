#include <stdio.h>

int main()
{
    int a, b, c, d = 0, j, i = 0;
    scanf("%d", &a);
    while (a != 0)
    {
        i++;
        printf("Teste %d\n", i);
        for (j = 1; j <= a; j++)
        {
            scanf("%d %d", &b, &c);
            d += b - c;
            printf("%d\n", d);
        }
        printf("\n");
        d = 0;
        scanf("%d", &a);
    }
    return 0;
}
