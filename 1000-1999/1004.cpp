#include <iostream>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int x1, y1, x2, y2, cnt = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		int n; cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x, y, r;
			cin >> x >> y >> r;
			if ((x - x1)*(x - x1) + (y - y1)*(y - y1) < r*r && (x - x2)*(x - x2) + (y - y2)*(y - y2) > r*r)
				cnt++;
			else if ((x - x1)*(x - x1) + (y - y1)*(y - y1) > r*r && (x - x2)*(x - x2) + (y - y2)*(y - y2) < r*r)
				cnt++;

		}
		cout << cnt << endl;
	}
}