#include <iostream>

using namespace std;

int max(int a, int b) {
	return (a > b ? a : b);
}

int main(void)
{
	int arr[501][501];
	int n;
	int maxCount = -100000000;
	scanf("%d", &n);
	for (int i = 0; i < 501; i++)
	{
		for (int j = 0; j < 501; j++)
		{
			arr[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (arr[n][i] > maxCount)
			maxCount = arr[n][i];
	}

	printf("%d", maxCount);
}