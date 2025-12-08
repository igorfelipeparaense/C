#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct{
    int code;
    char name[30];
    float price;
}Product;

typedef struct{
    Product product;
    int qtd;
}Cart;

void infoProduct(Product prod);
void menu();
void registerProduct();
void listProducts();
void buyProduct();
void viewCart();
Product getProductPerCode(int code);
int * isCart(int code);
void closeOrder();

static int count_product = 0;
static int count_cart = 0;
static Cart cart[50];
static Product products[50];

int main(){
    menu();

    return 0;
}

void infoProduct(Product prod){
    printf("Código: %d \nNome: %s \nPreço: %.2f \n", prod.code, strtok(prod.name, "\n"), prod.price);
}

void menu(){
	printf("==================================\n");
	printf("========== Bem-vindo(a) ==========\n");
	printf("=============  Shop  =============\n");
	printf("==================================\n");

	printf("Selecione uma das opções abaixo: \n");
	fflush(stdout);
	printf("1 - Cadastrar produto\n");
	fflush(stdout);
	printf("2 - Listar produtos\n");
	fflush(stdout);
	printf("3 - Comprar produto\n");
	fflush(stdout);
	printf("4 - Visualizar carrinho\n");
	fflush(stdout);
	printf("5 - Fechar pedido\n");
	fflush(stdout);
	printf("6 - Sair do sistema\n");
	fflush(stdout);

	int option;
	scanf("%d", &option);
	getchar();

	switch(option){
	case 1:
		registerProduct();
		break;
	case 2:
		listProducts();
		break;
	case 3:
		buyProduct();
		break;
	case 4:
		viewCart();
		break;
	case 5:
		closeOrder();
	case 6:
		printf("Volte sempre!\n");
		fflush(stdout);
		sleep(2);
		exit(0);
	default:
		printf("Opção inválida!\n\n");
		fflush(stdout);
		sleep(2);
		menu();
		break;
	}
}

void registerProduct(){
	printf("\nCadastro de produto\n");
	fflush(stdout);
	printf("====================\n");
	fflush(stdout);

	printf("Informe o nome do produto: \n");
	fflush(stdout);
	fgets(products[count_product].name, 30, stdin);

	printf("Informe o preço do produto: \n");
	fflush(stdout);
	scanf("%f", &products[count_product].price);

	printf("O produto %s foi cadastrado com sucesso.\n\n", strtok(products[count_product].name, "\n"));
	fflush(stdout);

	products[count_product].code = (count_product + 1);
	count_product++;

	sleep(2);
	menu();
}

void listProducts(){
	if(count_product > 0){
		printf("\nListagem de produtos\n");
		fflush(stdout);
		printf("---------------------\n");
		fflush(stdout);
		for(int i = 0; i < count_product; i++){
			infoProduct(products[i]);
			printf("---------------------\n");
			printf("\n");
			fflush(stdout);
			sleep(1);
		}
		sleep(2);
		menu();
	}else{
		printf("Não temos produtos cadastrados ainda.\n\n");
		fflush(stdout);
		sleep(2);
		menu();
	}
}

void buyProduct(){
	if(count_product > 0){
		printf("\nInforme o código do produto que deseja adicionar ao carrinho: \n");
		fflush(stdout);
		printf("====== Produtos Disponíveis ======\n");
		fflush(stdout);
		for(int i = 0; i < count_product; i++){
			infoProduct(products[i]);
			printf("---------------------\n");
			fflush(stdout);
			sleep(1);
		}
		int code;
		scanf("%d", &code);
		getchar();

		int is_market = 0;
		for(int i = 0; i < count_product; i++){
			if(products[i].code == code){
				is_market = 1;

				if(count_cart > 0){
					int * retorno = isCart(code);

					if(retorno[0] == 1){
						cart[retorno[1]].qtd++;
						printf("Aumentei a quantidade do produto %s já existente no carrinho.\n\n", strtok(cart[retorno[1]].product.name, "\n"));
						fflush(stdout);
						sleep(2);
						menu();
					}else{
						Product p = getProductPerCode(code);
						cart[count_cart].product = p;
						cart[count_cart].qtd = 1;
						count_cart++;
						printf("O produto %s foi adicionado ao carrinho.\n", strtok(p.name, "\n"));
						fflush(stdout);
						sleep(2);
						menu();
					}
				}else{
					Product p = getProductPerCode(code);
					cart[count_cart].product = p;
					cart[count_cart].qtd = 1;
					count_cart++;
					printf("\nO produto %s foi adicionado ao carrinho.\n\n", strtok(p.name, "\n"));
					fflush(stdout);
					sleep(2);
					menu();
				}
			}
		}
		if(is_market < 1){
			printf("Não foi encontrado o produto com código %d\n\n", code);
			fflush(stdout);
			sleep(2);
			menu();
		}
	}else{
		printf("Ainda não existem produtos para vender.\n\n");
		fflush(stdout);
		sleep(2);
		menu();
	}
}

void viewCart(){
	if(count_cart > 0){
		printf("\nProdutos do carrinho\n");
		fflush(stdout);
		printf("---------------------\n");
		fflush(stdout);
		for(int i = 0; i < count_cart; i++){
			infoProduct(cart[i].product);
			printf("Quantidade: %d\n", cart[i].qtd);
			fflush(stdout);
			printf("---------------------\n");
			printf("\n");
			fflush(stdout);
			sleep(1);
		}
		sleep(2);
		menu();
	}else{
        printf("Não temos produtos no carrinho ainda.\n\n");
        fflush(stdout);
        sleep(2);
        menu();
	}
}

Product getProductPerCode(int code){
    Product p;
	for(int i = 0; i < count_product; i++){
        if(products[i].code == code){
            p = products[i];
		}
	}
	return p;
}

int * isCart(int code){
    int static retorno[] = {0, 0};
	for(int i = 0; i < count_cart; i++){
        if(cart[i].product.code == code){
            retorno[0] = 1; //tem o produto com este código no carrinho
			retorno[1] = i; //o índice do produto no carrinho
		}
	}
	return retorno;
}

void closeOrder(){
	if(count_cart > 0){
		float valueTotal = 0.0;
		printf("\nProdutos do carrinho\n");
		fflush(stdout);
		printf("---------------------\n");
		fflush(stdout);
		for(int i = 0; i < count_cart; i++){
			Product p = cart[i].product;
			int qtd = cart[i].qtd;
			valueTotal += p.price * qtd;
			infoProduct(p);
			printf("Quantidade : %d\n", qtd);
			fflush(stdout);
			printf("---------------------\n");
			fflush(stdout);
			sleep(1);
		}
		printf("Sua fatura é: %.2f\n", valueTotal);
		fflush(stdout);

		//limpar carrinho
		count_cart = 0;
		printf("Obrigado pela preferência.\n\n");
		fflush(stdout);
		sleep(5);
		menu();
	}else{
		printf("Você não tem nenhum produto no carrinho ainda.\n\n");
		fflush(stdout);
		sleep(2);
		menu();
	}
}