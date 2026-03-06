#include <stdio.h>
#include <locale.h>

int get_element_of_sequence(int n1, int n2, int currentn, int requiredn) {
    if (currentn == requiredn) {return n1;}
    int newn = (2 * n2) - n1;
    return get_element_of_sequence(n2, newn, ++currentn, requiredn);
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int n;
    printf("Введите n: ");
    scanf("%i", &n);
    printf("Элемент последовательности: %i",get_element_of_sequence(1, 2, 0, n));
    return 0;
}
