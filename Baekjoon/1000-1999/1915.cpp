#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int arr[1001][1001];
int main()
{
	int ans = 0;
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &arr[i][j]);
			if (!arr[i][j]) dp[i][j] = 0;
			else
			{
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				ans = max(ans, dp[i][j] * dp[i][j]);
			}
		}
	}
	cout << ans << endl;
}