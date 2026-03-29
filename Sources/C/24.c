#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    time_t timestamp;
    struct tm *data;
    char date_string[20];
    time(&timestamp);
    data = localtime(&timestamp);
	setlocale(LC_ALL, "ru_RU.UTF-8");
    printf("%s", ctime(&timestamp));
}
