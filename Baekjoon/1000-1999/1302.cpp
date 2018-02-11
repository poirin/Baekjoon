#include <iostream>
#include <string>
#include <map>

using namespace std;
map<string, int> m;
int main() {
	string maxStr;
	int maxN = 0;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		m[str]++;
	}
	for (auto it = m.begin(); it != m.end(); it++)
	{
		if (maxN < it->second)
		{
			maxN = it->second;
			maxStr = it->first;
		}
	}
	cout << maxStr;
}