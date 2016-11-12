#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;
typedef pair<int, int> PII;

int n, m;

int dist[2][10000], parent[2][10000];
vector<PII> edges[2][10000];

void dijkstra(int gps, int source) {
	for (int i = 0; i < n; ++i) {
		dist[gps][i] = INT_MAX;
		parent[gps][i] = -1;
	}
	dist[gps][source] = 0;

	set<PII> unvisited;
	unvisited.insert(PII(0, source));

	while (!unvisited.empty()) {
		int next_v = unvisited.begin()->second;
		unvisited.erase(unvisited.begin());
		for (PII edge : edges[gps][next_v]) {
			if (dist[gps][edge.second] > dist[gps][next_v] + edge.first) {
				unvisited.erase(edge);
				dist[gps][edge.second] = dist[gps][next_v] + edge.first;
				unvisited.insert(PII(dist[gps][edge.second], edge.second));
				parent[gps][edge.second] = next_v;
			}
		}
	}
}

int main() {
	ifstream cin("gpsduel.in");
	// ofstream cout("gpsduel.out");

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		PII edge;
		edge.second = b;
		cin >> edge.first;
		edges[0][a].push_back(edge);
		cin >> edge.first;
		edges[1][a].push_back(edge);
	}
	dijkstra(0, 0);
	dijkstra(1, 0);

	vector<vector<int>> dp(n);
	for (int i = 0; i < n; ++i) {
		dp[i] = vector<int>(n, INT_MAX);
	}
	dp[n-1][n-1] = 0;
	for (int i = n - 2; i >= 0; --i) {
		dp[i]
	}
}