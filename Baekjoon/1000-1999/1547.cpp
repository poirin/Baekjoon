#include <iostream>
#include <algorithm>
using namespace std;

bool d[4] = { false,true,false,false };
int main()
{
	int m; cin >> m;
	while (m--)
	{
		int a, b; cin >> a >> b;
		swap(d[a], d[b]);
	}
	for (int i = 1; i <= 3; i++) if (d[i]) cout << i;
}