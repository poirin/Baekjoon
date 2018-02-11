#include <iostream>
#include <string>
using namespace std;

string source, dest;
int hs, ms, ss, hd, md, sd;
int main()
{
	cin >> source >> dest;
	hs = stoi(source.substr(0, 2));
	ms = stoi(source.substr(3, 2));
	ss = stoi(source.substr(6, 2));

	hd = stoi(dest.substr(0, 2));
	md = stoi(dest.substr(3, 2));
	sd = stoi(dest.substr(6, 2));
	hd -= hs;
	md -= ms;
	sd -= ss;
	if (sd < 0) {
		sd += 60; md--;
	}
	if (md < 0) {
		md += 60; hd--;
	}
	if (hd < 0) {
		hd += 24;
	}
	if (hd >= 10) cout << hd; else cout << 0 << hd;
	cout << ":";

	if (md >= 10) cout << md; else cout << 0 << md;
	cout << ":";

	if (sd >= 10) cout << sd; else cout << 0 << sd;
}