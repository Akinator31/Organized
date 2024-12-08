/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** main
*/

#include <stdlib.h>
#include "shell.h"
#include "my_lib.h"
#include "my_list.h"

int main(void)
{
    linked_list_t *list = new_list();

    return workshop_shell(&list);
}
