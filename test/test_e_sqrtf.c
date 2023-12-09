#include "../src/e_math.c"

int test_e_sqrtf(float a, float out)
{
	float result = e_sqrtf(a);
	if ((result-out) < 0.001 && (result-out) > -0.001)
		return 0;
	else
		return 1;
}

int main(void)
{
	for (float i = 0; i < 10; i += 0.1)
	{
		if (test_e_sqrtf(i*i, i))
		{
			printf("%s: Test failed for: %f", __FILE__, i);
			return 1;
		}
	}
	return 0;
}
