#include <iostream>
#include <stack>
using namespace std;

int arr[100001];
char a[1000000];
int main()
{
	stack<int> s;
	s.push(0);
	int num = 1, o = 0, n, ptr = 0; cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	while (ptr != n)
	{
		if (arr[ptr] > s.top())
		{
			s.push(num++);
			a[o++] = '+';
		}
		else if (arr[ptr] == s.top())
		{
			s.pop();
			a[o++] = '-';
			ptr++;
		}
		else
		{
			cout << "NO"; return 0;
		}
	}
	for (int i = 0; i < o; i++)
	{
		printf("%c\n", a[i]);;
	}
}