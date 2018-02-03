#include <iostream>
#include <algorithm>
using namespace std;

int arr[51][51];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);
	}
	for (int k = min(n, m); k > 0; k--)
	{
		for (int i = 0; i < n - k + 1; i++)
		{
			for (int j = 0; j < m - k + 1; j++)
			{
				if (arr[i][j] == arr[i + k - 1][j] && arr[i][j] == arr[i][j + k - 1] && arr[i][j] == arr[i + k - 1][j + k - 1])
				{
					cout << k*k;
					return 0;
				}
			}
		}
	}
}