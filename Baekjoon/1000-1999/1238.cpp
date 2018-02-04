#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001][1001];
int main()
{
	int n, x, m, maxNum = 0; cin >> n >> m >> x;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] = i == j ? 0 : 9999999;

	for (int i = 0; i < m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		arr[a][b] = c;
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
		int a = arr[i][x] + arr[x][i];
		maxNum = max(maxNum, a);
	}
	cout << maxNum;
}