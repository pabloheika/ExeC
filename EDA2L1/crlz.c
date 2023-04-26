#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
typedef struct reg {
   char texto[110];
   struct reg *prox;
} eda;
eda *remover(eda *p)
{
    if(p == NULL){
        printf ("NULL\n");
        return p;
    }
   eda *salva = p->prox;
   printf ( "%s", p->texto);
   free(p);
   return salva;
}

eda* insere(eda* l, char texto[]){
    eda* novo = (eda*)malloc(sizeof(eda));
    for (int i=8; i<=110; i++) {
        novo->texto[i-8] = texto[i];
    }
    novo->prox = l;
    return novo;
}
int main(void)
{
    eda* l = NULL;
    char frase[110];
    while (fgets(frase, sizeof(frase), stdin) != NULL) {
        if(frase[0] == 'i'){
	      l = insere(l, frase);
        }else if(frase[0] == 'd'){
            l = remover(l);
        }else{
            break;
        }
    }
    return 0;
}
