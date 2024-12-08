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

void print_disp_detail(linked_list_t *list)
{
    my_putstr(((hardware_t *)(*(linked_list_t **)(list))->data)->type);
    write(1, " n°", 4);
    my_put_nbr(((hardware_t *)(*(linked_list_t **)(list))->data)->id);
    write(1, " - \"", 5);
    my_putstr(((hardware_t *)(*(linked_list_t **)(list))->data)->name);
    write(1, "\"\n", 3);
}

int disp(void *data, char **args)
{
    linked_list_t *temp = data;

    while (temp->next != NULL) {
        print_disp_detail(temp);
        temp = temp->next;
    }
    return 0;
}
