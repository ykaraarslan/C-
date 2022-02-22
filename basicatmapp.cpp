#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <locale.h>

int balance;
int menu() {
	system("cls");
	printf("\navailable balance : %d $ \n\n", balance);
	int choose;
	printf("\n\tATM app \n");
	printf("\t1-withdraw money \n");
	printf("\t2-deposit money \n");
	printf("\t3-pay bill \n");
	printf("\t4-eft\n");
	printf("\t6-exit \n");
	scanf_s("%d", &choose);
	return choose;
}
void withdrawmoney()
{
	int amount;
	printf("amount:");
	scanf_s("%d", &amount);
	printf("your transaction is taking place...\n");
	Sleep(2000);

	if (balance < amount) {
		printf("insufficient balance\n");

	}
	else {
		balance -= amount;
		printf("Withdrawal successful...\n");
		Sleep(2000);
		printf("don't forget your money...\n");
		Sleep(2000);
	}
	printf("you are redirected to the main menu...\n");
	Sleep(2000);
}

void depositmoney()
{
	int amount;
	printf("amount to be deposited:");
	scanf_s("%d", &amount);
	printf("your transaction is taking place...\n");
	Sleep(2000);
	balance += amount;
	printf("deposit successful\n");
	Sleep(2000);
	printf("you are redirected to the main menu...\n");
	Sleep(2000);
}

void paybill()
{
	int amount, choose, number;
	printf("1-electric\n");
	printf("2-water\n");
	printf("3-natural gas\n");
	printf("4-phone\n");
	scanf_s("%d", &choose);
	if (choose < 1 || choose>4)
	{
		printf("wrong choose\n");
	}
	else
	{
		printf("invoice number:");
		scanf_s("%d", &number);
		Sleep(2000);
		amount = rand() % 100 + 20;
		printf("Invoice of J...... A....... %d $ \n");
		printf("1- I confirm the payment\n");
		scanf_s("%d", &choose);
		Sleep(2000);
		if (choose != 1)
		{
			printf("transaction canceled...\n");
		}
		else
		{
			if (amount > balance) {
				printf("insufficient balance");
				Sleep(2000);
			}
			else {
				balance -= amount;
				printf("invoice payment transaction completed successfully...\n");
				Sleep(2000);
			}

		}
	}
	printf("you are redirected to the main menu...\n");
	Sleep(2000);
}
void eft()
{
	int amount, IBAN;
	printf("IBAN number:");
	scanf_s("%d", &IBAN);
	printf("amount to be deposited:");
	scanf_s("%d", &amount);

	if (balance < amount) {
		printf("insufficient balance\n");

	}
	else {
		balance -= amount;
		printf("your transaction is taking place...\n");
		Sleep(2000);
		printf("eft transaction successful\n");
		Sleep(2000);
	}
	printf("you are redirected to the main menu...\n");
	Sleep(2000);
}

int main()
{
	int password, i = 0;
	printf("password:");
	scanf_s("%d", &password);
	while (password != 2406)
	{
		printf("wrong password...try again:\n");
		scanf_s("%d", &password);
		if (i == 3)
		{
			printf("card is blocked...\n");
			printf("call customer service...(212 000 31)");
			return 0;
		}
		i++;
	}
	printf("successful login\n");
	Sleep(2000);
	srand(time(0));

	balance = rand() % 900 + 100;

	int choose;
	while (1) {
		choose = menu();
		switch (choose) {
		case 1: withdrawmoney();
			break;
		case 2: depositmoney();
			break;
		case 3: paybill();
			break;
		case 4: eft();
			break;
		case 5: printf("Get your card...\n");
			return 0;
		default: printf("Incorrect operation \n");
			Sleep(2000);
		}
	}
	return 0;
}