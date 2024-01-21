#include <math.h>

// ------------ FLOAT OPS ------------

// ------------ SQRT ------------
float e_sqrtf(float number)
{
	int i;
	float x, y;
	x = number * 0.5;
	y  = number;
	i  = * (int * ) &y;
	i  = 0x5f3759df - (i >> 1);
	y  = * ( float * ) &i;
	y  = y * (1.5 - (x * y * y));
	y  = y * (1.5 - (x * y * y));
	return number * y;
}

// ------------ LENGTH ------------
float e_length2f(float *vec)
{
	return e_sqrtf(vec[0] * vec[0] + vec[1] * vec[1]);
}
float e_length3f(float *vec)
{
	return e_sqrtf(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
}
double e_length2d(double *vec)
{
	return sqrt(vec[0] * vec[0] + vec[1] * vec[1]);
}
double e_length3d(double *vec)
{
	return sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
}

// ------------ DISTANCE ------------
float e_distance2f(float *a, float *b)
{
	float tmp[2];
	tmp[0] = a[0] - b[0];
	tmp[1] = a[1] - b[1];
	return e_sqrtf(tmp[0] * tmp[0] + tmp[1] * tmp[1]);
}
float e_distance3f(float *a, float *b)
{
	float tmp[3];
	tmp[0] = a[0] - b[0];
	tmp[1] = a[1] - b[1];
	tmp[2] = a[2] - b[2];
	return e_sqrtf(tmp[0] * tmp[0] + tmp[1] * tmp[1] + tmp[2] * tmp[2]);
}
double e_distance2d(double *a, double *b)
{
	double tmp[2];
	tmp[0] = a[0] - b[0];
	tmp[1] = a[1] - b[1];
	return sqrt(tmp[0] * tmp[0] + tmp[1] * tmp[1]);
}
double e_distance3d(double *a, double *b)
{
	double tmp[3];
	tmp[0] = a[0] - b[0];
	tmp[1] = a[1] - b[1];
	tmp[2] = a[2] - b[2];
	return sqrt(tmp[0] * tmp[0] + tmp[1] * tmp[1] + tmp[2] * tmp[2]);
}

// ------------ DOT PRODUCT ------------
float e_dot2f(float *a, float *b)
{
	return a[0] * b[0] + a[1] * b[1];
}
double e_dot2d(double *a, double *b)
{
	return a[0] * b[0] + a[1] * b[1];
}
float e_dot3f(float *a, float *b)
{
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}
double e_dot3d(double *a, double *b)
{
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

// ------------ CROSS PRODUCT ------------
void e_cross2f(float *output, float *a, float *b)
{
	*output = a[0] * b[1] - a[1] * b[0];
}
void e_cross3f(float *output, float *a, float *b)
{
	output[0] = a[1] * b[2] - a[2] * b[1];
	output[1] = a[2] * b[0] - a[0] * b[2];
	output[2] = a[0] * b[1] - a[1] * b[0];
}
void e_cross2d(double *output, double *a, double *b)
{
	*output = a[0] * b[1] - a[1] * b[0];
}
void e_cross3d(double *output, double *a, double *b)
{
	output[0] = a[1] * b[2] - a[2] * b[1];
	output[1] = a[2] * b[0] - a[0] * b[2];
	output[2] = a[0] * b[1] - a[1] * b[0];
}


// ------------ NORMALIZE ------------
void e_normalize2f(float *vec)
{
	float f;
	f = e_sqrtf(vec[0] * vec[0] + vec[1] * vec[1]);
	vec[0] /= f;
	vec[1] /= f;
}
void e_normalize3f(float *vec)
{
	float f;
	f = e_sqrtf(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
	vec[0] /= f;
	vec[1] /= f;
	vec[2] /= f;
}
void e_normalize4f(float *vec)
{
	float f;
	f = e_sqrtf(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2] + vec[3] * vec[3]);
	vec[0] /= f;
	vec[1] /= f;
	vec[2] /= f;
	vec[3] /= f;
}
void e_normalize2d(double *vec)
{
	double f;
	f = sqrt(vec[0] * vec[0] + vec[1] * vec[1]);
	vec[0] /= f;
	vec[1] /= f;
}
void e_normalize3d(double *vec)
{
	double f;
	f = sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
	vec[0] /= f;
	vec[1] /= f;
	vec[2] /= f;
}
void e_normalize4d(double *vec)
{
	double f;
	f = sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2] + vec[3] * vec[3]);
	vec[0] /= f;
	vec[1] /= f;
	vec[2] /= f;
	vec[3] /= f;
}

// ------------ REFLECT ------------
void e_reflect2f(float *output, float *pos, float *normal)
{
	float f;
	f = pos[0] * normal[0] + pos[1] * normal[1];
	output[0] = pos[0] - normal[0] * 2.0 * f;
	output[1] = pos[1] - normal[1] * 2.0 * f;
}
void e_reflect3f(float *output, float *pos, float *normal)
{
	float f;
	f = pos[0] * normal[0] + pos[1] * normal[1] + pos[2] * normal[2];
	output[0] = pos[0] - normal[0] * 2.0 * f;
	output[1] = pos[1] - normal[1] * 2.0 * f;
	output[2] = pos[2] - normal[2] * 2.0 * f;
}
void e_reflect2d(double *output, double *pos, double *normal)
{
	double f;
	f = pos[0] * normal[0] + pos[1] * normal[1];
	output[0] = pos[0] - normal[0] * 2.0 * f;
	output[1] = pos[1] - normal[1] * 2.0 * f;
}
void e_reflect3d(double *output, double *pos, double *normal)
{
	double f;
	f = pos[0] * normal[0] + pos[1] * normal[1] + pos[2] * normal[2];
	output[0] = pos[0] - normal[0] * 2.0 * f;
	output[1] = pos[1] - normal[1] * 2.0 * f;
	output[2] = pos[2] - normal[2] * 2.0 * f;
}

