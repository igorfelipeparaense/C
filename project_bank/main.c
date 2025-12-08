#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct {
	int code;
	char name[50];
	char email[50];
	char cpf[50];
	char dataBirth[20];
	char dataRegister[20];
}Client;

typedef struct {
	int number;
	Client client;
	float balance;
	float limit;
	float balanceTotal; //saldo + limite
}Account;

void menu();
void infoClient(Client client);
void infoAccount(Account account);
void createAccount();
void makeWithdraw();
void makeDeposit();
void makeTransfer();
void listAccounts();
float updateBalanceTotal(Account account);
Account searchAccountPerNumber(int number);
void withdraw(Account account, float value);
void deposit(Account account, float value);
void transfer(Account origin_account, Account target_account, float value);

static Account accounts[50];
static int count_accounts = 0;
static int count_clients = 0;

int main(){
    menu();

    return 0;
}

void menu(){
	int option = 0;
	printf("=================================\n");
	printf("============== ATM ==============\n");
	printf("============== Bank =============\n");
	printf("=================================\n");

	printf("Selecione uma opção no menu: \n");
	fflush(stdout);
	printf("1 - Criar conta\n");
	fflush(stdout);
	printf("2 - Efetuar saque\n");
	fflush(stdout);
	printf("3 - Efetuar depósito\n");
	fflush(stdout);
	printf("4 - Efetuar transferência\n");
	fflush(stdout);
	printf("5 - Listar contas\n");
	fflush(stdout);
	printf("6 - Sair do sistema\n");
	fflush(stdout);

	scanf("%d", &option);
	getchar();

	switch(option){
	case 1:
		createAccount();
		break;
	case 2:
		makeWithdraw();
		break;
	case 3:
		makeDeposit();
		break;
	case 4:
		makeTransfer();
		break;
	case 5:
		listAccounts();
		break;
	case 6:
		printf("Até a próxima!\n");
		sleep(2);
		exit(0);
	default:
		printf("Opção inválida!\n\n");
		sleep(2);
		menu();
		break;
	}
}

void infoClient(Client client){
	printf("Código: %d \nNome: %s \nData de Nascimento: %s \nCadastro: %s",
        client.code, strtok(client.name, "\n"), strtok(client.dataBirth, "\n"),
        strtok(client.dataRegister, "\n"));
}

void infoAccount(Account account){
	printf("Número da conta: %d \nCliente: %s \nData de Nascimento: %s \nData de Cadastro: %s \nSaldo Total: %.2f\n\n",
        account.number, strtok(account.client.name, "\n"), strtok(account.client.dataBirth, "\n"),
        strtok(account.client.dataRegister, "\n"), account.balanceTotal);
}

void createAccount(){
	Client client;

	//Data de cadastro
	char day[3];
	char month[3];
	char year[5];
	char data_register[20];
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	//dia
	if(tm.tm_mday < 10){
		sprintf(day, "0%d", tm.tm_mday);
	}else{
		sprintf(day, "%d", tm.tm_mday);
	}

	//mês
	if((tm.tm_mon + 1) < 10){
		sprintf(month, "0%d", tm.tm_mon + 1);
	}else{
		sprintf(month, "%d", tm.tm_mon + 1);
	}

	//ano
	sprintf(year, "%d", tm.tm_year + 1900);

	strcpy(data_register, "");
	strcat(data_register, day);
	strcat(data_register, "/");
	strcat(data_register, month);
	strcat(data_register, "/");
	strcat(data_register, year);
	strcat(data_register, "\0");
	strcpy(client.dataRegister, data_register);

	//Criar o cliente
	printf("=================================\n");
	printf("Informe os dados do cliente: \n");
	printf("=================================\n");
	fflush(stdout);
	client.code = count_clients + 1;

	printf("Nome do cliente: \n");
	fflush(stdout);
	fgets(client.name, 50, stdin);

	printf("E-mail do cliente: \n");
	fflush(stdout);
	fgets(client.email, 50, stdin);

	printf("CPF do cliente: \n");
	fflush(stdout);
	fgets(client.cpf, 20, stdin);

	printf("Data de nascimento do cliente: \n");
	fflush(stdout);
	fgets(client.dataBirth, 20, stdin);

	count_clients++;

	//Criar a conta
	accounts[count_accounts].number = count_accounts + 1;
	accounts[count_accounts].client = client;
	accounts[count_accounts].balance = 0.0;
	accounts[count_accounts].limit = 0.0;
	accounts[count_accounts].balanceTotal = updateBalanceTotal(accounts[count_accounts]);

	printf("\nConta criada com sucesso!\n\n");
	printf("=================================\n");
	printf("Dados da conta criada: \n");
	printf("=================================\n");
	infoAccount(accounts[count_accounts]);
	count_accounts++;

	sleep(4);
	menu();
}

