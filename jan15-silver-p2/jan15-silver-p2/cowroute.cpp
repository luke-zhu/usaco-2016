#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<long long, int> PII;

int a, b, n;
vector< vector<PII> > adj(1000, vector<PII>(1000, PII(1000000000000000, 1000000000)));
vector<int> route[1000];

int main() {
	ifstream cin("cowroute.in");
	ofstream cout("cowroute.out");

	cin >> a >> b >> n;
	--a;
	--b;
	for (int i = 0; i < n; ++i) {
		int cost, len;
		cin >> cost >> len;
		
		route[i].resize(len);
		for (int j = 0; j < len; ++j) {
			cin >> route[i][j];
			--route[i][j];
		}
		for (int j = 0; j < len - 1; ++j) {
			for (int k = j + 1; k < len; ++k) {
				if (cost == adj[route[i][j]][route[i][k]].first) {
					adj[route[i][j]][route[i][k]].second = min(adj[route[i][j]][route[i][k]].second, k - j);
				}
				else if (cost < adj[route[i][j]][route[i][k]].first) {
					adj[route[i][j]][route[i][k]].first = cost;
					adj[route[i][j]][route[i][k]].second = k - j;
				}
			}
		}
	}

	// Dijkstra's
	vector<long long> distance(1000, 1000000000000000);
	vector<int> num_flights(1000, 1000000000);
	vector<bool> visited(1000);
	distance[a] = 0;
	num_flights[a] = 0;

	//Main loop
	for (int i = 0; i < 1000; ++i) {
		int v = -1;
		for (int j = 0; j < 1000; ++j) { //Find best vertex
			if (visited[j]) continue;
			if (v == -1 || distance[j] < distance[v]) {
				v = j;
			}
		}
		if (v == -1) {
			break;
		}
		visited[v] = true;

		for (int u = 0; u < adj[v].size(); ++u) { //Check neighbors
			if (distance[v] + adj[v][u].first == distance[u]) {
				num_flights[u] = min(num_flights[u], num_flights[v] + adj[v][u].second);
			}
			else if (distance[v] + adj[v][u].first < distance[u]) {
				distance[u] = distance[v] + adj[v][u].first;
				num_flights[u] = num_flights[v] + adj[v][u].second;
			}
		}
	}
	
	if (distance[b] == 1000000000000000) {
		cout << "-1 -1\n";
		return 0;
	}
	cout << distance[b] << " " << num_flights[b] << "\n";
}