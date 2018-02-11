#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool check(string str)
{
	int ja = 0, mo = 0;
	for (char x : str) {
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
			mo++;
		else
			ja++;
	}
	return ja >= 2 && mo >= 1;
}

void printPass(int n, vector<char> &v, string str, int i)
{
	if (str.length() == n)
	{
		if (check(str)) {
			cout << str << endl;
			return;
		}
	}
	if (i >= v.size())return;
	printPass(n, v, str + v[i], i + 1);
	printPass(n, v, str, i + 1);
}

int main()
{
	int l, c;
	vector<char> v;
	char a;
	cin >> l >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	printPass(l, v, "", 0);
}