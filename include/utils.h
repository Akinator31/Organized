/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** utils
*/

#ifndef INCLUDED_UTILS_H
    #define INCLUDED_UTILS_H
    #include "my_list.h"

typedef int (*cmp_func_t)(linked_list_t *first_part,
    linked_list_t *second_part);

int get_nb_args(char **args);
int is_good_type(char *type);
int check_del_args(char **args);
void free_hardware(void *data);
void my_free(int nb_value, ...);
int check_sorting_args(char **args);
int is_a_tags(char *arg);
cmp_func_t *get_tags_func(char **args, int nb_tags);

#endif
