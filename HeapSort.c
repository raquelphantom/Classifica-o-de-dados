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
/* Considerando que heap é um array e que a posição de um nó é i, a posição do seu filho da esquerda será (i * 2 + 1). */
int esquerdo(int i) 
{
  return (2*i+1);
}

/* Considerando que heap é um array e que a posição de um nó é i, a posição do seu filho da direita será (i * 2 + 1) + 1. */
int direito(int i) 
{
  return (2*i+2);
}

/* Considerando que heap é um array e que a posição de um nó é i, a posição do seu pai será (i - 1) / 2. */
int pai(int i) 
{
  return ( (i-1)/2 );
}

void heap_sort	(float * vetor)
{   
    int i, atual;

    for(i=TAMANHO_VETOR-1; i>0; i--)   /* percorre da última até a penúltima posição do vetor */
    {   /* (se todas as posições até a penúltima estiverem ordenadas, a última também estará) */
        troca(  &vetor[0], &vetor[i]  );       /* troca a posição corrente do heap com a raiz */
        
        /* i não pertence mais ao vetor */
        /* (o vetor vai diminuindo de tamanho, pois a última posição CERTAMENTE terá o maior valor) */
        
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
	float vetor [5+1];//ps:fazer mutável dps
	
	heap_sort(vetor);
	getch;
	return 0;
}
