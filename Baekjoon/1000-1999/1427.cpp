#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.length() - 1; i++)
	{
		for (int j = i + 1; j < str.length(); j++)
			if (str[i] < str[j])
				swap(str[i], str[j]);
	}
	cout << str;
}