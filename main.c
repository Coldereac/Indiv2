

#include "functions.h"

int main() {
    char formula[N];    //Рядковий масив, в якому буде зберігатися формула користувача.
    int indexes[N];    //indexes - масив, в якому будуть зберігатися індекси знайдених помилок в реченні користувача в formula[N].
    //size = змінна у якій буде зберігатися кількість знайдених помилок для масиву індексів цілого типу даних indexes[N].
    printf("Введіть формулу:\n");
    fgets(formula, N, stdin);
    formula[strlen(formula) - 1] = '\0';
    removeSpaces(formula);
    int size = checkScalarProcess(formula, indexes);
    if(size == 0) {
        printf("Все добре, формула є правильною.\n");
    } else {
        printf("У формулі є наступні помилки: ");
        for(int i = 0; i < size; i++) {
            printf("%c ", formula[indexes[i]]);
        }
    }
    return 0;
}