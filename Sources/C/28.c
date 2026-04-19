#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//#include <Windows.h>
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

void free_dynamic_str(dynamic_str* a) {
    free(a->items);
}

void clear_input_buffer() {
	while (getchar() != '\n');
}

void str_input_line(dynamic_str* str) {
	char c;
	while ((c = getchar()) != '\0' && c != '\n' && c != EOF) {
		str_push_back(str, c);
	}
}

struct person {
	dynamic_str full_name;
	char date_of_birth[11];
};

struct schoolboy{
    struct person* person;
	dynamic_str school_name;
	char class[3];
};

struct student {
    struct person* person;
	dynamic_str university;
	dynamic_str faculty;
	dynamic_str group;
};


struct person input_person_data() {
	struct person data = {0};
	printf("Введите имя человека: ");
	str_input_line(&data.full_name);
	printf("Введите дату рождения: ");
    scanf("%s", data.date_of_birth);
    return data;
}

struct student* input_student_data(struct person* a) {
    struct student* data = malloc(sizeof(struct student));
    data->person = a;
    printf("Введите университет студента: ");
    str_input_line(&data->university);
    printf("Введите факультет студента: ");
    str_input_line(&data->faculty);
    printf("Введите группу студента: ");
    str_input_line(&data->group);
    return data;
}

void clear_student_data(struct student* a) {
    free_dynamic_str(&a->group);
    free_dynamic_str(&a->faculty);
    free_dynamic_str(&a->university);
}

struct schoolboy* input_schoolboy_data(struct person* a) {
    struct schoolboy* data = malloc(sizeof(struct schoolboy));
    data->person = a;
    printf("Введите имя школы: ");
    str_input_line(&data->school_name);
    printf("Введите класс школьника: ");
    scanf("%s", data->class);
    return data;
}

void clear_schoolboy_data(struct schoolboy* a) {
    free_dynamic_str(&a->school_name);
}

int main() {
    void* person_data;
    struct person a = input_person_data();
    int is_student = 0;
    printf("Человек - студент? (0 - нет, 1 - да): ");
    scanf("%i", &is_student);
    clear_input_buffer();
    if (is_student == 1) {
        person_data = (void*)input_student_data(&a);
        clear_student_data((struct student*)person_data);
    } 
    else {
        person_data = (void*)input_schoolboy_data(&a);
        clear_schoolboy_data((struct schoolboy*)person_data);
    }
    free_dynamic_str(&a.full_name);
}





