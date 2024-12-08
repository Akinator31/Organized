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

hardware_t *create_hardware(linked_list_t *list, char *type, char *name)
{
    hardware_t *hardware = malloc(sizeof(hardware_t));

    hardware->type = my_strdup(type);
    hardware->name = my_strdup(name);
    hardware->id = get_unique_id(list);
    return hardware;
}

void print_add_detail(void *data)
{
    my_putstr(((hardware_t *)(*(linked_list_t **)(data))->data)->type);
    write(1, " n°", 4);
    my_put_nbr(((hardware_t *)(*(linked_list_t **)(data))->data)->id);
    write(1, " - \"", 5);
    my_putstr(((hardware_t *)(*(linked_list_t **)(data))->data)->name);
    write(1, "\" added.\n", 10);
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
            *((linked_list_t **)(data)) = push_front_list(
                *((linked_list_t **)(data)), create_hardware(*((
                    linked_list_t **)(data)), args[i], args[i + 1]));
            print_add_detail(data);
            i++;
        } else {
            write(2, "Incorrect device type\n", 23);
            return 84;
        }
    }
    return 0;
}
