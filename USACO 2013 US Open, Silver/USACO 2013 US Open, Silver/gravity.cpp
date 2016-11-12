#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct state {
	int row, col, flips;
};

int greater(state  a, state b) {
	return a.flips > b.flips;
}

int n, m, start[2], target[2], gravity[2][500][500];
bool grid[500][500], visited[2][500][500];

int main() {
	ifstream cin("gravity.in");
	//ofstream cout("gravity.out");
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			if (c == '.') {
				grid[i][j] = 1;
			}
			else if (c == 'C') {
				grid[i][j] = 1;
				start[0] = i;
				start[1] = j;
			}
			else if (c == 'D') {
				grid[i][j] = 1;
				target[0] = i;
				target[1] = j;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			gravity[0][i][j] = n;
			gravity[1][i][j] = n;
			if (!grid[i][j]) {
				continue;
			}
			int below = i + 1, above = i - 1;
			while (below < n) {
				if (!grid[below][j]) {
					gravity[0][i][j] = below - 1;
					break;
				}
				++below;
			}
			while (above >= 0) {
				if (!grid[above][j]) {
					gravity[1][i][j] = above + 1;
					break;
				}
				--above;
			}
		}
	}

	priority_queue<state> q;
	q.push({ start[0], start[1], 0 });

	while (!q.empty()) {
		state curr = q.top();
		q.pop();
		if (curr.col < 0 || curr.col >= n || gravity[curr.flips % 2][curr.row][curr.col] == n) {
			continue;
		}
		if (!visited[curr.flips % 2][curr.row][curr.col]) {
			q.push({ curr.row, curr.col, curr.flips });
			q.push({ curr.row, curr.col, curr.flips });
			q.push({ curr.row, curr.col, curr.flips + 1 });
		}
	}
}