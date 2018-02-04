#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[1001][3];
	int minArr[1001][3];
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
	minArr[1][0] = arr[1][0];
	minArr[1][1] = arr[1][1];
	minArr[1][2] = arr[1][2];

	for (int i = 2; i <= n; i++)
	{
		minArr[i][0] = min(minArr[i - 1][1], minArr[i - 1][2]) + arr[i][0];
		minArr[i][1] = min(minArr[i - 1][0], minArr[i - 1][2]) + arr[i][1];
		minArr[i][2] = min(minArr[i - 1][0], minArr[i - 1][1]) + arr[i][2];
	}

	cout << min(minArr[n][0], min(minArr[n][1], minArr[n][2]));
}