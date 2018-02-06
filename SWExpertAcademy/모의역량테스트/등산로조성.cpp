#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[9][9];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int n, k;
bool check[9][9];
int dfs(int row, int col, bool di, int depth)
{
	int maxNum = depth;
	for (int i = 0; i < 4; i++)
	{
		int dRow = row + dr[i];
		int dCol = col + dc[i];
		if (dRow >= 0 && dRow < n &&dCol >= 0 && dCol < n)
		{
			if (!check[dRow][dCol])
			{
				if (arr[row][col] > arr[dRow][dCol])
				{
					check[dRow][dCol] = true;
					maxNum = max(maxNum, dfs(dRow, dCol, di, depth + 1));
					check[dRow][dCol] = false;
				}
				else if (!di)
				{
					for (int j = 1; j <= k; j++)
					{
						arr[dRow][dCol] -= j;
						if (arr[row][col] > arr[dRow][dCol])
						{
							check[dRow][dCol] = true;
							maxNum = max(maxNum, dfs(dRow, dCol, true, depth + 1));
							check[dRow][dCol] = false;
						}
						arr[dRow][dCol] += j;
					}
				}
			}
		}
	}
	return maxNum;
}
int main()
{
	int t;
	int test = 1;
	cin >> t;
	while (t--) {
		int maxNum = 0;
		int high = -1;
		cin >> n >> k;
		memset(check, 0, sizeof(check));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				high = max(arr[i][j], high);
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == high) {
					check[i][j] = true;
					maxNum = max(maxNum, dfs(i, j, false, 1));
					check[i][j] = false;
				}
			}
		}
		cout << "#" << test++ << " " << maxNum << endl;
	}
}
