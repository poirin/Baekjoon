#include <iostream>
using namespace std;

long long int fact(int n)
{
	long long int mul = 1;
	if (n == 0 || n == 1) return 1;
	for (int i = 2; i <= n; i++)
	{
		mul *= i;
	}
	return mul;
}
int main(void) {
	int n; cin >> n;
	int p; cin >> p;
	int arr[30];
	int cur[30];
	int curCount = 0;
	long long int num = 0;
	long long int comp = 0;
	if (p == 1) {
		cin >> comp;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				bool duple = false;
				for (int k = 1; k < i; k++)
				{
					if (j == cur[k])
					{
						duple = true;
						break;
					}
				}
				if (duple) continue;
				num += fact(n - i);
				if (num >= comp) {
					cur[i] = j;
					num -= fact(n - i);
					break;
				}
			}
		}
		for (int i = 1; i <= n; i++)
			cout << cur[i] << " ";
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			int small = 0;
			cin >> arr[i];
			for (int j = 0; j < curCount; j++)
			{
				if (arr[i] > cur[j]) small++;
			}
			num += (arr[i] - (small + 1)) * fact(n - i);
			cur[curCount++] = arr[i];
		}
		cout << num + 1;
	}
}