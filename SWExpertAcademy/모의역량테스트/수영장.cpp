#include <iostream>
#include <algorithm>
using namespace std;
int p[20];
int main()
{
	int t, d, m, q, y, a = 1; cin >> t;
	while (t--) {
		cin >> d >> m >> q >> y;
		for (int i = 3; i<15; i++)
		{
			cin >> p[i]; p[i] = min(min(p[i - 1] + d*p[i], p[i - 1] + m), p[i - 3] + q);
		}
		cout << "#" << a++ << " " << min(p[14], y) << endl;
	}
}
