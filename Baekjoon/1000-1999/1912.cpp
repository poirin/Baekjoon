#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001], dp[100001];
int main()
{
	int n; cin >> n;
	int maxNum;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	maxNum = dp[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1], 0) + arr[i];
		maxNum = max(maxNum, dp[i]);
	}
	cout << maxNum;
}
