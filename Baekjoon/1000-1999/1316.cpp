#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool alphabet[27];
string str;
int main()
{
	int n; cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		memset(alphabet, 0, sizeof(alphabet));
		cin >> str;
		int curNum = str[0];
		int j = 0;
		for (j = 0; j < str.length(); j++)
		{
			if (!alphabet[str[j] - 'a'])
			{
				alphabet[str[j] - 'a'] = true;
			}
			else if (alphabet[str[j] - 'a'] && curNum != str[j])
			{
				break;
			}
			curNum = str[j];
		}
		if (j == str.length()) cnt++;
	}
	cout << cnt;
}