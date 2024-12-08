/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** utils
*/

#ifndef INCLUDED_UTILS_H
    #define INCLUDED_UTILS_H
    #include "my_list.h"

int get_nb_args(char **args);
int get_unique_id(linked_list_t *list);
int is_good_type(char *type);
int check_del_args(char **args);
void free_hardware(void *data);
void my_free(int nb_value, ...);

#endif
