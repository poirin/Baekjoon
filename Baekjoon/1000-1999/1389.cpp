#include <iostream>
#include <algorithm>
using namespace std;
;
int arr[101][101];
int main()
{
	int idx = 0, n, m, minNum = 9999999; cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] = i == j ? 0 : 9999999;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		arr[a][b] = arr[b][a] = 1;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			sum += arr[i][j];
		}
		if (sum < minNum)
		{
			minNum = sum;
			idx = i;
		}
	}
	cout << idx;
}