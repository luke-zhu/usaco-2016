#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream cin("feast.in");
	ofstream cout("feast.out");

	int t, a, b;
	cin >> t >> a >> b;
	vector<bool> before(t + max(a,b));
	vector<bool> after(t + max(a,b));

	before[0] = 1;
	after[0] = 1;
	for (int i = 0; i < t; ++i) {
		// cout << i << " " << before[i] << "\n";
		if (before[i]) {
			before[i + a] = 1;
			before[i + b] = 1;
			after[i / 2] = 1;
		}
	}
	for (int i = 0; i < t; ++i) {
		// cout << i << " " << after[i] << "\n";
		if (after[i]) {
			after[i + a] = after[i];
			after[i + b] = after[i];
		}
	}
	for (int i = t; i >= 0; --i) {
		if (before[i] || after[i]) {
			cout << i << "\n";
			return 0;
		}
	}
}