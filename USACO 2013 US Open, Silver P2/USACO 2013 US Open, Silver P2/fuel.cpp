// O(n log n), constant amount of gas bought

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;
typedef pair<int, int> PII;

int main() {
	ifstream cin("fuel.in");
	// ofstream cout("fuel.out");

	int n, g, b, d;
	cin >> n >> g >> b >> d;
	PII stations[50000];
	for (int i = 0; i < n; ++i) {
		cin >> stations[i].first >> stations[i].second;
	}
	sort(stations, stations + n);

	priority_queue<PII, vector<PII>, greater<PII>> reachable;
	int curr_d = 0, curr_g = b, furthest = 0, cost = 0;
	while (1) {
		while (furthest < n && stations[furthest].first - curr_d <= g) {
			reachable.push(PII(stations[furthest].second, stations[furthest].first));
			++furthest;
		}
		int station_x = reachable.top().second, station_c = reachable.top().first;
		reachable.pop();

		
	}
}