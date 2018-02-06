#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
#define NONE 0
#define AWAIT 1
#define A 2
#define BWAIT 3
#define B 4
#define FINISH 5
using namespace std;
class People {
public:
	People() :state(0) {}
	int time;
	int state;
	int remTime;
	int aNum, bNum;
};
People p[1001];
int aTime[10];
int bTime[10];
bool aPoss[10];
bool bPoss[10];
int tmp[10];
int tmpCnt;
int main()
{
	int test = 1;
	int a;
	cin >> a;
	while (a--) {
		int t;
		memset(p, 0, sizeof(p));
		queue<int> aWait;
		queue<int> bWait;
		int n, m, k, a, b;
		int sum = 0;
		cin >> n >> m >> k >> a >> b;
		for (int i = 0; i < n; i++)
		{
			cin >> aTime[i];
			aPoss[i] = true;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> bTime[i];
			bPoss[i] = true;
		}
		for (int i = 0; i < k; i++)
			cin >> p[i].time;

		for (t = 0;; t++)
		{
			int fin = 0;
			for (int i = 0; i < k; i++)
				if (p[i].state == FINISH)
					fin++;
			if (fin == k) break;
			for (int i = 0; i < k; i++)
			{
				if (p[i].state == B)
				{
					p[i].remTime--;
					if (!p[i].remTime)
					{
						bPoss[p[i].bNum] = true;
						p[i].state++;
					}
				}
			}
			tmpCnt = 0;
			for (int i = 0; i < k; i++)
			{
				if (p[i].state == A)
				{
					p[i].remTime--;
					if (!p[i].remTime)
					{
						aPoss[p[i].aNum] = true;
						p[i].state++;
						tmp[tmpCnt++] = i;
					}
				}
			}
			if (tmpCnt) {
				for (int i = 0; i < tmpCnt - 1; i++)
				{
					for (int j = i + 1; j < tmpCnt; j++)
					{
						if (p[tmp[i]].aNum > p[tmp[j]].aNum)
						{
							int a = tmp[i];
							tmp[i] = tmp[j];
							tmp[j] = a;
						}
					}
				}
				for (int i = 0; i < tmpCnt; i++)
				{
					bWait.push(tmp[i]);
				}
			}
			for (int i = 0; i < k; i++)
			{
				if (p[i].state == NONE&&p[i].time == t)
				{
					p[i].state++;
					aWait.push(i);
				}
			}
			for (int i = 0; i < m; i++) {
				if (bPoss[i] && !bWait.empty()) {
					int now = bWait.front(); bWait.pop();
					bPoss[i] = false;
					p[now].bNum = i;
					p[now].remTime = bTime[i];
					p[now].state++;
				}
			}

			for (int i = 0; i < n; i++) {
				if (aPoss[i] && !aWait.empty()) {
					int now = aWait.front(); aWait.pop();
					aPoss[i] = false;
					p[now].aNum = i;
					p[now].remTime = aTime[i];
					p[now].state++;
				}
			}
		}

		for (int i = 0; i < k; i++)
		{
			if (p[i].aNum == a - 1 && p[i].bNum == b - 1)
			{
				sum += i + 1;
			}
		}
		printf("#%d %d\n", test++, (sum ? sum : -1));
	}
}
