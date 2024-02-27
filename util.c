/**
 * @file util.h
 * @author Hugo Martins & João Ribeiro
 * @date 29-11-2023
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2023. All Rights MIT Licensed.
 *
 * @brief Contains functions for get input, clean buffer and validate nif.
 */

#include "util.h"
#include "functions.h"
#include "files.h"
#include "comment.h"
#include "LineOfWork.h"
#include "UserSearch.h"
#include "company.h"

void cleanInputBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int getInt(int minValue, int maxValue, char *msg) {
    int value;
    printf(msg);
    while (scanf("%d", &value) != 1 || value < minValue || value > maxValue) {
        puts(ERROR_INVALID_VALUE);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return value;
}

float getFloat(float minValue, float maxValue, char *msg) {
    float value;
    printf(msg);
    while (scanf("%f", &value) != 1 || value < minValue || value > maxValue) {
        puts(ERROR_INVALID_VALUE);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return value;
}

void readString(char *string, unsigned int size, char *msg) {
    printf(msg);
    if (fgets(string, size, stdin) != NULL) {
        unsigned int len = strlen(string) - 1;
        if (string[len] == '\n') {
            string[len] = '\0';
        } else {
            cleanInputBuffer();
        }
    }
}

int get_nif(char *msg) {
    int value;
    printf("%s", msg);

    while (scanf("%d", &value) != 1 || !valid_nif(value)) {
        puts(ERROR_INVALID_VALUE);
        cleanInputBuffer();
        printf("%s", msg); 
    }

    cleanInputBuffer();  
    return value;
}

int valid_nif(int nif) {

    return (nif >= 100000000 && nif <= 999999999);
}



