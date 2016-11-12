/*
O(N log N)
sort ranges
after checking 2 ranges merge them into one if intersecting
track rightmost of current,

*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ifstream cin("photo.in");
	ofstream cout("photo.out");

	// Get input
	int n, m;
	cin >> n >> m;
	pair<int, int> photo[100000];
	for (int i = 0; i < m; ++i) {
		cin >> photo[i].first >> photo[i].second;
		photo[i].first--;
		photo[i].second--;
	}
	
	sort(photo, photo + m);

	//Sweep algorithm
	int right = 0, num = 0;
	for (int i = 0; i < n; ++i) {
		if (photo[i].first > right) {
			++num;
			right = photo[i].second;
		}
		else if (photo[i].second > right) {
			right = photo[i].second;
		}
	}

}