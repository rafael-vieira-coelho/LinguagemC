/*
 * SOLUCAO 1: o programa usa a igualdade mdc(a,b,c) == mdc(mdc(a,b),c).
 *   Em cada iteracao o mdc de dois numeros, digamos num1 e num2,
 *   e' encontrado examinando-se os numero 
 *           1, 2, 3,  ..., min(num1,num2)  
 *   nessa ordem.
 */

#include <stdio.h>

int main() 
{
  int n;         /* no. de elementos na sequencia */
  int i;         /* contador de numeros lidos */
  int mdc;       /* maximo divisor comum dos numeros lidos */
  int numero;    /* guarda um numero da sequencia */ 
  int novo_mdc;  /* candidato a novo mdc */
  int divisor;   /* usado para encontrar  o novo mdc */

  printf("Determino mdc de n (>0) numeros positivos.\n");

  /* leia o tamanho da sequecia */
  printf("Entre com n: ");
  scanf ("%d", &n);

  /* leia o 1o. numero da sequencia */
  printf("Entre com o 1o. numero da sequencia: ");
  scanf ("%d", &mdc);
  
  i = 1;
  while (i < n) 
    {
      printf("Entre com o %do. numero da sequencia: ", i+1);
      scanf ("%d", &numero);
      i = i + 1; /* mais um numero foi lido */

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

/*
 * SOLUCAO 2: identica a anterior, apenas troca os while's por for's.
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
  int novo_mdc;  /* candidato a novo mdc */
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
      for (divisor = 1; divisor <= mdc && divisor <= numero; divisor++) 
        {
          if (mdc % divisor == 0 && numero % divisor == 0) 
	    {
              novo_mdc = divisor;                
            }
         }

      /* atualize o mdc dos numeros lidos */
      mdc = novo_mdc;
    }

  printf("MDC = %d\n", mdc);
  return 0;
} 

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

/*
 * SOLUCAO 4: o programa usa a igualdade mdc(a,b,c) == mdc(mdc(a,b),c).
 *   Em cada iteracao o mdc de dois numeros, digamos num1 e num2,
 *   e' encontrado examinando-se os numero 
 *              num1, num1-1, num1-2,..., 2, 1,
 *   nessa ordem.
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
  
  i = 1;
  while (i < n) 
    {
      printf("Entre com o %do. numero da sequencia: ", i+1);
      scanf ("%d", &numero);

      /* calcule o max divisor comum de mdc e numero */ 
      divisor = mdc; 
      while (mdc % divisor != 0 || numero % divisor != 0) 
	{ 
          divisor--;
        } 

      /* atualize o mdc dos numeros lidos */
      mdc = divisor;
    }

  printf("MDC = %d\n", mdc);
  return 0;
} 

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

/*
 * SOLUCAO 6: versao um pouco mais elaborada da solucao 4.
 *    Os parenteses superfluos foram removidos. (Ha quem goste
 *    desses parenteses.
 */

#include <stdio.h>

int main() 
{
  int n;         /* no. de elementos na sequencia */
  int i;         /* contador de numeros lidos */
  int mdc;       /* maximo divisor comum dos numeros lidos */
  int numero;    /* guarda um numero da sequencia */ 
  int divisor;   /* usado para encontrar o novo mdc */

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
      if (mdc < numero) 
          divisor = mdc;
      else
          divisor = numero;

      while (mdc % divisor != 0 || numero % divisor != 0)
	divisor--; 
      
      /* atualize o mdc dos numeros lidos */
      mdc = divisor;
    }

  printf("MDC = %d\n", mdc);
  return 0;
} 

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
