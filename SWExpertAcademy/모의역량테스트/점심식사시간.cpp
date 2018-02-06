#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[11][11];
int main()
{
	int t;
	int test = 1;
	cin >> t;
	while (t--) {
		int n;
		int mul = 1;
		vector<pair<int, int> > v;

		int cur = 0;
		int stair[2][2];
		int who[2][11][2];
		int a[2][11];
		int minC = 123;
		int minNum[2] = { 0, 0 };
		int cnt[2] = { 0, 0 };

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == 1)
					v.push_back(make_pair(i, j));
				else if (arr[i][j] > 1)
				{
					stair[cur][0] = i;
					stair[cur++][1] = j;
				}
			}
		}
		for (int i = 0; i < v.size(); i++)
			mul *= 2;

		for (int k = 0; k < mul; k++)
		{
			cnt[0] = 0;
			cnt[1] = 0;
			for (int i = 0; i < v.size(); i++)
			{
				int now;
				if (k&(1 << i)) now = 1;
				else now = 0;

				who[now][cnt[now]][0] = v[i].first;
				who[now][cnt[now]++][1] = v[i].second;
			}
			for (int m = 0; m < 2; m++)
			{
				minNum[m] = 123;
				for (int i = 0; i < cnt[m]; i++)
				{
					a[m][i] = abs(who[m][i][0] - stair[m][0]) + abs(who[m][i][1] - stair[m][1]) + 1;
				}
				sort(a[m], a[m] + cnt[m]);
				for (int i = 3; i < cnt[m]; i++)
				{
					if (a[m][i] - a[m][i - 3] < arr[stair[m][0]][stair[m][1]])
						a[m][i] = a[m][i - 3] + arr[stair[m][0]][stair[m][1]];
				}
				if (cnt[m])
					minNum[m] = min(minNum[m], a[m][cnt[m] - 1]) + arr[stair[m][0]][stair[m][1]];
			}

			minC = min(minC, max(cnt[0] ? minNum[0] : 0, cnt[1] ? minNum[1] : 0));
		}
		cout << "#" << test++ << " " << minC << endl;
	}
}
