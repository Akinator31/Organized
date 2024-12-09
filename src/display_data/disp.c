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

void print_disp_detail(linked_list_t *list)
{
    my_printf("%s", ((hardware_t *)(*(linked_list_t **)(list))->data)->type);
    my_printf(" n°");
    my_printf("%d", ((hardware_t *)(*(linked_list_t **)(list))->data)->id);
    my_printf(" - \"");
    my_printf(((hardware_t *)(*(linked_list_t **)(list))->data)->name);
    my_printf("\"\n");
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
