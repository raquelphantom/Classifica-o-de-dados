#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
int TAMANHO_VETOR;
float vetor [5+1];

//protótipos
char menu (void);
void gerencia (char opc);
void bubble_sort (void);
void insertion_sort(void);
void selection_sort(void);

char menu (void){
	char opc;
	do{
	system("cls");
	printf("\n ======================= \n");
	printf("             MENU         ");
	printf("\n ======================= \n");
	printf("1- BubbleSort\n");
	printf("2- InsertionSort\n");
	printf("3 - SelectionSort\n");
	printf("0 - encerrar\n");
	printf("Escolha:");
	fflush(stdin);opc = getche();
	}while(opc<'0' || opc>'3');
		return (opc);
};

void gerencia (char opc){
	switch(opc){
		case '0' : exit(0); break;
		case '1' : bubble_sort(); break;
		case '2' : insertion_sort(); break;
		case '3' : selection_sort(); break;
	};
};

void    abastece_notas (float*vetor)
{  int i;
   for (i=0; i<TAMANHO_VETOR; i++)
      do 
      {
         vetor[i] = rand()%11;// + rand()%10*0.23;
      }
      while ( vetor[i] > 10 );
}

void bubble_sort(float*vetor) 
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
 }
}

void insertion_sort(float*vetor) 
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
void selection_sort (float*vetor) 
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
void mostrar(float*vetor){
	int i;
	for(i=0; i<TAMANHO_VETOR; i++)
		printf("%2.f,")
}
int main(){
	abastece_notas();
	char escolha;
	do{
	escolha = menu();
	gerencia(escolha);
	} while(escolha != '0');
	return 0;
}
