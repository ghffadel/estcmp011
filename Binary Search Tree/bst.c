# include <locale.h>
# include <malloc.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include "bst.h"

int menu () {
  int operacao;

  system("cls");
  printf("0 - Sair\n");
  printf("1 - Inserir\n");
  printf("2 - Imprimir pré ordem\n");
  printf("3 - Imprimir em ordem\n");
  printf("4 - Imprimir pós ordem\n");
  printf("5 - Buscar\n");
  printf("6 - Excluir\n");
  printf("7 - Destruir árvore\n");
  printf("Digite a operação: "); scanf("%d", &operacao);
  system("cls");

  return operacao;
}

int main () {
  int operacao, valor;
  No *arvore = NULL;

  setlocale(LC_ALL, "Portuguese");

  do {
    operacao = menu();

    switch(operacao) {
      case 0:
        printf("Fim do programa!\n");
        break;

      case 1:
        printf("Digite o valor a ser inserido: "); scanf("%d", &valor);
        inserir(&arvore, valor);
        break;

      case 2:
        imprimir_pre_ordem(arvore);
        printf("\n");
        system("pause");
        break;

      case 3:
        imprimir_em_ordem(arvore);
        printf("\n");
        system("pause");
        break;

      case 4:
        imprimir_pos_ordem(arvore);
        printf("\n");
        system("pause");
        break;

      case 5:
        printf("Digite o valor a ser buscado: "); scanf("%d", &valor);
        if (buscar(arvore, valor)) printf("Elemento encontrado!\n");
        else printf("Elemento não encontrado!\n");
        system("pause");
        break;

      case 6:
        printf("Digite o valor a ser excluído: "); scanf("%d", &valor);
        excluir(&arvore, valor);
        break;

      case 7:
        destruir(&arvore);
        break;

      default:
        printf("Operação invalida!\n");
        system("pause");
    }
  } while (operacao != 0);

  return 0;
}
