/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** task06
*/

#include <stdlib.h>
#include "my_lib.h"

char is_alpha(char act_char)
{
    if ((act_char >= 'A') && (act_char <= 'Z'))
        return act_char + 32;
    return act_char;
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    int result = 0;

    for (int i = 0; (s1[i] != '\0') || (s2[i] != '\0'); i++) {
        if (s1[i] != s2[i]) {
            result = s1[i] - s2[i];
            return result;
        }
    }
    result = s1[i] != s2[i];
    return result;
}
