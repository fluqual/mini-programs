#include <iostream>
#define ARRAY_SIZE 5
int test(int (&arr)[ARRAY_SIZE]) {
	int count = 0;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (arr[i] % 2 == 0) {
			count++;
		}
	}
	return count;
}
int main() {
	std::setlocale(LC_ALL, "ru_RU.UTF-8");
	int array[ARRAY_SIZE];
	std::cout << "Введите " << ARRAY_SIZE << " чисел: ";
	
	for (int i = 0; i < ARRAY_SIZE; i++) {
		std::cin >> array[i];
	}
	int count = test(array);
	std::cout << "Количество четных чисел: " << count;
	return 0;
}
