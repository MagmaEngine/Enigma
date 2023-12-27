#include "../include/enigma.h"

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
	if (test_float_equality( ((float *)test->arr)[0], firstnum))
	{
		e_log_message(E_LOG_ERROR, L"Test", L"%s, %s: Test failed. Expected %f, but got %f", __FILE__, __func__, firstnum, ((float *)test->arr)[0]);
		return 1;
	}

	e_dynarr_remove_unordered(test, 50);
	e_dynarr_remove_unordered(test, 0);
	e_dynarr_remove_unordered(test, 1);
	e_dynarr_remove_unordered(test, 2);

	// should only be 2 items in array
	if (test->num_items != 2)
	{
		e_log_message(E_LOG_ERROR, L"Test", L"%s, %s: Test failed. Expected %i, but got %i", __FILE__, __func__, 2, test->num_items);
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
	if (test_float_equality( ((float *)test->arr)[0], firstnum))
	{
		e_log_message(E_LOG_ERROR, L"Test", L"%s, %s: Test failed. Expected %f, but got %f", __FILE__, __func__, firstnum, ((float *)test->arr)[0]);
		return 1;
	}

	e_dynarr_remove_ordered(test, 50);
	e_dynarr_remove_ordered(test, 0);
	e_dynarr_remove_ordered(test, 1);
	e_dynarr_remove_ordered(test, 2);

	// should only be 2 items in array
	if (test->num_items != 2)
	{
		e_log_message(E_LOG_ERROR, L"Test", L"%s, %s: Test failed. Expected %i, but got %i", __FILE__, __func__, 2, test->num_items);
		return 1;
	}
	// first number should be 2.05
	if (test_float_equality( ((float *)test->arr)[0], secondnum))
	{
		e_log_message(E_LOG_ERROR, L"Test", L"%s, %s: Test failed. Expected %f, but got %f", __FILE__, __func__, secondnum, ((float *)test->arr)[0]);
		return 1;
	}

	e_dynarr_add(test, &(float){4.78});
	e_dynarr_add(test, &(float){5.64});
	e_dynarr_add(test, &(float){4.78});
	e_dynarr_add(test, &(float){5.64});
	e_dynarr_add(test, &(float){4.78});
	e_dynarr_add(test, &(float){5.64});

	// should only be 8 items in array
	if (test->num_items != 8)
	{
		e_log_message(E_LOG_ERROR, L"Test", L"%s, %s: Test failed. Expected %i, but got %i", __FILE__, __func__, 8, test->num_items);
		return 1;
	}

	e_dynarr_deinit(test);
	return 0;
}
