#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string a, b;
int c[100];
int main()
{
	bool flag = false;
	bool d = false;
	cin >> a >> b;
	int aLen = a.length(), bLen = b.length();
	if (aLen > bLen)
		for (int i = 0; i < aLen - bLen; i++) b = "0" + b;
	if (aLen < bLen)
		for (int i = 0; i < bLen - aLen; i++) a = "0" + a;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		int n = a[i] - '0' + b[i] - '0';
		if (!flag&&n < 2) c[i] = n;
		else if (!flag) {
			c[i] = 0; flag = true;
		}
		else if (flag&&n == 0)
		{
			c[i] = 1; flag = false;
		}
		else
		{
			if (n % 2) c[i] = 0;
			else c[i] = 1;
		}

	}
	if (flag) {
		cout << 1; d = true;
	}
	for (int i = 0; i < a.length(); i++)
	{
		if (c[i] == 0 && !d) continue;
		else if (c[i] == 1) d = true;
		cout << c[i];
	}
	if (!d) cout << 0;
}