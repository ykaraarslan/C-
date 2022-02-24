#include <stdio.h>
#include <locale.h>

int main() {
	int digit1, digit10, digit100, total, number;
	total = 0;
	printf("Enter 3 digit number:");
	scanf_s("%d", &number);

	digit1 = number % 10;
	digit10 = (number / 10) % 10;
	digit100 = number / 100;
	total = digit1 + digit10 + digit100;
	printf("%d", total);
	return 0;
}
