#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_COUNT 10000
#define FILE_NAME "data.bin"

int main() {
    srand(time(NULL));

    FILE *outFile = fopen(FILE_NAME, "wb");
    if (outFile == NULL) {
        printf("Ошибка при открытии файла для записи");
        return 1;
    }

    for (int i = 0; i < NUM_COUNT; i++) {
        int num = (rand() % 2 == 0) ? -1 : 1;
        fwrite(&num, sizeof(int), 1, outFile);
    }
    fclose(outFile);

    int *buffer = (int *)malloc(NUM_COUNT * sizeof(int));
    FILE *inFile = fopen(FILE_NAME, "rb");
    if (inFile == NULL) {
        printf("Ошибка при открытии файла для чтения");
        free(buffer);
        return 1;
    }
    size_t readCount = fread(buffer, sizeof(int), NUM_COUNT, inFile);
    fclose(inFile);
    int sum = 0;
    for (int i = 0; i < NUM_COUNT; i++) {
        sum += buffer[i];
    }
    printf("Сумма %d элементов: %i\n", NUM_COUNT, sum);
    free(buffer);
    return 0;
}
