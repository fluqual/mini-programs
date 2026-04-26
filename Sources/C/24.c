#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char* get_current_date_str() {
    char* buffer = malloc(sizeof(char) * 50);
    time_t rawtime;
    struct tm *info;

    const char *months[] = {
        "январь", "февраль", "март", "апрель", "май", "июнь",
        "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь"
    };

    time(&rawtime);
    info = localtime(&rawtime);
    sprintf(buffer, "%02d/%s/%d", info->tm_mday, months[info->tm_mon], info->tm_year + 1900);
    return buffer;
}

int main() {
    printf("%s\n", get_current_date_str());
}



