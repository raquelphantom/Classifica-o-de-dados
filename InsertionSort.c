#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
int TAMANHO_VETOR;
float vetor [5+1];
void insertion_sort() 
{
    float escolhido;
    int   anterior, i;
      int TAMANHO_VETOR = 6;
    for (i = 1; i < TAMANHO_VETOR; i++) /* começa do 2º elemento */
    {	escolhido = vetor[i];
	anterior  = i - 1;
	/* Vai puxando os menores que o escolhido até encontrar
             um lugar para inseri-lo*/
         while ( (anterior >= 0) && (vetor[anterior] > escolhido) ) 
	{
	    vetor[anterior + 1] = vetor[anterior];
	    anterior--;
	}
	vetor[anterior + 1] = escolhido;
    }
}
int main(){
	insertion_sort();
	getch;
	return 0;
}
