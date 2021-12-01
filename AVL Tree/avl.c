# include <locale.h>
# include <malloc.h>
# include <stdio.h>
# include <stdlib.h>
# include "avl.h"

int menu () {
  int operacao;

  system("cls");
  printf("0 - Sair\n");
  printf("1 - Inserir\n");
  printf("2 - Imprimir\n");
  printf("Digite a operação: "); scanf("%d", &operacao);
  system("cls");

  return operacao;
}

int main () {
  Arvore *arvore = criar_arvore();
  int operacao, valor;

  setlocale(LC_ALL, "Portuguese");

  do {
    operacao = menu();

    switch(operacao) {
      case 0:
        liberar_memoria(arvore->raiz);
        printf("Fim do programa!\n");
        break;

      case 1:
        printf("Digite o valor a ser inserido: "); scanf("%d", &valor);
        inserir(arvore, valor);
        break;

      case 2:
        imprimir(arvore->raiz);
        printf("\n");
        system("pause");
        break;

      default:
        printf("Operação invalida!\n");
        system("pause");
    }
  } while (operacao != 0);

  return 0;
}
