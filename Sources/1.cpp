#include <iostream>
#include <ctime>
int main() {
	const int sizex = 5;
	const int sizey = 10;
	int** array = new int*[sizex];
	
	for (int i = 0; i < sizex; i++) {
		array[i] = new int[sizey];
	}
	std::srand(std::time(0));
	for (int i = 0; i < sizex; i++) {
		for (int j = 0; j < sizey; j++) {
			array[i][j] = rand() % 100;
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
