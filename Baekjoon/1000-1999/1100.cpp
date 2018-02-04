#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str[8];
	int cnt = 0;
	for (int i = 0; i < 8; i++)cin >> str[i];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (!((i + j) % 2) && str[i][j] == 'F') cnt++;
		}
	}
	cout << cnt;
}
