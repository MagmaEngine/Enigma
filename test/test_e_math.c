#include "enigma.h"
#include <stdio.h>
#include <math.h>

float tolerance = 0.0001;

int test_float_equality(float a, float b)
{
	float diff = a - b;
	if (diff > tolerance || diff < -tolerance)
		return 1;
	return 0;
}
int test_double_equality(double a, double b)
{
	double diff = a - b;
	if (diff > tolerance || diff < -tolerance)
		return 1;
	return 0;
}

int test_e_sqrtf(float a, float out)
{
	float b = e_sqrtf(a);
	if (test_float_equality(b, out))
	{
		fprintf(stderr, "%s, %s: Test failed for: %f. Expected %f, but got %f", __FILE__, __func__, a, out, b);
		return 1;
	}
	return 0;
}

// ---------- 2D floats -----------
int test_e_length2f(float a, float b, float c)
{
	float *i = malloc(sizeof *i * 2);
	i[0] = a;
	i[1] = b;
	float out = e_length2f(i);
	if (test_float_equality(out, c))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f). Expected %f, but got %f", __FILE__, __func__, a, b, c, out);
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
	float result = e_distance2f(i, j);
	if (test_float_equality(result, out))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f), (%f, %f). Expected %f, but got %f",
				__FILE__, __func__, a, b, c, d, out, result);
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
	float result = e_dot2f(i, j);
	if (test_float_equality(result, out))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f), (%f, %f). Expected %f, but got %f",
				__FILE__, __func__, a, b, c, d, out, result);
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
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f), (%f, %f). Expected %f, but got %f",
				__FILE__, __func__, a, b, c, d, out, *k);
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
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f). Expected (%f, %f), but got (%f, %f)",
				__FILE__, __func__, a, b, out0, out1, i[0], i[1]);
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
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f), (%f, %f). Expected (%f, %f), but got (%f, %f)",
				__FILE__, __func__, a, b, c, d, out0, out1, k[0], k[1]);
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

int test_e_project2f(float a, float b, float c, float d, float out0, float out1)
{
	float *pos = malloc(sizeof *pos * 2);
	pos[0] = a;
	pos[1] = b;
	float *normal = malloc(sizeof *normal * 2);
	normal[0] = c;
	normal[1] = d;
	float *k = malloc(sizeof *k * 2);
	e_project2f(k, pos, normal);
	if (test_float_equality(k[0], out0) || test_float_equality(k[1], out1))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f), (%f, %f). Expected (%f, %f), but got (%f, %f)",
				__FILE__, __func__, a, b, c, d, out0, out1, k[0], k[1]);
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

int test_e_normal2f(float a, float b, float c, float d, float out0, float out1)
{
	float *veca = malloc(sizeof *veca * 2);
	veca[0] = a;
	veca[1] = b;
	float *vecb = malloc(sizeof *vecb * 2);
	vecb[0] = c;
	vecb[1] = d;
	float *k = malloc(sizeof *k * 2);
	e_normal2f(k, veca, vecb);
	if (test_float_equality(k[0], out0) || test_float_equality(k[1], out1))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f), (%f, %f). Expected (%f, %f), but got (%f, %f)",
				__FILE__, __func__, a, b, c, d, out0, out1, k[0], k[1]);
		free(veca);
		free(vecb);
		free(k);
		return 1;
	}
	free(veca);
	free(vecb);
	free(k);
	return 0;
}
int test_e_intersect2f(float a, float b, float c, float d, float e, float f, float g, float h, float out0, float out1)
{
	float *pa1 = malloc(sizeof *pa1 * 2);
	pa1[0] = a;
	pa1[1] = b;
	float *pa2 = malloc(sizeof *pa2 * 2);
	pa2[0] = c;
	pa2[1] = d;
	float *pb1 = malloc(sizeof *pb1 * 2);
	pb1[0] = e;
	pb1[1] = f;
	float *pb2 = malloc(sizeof *pb2 * 2);
	pb2[0] = g;
	pb2[1] = h;
	float *k = malloc(sizeof *k * 2);
	e_intersect2f(k, pa1, pa2, pb1, pb2);
	if (test_float_equality(k[0], out0) || test_float_equality(k[1], out1))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f), (%f, %f), (%f, %f), (%f, %f). Expected (%f, %f), but got (%f, %f)",
				__FILE__, __func__, a, b, c, d, e, f, g, h, out0, out1, k[0], k[1]);
		free(pa1);
		free(pa2);
		free(pb1);
		free(pb2);
		free(k);
		return 1;
	}
	free(pa1);
	free(pa2);
	free(pb1);
	free(pb2);
	free(k);
	return 0;
}

