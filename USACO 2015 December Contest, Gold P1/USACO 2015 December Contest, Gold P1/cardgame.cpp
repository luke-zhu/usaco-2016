#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	ifstream cin("cardgame.in");
	// ofstream cout("cardgame.out");

	int n;
	cin >> n;
	int cards[100001] = { 0 }, elsie[50000];
	for (int i = 0; i < n; ++i) {
		cin >> elsie[i];
		cards[elsie[i]] = 1;
	}
	sort(elsie, elsie + n / 2, greater<int>());
	sort(elsie + n / 2, elsie + n);

	int num = 0, a = 0, b = 2*n;
	while (a < n / 2) {
		// cout << elsie[a] << " " << b << " " << num << "\n";
		if (cards[b]) {
			--b;
		}
		else if (b > elsie[a]) {
			++num;
			++a;
			--b;
			cards[b] = -1;
		}
		else {
			++a;
		}
	}

	b = 1;
	while (a < n) {
		// cout << elsie[a] << " " << b << " " << num << "\n";
		if (cards[b]) {
			++b;
		}
		else if (b < elsie[a]) {
			++num;
			++a;
			++b;
			cards[b] = -1;
		}
		else {
			++a;
		}
	}
	cout << num << "\n";
}