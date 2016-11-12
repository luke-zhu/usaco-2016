#include <iostream>
#include <fstream>
#include <algorithm>

#define INF 1000000000000;

using namespace std;
typedef pair<int, int> PII;

int n, m;
long long dp[1002][1002];
PII fjohn[1001], bessie[1001];

int calculate(PII a, PII b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
	ifstream cin("radio.in");
	ofstream cout("radio.out");

	cin >> n >> m;
	cin >> fjohn[0].first >> fjohn[0].second >> bessie[0].first >> bessie[0].second;
	//cout << fjohn[0].first << " " << fjohn[0].second << "\n";
	for (int i = 1; i <= n; ++i) {
		char c;
		cin >> c;
		//cout << c << " ";
		if (c == 'E') {
			fjohn[i].first = fjohn[i - 1].first + 1;
			fjohn[i].second = fjohn[i - 1].second;
		}
		else if (c == 'W') {
			fjohn[i].first = fjohn[i - 1].first - 1;
			fjohn[i].second = fjohn[i - 1].second;
		}
		else if (c == 'N') {
			fjohn[i].first = fjohn[i - 1].first;
			fjohn[i].second = fjohn[i - 1].second + 1;
		}
		else if (c == 'S') {
			fjohn[i].first = fjohn[i - 1].first;
			fjohn[i].second = fjohn[i - 1].second - 1;
		}
		//cout << fjohn[i].first << " " << fjohn[i].second << "\n";
	}

	for (int i = 1; i <= m; ++i) {
		char c;
		cin >> c;
		if (c == 'E') {
			bessie[i].first = bessie[i - 1].first + 1;
			bessie[i].second = bessie[i - 1].second;
		}
		else if (c == 'W') {
			bessie[i].first = bessie[i - 1].first - 1;
			bessie[i].second = bessie[i - 1].second;
		}
		else if (c == 'N') {
			bessie[i].first = bessie[i - 1].first;
			bessie[i].second = bessie[i - 1].second + 1;
		}
		else if (c == 'S') {
			bessie[i].first = bessie[i - 1].first;
			bessie[i].second = bessie[i - 1].second - 1;
		}
		//cout << bessie[i].first << " " << bessie[i].second << "\n";
	}

	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= m + 1; ++j) {
			dp[i][j] = INF;
			//cout << calculate(fjohn[i], bessie[j]) << " ";
		}
		//cout << "\n";
	}
	//cout << "\n";
	dp[1][1] = 0;

	for (int i = 1; i <= n + 1; ++i) {
		for (int j = 1; j <= m + 1; ++j) {
			if (i == 1 && j == 1) continue;

			dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
			dp[i][j] += calculate(fjohn[i - 1], bessie[j - 1]);
		}
	}
	for (int i = 1; i <= n + 1; ++i) {
		for (int j = 1; j <= m + 1; ++j) {
			//cout << dp[i][j] << " ";
		}
		//cout << "\n";
	}
	cout << dp[n + 1][m + 1] << "\n";
}