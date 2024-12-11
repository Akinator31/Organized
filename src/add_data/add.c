/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** add
*/

#include <unistd.h>
#include <stdlib.h>
#include "shell.h"
#include "my_lib.h"
#include "utils.h"
#include "hardware.h"
#include "my_printf.h"

hardware_t *create_hardware(linked_list_t *list, char *type,
    char *name, void *data)
{
    hardware_t *hardware = malloc(sizeof(hardware_t));

    hardware->type = my_strdup(type);
    hardware->name = my_strdup(name);
    hardware->id = ((device_list_t *)(data))->id;
    return hardware;
}

void print_add_detail(device_list_t *data, int *i)
{
    hardware_t *hardware = (hardware_t *)((linked_list_t *)(data)->list)->data;

    my_printf("%s", hardware->type);
    my_printf(" n°");
    my_printf("%d", data->id);
    my_printf(" - \"");
    my_printf("%s", hardware->name);
    my_printf("\" added.\n");
    *i += 1;
}

int add(void *data, char **args)
{
    int nb_args = get_nb_args(args);

    if ((nb_args % 2) != 0) {
        write(2, "Incorrect number of arguments\n", 31);
        return 84;
    }
    for (int i = 0; i < nb_args; i++) {
        if (is_good_type(args[i])) {
            ((device_list_t *)(linked_list_t *)(data))->list = push_front_list(
                ((device_list_t *)(linked_list_t *)(data))->list,
                create_hardware(((device_list_t *)(linked_list_t *)(data))->
                list, args[i], args[i + 1], data));
            print_add_detail(data, &i);
            ((device_list_t *)(linked_list_t *)(data))->id += 1;
        } else {
            write(2, "Incorrect device type\n", 23);
            return 84;
        }
    }
    return 0;
}
