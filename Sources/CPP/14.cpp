#include <iostream>
#include <string>
#include <Windows.h>

std::string removeFirstAndLastSpaces(std::string str) {
    if (str.back() == ' ') {
        int i = 0;
        while (str[str.length() - 1 - i] == ' ') {
            str.pop_back();
            i++;
        }
    }
    if (str.front() == ' ') {
        while (str[0] == ' ') {
            str.erase(0, 1);
        }
    }
    return str;

}
int main() {
	std::setlocale(LC_ALL, "ru_RU.UTF-8");
    std::string input;
    std::cout << "Введите строку: " << std::endl;
    std::getline(std::cin, input);
    std::cout << "Результат после удаления ведущих и конечных пробелов: " << std::endl;
    std::setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    std::cout << removeFirstAndLastSpaces(input) << std::endl;
    return 0;
}
