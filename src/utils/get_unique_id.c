/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** get_unique_id
*/

#include <stdlib.h>
#include "my_list.h"
#include "hardware.h"

int get_unique_id(linked_list_t *list)
{
    linked_list_t *temp = list;
    int max_id = 0;

    if (temp == NULL)
        return 0;
    while (temp != NULL) {
        if (((hardware_t *)(temp->data))->id > max_id)
            max_id = ((hardware_t *)(temp->data))->id;
        temp = temp->next;
    }
    return max_id + 1;
}