// ------------ 3D floats ------------
int test_e_length3f(float a, float b, float c, float out)
{
	float *i = malloc(sizeof *i * 3);
	i[0] = a;
	i[1] = b;
	i[2] = c;
	float result = e_length3f(i);
	if (test_float_equality(out, result))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f, %f). Expected %f, but got %f",
				__FILE__, __func__, a, b, c, out, result);
		free(i);
		return 1;
	}
	free(i);
	return 0;
}

int test_e_distance3f(float a, float b, float c, float d, float e, float f, float out)
{
	float *i = malloc(sizeof *i * 3);
	i[0] = a;
	i[1] = b;
	i[2] = c;
	float *j = malloc(sizeof *j * 3);
	j[0] = d;
	j[1] = e;
	j[2] = f;
	float result = e_distance3f(i, j);
	if (test_float_equality(result, out))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f, %f), (%f, %f, %f). Expected %f, but got %f",
				__FILE__, __func__, a, b, c, d, e, f, out, result);
		free(i);
		free(j);
		return 1;
	}
	free(i);
	free(j);
	return 0;
}

int test_e_dot3f(float a, float b, float c, float d, float e, float f, float out)
{
	float *i = malloc(sizeof *i * 3);
	i[0] = a;
	i[1] = b;
	i[2] = c;
	float *j = malloc(sizeof *j * 3);
	j[0] = d;
	j[1] = e;
	j[2] = f;
	float result = e_dot3f(i, j);
	if (test_float_equality(result, out))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f, %f), (%f, %f, %f), Expected %f, but got %f.",
				__FILE__, __func__, a, b, c, d, e, f, out, result);
		free(i);
		free(j);
		return 1;
	}
	free(i);
	free(j);
	return 0;
}

int test_e_cross3f(float a, float b, float c, float d, float e, float f, float out0, float out1, float out2)
{
	float *i = malloc(sizeof *i * 3);
	i[0] = a;
	i[1] = b;
	i[2] = c;
	float *j = malloc(sizeof *j * 3);
	j[0] = d;
	j[1] = e;
	j[2] = f;
	float *k = malloc(sizeof *k * 3);
	e_cross3f(k, i, j);
	if (test_float_equality(k[0], out0) || test_float_equality(k[1], out1) || test_float_equality(k[2], out2))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f, %f), (%f, %f, %f). Expected (%f, %f, %f), but got (%f, %f, %f)",
				__FILE__, __func__, a, b, c, d, e, f, out0, out1, out2, k[0], k[1], k[2]);
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

int test_e_normalize3f(float a, float b, float c, float out0, float out1, float out2)
{
	float *i = malloc(sizeof *i * 3);
	i[0] = a;
	i[1] = b;
	i[2] = c;
	e_normalize3f(i);
	if (test_float_equality(i[0], out0) || test_float_equality(i[1], out1) || test_float_equality(i[2], out2))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f, %f). Expected (%f, %f, %f), but got (%f, %f, %f)",
				__FILE__, __func__, a, b, c, out0, out1, out2, i[0], i[1], i[2]);
		free(i);
		return 1;
	}
	free(i);
	return 0;
}

