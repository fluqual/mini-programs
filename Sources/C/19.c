#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct {
    int* items;
    size_t count;
    size_t capacity;
} vector;

void vec_push_back(vector* vec, int n) {
    if (vec->items == NULL) {
        vec->capacity = 256;
        vec->items = malloc(sizeof(*vec->items) * vec->capacity);
    }
    if (vec->count + 1 > vec->capacity) {
        vec->capacity *= 2;
        vec->items = realloc(vec->items, sizeof(*vec->items) * vec->capacity);
    } 
    vec->items[vec->count] = n;
    vec->count++;
}

vector* factorize(int i, int divisor, vector* factors) {
    if (i <= 1) {return factors;}
    if (i % divisor == 0) {
        vec_push_back(factors, divisor);
        return factorize(i / divisor, divisor, factors);
    }
    else {
        if (divisor == 2) {
            divisor -= 1;
        }
        return factorize(i, divisor + 2, factors);
    }

}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    vector factors = {0};
    int input = 0;
    printf("Введите целое число: ");
    scanf("%i", &input);
    printf("Простые множители числа %i: ", input);
    factorize(input, 2, &factors);
    for (int i = 0; i < factors.count; i++) {
        printf("%i ", factors.items[i]);
    }
    return 0;   
}
