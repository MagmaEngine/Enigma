#include "../src/e_math.c"
#include <stdio.h>

float tolerance = 0.0001;

int test_float_equality(float a, float b)
{
	float diff = a - b;
	if (diff > tolerance || diff < -tolerance)
		return 1;
	return 0;
}

int test_e_sqrtf(float a, float out)
{
	float b = e_sqrtf(a);
	if (test_float_equality(b, out))
	{
		printf("%s, %s: Test failed for: %f. Expected %f, but got %f", __FILE__, __FUNCTION__, a, out, b);
		return 1;
	}
	return 0;
}

int test_e_length2f(float a, float b, float c)
{
	float *i = malloc(sizeof *i * 2);
	i[0] = a;
	i[1] = b;
	float out = e_length2f(i);
	if (test_float_equality(out, c))
	{
		printf("%s, %s: Test failed for: (%f, %f). Expected %f, but got %f", __FILE__, __FUNCTION__, a, b, c, out);
		free(i);
		return 1;
	}
	free(i);
	return 0;
}

int test_e_distance2f(float a, float b, float c, float d, float out)
{
	float *i = malloc(sizeof *i * 2);
	i[0] = a;
	i[1] = b;
	float *j = malloc(sizeof *j * 2);
	j[0] = c;
	j[1] = d;
	if (test_float_equality(e_distance2f(i, j), out))
	{
		printf("%s, %s: Test failed for: (%f, %f), (%f, %f)", __FILE__, __FUNCTION__, a, b, c, d);
		free(i);
		free(j);
		return 1;
	}
	free(i);
	free(j);
	return 0;
}

int test_e_dot2f(float a, float b, float c, float d, float out)
{
	float *i = malloc(sizeof *i * 2);
	i[0] = a;
	i[1] = b;
	float *j = malloc(sizeof *j * 2);
	j[0] = c;
	j[1] = d;
	if (test_float_equality(e_dot2f(i, j), out))
	{
		printf("%s, %s: Test failed for: %f, %f, %f, %f", __FILE__, __FUNCTION__, a, b, c, d);
		free(i);
		free(j);
		return 1;
	}
	free(i);
	free(j);
	return 0;
}

int test_e_cross2f(float a, float b, float c, float d, float out)
{
	float *i = malloc(sizeof *i * 2);
	i[0] = a;
	i[1] = b;
	float *j = malloc(sizeof *j * 2);
	j[0] = c;
	j[1] = d;
	float *k = malloc(sizeof *k);
	e_cross2f(k, i, j);
	if (test_float_equality(*k, out))
	{
		printf("%s, %s: Test failed for: (%f, %f), (%f, %f). Expected %f, but got %f",
				__FILE__, __FUNCTION__, a, b, c, d, out, *k);
		free(i);
		free(j);
		free(k);
		return 1;
	}
	free(i);
	free(j);
	free(k);
	return 0;
}

int test_e_normalize2f(float a, float b, float out0, float out1)
{
	float *i = malloc(sizeof *i * 2);
	i[0] = a;
	i[1] = b;
	e_normalize2f(i);
	if (test_float_equality(i[0], out0) || test_float_equality(i[1], out1))
	{
		printf("%s, %s: Test failed for: (%f, %f). Expected (%f, %f), but got (%f, %f)",
				__FILE__, __FUNCTION__, a, b, out0, out1, i[0], i[1]);
		free(i);
		return 1;
	}
	free(i);
	return 0;
}

int test_e_reflect2f(float a, float b, float c, float d, float out0, float out1)
{
	float *pos = malloc(sizeof *pos * 2);
	pos[0] = a;
	pos[1] = b;
	float *normal = malloc(sizeof *normal * 2);
	normal[0] = c;
	normal[1] = d;
	float *k = malloc(sizeof *k * 2);
	e_reflect2f(k, pos, normal);
	if (test_float_equality(k[0], out0) || test_float_equality(k[1], out1))
	{
		printf("%s, %s: Test failed for: (%f, %f), (%f, %f). Expected (%f, %f), but got (%f, %f)",
				__FILE__, __FUNCTION__, a, b, c, d, out0, out1, k[0], k[1]);
		free(pos);
		free(normal);
		free(k);
		return 1;
	}
	free(pos);
	free(normal);
	free(k);
	return 0;
}

int test_e_flatten2f(float a, float b, float c, float d, float out0, float out1)
{
	float *pos = malloc(sizeof *pos * 2);
	pos[0] = a;
	pos[1] = b;
	float *normal = malloc(sizeof *normal * 2);
	normal[0] = c;
	normal[1] = d;
	float *k = malloc(sizeof *k * 2);
	e_flatten2f(k, pos, normal);
	if (test_float_equality(k[0], out0) || test_float_equality(k[1], out1))
	{
		printf("%s, %s: Test failed for: (%f, %f), (%f, %f). Expected (%f, %f), but got (%f, %f)",
				__FILE__, __FUNCTION__, a, b, c, d, out0, out1, k[0], k[1]);
		free(pos);
		free(normal);
		free(k);
		return 1;
	}
	free(pos);
	free(normal);
	free(k);
	return 0;
}

int main(void)
{
	// test e_sqrtf
	for (float i = 0; i < 10; i += 0.1)
	{
		if (test_e_sqrtf(i*i, i))
			return 1;
	}

	if (
			test_e_length2f(3, 4, 5) ||
			test_e_distance2f(3, 4, 3, 4, 0) ||
			test_e_distance2f(0, 5, 0, 0, 5) ||
			test_e_distance2f(-5, 0, 0, 0, 5) ||
			test_e_dot2f(1, 2, 1, 5, 11) ||
			test_e_cross2f(1, 2, 3, 4, -2) ||
			test_e_cross2f(1, 0, 3, 0, 0) ||
			test_e_cross2f(-1, -3, 2, 4, 2) ||
			test_e_normalize2f(1, 1, sqrt(2.f)/2, sqrt(2.f)/2) ||
			test_e_normalize2f(-1, 1, -sqrt(2.f)/2, sqrt(2.f)/2) ||
			test_e_normalize2f(0, 1, 0, 1) ||
			test_e_reflect2f(1, 2, 3, -4, 31, -38) ||
			test_e_reflect2f(1, 0, sqrt(2.f)/2, sqrt(2.f)/2, 0, -1) ||
		0)
		return 1;


	return 0;
}
