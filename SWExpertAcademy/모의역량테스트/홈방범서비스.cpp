#include <iostream>
#include <algorithm>
using namespace std;
bool arr[21][21];
int main()
{
	int t, test = 1;
	cin >> t;
	while (t--) {
		int maxCnt = 0;
		int n, m;
		cin >> n >> m;
		for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++)
				cin >> arr[i][j];
		for (int k = 1; k<n * 2; k++)
		{
			int c = k*k + (k - 1)*(k - 1);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
				{
					int cnt = 0;
					for (int a = 0; a < n; a++)
						for (int b = 0; b < n; b++)
							if (arr[a][b] && abs(i - a) + abs(j - b) < k) cnt++;
					if (cnt*m >= c) maxCnt = max(maxCnt, cnt);
				}
		}
		cout << "#" << test++ << " " << maxCnt << endl;
	}
}
