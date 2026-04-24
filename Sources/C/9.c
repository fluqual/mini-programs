#include <stdio.h>
#include <stdlib.h>

typedef struct {
	size_t size_x;
	size_t size_y;
	int** data;
} matrix;

matrix* create_matrix(int size_x, int size_y) {
	matrix* new_m = malloc(sizeof(matrix));
	new_m->size_x = size_x;
	new_m->size_y = size_y;
	new_m->data = malloc(sizeof(int*) * new_m->size_x);
	for (int i = 0; i < size_x; i++) {
		new_m->data[i] = malloc(sizeof(int) * new_m->size_y);
	}
	return new_m;
}

matrix* create_matrix_from_input(int num) {
	int size_x;
	int size_y;
	printf("Введите данные %i матрицы:\n", num);
	printf("Введите кол-во строк: ");
	scanf("%i", &size_x);
	printf("Введите кол-во столбцов: ");
	scanf("%i", &size_y);
	matrix* new_m = create_matrix(size_x, size_y);
	printf("Введите матрицу: ");
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			scanf("%i", &new_m->data[i][j]);
		}
	}
}

matrix* multiply_matrices(matrix* x, matrix* y) {
	matrix* multiplied_m = create_matrix(x->size_x, y->size_y);
	for (int i = 0; i < multiplied_m->size_x; i++) {
		for (int j = 0; j < multiplied_m->size_y; j++) {

		}

	}
	
}

int main() {
	matrix* m = create_matrix_from_input(1);
}
