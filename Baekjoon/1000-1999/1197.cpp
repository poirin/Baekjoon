#include <iostream>
#include <algorithm>
using namespace std;

typedef struct ee
{
	int a, b, weight;
}Edge;
int v, e, dap, cnt;
Edge edge[100001];
int par[10001];
bool compare(Edge i, Edge j)
{
	return i.weight < j.weight;
}
int find(int i)
{
	if (par[i] == i) return i;
	else return find(par[i]);
}
int merge(int i, int j)
{
	i = find(i);
	j = find(j);
	if (i == j) return 0;
	par[j] = i;
	return 1;
}
int main()
{
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &edge[i].a, &edge[i].b, &edge[i].weight);
	}
	sort(edge, edge + e, compare);
	for (int i = 1; i <= v; i++)
	{
		par[i] = i;
	}
	for (int i = 0;; i++)
	{
		if (merge(edge[i].a, edge[i].b))
		{
			cnt++;
			dap += edge[i].weight;
		}
		if (cnt == v - 1) break;
	}
	cout << dap;
}