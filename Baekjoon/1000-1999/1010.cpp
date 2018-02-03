#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		long long int mul = 1;
		long long int div = 1;
		cin >> a >> b;
		for (int i = 0; i < a; i++)
		{
			mul *= b - i;
			mul /= i + 1;
		}
		cout << mul / div << endl;
	}
}