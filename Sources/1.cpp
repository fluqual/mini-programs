#include <iostream>
#include <random>
#include <ctime>
int main() {
	const int sizex = 5;
	const int sizey = 10;
	float** array = new float*[sizex];
	for (int i = 0; i < sizex; i++) {
		array[i] = new float[sizey];
	}
	std::mt19937 engine(std::time(0));
	std::uniform_real_distribution<float> dist(-1.0f, 1.0f);
	for (int i = 0; i < sizex; i++) {
		for (int j = 0; j < sizey; j++) {
			array[i][j] = dist(engine);
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < sizex; i++) {
		delete[] array[i];
	}
	delete[] array;
	return 0;
}
