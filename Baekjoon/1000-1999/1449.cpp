#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int main()
{
	int cnt = 0, n, l; cin >> n >> l;
	int a = 0;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		if (i == 0 || a + l - 1 < arr[i])
		{
			cnt++;
			a = arr[i];
		}
	}
	cout << cnt;
}