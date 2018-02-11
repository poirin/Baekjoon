#include <iostream>
#include <string>
using namespace std;

string str[101];
int n, a, b, cnt;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> str[i];
	for (int k = 0; k < 2; k++) {
		a = 0;
		for (int i = 0; i < n; i++)
		{
			cnt = 0;
			for (int j = 0; j < n; j++)
			{
				char s = k ? str[j][i] : str[i][j];
				if (s == '.')
				{
					cnt++;
					if (cnt == 2) a++;
				}
				else cnt = 0;
			}
		}
		cout << a << " ";
	}
}