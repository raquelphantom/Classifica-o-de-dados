#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
int TAMANHO_VETOR;
float vetor [5+1];
void selection_sort () 
{
    int 	pos_min, i, j;
    float 	aux;// tem que ter o msm tipo que o dado
    int TAMANHO_VETOR = 6;
    /* Percorre todo o vetor at� TAMANHO_VETOR-1, 
       pois a �ltima posi��o n�o precisa testar, pois j� estar� ordenada */
    for(i=0; i < TAMANHO_VETOR-1; i++) 
    {
        pos_min = i; /* A posi��o do menor valor recebe a posi��o que est� passando */
        /* Percorre o vetor da posi��o i+1 at� o final (varre o subvetor)*/
        for (j=i+1; j < TAMANHO_VETOR; j++) 
        {
        	/* Testa se o elemento da posi��o que est� passando
               � menor que o elemento daquela que considera-se ter o menor valor */
            if (vetor[j] < vetor[pos_min]) 
                pos_min = j; /* pos_min recebe a posi��o do menor valor */
        }
        /* Varreu o subvetor
           Se a posi��o do menor for diferente da que est� passando, ocorre a troca */
        if (pos_min != i) 
        {
            aux            = vetor[i];
            vetor[i]       = vetor[pos_min];
            vetor[pos_min] = aux;
        }
    }
}
int main(){
	selection_sort();
	getch;
	return 0;
}
