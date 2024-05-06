//
// Created by malinka on 06.05.24.
//

/*Побудувати синтаксичний аналізатор для поняття «скалярний_тип»:
скалярний_тип ::= { ім'я_константи {, ім'я_константи}*} | { константа . .
константа } | ім'я_скаляр_типу

/*
 *Правильні варіанти:
 *int, float, double x
 *int x
 *123 . . 225 x
 *123 .. 225 x
 *123 .. n3pq x
 *n3pq . . 123 x
 *qd7w x
 *
 *Неправильні варіанти:
 * , | . | ! | ? ... x
 * int, 1f x
 * double2 . . 32 . . 90 x
 * int ,, 1f x
 * 229
 * hello, . x
 * hello, x
 * 123 . .
 * 123b . . 934hwa x
 * 123 .... int x
 * 123 ... int x
 * ?..2h x
 * h., x
 */
/*
ім'я_константи ::= буква {цифра | буква}*
ім'я_скаляр_типу ::= буква {цифра | буква}*
константа ::= цифра {цифра}* | ім'я_константи

цифра ::= 0|1|2|3|4|5|6|7|8|9
буква ::=a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100
void removeSpaces(char word[]);
int checkScalarProcess(const char *scalar, int indexes[]);    /*Функція, яка буде викликатися рекурсивно в ній ми будемо
перевіряти чи є рядок правильним, інакше будемо вказувати на помилки.*/

#endif //FUNCTIONS_H
