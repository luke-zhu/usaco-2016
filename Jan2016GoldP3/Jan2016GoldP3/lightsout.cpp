#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int n, point[201][2], edge[201], dist[201];
bool angle[201];

int main() {
	ifstream cin("lightsout.in");
	ofstream cout("lightsout.out");

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> point[i][0] >> point[i][1];
	}

	edge[0] = abs(point[0][0] - point[n - 1][0]) + abs(point[0][1] - point[n - 1][1]);
	dist[0] = 0;
	for (int i = 1; i < n; ++i) {
		edge[i] = abs(point[i][0] - point[i - 1][0]) + abs(point[i][1] - point[i - 1][1]);
		dist[i] = dist[i - 1] + edge[i];
	}

	for (int i = 1; i < n; ++i) {
		if (point[i][0] < point[i - 1][0] && point[(i + 1) % n][1] < point[i][1]) {
			angle[i] = 1;
		}
		else if (point[i][0] > point[i - 1][0] && point[(i + 1) % n][1] > point[i][1]) {
			angle[i] = 1;
		}
		else if (point[(i + 1) % n][0] < point[i][0] && point[i - 1][1] < point[i][1]) {
			angle[i] = 1;
		}
		else if (point[(i + 1) % n][0] > point[i][0] && point[i - 1][1] > point[i][1]) {
			angle[i] = 1;
		}
	}

	dist[n - 1] = min(dist[n - 1], edge[0]);
	for (int i = n - 2; i > 0; --i) {
		if (dist[i + 1] + edge[i + 1] < dist[i]) {
			dist[i] = dist[i + 1] + edge[i + 1];
		}
	}

	for (int i = 0; i < n; ++i) {
		//cout << dist[i] << "\n";
	}

	int ans = 0;

	for (int i = 1; i < n; ++i) {
		int sum = 0, j = 1;
		vector<int> curr;
		vector<bool> curr_a;
		for (j; i + j < n; ++j) {
			sum += edge[i + j];
			//cout << sum << "\n";
			curr.push_back(edge[i + j]);
			curr_a.push_back(angle[i + j]);
			int *it1 = search(edge + 1, edge + n, curr.begin(), curr.end());
			int *it2 = find_end(edge + 1, edge + n, curr.begin(), curr.end());
			bool *it3 = search(angle + 1, angle + n, curr_a.begin(), curr_a.end());
			bool *it4 = find_end(angle + 1, angle + n, curr_a.begin(), curr_a.end());
			if (it1 == it2 && it3 == it4) {
				//cout << *it1 << " " << *it2 << "\n";
				ans = max(sum + dist[i + j] - dist[i], ans);
				break;
				//cout << j << "\n";
			}
		}
		//cout << "\n";

		if (i + j == n) {
			ans = max(sum + edge[0] - dist[i], ans);
		}
	}
	cout << ans << "\n";
}