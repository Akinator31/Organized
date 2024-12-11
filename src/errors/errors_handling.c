/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** errors
*/

#include <unistd.h>
#include <stdlib.h>

int incorrect_number_of_argument(void)
{
    write(2, "Incorrect number of arguments\n", 31);
    return 84;
}

int incorrect_device_type(void)
{
    write(2, "Incorrect device type\n", 23);
    return 84;
}

int no_argument_is_needed(void)
{
    write(2, "No arguments are needed for the disp command\n", 46);
    return 84;
}

int incorrect_argument_in_del_command(void)
{
    write(2, "Incorrect argument in DEL command\n", 35);
    return 84;
}

int incorrect_arguments_in_sort_command(void)
{
    write(2, "Incorrect argument in sort command\n", 36);
    return 84;
}
