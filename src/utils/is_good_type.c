/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** is_good_type
*/

#include <string.h>
#include <stdlib.h>
#include "my_lib.h"

static const char *type_arr[] = {
    "ACTUATOR",
    "DEVICE",
    "PROCESSOR",
    "SENSOR",
    "WIRE",
    NULL,
};

int is_good_type(char *type)
{
    for (int i = 0; type_arr[i] != NULL; i++) {
        if (my_strcmp(type, type_arr[i]) == 0)
            return 1;
    }
    return 0;
}
