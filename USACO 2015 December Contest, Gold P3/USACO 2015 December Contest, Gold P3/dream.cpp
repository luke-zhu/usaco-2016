#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> PII;

int n, m, maze[1002][1002];

int bfs() {
	int dist[1002][1002];
	bool smell[1002][1002] = { false };
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dist[i][j] = INT_MAX;
		}
	}
	dist[0][0] = 0;

	queue<PII> q;
	q.push(PII(0, 0));
	
	while (!q.empty()) {
		int r = q.front().first, c = q.front().second;
		if (r == 0 || r > n || c < 0 || c > m) {
			conti
		if (maze[r][c] == 1) {
			smell[r][c] = true;
		}
		else if (maze[r][c] == 2) {

		}

		if (dist[r - 1][c] == INT_MAX) {
			dist[r - 1][c] = dist[r][c] + 1;
			q.push(PII(r - 1, c));
			smell[r - 1][c] = smell[r][c];
		}
		if (dist[r + 1][c] == INT_MAX) {
			dist[r + 1][c] = dist[r][c] + 1;
			q.push(PII(r + 1, c));
			smell[r + 1][c] = smell[r][c];
		}
		if (dist[r][c - 1] == INT_MAX) {
			dist[r][c - 1] = dist[r][c] + 1;
			q.push(PII(r , c + 1));
			smell[r][c - 1] = smell[r][c];
		}
		if (dist[r][c + 1] == INT_MAX) {
			dist[r][c + 1] = dist[r][c] + 1;
			q.push(PII(r, c + 1));
			smell[r][c + 1] = smell[r][c];
		}
	}
	return dist[n - 1][m - 1];
}

int main() {
	ifstream cin("dream.in");
	ofstream cout("dream.out");

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> maze[i][j];
		}
	}
}