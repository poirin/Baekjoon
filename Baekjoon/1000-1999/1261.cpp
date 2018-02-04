#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int arr[101][101];
int d[101][101];

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

int main()
{
	int n, m;
	queue<pair<int, int>> q;
	queue<pair<int, int>> nq;
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &arr[i][j]);
			d[i][j] = -1;
		}
	}

	q.push(make_pair(0, 0));
	d[0][0] = 0;

	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second; q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nr < n&&nc >= 0 && nc < m)
			{
				if (d[nr][nc] == -1)
				{
					if (!arr[nr][nc])
					{
						d[nr][nc] = d[r][c];
						q.push(make_pair(nr, nc));
					}
					else
					{
						d[nr][nc] = d[r][c] + 1;
						nq.push(make_pair(nr, nc));
					}
				}
			}
		}
		if (q.empty())
		{
			q = nq;
			nq = queue<pair<int, int>>();
		}
	}
	cout << d[n - 1][m - 1];
}