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

// Перевіряє скаляр на наявність помилок. Якщо помилку знайдено,
// додає її індекс до масиву indexes.
int checkScalarProcess(const char scalar[], int indexes[]) {
    if (strlen(scalar) == 0) {
        return -1;
    }
    // Статичні змінні для відстеження стану та індексів помилок
    static int index = 0; // Поточний індекс у скалярі
    static int counter = 0; // Кількість знайдених помилок
    static int seen_dots = 0; // Кількість крапок (.)
    static int found_constant = 0; // Чи знайдено константу (число)
    static int index_of_first_symbol = 0; // Індекс першого символу після крапок (.)


    // Кінець скаляра: перевірка на завершення перегляду
    if (scalar[index] == '\0') {
        // Якщо знайдено константу без крапок, це помилка
        if (found_constant && seen_dots == 0) {
            indexes[counter++] = 0; // Індекс 0 для помилки на початку
            // Якщо останній символ - крапка, переглянути всі крапки
        } else if (scalar[strlen(scalar) - 1] == '.') {
            index = strlen(scalar) - 1;
            while (scalar[index] == '.') {
                indexes[counter++] = index--; // Додавання індексів крапок до помилок
            }
        }
        return counter; // Повернення кількості знайдених помилок
    }

    // Символ - крапка (.)
    if (scalar[index] == '.') {
        found_constant = 0; // Скидання прапора константи
        seen_dots++; // Збільшення лічильника крапок
        if (seen_dots >= 2) {
            index_of_first_symbol = index + 1; // Індекс першого символу після крапок
        }
    }

    // Визначення константи (числа)
    if ((index == 0 || seen_dots >= 2) && isdigit(scalar[index_of_first_symbol])) {
        found_constant = 1; // Встановлення прапора константи
    }

    // Перевірка помилок для різних символів
    if (index == 0 && !isalnum(scalar[index])) {
        indexes[counter++] = index; // Помилка: не алфавітно-цифровий символ на початку
    } else if (!isalnum(scalar[index]) && scalar[index] != ',' && scalar[index] != '.') {
        indexes[counter++] = index; // Помилка: недопустимий символ
    } else if (scalar[index] == ',' && (found_constant || seen_dots == 2)) {
        indexes[counter++] = index; // Помилка: кома після константи або двох крапок
    } else if (scalar[index] == ',' && !isalpha(scalar[index + 1])) {
        if (scalar[index + 1] != '\0' && scalar[index + 1] != '.') {
            indexes[counter++] = index + 1; // Помилка: кома перед не алфавітним символом
        } else {
            indexes[counter++] = index; // Помилка: зайва кома в кінці
        }
    } else if (seen_dots > 2 && scalar[index] == '.') {
        indexes[counter++] = index; // Помилка: більше двох послідовних крапок
    } else if (scalar[index] == '.' && scalar[index + 1] != '.' && seen_dots == 1) {
        indexes[counter++] = index; // Помилка: крапка після крапки (..), але не три крапки (...)
    } else if (found_constant && !isdigit(scalar[index]) && scalar[index] != ',' && scalar[index] != '.') {
        indexes[counter++] = index; // Помилка: символ після константи повинен бути цифрою, комою або крапкою
    }
    index++; // Перейти до наступного символу в скалярі
    return checkScalarProcess(scalar, indexes); // Рекурсивний виклик для перевірки решти скаляра
}
