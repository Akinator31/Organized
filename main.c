/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** main
*/

#include <stdlib.h>
#include "shell.h"
#include "my_lib.h"
#include "my_list.h"
#include "utils.h"
#include "error_handling.h"

int main(void)
{
    device_list_t *device_list =
        (device_list_t *)malloc(sizeof(device_list_t));
    int exit_code = 0;

    if (device_list == NULL)
        return probleme_device_list_alloc();
    device_list->list = NULL;
    device_list->id = 0;
    exit_code = workshop_shell(device_list);
    clear_list(device_list->list, free_hardware);
    free(device_list);
    return exit_code;
}
