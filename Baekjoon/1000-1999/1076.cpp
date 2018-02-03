#include <iostream>
#include <string>
using namespace std;

string str[3];
string s[10] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };
int a[10];
int main()
{
	long long int mul = 1, sum = 0;
	for (int i = 0; i < 10; i++)
	{
		a[i] = mul; mul *= 10;
	}
	for (int i = 0; i < 3; i++)
	{
		cin >> str[i];
		for (int j = 0; j < 10; j++)
			if (str[i] == s[j])
			{
				if (i != 2)
				{
					sum += j;
					if (!i) sum *= 10;
				}
				else sum *= a[j];
			}
	}
	cout << sum;
}