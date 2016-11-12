#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, k, grid[400][400], grass[400][400];

int main() {
	ifstream cin("lazy.in");
	// ofstream cout("lazy.out");

	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int r = max(0, i - k); r < min(n, i + k + 1); ++r) {
			for (int c = 0; c < min(k - abs(r - i) + 1, n); ++c) {
				grass[i][0] += grid[r][c];
			}
		}

		for (int j = 1; j < n; ++j) {
			grass[i][j] = grass[i][j - 1];
			for (int r = max(0, i - k); r < min(n, i + k + 1); ++r) {
				if (i - k < 0 || i + k + 1 > n) {
					continue;
				}
				else {
					grid[r][j - (abs(r - i) +
			}
		}
	}
}