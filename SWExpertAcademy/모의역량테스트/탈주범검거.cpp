#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int mvR[8][4] = { {},{ -1, 0, 0, 1 },{ -1, 1 },{ 0, 0 },{ -1, 0 },{ 0, 1 },{ 0, 1 },{ -1, 0 } };
int mvC[8][4] = { {},{ 0, -1, 1, 0 },{ 0, 0 },{ -1, 1 },{ 0, 1 },{ 1, 0 },{ -1, 0 },{ 0, -1 } };
int mvCnt[8] = { 0, 4, 2, 2, 2, 2, 2, 2 };
int main()
{
	int test = 1;
	int t;
	cin >> t;
	while (t--) {
		queue<pair<int, int> > q;
		int arr[51][51];
		int tim[51][51];
		int cnt = 0;
		int n, m, r, c, l;

		cin >> n >> m >> r >> c >> l;
		memset(tim, 0, sizeof(tim));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
			}
		}

		tim[r][c] = 1;
		q.push(make_pair(r, c));
		while (!q.empty())
		{
			int row = q.front().first;
			int col = q.front().second;
			q.pop();
			if (tim[row][col] > l) break;
			cnt++;
			for (int i = 0; i < mvCnt[arr[row][col]]; i++)
			{
				int nR = row + mvR[arr[row][col]][i];
				int nC = col + mvC[arr[row][col]][i];
				if (nR >= 0 && nR < n&&nC >= 0 && nC < m && !tim[nR][nC] && arr[nR][nC])
				{
					for (int j = 0; j < mvCnt[arr[nR][nC]]; j++)
					{
						if (nR + mvR[arr[nR][nC]][j] == row&&nC + mvC[arr[nR][nC]][j] == col)
						{
							tim[nR][nC] = tim[row][col] + 1;
							q.push(make_pair(nR, nC));
							break;
						}
					}
				}
			}
		}
		cout << "#" << test++ << " " << cnt << endl;
	}
}
