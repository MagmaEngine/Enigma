#include "enigma.h"
#include <math.h>

void e_matrixxyf(float *matrix, const float *origo, const float *point_a, const float *point_b)
{
	float r, a[3], b[3];
	if (origo != NULL)
	{
		a[0] = point_a[0] - origo[0];
		a[1] = point_a[1] - origo[1];
		a[2] = point_a[2] - origo[2];
		matrix[12] = origo[0];
		matrix[13] = origo[1];
		matrix[14] = origo[2];
		b[0] = point_b[0] - origo[0];
		b[1] = point_b[1] - origo[1];
		b[2] = point_b[2] - origo[2];
	} else
	{
		a[0] = point_a[0];
		a[1] = point_a[1];
		a[2] = point_a[2];
		matrix[12] = 0;
		matrix[13] = 0;
		matrix[14] = 0;
		b[0] = point_b[0];
		b[1] = point_b[1];
		b[2] = point_b[2];
	}
	r = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	matrix[0] = a[0] / r;
	matrix[1] = a[1] / r;
	matrix[2] = a[2] / r;
	matrix[8] = matrix[1] * b[2] - matrix[2] * b[1];
	matrix[9] = matrix[2] * b[0] - matrix[0] * b[2];
	matrix[10] = matrix[0] * b[1] - matrix[1] * b[0];
	r = sqrt(matrix[8] * matrix[8] + matrix[9] * matrix[9] + matrix[10] * matrix[10]);
	matrix[8] = matrix[8] / r;
	matrix[9] = matrix[9] / r;
	matrix[10] = matrix[10] / r;
	matrix[4] = matrix[2] * matrix[9] - matrix[1] * matrix[10];
	matrix[5] = matrix[0] * matrix[10] - matrix[2] * matrix[8];
	matrix[6] = matrix[1] * matrix[8] - matrix[0] * matrix[9];
	r = sqrt(matrix[4] * matrix[4] + matrix[5] * matrix[5] + matrix[6] * matrix[6]);
	matrix[4] = matrix[4] / r;
	matrix[5] = matrix[5] / r;
	matrix[6] = matrix[6] / r;
	matrix[3] = 0;
	matrix[7] = 0;
	matrix[11] = 0;
	matrix[15] = 1;
}

void e_matrixxzf(float *matrix, const float *origo, const float *point_a, const float *point_b)
{
	float r, a[3], b[3];
	if (origo != NULL)
	{
		a[0] = point_a[0] - origo[0];
		a[1] = point_a[1] - origo[1];
		a[2] = point_a[2] - origo[2];
		matrix[12] = origo[0];
		matrix[13] = origo[1];
		matrix[14] = origo[2];
		b[0] = point_b[0] - origo[0];
		b[1] = point_b[1] - origo[1];
		b[2] = point_b[2] - origo[2];
	} else
	{
		a[0] = point_a[0];
		a[1] = point_a[1];
		a[2] = point_a[2];
		matrix[12] = 0;
		matrix[13] = 0;
		matrix[14] = 0;
		b[0] = point_b[0];
		b[1] = point_b[1];
		b[2] = point_b[2];
	}
	r = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	matrix[0] = a[0] / r;
	matrix[1] = a[1] / r;
	matrix[2] = a[2] / r;
	matrix[4] = matrix[2] * b[1] - matrix[1] * b[2];
	matrix[5] = matrix[0] * b[2] - matrix[2] * b[0];
	matrix[6] = matrix[1] * b[0] - matrix[0] * b[1];
	r = sqrt(matrix[4] * matrix[4] + matrix[5] * matrix[5] + matrix[6] * matrix[6]);
	matrix[4] = matrix[4] / r;
	matrix[5] = matrix[5] / r;
	matrix[6] = matrix[6] / r;
	matrix[8] = matrix[1] * matrix[6] - matrix[2] * matrix[5];
	matrix[9] = matrix[2] * matrix[4] - matrix[0] * matrix[6];
	matrix[10] = matrix[0] * matrix[5] - matrix[1] * matrix[4];
	r = sqrt(matrix[8] * matrix[8] + matrix[9] * matrix[9] + matrix[10] * matrix[10]);
	matrix[8] = matrix[8] / r;
	matrix[9] = matrix[9] / r;
	matrix[10] = matrix[10] / r;
	matrix[3] = 0;
	matrix[7] = 0;
	matrix[11] = 0;
	matrix[15] = 1;
}

void e_matrixyxf(float *matrix, const float *origo, const float *point_a, const float *point_b)
{
	float r, a[3], b[3];
	if (origo != NULL)
	{
		a[0] = point_a[0] - origo[0];
		a[1] = point_a[1] - origo[1];
		a[2] = point_a[2] - origo[2];
		matrix[12] = origo[0];
		matrix[13] = origo[1];
		matrix[14] = origo[2];
		b[0] = point_b[0] - origo[0];
		b[1] = point_b[1] - origo[1];
		b[2] = point_b[2] - origo[2];
	} else
	{
		a[0] = point_a[0];
		a[1] = point_a[1];
		a[2] = point_a[2];
		matrix[12] = 0;
		matrix[13] = 0;
		matrix[14] = 0;
		b[0] = point_b[0];
		b[1] = point_b[1];
		b[2] = point_b[2];
	}
	r = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	matrix[4] = a[0] / r;
	matrix[5] = a[1] / r;
	matrix[6] = a[2] / r;
	matrix[8] = matrix[6] * b[1] - matrix[5] * b[2];
	matrix[9] = matrix[4] * b[2] - matrix[6] * b[0];
	matrix[10] = matrix[5] * b[0] - matrix[4] * b[1];
	r = sqrt(matrix[8] * matrix[8] + matrix[9] * matrix[9] + matrix[10] * matrix[10]);
	matrix[8] = matrix[8] / r;
	matrix[9] = matrix[9] / r;
	matrix[10] = matrix[10] / r;
	matrix[0] = matrix[5] * matrix[10] - matrix[6] * matrix[9];
	matrix[1] = matrix[6] * matrix[8] - matrix[4] * matrix[10];
	matrix[2] = matrix[4] * matrix[9] - matrix[5] * matrix[8];
	r = sqrt(matrix[0] * matrix[0] + matrix[1] * matrix[1] + matrix[2] * matrix[2]);
	matrix[0] = matrix[0] / r;
	matrix[1] = matrix[1] / r;
	matrix[2] = matrix[2] / r;
	matrix[3] = 0;
	matrix[7] = 0;
	matrix[11] = 0;
	matrix[15] = 1;
}

void e_matrixyzf(float *matrix, const float *origo, const float *point_a, const float *point_b)
{
	float r, a[3], b[3];
	if (origo != NULL)
	{
		a[0] = point_a[0] - origo[0];
		a[1] = point_a[1] - origo[1];
		a[2] = point_a[2] - origo[2];
		matrix[12] = origo[0];
		matrix[13] = origo[1];
		matrix[14] = origo[2];
		b[0] = point_b[0] - origo[0];
		b[1] = point_b[1] - origo[1];
		b[2] = point_b[2] - origo[2];
	} else
	{
		a[0] = point_a[0];
		a[1] = point_a[1];
		a[2] = point_a[2];
		matrix[12] = 0;
		matrix[13] = 0;
		matrix[14] = 0;
		b[0] = point_b[0];
		b[1] = point_b[1];
		b[2] = point_b[2];
	}
	r = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	matrix[4] = a[0] / r;
	matrix[5] = a[1] / r;
	matrix[6] = a[2] / r;
	matrix[0] = matrix[5] * b[2] - matrix[6] * b[1];
	matrix[1] = matrix[6] * b[0] - matrix[4] * b[2];
	matrix[2] = matrix[4] * b[1] - matrix[5] * b[0];
	r = sqrt(matrix[0] * matrix[0] + matrix[1] * matrix[1] + matrix[2] * matrix[2]);
	matrix[0] = matrix[0] / r;
	matrix[1] = matrix[1] / r;
	matrix[2] = matrix[2] / r;
	matrix[8] = matrix[6] * matrix[1] - matrix[5] * matrix[2];
	matrix[9] = matrix[4] * matrix[2] - matrix[6] * matrix[0];
	matrix[10] = matrix[5] * matrix[0] - matrix[4] * matrix[1];
	r = sqrt(matrix[8] * matrix[8] + matrix[9] * matrix[9] + matrix[10] * matrix[10]);
	matrix[8] = matrix[8] / r;
	matrix[9] = matrix[9] / r;
	matrix[10] = matrix[10] / r;
	matrix[3] = 0;
	matrix[7] = 0;
	matrix[11] = 0;
	matrix[15] = 1;
}

