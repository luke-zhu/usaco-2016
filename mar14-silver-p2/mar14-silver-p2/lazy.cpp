#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	ifstream cin("lazy.in");
	// ofstream cout("lazy.out");

	int n, k;
	cin >> n >> k;

	return 0;

	int grid[400][400];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> grid[i][j];
		}
	}
	
	int grass[400][400] = { 0 };
	for (int i = 0; i < min(k, n); ++i) {
		for (int j = 0; j < min(k - i, n); ++j) {
			grass[0][0] += grid[i][j];
		}
	}
	cout << grass[0][0] << "\n";
	return 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {

		}
	}
}