# ifndef LISTA_H_INCLUDED
# define LISTA_H_INCLUDED

typedef struct no {
  int conteudo;
  struct no *proximo;
  struct no *anterior;
} No;

No * criar_no (int conteudo) {
  No *novo = (No *) malloc(sizeof(No));
  novo->conteudo = conteudo; novo->anterior = novo->proximo = NULL;
  return novo;
}

No * inserir_inicio (No **lista, int conteudo) {
  No *inicio, *novo;

  if (*lista == NULL) {
    novo = criar_no(conteudo); inicio = *lista = novo;
  }

  else {
    inicio = *lista;
    novo = criar_no(conteudo); novo->proximo = inicio;
    inicio->anterior = novo; inicio = novo;
  }

  return inicio;
}

No * inserir_fim (No **lista, int conteudo) {
  No *inicio, *novo;

  if (*lista == NULL) {
    novo = criar_no(conteudo); inicio = *lista = novo;
  }

  else {
    inicio = *lista;

    while ((*lista)->proximo != NULL) {
      *lista = (*lista)->proximo;
    }

    novo = criar_no(conteudo); (*lista)->proximo = novo;
    novo->anterior = *lista;
  }

  return inicio;
}

No * remover (No **lista, int conteudo) {
  No *anterior, *atual, *inicio;
  anterior = atual = inicio = *lista;

  if (atual->conteudo == conteudo) {
    atual = atual->proximo; atual->anterior = anterior->proximo = NULL;
    free(anterior); inicio = atual;
    printf("Elemento %d foi removido!\n", conteudo);
  }

  else {
    while (atual->conteudo != conteudo && atual->proximo != NULL) {
      anterior = atual; atual = atual->proximo;
    }

    if (atual->conteudo == conteudo) {
      if (atual->proximo != NULL) {
        anterior->proximo = atual->proximo;
        atual->proximo->anterior = anterior;
        atual->anterior = atual->proximo = NULL;
        free(atual);
        printf("Elemento %d foi removido!\n", conteudo);
      }

      else {
        anterior->anterior = anterior->proximo = NULL;
        free(atual);
        printf("Elemento %d foi removido!\n", conteudo);
      }
    }

    else {
      printf("Elemento %d nao foi encontrado!\n", conteudo);
    }
  }

  return inicio;
}

int buscar (No *primeiro, int conteudo) {
  while (primeiro != NULL) {
    if (primeiro->conteudo == conteudo) return 1;
    primeiro = primeiro->proximo;
  }

  return 0;
}

void imprimir (No *lista) {
  while (lista != NULL) {
    printf("%d ", lista->conteudo);
    lista = lista->proximo;
  }

  printf("\n");
}

void imprimir_dois_sentidos (No *lista) {
  No *anterior = lista;

  while (lista != NULL) {
    printf("%d ", lista->conteudo);
    anterior = lista; lista = lista->proximo;
  }

  printf("\n");
  lista = anterior;

  while (lista != NULL) {
    printf("%d ", lista->conteudo);
    lista = lista->anterior;
  }

  printf("\n");
}

void liberar_memoria (No **lista) {
  No *anterior, *atual = *lista;

  while (atual != NULL) {
    anterior = atual; atual = atual->proximo; free(anterior);
  }

  *lista = NULL;
}

# endif // LISTA_H_INCLUDED
