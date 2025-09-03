#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void merge(float *vetor, int inicio, int meio, int fim)
{
	int tamEsq, tamDir, i, idxDir, idxEsq;
	float *vetor_Esq;
	float *vetor_Dir;
	
	tamEsq = meio - inicio + 1;
	tamDir = fim - meio;
	
	vetor_Esq = (float *) malloc( tamEsq * sizeof (float));
	if (vetor_Esq == NULL)
	{
		printf("malloc devolveu NULL\n");
		getch();
		exit(EXIT_FAILURE);
	}
	
	vetor_Dir = (float *) malloc( tamDir * sizeof (float));
	if (vetor_Esq == NULL)
	{
		printf("malloc devolveu NULL\n");
		getch();
		exit(EXIT_FAILURE);
	}
	
	for(i=0; i<tamEsq; i++) 
	{
		vetor_Esq[i] = vetor[inicio+i];
	}
	for(i=0; i<tamDir; i++)
	{
		vetor_Dir[i] = vetor[meio+1+i];		
	}
	
	idxEsq =0;
	idxDir = 0;
	
	for( i=inicio; i<=fim; i++)
	{
		if(idxEsq < tamEsq)
		{
			if(idxDir< tamDir)
			{
				if (vetor_Esq[idxEsq]< vetor_Dir[idxDir])
				{
					vetor[i] = vetor_Esq[idxEsq++];
				}
				else
				{
					vetor[i] = vetor_Dir[idxDir++];	
				}
			}
			else
			{
					vetor[i] = vetor_Esq[idxEsq++]; 	
			}
		}
		else
		{
			vetor[i] = vetor_Dir[idxDir++];					
		}
	}
	free(vetor_Esq);
	free(vetor_Dir);
}

void merge_sort (float * vetor, int inicio, int fim) 
{
  int  meio;
  if ( inicio < fim )
  {
    meio = (inicio + fim) / 2;        /*calcula o meio                        */
    merge_sort (vetor, inicio, meio); /*ordena o subvetor esquerdo            */
    merge_sort (vetor, meio+1, fim ); /*ordena o subvetor direito             */
    merge (vetor, inicio, meio, fim); /*funde os subvetores esquerdo e direito*/
  }
}
int main()
{
	int inicio,fim;
	float vetor [5+1];
	
	merge_sort(vetor, inicio, fim);
	getch;
	return 0;
}
