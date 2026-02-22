#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

int main() {
	int rows;
	int cols;
	setlocale(LC_ALL, "ru_RU.UTF-8");
	printf("Введите количество строк: ");
	scanf("%i", &rows);
	printf("Введите количество столбцов: ");
	scanf("%i", &cols);
	int arr[rows][cols];
	printf("Введите элементы матрицы:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			scanf("%i", &arr[i][j]);
		}

	}

	// main logic
	bool foundCols[cols];
	for (int i = 0; i < rows; i++) {
		int j;
		bool foundZero = false;
		for (j = 0; j < cols; j++) {
			if (arr[i][j] == 0) {
				foundCols[j] = true;
				foundZero = true;
			}
		}
		if (!foundZero) {
			printf("В каждой строке и столбце нету нулевого элемента.\n");
			return 0;
		}
	}
	for (int i = 0; i < cols; i++) {
		if (!foundCols[i]) {
			printf("В каждой строке и столбце нету нулевого элемента.\n");
			return 0;
		}

	}
	printf("В каждой строке и столбце есть нулевой элемент.\n");
	return 0;
}