void e_matrixzxf(float *matrix, const float *origo, const float *point_a, const float *point_b)
{
	float r, a[3], b[3];
	if (origo != NULL)
	{
		a[0] = point_a[0] - origo[0];
		a[1] = point_a[1] - origo[1];
		a[2] = point_a[2] - origo[2];
		matrix[12] = origo[0];
		matrix[13] = origo[1];
		matrix[14] = origo[2];
		b[0] = point_b[0] - origo[0];
		b[1] = point_b[1] - origo[1];
		b[2] = point_b[2] - origo[2];
	} else
	{
		a[0] = point_a[0];
		a[1] = point_a[1];
		a[2] = point_a[2];
		matrix[12] = 0;
		matrix[13] = 0;
		matrix[14] = 0;
		b[0] = point_b[0];
		b[1] = point_b[1];
		b[2] = point_b[2];
	}
	r = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	matrix[8] = a[0] / r;
	matrix[9] = a[1] / r;
	matrix[10] = a[2] / r;
	matrix[4] = matrix[9] * b[2] - matrix[10] * b[1];
	matrix[5] = matrix[10] * b[0] - matrix[8] * b[2];
	matrix[6] = matrix[8] * b[1] - matrix[9] * b[0];
	r = sqrt(matrix[4] * matrix[4] + matrix[5] * matrix[5] + matrix[6] * matrix[6]);
	matrix[4] = matrix[4] / r;
	matrix[5] = matrix[5] / r;
	matrix[6] = matrix[6] / r;
	matrix[0] = matrix[10] * matrix[5] - matrix[9] * matrix[6];
	matrix[1] = matrix[8] * matrix[6] - matrix[10] * matrix[4];
	matrix[2] = matrix[9] * matrix[4] - matrix[8] * matrix[5];
	r = sqrt(matrix[0] * matrix[0] + matrix[1] * matrix[1] + matrix[2] * matrix[2]);
	matrix[0] = matrix[0] / r;
	matrix[1] = matrix[1] / r;
	matrix[2] = matrix[2] / r;
	matrix[3] = 0;
	matrix[7] = 0;
	matrix[11] = 0;
	matrix[15] = 1;
}

void e_matrixzyf(float *matrix, const float *origo, const float *point_a, const float *point_b)
{
	float r, a[3], b[3];
	if (origo != NULL)
	{
		a[0] = point_a[0] - origo[0];
		a[1] = point_a[1] - origo[1];
		a[2] = point_a[2] - origo[2];
		matrix[12] = origo[0];
		matrix[13] = origo[1];
		matrix[14] = origo[2];
		b[0] = point_b[0] - origo[0];
		b[1] = point_b[1] - origo[1];
		b[2] = point_b[2] - origo[2];
	} else
	{
		a[0] = point_a[0];
		a[1] = point_a[1];
		a[2] = point_a[2];
		matrix[12] = 0;
		matrix[13] = 0;
		matrix[14] = 0;
		b[0] = point_b[0];
		b[1] = point_b[1];
		b[2] = point_b[2];
	}
	r = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	matrix[8] = a[0] / r;
	matrix[9] = a[1] / r;
	matrix[10] = a[2] / r;
	matrix[0] = matrix[10] * b[1] - matrix[9] * b[2];
	matrix[1] = matrix[8] * b[2] - matrix[10] * b[0];
	matrix[2] = matrix[9] * b[0] - matrix[8] * b[1];
	r = sqrt(matrix[0] * matrix[0] + matrix[1] * matrix[1] + matrix[2] * matrix[2]);
	matrix[0] = matrix[0] / r;
	matrix[1] = matrix[1] / r;
	matrix[2] = matrix[2] / r;
	matrix[4] = matrix[9] * matrix[2] - matrix[10] * matrix[1];
	matrix[5] = matrix[10] * matrix[0] - matrix[8] * matrix[2];
	matrix[6] = matrix[8] * matrix[1] - matrix[9] * matrix[0];
	r = sqrt(matrix[4] * matrix[4] + matrix[5] * matrix[5] + matrix[6] * matrix[6]);
	matrix[4] = matrix[4] / r;
	matrix[5] = matrix[5] / r;
	matrix[6] = matrix[6] / r;
	matrix[3] = 0;
	matrix[7] = 0;
	matrix[11] = 0;
	matrix[15] = 1;
}

void e_matrixxyd(double *matrix, const double *origo, const double *point_a, const double *point_b)
{
	double r, a[3], b[3];
	if (origo != NULL)
	{
		a[0] = point_a[0] - origo[0];
		a[1] = point_a[1] - origo[1];
		a[2] = point_a[2] - origo[2];
		matrix[12] = origo[0];
		matrix[13] = origo[1];
		matrix[14] = origo[2];
		b[0] = point_b[0] - origo[0];
		b[1] = point_b[1] - origo[1];
		b[2] = point_b[2] - origo[2];
	} else
	{
		a[0] = point_a[0];
		a[1] = point_a[1];
		a[2] = point_a[2];
		matrix[12] = 0;
		matrix[13] = 0;
		matrix[14] = 0;
		b[0] = point_b[0];
		b[1] = point_b[1];
		b[2] = point_b[2];
	}
	r = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	matrix[0] = a[0] / r;
	matrix[1] = a[1] / r;
	matrix[2] = a[2] / r;
	matrix[8] = matrix[1] * b[2] - matrix[2] * b[1];
	matrix[9] = matrix[2] * b[0] - matrix[0] * b[2];
	matrix[10] = matrix[0] * b[1] - matrix[1] * b[0];
	r = sqrt(matrix[8] * matrix[8] + matrix[9] * matrix[9] + matrix[10] * matrix[10]);
	matrix[8] = matrix[8] / r;
	matrix[9] = matrix[9] / r;
	matrix[10] = matrix[10] / r;
	matrix[4] = matrix[2] * matrix[9] - matrix[1] * matrix[10];
	matrix[5] = matrix[0] * matrix[10] - matrix[2] * matrix[8];
	matrix[6] = matrix[1] * matrix[8] - matrix[0] * matrix[9];
	r = sqrt(matrix[4] * matrix[4] + matrix[5] * matrix[5] + matrix[6] * matrix[6]);
	matrix[4] = matrix[4] / r;
	matrix[5] = matrix[5] / r;
	matrix[6] = matrix[6] / r;
	matrix[3] = 0;
	matrix[7] = 0;
	matrix[11] = 0;
	matrix[15] = 1;
}

