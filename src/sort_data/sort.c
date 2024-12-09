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
#include "utils.h"

int compare_by_id(linked_list_t *first_part, linked_list_t *second_part)
{
    if (((hardware_t *)(first_part->data))->id < ((hardware_t *)(second_part->data))->id)
        return 1;
    return 0;
}

int compare_by_type(linked_list_t *first_part, linked_list_t *second_part)
{
    if (my_strcmp(((hardware_t *)(second_part->data))->type, ((hardware_t *)(second_part->data))->type) < 0)
        return 1;
    return 0;
}

int compare_by_name(linked_list_t *first_part, linked_list_t *second_part)
{
    if (my_strcmp(((hardware_t *)(second_part->data))->name, ((hardware_t *)(second_part->data))->name) < 0)
        return 1;
    return 0;
}

linked_list_t *split_list(linked_list_t *list)
{
    linked_list_t *fast = list;
    linked_list_t *slow = list;
    linked_list_t *temp;

    while ((fast != NULL) && (fast->next != NULL)) {
        fast = fast->next->next;
        if (fast != NULL)
            slow = slow->next;
    }
    temp = slow->next;
    slow->next = NULL;
    return temp;
}

linked_list_t *merge_linked_list(linked_list_t *first_part, linked_list_t *second_part, int (*compare_func)(linked_list_t *first_part, linked_list_t *second_part))
{
    if (first_part == NULL)
        return second_part;
    if (second_part == NULL)
        return first_part;
    if (compare_func(first_part, second_part)) {
        first_part->next = merge_linked_list(first_part->next, second_part, compare_func);
        return first_part;
    } else {
        second_part->next = merge_linked_list(second_part->next, first_part, compare_func);
        return second_part;
    }
}

linked_list_t *merge_linked_list_reverse(linked_list_t *first_part, linked_list_t *second_part, int (*compare_func)(linked_list_t *first_part, linked_list_t *second_part))
{
    if (first_part == NULL)
        return second_part;
    if (second_part == NULL)
        return first_part;
    if (!compare_func(first_part, second_part)) {
        second_part->next = merge_linked_list_reverse(second_part->next, first_part, compare_func);
        return second_part;
    } else {
        first_part->next = merge_linked_list_reverse(first_part->next, second_part, compare_func);
        return first_part;
    }
}

linked_list_t *merge_sort_list(linked_list_t *list, int (*compare_func)(linked_list_t *first_part, linked_list_t *second_part))
{
    linked_list_t *second_part;

    if ((list == NULL) || (list->next == NULL))
        return list;
    second_part = split_list(list);
    list = merge_sort_list(list, compare_func);
    second_part = merge_sort_list(second_part, compare_func);
    return merge_linked_list(list, second_part, compare_func);
}

int sort(void *data, char **args)
{
    if (check_sorting_args(args) == 84)
        return 84;
    *((linked_list_t **)(data)) = merge_sort_list(*((linked_list_t **)(data)), &compare_by_name);
    return 0;
}
