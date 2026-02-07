#include <iostream>

double machine_zero() {
	double z = 1.0;
	while (z / 2.0 > 0.0) {
		z /= 2;
	}
	return z;
}

double machine_epsilon() {
	double e = 1.0;
	while (e + 1 > 1.0) {
		e /= 2;
	}
	return e * 2;
}

int main() {
	std::setlocale(LC_ALL, "ru_RU.UTF-8");
	std::cout << "Машинный ноль: " << machine_zero() << std::endl;
	std::cout << "Машинный эпсилон: " << machine_epsilon() << std::endl;
	return 0;
}