int test_e_reflect3f(float a, float b, float c, float d, float e, float f, float out0, float out1, float out2)
{
	float *pos = malloc(sizeof *pos * 3);
	pos[0] = a;
	pos[1] = b;
	pos[2] = c;
	float *vec = malloc(sizeof *vec * 3);
	vec[0] = d;
	vec[1] = e;
	vec[2] = f;
	float *k = malloc(sizeof *k * 3);
	e_reflect3f(k, pos, vec);
	if (test_float_equality(k[0], out0) || test_float_equality(k[1], out1) || test_float_equality(k[2], out2))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f, %f), (%f, %f, %f). Expected (%f, %f, %f), but got (%f, %f, %f)",
				__FILE__, __func__, a, b, c, d, e, f, out0, out1, out2, k[0], k[1], k[2]);
		free(pos);
		free(vec);
		free(k);
		return 1;
	}
	free(pos);
	free(vec);
	free(k);
	return 0;
}

int test_e_project3f(float a, float b, float c, float d, float e, float f, float out0, float out1, float out2)
{
	float *pos = malloc(sizeof *pos * 3);
	pos[0] = a;
	pos[1] = b;
	pos[2] = c;
	float *vec = malloc(sizeof *vec * 3);
	vec[0] = d;
	vec[1] = e;
	vec[2] = f;
	float *k = malloc(sizeof *k * 3);
	e_project3f(k, pos, vec);
	if (test_float_equality(k[0], out0) || test_float_equality(k[1], out1) || test_float_equality(k[2], out2))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f, %f), (%f, %f, %f). Expected (%f, %f, %f), but got (%f, %f, %f)",
				__FILE__, __func__, a, b, c, d, e, f, out0, out1, out2, k[0], k[1], k[2]);
		free(pos);
		free(vec);
		free(k);
		return 1;
	}
	free(pos);
	free(vec);
	free(k);
	return 0;
}
int test_e_normal3f(float a, float b, float c, float d, float e, float f, float g, float h, float i,
		float out0, float out1, float out2)
{
	float *veca = malloc(sizeof *veca * 3);
	veca[0] = a;
	veca[1] = b;
	veca[2] = c;
	float *vecb = malloc(sizeof *vecb * 3);
	vecb[0] = d;
	vecb[1] = e;
	vecb[2] = f;
	float *vecc = malloc(sizeof *vecc * 3);
	vecc[0] = g;
	vecc[1] = h;
	vecc[2] = i;
	float *k = malloc(sizeof *k * 3);
	e_normal3f(k, veca, vecb, vecc);
	if (test_float_equality(k[0], out0) || test_float_equality(k[1], out1) || test_float_equality(k[2], out2))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f, %f), (%f, %f, %f), (%f, %f, %f). Expected (%f, %f, %f), but got (%f, %f, %f)",
				__FILE__, __func__, a, b, c, d, e, f, g, h, i, out0, out1, out2, k[0], k[1], k[2]);
		free(veca);
		free(vecb);
		free(vecc);
		free(k);
		return 1;
	}
	free(veca);
	free(vecb);
	free(vecc);
	free(k);
	return 0;
}

// ---------- 2D doubles -----------
int test_e_length2d(double a, double b, double c)
{
	double *i = malloc(sizeof *i * 2);
	i[0] = a;
	i[1] = b;
	double out = e_length2d(i);
	if (test_double_equality(out, c))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f). Expected %f, but got %f", __FILE__, __func__, a, b, c, out);
		free(i);
		return 1;
	}
	free(i);
	return 0;
}

int test_e_distance2d(double a, double b, double c, double d, double out)
{
	double *i = malloc(sizeof *i * 2);
	i[0] = a;
	i[1] = b;
	double *j = malloc(sizeof *j * 2);
	j[0] = c;
	j[1] = d;
	double result = e_distance2d(i, j);
	if (test_double_equality(result, out))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f), (%f, %f). Expected %f, but got %f",
				__FILE__, __func__, a, b, c, d, out, result);
		free(i);
		free(j);
		return 1;
	}
	free(i);
	free(j);
	return 0;
}

