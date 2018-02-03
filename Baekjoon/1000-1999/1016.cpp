#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	long long int min;
	long long int max;
	int count = 0;
	bool flag[1000001] = { false, };

	cin >> min >> max;
	for (long long int i = 2; i <= sqrt(max); i++)
	{
		long long int square = i*i;
		long long int num = min;
		if (min%square) num += square - (min%square);
		for (long long int j = num; j <= max; j += square)
		{
			flag[j - min] = true;
		}
	}

	for (long long int i = min; i <= max; i++)
	{
		if (!flag[i - min]) count++;
	}
	cout << count;
}