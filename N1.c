#include <stdio.h>
#include <string.h>

//Construção de struct para a aguentar mais cliente e carros sem apagar o anterior da memória. //
typedef struct Cliente
{
    char nome_cliente[50];
    char cpf[12];
    float renda_cliente;
    char status[15];
}Cliente;

typedef struct Carro
{
    char modelo[50];
    char marca[50];
    int ano_carro;
    float valor_carro;
    float juros;
}Carro;

void limpar_buffer(void) {
    int caractere;

    while ((caractere = getchar()) != '\n' && caractere != EOF) {
    }
}

int main(){
    int opcao;
    Cliente clientes[50];
    Carro carros[50];
    int total_clientes = 0; 
    int total_carros = 0;
    float renda_anual;
    char cnh;


    do{
        printf("\n ==== Menu ==== \n");
        printf("1. Cadastro de clientes. \n");
        printf("2. Cadastro de Carros. \n");
        printf("3. Venda \n");
        printf("0. Sair \n");

        printf("Digite a opção: \n");
        scanf("%d", &opcao);
        limpar_buffer();

        switch(opcao){
            case 1:
                printf("Digite o nome do cliente: \n");
                fgets(clientes[total_clientes].nome_cliente, sizeof(clientes[total_clientes].nome_cliente), stdin);
                printf("Digite o cpf do cliente: \n");
                scanf("%11s", clientes[total_clientes].cpf);
                printf("Digite a renda do cliente: \n");
                scanf("%f", &clientes[total_clientes].renda_cliente);
                limpar_buffer();
                printf("O cliente possui cnh? (S/N) \n");
                scanf("%c", &cnh);

                renda_anual = clientes[total_clientes].renda_cliente * 12;


                if (cnh == 'N' || cnh == 'n'){
                    printf("Não é possivel efetuar uma compra sem CNH! \n");
                }
                else{
                    printf("\nCliente cadastrado! \n");
                    total_clientes++;
                    printf("Nome do cliente: %s\n", clientes[total_clientes].nome_cliente);
                    printf("CPF: %s\n", clientes[total_clientes].cpf);
                    printf("Renda mensal: %.2f\n", clientes[total_clientes].renda_cliente);
                    printf("Renda anual: %.2f\n", renda_anual);
                }
            break;
            case 2:
                printf("Digite o modelo do carro: \n");
                fgets(carros[total_carros].modelo, sizeof(carros[total_carros].modelo), stdin);
                printf("Digite a marca do carro: \n");
                fgets(carros[total_carros].marca, sizeof(carros[total_carros].marca), stdin);
                printf("Digite o ano do carro: \n");
                scanf("%d", &carros[total_carros].ano_carro);
                printf("Digite o valor do carro: \n");
                scanf("%f", &carros[total_carros].valor_carro);
                printf("Digite a taxa de juros do carro: \n");
                scanf("%f", &carros[total_carros].juros);

                if( strlen(carros[total_carros].modelo) > 0 && strlen(carros[total_carros].marca) > 0 && carros[total_carros].valor_carro > 0 && carros[total_carros].ano_carro && carros[total_carros].juros){
                    printf("Faltam informações, por este motivo não foi possivel efetuar o cadastro!.");
                }
                else{
                    printf("Carro cadastrado!\n");
                    total_carros++;
                    printf("==== Dados do carro ====\n");
                    printf("Modelo do carro: %s\n", carros[total_carros].modelo);
                    printf("Marca do carro: %s\n", carros[total_carros].marca);
                    printf("Ano do carro: %d\n", carros[total_carros].ano_carro);
                    printf("Valor do carro: %f\n", carros[total_carros].valor_carro);
                    printf("Taxa de juros do carro: %f\n", carros[total_carros].juros);
                }
            break;
        



        }

    } while(opcao != 0);
}