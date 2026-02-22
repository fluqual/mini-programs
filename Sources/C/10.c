#include <stdio.h>
#include <locale.h>
void findNumbersWithDigitSumOf(int n) {
	if (n <= 0 || n > 27) { printf("Нет чисел"); return; }
	for (int i = 100; i < 1000; i++) {
		int sum = 0;
		int tempi = i;
		for (int j = 0; j < 3; j++) {
			sum += tempi % 10;
			tempi /= 10;
		}
		if (sum == n) {
			printf("%d\n", i);
		}

	}
}
int main() {
	int n;
	setlocale(LC_ALL, "ru_RU.UTF-8");
	printf("Введите число n: ");
	scanf("%i", &n);
	printf("Числа, сумма которых равна %i: \n", n);
	findNumbersWithDigitSumOf(n);
	return 0;
}
