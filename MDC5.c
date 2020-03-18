
/*
 * SOLUCAO 5: identica a anterior, apenas troca os while's por for's.
 *
 *
 */

#include <stdio.h>

int main() 
{
  int n;         /* no. de elementos na sequencia */
  int i;         /* contador de numeros lidos */
  int mdc;       /* maximo divisor comum dos numeros lidos */
  int numero;    /* guarda um numero da sequencia */ 
  int divisor;   /* usado para encontrar  o novo mdc */

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

      /* calcule o max divisor comum de mdc e numero */ 
      for (divisor = mdc; mdc % divisor != 0 || numero % divisor != 0; divisor--); 

      /* atualize o mdc dos numeros lidos */
      mdc = divisor;
    }

  printf("MDC = %d\n", mdc);
  return 0;
} 
