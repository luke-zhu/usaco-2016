#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//O(n^2), O(n^2)

int main() {
	ifstream cin("msched.in");
	// ofstream cout("msched.out");

	int n, m;
	cin >> n >> m;

	int time[10001], milked[10001], end_t;
	for (int i = 1; i <= n; ++i) {
		cin >> time[i];
		milked[i] = time[i];
		end_t = max(end_t, milked[i]);
	}
	
	vector<int> after[10000];
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		after[a].push_back(b);
		
		milked[b] = max(milked[b], milked[a] + time[b]);
		end_t = max(end_t, milked[b]);


		for (int j = 0; j < after[b].size(); ++j) {
			milked[after[b][j]] = max(milked[after[b][j]], milked[b] + time[after[b][j]]);
			end_t = max(end_t, milked[after[b][j]]);
		}
	}

	cout << end_t << "\n";
}

using namespace std;

//O(n^2), O(n^2)

int main2() {
	ifstream cin("msched.in");
	// ofstream cout("msched.out");

	int n, m;
	cin >> n >> m;

	int time[10000];
	for (int i = 0; i < n; ++i) {
		cin >> time[i];
	}

	vector<int> constraint[1000];
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		constraint[a].push_back(b);
	}

	for (int i = 0; i < n; ++i) {

	}
}