void e_matrixxzd(double *matrix, const double *origo, const double *point_a, const double *point_b)
{
	double r, a[3], b[3];
	if (origo != NULL)
	{
		a[0] = point_a[0] - origo[0];
		a[1] = point_a[1] - origo[1];
		a[2] = point_a[2] - origo[2];
		matrix[12] = origo[0];
		matrix[13] = origo[1];
		matrix[14] = origo[2];
		b[0] = point_b[0] - origo[0];
		b[1] = point_b[1] - origo[1];
		b[2] = point_b[2] - origo[2];
	} else
	{
		a[0] = point_a[0];
		a[1] = point_a[1];
		a[2] = point_a[2];
		matrix[12] = 0;
		matrix[13] = 0;
		matrix[14] = 0;
		b[0] = point_b[0];
		b[1] = point_b[1];
		b[2] = point_b[2];
	}
	r = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	matrix[0] = a[0] / r;
	matrix[1] = a[1] / r;
	matrix[2] = a[2] / r;
	matrix[4] = matrix[2] * b[1] - matrix[1] * b[2];
	matrix[5] = matrix[0] * b[2] - matrix[2] * b[0];
	matrix[6] = matrix[1] * b[0] - matrix[0] * b[1];
	r = sqrt(matrix[4] * matrix[4] + matrix[5] * matrix[5] + matrix[6] * matrix[6]);
	matrix[4] = matrix[4] / r;
	matrix[5] = matrix[5] / r;
	matrix[6] = matrix[6] / r;
	matrix[8] = matrix[1] * matrix[6] - matrix[2] * matrix[5];
	matrix[9] = matrix[2] * matrix[4] - matrix[0] * matrix[6];
	matrix[10] = matrix[0] * matrix[5] - matrix[1] * matrix[4];
	r = sqrt(matrix[8] * matrix[8] + matrix[9] * matrix[9] + matrix[10] * matrix[10]);
	matrix[8] = matrix[8] / r;
	matrix[9] = matrix[9] / r;
	matrix[10] = matrix[10] / r;
	matrix[3] = 0;
	matrix[7] = 0;
	matrix[11] = 0;
	matrix[15] = 1;
}

void e_matrixyxd(double *matrix, const double *origo, const double *point_a, const double *point_b)
{
	double r, a[3], b[3];
	if (origo != NULL)
	{
		a[0] = point_a[0] - origo[0];
		a[1] = point_a[1] - origo[1];
		a[2] = point_a[2] - origo[2];
		matrix[12] = origo[0];
		matrix[13] = origo[1];
		matrix[14] = origo[2];
		b[0] = point_b[0] - origo[0];
		b[1] = point_b[1] - origo[1];
		b[2] = point_b[2] - origo[2];
	} else
	{
		a[0] = point_a[0];
		a[1] = point_a[1];
		a[2] = point_a[2];
		matrix[12] = 0;
		matrix[13] = 0;
		matrix[14] = 0;
		b[0] = point_b[0];
		b[1] = point_b[1];
		b[2] = point_b[2];
	}
	r = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	matrix[4] = a[0] / r;
	matrix[5] = a[1] / r;
	matrix[6] = a[2] / r;
	matrix[8] = matrix[6] * b[1] - matrix[5] * b[2];
	matrix[9] = matrix[4] * b[2] - matrix[6] * b[0];
	matrix[10] = matrix[5] * b[0] - matrix[4] * b[1];
	r = sqrt(matrix[8] * matrix[8] + matrix[9] * matrix[9] + matrix[10] * matrix[10]);
	matrix[8] = matrix[8] / r;
	matrix[9] = matrix[9] / r;
	matrix[10] = matrix[10] / r;
	matrix[0] = matrix[5] * matrix[10] - matrix[6] * matrix[9];
	matrix[1] = matrix[6] * matrix[8] - matrix[4] * matrix[10];
	matrix[2] = matrix[4] * matrix[9] - matrix[5] * matrix[8];
	r = sqrt(matrix[0] * matrix[0] + matrix[1] * matrix[1] + matrix[2] * matrix[2]);
	matrix[0] = matrix[0] / r;
	matrix[1] = matrix[1] / r;
	matrix[2] = matrix[2] / r;
	matrix[3] = 0;
	matrix[7] = 0;
	matrix[11] = 0;
	matrix[15] = 1;
}

void e_matrixyzd(double *matrix, const double *origo, const double *point_a, const double *point_b)
{
	double r, a[3], b[3];
	if (origo != NULL)
	{
		a[0] = point_a[0] - origo[0];
		a[1] = point_a[1] - origo[1];
		a[2] = point_a[2] - origo[2];
		matrix[12] = origo[0];
		matrix[13] = origo[1];
		matrix[14] = origo[2];
		b[0] = point_b[0] - origo[0];
		b[1] = point_b[1] - origo[1];
		b[2] = point_b[2] - origo[2];
	} else
	{
		a[0] = point_a[0];
		a[1] = point_a[1];
		a[2] = point_a[2];
		matrix[12] = 0;
		matrix[13] = 0;
		matrix[14] = 0;
		b[0] = point_b[0];
		b[1] = point_b[1];
		b[2] = point_b[2];
	}
	r = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	matrix[4] = a[0] / r;
	matrix[5] = a[1] / r;
	matrix[6] = a[2] / r;
	matrix[0] = matrix[5] * b[2] - matrix[6] * b[1];
	matrix[1] = matrix[6] * b[0] - matrix[4] * b[2];
	matrix[2] = matrix[4] * b[1] - matrix[5] * b[0];
	r = sqrt(matrix[0] * matrix[0] + matrix[1] * matrix[1] + matrix[2] * matrix[2]);
	matrix[0] = matrix[0] / r;
	matrix[1] = matrix[1] / r;
	matrix[2] = matrix[2] / r;
	matrix[8] = matrix[6] * matrix[1] - matrix[5] * matrix[2];
	matrix[9] = matrix[4] * matrix[2] - matrix[6] * matrix[0];
	matrix[10] = matrix[5] * matrix[0] - matrix[4] * matrix[1];
	r = sqrt(matrix[8] * matrix[8] + matrix[9] * matrix[9] + matrix[10] * matrix[10]);
	matrix[8] = matrix[8] / r;
	matrix[9] = matrix[9] / r;
	matrix[10] = matrix[10] / r;
	matrix[3] = 0;
	matrix[7] = 0;
	matrix[11] = 0;
	matrix[15] = 1;
}

void e_matrixzxd(double *matrix, const double *origo, const double *point_a, const double *point_b)
{
	double r, a[3], b[3];
	if (origo != NULL)
	{
		a[0] = point_a[0] - origo[0];
		a[1] = point_a[1] - origo[1];
		a[2] = point_a[2] - origo[2];
		matrix[12] = origo[0];
		matrix[13] = origo[1];
		matrix[14] = origo[2];
		b[0] = point_b[0] - origo[0];
		b[1] = point_b[1] - origo[1];
		b[2] = point_b[2] - origo[2];
	} else
	{
		a[0] = point_a[0];
		a[1] = point_a[1];
		a[2] = point_a[2];
		matrix[12] = 0;
		matrix[13] = 0;
		matrix[14] = 0;
		b[0] = point_b[0];
		b[1] = point_b[1];
		b[2] = point_b[2];
	}
	r = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	matrix[8] = a[0] / r;
	matrix[9] = a[1] / r;
	matrix[10] = a[2] / r;
	matrix[4] = matrix[9] * b[2] - matrix[10] * b[1];
	matrix[5] = matrix[10] * b[0] - matrix[8] * b[2];
	matrix[6] = matrix[8] * b[1] - matrix[9] * b[0];
	r = sqrt(matrix[4] * matrix[4] + matrix[5] * matrix[5] + matrix[6] * matrix[6]);
	matrix[4] = matrix[4] / r;
	matrix[5] = matrix[5] / r;
	matrix[6] = matrix[6] / r;
	matrix[0] = matrix[10] * matrix[5] - matrix[9] * matrix[6];
	matrix[1] = matrix[8] * matrix[6] - matrix[10] * matrix[4];
	matrix[2] = matrix[9] * matrix[4] - matrix[8] * matrix[5];
	r = sqrt(matrix[0] * matrix[0] + matrix[1] * matrix[1] + matrix[2] * matrix[2]);
	matrix[0] = matrix[0] / r;
	matrix[1] = matrix[1] / r;
	matrix[2] = matrix[2] / r;
	matrix[3] = 0;
	matrix[7] = 0;
	matrix[11] = 0;
	matrix[15] = 1;
}

