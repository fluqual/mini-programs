#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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
    if (a->items) free(a->items);
    a->items = NULL;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void str_input_line(dynamic_str* str) {
    char c;
    while ((c = getchar()) != '\0' && c != '\n' && c != EOF) {
        str_push_back(str, c);
    }
}


struct employee {
    dynamic_str full_name;
    char date_of_birth[11]; 
};

struct worker {
    struct employee* base;
    dynamic_str professions[5];
    int categories[5];
    int prof_count;
};

struct programmer {
    struct employee* base;
    dynamic_str university;
    int graduation_year;
    dynamic_str languages[5];
    dynamic_str skill_levels[5];
    int lang_count;
};


struct employee input_employee_data() {
    struct employee data = {0};
    printf("Введите ФИО сотрудника: ");
    str_input_line(&data.full_name);
    printf("Введите дату рождения (дд.мм.гггг): ");
    scanf("%10s", data.date_of_birth);
    clear_input_buffer();
    return data;
}

struct worker* input_worker_data(struct employee* e) {
    struct worker* data = malloc(sizeof(struct worker));
    data->base = e;
    printf("Сколько профессий ввести (макс. 5): ");
    scanf("%d", &data->prof_count);
    if (data->prof_count > 5) data->prof_count = 5;
    clear_input_buffer();

    for (int i = 0; i < data->prof_count; i++) {
        data->professions[i].items = NULL;
        printf("Профессия %d: ", i + 1);
        str_input_line(&data->professions[i]);
        printf("Разряд/категория по этой профессии: ");
        scanf("%d", &data->categories[i]);
        clear_input_buffer();
    }
    return data;
}

struct programmer* input_programmer_data(struct employee* e) {
    struct programmer* data = malloc(sizeof(struct programmer));
    data->base = e;
    data->university.items = NULL;
    
    printf("Название вуза: ");
    str_input_line(&data->university);
    printf("Год окончания: ");
    scanf("%d", &data->graduation_year);
    
    printf("Сколько языков программирования ввести (макс. 5): ");
    scanf("%d", &data->lang_count);
    if (data->lang_count > 5) data->lang_count = 5;
    clear_input_buffer();

    for (int i = 0; i < data->lang_count; i++) {
        data->languages[i].items = NULL;
        data->skill_levels[i].items = NULL;
        printf("Язык %d: ", i + 1);
        str_input_line(&data->languages[i]);
        printf("Степень владения: ");
        str_input_line(&data->skill_levels[i]);
    }
    return data;
}


void free_worker(struct worker* w) {
    for (int i = 0; i < w->prof_count; i++) {
        free_dynamic_str(&w->professions[i]);
    }
    free(w);
}

void free_programmer(struct programmer* p) {
    free_dynamic_str(&p->university);
    for (int i = 0; i < p->lang_count; i++) {
        free_dynamic_str(&p->languages[i]);
        free_dynamic_str(&p->skill_levels[i]);
    }
    free(p);
}

int main() {
    setlocale(LC_ALL, "Russian");

    struct employee emp = input_employee_data();
    int type;
    printf("Тип сотрудника (1 - Рабочий, 2 - Программист): ");
    scanf("%d", &type);
    clear_input_buffer();

    if (type == 1) {
        struct worker* w = input_worker_data(&emp);
        free_worker(w);
    } else if (type == 2) {
        struct programmer* p = input_programmer_data(&emp);
        free_programmer(p);
    }

    free_dynamic_str(&emp.full_name);
    return 0;
}
