/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** task02
*/

#include "my_lib.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}
