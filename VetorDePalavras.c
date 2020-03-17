#include <stdio.h>
#include <stdlib.h>
 
 
char **ListaPalavras(char texto[], int *npalavras){
  char **L = NULL;
  int i,j,tam,npal,inic;
  char *pal;
 
  /* Conta o número de palavras. */
  i = 0;
  npal = 0;
  while(texto[i] != '\0'){
    while(texto[i] == ' ')
      i++;
    if(texto[i] != '\0'){
      npal++;
      while(texto[i] != ' ' && texto[i] != '\0')
        i++;
    }
  }
  *npalavras = npal;
 
  /* Aloca o vetor de apontadores. */
  L = (char **)malloc(npal*sizeof(char *));
  if(L == NULL){
    printf("Memoria insuficiente.\n");
    exit(1);
  }
 
  i = 0;
  j = 0;
  while(texto[i] != '\0'){
    while(texto[i] == ' ')
      i++;
    inic = i;
    while(texto[i] != ' ' && texto[i] != '\0')
      i++;
 
    tam = i - inic;
    if(tam > 0){
      pal = (char *)malloc(sizeof(char)*(tam+1));
      if(pal == NULL){
        printf("Memoria insuficiente.\n");
        exit(1);
      }
      L[j] = pal;
      i = inic;
      while(texto[i] != ' ' && texto[i] != '\0'){
        pal[i-inic] = texto[i];
        i++;
      }
      pal[i-inic] = '\0';
      j++;
    }
  }
  return L;
}
 
int main(){
  char texto[] = "A  primeira Guerra Mundial    completa 100 anos    em 2014";
  char **L;
  int n,i;
 
  L = ListaPalavras(texto, &n);
 
  printf("Lista de palavras:\n");
  for(i = 0; i < n; i++){
    printf("%s.\n",L[i]);
  }
 
  /* Libera memória */
  for(i = 0; i < n; i++){ 
    free(L[i]);
  }
  free(L);
 
  return 0;
}
