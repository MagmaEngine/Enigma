#include "enigma.h"
#include <stdio.h>

float tolerance = 0.0001;

int test_float_equality(float a, float b)
{
	float diff = a - b;
	if (diff > tolerance || diff < -tolerance)
		return 1;
	return 0;
}

int main(void)
{
	EDynarr *test = e_dynarr_init(sizeof(float), 1);
	float firstnum = 1.1;
	float secondnum = 2.05;
	float fifthnum = 5.64;
	e_dynarr_add(test, &firstnum);
	e_dynarr_add(test, &secondnum);
	e_dynarr_add(test, &(float){PI});
	e_dynarr_add(test, &(float){4.78});
	e_dynarr_add(test, &fifthnum);

	// first number should be 1.1
	void *arr = e_dynarr_get_arr(test);
	if (test_float_equality( ((float *)arr)[0], firstnum))
	{
		fprintf(stderr, "%s, %s: Test failed. Expected %f, but got %f", __FILE__, __func__, firstnum, ((float *)arr)[0]);
		return 1;
	}

	e_dynarr_remove_unordered(test, 50);
	e_dynarr_remove_unordered(test, 0);
	e_dynarr_remove_unordered(test, 1);
	e_dynarr_remove_unordered(test, 2);

	// should only be 2 items in array
	if (e_dynarr_item_count(test) != 2)
	{
		fprintf(stderr, "%s, %s: Test failed. Expected %i, but got %i", __FILE__, __func__, 2, e_dynarr_item_count(test));
		return 1;
	}

	e_dynarr_deinit(test);

	test = e_dynarr_init(sizeof(float), 1);
	e_dynarr_add(test, &firstnum);
	e_dynarr_add(test, &secondnum);
	e_dynarr_add(test, &(float){PI});
	e_dynarr_add(test, &(float){4.78});
	e_dynarr_add(test, &fifthnum);

	// first number should be 1.1
	arr = e_dynarr_get_arr(test);
	if (test_float_equality( ((float *)arr)[0], firstnum))
	{
		fprintf(stderr, "%s, %s: Test failed. Expected %f, but got %f", __FILE__, __func__, firstnum, ((float *)arr)[0]);
		return 1;
	}

	e_dynarr_remove_ordered(test, 50);
	e_dynarr_remove_ordered(test, 0);
	e_dynarr_remove_ordered(test, 1);
	e_dynarr_remove_ordered(test, 2);

	// should only be 2 items in array
	if (e_dynarr_item_count(test) != 2)
	{
		fprintf(stderr, "%s, %s: Test failed. Expected %i, but got %i", __FILE__, __func__, 2, e_dynarr_item_count(test));
		return 1;
	}
	// first number should be 2.05
	arr = e_dynarr_get_arr(test);
	if (test_float_equality( ((float *)arr)[0], secondnum))
	{
		fprintf(stderr, "%s, %s: Test failed. Expected %f, but got %f", __FILE__, __func__, secondnum, ((float *)arr)[0]);
		return 1;
	}

	e_dynarr_add(test, &(float){4.78});
	e_dynarr_add(test, &(float){5.64});
	e_dynarr_add(test, &(float){4.78});
	e_dynarr_add(test, &(float){5.64});
	e_dynarr_add(test, &(float){4.78});
	e_dynarr_add(test, &(float){5.64});

	// should only be 8 items in array
	if (e_dynarr_item_count(test) != 8)
	{
		fprintf(stderr, "%s, %s: Test failed. Expected %i, but got %i", __FILE__, __func__, 8, e_dynarr_item_count(test));
		return 1;
	}

	e_dynarr_deinit(test);

	// test e_dynarr_init_arr, e_dynarr_find, and e_dynarr_set
	int *array = malloc(5 * sizeof(int));
	array[0] = 0;
	array[1] = 1;
	array[2] = 2;
	array[3] = 3;
	array[4] = 4;
	test = e_dynarr_init_arr(sizeof(int), 5, array);
	if (e_dynarr_find(test, E_VOID_PTR_FROM_VALUE(int, 4)) != 4)
	{
		fprintf(stderr, "%s, %s: Test failed. Expected %i, but got %i", __FILE__, __func__, 4,
				e_dynarr_find(test, E_VOID_PTR_FROM_VALUE(int, 4)));
		return 1;
	}
	e_dynarr_set(test, 4, E_VOID_PTR_FROM_VALUE(int, 5));
	if (e_dynarr_find(test, E_VOID_PTR_FROM_VALUE(int, 5)) != 4)
	{
		fprintf(stderr, "%s, %s: Test failed. Expected %i, but got %i", __FILE__, __func__, 4,
				e_dynarr_find(test, E_VOID_PTR_FROM_VALUE(int, 5)));
		return 1;
	}
	e_dynarr_deinit(test);

	return 0;
}
