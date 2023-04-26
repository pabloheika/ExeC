#include <stdio.h>
#include <stdlib.h>

typedef struct reg
{
    long int num;
    char letra;
    long int local;
    struct reg *prox;
    struct reg *ant;
} eda;

eda *insere(eda *l, long int num, char letra, long int local, eda **ultimo)
{
    eda *aux1 = l, *aux2 = *ultimo, *novo = (eda *)malloc(sizeof(eda));
    novo->num = num;
    novo->letra = letra;
    novo->local = local;
    novo->prox = NULL;
    novo->ant = NULL;
    if (l == NULL)
    {
        *ultimo = novo; // Atualiza o ponteiro "ultimo" quando a lista está vazia
        return novo;
    }
    else if (num > l->num)
    {
        novo->prox = l;
        l->ant = novo;
        //*ultimo = novo; // Atualiza o ponteiro "ultimo" quando o novo nó é inserido no início da lista
        return novo;
    }
    else if (num <= (*ultimo)->num)
    {
        (*ultimo)->prox = novo;
        novo->ant = *ultimo;
        //*ultimo = novo; // Atualiza o ponteiro "ultimo" quando o novo nó é inserido no início da lista
        return l;
    }
    else
    {
        while ((aux1 && num <= aux1->num)&&(aux2 && num > aux2->num))
        {
            aux2 = aux2->ant;
            aux1 = aux1->prox;
        }
        if(aux1->num < num){
            novo->prox = aux1;
            novo->ant = aux1->ant;
            aux1->ant->prox = novo;
            aux1->ant = novo;
            return l;
        }else if(aux2->num >= num){
            novo->prox = aux2->prox;
            novo->ant = aux2;
            aux2->prox->ant = novo;
            aux2->prox = novo;
            return l;
        }
        /*if (aux1 == NULL)
        {
            novo->ant = *ultimo;
            (*ultimo)->prox = novo;
            return l;
        }
        else
        {
            novo->prox = aux1;
            novo->ant = *ultimo;
            aux1->ant = novo;
            (*ultimo)->prox = novo;
        }

        if (novo->prox == NULL)
        {
            *ultimo = novo; // Atualiza o ponteiro "ultimo" quando o novo nó é inserido no final da lista
        }
        */
        //return l;
    }
}

int main(void)
{
    char frase[100020], aux;
    eda *l = NULL;
    long int a, b = 0;
    eda *ultimo = NULL; // Adicionado o ponteiro para o último elemento da lista
    scanf("%s", frase);
    for (long int j = 0; frase[j] != '\0'; j++)
    {
        if (j == 0)
        {
            aux = frase[j];
            a = j;
            b++;
        }
        else if (aux == frase[j])
        {
            b++;
        }
        else
        {
            l = insere(l, b, aux, a, &ultimo); // Passa o ponteiro "ultimo" como parâmetro
            b = 1;
            aux = frase[j];
            a = j;
        }
    }
    l = insere(l, b, aux, a, &ultimo); // Passa o ponteiro "ultimo" como parâmetro
    while (l)
    {
        printf("%ld %c %ld\n", l->num, l->letra, l->local);
        l = l->prox;
    }

    return 0;
}