void e_matrixzyd(double *matrix, const double *origo, const double *point_a, const double *point_b)
{
	double r, a[3], b[3];
	if (origo != NULL)
	{
		a[0] = point_a[0] - origo[0];
		a[1] = point_a[1] - origo[1];
		a[2] = point_a[2] - origo[2];
		matrix[12] = origo[0];
		matrix[13] = origo[1];
		matrix[14] = origo[2];
		b[0] = point_b[0] - origo[0];
		b[1] = point_b[1] - origo[1];
		b[2] = point_b[2] - origo[2];
	} else
	{
		a[0] = point_a[0];
		a[1] = point_a[1];
		a[2] = point_a[2];
		matrix[12] = 0;
		matrix[13] = 0;
		matrix[14] = 0;
		b[0] = point_b[0];
		b[1] = point_b[1];
		b[2] = point_b[2];
	}
	r = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	matrix[8] = a[0] / r;
	matrix[9] = a[1] / r;
	matrix[10] = a[2] / r;
	matrix[0] = matrix[10] * b[1] - matrix[9] * b[2];
	matrix[1] = matrix[8] * b[2] - matrix[10] * b[0];
	matrix[2] = matrix[9] * b[0] - matrix[8] * b[1];
	r = sqrt(matrix[0] * matrix[0] + matrix[1] * matrix[1] + matrix[2] * matrix[2]);
	matrix[0] = matrix[0] / r;
	matrix[1] = matrix[1] / r;
	matrix[2] = matrix[2] / r;
	matrix[4] = matrix[9] * matrix[2] - matrix[10] * matrix[1];
	matrix[5] = matrix[10] * matrix[0] - matrix[8] * matrix[2];
	matrix[6] = matrix[8] * matrix[1] - matrix[9] * matrix[0];
	r = sqrt(matrix[4] * matrix[4] + matrix[5] * matrix[5] + matrix[6] * matrix[6]);
	matrix[4] = matrix[4] / r;
	matrix[5] = matrix[5] / r;
	matrix[6] = matrix[6] / r;
	matrix[3] = 0;
	matrix[7] = 0;
	matrix[11] = 0;
	matrix[15] = 1;
}

void e_matrix_clearf(float *matrix)
{
	matrix[0] = 1;
	matrix[1] = 0;
	matrix[2] = 0;
	matrix[3] = 0;
	matrix[4] = 0;
	matrix[5] = 1;
	matrix[6] = 0;
	matrix[7] = 0;
	matrix[8] = 0;
	matrix[9] = 0;
	matrix[10] = 1;
	matrix[11] = 0;
	matrix[12] = 0;
	matrix[13] = 0;
	matrix[14] = 0;
	matrix[15] = 1;
}

void e_transform3f(float *output, const float *matrix, const float x, const float y, const float z)
{
	output[0] = (matrix[0] * x) + (matrix[4] * y) + (matrix[8] * z) + matrix[12];
	output[1] = (matrix[1] * x) + (matrix[5] * y) + (matrix[9] * z) + matrix[13];
	output[2] = (matrix[2] * x) + (matrix[6] * y) + (matrix[10] * z) + matrix[14];
}

void e_transforminv3f(float *out, const float *matrix, float x, float y, float z)
{
	x -= matrix[12];
	y -= matrix[13];
	z -= matrix[14];
	out[0] = (matrix[0] * x) + (matrix[1] * y) + (matrix[2] * z);
	out[1] = (matrix[4] * x) + (matrix[5] * y) + (matrix[6] * z);
	out[2] = (matrix[8] * x) + (matrix[9] * y) + (matrix[10] * z);
}

void e_transform4f(float *output, const float *matrix, const float x, const float y, const float z, const double w)
{
	output[0] = (matrix[0] * x) + (matrix[4] * y) + (matrix[8] * z) + (matrix[12] * w);
	output[1] = (matrix[1] * x) + (matrix[5] * y) + (matrix[9] * z) + (matrix[13] * w);
	output[2] = (matrix[2] * x) + (matrix[6] * y) + (matrix[10] * z) + (matrix[14] * w);
	output[3] = (matrix[3] * x) + (matrix[7] * y) + (matrix[11] * z) + (matrix[15] * w);
}

void e_matrix_multiplyf(float *output, const float *a, const float *b)
{
	output[0] = (b[0] * a[0]) + (b[1] * a[4]) + (b[2] * a[8]) + (b[3] * a[12]);
	output[4] = (b[4] * a[0]) + (b[5] * a[4]) + (b[6] * a[8]) + (b[7] * a[12]);
	output[8] = (b[8] * a[0]) + (b[9] * a[4]) + (b[10] * a[8]) + (b[11] * a[12]);
	output[12] = (b[12] * a[0]) + (b[13] * a[4]) + (b[14] * a[8]) + (b[15] * a[12]);

	output[1] = (b[0] * a[1]) + (b[1] * a[5]) + (b[2] * a[9]) + (b[3] * a[13]);
	output[5] = (b[4] * a[1]) + (b[5] * a[5]) + (b[6] * a[9]) + (b[7] * a[13]);
	output[9] = (b[8] * a[1]) + (b[9] * a[5]) + (b[10] * a[9]) + (b[11] * a[13]);
	output[13] = (b[12] * a[1]) + (b[13] * a[5]) + (b[14] * a[9]) + (b[15] * a[13]);

	output[2] = (b[0] * a[2]) + (b[1] * a[6]) + (b[2] * a[10]) + (b[3] * a[14]);
	output[6] = (b[4] * a[2]) + (b[5] * a[6]) + (b[6] * a[10]) + (b[7] * a[14]);
	output[10] = (b[8] * a[2]) + (b[9] * a[6]) + (b[10] * a[10]) + (b[11] * a[14]);
	output[14] = (b[12] * a[2]) + (b[13] * a[6]) + (b[14] * a[10]) + (b[15] * a[14]);

	output[3] = (b[0] * a[3]) + (b[1] * a[7]) + (b[2] * a[11]) + (b[3] * a[15]);
	output[7] = (b[4] * a[3]) + (b[5] * a[7]) + (b[6] * a[11]) + (b[7] * a[15]);
	output[11] = (b[8] * a[3]) + (b[9] * a[7]) + (b[10] * a[11]) + (b[11] * a[15]);
	output[15] = (b[12] * a[3]) + (b[13] * a[7]) + (b[14] * a[11]) + (b[15] * a[15]);
}

