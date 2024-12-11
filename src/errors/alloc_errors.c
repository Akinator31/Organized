/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** alloc_errors
*/

#include <stdlib.h>

void *problem_during_alloc(void)
{
    write(2, "Problem during memory allocation\n", 34);
    return NULL;
}

int probleme_device_list_alloc(void)
{
    write(2, "Problem during memory allocation\n", 34);
    return 84;
}

int device_list_empty(void)
{
    write(1, "Device list is empty\n", 22);
    return 84;
};
