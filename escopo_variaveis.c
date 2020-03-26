#include <stdio.h>

int global = 666;

int soma (int x, int y) {
      int s;

      s = x + y;
      return s;
}

int multiplica (int x, int y) {
      int m;

      m = x * y;
      return m;
}

int main() {
	int v1, v2, s, m;

	printf ("Informe o valor 1: "); 
	scanf("%d", &v1);
	printf ("Informe o valor 2: "); 
	scanf("%d", &v2);

	s = soma(v1, v2);
	m = multiplica(v1, v2);

	printf("Soma = %d, Produto = %d \n", s, m);
	return 0;
}