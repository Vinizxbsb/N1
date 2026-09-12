#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpar_buffer(void) {
    int caractere;

    while ((caractere = getchar()) != '\n' && caractere != EOF) {
    }
}
    int opcao;
//Dados do cliente  
#define MAX_CLIENTES 50
    char nome_cliente[MAX_CLIENTES][50];
    char cpf_cliente[MAX_CLIENTES][12];
    float renda_cliente[MAX_CLIENTES];
    float renda_anual[MAX_CLIENTES];
    char status_cliente[MAX_CLIENTES][15];
    char cnh[MAX_CLIENTES];
//Dados do carro
    char marca_carro[MAX_CLIENTES][50];
    char modelo_carro[MAX_CLIENTES][50];
    float preco_venda[MAX_CLIENTES];
    int ano_carro[MAX_CLIENTES];
    int opcao_parcelas;
    float limite_venda[MAX_CLIENTES];

int main(){   
    int total_clientes = 0;
    int total_carros = 0;


    do{
        printf("\n ==== Menu ==== \n");
        printf("1- Cadastro de cliente \n");
        printf("2- Cadastro de carro \n");
        printf("3- Venda \n");
        printf("0- Sair \n");

        printf("Digite a opcao: \n");
        scanf(" %d", &opcao);
        limpar_buffer();

        switch (opcao){
            case 1:
                printf("Digite o nome do cliente: \n");
                fgets(nome_cliente[total_clientes], 49, stdin);
                printf("Digite o CPF do cliente: \n");
                scanf(" %11s", cpf_cliente[total_clientes]);
                limpar_buffer();
                printf("Digite a renda do cliente: \n");
                scanf(" %f", &renda_cliente[total_clientes]);
                printf("O cliente possui cnh? (S||N)\n");
                scanf(" %c", &cnh[total_clientes]);
                limpar_buffer();

                if( cnh[total_clientes] == 's' || cnh[total_clientes] == 'S'){
                    renda_anual[total_clientes] = renda_cliente[total_clientes] * 12;
                    limite_venda[total_clientes] = (renda_anual[total_clientes] * 0.3) / 12;
                    strcpy(status_cliente[total_clientes], "Cadastrado");

                    printf("\n==== Dados do cliente ==== \n");
                    printf("Nome: %s \n", nome_cliente[total_clientes]);
                    printf("CPF: %s \n", cpf_cliente[total_clientes]);
                    printf("Renda: %.2f \n", renda_cliente[total_clientes]);
                    printf("Renda anual: %.2f \n", renda_anual[total_clientes]);
                    printf("Possui CNH: %c \n", cnh[total_clientes]);
                    total_clientes++;
                    break;
                }
                else if(cnh[total_clientes] == 'n' || cnh[total_clientes] == 'N'){
                    printf("Não é possivel comprar um veículo sem CNH!");
                    break;
                }
                else{
                    printf("Valor inválido!");
                }
                break;
            case 2:
                printf("Digite a marca do carro: \n");
                scanf("%49s", marca_carro[total_carros]);
                printf("Digite o modelo do carro: \n");
                scanf("%49s", modelo_carro[total_carros]);
                printf("Digite o valor do carro: \n");
                scanf("%f", &preco_venda[total_carros]);
                printf("Digite o ano do carro: \n");
                scanf("%d", &ano_carro[total_carros]);
                total_carros++;
                printf("Carro cadastrado com sucesso! \n");
                strcpy(status_cliente[total_carros], "Cadastrado");

                break;
            case 3: {
                printf("Deseja efetuar a compra do veículo? (S/N) \n");
                char opcao_compra;
                scanf(" %c", &opcao_compra);
                
                if(opcao_compra == 's' || opcao_compra == 'S'){
                    printf("Deseja a compra deste veículo? \n");
                    printf("Marca: %s \n", marca_carro[total_carros - 1]);
                    printf("Modelo: %s \n", modelo_carro[total_carros - 1]);
                    printf("Valor: R$%.2f \n", preco_venda[total_carros - 1]);
                    
                    char opcao_confirmacao;
                    printf("Confirma a compra? (S/N) \n");
                    scanf(" %c", &opcao_confirmacao);
                    
                    if(opcao_confirmacao == 's' || opcao_confirmacao == 'S'){
                        printf("Deseja pagar em quantas vezes? (12/24/36/48) \n");
                        int opcao_parcelas;
                        scanf("%d", &opcao_parcelas);
                        
                        float valor_parcela = 0.0;
                        
                        switch (opcao_parcelas){
                            case 12:
                                valor_parcela = preco_venda[total_carros - 1] / 12;
                                break;
                            case 24:
                                valor_parcela = preco_venda[total_carros - 1] / 24;
                                break;
                            case 36:
                                valor_parcela = preco_venda[total_carros - 1] / 36;
                                break;
                            case 48:
                                valor_parcela = preco_venda[total_carros - 1] / 48;
                                break;
                            default:
                                printf("Opção inválida! \n");
                                valor_parcela = -1; // Sinaliza que a parcela deu erro
                                break;
                        }
                        if (valor_parcela != -1) {
                            if (valor_parcela > limite_venda[total_clientes - 1]){
                                printf("O valor da parcela excede o limite de 30%% da renda mensal do cliente! \n");
                            } else {
                                printf("O valor da parcela fica em: R$%.2f por mês\n", valor_parcela);
                                printf("Compra realizada com sucesso! \n");
                            }
                        }
                    }
                    else if(opcao_confirmacao == 'n' || opcao_confirmacao == 'N'){
                        printf("Compra cancelada! \n");
                    }
                }
                else if(opcao_compra == 'n' || opcao_compra == 'N'){
                    printf("Compra cancelada! \n");
                }
                break;
            }
        }
    }while (opcao != 0);
    return 0;
}