#include <stdio.h>

int main() {
    // Variaveis de controle
    int opcao;
    int total_clientes = 0;
    int total_carros = 0;
    int i, c; // Variaveis de controle para os lacos for

    // Vetores simples para armazenar ate 50 clientes
    char nome_cliente[50][50];
    char cpf_cliente[50][12];
    float renda_cliente[50];
    char data_nascimento[50][11];
    float renda_anual[50];
    int status_cliente[50]; // 1 = Cadastrado/Em Analise, 2 = Aprovado, 3 = Reprovado
    char cnh[50];
    float limite_venda[50];

    // Vetores simples para armazenar ate 50 carros
    char marca_carro[50][50];
    char modelo_carro[50][50];
    float preco_venda[50];
    int ano_carro[50];

    // Variaveis auxiliares para operacoes de venda
    int id_cliente_sel, id_carro_sel;
    char opcao_confirmacao;
    int opcao_parcelas;
    float valor_parcela;

    // Loop do menu principal (while/do-while)
    do {
        printf("\n==== Menu ====\n");
        printf("1- Cadastro de cliente\n");
        printf("2- Cadastro de carro\n");
        printf("3- Venda\n");
        printf("4- Listar clientes\n");
        printf("5- Listar carros\n");
        printf("0- Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        // Estrutura switch para tratar o menu
        switch (opcao) {
            case 1:
                if (total_clientes >= 50) {
                    printf("Limite de clientes atingido!\n");
                    break;
                }

                printf("\n--- Cadastro de Cliente ---\n");
                printf("Digite o primeiro nome do cliente: ");
                scanf("%s", nome_cliente[total_clientes]);

                printf("Digite o CPF do cliente: ");
                scanf("%s", cpf_cliente[total_clientes]);

                printf("Digite a renda mensal do cliente: ");
                scanf("%f", &renda_cliente[total_clientes]);

                printf("Digite a data de nascimento (dd/mm/aaaa): ");
                scanf("%s", data_nascimento[total_clientes]);

                printf("O cliente possui CNH? (S/N): ");
                scanf(" %c", &cnh[total_clientes]);

                // Estrutura if/else para regra de negocios da CNH
                if (cnh[total_clientes] == 's' || cnh[total_clientes] == 'S') {
                    renda_anual[total_clientes] = renda_cliente[total_clientes] * 12;
                    limite_venda[total_clientes] = renda_cliente[total_clientes] * 0.30; // 30% da renda mensal
                    status_cliente[total_clientes] = 1; // 1 = Em Analise / Cadastrado

                    printf("\n==== Dados do Cliente Cadastrado ====\n");
                    printf("Nome: %s\n", nome_cliente[total_clientes]);
                    printf("CPF: %s\n", cpf_cliente[total_clientes]);
                    printf("Renda Mensal: R$%.2f\n", renda_cliente[total_clientes]);
                    printf("Renda Anual: R$%.2f\n", renda_anual[total_clientes]);
                    printf("Data de Nascimento: %s\n", data_nascimento[total_clientes]);
                    printf("Possui CNH: %c\n", cnh[total_clientes]);
                    printf("Limite de Parcela (30%% da renda): R$%.2f\n", limite_venda[total_clientes]);

                    total_clientes++;
                } else if (cnh[total_clientes] == 'n' || cnh[total_clientes] == 'N') {
                    printf("\nNao e possivel cadastrar/comprar veiculo sem CNH!\n");
                } else {
                    printf("\nOpcao de CNH invalida!\n");
                }
                break;

            case 2:
                if (total_carros >= 50) {
                    printf("Limite de carros atingido!\n");
                    break;
                }

                printf("\n--- Cadastro de Carro ---\n");
                printf("Digite a marca do carro: ");
                scanf("%s", marca_carro[total_carros]);

                printf("Digite o modelo do carro: ");
                scanf("%s", modelo_carro[total_carros]);

                printf("Digite o valor do carro: ");
                scanf("%f", &preco_venda[total_carros]);

                printf("Digite o ano do carro: ");
                scanf("%d", &ano_carro[total_carros]);

                total_carros++;
                printf("\nCarro cadastrado com sucesso!\n");
                break;

            case 3:
                if (total_clientes == 0 || total_carros == 0) {
                    printf("\nE necessario ter pelo menos 1 cliente e 1 carro cadastrados para realizar a venda!\n");
                    break;
                }

                printf("\n--- Venda de Veiculo ---\n");

                // 1. SELECAO DO CLIENTE
                printf("\nSelecione o cliente comprador:\n");
                for (i = 0; i < total_clientes; i++) {
                    printf("  [%d] Nome: %s | CPF: %s | Limite de Parcela: R$%.2f\n", 
                           i + 1, nome_cliente[i], cpf_cliente[i], limite_venda[i]);
                }
                printf("Digite o numero do cliente (1 a %d): ", total_clientes);
                scanf("%d", &id_cliente_sel);

                // Valida se o ID escolhido existe
                if (id_cliente_sel < 1 || id_cliente_sel > total_clientes) {
                    printf("Cliente invalido!\n");
                    break;
                }
                id_cliente_sel--; // Ajusta para o indice do vetor (0 a total_clientes - 1)

                // 2. SELECAO DO CARRO
                printf("\nSelecione o carro a ser comprado:\n");
                for (c = 0; c < total_carros; c++) {
                    printf("  [%d] Marca: %s | Modelo: %s | Preco: R$%.2f\n", 
                           c + 1, marca_carro[c], modelo_carro[c], preco_venda[c]);
                }
                printf("Digite o numero do carro (1 a %d): ", total_carros);
                scanf("%d", &id_carro_sel);

                // Valida se o ID escolhido existe
                if (id_carro_sel < 1 || id_carro_sel > total_carros) {
                    printf("Carro invalido!\n");
                    break;
                }
                id_carro_sel--; // Ajusta para o indice do vetor (0 a total_carros - 1)

                // 3. CONFIRMACAO E PARCELAMENTO
                printf("\nResumo do Pedido:\n");
                printf("Cliente: %s\n", nome_cliente[id_cliente_sel]);
                printf("Veiculo: %s %s (R$%.2f)\n", marca_carro[id_carro_sel], modelo_carro[id_carro_sel], preco_venda[id_carro_sel]);

                printf("Confirma a selecao? (S/N): ");
                scanf(" %c", &opcao_confirmacao);

                if (opcao_confirmacao == 's' || opcao_confirmacao == 'S') {
                    printf("Deseja pagar em quantas vezes? (12 / 24 / 36 / 48): ");
                    scanf("%d", &opcao_parcelas);

                    valor_parcela = 0.0;

                    // Switch para calcular as parcelas
                    switch (opcao_parcelas) {
                        case 12:
                            valor_parcela = preco_venda[id_carro_sel] / 12;
                            break;
                        case 24:
                            valor_parcela = preco_venda[id_carro_sel] / 24;
                            break;
                        case 36:
                            valor_parcela = preco_venda[id_carro_sel] / 36;
                            break;
                        case 48:
                            valor_parcela = preco_venda[id_carro_sel] / 48;
                            break;
                        default:
                            printf("Opcao de parcelamento invalida!\n");
                            valor_parcela = -1;
                            break;
                    }

                    // Avaliacao de aprovacao com base no limite do cliente selecionado
                    if (valor_parcela != -1) {
                        if (valor_parcela > limite_venda[id_cliente_sel]) {
                            printf("\nREPROVADO: O valor da parcela (R$%.2f) excede o limite de 30%% da renda do cliente %s (R$%.2f)!\n", 
                                   valor_parcela, nome_cliente[id_cliente_sel], limite_venda[id_cliente_sel]);
                            status_cliente[id_cliente_sel] = 3; // 3 = Reprovado
                        } else {
                            printf("\nAPROVADO: Valor da parcela fica em R$%.2f por mes.\n", valor_parcela);
                            printf("Compra realizada com sucesso para %s!\n", nome_cliente[id_cliente_sel]);
                            status_cliente[id_cliente_sel] = 2; // 2 = Aprovado
                        }
                    }
                } else {
                    printf("Compra cancelada na confirmacao.\n");
                }
                break;

            case 4:
                printf("\n==== Relatorio Final - Lista de Clientes ====\n");
                if (total_clientes == 0) {
                    printf("Nenhum cliente cadastrado!\n");
                } else {
                    // Laco for para percorrer os clientes
                    for (i = 0; i < total_clientes; i++) {
                        printf("Cliente %d:\n", i + 1);
                        printf("  Nome: %s\n", nome_cliente[i]);
                        printf("  CPF: %s\n", cpf_cliente[i]);
                        printf("  Renda Mensal: R$%.2f\n", renda_cliente[i]);
                        printf("  Renda Anual: R$%.2f\n", renda_anual[i]);
                        printf("  Possui CNH: %c\n", cnh[i]);

                        // Exibicao simplificada do status sem usar strcmp ou strcpy
                        printf("  Status da Compra: ");
                        switch (status_cliente[i]) {
                            case 1:
                                printf("Em Analise / Cadastrado\n");
                                break;
                            case 2:
                                printf("Aprovado\n");
                                break;
                            case 3:
                                printf("Reprovado\n");
                                break;
                            default:
                                printf("Indefinido\n");
                                break;
                        }
                        printf("-----------------------------------\n");
                    }
                }
                break;

            case 5:
                printf("\n==== Relatorio Final - Lista de Carros ====\n");
                if (total_carros == 0) {
                    printf("Nenhum carro cadastrado!\n");
                } else {
                    // Laco for para percorrer os carros
                    for (c = 0; c < total_carros; c++) {
                        printf("Carro %d:\n", c + 1);
                        printf("  Marca: %s\n", marca_carro[c]);
                        printf("  Modelo: %s\n", modelo_carro[c]);
                        printf("  Preco: R$%.2f\n", preco_venda[c]);
                        printf("  Ano: %d\n", ano_carro[c]);
                        printf("-----------------------------------\n");
                    }
                }
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}