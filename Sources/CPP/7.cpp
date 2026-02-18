#include <iostream>

bool isPalindrome(int a) {
	int n = 1;
	int iter = a;
	int reversed = 0;
	while (iter != 0) {
		n *= 10;
		iter /= 10;
	}
	n /= 10;
	iter = a;
	while (iter != 0) {
		reversed += (iter % 10) * n;
		iter /= 10;
		n/= 10;
	}
	if (reversed == a) {
		return true; 
	} else {
		return false;
	}
}

int main() {
	int n;
	std::setlocale(LC_ALL, "ru_RU.UTF-8");
	std::cout << "Введите число: ";
	std::cin >> n;
	for (int i = 1; i < n; i++) {
		if (isPalindrome(i)) {
			std::cout << i << "\n";
		}
	}
}
