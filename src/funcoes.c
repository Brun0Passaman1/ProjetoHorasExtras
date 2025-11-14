#include <stdio.h>
#include <string.h>
#include "funcoes.h"

// Função auxiliar para limpar o buffer de entrada
static void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // descarta caracteres restantes
    }
}

// Exibe o menu principal
void exibirMenu() {
    printf("\n================= CONTROLE DE HORAS EXTRAS =================\n");
    printf("1 - Cadastrar funcionarios\n");
    printf("2 - Registrar horas extras\n");
    printf("3 - Aprovar registros (gestor)\n");
    printf("4 - Gerar relatorio\n");
    printf("0 - Sair\n");
    printf("============================================================\n");
}

// Cadastra um novo funcionario
void adicionarFuncionario(Funcionario lista[], int *qtd) {
    if (*qtd >= MAX_FUNC) {
        printf("\nLimite maximo de funcionarios (%d) atingido.\n", MAX_FUNC);
        return;
    }

    Funcionario novo;
    novo.id = *qtd + 1;
    novo.horasExtras = 0.0f;
    novo.totalPagar = 0.0f;
    novo.status = 0; // Pendente

    printf("\n--- Cadastro de Funcionarios ---\n");
    printf("Digite o nome do funcionario: ");
    limparBuffer();
    fgets(novo.nome, sizeof(novo.nome), stdin);

    // remove '\n' final, se existir
    size_t len = strlen(novo.nome);
    if (len > 0 && novo.nome[len - 1] == '\n') {
        novo.nome[len - 1] = '\0';
    }

    lista[*qtd] = novo;
    (*qtd)++;

    printf("Funcionario cadastrado com sucesso! ID = %d\n", novo.id);
}

// Registra horas extras para um funcionario (respeitando o limite diario)
void registrarHoras(Funcionario lista[], int qtd) {
    if (qtd == 0) {
        printf("\nNenhum funcionario cadastrado.\n");
        return;
    }

    int id;
    float horas;

    printf("\n--- Registro de Horas Extras ---\n");
    printf("Funcionarios cadastrados:\n");

    for (int i = 0; i < qtd; i++) {
        printf("ID: %d | Nome: %s | Horas atuais: %.1f | Status: %s\n",
               lista[i].id,
               lista[i].nome,
               lista[i].horasExtras,
               lista[i].status ? "Aprovada" : "Pendente");
    }

    printf("\nDigite o ID do funcionario para registrar horas: ");
    scanf("%d", &id);

    if (id < 1 || id > qtd) {
        printf("ID invalido.\n");
        return;
    }

    Funcionario *f = &lista[id - 1];

    printf("Informe a quantidade de horas extras (limite diario: %.1f h): ",
           LIMITE_DIARIO);
    scanf("%f", &horas);

    if (horas < 0.0f) {
        printf("Quantidade de horas nao pode ser negativa.\n");
        return;
    }

    // Simulacao do limite diario: total do dia nao pode ultrapassar 2h
    if (f->horasExtras + horas > LIMITE_DIARIO) {
        printf("Erro: limite diario de %.1f horas seria excedido.\n", LIMITE_DIARIO);
        printf("Horas ja registradas: %.1f\n", f->horasExtras);
        return;
    }

    f->horasExtras += horas;
    f->status = 0;       // volta para Pendente apos novo registro
    f->totalPagar = 0.0; // recalculado apenas apos aprovacao

    printf("Horas extras registradas com sucesso!\n");
    printf("Funcionario: %s | Horas acumuladas: %.1f\n", f->nome, f->horasExtras);
}

// Aprova os registros de horas de um funcionario (acao do gestor)
void aprovarHoras(Funcionario lista[], int qtd) {
    if (qtd == 0) {
        printf("\nNenhum funcionario cadastrado.\n");
        return;
    }

    int id;

    printf("\n--- Aprovacao de Registros de Horas Extras ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("ID: %d | Nome: %s | Horas: %.1f | Status: %s\n",
               lista[i].id,
               lista[i].nome,
               lista[i].horasExtras,
               lista[i].status ? "Aprovada" : "Pendente");
    }

    printf("\nDigite o ID do funcionario para aprovar as horas: ");
    scanf("%d", &id);

    if (id < 1 || id > qtd) {
        printf("ID invalido.\n");
        return;
    }

    Funcionario *f = &lista[id - 1];

    if (f->horasExtras <= 0.0f) {
        printf("Nao ha horas extras registradas para este funcionario.\n");
        return;
    }

    f->status = 1; // Aprovada
    calcularPagamento(f);

    printf("Registros de horas extras APROVADOS para %s.\n", f->nome);
    printf("Valor total a ser pago: R$ %.2f\n", f->totalPagar);
}

// Calcula o pagamento das horas extras (apenas se o status for Aprovada)
void calcularPagamento(Funcionario *f) {
    if (f->status == 1) { // Aprovada
        f->totalPagar = f->horasExtras * VALOR_HORA_EXTRA;
    } else {
        f->totalPagar = 0.0f;
    }
}

// Gera o relatorio com nome, ID, horas e valor total
void mostrarRelatorio(Funcionario lista[], int qtd) {
    if (qtd == 0) {
        printf("\nNenhum funcionario cadastrado.\n");
        return;
    }

    printf("\n---------------- RELATORIO DE HORAS EXTRAS ----------------\n");
    printf("ID | Nome                     | Horas |   Valor (R$) | Status\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < qtd; i++) {
        // garante consistencia do valor
        if (lista[i].status == 1) {
            calcularPagamento(&lista[i]);
        } else {
            lista[i].totalPagar = 0.0f;
        }

        printf("%-2d | %-24s | %5.1f | %11.2f | %s\n",
               lista[i].id,
               lista[i].nome,
               lista[i].horasExtras,
               lista[i].totalPagar,
               lista[i].status ? "Aprovada" : "Pendente");
    }

    printf("------------------------------------------------------------\n");
}
