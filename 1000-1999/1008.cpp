#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	printf("%.12llf", (long double)a / b);
}