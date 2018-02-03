#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

string str[51];
int main()
{
	int row, col, cnt = 0, cnt2 = 0, minNum = INT_MAX;
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		cin >> str[i];

	for (int i = 0; i <= row - 8; i++)
	{
		for (int j = 0; j <= col - 8; j++)
		{
			cnt = 0; cnt2 = 0;
			for (int k = 0; k < 8; k++)
			{
				for (int l = 0; l < 8; l++)
				{
					if (!((k + l + i + j) % 2) && str[k + i][l + j] == 'B') cnt++;
					else if ((k + l + i + j) % 2 && str[k + i][l + j] == 'W') cnt++;
					else if (!((k + l + i + j) % 2) && str[k + i][l + j] == 'W') cnt2++;
					else if ((k + l + i + j) % 2 && str[k + i][l + j] == 'B') cnt2++;
				}
			}
			minNum = min(minNum, min(cnt, cnt2));
		}
	}
	cout << minNum;
}