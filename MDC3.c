
/*
 * SOLUCAO 3: identica a solucao anterior. Usa a variavel pcomo contador 
 *    de numero a serem lidos.
 *
 */

#include <stdio.h>

int main() 
{
  int n;         /* no. de elementos na sequencia */
  int mdc;       /* maximo divisor comum dos numeros lidos */
  int numero;    /* guarda um numero da sequencia */ 
  int novo_mdc;  /* candidato a novo mdc */
  int divisor;   /* usado para encontra  o novo mdc */

  printf("Determino mdc de n (>0) numeros positivos.\n");

  /* leia o tamanho da sequecia */
  printf("Entre com n: ");
  scanf ("%d", &n);

  /* leia o 1o. numero da sequencia */
  printf("Entre com um numero da sequencia: ");
  scanf ("%d", &mdc);
  n = n - 1;

  while (n > 0) 
    {
      printf("Entre com um numero da sequencia: ");
      scanf ("%d", &numero);
      n = n - 1; /* mais um numero foi lido */

      /* calcule o max divisor comum de mdc e numero */ 
      divisor = 1;
      while (divisor <= mdc && divisor <= numero) 
        {
          if (mdc % divisor == 0 && numero % divisor == 0) 
	    {
              novo_mdc = divisor;                
            }
          divisor = divisor + 1;
        }

      /* atualize o mdc dos numeros lidos */
      mdc = novo_mdc;
    }

  printf("MDC = %d\n", mdc);
  return 0;
} 