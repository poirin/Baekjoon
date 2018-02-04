#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

string str[20001];
int n;
bool compare(string a, string b)
{
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}
int main()
{
	map<string, int> m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
		m[str[i]]++;
	}
	sort(str, str + n, compare);

	for (int i = 0; i < n; i++)
	{
		if (m[str[i]] > 1) m[str[i]]--;
		else cout << str[i] << endl;
	}
}