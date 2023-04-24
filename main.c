#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

typedef struct {
    char nome_produto[50];
    float preco;
	int status; // para mostrar no carrinho 
	int quant;
} Produto;

float localidades(int cidade) {
    float frete;
    if (cidade == 1) {
        frete = 25;
    } else if (cidade == 2) {
        frete = 30;
    } else if (cidade == 3) {
        frete = 20;
    } else {
        frete = 40;
    }
    return frete;
}

void registrar_produto(Produto produtos[], int *num_produtos) {
	
	
	
    if (*num_produtos >= 10) {
        printf("\nNão é possível registrar mais produtos.\n");
        return;
    }
	
	
    printf("\nDigite o nome do produto: ");
    limparBuffer();
    fgets(produtos[*num_produtos].nome_produto, 50, stdin);
    printf("\nDigite o preço do produto: ");
    scanf("%f", &produtos[*num_produtos].preco);
    (*num_produtos)++;
    printf("\nProduto registrado com sucesso.\n");
}

int ler_inteiro_valido(int min, int max) {
    int opcao;
    while (1) {
        printf("Escolha uma opção (%d-%d): ", min, max);
        if (scanf("%d", &opcao) == 1 && opcao >= min && opcao <= max) {
            return opcao;
        }
        printf("Opção inválida. Por favor, tente novamente.\n");
        limparBuffer();
    }
}

int main() {
    Produto produtos[10];
    int num_produtos = 0;
    float compra = 0;
	int tamanho_carrinho = 0; // Essa função apenas existe para caso n tiver nada no carrinho, printar "Você não tem nada no carrinho"
	
    printf("Bem-vindo(a) à nossa loja!\n\n");

    while (1) {
        printf("1. Comprar produto\n");
        printf("2. Registrar novo produto\n");
		printf("3. Ver carrinho\n");
        printf("4. Sair\n");
        int opcao = ler_inteiro_valido(1, 4);
        if (opcao == 1) {
			if (num_produtos == 0){
				puts("\nNenhum produto cadastrado, por favor, aguarde ou registre um produto para nossa loja. \n");
			}
			else{
            printf("Escolha um produto:\n");
            for (int j = 0; j < num_produtos; j++) {
                printf("%i. %s // R$%.2f\n \n", j + 1, produtos[j].nome_produto, produtos[j].preco);
            }
            int desejo;
            printf("Qual produto deseja comprar? ");
            desejo = ler_inteiro_valido(1, num_produtos);
			int quantidade; // Quantidade do produto a ser comprado
			printf("Quantos? ");
			scanf("%i", &quantidade);
			produtos[desejo - 1].quant = quantidade;
			compra += produtos[desejo -1].preco * quantidade; 
			tamanho_carrinho++;
			produtos[desejo - 1].status = 1; // se o status for 1, significa que o produto está comprado.
			printf("Deseja comprar outro produto? \n");
			int mais_produto;
			printf("1. Sim \n");
			printf("2. Não \n");
			
			mais_produto = ler_inteiro_valido(1, 2);
                while (mais_produto == 1) {
                    printf("Escolha outro produto:\n");
                    for (int q = 0; q < num_produtos; q++) {
                        printf("%i. %s // R$%.2f\n \n", q + 1, produtos[q].nome_produto, produtos[q].preco);
            }

			printf("Qual produto deseja comprar? ");
			desejo = ler_inteiro_valido(1, num_produtos);
        	printf("Quantos? ");
			scanf("%i", &quantidade);
			
            compra += produtos[desejo -1].preco * quantidade; 
			printf("Deseja comprar outro produto? \n");
			

			
					
			printf("\n1. Sim \n");
			printf("2. Não \n");
			mais_produto = ler_inteiro_valido(1, 2);
					
				}

			
			printf("Total da compra: %.2f \n\n", compra);

				
          /*   int cidade;
            printf("Onde você mora?\n");
            printf("1. Rio de Janeiro\n");
            printf("2. Minas Gerais\n");
            printf("3. São Paulo\n");
            printf("4. Outra cidade\n");
            cidade = ler_inteiro_valido(1, 4);
            compra += produtos[desejo - 1].preco;
            compra += localidades(cidade);
            printf("O valor total da sua compra é R$%.2f.\n\n", compra);
             */
			}
			
        } else if (opcao == 2) {
			int quant_cad = 0;
			printf("Quantos produtos você gostaria de cadastrar? \n");
			scanf("%i", &quant_cad);

			for (int w = 0; w< quant_cad; w++) {
            registrar_produto(produtos, &num_produtos);
				}
        }



			
		else if (opcao == 3){

		if (tamanho_carrinho == 0){
			printf("Nenhum produto no carrinho... Voltando para o menu principal.");
		}
			
		else {
    for (int a = 0; a < num_produtos; a++){
        if (produtos[a].status == 1) {
            printf("%i. %s // R$%.2f x %i\n ", a + 1, produtos[a].nome_produto, produtos[a].preco, produtos[a].quant);
        }
    }
	


	int checkout_choice = 0;

	
	printf("O que gostaria de fazer?"); 
	printf("1. Checkout\n ");
	printf("2. Remover um produto\n");

			
	checkout_choice = ler_inteiro_valido(1, 2);


	if (checkout_choice == 1){
	printf("Agora vamos calcular seu frete! :) \n\n ");
		int cidade;
		printf("Onde você mora?\n");
            printf("1. Rio de Janeiro\n");
            printf("2. Minas Gerais\n");
            printf("3. São Paulo\n");
            printf("4. Outra cidade\n");
            cidade = ler_inteiro_valido(1, 4);
           
            compra += localidades(cidade);
            printf("O valor total da sua compra é R$%.2f.\n\n", compra);



			printf("\n\n Muito obrigado, volte sempre :) \n\n");
			break;
	


	}
			
    printf("Digite o número do produto que deseja remover: ");
    int produto_remover;
    scanf("%d", &produto_remover);

    if (produto_remover <= num_produtos && produtos[produto_remover - 1].status == 1) {
        produtos[produto_remover - 1].status = 0;
        printf("Produto removido com sucesso!\n");
    } else {
        printf("Produto inválido ou já removido.\n");
    }
		}
}

			
		else if (opcao == 4) {
            printf("Obrigado pela visita! Volte sempre.\n");
            break;
        } else {
            printf("Opção inválida.\n  ");
        }
    }

    return 0;
}
