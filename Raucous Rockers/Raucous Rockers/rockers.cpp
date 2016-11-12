/*
ID: lukezhu1
PROG: rockers
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, t, m, length[20], dp[21][401];

int func(int song, int time) {
	if (length[song] + time > m * t) return 0;
	else if ((length[song] + time - 1) / t > time / t) return dp[song + 1][((length[song] + time - 1) / t) * t + length[song]] + 1;
	return dp[song + 1][length[song] + time] + 1;
}

int main() {
	ifstream cin("rockers.in");
	ofstream cout("rockers.out");

	cin >> n >> t >> m;

	for (int i = 0; i < n; ++i) cin >> length[i];

	for (int i = n - 1; i >= 0; --i)
		for (int j = 0; j < m * t; ++j)
			dp[i][j] = max(dp[i + 1][j], func(i, j));

	cout << dp[0][0] << "\n";
}