void e_matrix_reverse4d(double *output, const double *matrix)
{
	output[0] = matrix[5] * matrix[10] * matrix[15] + matrix[6] * matrix[11] * matrix[13] + matrix[7] * matrix[9] * matrix[14] - matrix[5] * matrix[11] * matrix[14] - matrix[6] * matrix[9] * matrix[15] - matrix[7] * matrix[10] * matrix[13];
	output[1] = matrix[1] * matrix[11] * matrix[14] + matrix[2] * matrix[9] * matrix[15] + matrix[3] * matrix[10] * matrix[13] - matrix[1] * matrix[10] * matrix[15] - matrix[2] * matrix[11] * matrix[13] - matrix[3] * matrix[9] * matrix[14];
	output[2] = matrix[1] * matrix[6] * matrix[15] + matrix[2] * matrix[7] * matrix[13] + matrix[3] * matrix[5] * matrix[14] - matrix[1] * matrix[7] * matrix[14] - matrix[2] * matrix[5] * matrix[15] - matrix[3] * matrix[6] * matrix[13];
	output[3] = matrix[1] * matrix[7] * matrix[10] + matrix[2] * matrix[5] * matrix[11] + matrix[3] * matrix[6] * matrix[9] - matrix[1] * matrix[6] * matrix[11] - matrix[2] * matrix[7] * matrix[9] - matrix[3] * matrix[5] * matrix[10];
	output[4] = matrix[4] * matrix[11] * matrix[14] + matrix[6] * matrix[8] * matrix[15] + matrix[7] * matrix[10] * matrix[12] - matrix[4] * matrix[10] * matrix[15] - matrix[6] * matrix[11] * matrix[12] - matrix[7] * matrix[8] * matrix[14];
	output[5] = matrix[0] * matrix[10] * matrix[15] + matrix[2] * matrix[11] * matrix[12] + matrix[3] * matrix[8] * matrix[14] - matrix[0] * matrix[11] * matrix[14] - matrix[2] * matrix[8] * matrix[15] - matrix[3] * matrix[10] * matrix[12];
	output[6] = matrix[0] * matrix[7] * matrix[14] + matrix[2] * matrix[4] * matrix[15] + matrix[3] * matrix[6] * matrix[12] - matrix[0] * matrix[6] * matrix[15] - matrix[2] * matrix[7] * matrix[12] - matrix[3] * matrix[4] * matrix[14];
	output[7] = matrix[0] * matrix[6] * matrix[11] + matrix[2] * matrix[7] * matrix[8] + matrix[3] * matrix[4] * matrix[10] - matrix[0] * matrix[7] * matrix[10] - matrix[2] * matrix[4] * matrix[11] - matrix[3] * matrix[6] * matrix[8];
	output[8] = matrix[4] * matrix[9] * matrix[15] + matrix[5] * matrix[11] * matrix[12] + matrix[7] * matrix[8] * matrix[13] - matrix[4] * matrix[11] * matrix[13] - matrix[5] * matrix[8] * matrix[15] - matrix[7] * matrix[9] * matrix[12];
	output[9] = matrix[0] * matrix[11] * matrix[13] + matrix[1] * matrix[8] * matrix[15] + matrix[3] * matrix[9] * matrix[12] - matrix[0] * matrix[9] * matrix[15] - matrix[1] * matrix[11] * matrix[12] - matrix[3] * matrix[8] * matrix[13];
	output[10] = matrix[0] * matrix[5] * matrix[15] + matrix[1] * matrix[7] * matrix[12] + matrix[3] * matrix[4] * matrix[13] - matrix[0] * matrix[7] * matrix[13] - matrix[1] * matrix[4] * matrix[15] - matrix[3] * matrix[5] * matrix[12];
	output[11] = matrix[0] * matrix[7] * matrix[9] + matrix[1] * matrix[4] * matrix[11] + matrix[3] * matrix[5] * matrix[8] - matrix[0] * matrix[5] * matrix[11] - matrix[1] * matrix[7] * matrix[8] - matrix[3] * matrix[4] * matrix[9];
	output[12] = matrix[4] * matrix[10] * matrix[13] + matrix[5] * matrix[8] * matrix[14] + matrix[6] * matrix[9] * matrix[12] - matrix[4] * matrix[9] * matrix[14] - matrix[5] * matrix[10] * matrix[12] - matrix[6] * matrix[8] * matrix[13];
	output[13] = matrix[0] * matrix[9] * matrix[14] + matrix[1] * matrix[10] * matrix[12] + matrix[2] * matrix[8] * matrix[13] - matrix[0] * matrix[10] * matrix[13] - matrix[1] * matrix[8] * matrix[14] - matrix[2] * matrix[9] * matrix[12];
	output[14] = matrix[0] * matrix[6] * matrix[13] + matrix[1] * matrix[4] * matrix[14] + matrix[2] * matrix[5] * matrix[12] - matrix[0] * matrix[5] * matrix[14] - matrix[1] * matrix[6] * matrix[12] - matrix[2] * matrix[4] * matrix[13];
	output[15] = matrix[0] * matrix[5] * matrix[10] + matrix[1] * matrix[6] * matrix[8] + matrix[2] * matrix[4] * matrix[9] - matrix[0] * matrix[6] * matrix[9] - matrix[1] * matrix[4] * matrix[10] - matrix[2] * matrix[5] * matrix[8];
}

void e_matrix_reverse4f(float *output, const float *matrix)
{
	output[0] = matrix[5] * matrix[10] * matrix[15] + matrix[6] * matrix[11] * matrix[13] + matrix[7] * matrix[9] * matrix[14] - matrix[5] * matrix[11] * matrix[14] - matrix[6] * matrix[9] * matrix[15] - matrix[7] * matrix[10] * matrix[13];
	output[1] = matrix[1] * matrix[11] * matrix[14] + matrix[2] * matrix[9] * matrix[15] + matrix[3] * matrix[10] * matrix[13] - matrix[1] * matrix[10] * matrix[15] - matrix[2] * matrix[11] * matrix[13] - matrix[3] * matrix[9] * matrix[14];
	output[2] = matrix[1] * matrix[6] * matrix[15] + matrix[2] * matrix[7] * matrix[13] + matrix[3] * matrix[5] * matrix[14] - matrix[1] * matrix[7] * matrix[14] - matrix[2] * matrix[5] * matrix[15] - matrix[3] * matrix[6] * matrix[13];
	output[3] = matrix[1] * matrix[7] * matrix[10] + matrix[2] * matrix[5] * matrix[11] + matrix[3] * matrix[6] * matrix[9] - matrix[1] * matrix[6] * matrix[11] - matrix[2] * matrix[7] * matrix[9] - matrix[3] * matrix[5] * matrix[10];
	output[4] = matrix[4] * matrix[11] * matrix[14] + matrix[6] * matrix[8] * matrix[15] + matrix[7] * matrix[10] * matrix[12] - matrix[4] * matrix[10] * matrix[15] - matrix[6] * matrix[11] * matrix[12] - matrix[7] * matrix[8] * matrix[14];
	output[5] = matrix[0] * matrix[10] * matrix[15] + matrix[2] * matrix[11] * matrix[12] + matrix[3] * matrix[8] * matrix[14] - matrix[0] * matrix[11] * matrix[14] - matrix[2] * matrix[8] * matrix[15] - matrix[3] * matrix[10] * matrix[12];
	output[6] = matrix[0] * matrix[7] * matrix[14] + matrix[2] * matrix[4] * matrix[15] + matrix[3] * matrix[6] * matrix[12] - matrix[0] * matrix[6] * matrix[15] - matrix[2] * matrix[7] * matrix[12] - matrix[3] * matrix[4] * matrix[14];
	output[7] = matrix[0] * matrix[6] * matrix[11] + matrix[2] * matrix[7] * matrix[8] + matrix[3] * matrix[4] * matrix[10] - matrix[0] * matrix[7] * matrix[10] - matrix[2] * matrix[4] * matrix[11] - matrix[3] * matrix[6] * matrix[8];
	output[8] = matrix[4] * matrix[9] * matrix[15] + matrix[5] * matrix[11] * matrix[12] + matrix[7] * matrix[8] * matrix[13] - matrix[4] * matrix[11] * matrix[13] - matrix[5] * matrix[8] * matrix[15] - matrix[7] * matrix[9] * matrix[12];
	output[9] = matrix[0] * matrix[11] * matrix[13] + matrix[1] * matrix[8] * matrix[15] + matrix[3] * matrix[9] * matrix[12] - matrix[0] * matrix[9] * matrix[15] - matrix[1] * matrix[11] * matrix[12] - matrix[3] * matrix[8] * matrix[13];
	output[10] = matrix[0] * matrix[5] * matrix[15] + matrix[1] * matrix[7] * matrix[12] + matrix[3] * matrix[4] * matrix[13] - matrix[0] * matrix[7] * matrix[13] - matrix[1] * matrix[4] * matrix[15] - matrix[3] * matrix[5] * matrix[12];
	output[11] = matrix[0] * matrix[7] * matrix[9] + matrix[1] * matrix[4] * matrix[11] + matrix[3] * matrix[5] * matrix[8] - matrix[0] * matrix[5] * matrix[11] - matrix[1] * matrix[7] * matrix[8] - matrix[3] * matrix[4] * matrix[9];
	output[12] = matrix[4] * matrix[10] * matrix[13] + matrix[5] * matrix[8] * matrix[14] + matrix[6] * matrix[9] * matrix[12] - matrix[4] * matrix[9] * matrix[14] - matrix[5] * matrix[10] * matrix[12] - matrix[6] * matrix[8] * matrix[13];
	output[13] = matrix[0] * matrix[9] * matrix[14] + matrix[1] * matrix[10] * matrix[12] + matrix[2] * matrix[8] * matrix[13] - matrix[0] * matrix[10] * matrix[13] - matrix[1] * matrix[8] * matrix[14] - matrix[2] * matrix[9] * matrix[12];
	output[14] = matrix[0] * matrix[6] * matrix[13] + matrix[1] * matrix[4] * matrix[14] + matrix[2] * matrix[5] * matrix[12] - matrix[0] * matrix[5] * matrix[14] - matrix[1] * matrix[6] * matrix[12] - matrix[2] * matrix[4] * matrix[13];
	output[15] = matrix[0] * matrix[5] * matrix[10] + matrix[1] * matrix[6] * matrix[8] + matrix[2] * matrix[4] * matrix[9] - matrix[0] * matrix[6] * matrix[9] - matrix[1] * matrix[4] * matrix[10] - matrix[2] * matrix[5] * matrix[8];
}
void e_matrix_cleard(double *matrix)
{
	matrix[0] = 1;
	matrix[1] = 0;
	matrix[2] = 0;
	matrix[3] = 0;
	matrix[4] = 0;
	matrix[5] = 1;
	matrix[6] = 0;
	matrix[7] = 0;
	matrix[8] = 0;
	matrix[9] = 0;
	matrix[10] = 1;
	matrix[11] = 0;
	matrix[12] = 0;
	matrix[13] = 0;
	matrix[14] = 0;
	matrix[15] = 1;
}

