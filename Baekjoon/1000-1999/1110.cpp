#include <iostream>
using namespace std;

int main()
{
	int n, a; cin >> n;
	int cnt = 0;
	a = n;
	for (int i = 0;; i++)
	{
		a = (a % 10 * 10) + (a / 10 + a % 10) % 10; cnt++;
		if (a == n) {
			cout << cnt; return 0;
		}
	}
}