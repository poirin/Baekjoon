#include <iostream>
using namespace std;
int main()
{
	int a, b, cnt = 0;
	cin >> a >> a >> b;
	a--; b--;
	while (a != b) {
		a /= 2; b /= 2;
		cnt++;
	}
	cout << cnt;
}