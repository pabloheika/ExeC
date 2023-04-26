#include <stdio.h>
#include <stdlib.h>
typedef struct reg
{
    long int num;
    char letra;
    long int local;
    struct reg *prox;
} eda;

eda* insere( eda *l ,long int num,char letra, long int local)
{
    eda *aux, *novo = (eda *)malloc(sizeof(eda));
    novo->num = num;
    novo->letra = letra;
    novo->local = local;
    novo->prox = NULL;
    if (l == NULL)
    {        
        return novo;
    }
    else if(num > l->num){
        novo->prox = l;
        return novo;
    }else 
    {
        aux = l;
        while (aux->prox && num <= aux->prox->num)
        {
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
        return l;
    }
}
int main(void)
{
    char frase[100020], aux;
    eda *l = NULL;
    long int a, b=0;
    fgets(frase, sizeof(frase), stdin);
    //scanf("%s", frase);
    for (long int j = 0; frase[j] != '\n'; j++)
    {
        if (j == 0){
            aux = frase[j];
            a = j;
            b++;
        }
        else if( aux == frase[j]){
            b++;
        }else{
            l = insere(l, b, aux, a);
            b=1;
            aux= frase[j];
            a = j;
        }
    }
    l = insere(l, b, aux, a);
    while (l)
    {
        printf("%ld %c %ld\n", l->num,l->letra,l->local);
        l = l->prox;
    }
    
    return 0;
}
