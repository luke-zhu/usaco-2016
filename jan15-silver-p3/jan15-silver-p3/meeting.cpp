#include <iostream>
#include <fstream>
#include <set>

#define INF 1000000000

using namespace std;

int n, m, b_adj[1000][1000], e_adj[1000][1000];

int main() {
	ifstream cin("meeting.in");
	// ofstream cout("meeting.out");

	// Initialization
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j) {
				b_adj[i][j] = e_adj[i][j] = INF;
			}
		}
	}

	// Input
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		if (a < b) {
			cin >> b_adj[a][b] >> e_adj[a][b];
		}
		else {
			cin >> b_adj[b][a] >> e_adj[b][a];
		}
	}

	// get possible times
	bool dp[100][10001];
	dp[0][0] = 1;
}