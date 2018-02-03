#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		int mul = 1;
		cin >> a >> b;
		for (int i = 0; i < b; i++)
		{
			mul *= a;
			mul %= 10;
		}
		cout << ((!mul) ? 10 : mul) << endl;
	}
}