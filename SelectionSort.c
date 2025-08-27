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
    /* Percorre todo o vetor até TAMANHO_VETOR-1, 
       pois a última posição não precisa testar, pois já estará ordenada */
    for(i=0; i < TAMANHO_VETOR-1; i++) 
    {
        pos_min = i; /* A posição do menor valor recebe a posição que está passando */
        /* Percorre o vetor da posição i+1 até o final (varre o subvetor)*/
        for (j=i+1; j < TAMANHO_VETOR; j++) 
        {
        	/* Testa se o elemento da posição que está passando
               é menor que o elemento daquela que considera-se ter o menor valor */
            if (vetor[j] < vetor[pos_min]) 
                pos_min = j; /* pos_min recebe a posição do menor valor */
        }
        /* Varreu o subvetor
           Se a posição do menor for diferente da que está passando, ocorre a troca */
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
