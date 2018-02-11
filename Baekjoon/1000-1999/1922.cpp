#include <iostream>
#include <algorithm>
using namespace std;
typedef struct edge {
	int a, b, c;
}Edge;
int pa[1001];
Edge edge[100001];
bool compare(Edge i, Edge j)
{
	return i.c < j.c;
}
int find(int o)
{
	return pa[o] == o ? o : find(pa[o]);
}
int merge(int i, int j)
{
	i = find(i);
	j = find(j);
	if (i == j)return 0;
	pa[j] = i;
	return 1;
}
int main()
{
	int n, m, cnt = 0, sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		pa[i] = i;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &edge[i].a, &edge[i].b, &edge[i].c);
	}
	sort(edge, edge + m, compare);
	int i = 0;
	while (cnt != n - 1)
	{
		if (merge(edge[i].a, edge[i].b))
		{
			cnt++;
			sum += edge[i].c;
		}
		i++;
	}
	cout << sum;
}