/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** my_free
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

void my_free(int nb_value, ...)
{
    va_list free_list;

    va_start(free_list, nb_value);
    for (int i = 0; i < nb_value; i++) {
        free(va_arg(free_list, void *));
    }
    va_end(free_list);
}
