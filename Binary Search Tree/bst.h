# ifndef BST_H_INCLUDED
# define BST_H_INCLUDED

typedef struct no {
  int chave;
  struct no *esquerda, *direita;
} No;

No *criar_no (int chave) {
  No *no = (No *) malloc(sizeof(No));
  no->chave = chave;
  no->esquerda = no->direita = NULL;
  return no;
}

void inserir_aux (No *raiz, int chave) {
  if (raiz->chave > chave) {
    if (raiz->esquerda == NULL) raiz->esquerda = criar_no(chave);
    else inserir_aux(raiz->esquerda, chave);
  }

  else {
    if (raiz->direita == NULL) raiz->direita = criar_no(chave);
    else return inserir_aux(raiz->direita, chave);
  }
}

void inserir (No **raiz, int chave) {
  if (*raiz == NULL) *raiz = criar_no(chave);
  else inserir_aux(*raiz, chave);
}

No *maior_chave (No *atual, No **anterior) {
  *anterior = atual;
  atual = atual->esquerda;

  while (atual->direita) {
    *anterior = atual;
    atual = atual->direita;
  }

  return atual;
}

No *buscar_no (No *raiz, int chave, No **pai) {
  No *atual = raiz;
  *pai = NULL;

  while (atual) {
    if (atual->chave == chave) return atual;
    *pai = atual;
    if (atual->chave > chave) atual = atual->esquerda;
    else atual = atual->direita;
  }

  return NULL;
}

void excluir (No **raiz, int chave) {
  No *atual, *pai, *pai_substituto, *substituto;
  substituto = NULL;
  atual = buscar_no(*raiz, chave, &pai);

  if (atual == NULL) return;

  if (atual->esquerda && atual->direita) {
    substituto = maior_chave(atual, &pai_substituto);
    atual->chave = substituto->chave;
    if (pai_substituto->esquerda == substituto) pai_substituto->esquerda = substituto->esquerda;
    else pai_substituto->direita = substituto->esquerda;
    free(substituto);
  }

  else {
    if (!atual->esquerda) substituto = atual->direita;
    if (!atual->direita) substituto = atual->esquerda;
    if (!pai) *raiz = substituto;
    else {
      if (pai->chave > chave) pai->esquerda = substituto;
      else pai->direita = substituto;
    }
    free(atual);
  }
}

No *buscar (No *raiz, int chave) {
  if (raiz == NULL) return NULL;
  else if (raiz->chave < chave) return buscar(raiz->direita, chave);
  else if (raiz->chave == chave) return raiz;
  else return buscar(raiz->esquerda, chave);
}

void imprimir_pre_ordem (No *raiz) {
  if (raiz == NULL) return;
  printf("%d ", raiz->chave);
  imprimir_pre_ordem(raiz->esquerda);
  imprimir_pre_ordem(raiz->direita);
}

void imprimir_em_ordem (No *raiz) {
  if (raiz == NULL) return;
  imprimir_em_ordem(raiz->esquerda);
  printf("%d ", raiz->chave);
  imprimir_em_ordem(raiz->direita);
}

void imprimir_pos_ordem (No *raiz) {
  if (raiz == NULL) return;
  imprimir_pos_ordem(raiz->esquerda);
  imprimir_pos_ordem(raiz->direita);
  printf("%d ", raiz->chave);
}

void destruir_aux (No *subraiz) {
  if (subraiz) {
    destruir_aux(subraiz->esquerda);
    destruir_aux(subraiz->direita);
    free(subraiz);
  }
}

void destruir (No **raiz) {
  destruir_aux(*raiz);
  *raiz = NULL;
}

# endif // BST_H_INCLUDED
