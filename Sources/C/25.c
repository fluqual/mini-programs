#include <stdio.h>
#include <stdlib.h>
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
int count_file_lines(FILE* file) {
	dynamic_str str = {0};
	int count = 0;
	int is_eof = 0;
	while(is_eof == 0) {
		is_eof = read_file_line(&str, file);
		count++;
	}
	//count--;
	free(str.items);
	return count;
}
int main() {
	FILE *file;
	dynamic_str a = {0};
    setlocale(LC_ALL, "ru_RU.UTF-8");
	printf("Введите путь/имя файла: ");
	read_line(&a);
	file = fopen(a.items, "r");
	if (file == NULL) {
		printf("Неудалось найти файл/Неудалось открыть файл\n");
		return 1;
	}
	int count = count_file_lines(file);
	fclose(file);
	printf("Количество строк в файле: %i\n", count);
	free(a.items);
	return 0;
}