int test_e_dot2d(double a, double b, double c, double d, double out)
{
	double *i = malloc(sizeof *i * 2);
	i[0] = a;
	i[1] = b;
	double *j = malloc(sizeof *j * 2);
	j[0] = c;
	j[1] = d;
	double result = e_dot2d(i, j);
	if (test_double_equality(result, out))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f), (%f, %f). Expected %f, but got %f",
				__FILE__, __func__, a, b, c, d, out, result);
		free(i);
		free(j);
		return 1;
	}
	free(i);
	free(j);
	return 0;
}

int test_e_cross2d(double a, double b, double c, double d, double out)
{
	double *i = malloc(sizeof *i * 2);
	i[0] = a;
	i[1] = b;
	double *j = malloc(sizeof *j * 2);
	j[0] = c;
	j[1] = d;
	double *k = malloc(sizeof *k);
	e_cross2d(k, i, j);
	if (test_double_equality(*k, out))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f), (%f, %f). Expected %f, but got %f",
				__FILE__, __func__, a, b, c, d, out, *k);
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

int test_e_normalize2d(double a, double b, double out0, double out1)
{
	double *i = malloc(sizeof *i * 2);
	i[0] = a;
	i[1] = b;
	e_normalize2d(i);
	if (test_double_equality(i[0], out0) || test_double_equality(i[1], out1))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f). Expected (%f, %f), but got (%f, %f)",
				__FILE__, __func__, a, b, out0, out1, i[0], i[1]);
		free(i);
		return 1;
	}
	free(i);
	return 0;
}

int test_e_reflect2d(double a, double b, double c, double d, double out0, double out1)
{
	double *pos = malloc(sizeof *pos * 2);
	pos[0] = a;
	pos[1] = b;
	double *normal = malloc(sizeof *normal * 2);
	normal[0] = c;
	normal[1] = d;
	double *k = malloc(sizeof *k * 2);
	e_reflect2d(k, pos, normal);
	if (test_double_equality(k[0], out0) || test_double_equality(k[1], out1))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f), (%f, %f). Expected (%f, %f), but got (%f, %f)",
				__FILE__, __func__, a, b, c, d, out0, out1, k[0], k[1]);
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

int test_e_project2d(double a, double b, double c, double d, double out0, double out1)
{
	double *pos = malloc(sizeof *pos * 2);
	pos[0] = a;
	pos[1] = b;
	double *normal = malloc(sizeof *normal * 2);
	normal[0] = c;
	normal[1] = d;
	double *k = malloc(sizeof *k * 2);
	e_project2d(k, pos, normal);
	if (test_double_equality(k[0], out0) || test_double_equality(k[1], out1))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f), (%f, %f). Expected (%f, %f), but got (%f, %f)",
				__FILE__, __func__, a, b, c, d, out0, out1, k[0], k[1]);
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
int test_e_normal2d(double a, double b, double c, double d, double out0, double out1)
{
	double *veca = malloc(sizeof *veca * 2);
	veca[0] = a;
	veca[1] = b;
	double *vecb = malloc(sizeof *vecb * 2);
	vecb[0] = c;
	vecb[1] = d;
	double *k = malloc(sizeof *k * 2);
	e_normal2d(k, veca, vecb);
	if (test_double_equality(k[0], out0) || test_double_equality(k[1], out1))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f), (%f, %f). Expected (%f, %f), but got (%f, %f)",
				__FILE__, __func__, a, b, c, d, out0, out1, k[0], k[1]);
		free(veca);
		free(vecb);
		free(k);
		return 1;
	}
	free(veca);
	free(vecb);
	free(k);
	return 0;
}
int test_e_intersect2d(double a, double b, double c, double d, double e, double f, double g, double h, double out0, double out1)
{
	double *pa1 = malloc(sizeof *pa1 * 2);
	pa1[0] = a;
	pa1[1] = b;
	double *pa2 = malloc(sizeof *pa2 * 2);
	pa2[0] = c;
	pa2[1] = d;
	double *pb1 = malloc(sizeof *pb1 * 2);
	pb1[0] = e;
	pb1[1] = f;
	double *pb2 = malloc(sizeof *pb2 * 2);
	pb2[0] = g;
	pb2[1] = h;
	double *k = malloc(sizeof *k * 2);
	e_intersect2d(k, pa1, pa2, pb1, pb2);
	if (test_double_equality(k[0], out0) || test_double_equality(k[1], out1))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f), (%f, %f), (%f, %f), (%f, %f). Expected (%f, %f), but got (%f, %f)",
				__FILE__, __func__, a, b, c, d, e, f, g, h, out0, out1, k[0], k[1]);
		free(pa1);
		free(pa2);
		free(pb1);
		free(pb2);
		free(k);
		return 1;
	}
	free(pa1);
	free(pa2);
	free(pb1);
	free(pb2);
	free(k);
	return 0;
}

