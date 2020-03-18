/*
 * SOLUCAO 1: o programa usa a igualdade mdc(a,b,c) == mdc(mdc(a,b),c).
 *   Em cada iteracao o mdc de dois numeros, digamos num1 e num2,
 *   e' encontrado examinando-se os numero 
 *           1, 2, 3,  ..., min(num1,num2)  
 *   nessa ordem.
 */

#include <stdio.h>

int main() {
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
  while (i < n) {
      printf("Entre com o %do. numero da sequencia: ", i+1);
      scanf ("%d", &numero);
      i = i + 1; /* mais um numero foi lido */

      /* calcule o max divisor comum de mdc e numero */ 
      divisor = 1;
      while (divisor <= mdc && divisor <= numero) {
          if (mdc % divisor == 0 
              && numero % divisor == 0) {
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
