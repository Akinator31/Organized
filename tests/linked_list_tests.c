/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** linked_list_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include <math.h>
#include "my_lib.h"
#include "my_list.h"
#include "units_test.h"

Test(push_front_list, classic_linked_list_test)
{
    linked_list_t *list = new_list();
    linked_list_t *temp = NULL;
    int data = 42;
    int result = 0;

    list = push_front_list(list, &data);
    temp = list;

    while (temp != NULL) {
        result = *(int *)temp->data;
        temp = temp->next;
    }
    cr_assert_eq(result, 42);
    free(list);
}

Test(push_front_list, classic_linked_list_test_with_null_value)
{
    linked_list_t *list = new_list();
    linked_list_t *temp = NULL;

    list = push_front_list(list, NULL);
    cr_assert_null(list);
}

Test(push_front_list_all, classic_push_front_all)
{
    linked_list_t *list = new_list();
    linked_list_t *temp = NULL;
    int data1 = 12;
    int data2 = 13;
    int data3 = 14;
    int result[3] = {0};
    int expected[3] = {14, 13, 12};
    int i = 0;

    list = push_front_list_all(list, 3, &data1, &data2, &data3);
    temp = list;
    while (temp != NULL) {
        result[i] = *(int *)temp->data;
        temp = temp->next;
        i++;
    }
    cr_assert_arr_eq(result, expected, 3);
}

Test(push_back_list, classic_linked_list_test_push_back)
{
    linked_list_t *list = new_list();
    linked_list_t *temp = NULL;
    int data = 42;
    int result = 0;

    list = push_back_list(list, &data);
    temp = list;

    while (temp != NULL) {
        result = *(int *)temp->data;
        temp = temp->next;
    }
    cr_assert_eq(result, 42);
    free(list);
}

Test(push_back_list, multi_linked_list_test_push_back)
{
    linked_list_t *list = new_list();
    linked_list_t *temp = NULL;
    int data = 42;
    int data1 = 45;
    int result = 0;

    list = push_back_list(list, &data);
    list = push_back_list(list, &data1);
    temp = list;

    while (temp != NULL) {
        result = *(int *)temp->data;
        temp = temp->next;
    }
    cr_assert_eq(result, 45);
    free(list);
}

Test(my_rev_list, linked_list_reverse)
{
    linked_list_t *list = new_list();
    linked_list_t *temp = NULL;
    int data = 42;
    int data1 = 45;
    int result = 0;

    list = push_back_list(list, &data);
    list = push_back_list(list, &data1);
    my_rev_list(&list);
    temp = list;

    while (temp != NULL) {
        result = *(int *)temp->data;
        temp = temp->next;
    }
    cr_assert_eq(result, 42);
    free(list);   
}

Test(clear_list, test_clear_linked_list)
{
    linked_list_t *list = new_list();
    int *data = (int *)malloc(sizeof(int));

    *data = 84;
    list = push_front_list(list, data);
    list = clear_list(list, free);
    cr_assert_null(list);
}

Test(pop_front_list, test_pop_from_linked_list)
{
    linked_list_t *list = new_list();
    linked_list_t *temp = NULL;
    int *data = (int *)malloc(sizeof(int));
    int *data1 = (int *)malloc(sizeof(int));
    int result = 0;

    *data = 84;
    *data1 = 42;
    list = push_front_list(list, data);
    list = push_back_list(list, data1);
    list = pop_front_list(list, free);
    temp = list;
    while (temp != NULL) {
        result = *(int *)temp->data;
        temp = temp->next;
    }
    cr_assert_eq(result, 42);
}

Test(pop_front_list, null_list)
{
    linked_list_t *list = new_list();

    list = pop_front_list(list, free);
    cr_assert_null(list);
}

Test(pop_front_list, one_element_list)
{
    linked_list_t *list = new_list();
    int *data = (int *)malloc(sizeof(int));
    *data = 67;

    list = push_front_list(list, data);
    list = pop_front_list(list, free);
    cr_assert_null(list);
}
