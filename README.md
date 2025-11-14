    Sistema Digital de Controle de Horas Extras

Projeto desenvolvido em Linguagem C para simular um sistema de controle e gerenciamento de horas extras de funcionários.
Este sistema foi criado como parte do Projeto Integrador – Base27, utilizando conceitos fundamentais de lógica de programação, modularização e estruturas de dados.

Trabalho acadêmico desenvolvido pelo grupo:
Bruno Passamani, Lucas Simões Teixeira Scardua e Vitor Esteves Palácio.

    Objetivo

O objetivo deste projeto é substituir o processo manual de controle de horas extras, permitindo:

-Registro automatizado das horas

-Aprovação das horas pelo gestor

-Cálculo do valor total a ser pago

-Geração de relatório organizado

-O sistema segue as regras descritas no documento do grupo:

-Valor fixo da hora extra: R$ 80,00

-Limite diário: 2 horas

-Somente horas aprovadas são computadas para pagamento


    Funcionalidades do Sistema

✔ Cadastrar funcionário
✔ Registrar horas extras (verificação do limite diário)
✔ Aprovar horas (alteração de status e cálculo do pagamento)
✔ Gerar relatório completo, exibindo:

-ID

-Nome

-Horas extras acumuladas

-Valor total a receber

-Status (Pendente/Aprovada)


    Estrutura do Projeto

ProjetoHorasExtras/
│
├─  docs/ → Arquivos da entrega
│ ├─  especificacao_do_projeto.pdf
│ └─  fluxograma.png
│
├─  src/ → Código-fonte
│ ├─  main.c (menu e fluxo principal)
│ ├─  funcoes.c (implementação das funcionalidades)
│ └─  funcoes.h (estruturas e protótipos)
│
│
├─  README.md → Documentação do projeto
│
└─  SistemaDeControle.exe → Executável da aplicação
