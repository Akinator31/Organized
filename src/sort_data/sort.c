/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** sort
*/

#include <stdlib.h>
#include "shell.h"
#include "my_list.h"
#include "hardware.h"
#include "my_lib.h"
#include <utils.h>

int compare_data(linked_list_t *first_part,
    linked_list_t *second_part, cmp_func_t *p)
{
    int result = 0;

    for (int i = 0; p[i] != NULL; i++) {
        result = (*p[i])(first_part, second_part);
        if (result == 2)
            continue;
        return result;
    }
}

linked_list_t *split_list(linked_list_t *list)
{
    linked_list_t *first_part = list;
    linked_list_t *second_part = list;
    linked_list_t *temp;

    while ((first_part != NULL) && (first_part->next != NULL)) {
        first_part = first_part->next->next;
        if (first_part != NULL)
            second_part = second_part->next;
    }
    temp = second_part->next;
    second_part->next = NULL;
    return temp;
}

linked_list_t *merge_linked_list(linked_list_t *first_part,
    linked_list_t *second_part, cmp_func_t *p)
{
    if (first_part == NULL)
        return second_part;
    if (second_part == NULL)
        return first_part;
    if (compare_data(first_part, second_part, p)) {
        first_part->next = merge_linked_list(
            first_part->next, second_part, p);
        return first_part;
    } else {
        second_part->next = merge_linked_list(
            second_part->next, first_part, p);
        return second_part;
    }
}

linked_list_t *merge_sort_list(linked_list_t *list, cmp_func_t *p)
{
    linked_list_t *second_part;

    if ((list == NULL) || (list->next == NULL))
        return list;
    second_part = split_list(list);
    list = merge_sort_list(list, p);
    second_part = merge_sort_list(second_part, p);
    return merge_linked_list(list, second_part, p);
}

int sort(void *data, char **args)
{
    int nb_tags = check_sorting_args(args);
    cmp_func_t *tags_arr = NULL;

    if (nb_tags == 84)
        return 84;
    tags_arr = get_tags_func(args, nb_tags);
    *((linked_list_t **)(data)) =
        merge_sort_list(*((linked_list_t **)(data)), tags_arr);
    free(tags_arr);
    return 0;
}
