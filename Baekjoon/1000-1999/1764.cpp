#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
string strr[500001];
map<string, int> m;
vector<string> v;
int main()
{
	int a, b, cnt = 0;
	cin >> a >> b;
	for (int i = 0; i < a; i++)
	{
		string str;
		cin >> str;
		m[str]++;
	}
	for (int i = 0; i < b; i++)
	{
		string str;
		cin >> str;
		m[str]++;
	}
	for (auto it = m.begin(); it != m.end(); it++)
	{
		if (it->second == 2) {
			cnt++;
			v.push_back(it->first);
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < v.size(); i++)
	{
		printf("%s\n", v[i].c_str());
	}
}