# include <locale.h>
# include <stdio.h>
# include <stdlib.h>
# include "pilha.h"

int menu () {
  int operacao;

  system("cls");
  printf("0 - Sair\n");
  printf("1 - Empilhar\n");
  printf("2 - Desempilhar\n");
  printf("3 - Imprimir\n");
  printf("Digite a operação: "); scanf("%d", &operacao);
  system("cls");

  return operacao;
}

int main () {
  int operacao, valor;
  No * pilha = NULL;

  setlocale(LC_ALL, "Portuguese");

  do {
    operacao = menu();

    switch(operacao) {
      case 0:
        printf("Fim do programa!\n");
        break;

      case 1:
        printf("Digite o valor a ser empilhado: "); scanf("%d", &valor);
        empilhar_no(&pilha, criar_no(valor));
        break;

      case 2:
        desempilhar_no(&pilha);
        system("pause");
        break;

      case 3:
        imprimir(pilha);
        system("pause");
        break;

      default:
        printf("Operação invalida!\n");
        system("pause");
    }
  } while (operacao != 0);

  return 0;
}
