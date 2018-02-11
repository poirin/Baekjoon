#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> q;

	int n; cin >> n;
	while (n--)
	{
		int a; cin >> a;
		if (!a)
		{
			if (!q.empty())
			{
				int b = q.top(); q.pop(); cout << -b << endl;
			}
			else cout << 0 << endl;
		}
		else q.push(-a);
	}
}