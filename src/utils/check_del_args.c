/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** check_del_args
*/

#include <stdlib.h>

int is_number(char *arg)
{
    for (int i = 0; arg[i] != '\0'; i++) {
        if ((arg[i] < '0') || (arg[i] > '9'))
            return 0;
    }
    return 1;
}

int check_del_args(char **args)
{
    for (int i = 0; args[i] != NULL; i++) {
        if (!is_number(args[i]))
            return 0;
    }
    return 1;
}
