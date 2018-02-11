#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> i, pair<int, int> j)
{
	if (i.first == j.first)
		return i.second < j.second;
	return i.first < j.first;
}
int main()
{
	int cnt = 0, curEndTime = -1;
	vector<pair<int, int> > v;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back(make_pair(b, a));
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++)
	{
		if (v[i].second >= curEndTime)
		{
			curEndTime = v[i].first;
			cnt++;
		}
	}
	cout << cnt;
}