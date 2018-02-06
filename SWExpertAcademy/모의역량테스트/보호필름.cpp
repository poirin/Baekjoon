#include <iostream>
#include <algorithm>
using namespace std;

int arr[14][21];
int d, w, k;

bool checkArr()
{
	for (int j = 0; j < w; j++)
	{
		int testNum = 0;
		int i = 0;
		for (; i < d; i++)
		{
			if (arr[i][j] == 0 && testNum<0) testNum--;
			else if (arr[i][j] == 1 && testNum > 0) testNum++;
			else if (arr[i][j] == 0 && testNum >= 0) testNum = -1;
			else if (arr[i][j] == 1 && testNum <= 0) testNum = 1;

			if (testNum == k || testNum == -k)
				break;
		}
		if (i == d) return false;
	}
	return true;
}

int dfs(int row, int num, int depth)
{
	int prevArr[21];
	int minNum = 100000;

	for (int j = 0; j < w; j++)
	{
		prevArr[j] = arr[row][j];
	}

	for (int j = 0; j < w; j++)
	{
		arr[row][j] = num;
	}

	if (checkArr() || depth == k)
	{
		for (int j = 0; j < w; j++)
		{
			arr[row][j] = prevArr[j];
		}
		return depth;
	}
	else
	{
		for (int i = row + 1; i < d; i++)
		{
			minNum = min(minNum, dfs(i, 0, depth + 1));
			if (minNum == depth + 1) break;
			minNum = min(minNum, dfs(i, 1, depth + 1));
			if (minNum == depth + 1) break;
		}
	}

	for (int j = 0; j < w; j++)
	{
		arr[row][j] = prevArr[j];
	}

	return minNum;

}

int main()
{
	int test = 1;
	int a;
	int minNum;
	cin >> a;
	while (a--)
	{
		minNum = 1000000;
		cin >> d >> w >> k;
		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
			}
		}

		if (checkArr())
		{
			cout << "#" << test++ << " 0" << endl;
		}
		else
		{
			for (int i = 0; i < d; i++)
			{
				minNum = min(minNum, dfs(i, 0, 1));
				if (minNum == 1) break;
				minNum = min(minNum, dfs(i, 1, 1));
				if (minNum == 1) break;
			}
			cout << "#" << test++ << " " << minNum << endl;
		}
	}
}
