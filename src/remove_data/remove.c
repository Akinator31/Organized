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

void print_del_detail(hardware_t *hardware)
{
    my_putstr(hardware->type);
    write(1, " n°", 4);
    my_put_nbr(hardware->id);
    write(1, " - \"", 5);
    my_putstr(hardware->name);
    write(1, "\" deleted.\n", 12);
}

linked_list_t *pop_from_index(linked_list_t *list, int index)
{
    linked_list_t *prev = NULL;
    linked_list_t *temp = list;

    if (((hardware_t *)(temp->data))->id == index) {
        list = temp->next;
        print_del_detail(temp->data);
        my_free(2, temp->data, temp);
        return list;
    }
    while ((temp != NULL) && (((hardware_t *)(temp->data))->id != index)) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        prev->next = temp->next;
        print_del_detail(temp->data);
        my_free(2, temp->data, temp);
    }
    return list;
}

int del(void *data, char **args)
{
    if (*((linked_list_t **)(data)) == NULL) {
        write(1, "Device list is empty\n", 22);
        return 0;
    }
    if (!check_del_args(args)) {
        write(2, "Incorrect argument in DEL command\n", 35);
        return 84;
    }
    for (int i = 0; args[i] != NULL; i++) {
        *((linked_list_t **)(data)) =
            pop_from_index(*((linked_list_t **)(data)), my_getnbr(args[i]));
    }
    return 0;
}
