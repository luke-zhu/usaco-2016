// O(n log n)

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;
typedef pair<int, int> PII;

struct Cow {
	int in, out, y;
};

bool cmp(Cow a, Cow b) {
	if (a.in == b.in) {
		return a.out < b.out;
	}
	return a.in < b.in;
}

int n;
Cow cows[50000];

int main() {
	ifstream cin("stampede.in");
	ofstream cout("stampede.out");

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, r;
		cin >> x >> cows[i].y >> r;
		cows[i].in = r * (x + 1);
		cows[i].out = r * x;
	}

	sort(cows, cows + n, cmp);

	int num_seen = 0;
	priority_queue<PII, vector<PII>, greater<PII> > pq;
	for (int i = 0; i < n; ++i) {
		while (!pq.empty() && pq.top().second < cows[i].in) {
			pq.pop();
			++num_seen;
		}
		pq.push(PII(cows[i].y, cows[i].out));
	}
}