// ------------ 3D doubles ------------
int test_e_length3d(double a, double b, double c, double out)
{
	double *i = malloc(sizeof *i * 3);
	i[0] = a;
	i[1] = b;
	i[2] = c;
	double result = e_length3d(i);
	if (test_double_equality(out, result))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f, %f). Expected %f, but got %f",
				__FILE__, __func__, a, b, c, out, result);
		free(i);
		return 1;
	}
	free(i);
	return 0;
}

int test_e_distance3d(double a, double b, double c, double d, double e, double f, double out)
{
	double *i = malloc(sizeof *i * 3);
	i[0] = a;
	i[1] = b;
	i[2] = c;
	double *j = malloc(sizeof *j * 3);
	j[0] = d;
	j[1] = e;
	j[2] = f;
	double result = e_distance3d(i, j);
	if (test_double_equality(result, out))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f, %f), (%f, %f, %f). Expected %f, but got %f",
				__FILE__, __func__, a, b, c, d, e, f, out, result);
		free(i);
		free(j);
		return 1;
	}
	free(i);
	free(j);
	return 0;
}

int test_e_dot3d(double a, double b, double c, double d, double e, double f, double out)
{
	double *i = malloc(sizeof *i * 3);
	i[0] = a;
	i[1] = b;
	i[2] = c;
	double *j = malloc(sizeof *j * 3);
	j[0] = d;
	j[1] = e;
	j[2] = f;
	double result = e_dot3d(i, j);
	if (test_double_equality(result, out))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f, %f), (%f, %f, %f), Expected %f, but got %f.",
				__FILE__, __func__, a, b, c, d, e, f, out, result);
		free(i);
		free(j);
		return 1;
	}
	free(i);
	free(j);
	return 0;
}

int test_e_cross3d(double a, double b, double c, double d, double e, double f, double out0, double out1, double out2)
{
	double *i = malloc(sizeof *i * 3);
	i[0] = a;
	i[1] = b;
	i[2] = c;
	double *j = malloc(sizeof *j * 3);
	j[0] = d;
	j[1] = e;
	j[2] = f;
	double *k = malloc(sizeof *k * 3);
	e_cross3d(k, i, j);
	if (test_double_equality(k[0], out0) || test_double_equality(k[1], out1) || test_double_equality(k[2], out2))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f, %f), (%f, %f, %f). Expected (%f, %f, %f), but got (%f, %f, %f)",
				__FILE__, __func__, a, b, c, d, e, f, out0, out1, out2, k[0], k[1], k[2]);
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

int test_e_normalize3d(double a, double b, double c, double out0, double out1, double out2)
{
	double *i = malloc(sizeof *i * 3);
	i[0] = a;
	i[1] = b;
	i[2] = c;
	e_normalize3d(i);
	if (test_double_equality(i[0], out0) || test_double_equality(i[1], out1) || test_double_equality(i[2], out2))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f, %f). Expected (%f, %f, %f), but got (%f, %f, %f)",
				__FILE__, __func__, a, b, c, out0, out1, out2, i[0], i[1], i[2]);
		free(i);
		return 1;
	}
	free(i);
	return 0;
}

