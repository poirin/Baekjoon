#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int arr[100001];
int main()
{
	map<int, int> mm;
	int a, n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a); mm[a]++;
	}
	sort(arr, arr + n);
	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &a);
		if (mm[a] > 0) printf("1\n");
		else printf("0\n");
	}
}