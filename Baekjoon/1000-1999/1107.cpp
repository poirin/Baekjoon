#include <iostream>
using namespace std;

bool broken[10] = { false, };
bool possible(int c)
{
	if (c == 0 && broken[0]) return false;
	while (c > 0) {
		if (broken[c % 10]) return false;
		c /= 10;
	}
	return true;
}
int countButton(int c)
{
	int n = 0;
	if (c == 0) return 1;

	while (c > 0)
	{
		n++; c /= 10;
	}
	return n;
}
int main(void) {
	int n, m, count = 0, c;
	int a[6];
	int min = 10000000;
	int minN, maxN;
	int arr[11];
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d", &arr[i]);
		broken[arr[i]] = true;
	}

	for (int i = 0; i <= 1000000; i++)
	{
		int count;
		if (possible(i))
		{
			count = countButton(i) + abs(i - n);
			if (min > count)min = count;
		}
		count = abs(100 - i) + abs(i - n);
		if (min > count)min = count;
	}
	cout << min;
}