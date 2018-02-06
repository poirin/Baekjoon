#include <iostream>
#include <algorithm>
using namespace std;

int dRow[4] = { 1,1,-1,-1 };
int dCol[4] = { 1,-1,-1,1 };
int arr[21][21];
int curDesert[101];

int n;

int dfs(int row, int col, int firstRow, int firstCol, int direction, int desertIndex)
{
	int maxNum = 0;
	if (direction == 3 && row == firstRow&&col == firstCol)
		return desertIndex;
	for (int i = 0; i < desertIndex; i++)
	{
		if (curDesert[i] == arr[row][col])
		{
			return maxNum;
		}
	}
	curDesert[desertIndex++] = arr[row][col];
	if (row + dRow[direction] >= 0 && row + dRow[direction] < n&&col + dCol[direction] >= 0 && col + dCol[direction] < n)
	{
		maxNum = max(maxNum, dfs(row + dRow[direction], col + dCol[direction], firstRow, firstCol, direction, desertIndex));
	}
	if (direction != 3 && row + dRow[direction + 1] >= 0 && row + dRow[direction + 1] < n&&col + dCol[direction + 1] >= 0 && col + dCol[direction + 1] < n)
	{
		maxNum = max(maxNum, dfs(row + dRow[direction + 1], col + dCol[direction + 1], firstRow, firstCol, direction + 1, desertIndex));
	}
	return maxNum;
}

int main()
{
	int maxNum = 0;
	int t;
	int test = 1;
	cin >> t;
	while (t--) {
		maxNum = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < n - 2; i++)
		{
			for (int j = 1; j < n - 1; j++)
			{
				curDesert[0] = arr[i][j];
				maxNum = max(maxNum, dfs(i + 1, j + 1, i, j, 0, 1));
			}
		}
		if (maxNum < 4) cout << "#" << test++ << " -1" << endl;
		else cout << "#" << test++ << " " << maxNum << endl;
	}
}
