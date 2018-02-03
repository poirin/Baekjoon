#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int arr[51][51];
bool check[51][51];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int main()
{
	int t;
	cin >> t;

	while (t--) {
		memset(check, 0, sizeof(check));
		memset(arr, 0, sizeof(arr));
		int n, m, k, cnt = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> b >> a;
			arr[a][b] = 1;
		}
		queue<pair<int, int> > q;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] && !check[i][j])
				{
					cnt++;
					check[i][j] = true;
					q.push(make_pair(i, j));
					while (!q.empty())
					{
						int nr = q.front().first;
						int nc = q.front().second; q.pop();
						for (int i = 0; i < 4; i++)
						{
							int nR = nr + dr[i];
							int nC = nc + dc[i];
							if (nR >= 0 && nR < n&&nC >= 0 && nC < m&&arr[nR][nC] && !check[nR][nC])
							{
								check[nR][nC] = true;
								q.push(make_pair(nR, nC));
							}
						}
					}
				}
			}
		}
		cout << cnt << endl;
	}
}