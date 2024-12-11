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

void print_del_detail(hardware_t *hardware)
{
    my_printf("%s", hardware->type);
    my_printf(" n°", 4);
    my_printf("%d", hardware->id);
    my_printf(" - \"");
    my_printf("%s", hardware->name);
    my_printf("\" deleted.\n");
}

linked_list_t *pop_from_index(linked_list_t *list, int index)
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
    if (temp != NULL) {
        prev->next = temp->next;
        print_del_detail(temp->data);
        my_free(2, temp->data, temp);
    }
    return list;
}

int del(void *data, char **args)
{
    if (((device_list_t *)(linked_list_t *)(data))->list == NULL) {
        write(1, "Device list is empty\n", 22);
        return 84;
    }
    if (!check_del_args(args)) {
        write(2, "Incorrect argument in DEL command\n", 35);
        return 84;
    }
    for (int i = 0; args[i] != NULL; i++) {
        ((device_list_t *)(linked_list_t *)(data))->list =
            pop_from_index(((device_list_t *)(linked_list_t *)(data))->
                list, my_getnbr(args[i]));
    }
    return 0;
}
