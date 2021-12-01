int max (int x, int y) {
  if (x > y) return x;
  else return y;
}

typedef struct No {
  struct No *esquerda, *direita;
  int valor;
} No;

typedef struct Arvore {
  No *raiz;
} Arvore;

Arvore *criar_arvore () {
  Arvore *arvore = malloc(sizeof(Arvore));

  arvore->raiz = NULL;

  return arvore;
}

No *criar_no (int valor) {
  No *no = malloc(sizeof(No));

  no->esquerda = no->direita = NULL;
  no->valor = valor;

  return no;
}

int altura (No *no) {
  int altura_esquerda = 0, altura_direita = 0;

  if (no->esquerda) altura_esquerda = altura(no->esquerda);
  if (no->direita) altura_direita = altura(no->direita);

  return max(altura_esquerda, altura_direita) + 1;
}

int fator_balanceamento (No *no) {
  int fator = 0;

  if (no->esquerda) fator += altura(no->esquerda);
  if (no->direita) fator -= altura(no->direita);

  return fator;
}

No *rotacionar_esquerda_esquerda (No *no) {
  No *auxiliar = no;
  No *esquerda = auxiliar->esquerda;

  auxiliar->esquerda = esquerda->direita;
  esquerda->direita = auxiliar;

  return esquerda;
}

No *rotacionar_esquerda_direita (No *no) {
  No *auxiliar = no;
  No *esquerda = auxiliar->esquerda;
  No *direita = esquerda->direita;

  auxiliar->esquerda = direita->direita;
  esquerda->direita = direita->esquerda;
  direita->esquerda = esquerda;
  direita->direita = auxiliar;

  return direita;
}

No *rotacionar_direita_esquerda (No *no) {
  No *auxiliar = no;
  No *direita = auxiliar->direita;
  No *esquerda = direita->esquerda;

  auxiliar->direita = esquerda->esquerda;
  direita->esquerda = esquerda->direita;
  esquerda->direita = direita;
  esquerda->esquerda = auxiliar;

  return esquerda;
}

No *rotacionar_direita_direita (No *no) {
  No *auxiliar = no;
  No *direita = auxiliar->direita;

  auxiliar->direita = direita->esquerda;
  direita->esquerda = auxiliar;

  return direita;
}

No *balancear_no (No *no) {
  No *balanceado = NULL;

  if (no->esquerda) balancear_no(no->esquerda);
  if (no->direita) balancear_no(no->direita);

  int fator = fator_balanceamento(no);

  if (fator >= 2) {
    if (fator_balanceamento(no->esquerda) < 0) balanceado = rotacionar_esquerda_direita(no);
    else balanceado = rotacionar_esquerda_esquerda(no);
  }

  else if (fator <= -2) {
    if (fator_balanceamento(no->direita) > 0) balanceado = rotacionar_direita_esquerda(no);
    else balanceado = rotacionar_direita_direita(no);
  }

  else balanceado = no;

  return balanceado;
}

void balancear_arvore (Arvore *arvore) {
  No *raiz = balancear_no(arvore->raiz);

  if (arvore->raiz != raiz) {
    arvore->raiz = raiz;
  }
}

void inserir (Arvore *arvore, int valor) {
  if (arvore->raiz == NULL) arvore->raiz = criar_no(valor);

  else {
    No *anterior = NULL, *atual = arvore->raiz;

    while (atual != NULL) {
      anterior = atual;

      if (valor < atual->valor) atual = atual->esquerda;
      else if (valor == atual->valor) return;
      else atual = atual->direita;
    }

    No *no = criar_no(valor);

    if (valor < anterior->valor) anterior->esquerda = no;
    else anterior->direita = no;
  }

  balancear_arvore(arvore);
}

No *buscar (Arvore *arvore, int valor) {
  No *atual = arvore->raiz;

  while (atual && atual->valor != valor) {
    if (atual->valor < valor) atual = atual->direita;
    else atual = atual->esquerda;
  }

  return atual;
}

void imprimir (No *no) {
  if (no != NULL) {
    printf("Nó = %d, Altura = %d\n", no->valor, altura(no));
    imprimir(no->esquerda);
    imprimir(no->direita);
  }
}

void liberar_memoria (No *no) {
  if (no == NULL) return;

  liberar_memoria(no->esquerda);
  liberar_memoria(no->direita);

  free(no);
}
