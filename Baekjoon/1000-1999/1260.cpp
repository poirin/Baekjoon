#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int arr[10001][2];
bool check[1001];
int n, m, v;
void dfs(int num)
{
	check[num] = true;
	cout << num << " ";
	for (int i = 0; i < m; i++)
	{
		if (arr[i][0] == num && !check[arr[i][1]])
		{
			check[arr[i][1]] = true;
			dfs(arr[i][1]);
		}
		else if (arr[i][1] == num && !check[arr[i][0]]) {
			check[arr[i][0]] = true;
			dfs(arr[i][0]);
		}
	}
}
int main()
{
	queue<int> q;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
		cin >> arr[i][0] >> arr[i][1];
	for (int i = 0; i < m; i++)
	{
		if (arr[i][0] > arr[i][1]) swap(arr[i][0], arr[i][1]);
	}
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = i; j < m; j++)
		{
			if (arr[i][0] > arr[j][0])
			{
				swap(arr[i][0], arr[j][0]);
				swap(arr[i][1], arr[j][1]);
			}
		}
	}
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = i; j < m; j++)
		{
			if (arr[i][0] == arr[j][0] && arr[i][1]>arr[j][1])
			{
				swap(arr[i][1], arr[j][1]);
			}
		}
	}
	check[v] = true;
	cout << v << " ";
	for (int i = 0; i < m; i++)
	{
		if (arr[i][0] == v && !check[arr[i][1]])
		{
			check[arr[i][1]] = true;
			dfs(arr[i][1]);
		}
		else if (arr[i][1] == v && !check[arr[i][0]])
		{
			check[arr[i][0]] = true;
			dfs(arr[i][0]);
		}
	}
	cout << endl;
	memset(check, 0, sizeof(check));
	q.push(v);
	check[v] = true;
	while (!q.empty())
	{
		int num = q.front(); q.pop();
		cout << num << " ";
		for (int i = 0; i < m; i++)
		{
			if (arr[i][0] == num && !check[arr[i][1]])
			{
				check[arr[i][1]] = true;
				q.push(arr[i][1]);
			}
			if (arr[i][1] == num && !check[arr[i][0]])
			{
				check[arr[i][0]] = true;
				q.push(arr[i][0]);
			}
		}
	}
}