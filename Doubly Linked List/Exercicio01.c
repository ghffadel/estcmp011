# include <stdio.h>
# include <stdlib.h>
# include "lista.h"

int main () {
  int i, n;
  No *impares, *pares;

  impares = pares = NULL;

  printf("Digite o valor de n: "); scanf("%d", &n);

  int vetor[n];

  for (i = 0; i < n; i++) {
    printf("Digite o valor da posicao %d: ", i + 1); scanf("%d", &vetor[i]);

    if (vetor[i] % 2 == 0) {
      pares = inserir_fim(&pares, vetor[i]);
    }

    else {
      impares = inserir_fim(&impares, vetor[i]);
    }
  }

  printf("Pares: "); imprimir(pares);
  printf("Impares: "); imprimir(impares);

  free(pares); free(impares);

  return 0;
}
