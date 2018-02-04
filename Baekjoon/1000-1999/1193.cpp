#include <iostream>
using namespace std;

int main()
{
	int a = 1, b = 1, flag = false;
	int x; cin >> x;
	for (int i = 2; i <= x; i++)
	{
		if (a == 1 && b % 2) {
			b++; flag = true;
		}
		else if (b == 1 && !(a % 2))
		{
			a++; flag = false;
		}
		else if (flag) {
			b--; a++;
		}
		else
		{
			b++; a--;
		}
	}
	printf("%d/%d", a, b);
}