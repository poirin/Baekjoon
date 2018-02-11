#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int dp[100001];
int main()
{
	int n; cin >> n;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = INT_MAX;
		int k = 1;
		while (k*k <= i)
		{
			dp[i] = min(dp[i], dp[i - k*k] + 1); k++;
		}

	}
	cout << dp[n];
}