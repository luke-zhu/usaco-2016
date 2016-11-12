//NE	

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1000000010

using namespace std;
typedef pair<int, int> PII;

int n, e, dp[1001];
PII patch[1001];
vector< vector<int> > adj(1001), dist(1001, vector<int>(1001, INF));

void bfs(int src) {
	dist[src][src] = 0;

	queue<int> q;
	q.push(src);

	while (!q.empty()) {
		int curr_v = q.front();
		q.pop();

		for (int v : adj[curr_v]) {
			//cout << v << "\n";
			if (dist[src][v] == INF) {
				dist[src][v] = dist[src][curr_v] + 1;
				q.push(v);
			}
		}
	}
}

int main() {
	ifstream cin("buffet.in");
	// ofstream cout("buffet.out");

	// Input
	cin >> n >> e;
	for (int i = 1; i <= n; ++i) {
		int num_edges;
		cin >> patch[i].first >> num_edges;
		patch[i].second = i;
		adj[i].resize(num_edges);
		for (int j = 0; j < num_edges; ++j) {
			cin >> adj[i][j];
		}
	}

	// Find shortest path between each patch
	for (int i = 1; i <= n; ++i) {
		bfs(i);
	}

	/*
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	//DP sort by patch quality
	sort(patch + 1, patch + n + 1);

	/*
	for (int i = 1; i <= n; ++i) {
		cout << patch[i].second << " " << patch[i].first << "\n";
	}
	*/

	int best = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i] = patch[i].first;

		for (int j = 1; j < i; ++j) {
			dp[i] = max(dp[i], dp[j] + patch[i].first - e * dist[patch[j].second][patch[i].second]);
		}
		cout << patch[i].second << " " << dp[i] << "\n";
		best = max(best, dp[i]);
	}
	cout << dp[n] << "\n";
}