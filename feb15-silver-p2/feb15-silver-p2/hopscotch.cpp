// O(n^3)

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream cin("hopscotch.in");
	ofstream cout("hopscotch.out");

	int r, c, k;
	cin >> r >> c >> k;

	int grid[100][100];
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> grid[i][j];
		}
	}

	int dp[100][100] = { 1 };
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			for (int k = 0; k < i; ++k) {
				for (int l = 0; l < j; ++l) {
					if (grid[i][j] != grid[k][l]) {
						dp[i][j] += dp[k][l];
						dp[i][j] %= 1000000007;
					}
				}
			}
		}
	}

	cout << dp[r - 1][c - 1] << "\n";
}