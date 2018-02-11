#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str;
int dp[2501];
int c[2501][2501];
int dfs(int a, int b)
{
	if (c[a][b] >= 0) return c[a][b];
	if (a == b)
		c[a][b] = 1;
	else if (a + 1 == b)
		c[a][b] = ((str[a] == str[b]) ? 1 : 0);
	else
		c[a][b] = ((dfs(a + 1, b - 1) && (str[a] == str[b])) ? 1 : 0);
	return c[a][b];
}
int main()
{
	memset(c, -1, sizeof(c));
	memset(dp, -1, sizeof(dp));
	cin >> str;
	dp[0] = 1;
	for (int i = 1; i < str.length(); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (dfs(j, i) == 1)
			{
				if (dp[i] == -1 || dp[i] > dp[j - 1] + 1)
					dp[i] = dp[j - 1] + 1;
			}
		}
	}
	cout << dp[str.length() - 1];
}