#include <iostream>
using namespace std;

double arr[1001];
int main()
{
	int n; cin >> n;
	int maxNum = 0;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (maxNum < arr[i]) maxNum = arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = arr[i] / maxNum * 100;
		sum += arr[i];
	}
	printf("%.2f", sum / n);
}