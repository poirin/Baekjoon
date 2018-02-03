#include <iostream>
using namespace std;

int n, r, c;

int dfs(int curNum, int startRow, int startCol, int row, int col, int len)
{
	int mul = 1;
	if (len == 1)
		return curNum;
	if (row < startRow + len / 2 && col < startCol + len / 2)
	{
		return dfs(curNum, startRow, startCol, r, c, len / 2);
	}
	if (row < startRow + len / 2 && col >= startCol + len / 2)
	{
		return dfs(curNum + (len*len) / 4, startRow, startCol + len / 2, r, c, len / 2);
	}
	if (row >= startRow + len / 2 && col < startCol + len / 2)
	{
		return dfs(curNum + (len*len) / 2, startRow + len / 2, startCol, r, c, len / 2);
	}
	if (row >= startRow + len / 2 && col >= startCol + len / 2)
	{
		return dfs(curNum + (len*len) / 4 * 3, startRow + len / 2, startCol + len / 2, r, c, len / 2);
	}
}

int main()
{
	cin >> n >> r >> c;
	int mul = 1;
	for (int i = 0; i < n; i++)
		mul *= 2;
	cout << dfs(0, 0, 0, r, c, mul);
}