#include <iostream>
#include <queue>
using namespace std;



int main(void)
{
	bool check[400000] = { false, };
	int dist[400000];
	int n, k;
	queue<int> q;
	cin >> n >> k;
	check[n] = true;
	dist[n] = 0;
	q.push(n);

	while (!q.empty())
	{
		int now = q.front();
		if (now == k)
		{
			cout << dist[k];
			return 0;
		}
		int status[3] = { now - 1, now + 1, 2 * now };
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			if (!check[status[i]] && now >= 0 && now<200000)
			{
				check[status[i]] = true;
				dist[status[i]] = dist[now] + 1;
				q.push(status[i]);
			}
		}
	}
}