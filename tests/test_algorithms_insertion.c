#include "unity.h"
#include "../sort.h"
#include <stdlib.h>
#include <string.h>

static listint_t *create_list_from_array(const int *array, size_t size)
{
    listint_t *head = NULL, *node, *tail = NULL;
    for (size_t i = 0; i < size; i++)
    {
        node = malloc(sizeof(listint_t));
        TEST_ASSERT_NOT_NULL_MESSAGE(node, "Memory allocation failed");
        *((int *)&node->n) = array[i];
        node->prev = tail;
        node->next = NULL;
        if (tail)
            tail->next = node;
        else
            head = node;
        tail = node;
    }
    return head;
}

static void free_list(listint_t *head)
{
    listint_t *tmp;
    while (head)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

static void list_to_array(listint_t *head, int *out_array, size_t size)
{
    size_t i = 0;
    while (head && i < size)
    {
        out_array[i++] = head->n;
        head = head->next;
    }
}

/* ---------- Unity required functions ---------- */
void setUp(void) {}
void tearDown(void) {}

/* ---------- Tests ---------- */
void test_insertion_sort_list_basic(void)
{
    int input[] = {5, 2, 8, 1, 3};
    int expected[] = {1, 2, 3, 5, 8};
    size_t size = sizeof(input) / sizeof(input[0]);

    listint_t *list = create_list_from_array(input, size);
    insertion_sort_list(&list);

    int result[size];
    list_to_array(list, result, size);

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, result, size);

    free_list(list);
}

void test_insertion_sort_list_single_element(void)
{
    int input[] = {42};
    int expected[] = {42};
    size_t size = 1;

    listint_t *list = create_list_from_array(input, size);
    insertion_sort_list(&list);

    int result[size];
    list_to_array(list, result, size);

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, result, size);

    free_list(list);
}

void test_insertion_sort_list_already_sorted(void)
{
    int input[] = {1, 2, 3, 4, 5};
    int expected[] = {1, 2, 3, 4, 5};
    size_t size = 5;

    listint_t *list = create_list_from_array(input, size);
    insertion_sort_list(&list);

    int result[size];
    list_to_array(list, result, size);

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, result, size);

    free_list(list);
}

void test_insertion_sort_list_reverse_order(void)
{
    int input[] = {9, 7, 5, 3, 1};
    int expected[] = {1, 3, 5, 7, 9};
    size_t size = 5;

    listint_t *list = create_list_from_array(input, size);
    insertion_sort_list(&list);

    int result[size];
    list_to_array(list, result, size);

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, result, size);

    free_list(list);
}

/* ---------- Main ---------- */
int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_insertion_sort_list_basic);
    RUN_TEST(test_insertion_sort_list_single_element);
    RUN_TEST(test_insertion_sort_list_already_sorted);
    RUN_TEST(test_insertion_sort_list_reverse_order);

    return UNITY_END();
}