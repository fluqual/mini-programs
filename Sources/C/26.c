#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

typedef struct {
	char* items;
	size_t count;
	size_t capacity;
} dynamic_str;

void push_back_char(dynamic_str* str, char c) {
	if (str->items == NULL) {
		str->capacity = 256;
		str->items = malloc(sizeof(*str->items) * str->capacity);
	}
	if (str->count + 2 > str->capacity) {
		str->capacity *= 2;
		str->items = realloc(str->items, sizeof(*str->items) * str->capacity);
	}
	str->items[str->count] = c;
	str->count++;
	str->items[str->count] = '\0';
}

void clear_str(dynamic_str* str) {
	str->capacity = 256;
	str->count = 0;
	str->items = realloc(str->items, sizeof(*str->items) * str->capacity);
}

void read_line(dynamic_str* str) {
	clear_str(str);
	int c; 
	while((c = getchar()) != '\n' && c != EOF) {
		push_back_char(str,(char)c);
	}
}

int read_file_line(dynamic_str* str, FILE* file) {
	clear_str(str);
	int c; 
	while((c = fgetc(file))!= '\n' && c != EOF) {
		push_back_char(str,(char)c);
	}
	if (c == EOF) {
		return 1;
	}
	return 0;
}

bool compare_files(FILE* file1, FILE* file2) {
	int file_end1 = 0;
	int file_end2 = 0;
	dynamic_str file_read1 = {0};
	dynamic_str file_read2 = {0};
	while (file_end1 != 1 && file_end2 != 1) {
		file_end1 = read_file_line(&file_read1, file1);
		file_end2 = read_file_line (&file_read2, file2);
		if (strcmp(file_read1.items, file_read2.items) != 0 || file_end1 != file_end2) {
			return false;
			free(file_read1.items);
			free(file_read2.items);
		}
	}
	free(file_read1.items);
	free(file_read2.items);
	return true;
}
int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
	FILE *file1;
	FILE *file2;
	dynamic_str a = {0};
	printf("Введите путь/имя 1 файла: ");
	read_line(&a);
	file1 = fopen(a.items, "r");
	printf("Введите путь/имя 2 файла: ");
	read_line(&a);
	file2 = fopen(a.items, "r");
	if (file1 == NULL || file2 == NULL) {
		printf("Неудалось найти файл/Неудалось открыть файл\n");
		return 1;
	}
	bool result = compare_files(file1, file2);
	if (result == true) {
		printf("Файлы одинаковые.\n");
	}
	else {
		printf("Файлы разные.\n");
	}
	fclose(file1);
	fclose(file2);
	free(a.items);
	return 0;
}
