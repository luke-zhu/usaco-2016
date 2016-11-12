#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> PII;

int main() {
	ifstream cin("trapped.in");
	// ofstream cout("trapped.out");

	int n, b;
	cin >> n >> b;

	vector<PII> left, right;
	for (int i = 0; i < n; ++i) {
		PII temp;
		cin >> temp.first >> temp.second;
		if (temp.first < b) {
			left.push_back(temp);
		}
		else {
			right.push_back(temp);
		}
	}

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	int max_r = 0;
	int result = 1000000000;
	for (int i = 0; i < left.size(); ++i) {
		while (max_r < right.size() && right[max_r].first - left[i].first <= left[i].second) {
			result = min(result, right[max_r].first - left[i].first - right[max_r].second);
			++max_r;
		}
	}
	int min_l = left.size() - 1;
	for (int i = 0; i < right.size(); ++i) {
		while (min_l >= 0 && min_l >= 0 && right[i].first - left[min_l].first <= right[i].second) {
			result = min(result, right[i].first - left[min_l].first - left[min_l].second);
			--min_l;
		}
	}
}