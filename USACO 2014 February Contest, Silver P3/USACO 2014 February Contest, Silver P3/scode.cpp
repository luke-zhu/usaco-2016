#include <iostream>
#include <fstream>
#include <string>

using namespace std;	

int recursion(string s) {
	//cout << s << "\n";
	int num = 1;
	for (int i = 1; i < (s.length() + 1) / 2; ++i) {
		string sub = s.substr(0, i);
		if (sub.compare(s.substr(i, i)) == 0 || sub.compare(s.substr(s.length() - i)) == 0) {
			//cout << "P ";
			num += recursion(s.substr(i));
		}
		
		sub = s.substr(s.length() - i);
		if (sub.compare(s.substr(s.length() - 2 * i, i)) == 0 || sub.compare(s.substr(0, i)) == 0) {
			//cout << "S ";
			num += recursion(s.substr(0, s.length() - i));
		}
	}
	return num;
}

int main() {
	ifstream cin("scode.in");
	//ofstream cout("scode.out");

	string s;
	cin >> s;
	cout << (recursion(s) - 1) % 2014 << "\n";

	int dp[100][101] = { 0 };
	dp[0][s.length()] = 1;
	for (int i = s.length() - 1; i > 1; --i) {
		for (int j = 0; j < s.length() - i; ++j) {

		}
	}

}