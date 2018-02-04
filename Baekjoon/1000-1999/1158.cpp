#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[5001];
int main()
{
	int cnt = 0;
	int ptr = 0;
	queue<int> q;
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
		q.push(i);
	while (!q.empty())
	{
		cnt++;
		if (cnt == m)
		{
			arr[ptr++] = q.front();
			cnt = 0;
			q.pop();
		}
		else
		{
			q.push(q.front()); q.pop();
		}
	}
	printf("<");
	for (int i = 0; i < ptr - 1; i++)
		printf("%d, ", arr[i]);
	printf("%d>", arr[ptr - 1]);
}