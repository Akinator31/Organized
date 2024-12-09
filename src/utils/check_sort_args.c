/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** check_sort_args
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_lib.h"

static const char *sorting_tags[] = {
    "TYPE",
    "NAME",
    "ID"
};

int is_a_tags(char *arg)
{
    for (int i = 0; sorting_tags[i] != NULL; i++) {
        if (my_strcmp(sorting_tags[i], arg) == 0)
            return 1;
    }
    return 0;
}

int check_sorting_args(char **args)
{
    if (*args == NULL) {
        write(2, "No argument in sort command\n", 29);
        return 84;
    }
    if (my_strcmp(args[0], "-r") == 0) {
        write(2, "Incorrect argument in sort command\n", 36);
        return 84;
    }
    for (int i = 0; args[i] != NULL; i++) {
        if (is_a_tags(args[i]) && (args[i + 1] != NULL) && (my_strcmp(args[i + 1], "-r") == 0)) {
            i++;
            continue;
        }
        if (is_a_tags(args[i]))
            continue;
        else
            return 84;
    }
    return 1;
}
