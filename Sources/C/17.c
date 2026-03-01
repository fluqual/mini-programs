#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

typedef struct {
    char* items;
    size_t count;
    size_t capacity;
} dynamic_str;

void str_push_back_arr(dynamic_str* str, char* items) {
    if (str->capacity == 0) {
        str->capacity = 256;
    }
    if (str->items == NULL) {
        str->items = malloc(sizeof(*str->items) * str->capacity);
    }
    int i = 0;
    while (items[i] != '\0') {
        if (str->count + 2 > str->capacity) {
            str->capacity *= 2;
            str->items = realloc(str->items, sizeof(*str->items) * str->capacity);
        }
        str->items[str->count] = items[i];
        str->count++;
        i++;
    }
    str->items[str->count] = '\0';
}

void str_push_back_char(dynamic_str* str, char c) {
    if (str->capacity == 0) {
        str->capacity = 256;
    }
    if (str->items == NULL) {
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

void str_read_word(dynamic_str* str) {
    int ch;
    while ((ch = fgetc(stdin)) != ' ' && ch != '\n' && ch != EOF) {
        str_push_back_char(str, (char)ch);
    }
}
void str_read_line(dynamic_str* str) {
    int ch;
    while ((ch = fgetc(stdin)) != '\n' && ch != EOF) {
        str_push_back_char(str, (char)ch);
    }
}
int str_lchr(dynamic_str* str, char c) {
    int pos = -1;
    int i = 0;
    while (str->items[i] != '\0') {
        if (str->items[i] == c) {
            pos = i;
        }
        i++;
    }
    return pos;
}
int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    dynamic_str str = {0};
    char c;
    printf("Введите символ: ");
    scanf(" %c", &c);
    while (getchar() != '\n'); //input buffer clearing
    printf("Введите строку: ");
    str_read_line(&str);
    int lchr = str_lchr(&str,c);   
    if (lchr != -1) {
        printf("Последнее вхождение находится на индексе: %i", lchr);
    }
    else {
        printf("Символа в строке нету");
    }
    free(str.items);
    return 0;
}
