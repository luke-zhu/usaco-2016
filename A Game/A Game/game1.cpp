/*
ID: lukezhu1
PROG: game1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, optimal[201][201], sum[201][201];

int main() {
	ifstream cin("game1.in");
	ofstream cout("game1.out");

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		for (int j = 0; j <= i; ++j) {
			for (int k = i + 1; k <= n; ++k) {
				sum[j][k] += temp;
			}
		}
	}
	//cout << sum[0][1] << "\n";

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n - i; ++j) {
			optimal[j][j + i] = max(sum[j][j + i] - optimal[j + 1][j + i], sum[j][j + i] - optimal[j][j + i - 1]);
		}
	}
	cout << optimal[0][n] << " " << sum[0][n] - optimal[0][n] << "\n";
}