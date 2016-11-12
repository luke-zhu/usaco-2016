/*
IDL lukezhu1
PROG: fence9
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream cin("fence9.in");
	ofstream cout("fence9.out");

	int n, m, p, a, b, num = 0;
	cin >> n >> m >> p;

	for (int i = 1; i < m; ++i) {
		a = (i * n) / m + 1;
		if ((p * m + (n - p) * i) % m == 0)
			b = (p * m + (n - p) * i) / m - 1;
		else
			b = (p * m + (n - p) * i) / m;
		num += (b - a + 1);
	}
	cout << num << "\n";
}