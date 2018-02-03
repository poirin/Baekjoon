#include <iostream>
#include <algorithm>
using namespace std;

int arr[51];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	if (n % 2)
	{
		cout << arr[n / 2] * arr[n / 2];
	}
	else
	{
		cout << arr[0] * arr[n - 1];
	}
}