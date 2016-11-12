#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
	ifstream cin("invite.in");
	ofstream cout("invite.out");

	int n, g;
	cin >> n >> g;
	
	vector< set<int> > group(g), cow(n);
	for (int i = 0; i < n; ++i) {
		int size;
		cin >> size;
		for (int j = 0; j < size; ++j) {
			int temp;
			cin >> temp;
			group[i].insert(temp);
			cow[temp].insert(i);
		}
	} 
}