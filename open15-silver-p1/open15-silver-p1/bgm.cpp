#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

int n;
long long num;
map<char, int> index;
vector<int> val[7];

int main() {
	ifstream cin("bgm.in");
	ofstream cout("bgm.out");

	index['B'] = 0;
	index['E'] = 1;
	index['S'] = 2;
	index['I'] = 3;
	index['G'] = 4;
	index['O'] = 5;
	index['M'] = 6;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		int x;
		cin >> x;
		val[index[c]].push_back(x);
	}

	for (int i = 0; i < val[0].size(); ++i) {
		for (int j = 0; j < val[1].size(); ++j) {
			for (int k = 0; k < val[2].size(); ++k) {
				for (int l = 0; l < val[3].size(); ++l) {
					if ((val[0][i] + val[1][j] + val[2][k] + val[3][l]) % 7 == 0) {
						num += ;
					}
				}
			}
		}
	}
}