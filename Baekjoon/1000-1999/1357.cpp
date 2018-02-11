#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int a, b;
	string strA, strB, str;
	cin >> strA >> strB;
	for (int i = 0; i < strA.length() / 2; i++)
	{
		swap(strA[i], strA[strA.length() - i - 1]);
	}
	for (int i = 0; i < strB.length() / 2; i++)
	{
		swap(strB[i], strB[strB.length() - i - 1]);
	}
	str = to_string(stoi(strA) + stoi(strB));
	for (int i = 0; i < str.length() / 2; i++)
	{
		swap(str[i], str[str.length() - i - 1]);
	}
	cout << stoi(str);
}