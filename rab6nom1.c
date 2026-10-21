
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int remainder_by_4(int year);
int is_leap_year(int year);

int main(void)
{
    int year;
    int rem;
    int leap;

    setlocale(LC_ALL, "Russian");

    printf("Введите год: ");
    if (scanf("%d", &year) != 1 || year <= 0)
    {
        printf("Ошибка: нужно ввести целое положительное число.\n");
        return 1;
    }

    /* 1 */
    rem = remainder_by_4(year);
    printf("Остаток от деления на 4: %d\n", rem);
    if (rem == 0)
        printf("По упрощённому правилу (кратность 4): год %d високосный\n", year);
    else
        printf("По упрощённому правилу (кратность 4): год %d не високосный\n", year);

    /* 2 */
    leap = is_leap_year(year);
    if (leap)
        printf("По точному правилу (4, 100, 400): год %d високосный\n", year);
    else
        printf("По точному правилу (4, 100, 400): год %d не високосный\n", year);

    return 0;
}

int remainder_by_4(int year)
{
    int rem;
    rem = year % 4;
    return rem;
}

int is_leap_year(int year)
{
    int leap;
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    return leap;
}