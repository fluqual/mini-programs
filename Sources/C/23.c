#include <stdio.h>

int compare_dates(char* date1, char* date2) {
    int d1, m1, y1;
    int d2, m2, y2;
    sscanf(date1, "%d/%d/%d", &d1, &m1, &y1);
    sscanf(date2, "%d/%d/%d", &d2, &m2, &y2);
    if (y1 < y2) return -1;
    if (y1 > y2) return 1;

    if (m1 < m2) return -1;
    if (m1 > m2) return 1;

    if (d1 < d2) return -1;
    if (d1 > d2) return 1;
    return 0; 
}

int main() {
    char date_a[11];
    char date_b[11];
    printf("Введите первую дату: ");
    scanf("%s", date_a);
    printf("Введите вторую дату: ");
    scanf("%s", date_b);

    int result = compare_dates(date_a, date_b);

    if (result > 0) { 
        printf("Первая дата позже.\n");
    }
    else if (result < 0) {
        printf("Вторая дата позже.\n");
    }
    else {
        printf("Даты одинаковы.\n");
    }
    return 0;
}
