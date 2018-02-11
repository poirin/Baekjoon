#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a, b, c, d;
	int up, down;
	cin >> a >> b >> c >> d;

	up = a*d + b*c;
	down = b*d;
	for (int i = min(up, down); i >= 1; i--)
	{
		if (!(up%i || down%i))
		{
			cout << up / i << " " << down / i;
			return 0;
		}
	}
}