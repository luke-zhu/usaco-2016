/*
ID: lukezhu1
PROG: shopping
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

int offers[104][5];

int main() {
	ifstream cin("shopping.in");
	ofstream cout("shopping.out");

	map<int, int> code;
	int s, num_products = 0, price[104];
	cin >> s;
	//cout << s << "\n";
	for (int i = 0; i < s; ++i) {
		int n;
		cin >> n;
		//cout << n << " ";
		for (int j = 0; j < n; ++j) {
			int c;
			cin >> c;
			if (!code.count(c)) {
				code[c] = num_products;
				++num_products;
			}
			cin >> offers[i][code[c]];
			//cout << c << " " << offers[i][code[c]] << " ";
		}
		cin >> price[i];
		//cout << price[i] << "\n";
	}

	int b, purchase[5] = { 0 };
	cin >> b;
	//cout << b << "\n";
	for (int i = 0; i < b; ++i) {
		int c;
		cin >> c;
		if (!code.count(c)) {
			code[c] = num_products;
			++num_products;
		}
		cin >> purchase[code[c]] >> price[s + i];
		offers[s + i][code[c]] = 1;
		//cout << c << " " << purchase[code[c]] << " " << price[s + i] << "\n";
	}

	int dp[6][6][6][6][6];
	int a[5] = { 0 };
	for (a[0] = 0; a[0] <= 5; ++a[0]) {
		for (a[1] = 0; a[1] <= 5; ++a[1]) {
			for (a[2] = 0; a[2] <= 5; ++a[2]) {
				for (a[3] = 0; a[3] <= 5; ++a[3]) {
					for (a[4] = 0; a[4] <= 5; ++a[4]) {
						dp[a[0]][a[1]][a[2]][a[3]][a[4]] = 1000000000;
					}
				}
			}
		}
	}
	dp[0][0][0][0][0] = 0;


	int i[5] = { 0 };
	for (i[0] = 0; i[0] <= 5; ++i[0]) {
		for (i[1] = 0; i[1] <= 5; ++i[1]) {
			for (i[2] = 0; i[2] <= 5; ++i[2]) {
				for (i[3] = 0; i[3] <= 5; ++i[3]) {
					for (i[4] = 0; i[4] <= 5; ++i[4]) {
						for (int j = 0; j < s + b; ++j) {
							bool flag = false;
							for (int k = 0; k < 5; ++k) {
								if (i[k] + offers[j][k] > 5) {
									flag = true;
									break;
								}
							}
							if (flag) {
								continue;
							}
							//cout << dp[i[0]][i[1]][i[2]][i[3]][i[4]] + price[j]<< " ";
							//cout << dp[i[0] + offers[j][0]][i[1] + offers[j][1]][i[2] + offers[j][2]][i[3] + offers[j][3]][i[4] + offers[j][4]] << "\n";
							dp[i[0] + offers[j][0]][i[1] + offers[j][1]][i[2] + offers[j][2]][i[3] + offers[j][3]][i[4] + offers[j][4]] = min(dp[i[0]][i[1]][i[2]][i[3]][i[4]] + price[j], dp[i[0] + offers[j][0]][i[1] + offers[j][1]][i[2] + offers[j][2]][i[3] + offers[j][3]][i[4] + offers[j][4]]);
						}
					}
				}
			}
		}
	}
	cout << dp[purchase[0]][purchase[1]][purchase[2]][purchase[3]][purchase[4]] << "\n";
}