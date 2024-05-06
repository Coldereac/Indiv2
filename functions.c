#include "functions.h"

void removeSpaces(char word[]) {
    int i = 0, j = 0;
    while (word[i] != '\0') {
        if (word[i] != ' ' || (word[i] != ' ' && word[i + 1] != ' ')) {
            word[j++] = word[i];
        }
        i++;
    }
    word[j] = '\0';
}

//перевіряємо scalar на наявність помилок. Якщо помилку знайдено, то записуємо її індекс в indexes.
int checkScalarProcess(const char scalar[], int indexes[]) {
    static int index = 0;
    static int counter = 0;
    static int seen_coma = 0;
    static int seen_dots = 0;
    static int found_constant = 0;
    static int index_of_first_symbol = 0;
    if (scalar[index] == '\0') {
        return counter;
    }
    if (scalar[index] == '.') {
        found_constant = 0;
        seen_dots++;
        if (seen_dots == 2) {
            index_of_first_symbol = index + 1;
        }
    } else if (scalar[index] == ',') {
        seen_coma = 1;
    }
    if ((index == 0 || seen_dots == 2) && isdigit(scalar[index_of_first_symbol])) {
        found_constant = 1;
    }
    if (index == 0 && !isalnum(scalar[index])) {
        indexes[counter++] = index;
    } else if (!isalnum(scalar[index]) && scalar[index] != '.') {
            indexes[counter++] = index;
    } else if (scalar[index] == ',' && (found_constant || seen_dots == 2)) {
        indexes[counter++] = index;
    } else if (scalar[index] == ',' && !isalpha(scalar[index + 1])) {
        if (scalar[index + 1] != '\0' && scalar[index + 1] != '.')
            indexes[counter++] = index + 1;
        else {
            indexes[counter++] = index;
        }
    } else if (seen_dots > 2 && scalar[index] == '.') {
        indexes[counter++] = index;
    } else if (scalar[index] == '.' && scalar[index + 1] != '.' && seen_dots == 1) {
        indexes[counter++] = index;
    } else if (found_constant && !isdigit(scalar[index]) && scalar[index] != ',' && scalar[index] != '.') {
        indexes[counter++] = index;
    }
    index++;
    return checkScalarProcess(scalar, indexes);
}