void e_transform3d(double *out, const double *matrix, const double x, const double y, const double z)
{
	out[0] = (matrix[0] * x) + (matrix[4] * y) + (matrix[8] * z) + matrix[12];
	out[1] = (matrix[1] * x) + (matrix[5] * y) + (matrix[9] * z) + matrix[13];
	out[2] = (matrix[2] * x) + (matrix[6] * y) + (matrix[10] * z) + matrix[14];
}

void e_transforminv3d(double *out, const double *matrix, double x, double y, double z)
{
	x = x - matrix[12];
	y = y - matrix[13];
	z = z - matrix[14];
	out[0] = (matrix[0] * x) + (matrix[1] * y) + (matrix[2] * z);
	out[1] = (matrix[4] * x) + (matrix[5] * y) + (matrix[6] * z);
	out[2] = (matrix[8] * x) + (matrix[9] * y) + (matrix[10] * z);
}

void e_transform4d(double *out, const double *matrix, const double x, const double y, const double z, const double w)
{
	out[0] = (matrix[0] * x) + (matrix[4] * y) + (matrix[8] * z) + (matrix[12] * w);
	out[1] = (matrix[1] * x) + (matrix[5] * y) + (matrix[9] * z) + (matrix[13] * w);
	out[2] = (matrix[2] * x) + (matrix[6] * y) + (matrix[10] * z) + (matrix[14] * w);
	out[3] = (matrix[3] * x) + (matrix[7] * y) + (matrix[11] * z) + (matrix[15] * w);
}

void e_matrix_multiplyd(double *output, const double *a, const double *b)
{
	output[0] = (b[0] * a[0]) + (b[1] * a[4]) + (b[2] * a[8]) + (b[3] * a[12]);
	output[4] = (b[4] * a[0]) + (b[5] * a[4]) + (b[6] * a[8]) + (b[7] * a[12]);
	output[8] = (b[8] * a[0]) + (b[9] * a[4]) + (b[10] * a[8]) + (b[11] * a[12]);
	output[12] = (b[12] * a[0]) + (b[13] * a[4]) + (b[14] * a[8]) + (b[15] * a[12]);

	output[1] = (b[0] * a[1]) + (b[1] * a[5]) + (b[2] * a[9]) + (b[3] * a[13]);
	output[5] = (b[4] * a[1]) + (b[5] * a[5]) + (b[6] * a[9]) + (b[7] * a[13]);
	output[9] = (b[8] * a[1]) + (b[9] * a[5]) + (b[10] * a[9]) + (b[11] * a[13]);
	output[13] = (b[12] * a[1]) + (b[13] * a[5]) + (b[14] * a[9]) + (b[15] * a[13]);

	output[2] = (b[0] * a[2]) + (b[1] * a[6]) + (b[2] * a[10]) + (b[3] * a[14]);
	output[6] = (b[4] * a[2]) + (b[5] * a[6]) + (b[6] * a[10]) + (b[7] * a[14]);
	output[10] = (b[8] * a[2]) + (b[9] * a[6]) + (b[10] * a[10]) + (b[11] * a[14]);
	output[14] = (b[12] * a[2]) + (b[13] * a[6]) + (b[14] * a[10]) + (b[15] * a[14]);

	output[3] = (b[0] * a[3]) + (b[1] * a[7]) + (b[2] * a[11]) + (b[3] * a[15]);
	output[7] = (b[4] * a[3]) + (b[5] * a[7]) + (b[6] * a[11]) + (b[7] * a[15]);
	output[11] = (b[8] * a[3]) + (b[9] * a[7]) + (b[10] * a[11]) + (b[11] * a[15]);
	output[15] = (b[12] * a[3]) + (b[13] * a[7]) + (b[14] * a[11]) + (b[15] * a[15]);
}

void e_quaternion_to_matrixf(float *matrix, float x, float y, float z, float w)
{
	float xx, xy, xz, xw, yy, yz, yw, zz, zw;
	xx = sqrt(x * x + y * y + z * z + w * w);
	x /= xx;
	y /= xx;
	z /= xx;
	w /= xx;
	xx = x * x;
    xy = x * y;
    xz = x * z;
    xw = x * w;
    yy = y * y;
    yz = y * z;
    yw = y * w;
    zz = z * z;
    zw = z * w;
    matrix[0]  = 1 - 2 * (yy + zz);
    matrix[1]  = 2 * (xy - zw);
    matrix[2]  = 2 * (xz + yw);
    matrix[4]  = 2 * (xy + zw);
    matrix[5]  = 1 - 2 * (xx + zz);
    matrix[6]  = 2 * (yz - xw);
    matrix[8]  = 2 * (xz - yw);
    matrix[9]  = 2 * (yz + xw);
    matrix[10] = 1 - 2 * (xx + yy);
    matrix[3]  = matrix[7] = matrix[11] = matrix[12] = matrix[13] = matrix[14] = 0;
    matrix[15] = 1;
}

