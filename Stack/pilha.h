# ifndef PILHA_H_INCLUDED
# define PILHA_H_INCLUDED

typedef struct no {
  int valor;
  struct no *proximo;
} No;

No * criar_no (int valor) {
  No *novo = (No *) malloc(sizeof(No));
  novo->valor = valor; novo->proximo = NULL;
  return novo;
}

void empilhar_no (No **topo, No *no) {
  if (*topo != NULL) no->proximo = *topo;
  *topo = no;
}

void empilhar_valor (No **topo, int valor) {
  No *no = criar_no(valor);
  if (*topo != NULL) no->proximo = *topo;
  *topo = no;
}

No * desempilhar_no (No **topo) {
  No *retirado = *topo;

  if (retirado == NULL) {
    printf("Pilha vazia!\n");
  }

  else {
    *topo = (*topo)->proximo;
    retirado->proximo = NULL;
  }

  printf("Valor retirado: %d\n", retirado->valor);
  return retirado;
}

int desempilhar_valor (No **topo) {
  int valor;
  No *retirado = *topo;

  if (retirado == NULL) {
    printf("Pilha vazia!\n");
    return;
  }

  else {
    valor = retirado->valor;
    *topo = (*topo)->proximo;
    free(retirado);
    printf("Valor retirado: %d\n", valor);
    return valor;
  }
}

void imprimir (No *topo) {
  No *atual = topo;

  if (atual == NULL) {
    printf("Pilha vazia!");
  }

  while (atual != NULL) {
    printf("%d ", atual->valor);
    atual = atual->proximo;
  }

  printf("\n");
}

# endif // PILHA_H_INCLUDED
