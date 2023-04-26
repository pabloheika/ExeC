#include <stdio.h>

int main(){
    int quantosRestaurantes, codigoNota[999], melhorNota, melhorRestaurante, dia = 0;

    while ((scanf("%d", &quantosRestaurantes)) != EOF){
        dia++;
        melhorNota = 0;
        melhorRestaurante = 10^7+1;
        for (int i = 0; i < (quantosRestaurantes * 2); i++){
            scanf("%d", &codigoNota[i]);
            if ((i % 2 == 1) && (codigoNota[i] > 0 && codigoNota[i] < 6)){
                if (melhorNota < codigoNota[i]){
                    melhorNota = codigoNota[i];
                    melhorRestaurante = codigoNota[i-1];
                } else if ((codigoNota[i] == 5) && (codigoNota[i-1] < melhorRestaurante)){
                    melhorRestaurante = codigoNota[i-1];
                }
                
            }
            
        }
        printf("Dia %d\n%d\n\n", dia, melhorRestaurante);
    }

    return 0;
}