void makeWithdraw(){
    if(count_accounts > 0){
		int number;
		printf("Informe o número da conta: \n");
		fflush(stdout);
		scanf("%d", &number);

		Account account = searchAccountPerNumber(number);

		if(account.number == number){
			float value;
			printf("Informe o valor do saque: \n");
			fflush(stdout);
			scanf("%f", &value);

			withdraw(account, value);
		}else{
			printf("Não foi encontrada uma conta com o número %d.\n\n", number);
		}

	}else{
		printf("Ainda não existem contas para saque.\n\n");
	}
	sleep(2);
	menu();
}

void makeDeposit(){
    if(count_accounts > 0){
        int number;
        printf("Informe o número da conta: \n");
        fflush(stdout);
        scanf("%d", &number);

        Account account = searchAccountPerNumber(number);

        if(account.number == number){
            float value;
            printf("Informe o valor do depósito: \n");
            fflush(stdout);
            scanf("%f", &value);

            deposit(account, value);
        }else{
            printf("Não foi encontrada uma conta com o número %d.\n\n", number);
        }

    }else{
        printf("Ainda não existem contas para depósito.\n\n");
    }
    sleep(2);
    menu();
}

void makeTransfer(){
    if(count_accounts > 0){
		int number_o, number_d;
		printf("Informe o número da sua conta: \n");
		fflush(stdout);
		scanf("%d", &number_o);

		Account account_o = searchAccountPerNumber(number_o);

		if(account_o.number == number_o){
			printf("Informe o número da conta destino: \n");
			fflush(stdout);
			scanf("%d", &number_d);

			Account account_d = searchAccountPerNumber(number_d);

			if(account_d.number == number_d){
				float value;
				printf("Informe o valor para transferência: \n");
				fflush(stdout);
				scanf("%f", &value);

				transfer(account_o, account_d, value);
			}else{
				printf("A conta destino com número %d não foi encontrada.\n\n", number_d);
			}
		}else{
			printf("A conta com número %d não foi encontrada.\n\n", number_o);
		}
	}else{
		printf("Ainda não existem contas para transferência.\n\n");
	}
	sleep(2);
	menu();
}

void listAccounts(){
    if(count_accounts > 0){
		for(int i = 0; i < count_accounts; i++){
			infoAccount(accounts[i]);
			sleep(1);
		}
	}else{
		printf("Não existem contas cadastradas ainda.\n\n");
	}
	sleep(2);
	menu();
}

float updateBalanceTotal(Account account){
    return account.balance + account.limit;
}

Account searchAccountPerNumber(int number){
    Account c;
	if(count_accounts > 0){
		for(int i = 0; i < count_accounts; i++){
			if(accounts[i].number == number){
				c = accounts[i];
			}
		}
	}
	return c;
}

void withdraw(Account account, float value){
    if(value > 0 && account.balanceTotal >= value){
		for(int i = 0; i < count_accounts; i++){
			if(accounts[i].number == account.number){
				if(accounts[i].balance >= value){
					accounts[i].balance = accounts[i].balance - value;
					accounts[i].balanceTotal = updateBalanceTotal(accounts[i]);
					printf("Saque efetuado com sucesso.\n\n");
				}else{
					float rest = accounts[i].balance - value;
					accounts[i].limit = accounts[i].limit + rest;
					accounts[i].balance = 0.0;
					accounts[i].balanceTotal = updateBalanceTotal(accounts[i]);
					printf("Saque efetuado com sucesso.\n\n");
				}
			}
		}
	}else{
		printf("Saque não realizado. Tente novamente.\n\n");
	}
}

void deposit(Account account, float value){
    if(value > 0){
		for(int i = 0; i < count_accounts; i++){
			if(accounts[i].number == account.number){
				accounts[i].balance = accounts[i].balance + value;
				accounts[i].balanceTotal = updateBalanceTotal(accounts[i]);
				printf("Depósito efetuado com sucesso.\n\n");
			}
		}
	}else{
		printf("Erro ao efetuar depósito. Tente novamente.\n\n");
	}
}

void transfer(Account origin_account, Account target_account, float value){
    if(value > 0 && origin_account.balanceTotal >= value){
		for(int co = 0; co < count_accounts; co++){
			if(accounts[co].number == origin_account.number){
				for(int cd = 0; cd < count_accounts; cd++){
					if(accounts[cd].number == target_account.number){
						if(accounts[co].balance >= value){
							accounts[co].balance = accounts[co].balance - value;
							accounts[cd].balance = accounts[cd].balance + value;
							accounts[co].balanceTotal = updateBalanceTotal(accounts[co]);
							accounts[cd].balanceTotal = updateBalanceTotal(accounts[cd]);
							printf("Transferência realizada com sucesso.\n\n");
						}else{
							float rest = accounts[co].balance - value;
							accounts[co].limit = accounts[co].limit + rest;
							accounts[co].balance = 0.0;
							accounts[cd].balance = accounts[cd].balance + value;
							accounts[co].balanceTotal = updateBalanceTotal(accounts[co]);
							accounts[cd].balanceTotal = updateBalanceTotal(accounts[cd]);
							printf("Transferência realizada com sucesso.\n\n");
						}
					}
				}
			}
		}
	}else{
		printf("Transferência não realizada. Tente novamente.\n\n");
	}
}