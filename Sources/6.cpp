#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <ctime>
int main() {
	std::ios_base::sync_with_stdio(false);
	std::clock_t t1 = std::clock();
	std::array<std::vector<std::string>, 28> sorted_combos;
	bool print_combinations = true;
	for (int i = 0; i < 28; i++) {
		std::vector<std::string> vec = {};
		sorted_combos[i] = vec;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int z = 0; z < 10; z++) {
				std::string str = std::to_string(i) + std::to_string(j) + std::to_string(z);
				sorted_combos[i + j + z].push_back(str);
			}
		}
		
	}
	int count = 0;
	for (int i = 0; i < 28; i++) {
		for (int j = 0; j < sorted_combos[i].size(); j++) {
			for (int z = 0; z < sorted_combos[i].size(); z++) {
				if (print_combinations) {
					std::cout << sorted_combos[i][j];
					std::cout << sorted_combos[i][z];
				std::cout << " ";
				}
				count++;
			}
			if (print_combinations) {
				std::cout << "\n";
			}
		}
		if (print_combinations) {
			std::cout << std::endl;
		}
	}
	std::clock_t t2 = std::clock();
	std::setlocale(LC_ALL, "ru_RU.UTF-8");
	std::cout << "Количество счастливых билетов: " << count << std::endl;
	std::cout << "Скорость программы в секундах: " << ((double)(t2 - t1) / CLOCKS_PER_SEC);
}
