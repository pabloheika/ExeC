#include <stdio.h>
#include <stdlib.h>

typedef struct reg
{
    unsigned int num;
    char letra;
    unsigned int local;
    struct reg *prox;
    struct reg *ant;
} eda;

int main(void)
{
    char frase[100020], aux;
    eda *l = NULL, *ultimo = NULL;
    unsigned int a, num = 0;
    scanf("%s", frase);
    aux = frase[0];
    a = 0;
    for (unsigned int j = 0; frase[j] != '\0'; j++)
    {
        if (aux == frase[j])
        {
            num++;
        }
        else
        {
            eda *novo = (eda *)malloc(sizeof(eda));
            novo->num = num;
            novo->letra = aux;
            novo->local = a;
            novo->prox = NULL;
            novo->ant = NULL;
            if (!l)
            {
                ultimo = novo;
                l = novo;
            }
            else if (num > l->num)
            {
                novo->prox = l;
                l->ant = novo;
                l = novo;
            }
            else if (num <= ultimo->num)
            {
                ultimo->prox = novo;
                novo->ant = ultimo;
                ultimo = novo;
            }
            else
            {
                eda *aux1 = l, *aux2 = ultimo;
                while ((aux1 && num <= aux1->num) && (aux2 && num > aux2->num))
                {
                    aux2 = aux2->ant;
                    aux1 = aux1->prox;
                }
                if (aux1->num < num)
                {
                    novo->prox = aux1;
                    novo->ant = aux1->ant;
                    aux1->ant->prox = novo;
                    aux1->ant = novo;
                }
                else
                {
                    novo->prox = aux2->prox;
                    novo->ant = aux2;
                    aux2->prox->ant = novo;
                    aux2->prox = novo;
                }
            }
            aux = frase[j];
            a = j;
            num = 1;
        }
    }
    eda *novo = (eda *)malloc(sizeof(eda));
    novo->num = num;
    novo->letra = aux;
    novo->local = a;
    novo->prox = NULL;
    novo->ant = NULL;
    if (!l)
    {
        ultimo = novo;
        l = novo;
    }
    else if (num > l->num)
    {
        novo->prox = l;
        l->ant = novo;
        l = novo;
    }
    else if (num <= ultimo->num)
    {
        ultimo->prox = novo;
        novo->ant = ultimo;
        ultimo = novo;
    }
    else
    {
        eda *aux1 = l, *aux2 = ultimo;
        while ((aux1 && num <= aux1->num) && (aux2 && num > aux2->num))
        {
            aux2 = aux2->ant;
            aux1 = aux1->prox;
        }
        if (aux1->num < num)
        {
            novo->prox = aux1;
            novo->ant = aux1->ant;
            aux1->ant->prox = novo;
            aux1->ant = novo;
        }
        else
        {
            novo->prox = aux2->prox;
            novo->ant = aux2;
            aux2->prox->ant = novo;
            aux2->prox = novo;
        }
    }
    while (l)
    {
        printf("%d %c %d\n", l->num, l->letra, l->local);
        l = l->prox;
    }

    return 0;
}
