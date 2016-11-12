#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>

using namespace std;
typedef pair<long long, pair<long long, long long> > cow;
typedef pair<long long, long long> PLL;

long long n, h;
cow c[20]; // strength, height, weight
vector< pair<long long, long long> > dp(2000000); // (cow, index) -> (height, safety)

int main() {
	ifstream cin("guard.in");
	// ofstream cout("guard.out");

	cin >> n >> h;
	for (int i = 0; i < n; ++i) {
		cin >> c[i].second.first >> c[i].second.second >> c[i].first;
	}
	
	sort(c , c + n, greater<cow>());

	long long best = -1, curr_s = 1;
	dp.push_back(PLL(0, 1000000000));
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < curr_s; ++j) {
			if (dp[j].second < 0) {
				continue;
			}
			dp[curr_s + j] = PLL(dp[j].first + c[i - 1].second.first, min(dp[j].second - c[i - 1].second.second, c[i - 1].first)); // add
		}
		curr_s *= 2;
	}

	for (int j = 0; j < dp.size(); ++j) {
		//cout << dp[i][j].first << " " << dp[i][j].second << "\n";
		if (dp[j].first >= h) {
			best = max(best, dp[j].second);
		}
	}
	cout << curr_s << "\n";

	if (best < 0) {
		cout << "Mark is too tall\n";
	}
	else {
		cout << best << "\n";
	}
}