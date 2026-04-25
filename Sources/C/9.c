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
    return new_m;
}

matrix* multiply_matrices(matrix* x, matrix* y) {
	matrix* multiplied_m = create_matrix(x->size_x, y->size_y);
	if (x->size_y != y->size_x) {
		return NULL;
	}
	for (int i = 0; i < x->size_x; i++) {
		for (int j = 0; j < y->size_y; j++) {
		    int sum = 0;
            for (int k = 0; k < x->size_y; k++) {
			    sum += x->data[i][k] * y->data[k][j];
            }
            multiplied_m->data[i][j] = sum;
		}
	}
	return multiplied_m;
}

int main() {
	matrix* m_1 = create_matrix_from_input(1);
	matrix* m_2 = create_matrix_from_input(2);
	matrix* result = multiply_matrices(m_1, m_2);
    if (result == NULL) {
        printf("Умножение невозможно");
        return 0;
    }
	for (int i = 0; i < result->size_x; i++) {
		for (int j = 0; j < result->size_y; j++) {
			printf("%i ", result->data[i][j]);
		}
        printf("\n");
	}
	return 0;
}
