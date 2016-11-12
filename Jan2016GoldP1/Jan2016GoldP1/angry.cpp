#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <set>
#include <functional>

using namespace std;

int n;
double pos[50010], l[50010], r[50010];

set<pair<int, int>> s;

int main() {
	ifstream cin("angry.in");
	ofstream cout("angry.out");

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> pos[i];
		s.insert(pair<int, int>(pos[i], i));
		
	}
	sort(pos, pos + n);

	l[1] = pos[1] - pos[0] + 1;
	//cout << l[1] << "\n";

	for (int i = 2; i < n; ++i) {
		l[i] = max(l[i - 1] + 1, pos[i] - pos[i - 1]);
		//cout << l[i] << "\n";
	}
	//cout << "\n";

	r[n - 2] = pos[n - 1] - pos[n - 2] + 1;
	//cout << r[n - 2] << "\n";
	for (int i = n - 3; i >= 0; --i) {
		r[i] = max(r[i + 1] + 1, pos[i + 1] - pos[i]);
		//cout << r[i] << "\n";
	}
	//cout << "\n";

	double power = 1100000000;
	for (int i = 1; i < n; ++i) {
		double temp = max(0.5 * (pos[i] - pos[i - 1]), 1.0 * max(l[i - 1], r[i]));
		while(s.lower_bound(pos[i - 1]))
		power = min(power, temp);
	}
	cout << fixed;
	cout << setprecision(1) << power << "\n";
}