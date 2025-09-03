#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
int TAMANHO_VETOR;
void troca (float *A, float *B) 
{
  float aux = *A; 
  *A = *B; 
  *B = aux;
} 
/* Considerando que heap � um array e que a posi��o de um n� � i, a posi��o do seu filho da esquerda ser� (i * 2 + 1). */
int esquerdo(int i) 
{
  return (2*i+1);
}

/* Considerando que heap � um array e que a posi��o de um n� � i, a posi��o do seu filho da direita ser� (i * 2 + 1) + 1. */
int direito(int i) 
{
  return (2*i+2);
}

/* Considerando que heap � um array e que a posi��o de um n� � i, a posi��o do seu pai ser� (i - 1) / 2. */
int pai(int i) 
{
  return ( (i-1)/2 );
}

void heap_sort	(float * vetor)
{   
    int i, atual;

    for(i=TAMANHO_VETOR-1; i>0; i--)   /* percorre da �ltima at� a pen�ltima posi��o do vetor */
    {   /* (se todas as posi��es at� a pen�ltima estiverem ordenadas, a �ltima tamb�m estar�) */
        troca(  &vetor[0], &vetor[i]  );       /* troca a posi��o corrente do heap com a raiz */
        
        /* i n�o pertence mais ao vetor */
        /* (o vetor vai diminuindo de tamanho, pois a �ltima posi��o CERTAMENTE ter� o maior valor) */
        
        /* ajusta o heap */
        atual = 0;
        while ( direito(atual) <= (i-1)                                       /* Enquanto tiver 2 filhos                                  */
                &&                                                                       /* E                                                                    */
	( vetor[atual] < vetor[esquerdo(atual)] ||     /* o pai for menor que um dos dois filhos...     */
                 vetor[atual] < vetor[direito(atual)] ) )
        {   /*...troca o pai com o maior dos filhos */
            if ( vetor[esquerdo(atual)] > vetor[direito(atual)] )
            {
               troca(  &vetor[atual], &vetor[esquerdo(atual)]  ); /*troca o atual com o filho esquerdo*/
               atual = esquerdo(atual);
            } 
            else 
            {
                troca(  &vetor[atual], &vetor[direito(atual)]  ); /*troca o atual com o filho direito*/
                atual = direito(atual);
            }
        }
        /* Verificar se sobrou um filho (esquerdo) maior que o atual */
        if ( esquerdo(atual) <= i-1 && vetor[atual] < vetor[esquerdo(atual)] )
        {
            troca(  &vetor[atual], &vetor[esquerdo(atual)]  ); /*troca o atual com o filho esquerdo*/
            atual = esquerdo(atual);
        }
    }
}

int main()
{
	float vetor [5+1];//ps:fazer mut�vel dps
	
	heap_sort(vetor);
	getch;
	return 0;
}
