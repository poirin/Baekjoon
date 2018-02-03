#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	int cnt = (n>99) ? 99 : n;
	for (int i = 100; i <= n; i++)
	{
		int diff = i % 10 - (i / 10) % 10;
		int diff2 = (i / 10) % 10 - (i / 100) % 10;
		int diff3;
		if (i > 999) diff3 = (i / 100) % 10 - i / 1000;
		if (diff == diff2)
		{
			if (i < 1000) cnt++;
			else if (diff2 == diff3) cnt++;
		}
	}
	cout << cnt;
}