void e_matrix_to_quaternionf(float *quaternion, float *matrix)
{
	float trace, s;
	trace = matrix[0 * 4 + 0] + matrix[1 * 4 + 1] + matrix[2 * 4 + 2];
	if (trace > 0.0f)
	{
		s = 0.5f / sqrt(trace + 1.0f);
		quaternion[3] = 0.25f / s;
		quaternion[0] = (matrix[2 * 4 + 1] - matrix[1 * 4 + 2]) * s;
		quaternion[1] = (matrix[0 * 4 + 2] - matrix[2 * 4 + 0]) * s;
		quaternion[2] = (matrix[1 * 4 + 0] - matrix[0 * 4 + 1]) * s;
	} else
	{
		if (matrix[0 * 4 + 0] > matrix[1 * 4 + 1] && matrix[0 * 4 + 0] > matrix[2 * 4 + 2])
		{
			s = 2.0f * sqrt(1.0f + matrix[0 * 4 + 0] - matrix[1 * 4 + 1] - matrix[2 * 4 + 2]);
			quaternion[3] = (matrix[2 * 4 + 1] - matrix[1 * 4 + 2]) / s;
			quaternion[0] = 0.25f * s;
			quaternion[1] = (matrix[0 * 4 + 1] + matrix[1 * 4 + 0]) / s;
			quaternion[2] = (matrix[0 * 4 + 2] + matrix[2 * 4 + 0]) / s;
		} else if (matrix[1 * 4 + 1] > matrix[2 * 4 + 2])
		{
			s = 2.0f * sqrt(1.0f + matrix[1 * 4 + 1] - matrix[0 * 4 + 0] - matrix[2 * 4 + 2]);
			quaternion[3] = (matrix[0 * 4 + 2] - matrix[2 * 4 + 0]) / s;
			quaternion[0] = (matrix[0 * 4 + 1] + matrix[1 * 4 + 0]) / s;
			quaternion[1] = 0.25f * s;
			quaternion[2] = (matrix[1 * 4 + 2] + matrix[2 * 4 + 1]) / s;
		} else
		{
			s = 2.0f * sqrt(1.0f + matrix[2 * 4 + 2] - matrix[0 * 4 + 0] - matrix[1 * 4 + 1]);
			quaternion[3] = (matrix[1 * 4 + 0] - matrix[0 * 4 + 1]) / s;
			quaternion[0] = (matrix[0 * 4 + 2] + matrix[2 * 4 + 0]) / s;
			quaternion[1] = (matrix[1 * 4 + 2] + matrix[2 * 4 + 1]) / s;
			quaternion[2] = 0.25f * s;
		}
	}
	s = sqrt(quaternion[0] * quaternion[0] + quaternion[1] * quaternion[1] + quaternion[2] * quaternion[2] + quaternion[3] * quaternion[3]);
	quaternion[0] /= s;
	quaternion[1] /= s;
	quaternion[2] /= s;
	quaternion[3] /= s;
}

extern float e_length3f(float *vec);

void e_matrix_to_pos_quaternion_scalef(float *matrix, float *pos, float *quaternion, float *scale)
{
	e_matrix_to_quaternionf(quaternion, matrix);
	pos[0] = matrix[12];
	pos[1] = matrix[13];
	pos[2] = matrix[14];
	scale[0] = e_length3f(matrix);
	scale[1] = e_length3f(&matrix[4]);
	scale[2] = e_length3f(&matrix[8]);
}


void e_pos_quaternion_scale_to_matrixf(float *pos, float *quaternion, float *scale, float *matrix)
{
	e_quaternion_to_matrixf(matrix, quaternion[0], quaternion[1], quaternion[2], quaternion[3]);
	matrix[12] = pos[0];
	matrix[13] = pos[1];
	matrix[14] = pos[2];
	matrix[0] *= scale[0];
	matrix[1] *= scale[0];
	matrix[2] *= scale[0];
	matrix[4] *= scale[1];
	matrix[5] *= scale[1];
	matrix[6] *= scale[1];
	matrix[8] *= scale[2];
	matrix[9] *= scale[2];
	matrix[10] *= scale[2];
}

void e_quaternion_to_matrixd(double *matrix, double x, double y, double z, double w)
{
	double xx, xy, xz, xw, yy, yz, yw, zz, zw;
	xx = x * x;
    xy = x * y;
    xz = x * z;
    xw = x * w;
    yy = y * y;
    yz = y * z;
    yw = y * w;
    zz = z * z;
    zw = z * w;
    matrix[0]  = 1 - 2 * (yy + zz);
    matrix[1]  = 2 * (xy - zw);
    matrix[2]  = 2 * (xz + yw);
    matrix[4]  = 2 * (xy + zw);
    matrix[5]  = 1 - 2 * (xx + zz);
    matrix[6]  = 2 * (yz - xw);
    matrix[8]  = 2 * (xz - yw);
    matrix[9]  = 2 * (yz + xw);
    matrix[10] = 1 - 2 * (xx + yy);
    matrix[3]  = matrix[7] = matrix[11] = matrix[12] = matrix[13] = matrix[14] = 0;
    matrix[15] = 1;
}

void e_matrix_to_quaterniond(double *quaternion, double *matrix)
{
	double trace, s;
	trace = matrix[0 * 4 + 0] + matrix[1 * 4 + 1] + matrix[2 * 4 + 2];
	if (trace > 0.0)
	{
		s = 0.f / sqrt(trace + 1.0);
		quaternion[3] = 0.25 / s;
		quaternion[0] = (matrix[2 * 4 + 1] - matrix[1 * 4 + 2]) * s;
		quaternion[1] = (matrix[0 * 4 + 2] - matrix[2 * 4 + 0]) * s;
		quaternion[2] = (matrix[1 * 4 + 0] - matrix[0 * 4 + 1]) * s;
	} else
	{
		if (matrix[0 * 4 + 0] > matrix[1 * 4 + 1] && matrix[0 * 4 + 0] > matrix[2 * 4 + 2])
		{
			s = 2.0 * sqrt(1.0f + matrix[0 * 4 + 0] - matrix[1 * 4 + 1] - matrix[2 * 4 + 2]);
			quaternion[3] = (matrix[2 * 4 + 1] - matrix[1 * 4 + 2]) / s;
			quaternion[0] = 0.25 * s;
			quaternion[1] = (matrix[0 * 4 + 1] + matrix[1 * 4 + 0]) / s;
			quaternion[2] = (matrix[0 * 4 + 2] + matrix[2 * 4 + 0]) / s;
		} else if (matrix[1 * 4 + 1] > matrix[2 * 4 + 2])
		{
			s = 2.0 * sqrt(1.0f + matrix[1 * 4 + 1] - matrix[0 * 4 + 0] - matrix[2 * 4 + 2]);
			quaternion[3] = (matrix[0 * 4 + 2] - matrix[2 * 4 + 0]) / s;
			quaternion[0] = (matrix[0 * 4 + 1] + matrix[1 * 4 + 0]) / s;
			quaternion[1] = 0.25 * s;
			quaternion[2] = (matrix[1 * 4 + 2] + matrix[2 * 4 + 1]) / s;
		} else
		{
			s = 2.0 * sqrt(1.0 + matrix[2 * 4 + 2] - matrix[0 * 4 + 0] - matrix[1 * 4 + 1]);
			quaternion[3] = (matrix[1 * 4 + 0] - matrix[0 * 4 + 1]) / s;
			quaternion[0] = (matrix[0 * 4 + 2] + matrix[2 * 4 + 0]) / s;
			quaternion[1] = (matrix[1 * 4 + 2] + matrix[2 * 4 + 1]) / s;
			quaternion[2] = 0.25 * s;
		}
	}
}

extern double e_length3d(double *vec);

void e_matrix_to_pos_quaternion_scaled(double *matrix, double *pos, double *quaternion, double *scale)
{
	e_matrix_to_quaterniond(quaternion, matrix);
	pos[0] = matrix[12];
	pos[1] = matrix[13];
	pos[2] = matrix[14];
	scale[0] = e_length3d(matrix);
	scale[1] = e_length3d(&matrix[4]);
	scale[2] = e_length3d(&matrix[8]);
}


void e_pos_quaternion_scale_to_matrixd(double *pos, double *quaternion, double *scale, double *matrix)
{
	e_quaternion_to_matrixd(matrix, quaternion[0], quaternion[1], quaternion[2], quaternion[3]);
	matrix[12] = pos[0];
	matrix[13] = pos[1];
	matrix[14] = pos[2];
	matrix[0] *= scale[0];
	matrix[1] *= scale[0];
	matrix[2] *= scale[0];
	matrix[4] *= scale[1];
	matrix[5] *= scale[1];
	matrix[6] *= scale[1];
	matrix[8] *= scale[2];
	matrix[9] *= scale[2];
	matrix[10] *= scale[2];
}

