#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void findNumbersWithDiffDigits(int n) {
	size_t buf_size = 1024;
	char* buffer = malloc(buf_size);
	int offset = 0;
	for (int i = 0; i < n; i++) {
		int tempi = i;
		unsigned int mask = 0;
		while (tempi != 0) {
			int remainder = tempi % 10;
			if ((mask >> remainder) & 1) {
				break;
			}
			mask |= 1 << remainder;
			tempi /= 10;
		}
		if (tempi == 0) {
			if (offset + 13 > buf_size) {
				buf_size *= 2;
				buffer = realloc(buffer, buf_size);
			}
			offset += sprintf(buffer + offset, "%i\n", i);
		}
	}
	fputs(buffer, stdout);
	free(buffer);
}
int main() {
	int n;
	setlocale(LC_ALL, "ru_RU.UTF-8");
	printf("Введите число n: ");
	scanf("%i", &n);
	printf("Числа без повторяющихся цифр до %i: \n", n);
	setlocale(LC_ALL, "C");
	findNumbersWithDiffDigits(n);
	return 0;
}
