#ifndef FUNCOES_H
#define FUNCOES_H

#define MAX_FUNC 100            // Máximo de funcionários
#define VALOR_HORA_EXTRA 80.0f  // Valor fixo da hora extra (R$ 80,00)
#define LIMITE_DIARIO 2.0f      // Limite diário de horas extras (simulação)

// Estrutura que representa um funcionário no sistema
typedef struct {
    int id;                 // ID do funcionário
    char nome[50];          // Nome do funcionário
    float horasExtras;      // Horas extras acumuladas (simulando o dia)
    float totalPagar;       // Valor total a ser pago (apenas se aprovado)
    int status;             // 0 = Pendente, 1 = Aprovada
} Funcionario;

// Protótipos
void exibirMenu();
void adicionarFuncionario(Funcionario lista[], int *qtd);
void registrarHoras(Funcionario lista[], int qtd);
void aprovarHoras(Funcionario lista[], int qtd);
void mostrarRelatorio(Funcionario lista[], int qtd);
void calcularPagamento(Funcionario *f);

#endif
