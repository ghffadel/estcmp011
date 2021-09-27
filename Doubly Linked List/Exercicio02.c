# include <stdio.h>
# include <stdlib.h>
# include "lista.h"

No * unir_listas (No *lista1, No *lista2) {
  No *uniao; uniao = NULL;

  while (lista1 != NULL) {
    uniao = inserir_fim(&uniao, lista1->conteudo); lista1 = lista1->proximo;
  }

  while (lista2 != NULL) {
    uniao = inserir_fim(&uniao, lista2->conteudo); lista2 = lista2->proximo;
  }

  return uniao;
}

int main () {
  int i, tamanho, valor;
  No *lista1, *lista2;

  lista1 = lista2 = NULL;

  printf("Digite o tamanho da primeira lista: "); scanf("%d", &tamanho);

  for (i = 0; i < tamanho; i++) {
    printf("Digite o elemento da posicao %d: ", i + 1); scanf("%d", &valor);
    lista1 = inserir_fim(&lista1, valor);
  }

  printf("\nDigite o tamanho da segunda lista: "); scanf("%d", &tamanho);

  for (i = 0; i < tamanho; i++) {
    printf("Digite o elemento da posicao %d: ", i + 1); scanf("%d", &valor);
    lista2 = inserir_fim(&lista2, valor);
  }

  No *uniao = unir_listas(lista1, lista2);

  printf("\nUniao das duas listas: "); imprimir(uniao);

  liberar_memoria(&lista1); liberar_memoria(&lista2); liberar_memoria(&uniao);

  return 0;
}
