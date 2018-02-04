#include <iostream>
#include <string>
using namespace std;

string str;
int arr[200];
int main()
{
	int maxNum = 0;
	int maxIdx = 0;
	bool flag = false;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		arr[((str[i] >= 96) ? str[i] - 32 : str[i])]++;
	}
	for (int i = 0; i < 200; i++)
	{
		if (maxNum < arr[i])
		{
			maxNum = arr[i];
			maxIdx = i;
			flag = false;
		}
		else if (maxNum == arr[i] && maxNum >= 1)
		{
			flag = true;
		}
	}
	if (flag) cout << '?'; else
		printf("%c", ((maxIdx >= 96) ? maxIdx - 32 : maxIdx));
}