// ------------ PROJECT ------------
void e_project2f(float *output, float *pos, float *vec)
{
	float c;
	c = pos[0] * vec[0] + pos[1] * vec[1];
	c /= vec[0] * vec[0] + vec[1] * vec[1];
	output[0] = c * vec[0];
	output[1] = c * vec[1];
}
void e_project3f(float *output, float *pos, float *vec)
{
	float c;
	c = vec[0] * pos[0] + vec[1] * pos[1] + vec[2] * pos[2];
	c /= vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2];
	output[0] = vec[0] * c;
	output[1] = vec[1] * c;
	output[2] = vec[2] * c;
}
void e_project2d(double *output, double *pos, double *vec)
{
	double c;
	c = pos[0] * vec[0] + pos[1] * vec[1];
	c /= vec[0] * vec[0] + vec[1] * vec[1];
	output[0] = c * vec[0];
	output[1] = c * vec[1];
}
void e_project3d(double *output, double *pos, double *vec)
{
	double c;
	c = vec[0] * pos[0] + vec[1] * pos[1] + vec[2] * pos[2];
	c /= vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2];
	output[0] = vec[0] * c;
	output[1] = vec[1] * c;
	output[2] = vec[2] * c;
}

// ------------ NORMAL ------------
void e_normal2f(float *output, float *a, float *b)
{
	float f;
	output[0] = a[1] - b[1];
	output[1] = b[0] - a[0];
	f = e_sqrtf(output[0] * output[0] + output[1] * output[1]);
	output[0] /= f;
	output[1] /= f;
}
void e_normal3f(float *output, float *a, float *b, float *c)
{
	float a2[3], b2[3], f;
	a2[0] = a[0] - c[0];
	a2[1] = a[1] - c[1];
	a2[2] = a[2] - c[2];
	b2[0] = b[0] - c[0];
	b2[1] = b[1] - c[1];
	b2[2] = b[2] - c[2];
	output[0] = a2[1] * b2[2] - a2[2] * b2[1];
	output[1] = a2[2] * b2[0] - a2[0] * b2[2];
	output[2] = a2[0] * b2[1] - a2[1] * b2[0];
	f = e_sqrtf(output[0] * output[0] + output[1] * output[1] + output[2] * output[2]);
	output[0] /= f;
	output[1] /= f;
	output[2] /= f;
}
void e_normal2d(double *output, double *a, double *b)
{
	double f;
	output[0] = a[1] - b[1];
	output[1] = b[0] - a[0];
	f = sqrt(output[0] * output[0] + output[1] * output[1]);
	output[0] /= f;
	output[1] /= f;
}
void e_normal3d(double *output, double *a, double *b, double *c)
{
	double a2[3], b2[3], f;
	a2[0] = a[0] - c[0];
	a2[1] = a[1] - c[1];
	a2[2] = a[2] - c[2];
	b2[0] = b[0] - c[0];
	b2[1] = b[1] - c[1];
	b2[2] = b[2] - c[2];
	output[0] = a2[1] * b2[2] - a2[2] * b2[1];
	output[1] = a2[2] * b2[0] - a2[0] * b2[2];
	output[2] = a2[0] * b2[1] - a2[1] * b2[0];
	f = sqrt(output[0] * output[0] + output[1] * output[1] + output[2] * output[2]);
	output[0] /= f;
	output[1] /= f;
	output[2] /= f;
}

// ------------ INTERSECT ------------
void e_intersect2f(float *output, float *line_a0, float *line_a1, float *line_b0, float *line_b1)
{
	output[0] = (line_a0[0] * line_a1[1] - line_a0[1] * line_a1[0])	* (line_b0[0] - line_b1[0]) -
				(line_b0[0] * line_b1[1] - line_b0[1] * line_b1[0])	* (line_a0[0] - line_a1[0]);
	output[0] /= (line_a0[0] - line_a1[0]) * (line_b0[1] - line_b1[1]) - (line_a0[1] - line_a1[1]) * (line_b0[0] - line_b1[0]);
	output[1] = (line_a0[0] * line_a1[1] - line_a0[1] * line_a1[0])	* (line_b0[1] - line_b1[1]) -
				(line_b0[0] * line_b1[1] - line_b0[1] * line_b1[0])	* (line_a0[1] - line_a1[1]);
	output[1] /= (line_a0[0] - line_a1[0]) * (line_b0[1] - line_b1[1]) - (line_a0[1] - line_a1[1]) * (line_b0[0] - line_b1[0]);
}
void e_intersect2d(double *output, double *line_a0, double *line_a1, double *line_b0, double *line_b1)
{
	output[0] = (line_a0[0] * line_a1[1] - line_a0[1] * line_a1[0])	* (line_b0[0] - line_b1[0]) -
				(line_b0[0] * line_b1[1] - line_b0[1] * line_b1[0])	* (line_a0[0] - line_a1[0]);
	output[0] /= (line_a0[0] - line_a1[0]) * (line_b0[1] - line_b1[1]) - (line_a0[1] - line_a1[1]) * (line_b0[0] - line_b1[0]);
	output[1] = (line_a0[0] * line_a1[1] - line_a0[1] * line_a1[0])	* (line_b0[1] - line_b1[1]) -
				(line_b0[0] * line_b1[1] - line_b0[1] * line_b1[0])	* (line_a0[1] - line_a1[1]);
	output[1] /= (line_a0[0] - line_a1[0]) * (line_b0[1] - line_b1[1]) - (line_a0[1] - line_a1[1]) * (line_b0[0] - line_b1[0]);
}