int test_e_reflect3d(double a, double b, double c, double d, double e, double f, double out0, double out1, double out2)
{
	double *pos = malloc(sizeof *pos * 3);
	pos[0] = a;
	pos[1] = b;
	pos[2] = c;
	double *vec = malloc(sizeof *vec * 3);
	vec[0] = d;
	vec[1] = e;
	vec[2] = f;
	double *k = malloc(sizeof *k * 3);
	e_reflect3d(k, pos, vec);
	if (test_double_equality(k[0], out0) || test_double_equality(k[1], out1) || test_double_equality(k[2], out2))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f, %f), (%f, %f, %f). Expected (%f, %f, %f), but got (%f, %f, %f)",
				__FILE__, __func__, a, b, c, d, e, f, out0, out1, out2, k[0], k[1], k[2]);
		free(pos);
		free(vec);
		free(k);
		return 1;
	}
	free(pos);
	free(vec);
	free(k);
	return 0;
}

int test_e_project3d(double a, double b, double c, double d, double e, double f, double out0, double out1, double out2)
{
	double *pos = malloc(sizeof *pos * 3);
	pos[0] = a;
	pos[1] = b;
	pos[2] = c;
	double *vec = malloc(sizeof *vec * 3);
	vec[0] = d;
	vec[1] = e;
	vec[2] = f;
	double *k = malloc(sizeof *k * 3);
	e_project3d(k, pos, vec);
	if (test_double_equality(k[0], out0) || test_double_equality(k[1], out1) || test_double_equality(k[2], out2))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f, %f), (%f, %f, %f). Expected (%f, %f, %f), but got (%f, %f, %f)",
				__FILE__, __func__, a, b, c, d, e, f, out0, out1, out2, k[0], k[1], k[2]);
		free(pos);
		free(vec);
		free(k);
		return 1;
	}
	free(pos);
	free(vec);
	free(k);
	return 0;
}
int test_e_normal3d(double a, double b, double c, double d, double e, double f, double g, double h, double i,
		double out0, double out1, double out2)
{
	double *veca = malloc(sizeof *veca * 3);
	veca[0] = a;
	veca[1] = b;
	veca[2] = c;
	double *vecb = malloc(sizeof *vecb * 3);
	vecb[0] = d;
	vecb[1] = e;
	vecb[2] = f;
	double *vecc = malloc(sizeof *vecc * 3);
	vecc[0] = g;
	vecc[1] = h;
	vecc[2] = i;
	double *k = malloc(sizeof *k * 3);
	e_normal3d(k, veca, vecb, vecc);
	if (test_double_equality(k[0], out0) || test_double_equality(k[1], out1) || test_double_equality(k[2], out2))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f, %f), (%f, %f, %f), (%f, %f, %f). Expected (%f, %f, %f), but got (%f, %f, %f)",
				__FILE__, __func__, a, b, c, d, e, f, g, h, i, out0, out1, out2, k[0], k[1], k[2]);
		free(veca);
		free(vecb);
		free(vecc);
		free(k);
		return 1;
	}
	free(veca);
	free(vecb);
	free(vecc);
	free(k);
	return 0;
}

// ---------- 4D normalize -----------
int test_e_normalize4f(float a, float b, float c, float d, float out0, float out1, float out2, float out3)
{
	float *i = malloc(sizeof *i * 4);
	i[0] = a;
	i[1] = b;
	i[2] = c;
	i[3] = d;
	e_normalize3f(i);
	if (
			test_float_equality(i[0], out0) ||
			test_float_equality(i[1], out1) ||
			test_float_equality(i[2], out2) ||
			test_float_equality(i[2], out2))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f, %f, %f). Expected (%f, %f, %f, %f), but got (%f, %f, %f, %f)",
				__FILE__, __func__, a, b, c, d, out0, out1, out2, out3, i[0], i[1], i[2], i[3]);
		free(i);
		return 1;
	}
	free(i);
	return 0;
}
int test_e_normalize4d(double a, double b, double c, double d, double out0, double out1, double out2, double out3)
{
	double *i = malloc(sizeof *i * 4);
	i[0] = a;
	i[1] = b;
	i[2] = c;
	i[3] = d;
	e_normalize3d(i);
	if (
			test_double_equality(i[0], out0) ||
			test_double_equality(i[1], out1) ||
			test_double_equality(i[2], out2) ||
			test_double_equality(i[2], out2))
	{
		fprintf(stderr, "%s, %s: Test failed for: (%f, %f, %f, %f). Expected (%f, %f, %f, %f), but got (%f, %f, %f, %f)",
				__FILE__, __func__, a, b, c, d, out0, out1, out2, out3, i[0], i[1], i[2], i[3]);
		free(i);
		return 1;
	}
	free(i);
	return 0;
}

