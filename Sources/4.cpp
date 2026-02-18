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
	std::vector<double> vec = {};
	int vec_d;
	std::cin >> vec_d;
	for (int i = 0; i < vec_d; i++) {
		int in;
		std::cin >> in;
		vec.push_back(in);
	}
	std::cout << calculate_vector_length(vec);
	return 0;
}
