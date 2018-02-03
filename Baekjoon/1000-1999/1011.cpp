#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int x, y; cin >> x >> y;
		y -= x;
		if (y >= ceil(sqrt(y))*ceil(sqrt(y)) - ceil(sqrt(y)) + 1)
			cout << ceil(sqrt(y)) * 2 - 1;
		else
			cout << ceil(sqrt(y)) * 2 - 2;
		cout << endl;
	}
}