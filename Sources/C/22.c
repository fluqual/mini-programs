#include <stdio.h>
#include <time.h>
#include <locale.h>
int main() {
	char input;
	clock_t timestamp1;
	setlocale(LC_ALL, "ru_RU.UTF-8");
	printf("Нажмите enter два раза ");
	scanf("%c", &input);
	timestamp1 = clock();
	scanf("%c", &input);
	printf("Количество времени, которое прошло после первого ввода: %.3f\n", ((double)(clock() - timestamp1)) / CLOCKS_PER_SEC);
}
