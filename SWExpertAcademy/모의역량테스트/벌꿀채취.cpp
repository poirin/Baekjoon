#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, c;
int arr[11][11];

int square(int a)
{
	int mul = 1;
	for (int i = 0; i < a; i++)
	{
		mul *= 2;
	}
	return mul;
}
bool isCheck(int firstRow, int firstCol, int secondRow, int secondCol)
{
	if (firstRow == secondRow&&abs(firstCol - secondCol) < m)
		return false;
	else return true;
}

int dfs(int row, int col, int whoIs)
{
	int maxNum = 0;
	int maxNum2 = 0;
	if (whoIs == 0)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - m + 1; j++)
			{
				if (isCheck(row, col, i, j))
				{
					maxNum = max(maxNum, dfs(i, j, 1));
				}
			}
		}
	}
	for (int j = 0; j < square(m); j++)
	{
		int sum = 0;
		int square = 0;
		for (int i = 0; i < m; i++)
		{
			if (j & (1 << i))
			{
				sum += arr[row][col + i];
				if (sum > c) break;
				square += arr[row][col + i] * arr[row][col + i];
			}
		}
		maxNum2 = max(maxNum2, square);
	}

	return maxNum + maxNum2;
}

int main()
{
	int t;
	int test = 1;
	int maxNum = 0;
	cin >> t;
	while (t--) {
		maxNum = 0;
		cin >> n >> m >> c;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - m + 1; j++)
			{
				maxNum = max(maxNum, dfs(i, j, 0));
			}
		}
		cout << "#" << test++ << " " << maxNum << endl;
	}
}
