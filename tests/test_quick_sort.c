#include "../Unity/unity.h"
#include "../sort.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_quick_sort(void)
{
	int tabTest[10] = {5, 10, 20, 8, 47, 100, 35, 46, 1, 0};
	int expect[10] = {0, 1, 5, 8, 10, 20, 35, 46, 47, 100};

	quick_sort(tabTest, 10);
	TEST_ASSERT_EQUAL_INT_ARRAY(expect, tabTest, 10);
}

void test_quick_sort_null(void)
{
	quick_sort(NULL, 10);
	TEST_ASSERT_TRUE(1);
}

void test_quick_sort_single_elem(void)
{
	int tab[1] = {10};
	int expected[1] = {10};

	quick_sort(tab, 1);	
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, tab, 1);
}

void test_quick_sort_already_sorted(void)
{
	int test[10] = {0, 1, 5, 8, 10, 20, 35, 46, 47, 100};
	int expect[10] = {0, 1, 5, 8, 10, 20, 35, 46, 47, 100};
	
	quick_sort(test, 10);
	TEST_ASSERT_EQUAL_INT_ARRAY(expect, test, 10);
}

void test_quick_sort_duplicate(void)
{
	int duplicate[10] = {0, 46, 5, 8, 100, 20, 35, 46, 47, 100};
	int expect[10] = {0, 5, 8, 20, 35, 46, 46, 47, 100, 100};

	quick_sort(duplicate, 10);
	TEST_ASSERT_EQUAL_INT_ARRAY(expect, duplicate, 10);
}

void test_quick_sort_reverse(void)
{
	int reverse[10] = {100, 47, 46, 35, 20, 10, 8, 5, 1, 0};
	int expect[10] = {0, 1, 5, 8, 10, 20, 35, 46, 47, 100};
	
	quick_sort(reverse, 10);
	TEST_ASSERT_EQUAL_INT_ARRAY(expect, reverse, 10);
}
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_quick_sort);
	RUN_TEST(test_quick_sort_null);
	RUN_TEST(test_quick_sort_single_elem);
	RUN_TEST(test_quick_sort_already_sorted);
	RUN_TEST(test_quick_sort_duplicate);
	RUN_TEST(test_quick_sort_reverse);
    return UNITY_END();
}

