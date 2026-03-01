#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

void swap(std::string* x, std::string* y) {
    std::string temp = *x;
	*x = *y;
	*y = temp;
}

int partition(std::vector<std::string>& arr, int low, int high) {
    std::string pivot = arr[high];
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


void quicksort(std::vector<std::string>& arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

int main() {
	std::setlocale(LC_ALL, "ru_RU.UTF-8");
    int size;
    std::vector<std::string> arr = {};
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    std::cout << "Введите массив строк (один элемент читается до пробела): ";
	std::setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    for (int i = 0; i < size; i++) {
        std::string input;
        std::cin >> input;
        for (char &c : input) {
            c = std::tolower(c);
        }
        arr.push_back(input);
    }
    quicksort(arr, 0, size - 1);
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
