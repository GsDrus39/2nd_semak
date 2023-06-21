#include <iostream>

int main()
{
	const int N = 1000;
	int mas_1[N] = {1, 2, 3, 4, 5};
	int mas_2[N] = {0};

	const long long* ptr1 = (const long long*)mas_1;
	long long* t_ptr1 = (long long*)mas_2;
	int m = sizeof(int) * N / sizeof(long long);
	for (int i = 0; i < m; ++i)
	{
		*(t_ptr1++) = *(ptr1++);
	}
	char* ptr2 = (char*)ptr1;
	char* t_ptr2 = (char*)t_ptr1;

	m = (sizeof(int) * N) % sizeof(long long);
	for (int i = 0; i < m; i++) {
		*(t_ptr++) = *(ptr2++);
	}
}
