#include <iostream>
using namespace std;

int arr[501][501];
int n;
int m;
int pos[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
int num[501][501];
bool checkPath(int r, int c)
{
	if (r >= 0 && r <= m - 1 && c >= 0 && c <= n - 1)
		return true;
	else
		return false;
}
int path(int r, int c)
{
	int count = 0;

	for (int i = 0; i < 4; i++)
	{
		if (checkPath(r + pos[i][0], c + pos[i][1]))
		{
			if (arr[r][c] > arr[r + pos[i][0]][c + pos[i][1]])
			{
				if (num[r + pos[i][0]][c + pos[i][1]] != -1)
				{
					count += num[r + pos[i][0]][c + pos[i][1]];
				}
				else
					count += path(r + pos[i][0], c + pos[i][1]);
			}
		}
	}
	num[r][c] = count;
	return count;
}

int main()
{
	int count = 0;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			num[i][j] = -1;
		}
	}
	if (m == 1 && n == 1)
	{
		cout << 1;
		return 0;
	}
	num[m - 1][n - 1] = 1;
	count = path(0, 0);
	cout << count;
}