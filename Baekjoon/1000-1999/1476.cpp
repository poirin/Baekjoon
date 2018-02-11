#include <iostream>
using namespace std;

int main(void) {
	int e, s, m;
	cin >> e >> s >> m;
	int n = 1;
	int ne = 1, ns = 1, nm = 1;
	while (1) {
		if (e == ne&&s == ns&&m == nm)
		{
			cout << n;
			return 0;
		}
		ne = n % 15 + 1;
		ns = n % 28 + 1;
		nm = n % 19 + 1;
		n++;
	}
}