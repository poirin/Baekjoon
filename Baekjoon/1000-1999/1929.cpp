#include <iostream>
using namespace std;

bool flag[1000001];
int main()
{
	long long int m, n; cin >> m >> n;
	for (long long int i = 2; i <= n; i++)
	{
		if (i == 3)
			printf("");
		if (flag[i]) continue;
		for (long long int j = i*i; j <= 1000000; j += i)
			flag[j] = true;
	}
	for (int i = ((2>m) ? 2 : m); i <= n; i++)
	{
		if (!flag[i]) cout << i << endl;
	}
}