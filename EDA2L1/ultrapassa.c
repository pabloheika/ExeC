#include <stdio.h>
#include <stdlib.h>
typedef struct reg {
   long int num;
   struct reg *prox;
} eda;

void insere(eda* l, long int num){
    if( l->prox == NULL){
        eda* novo = (eda*)malloc(sizeof(eda));
        novo->num = num;
        novo->prox = l->prox;
        l->prox = novo;     
    }else{
        insere(l->prox, num);
    }   
}
void limite(eda* l, long int num, long int soma){
    if( l == NULL){
    }else if( (soma + l->num) <= num){
        limite(l->prox, num, (soma + l->num));
    }else{
        limite(l->prox, num, 0);
        printf("%ld\n",l->num);
    }
}
int main(void)
{
    eda* l = (eda*)malloc(sizeof(eda));
    l->num = 0;
    l->prox = NULL;
    long int a, b;
    scanf ("%ld", &a);
    while (a != 0) {
	    insere(l, a); 
        scanf ("%ld", &a);       
    }
    scanf ("%ld", &b);
    limite(l, b, 0);
    return 0;
}
