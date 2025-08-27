#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
int TAMANHO_VETOR;
float vetor [5+1];
void bubble_sort() 
{
  int i, j; float aux;
  int TAMANHO_VETOR = 6;	
  for ( j = 0; j<TAMANHO_VETOR-1; j++) 
  {
    for ( i = 0; i<TAMANHO_VETOR-1-j; i++) 
    {
      printf ("\nComparando %.2f com %.2f ", vetor[i], vetor[i+1]);
      if ( vetor[i] > vetor[i+1])//esse cara nessa posição é maior que a do lado?
      {
         printf ("->empurra %.2f para o fundo", vetor[i] );
         printf ("-> troca com %.2f", vetor[i+1]);
         aux 	   = vetor[i];//guarda valor pra não sobrescrever dados
	vetor[i] 	   = vetor[i+1];//troca de lugar
	vetor[i+1]  = aux;//troca de lugar pt2
      }
    }
    if (j<TAMANHO_VETOR-1)//não faz parte do bubble, só pra conseguir ver
       mostra_notas(vetor); /*exibe os valores das notas */
   }
}

int main(){
	/*
	printf("quantas notas quer??")
	scanf("%i",TAMANHO_VETOR)*/
	bubble_sort();
	getch;
	return 0;
}