// ------------ Integer Tests ------------
//int test_e_sqrti(int a, int out)
//{
//	int result = e_sqrti(a);
//	if (result != out)
//	{
//		fprintf(stderr, "%s, %s: Test failed for: %i. Expected %i, but got %i", __FILE__, __func__, a, out, result);
//		return 1;
//	}
//	return 0;
//}

int test_e_max(int a, int b, int out)
{
	int result = E_MAX(a, b);
	if (result != out)
	{
		fprintf(stderr, "%s, %s: Test failed for: %i, %i. Expected %i, but got %i", __FILE__, __func__, a, b, out, result);
		return 1;
	}
	return 0;
}

int test_e_min(int a, int b, int out)
{
	int result = E_MIN(a, b);
	if (result != out)
	{
		fprintf(stderr, "%s, %s: Test failed for: %i, %i. Expected %i, but got %i", __FILE__, __func__, a, b, out, result);
		return 1;
	}
	return 0;
}

// ------------- MAIN -------------------
int main(void)
{
	// test e_sqrtf
	for (float i = 0; i < 10; i += 0.1)
	{
		if (test_e_sqrtf(i*i, i))
			return 1;
	}

	if (
			// Float tests
			test_e_length2f(3, 4, 5) ||
			test_e_length3f(3, 4, 0, 5) ||
			test_e_length3f(1, 1, 1, sqrt(3)) ||
			test_e_distance2f(3, 4, 3, 4, 0) ||
			test_e_distance2f(0, 5, 0, 0, 5) ||
			test_e_distance2f(-5, 0, 0, 0, 5) ||
			test_e_distance3f(3, 4, 0, 3, 4, 0, 0) ||
			test_e_distance3f(0, 5, 0, 0, 0, 0, 5) ||
			test_e_distance3f(-5, 0, 0, 0, 0, 0, 5) ||
			test_e_dot2f(1, 2, 1, 5, 11) ||
			test_e_dot3f(1, 2, 3, 1, 5, 7, 32) ||
			test_e_cross2f(1, 2, 3, 4, -2) ||
			test_e_cross2f(1, 0, 3, 0, 0) ||
			test_e_cross2f(-1, -3, 2, 4, 2) ||
			test_e_cross3f(1, 2, 3, 4, 5, 6, -3, 6, -3) ||
			test_e_normalize2f(1, 1, sqrt(2.f)/2, sqrt(2.f)/2) ||
			test_e_normalize2f(-1, 1, -sqrt(2.f)/2, sqrt(2.f)/2) ||
			test_e_normalize2f(0, 1, 0, 1) ||
			test_e_normalize3f(1, 1, -1, sqrt(3.f)/3, sqrt(3.f)/3, -sqrt(3.f)/3) ||
			test_e_normalize4f(1, 1, -1, 0, sqrt(3.f)/3, sqrt(3.f)/3, -sqrt(3.f)/3, 0) ||
			test_e_reflect2f(1, 2, 3, -4, 31, -38) ||
			test_e_reflect2f(1, 0, sqrt(2.f)/2, sqrt(2.f)/2, 0, -1) ||
			test_e_reflect3f(3, 2, 6, 0.5, 0.4, 0.3, -1.1, -1.28, 3.54) ||
			test_e_project2f(1, 2, -3, 4, -0.6, 0.8) ||
			test_e_project3f(1, 2, 0, -3, 4, 0, -0.6, 0.8, 0) ||
			test_e_project3f(-1, 4, 2, 1, 0, 3, 0.5, 0, 1.5) ||
			test_e_normal2f(0, 0, 1, 1, -sqrt(2.f)/2, sqrt(2.f)/2) ||
			test_e_normal3f(0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1) ||
			test_e_intersect2f(0, 0, 0, 1, 0, 0, -1, 1, 0, 0) ||
			test_e_intersect2f(0, 0, 0, 1, 0, 0, 0, -1, 0, 0) ||
			test_e_intersect2f(1, 1, 1, 2, 0, 1.5, 2, 1.5, 1, 1.5) ||
			test_e_intersect2f(0, 0, 0, 1, 1, 1, 2, 1, 0, 1) ||

			// Double tests
			test_e_length2d(3, 4, 5) ||
			test_e_length3d(3, 4, 0, 5) ||
			test_e_length3d(1, 1, 1, sqrt(3)) ||
			test_e_distance2d(3, 4, 3, 4, 0) ||
			test_e_distance2d(0, 5, 0, 0, 5) ||
			test_e_distance2d(-5, 0, 0, 0, 5) ||
			test_e_distance3d(3, 4, 0, 3, 4, 0, 0) ||
			test_e_distance3d(0, 5, 0, 0, 0, 0, 5) ||
			test_e_distance3d(-5, 0, 0, 0, 0, 0, 5) ||
			test_e_dot2d(1, 2, 1, 5, 11) ||
			test_e_dot3d(1, 2, 3, 1, 5, 7, 32) ||
			test_e_cross2d(1, 2, 3, 4, -2) ||
			test_e_cross2d(1, 0, 3, 0, 0) ||
			test_e_cross2d(-1, -3, 2, 4, 2) ||
			test_e_cross3d(1, 2, 3, 4, 5, 6, -3, 6, -3) ||
			test_e_normalize2d(1, 1, sqrt(2.f)/2, sqrt(2.f)/2) ||
			test_e_normalize2d(-1, 1, -sqrt(2.f)/2, sqrt(2.f)/2) ||
			test_e_normalize2d(0, 1, 0, 1) ||
			test_e_normalize3d(1, 1, -1, sqrt(3.f)/3, sqrt(3.f)/3, -sqrt(3.f)/3) ||
			test_e_normalize4d(1, 1, -1, 0, sqrt(3.f)/3, sqrt(3.f)/3, -sqrt(3.f)/3, 0) ||
			test_e_reflect2d(1, 2, 3, -4, 31, -38) ||
			test_e_reflect2d(1, 0, sqrt(2.f)/2, sqrt(2.f)/2, 0, -1) ||
			test_e_reflect3d(3, 2, 6, 0.5, 0.4, 0.3, -1.1, -1.28, 3.54) ||
			test_e_project2d(1, 2, -3, 4, -0.6, 0.8) ||
			test_e_project3d(-1, 4, 2, 1, 0, 3, 0.5, 0, 1.5) ||
			test_e_normal2d(0, 0, 1, 1, -sqrt(2.f)/2, sqrt(2.f)/2) ||
			test_e_normal3d(0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1) ||
			test_e_intersect2d(0, 0, 0, 1, 0, 0, -1, 1, 0, 0) ||
			test_e_intersect2d(0, 0, 0, 1, 0, 0, 0, -1, 0, 0) ||
			test_e_intersect2d(1, 1, 1, 2, 0, 1.5, 2, 1.5, 1, 1.5) ||
			test_e_intersect2d(0, 0, 0, 1, 2, 1, 1, 1, 0, 1) ||

			// Integer tests
			//test_e_sqrti(9, 3) ||
			//test_e_sqrti(4, 2) ||
			//test_e_sqrti(1, 1) ||
			test_e_max(4, 5, 5) ||
			test_e_max(-1, -5, -1) ||
			test_e_min(4, 5, 4) ||
			test_e_min(-1, -5, -5))
		return 1;


	return 0;
}
