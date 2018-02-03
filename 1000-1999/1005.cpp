#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int curTime[1001];
int minTime[1001];
int indeg[1001];
vector<int> v[1001];

int main(void)
{
	int t, n, k, w;
	int curValue;
	int count = 0;

	cin >> t;

	while (t--) {
		queue<int> q;
		int a, b;
		int w;
		memset(indeg, 0, sizeof(indeg));
		cin >> n >> k;

		for (int i = 1; i <= n; i++)
		{
			cin >> curTime[i];
			minTime[i] = curTime[i];
		}

		for (int i = 0; i < k; i++)
		{
			cin >> a >> b;
			v[a].push_back(b);
			indeg[b]++;
		}

		cin >> w;
		for (int i = 1; i <= n; i++)
		{
			if (!indeg[i])
			{
				q.push(i);
				minTime[i] = curTime[i];
			}
		}

		while (!q.empty())
		{
			int here = q.front(); q.pop();

			if (!indeg[w])
			{
				cout << minTime[w] << endl; break;
			}
			for (int i = 0; i < v[here].size(); i++)
			{
				int there = v[here][i];
				minTime[there] = max(minTime[there], minTime[here] + curTime[there]);
				indeg[there]--;
				if (!indeg[there]) q.push(there);
			}
		}
		memset(v, 0, sizeof(v));
	}
}