/*
ID: lukezhu1
PROG: range
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int n, square[251], dp[251][251];
string field[250]; // (row, column)

int main() {
	ifstream cin("range.in");
	ofstream cout("range.out");

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> field[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (field[i][j] == '1') {
				dp[i + 1][j + 1] = min(dp[i][j], min(dp[i + 1][j], dp[i][j + 1])) + 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 2; k <= dp[i][j]; ++k) {
				++square[k];
			}
		}
	}
	for (int i = 2; i <= n; ++i)
		if (square[i] != 0) {
			cout << i << " " << square[i] << "\n";
		}
	return 0;
}