#include "functions.h"

int main() {
    char scalar[N]; //Масив, в якому буде зберігатися скаляр користувача.
    int indexes[N]; //indexes - масив, в якому будуть зберігатися індекси знайдених помилок в scalar[N].
    printf("Введіть скаляр:\n");
    gets(scalar);
    removeSpaces(scalar);
    //size = змінна у якій буде зберігатися кількість знайдених помилок для масиву індексів цілого типу даних indexes[N].
    int size = checkScalarProcess(scalar, indexes);
    if (size == 0) {
        printf("Все добре, скаляр є правильним.\n");
    } else if (size == -1) {
        puts("Ви не можете нічого не вводити");
    } else {
        printf("У скалярі є наступні помилки: ");
        for (int i = 0; i < size; i++) {
            printf("%c ", scalar[indexes[i]]);
        }
    }
    return 0;
}
