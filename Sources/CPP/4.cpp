#include <iostream>
#include <vector>
#include <cmath>

double calculate_vector_length(std::vector<double> vec) {
	double sum = 0;
	for (double i : vec) {
		sum += i * i;
	}
	return std::sqrt(sum);
}

int main() {
	std::setlocale(LC_ALL, "ru_RU.UTF-8");
	std::vector<double> vec = {};
	int vec_d;
	std::cout << "Введите кол-во чисел: ";
	std::cin >> vec_d;
	std::cout << "Введите координаты вектора: ";
	for (int i = 0; i < vec_d; i++) {
		int in;
		std::cin >> in;
		vec.push_back(in);
	}
	std::cout << "Длина вектора: " << calculate_vector_length(vec);
	return 0;
}
