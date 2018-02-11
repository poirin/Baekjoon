#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	int minLength = 999999;
	int l = 0, r = 0;
	int curLength;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int sum = a[0];
	curLength = 1;
	while (r != n)
	{
		if (sum < m)
		{
			r++;
			sum += a[r];
			curLength++;
		}
		else if (sum >= m)
		{
			minLength = min(minLength, curLength);
			sum -= a[l];
			l++;
			curLength--;
			if (!curLength)
			{
				r = l;
				sum = a[r];
				curLength = 1;
			}
		}
	}
	if (minLength != 999999)
		cout << minLength;
	else
		cout << 0;
}