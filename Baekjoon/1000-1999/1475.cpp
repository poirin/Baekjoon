#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str;
int arr[10];
int main()
{
	int maxNum = 0;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '9') arr[6]++;
		else arr[str[i] - '0']++;
	}
	if (arr[6] % 2) arr[6] = arr[6] / 2 + 1;
	else arr[6] /= 2;
	for (int i = 0; i < 10; i++)
	{
		maxNum = max(maxNum, arr[i]);
	}
	cout << maxNum;
}