/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** remove
*/

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include "my_list.h"
#include "hardware.h"
#include "utils.h"
#include "my_lib.h"
#include "my_printf.h"
#include "error_handling.h"

void print_del_detail(hardware_t *hardware)
{
    my_printf("%s", hardware->type);
    my_printf(" n°", 4);
    my_printf("%d", hardware->id);
    my_printf(" - \"");
    my_printf("%s", hardware->name);
    my_printf("\" deleted.\n");
}

linked_list_t *return_new_linked_list(linked_list_t *temp,
    linked_list_t *prev, linked_list_t *list, int *test)
{
    if (temp != NULL) {
        prev->next = temp->next;
        print_del_detail(temp->data);
        my_free(2, temp->data, temp);
    } else {
        *test = 1;
        return NULL;
    }
    return list;
}

linked_list_t *pop_from_index(linked_list_t *list, int index, int *test)
{
    linked_list_t *prev = NULL;
    linked_list_t *temp = list;

    if ((list != NULL) && (((hardware_t *)(temp->data))->id == index)) {
        list = temp->next;
        print_del_detail(temp->data);
        my_free(2, temp->data, temp);
        return list;
    }
    while ((temp != NULL) && (((hardware_t *)(temp->data))->id != index)) {
        prev = temp;
        temp = temp->next;
    }
    return return_new_linked_list(temp, prev, list, test);
}

int del(void *data, char **args)
{
    int test = 0;

    if (((device_list_t *)(linked_list_t *)(data))->list == NULL)
        return device_list_empty();
    if (!check_del_args(args))
        return incorrect_argument_in_del_command();
    for (int i = 0; args[i] != NULL; i++) {
        ((device_list_t *)(data))->list =
            pop_from_index(((device_list_t *)(data))->
                list, my_getnbr(args[i]), &test);
        if (test)
            return 84;
    }
    return 0;
}
