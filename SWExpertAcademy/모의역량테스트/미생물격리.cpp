#include <iostream>
using namespace std;

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
class Agar {
public:
	int d;
	int cnt;
	int tmpCnt;
	int row, col;
};
Agar agar[1001];
int n, m, k;
int main()
{
	int t;
	int test = 1;
	cin >> t;
	while (t--) {
		int sum = 0;
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++)
			cin >> agar[i].row >> agar[i].col >> agar[i].cnt >> agar[i].d;

		for (int a = 0; a < m; a++)
		{
			for (int i = 0; i < k; i++)
			{
				if (agar[i].cnt) {
					agar[i].tmpCnt = agar[i].cnt;
					agar[i].row += dr[agar[i].d - 1];
					agar[i].col += dc[agar[i].d - 1];
					if (agar[i].row == 0 || agar[i].row == n - 1 || agar[i].col == 0 || agar[i].col == n - 1)
					{
						agar[i].tmpCnt = agar[i].cnt /= 2;
						if (agar[i].d % 2) agar[i].d++;
						else agar[i].d--;
					}
					for (int j = 0; j < i; j++)
					{
						if (agar[i].row == agar[j].row&&agar[i].col == agar[j].col)
						{
							if (agar[i].cnt > agar[j].cnt)
							{
								agar[i].tmpCnt += agar[j].tmpCnt;
								agar[j].tmpCnt = 0;
								agar[j].cnt = 0;
							}
							else {
								agar[j].tmpCnt += agar[i].tmpCnt;
								agar[i].tmpCnt = 0;
								agar[i].cnt = 0;
							}
						}
					}
				}
			}
			for (int i = 0; i < k; i++)
			{
				agar[i].cnt = agar[i].tmpCnt;
			}
		}

		for (int i = 0; i < k; i++)
		{
			sum += agar[i].cnt;
		}
		cout << "#" << test++ << " " << sum << endl;
	}
}
