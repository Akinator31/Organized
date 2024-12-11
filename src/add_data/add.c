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
#include "error_handling.h"

hardware_t *create_hardware(linked_list_t *list, char *type,
    char *name, void *data)
{
    hardware_t *hardware = malloc(sizeof(hardware_t));

    if (hardware == NULL)
        return problem_during_alloc();
    hardware->type = my_strdup(type);
    hardware->name = my_strdup(name);
    hardware->id = ((device_list_t *)(data))->id;
    return hardware;
}

int print_add_detail(device_list_t *data, int *i, int *checker)
{
    linked_list_t *list = (linked_list_t *)(data);
    hardware_t *hardware = NULL;

    if (list == NULL) {
        *checker = 84;
        return 84;
    }
    hardware = (hardware_t *)((linked_list_t *)(data)->list)->data;
    my_printf("%s", hardware->type);
    my_printf(" n°");
    my_printf("%d", data->id);
    my_printf(" - \"");
    my_printf("%s", hardware->name);
    my_printf("\" added.\n");
    *i += 1;
    return 0;
}

int add(void *data, char **args)
{
    int nb_args = get_nb_args(args);
    device_list_t *dvice = (device_list_t *)(data);
    int checker = 0;

    if ((nb_args % 2) != 0)
        return incorrect_number_of_argument();
    for (int i = 0; (i < nb_args) && (checker != 84); i++) {
        if (is_good_type(args[i])) {
            dvice->list = push_front_list(dvice->list,
                create_hardware(dvice->list, args[i], args[i + 1], data));
            print_add_detail(data, &i, &checker);
            ((device_list_t *)(linked_list_t *)(data))->id += 1;
        } else {
            return incorrect_device_type();
        }
    }
    return 0;
}
