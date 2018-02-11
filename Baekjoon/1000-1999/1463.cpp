#include <iostream>

using namespace std;

int min(int a, int b) {
	return (a < b ? a : b);
}
int min(int a, int b, int c) {
	return min(min(a, b), c);
}

int main(void)
{
	int n;
	char arr[1000001];
	scanf("%d", &n);

	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;

	for (int i = 4; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			arr[i] = min(arr[i - 1], arr[i / 2]) + 1;
			if (i % 3 == 0) arr[i] = min(arr[i], arr[i / 3] + 1);
		}
		else if (i % 3 == 0)
		{
			arr[i] = min(arr[i - 1], arr[i / 3]) + 1;
		}
		else arr[i] = arr[i - 1] + 1;
	}
	printf("%d", arr[n]);
}