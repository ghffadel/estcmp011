# ifndef FILA_H_INCLUDED
# define FILA_H_INCLUDED

typedef struct no {
  int valor;
  struct no *proximo;
} No;

No * criar_no (int valor) {
  No *novo = (No *) malloc(sizeof(No));
  novo->valor = valor; novo->proximo = NULL;
  return novo;
}

void enfileirar_no (No **inicio, No **fim, No *no) {
  if (*inicio == NULL) {
    *inicio = *fim = no;
  }

  else {
    (*fim)->proximo = no;
    *fim = no;
  }
}

void enfileirar_valor (No **inicio, No **fim, int valor) {
  No *no; no = criar_no(valor);

  if (*inicio == NULL) {
    *inicio = *fim = no;
  }

  else {
    (*fim)->proximo = no;
    *fim = no;
  }
}

No * desenfileirar (No **inicio) {
  No *removido; removido = *inicio;

  if (*inicio != NULL) {
    *inicio = (*inicio)->proximo;
    removido->proximo = NULL;
  }

  return removido;
}

void imprimir (No *fila) {
  No *atual = fila;

  if (atual == NULL) {
    printf("Fila vazia!");
  }

  while (atual != NULL) {
    printf("%d ", atual->valor);
    atual = atual->proximo;
  }

  printf("\n");
}

# endif // FILA_H_INCLUDED
