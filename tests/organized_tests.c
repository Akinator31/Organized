/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** organized_tests
*/

#include <criterion/criterion.h>
#include "error_handling.h"
#include "utils.h"
#include "my_lib.h"

Test(incorrect_number_of_argument, incorrect_number_of_argument_output)
{
    int result = incorrect_number_of_argument();

    cr_assert_eq(result, 84);
}

Test(incorrect_device_type, incorrect_device_type_output)
{
    int result = incorrect_device_type();

    cr_assert_eq(result, 84);
}

Test(no_argument_is_needed, no_argument_is_needed_output)
{
    int result = no_argument_is_needed();

    cr_assert_eq(result, 84);
}

Test(incorrect_argument_in_del_command, incorrect_argument_in_del_command_output)
{
    int result = incorrect_argument_in_del_command();

    cr_assert_eq(result, 84);
}

Test(incorrect_arguments_in_sort_command, incorrect_arguments_in_sort_command_output)
{
    int result = incorrect_arguments_in_sort_command();

    cr_assert_eq(result, 84);
}

Test(problem_during_alloc, problem_during_alloc_output)
{
    void *result = problem_during_alloc();

    cr_assert_null(result);
}

Test(probleme_device_list_alloc, probleme_device_list_alloc_output)
{
    int result = probleme_device_list_alloc();

    cr_assert_eq(result, 84);
}

Test(device_list_empty, device_list_empty_output)
{
    int result = device_list_empty();

    cr_assert_eq(result, 84);
}
