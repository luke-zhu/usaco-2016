/*
ID: lukezhu1
PROG: nuggets
LANG: C++11
*/

#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b) { // a > b
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ifstream cin("nuggets.in");
	//ofstream cout("nuggets.out");

	int n;
	cin >> n;

	int package[10];
	for (int i = 0; i < n; ++i) cin >> package[i];

	//Check if GCD = 1
	int d = package[0];
	for (int i = 1; i < n; ++i) {
		if (d > package[i]) d = gcd(d, package[i]);
		else d = gcd(package[i], d);
	}

	if (d > 1) {
		cout << "0\n";
		return 0;
	}


}