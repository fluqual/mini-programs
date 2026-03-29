#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
typedef struct {
	char* items;
	size_t count;
	size_t capacity;
} dynamic_str;

void str_push_back(dynamic_str* str, char c) {
	if (str->items == NULL) {
		str->capacity = 256;
		str->count = 0;
		str->items = malloc(sizeof(*str->items) * str->capacity);
	}
	if (str->count + 2 > str->capacity) {
		str->capacity *= 2;
		str->items = realloc(str->items, sizeof(*str->items) * str->capacity);
	}
	str->items[str->count] = c;
	str->items[str->count + 1] = '\0';
	str->count++;	
}

void str_push_back_arr(dynamic_str* str, char* arr) {
	int i = 0;
	while (arr[i] != '\0') {
		str_push_back(str, arr[i]);
	}
}

struct person {
	dynamic_str full_name;
	char date_of_birth[11];
} ;

typedef struct {
	dynamic_str school_name;
	char class[3];
} schoolboy;

typedef struct {
	dynamic_str university;
	dynamic_str faculty;
	dynamic_str group;
} student;

void clear_input_buffer() {
	while (getchar() != '\n');
}

void str_input_line(dynamic_str* str) {
	char c;
	while ((c = getchar()) != '\0' && c != '\n' && c != EOF) {
		str_push_back(str, c);
	}
	clear_input_buffer();
}


struct person input_human_data() {
	struct person data = {0};
	printf("Введите имя человека: ");
	str_input_line(&(data.full_name));
	printf("Введите дату рождения: ");
    scanf("%s", &data.date_of_birth);
    return data;
}

int main() {
	
}
