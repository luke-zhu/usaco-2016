/*
ID: lukezhu1
PROG: heritage
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string in, pre, post;

void build(string pre, string in)
{
	if (!pre.size()) {
		return;
	}
	int pos = in.find(pre[0]);
	build(pre.substr(1, pos), in.substr(0, pos));
	build(pre.substr(pos + 1), in.substr(pos + 1));
	post += pre[0];
}

int main() {
	ifstream cin("heritage.in");
	ofstream cout("heritage.out");

	cin >> in >> pre;
	build(pre, in);
	cout << post << "\n";
}