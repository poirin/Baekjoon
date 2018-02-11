#include <iostream>
using namespace std;

int main(void)
{
	int mon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char str[7][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

	int month;
	int day;
	int curStr = 0;
	cin >> month >> day;

	for (int i = 0; i < month - 1; i++)
	{
		curStr += mon[i];
	}

	curStr += day;
	curStr %= 7;

	printf("%s", str[curStr]);
}