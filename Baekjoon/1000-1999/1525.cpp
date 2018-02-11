#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	int tmp;
	int start = 0;
	int nine;
	queue<int> q;
	map<int, int> m;
	string strNow;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> tmp;
			if (tmp == 0) tmp = 9;
			start = start * 10 + tmp;
		}
	}

	q.push(start);
	m[start] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == 123456789)
		{
			cout << m[123456789]; return 0;
		}
		strNow = to_string(now);
		nine = strNow.find('9');
		int x = nine % 3;
		int y = nine / 3;
		for (int i = 0; i < 4; i++)
		{
			int changeX;
			int changeY;
			int changeNum;
			int changeIndex;
			string changeStr;
			changeX = x + dx[i];
			changeY = y + dy[i];
			changeIndex = changeY * 3 + changeX;
			if (changeX >= 0 && changeX <= 2 && changeY >= 0 && changeY <= 2)
			{
				changeStr = strNow;
				swap(changeStr[nine], changeStr[changeIndex]);
				changeNum = stoi(changeStr);
				if (m.find(changeNum) == m.end())
				{
					q.push(changeNum);
					m[changeNum] = m[now] + 1;
				}
			}
		}
	}
	cout << -1;
}