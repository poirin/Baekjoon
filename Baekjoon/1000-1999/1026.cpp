#include <iostream>
#include <algorithm>
using namespace std;
int a[51], b[51];
bool compare(int a, int b)
{
	return (a > b) ? true : false;
}
int main()
{
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + n, compare);
	for (int i = 0; i < n; i++)
		sum += a[i] * b[i];
	cout << sum;
}