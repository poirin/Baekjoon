#include <iostream>
using namespace std;

bool check[101] = { false, };
int main()
{
	int n, a, c = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (check[a])c++;
		else check[a] = true;
	}
	cout << c;
}