#include <iostream>
#include <cstdio>
using namespace std;

char a[1000000];
int main()
{
	int cnt = 0;
	while (scanf("%s", a) != EOF)
	{
		cnt++;
	}
	printf("%d", cnt);
}