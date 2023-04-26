#include <stdio.h>
#define MAX_ALUNOS 1000000 
int main() {
    long int N;
    char registro[MAX_ALUNOS] = {'0'};
    long int numRegistro; 
    long int totalPresenca = 0; 
    scanf("%ld", &N);
    for (long int i = 0; i < N; i++) {
        scanf("%ld", &numRegistro);
        if(registro[numRegistro] == '1'){}
        else{
        registro[numRegistro] = '1';
        totalPresenca++;
        }
    }
    printf("%ld\n", totalPresenca);
    return 0;
}