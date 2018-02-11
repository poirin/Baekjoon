#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[10001];
int main()
{
	long long int k, n, left = 0, len = 0, right = 9999999999; cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
		right = max(right, arr[i]);
	}

	while (left <= right)
	{
		long long int mid = (left + right) / 2;
		long long int sum = 0;
		long long int cnt = 0;
		for (int i = 0; i < k; i++)
		{
			sum += arr[i] / mid;
		}
		if (sum < n)
			right = mid - 1;
		else
		{
			len = max(len, mid);
			left = mid + 1;
		}
	}
	cout << len;
}