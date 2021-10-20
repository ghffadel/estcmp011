# include <locale.h>
# include <stdio.h>
# include <stdlib.h>
# include "fila.h"

int menu () {
  int operacao;

  system("cls");
  printf("0 - Sair\n");
  printf("1 - Enfileirar\n");
  printf("2 - Desenfileirar\n");
  printf("3 - Imprimir\n");
  printf("Digite a operação: "); scanf("%d", &operacao);
  system("cls");

  return operacao;
}

int main () {
  int operacao, valor;
  No *inicio, *fim; inicio = fim = NULL;

  setlocale(LC_ALL, "Portuguese");

  do {
    operacao = menu();

    switch(operacao) {
      case 0:
        printf("Fim do programa!\n");
        break;

      case 1:
        printf("Digite o valor a ser enfileirado: "); scanf("%d", &valor);
        enfileirar_valor(&inicio, &fim, valor);
        break;

      case 2:
        desenfileirar(&inicio);
        break;

      case 3:
        imprimir(inicio);
        system("pause");
        break;

      default:
        printf("Operação invalida!\n");
        system("pause");
    }
  } while (operacao != 0);

  return 0;
}
