#include <stdio.h>
int main(void) {
    unsigned long int n,a, i;
    scanf("%ld", &n);

    char proibidos[1000000];
    for ( i = 0; i < n; i++) {
        scanf("%ld", &a);
        proibidos[a]='1';
    }
    while (scanf("%ld", &a) != EOF) {
        if (proibidos[a] == '1') {
            printf("sim\n");
        } else {
            printf("nao\n");
        }
    }

    return 0;
}
