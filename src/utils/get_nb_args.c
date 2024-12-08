/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** get_nb_args
*/

#include <stdlib.h>

int get_nb_args(char **args)
{
    int result = 0;

    for (int i = 0; args[i] != NULL; i++)
        result++;
    return result;
}