/* #define E_MATRIX_CODE_GEN */

#ifdef E_MATRIX_CODE_GEN

#include <stdio.h>

void e_gen_matrix_code(FILE *f, int a, int b, char *type, char *letter, int neg)
{
	char *axis[3] = {"x", "y", "z"};
	int c;
	c = 3 - (a + b);
/*	fprintf(f, "extern void e_matrix%s%s%s(%s *matrix, const %s *origo, const %s *point_a, const %s *point_b);\n", axis[a], axis[b], letter, type, type, type, type);*/

	fprintf(f, "void e_matrix%s%s%s(%s *matrix, const %s *origo, const %s *point_a, const %s *point_b)\n", axis[a], axis[b], letter, type, type, type, type);
	fprintf(f, "{\n");
	fprintf(f, "\t%s r, a[3], b[3];\n", type);
	fprintf(f, "\tif (origo != NULL)\n");
	fprintf(f, "\t{\n");
	fprintf(f, "\t\ta[0] = point_a[0] - origo[0];\n");
	fprintf(f, "\t\ta[1] = point_a[1] - origo[1];\n");
	fprintf(f, "\t\ta[2] = point_a[2] - origo[2];\n");
	fprintf(f, "\t\tmatrix[12] = origo[0];\n");
	fprintf(f, "\t\tmatrix[13] = origo[1];\n");
	fprintf(f, "\t\tmatrix[14] = origo[2];\n");
	fprintf(f, "\t\tb[0] = point_b[0] - origo[0];\n");
	fprintf(f, "\t\tb[1] = point_b[1] - origo[1];\n");
	fprintf(f, "\t\tb[2] = point_b[2] - origo[2];\n");
	fprintf(f, "\t} else\n");
	fprintf(f, "\t{\n");
	fprintf(f, "\t\ta[0] = point_a[0];\n");
	fprintf(f, "\t\ta[1] = point_a[1];\n");
	fprintf(f, "\t\ta[2] = point_a[2];\n");
	fprintf(f, "\t\tmatrix[12] = 0;\n");
	fprintf(f, "\t\tmatrix[13] = 0;\n");
	fprintf(f, "\t\tmatrix[14] = 0;\n");
	fprintf(f, "\t\tb[0] = point_b[0];\n");
	fprintf(f, "\t\tb[1] = point_b[1];\n");
	fprintf(f, "\t\tb[2] = point_b[2];\n");
	fprintf(f, "\t}\n");
	fprintf(f, "\tr = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);\n");
	fprintf(f, "\tmatrix[%u] = a[0] / r;\n", a * 4);
	fprintf(f, "\tmatrix[%u] = a[1] / r;\n", a * 4 + 1);
	fprintf(f, "\tmatrix[%u] = a[2] / r;\n", a * 4 + 2);
	if (neg)
	{
		fprintf(f, "\tmatrix[%u] = matrix[%u] * b[1] - matrix[%u] * b[2];\n", c * 4 + 0, a * 4 + 2, a * 4 + 1);
		fprintf(f, "\tmatrix[%u] = matrix[%u] * b[2] - matrix[%u] * b[0];\n", c * 4 + 1, a * 4 + 0, a * 4 + 2);
		fprintf(f, "\tmatrix[%u] = matrix[%u] * b[0] - matrix[%u] * b[1];\n", c * 4 + 2, a * 4 + 1, a * 4 + 0);
	} else
	{
		fprintf(f, "\tmatrix[%u] = matrix[%u] * b[2] - matrix[%u] * b[1];\n", c * 4 + 0, a * 4 + 1, a * 4 + 2);
		fprintf(f, "\tmatrix[%u] = matrix[%u] * b[0] - matrix[%u] * b[2];\n", c * 4 + 1, a * 4 + 2, a * 4 + 0);
		fprintf(f, "\tmatrix[%u] = matrix[%u] * b[1] - matrix[%u] * b[0];\n", c * 4 + 2, a * 4 + 0, a * 4 + 1);
	}
	fprintf(f, "\tr = sqrt(matrix[%u] * matrix[%u] + matrix[%u] * matrix[%u] + matrix[%u] * matrix[%u]);\n", c * 4 + 0, c * 4 + 0, c * 4 + 1, c * 4 + 1, c * 4 + 2, c * 4 + 2);
	fprintf(f, "\tmatrix[%u] = matrix[%u] / r;\n", c * 4 + 0, c * 4 + 0);
	fprintf(f, "\tmatrix[%u] = matrix[%u] / r;\n", c * 4 + 1, c * 4 + 1);
	fprintf(f, "\tmatrix[%u] = matrix[%u] / r;\n", c * 4 + 2, c * 4 + 2);
	if (neg)
	{
		fprintf(f, "\tmatrix[%u] = matrix[%u] * matrix[%u] - matrix[%u] * matrix[%u];\n", b * 4 + 0, a * 4 + 1, c * 4 + 2, a * 4 + 2, c * 4 + 1);
		fprintf(f, "\tmatrix[%u] = matrix[%u] * matrix[%u] - matrix[%u] * matrix[%u];\n", b * 4 + 1, a * 4 + 2, c * 4 + 0, a * 4 + 0, c * 4 + 2);
		fprintf(f, "\tmatrix[%u] = matrix[%u] * matrix[%u] - matrix[%u] * matrix[%u];\n", b * 4 + 2, a * 4 + 0, c * 4 + 1, a * 4 + 1, c * 4 + 0);
	} else
	{
		fprintf(f, "\tmatrix[%u] = matrix[%u] * matrix[%u] - matrix[%u] * matrix[%u];\n", b * 4 + 0, a * 4 + 2, c * 4 + 1, a * 4 + 1, c * 4 + 2);
		fprintf(f, "\tmatrix[%u] = matrix[%u] * matrix[%u] - matrix[%u] * matrix[%u];\n", b * 4 + 1, a * 4 + 0, c * 4 + 2, a * 4 + 2, c * 4 + 0);
		fprintf(f, "\tmatrix[%u] = matrix[%u] * matrix[%u] - matrix[%u] * matrix[%u];\n", b * 4 + 2, a * 4 + 1, c * 4 + 0, a * 4 + 0, c * 4 + 1);
	}
	fprintf(f, "\tr = sqrt(matrix[%u] * matrix[%u] + matrix[%u] * matrix[%u] + matrix[%u] * matrix[%u]);\n", b * 4 + 0, b * 4 + 0, b * 4 + 1, b * 4 + 1, b * 4 + 2, b * 4 + 2);
	fprintf(f, "\tmatrix[%u] = matrix[%u] / r;\n", b * 4 + 0, b * 4 + 0);
	fprintf(f, "\tmatrix[%u] = matrix[%u] / r;\n", b * 4 + 1, b * 4 + 1);
	fprintf(f, "\tmatrix[%u] = matrix[%u] / r;\n", b * 4 + 2, b * 4 + 2);
	fprintf(f, "\tmatrix[3] = 0;\n");
	fprintf(f, "\tmatrix[7] = 0;\n");
	fprintf(f, "\tmatrix[11] = 0;\n");
	fprintf(f, "\tmatrix[15] = 1;\n");
	fprintf(f, "}\n\n");
}



int main()
{
	FILE *f;
	int i, j, neg[9] = {-1, 0, 1, 1, -1, 0, 0, 1, -1};
	f = fopen("e_matrix_make.c", "w");
	fprintf(f, "#include <math.h>\n");
	fprintf(f, "#define NULL (void*)0\n\n");
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (i != j)
				e_gen_matrix_code(f, i, j, "float", "f", neg[i * 3 + j]);
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (i != j)
				e_gen_matrix_code(f, i, j, "double", "d", neg[i * 3 + j]);
	fclose(f);
}

#endif
