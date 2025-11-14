#include <stdio.h>
#include "funcoes.h"

int main() {
    Funcionario funcionarios[MAX_FUNC];
    int quantidade = 0;
    int opcao;

    do {
        exibirMenu();

        printf("Selecione uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarFuncionario(funcionarios, &quantidade);
                break;
            case 2:
                registrarHoras(funcionarios, quantidade);
                break;
            case 3:
                aprovarHoras(funcionarios, quantidade);
                break;
            case 4:
                mostrarRelatorio(funcionarios, quantidade);
                break;
            case 0:
                printf("\nEncerrando o sistema. Ate mais!\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
