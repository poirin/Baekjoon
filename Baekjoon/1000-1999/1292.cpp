#include <iostream>
using namespace std;
int arr[1001];
int main()
{
	int cnt = 0, sum = 0, a, b;
	for (int i = 1; i <= 1000; i += cnt)
	{
		cnt++;
		for (int j = 0; j < cnt; j++)
		{
			arr[i + j] = cnt;
		}
	}
	cin >> a >> b;
	for (int i = a; i <= b; i++)
	{
		sum += arr[i];
	}
	cout << sum;
}