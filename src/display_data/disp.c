/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** disp
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_lib.h"
#include "my_list.h"
#include "hardware.h"
#include "my_printf.h"
#include "error_handling.h"

void print_disp_detail(linked_list_t *list)
{
    hardware_t *hardware = (hardware_t *)((linked_list_t *)(list))->data;

    my_printf("%s", hardware->type);
    my_printf(" n°");
    my_printf("%d", hardware->id);
    my_printf(" - \"");
    my_printf(hardware->name);
    my_printf("\"\n");
}

int disp(void *data, char **args)
{
    linked_list_t *temp = ((device_list_t *)(data))->list;

    if (args[0] != NULL)
        return no_argument_is_needed();
    while (temp != NULL) {
        print_disp_detail(temp);
        temp = temp->next;
    }
    return 0;
}
