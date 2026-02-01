#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <ctime>
int main() {
	std::ios_base::sync_with_stdio(false);
	std::clock_t t1 = std::clock();
	std::unordered_map<int, std::vector<std::array<int, 3>>> sorted_combos;
	bool print_combinations = true;
	for (int i = 0; i < 28; i++) {
		std::vector<std::array<int, 3>> vec = {};
		sorted_combos[i] = vec;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int z = 0; z < 10; z++) {
				std::array<int, 3> arr = {i, j, z};
				sorted_combos[i + j + z].push_back(arr);
			}
		}
		
	}
	int count = 0;
	for (int i = 0; i < 28; i++) {
		for (int j = 0; j < sorted_combos[i].size(); j++) {
			for (int z = 0; z < sorted_combos[i].size(); z++) {
				if (print_combinations) {
					for (int y = 0; y < 3; y++) {
						std::cout << sorted_combos[i][j][y];
					}
					for (int y = 0; y < 3; y++) {
						std::cout << sorted_combos[i][z][y];
					}
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
