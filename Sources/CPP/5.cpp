#include <iostream>
#include <cmath>


int findPrimeNumbers(int n) {
	bool *arr = new bool[n];
	if (n < 2) { return -1; }
	for (int i = 0; i < n; i++) {
		arr[i] = true;
	}
	arr[0] = false;
	arr[1] = false;
	for (int i = 2; i < std::sqrt(n); i++) {
		if (arr[i]) {
			for (int p = i * i; p < n; p += i) {
				arr[p] = false;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i]) {
			std::cout << i << "\n";
		}
	}
	return 0;
}

int main() {
	std::setlocale(LC_ALL, "ru_RU.UTF-8");
	int n;
	std::cout << "Введите число n: ";
	std::cin >> n;
	findPrimeNumbers(n);
}
