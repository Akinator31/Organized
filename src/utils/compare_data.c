/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** compare_data
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hardware.h"
#include "my_list.h"
#include "utils.h"
#include "my_lib.h"

static int compare_by_id(linked_list_t *first_part,
    linked_list_t *second_part)
{
    hardware_t *hardware_1 = ((hardware_t *)(first_part->data));
    hardware_t *hardware_2 = ((hardware_t *)(second_part->data));

    if (hardware_1->id < hardware_2->id)
        return 1;
    if (hardware_1->id == hardware_2->id)
        return 2;
    return 0;
}

static int compare_by_id_reversed(linked_list_t *first_part,
    linked_list_t *second_part)
{
    hardware_t *hardware_1 = ((hardware_t *)(first_part->data));
    hardware_t *hardware_2 = ((hardware_t *)(second_part->data));

    if (hardware_1->id < hardware_2->id)
        return 0;
    if (hardware_1->id == hardware_2->id)
        return 2;
    return 1;
}

static int compare_by_type(linked_list_t *first_part,
    linked_list_t *second_part)
{
    hardware_t *hardware_1 = ((hardware_t *)(first_part->data));
    hardware_t *hardware_2 = ((hardware_t *)(second_part->data));

    if (my_strcmp(hardware_1->type, hardware_2->type) < 0)
        return 1;
    if (my_strcmp(hardware_1->type, hardware_2->type) == 0)
        return 2;
    return 0;
}

static int compare_by_type_reversed(linked_list_t *first_part,
    linked_list_t *second_part)
{
    hardware_t *hardware_1 = ((hardware_t *)(first_part->data));
    hardware_t *hardware_2 = ((hardware_t *)(second_part->data));

    if (my_strcmp(hardware_1->type, hardware_2->type) < 0)
        return 0;
    if (my_strcmp(hardware_1->type, hardware_2->type) == 0)
        return 2;
    return 1;
}

static int compare_by_name(linked_list_t *first_part,
    linked_list_t *second_part)
{
    hardware_t *hardware_1 = ((hardware_t *)(first_part->data));
    hardware_t *hardware_2 = ((hardware_t *)(second_part->data));

    if (my_strcmp(hardware_1->name, hardware_2->name) < 0)
        return 1;
    if (my_strcmp(hardware_1->name, hardware_2->name) == 0)
        return 2;
    return 0;
}

static int compare_by_name_reversed(linked_list_t *first_part,
    linked_list_t *second_part)
{
    hardware_t *hardware_1 = ((hardware_t *)(first_part->data));
    hardware_t *hardware_2 = ((hardware_t *)(second_part->data));

    if (my_strcmp(hardware_1->name, hardware_2->name) < 0)
        return 0;
    if (my_strcmp(hardware_1->name, hardware_2->name) == 0)
        return 2;
    return 1;
}

int reverse_tags(char *args, char *next_args, cmp_func_t *tags_ptr, int *cmpt)
{
    if (is_a_tags(args) && (my_strcmp(args, "ID") == 0) &&
        (next_args != NULL) && (my_strcmp(next_args, "-r") == 0)) {
        tags_ptr[*cmpt] = &compare_by_id_reversed;
        *cmpt += 1;
        return 1;
    }
    if (is_a_tags(args) && (my_strcmp(args, "TYPE") == 0) &&
        (next_args != NULL) && (my_strcmp(next_args, "-r") == 0)) {
        tags_ptr[*cmpt] = &compare_by_type_reversed;
        *cmpt += 1;
        return 1;
    }
    if (is_a_tags(args) && (my_strcmp(args, "NAME") == 0) &&
        (next_args != NULL) && (my_strcmp(next_args, "-r") == 0)) {
        tags_ptr[*cmpt] = &compare_by_name_reversed;
        *cmpt += 1;
        return 1;
    }
    return 0;
}

int normal_tags(char *args, cmp_func_t *tags_ptr, int *cmpt)
{
    if (is_a_tags(args) && (my_strcmp(args, "ID") == 0)) {
        tags_ptr[*cmpt] = &compare_by_id;
        *cmpt += 1;
    }
    if (is_a_tags(args) && (my_strcmp(args, "TYPE") == 0)) {
        tags_ptr[*cmpt] = &compare_by_type;
        *cmpt += 1;
    }
    if (is_a_tags(args) && (my_strcmp(args, "NAME") == 0)) {
        tags_ptr[*cmpt] = &compare_by_name;
        *cmpt += 1;
    }
}

cmp_func_t *get_tags_func(char **args, int nb_tags)
{
    cmp_func_t *tags_ptr = malloc(sizeof(cmp_func_t *) * (nb_tags + 1));
    int cmpt = 0;

    memset(tags_ptr, 0, sizeof(cmp_func_t *) * (nb_tags + 1));
    for (int i = 0; args[i] != NULL; i++) {
        if (reverse_tags(args[i], args[i + 1], tags_ptr, &cmpt))
            continue;
        normal_tags(args[i], tags_ptr, &cmpt);
    }
    return tags_ptr;
}
