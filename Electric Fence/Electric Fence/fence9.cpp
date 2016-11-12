#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream cin("fence9.in");
	//ofstream cout("fence9.out");

	int n, m, p;
	cin >> n >> m >> p;

	float a = 0.5 * p * m;
	int b = p + 1;
	for (int i = 1; i < n; ++i) {
		if (m * i % n == 0) ++b;
	}
	for (int i = n; i < p; ++i) {
		if (m * i % (p - n) == 0) ++b;
	}
	cout << (int)(a + 1 - b / 2.0) << "\n";
}