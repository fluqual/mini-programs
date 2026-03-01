#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int *arr, int low, int high) {
	int pivot = arr[high];
	int j = (low - 1);
	for (int i = low; i <= high - 1; ++i) {
		if (arr[i] <= pivot) {
			j++;
			swap(&arr[j], &arr[i]);
		}
	}
	swap(&arr[j + 1], &arr[high]);
	return (j + 1);
}

void quicksort(int* arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int size;
	printf("Введите размер массива: ");
	scanf("%i", &size);
	printf("Введите массив:\n");
	int *arr = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; ++i) {
		scanf("%i", &arr[i]);
	}
	quicksort(arr, 0, size - 1);
    printf("Отсортированный массив: ");
	for (int i = 0; i < size; ++i) {
		printf("%i ", arr[i]);
	}
	printf("\n");
    free(arr);
	return 0;
}
