
/*
 * SOLUCAO 7: Versao mais elaborada. Usa o algoritmo de Euclides
 *    para determinar o maximo divisor comum de dois numero.
 *
 */

#include <stdio.h>

int main() 
{
  int n;         /* no. de elementos na sequencia */
  int i;         /* contador de numeros lidos */
  int mdc;       /* maximo divisor comum dos numeros lidos */
  int numero;    /* guarda um numero da sequencia */ 
  int resto;     /* usado para encontrar o novo mdc */

  printf("Determino mdc de n (>0) numeros positivos.\n");

  /* leia o tamanho da sequecia */
  printf("Entre com n: ");
  scanf ("%d", &n);

  /* leia o 1o. numero da sequencia */
  printf("Entre com o 1o. numero da sequencia: ");
  scanf ("%d", &mdc);
  
  for (i = 1; i < n; i++) 
    {
      printf("Entre com o %do. numero da sequencia: ", i+1);
      scanf ("%d", &numero);

      /* algoritmo de Euclides para encontra o maxi divisor comum de 
       * mdc e numero 
       */ 
      while (numero != 0) 
	{
	  resto = mdc % numero;
	  mdc   = numero;
	  numero = resto;
	}
      /* neste ponto do progra mdc contem o maximo divisor comum dos 
       * numeros lido
       */
    }

  printf("MDC = %d\n", mdc);
  return 0;
} 