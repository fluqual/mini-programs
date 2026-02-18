#include <iostream>
#include <random>
#include <vector>
#include <ctime>
int main() {
	const int sizex = 5;
	const int sizey = 10;
	std::vector<std::vector<float>>* array = new std::vector<std::vector<float>>(sizex, std::vector<float>(sizey, 0));
	std::mt19937 engine(std::time(0));
	std::uniform_real_distribution<float> dist(-1.0f, 1.0f);
	for (int i = 0; i < sizex; i++) {
		for (int j = 0; j < sizey; j++) {
			(*array)[i][j] = dist(engine);
			std::cout << (*array)[i][j] << " ";
		}
		std::cout << std::endl;
	}
	delete array;
	return 0;
}
