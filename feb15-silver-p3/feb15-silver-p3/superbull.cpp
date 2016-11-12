// O(n^2 log n)

// a ^ b + 

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int n, id[2000], game[2000][2000];

int main() {
	ifstream cin("superbull.in");
	// ofstream cout("superbull.out");

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> id[i];
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			game[i][j] = id[i] ^ id[j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << game[i][j] << " ";
		}
		cout << "\n";
	}
}